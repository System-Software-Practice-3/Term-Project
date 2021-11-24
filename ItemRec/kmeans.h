#ifndef KMEAN
#define  KMEAN

#include "MYopencv.h"
#include "image2vec.h"
#include <vector>
#include <ctime>
#include <utility>
using namespace cbr;
cv::Mat kmeans_clustering(cv::Mat input_matrix, int Numofcluster, int withinDistance);
std::vector<std::pair<int,double>> kmeans_similarity(img2RGB input,std::vector<img2RGB> stored_picture,int number_of_cluster,int withinDistance, int choose_num);
//kmeans_compare func
#endif


