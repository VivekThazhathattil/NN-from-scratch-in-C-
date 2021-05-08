#include "../src/include/utils.h"
#include "../eigen/Eigen/Dense"
#include <time.h>
#include <stdlib.h>
#include <iostream>

#define MIN_MAT_SIZE_LIM 3

int main(){
	Utils util;
	std::srand(time(0));
	int m = std::rand()%8 + MIN_MAT_SIZE_LIM;
	int n = std::rand()%8 + MIN_MAT_SIZE_LIM;
	Eigen::MatrixXf classNumVec (5,4);
	Eigen::MatrixXf outMat = Eigen::MatrixXf::Zero(m,n);
	for(int i = 0; i< m; i++)
		outMat(i,rand()%n) = 1;
	util.outMat2ClassNum(outMat, classNumVec);

	std::cout << "Out Matrix:\n" << outMat << std::endl;
	std::cout << "Class Number Vector: \n" << classNumVec << std::endl;
	util.classNumVec2OutMat(outMat, classNumVec,n);
	std::cout << "Out Matrix after classNumVec2OutMat call:\n" << outMat << std::endl;
	return 0;
}
