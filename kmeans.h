#ifndef KMEAN
#define  KMEAN

#include "MYopencv.h"
#include <vector>
#include <ctime>

cv::Mat kmeans_clustering(cv::Mat input_matrix, int Numofcluster, int withinDistance);

#endif


