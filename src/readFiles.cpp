#include "include/readFiles.h"

ReadFiles::ReadFiles() {}
ReadFiles::~ReadFiles() {}

unsigned char** ReadFiles::readMnistImages(string fullPath, int numImages, int imgSize) {
    auto reverseInt = [](int i) {
        unsigned char c1, c2, c3, c4;
        c1 = i & 255, c2 = (i >> 8) & 255, c3 = (i >> 16) & 255, c4 = (i >> 24) & 255;
        return ((int)c1 << 24) + ((int)c2 << 16) + ((int)c3 << 8) + c4;
    };


    ifstream file(fullPath, ios::binary);

    if(file.is_open()) {
        int magicNo = 0, nRows = 0, nCols = 0;

        file.read((char *)&magicNo, sizeof(magicNo));
        magicNo = reverseInt(magicNo);

        if(magicNo != 2051) std::cerr << "Invalid MNIST image file!";

        file.read((char *)&numImages, sizeof(numImages)), numImages = reverseInt(numImages);
        file.read((char *)&nRows, sizeof(nRows)), nRows = reverseInt(nRows);
        file.read((char *)&nCols, sizeof(nCols)), nCols = reverseInt(nCols);

        imgSize = nRows * nCols;

        unsigned char** _dataset = new unsigned char*[numImages];
        for(int i = 0; i < numImages; i++) {
            _dataset[i] = new unsigned char[imgSize];
            file.read((char *)_dataset[i], imgSize);
        }
        return _dataset;
    } else {
        std::cerr << "Cannot open file ";
	exit(0);
    }
}

unsigned char* ReadFiles::readMnistLabels(string fullPath, int noOfLabels) {
    auto reverseInt = [](int i) {
        unsigned char c1, c2, c3, c4;
        c1 = i & 255, c2 = (i >> 8) & 255, c3 = (i >> 16) & 255, c4 = (i >> 24) & 255;
        return ((int)c1 << 24) + ((int)c2 << 16) + ((int)c3 << 8) + c4;
    };

    ifstream file(fullPath, ios::binary);

    if(file.is_open()) {
        int magicNo = 0;
        file.read((char *)&magicNo, sizeof(magicNo));
        magicNo = reverseInt(magicNo);

        if(magicNo != 2049){ 
		std::cerr << "Invalid MNIST label file!";
		exit(0);
	}

        file.read((char *)&noOfLabels, sizeof(noOfLabels)), noOfLabels = reverseInt(noOfLabels);

        unsigned char* _dataset = new unsigned char[noOfLabels];
        for(int i = 0; i < noOfLabels; i++) {
            file.read((char*)&_dataset[i], 1);
        }
        return _dataset;
    } else {
        std::cerr << "Unable to open file ";
	exit(0);
    }
}
