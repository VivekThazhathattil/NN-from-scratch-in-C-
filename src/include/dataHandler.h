class DataHandler{
	public:
		unsigned char** trainingSetImages;
		unsigned char* trainingSetLabels;
		unsigned char** evalSetImages;
		unsigned char* evalSetLabels;
		int inputCount;
		int outputCount;
//		unsigned char** testSetImages;
//		unsigned char* testSetImages;

		DataHandler();
		DataHandler( unsigned char** img, unsigned char* label, int inputCount, int outputCount);
		~DataHandler();
};
