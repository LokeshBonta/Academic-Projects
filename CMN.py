from __future__ import print_function
from __future__ import division
import numpy as np  
from nvidia.dali.pipeline import Pipeline
import os.path
import fnmatch
from timeit import default_timer as timer
import matplotlib.gridspec as gridspec
import matplotlib.pyplot as plt
import nvidia.dali.ops as ops
import nvidia.dali.types as types
import nvidia.dali as dali

data_folder = "/home/mcw/Lokesh/data/"
out_folder = "/home/mcw/Lokesh/"
print("Printing Elements in the Data Processed")
def showDir(folder_name : str):
    for root, dir, files in os.walk(folder_name):
            depth = root.count('/')
            ret = ""
            if depth > 0:
                ret += "  " * (depth - 1) + "|-"
            print (ret + root)
            for items in fnmatch.filter(files, "*"):
                    print (" " * len(ret) + "|-" + items)

def show_images(image_batch, name):
    columns = 4
    rows = (batch_size + 1) // (columns)
    fig = plt.figure(figsize = (32,(32 // columns) * rows))
    gs = gridspec.GridSpec(rows, columns)
    for j in range(rows*columns):
        plt.subplot(gs[j])
        plt.axis("off")
        plt.imshow(image_batch.at(j))
        plt.imsave(name + str(j) + ".png" , image_batch.at(j)/255.0)


print("\n Building Pipeline")
showDir(data_folder)
batch_size = 8

class CMNSimplePipeline(Pipeline):
    def __init__(self, batch_size, num_threads, device_id):
        super(CMNSimplePipeline, self).__init__(batch_size, num_threads, device_id, seed = 12)
        self.input = ops.FileReader(file_root = data_folder)
        # instead of path to file directory file with pairs image_name image_label_value can be provided
        # self.input = ops.FileReader(file_root = image_dir, file_list = image_dir + '/file_list.txt')
        self.decode = ops.ImageDecoder(device = 'cpu', output_type = types.RGB)
        self.normalize = dali.ops.CropMirrorNormalize(
            device="cpu",
            output_dtype=dali.types.FLOAT,
            crop = 100,
            image_type=dali.types.RGB,
            mean=  [0.0, 0.0, 0.0, 0.0],#[100, 0., 0.],
            #std=[10, 1., 1.],
            output_layout=dali.types.NHWC)

    def define_graph(self):
        jpegs, labels = self.input()
        images = self.decode(jpegs)
        normalize_images = self.normalize(images)
        return (images, normalize_images, labels)

pipe = CMNSimplePipeline(batch_size, 1, 0)
pipe.build()
pipe_cmn = pipe.run()

images, normal_images, labels = pipe_cmn
print("Images is_dense_tensor: " + str(normal_images.is_dense_tensor()))
print("Labels is_dense_tensor: " + str(labels.is_dense_tensor()))
print(images.at(0).shape)
#print(normal_images.shape)
print(normal_images.at(0).shape)
show_images(normal_images, "normal")
show_images(images, "images")


normal_tensors = normal_images.as_tensor()
print(normal_tensors.shape())