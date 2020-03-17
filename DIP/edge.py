# To add a new cell, type '# %%'
# To add a new markdown cell, type '# %% [markdown]'
# %% [markdown]
# # Comparing Edge Detection Methods
# 
# 
# 

# %%
import numpy as np
from PIL import Image
import matplotlib.pyplot as plt


# %%
# Open Image
img = np.array(Image.open("myphoto.jpeg")).astype(np.uint8)


# %%
img.shape
#img


# %%
# Make gray Image
gray_img = np.round( 0.299 * img[:,:,0] + 0.587 * img[:,:,1] + 0.11 * img[:,:, -1])
#grey_image


# %%
# Sobel Operator
horizontal = np.array([[-1, 0, 1],[-2, 0, 2],[-1, 0, 1]])
vertical = np.array([[-1, -2, -1],[0, 0, 0],[1, 2, 1]])
type(horizontal)


# %%
new_horizontal_image = np.zeros(gray_img.shape)
new_vertical_image = np.zeros(gray_img.shape)
new_gradient = np.zeros(grey_image.shape)
#new_horizontal_image.shape
#new_horizontal_image


# %%
for i in range(1, img.shape[0] -1 ):
    for j in range( 1, img.shape[1] -1 ):
        horizontalGrad = (horizontal[0, 0] * gray_img[i - 1, j - 1]) +                          (horizontal[0, 1] * gray_img[i - 1, j]) +                          (horizontal[0, 2] * gray_img[i - 1, j + 1]) +                          (horizontal[1, 0] * gray_img[i, j - 1]) +                          (horizontal[1, 1] * gray_img[i, j]) +                          (horizontal[1, 2] * gray_img[i, j + 1]) +                          (horizontal[2, 0] * gray_img[i + 1, j - 1]) +                          (horizontal[2, 1] * gray_img[i + 1, j]) +                          (horizontal[2, 2] * gray_img[i + 1, j + 1])
        new_horizontal_image[i - 1, j - 1] = abs(horizontalGrad)
        verticalGrad = (vertical[0, 0] * gray_img[i - 1, j - 1]) +                        (vertical[0, 1] * gray_img[i - 1, j]) +                        (vertical[0, 2] * gray_img[i - 1, j + 1]) +                        (vertical[1, 0] * gray_img[i, j - 1]) +                        (vertical[1, 1] * gray_img[i, j]) +                        (vertical[1, 2] * gray_img[i, j + 1]) +                        (vertical[2, 0] * gray_img[i + 1, j - 1]) +                        (vertical[2, 1] * gray_img[i + 1, j]) +                        (vertical[2, 2] * gray_img[i + 1, j + 1])

        new_vertical_image[i - 1, j - 1] = abs(verticalGrad)
         # Edge Magnitude
        mag = np.sqrt(pow(horizontalGrad, 2.0) + pow(verticalGrad, 2.0))
        new_gradient[i - 1, j - 1] = mag


# %%
plt.figure()
plt.title('input')
plt.imsave('myphoto.jpeg', new_gradient, cmap = "gray", format = "png")
plt.imshow(new_horizontal_image, cmap = "gray")
plt.show()


# %%


