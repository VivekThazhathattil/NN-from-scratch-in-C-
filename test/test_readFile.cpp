#include "../src/include/readFiles.h"
#include <iostream>

int main(){
	ReadFiles rf;
	unsigned char* readLabels = rf.readMnistLabels("/mnt/sda_12/c++_course/nn3/data/t10k-labels-idx1-ubyte", 10000);
	unsigned char** readImg = rf.readMnistImages("/mnt/sda_12/c++_course/nn3/data/train-images-idx3-ubyte", 60000, 784);
	for (int i = 0; i < 10000; i++)
		std::cout << i << ")" << static_cast<unsigned>(readLabels[i]) << std::endl;
	return 0;
}
