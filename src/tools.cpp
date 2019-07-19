#include <iostream>
#include "tools.h"

using Eigen::VectorXd;
using Eigen::MatrixXd;
using std::vector;

Tools::Tools() {}

Tools::~Tools() {}

VectorXd Tools::CalculateRMSE(const vector<VectorXd> &estimations,
                              const vector<VectorXd> &ground_truth) {
	int n = estimations.size();
	VectorXd rmse(4);
	rmse<<0,0,0,0;
	for(int i=0;i<n;++i){
		VectorXd residuals = estimations[i]-ground_truth[i];
		residuals = residuals.array()*residuals.array();
		rmse += residuals;
	}
	rmse = rmse/n;
	rmse = sqrt(rmse.array());
	return rmse;
}