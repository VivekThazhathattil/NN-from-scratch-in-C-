#include "include/dataHandler.h"

DataHandler::DataHandler( unsigned char** img, unsigned char* label, int inputCount, int outputCount) {
	trainingSetImages = img;
	trainingSetLabels = label;
	this->inputCount = inputCount;
	this->outputCount = outputCount;
}
DataHandler::~DataHandler() {}
