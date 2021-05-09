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

void Utils::activationFunction(Eigen::MatrixXf& X, Eigen::MatrixXf& Y){
	for (int i = 0; i < X.rows(); i++)
		for(int j = 0; j < X.cols(); j++)
			Y(i,j) = 0.5*(tanh(X(i,j)) + 1);
}

void Utils::activationFunctionPrime(Eigen::MatrixXf& X, Eigen::MatrixXf& Y){
	for (int i = 0; i < X.rows(); i++)
		for(int j = 0; j < X.cols(); j++)
			Y(i,j) = 0.5*(1 - tanh(X(i,j))*tanh(X(i,j)))
}

void Utils::feedForwardFunction(Eigen::MatrixXf& inMat, Eigen::MatrixXf& outMat, Eigen::MatrixXf& wtsMat, Eigen::MatrixXf& bias){
	Eigen::MatrixXf net(1,1);
	Eigen::MatrixXf temp = horzCat(inMat, bias);
	net = wtsMat * temp;
	outMat = activationFunction(net);
	
}

void Utils::horzCat(Eigen::MatrixXf& x, Eigen::MatrixXf& y, Eigen::MatrixXf& z){
	assert(x.rows() == y.rows());
	assert(y.rows() == z.rows());

	for(int i = 0; i < x.rows(); i++)
		for(int j = 0; j < x.cols() + y.cols(); j++){
			if( j < x.cols())
				z(i,j) = x(i,j);
			else
				z(i,j) = y(i,j);
		}
	
}

void initWts( float maxWt, float width, float height, Eigen::MatrixXf& mat){
	mat = Eigen::MatrixXf::Random(height,width) * maxWt;
}

void evalNetworkError();
