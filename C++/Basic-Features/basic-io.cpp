#include <iostream>

int main() {
	using namespace std;
	
	char buff[512];
	cout << "What is your name?";
	cin.getline(buff, 64, '\n');
	cout << "Your name is:" << buff << endl;
    float f = 1.0;
    int i{static_cast<int>(f)}; // Will give a warning if we dont cast...Uniform initalization Concepts
    //int i = f; 
    int *poiter = &i;
    //int *pointer2 = nullptr;
    //cout << *pointer2 << endl;  // Will give rise to Segmentation Fault
	int age ;
	cin >> age ;
	return 0;
}