#include "../../eigen/Eigen/Dense"
#include <math.h>

class Utils{
	public:
		Utils();
		~Utils();

		void outMat2ClassNum(Eigen::MatrixXf& outMat, Eigen::MatrixXf& classNumVec); // converts output matrix to class number vector
		void classNumVec2OutMat(Eigen::MatrixXf& outMat, Eigen::MatrixXf& classNumVec, int inputSize = -1); // converts class number vector to output matrix
		void feedForwardFunction(Eigen::MatrixXf& inMat, Eigen::MatrixXf& outMat, Eigen::MatrixXf& wtsMat, Eigen::MatrixXf& bias);
		void activationFunction(Eigen::MatrixXf& X, Eigen::MatrixXf& Y);
		void activationFunctionPrime(Eigen::MatrixXf& X, Eigen::MatrixXf& Y);
		void horzCat(Eigen::MatrixXf& x, Eigen::MatrixXf& y, Eigen::MatrixXf& z); //horizontally catenate x and y to give z.
		void initWts( float maxWt, float width, float height, Eigen::MatrixXf& mat);
		void evalNetworkError(Eigen::MatrixXf& inMat, Eigen::MatrixXf& wtMat,\
			       		Eigen::MatrixXf& outMat, Eigen::MatrixXf& classNumVec,\
					Eigen::MatrixXf& bias);
};
