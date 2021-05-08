#include "../../eigen/Eigen/Dense"

class Utils{
	public:
		Utils();
		~Utils();

		void outMat2ClassNum(Eigen::MatrixXf& outMat, Eigen::MatrixXf& classNumVec); // converts output matrix to class number vector
		void classNumVec2OutMat(Eigen::MatrixXf& outMat, Eigen::MatrixXf& classNumVec, int inputSize = -1); // converts class number vector to output matrix
};
