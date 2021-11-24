#ifndef HISTO
#define HISTO
#include <utility>

void calculate_histo(std::vector<img2RGB>& stored_picture);
std::vector<std::pair<int,double>> histo_similarity(img2RGB input, std::vector<img2RGB> stored_picture, int choose_num);

#endif