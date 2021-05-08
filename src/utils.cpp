#include "include/utils.h"

Utils::Utils() {}
Utils::~Utils() {}

void Utils::outMat2ClassNum(Eigen::MatrixXf& outMat, Eigen::MatrixXf& classNumVec){
	int m = outMat.rows(); //training count
	int n = outMat.cols(); //no. of classes count

	classNumVec.resize(m,1);
	for(int i = 0; i < m; i++){
		int j = 0;
		while(j<n){
			if(outMat(i,j))
				break;
			else
				j++;
		}
		if(j < n)
			classNumVec(i) = j+1;
		else
			classNumVec(i) = 0;
	}
		
}
void Utils::classNumVec2OutMat(Eigen::MatrixXf& outMat, Eigen::MatrixXf& classNumVec, int inputSize){
	/* the classes size is unknown. So get the maximum class size in the output matrix and that corresponds to n.
	 * Then convert the classNumVec's each element to 0s-1s form */

	int m = classNumVec.rows();
	int n;
	if(inputSize <= 0)
		n = classNumVec.maxCoeff();
	else
		n = inputSize;

	outMat = Eigen::MatrixXf::Zero(m,n);
	for (int i = 0; i < m; i++){
		int jTemp = classNumVec(i,0) - 1;
		outMat( i, jTemp) = 1;
	}
}
