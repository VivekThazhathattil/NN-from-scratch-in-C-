#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class ReadFiles{
	public:
		ReadFiles();
		~ReadFiles();

		unsigned char** readMnistImages(string full_path, int number_of_images, int image_size);
		unsigned char* readMnistLabels(string full_path, int number_of_labels);
};
