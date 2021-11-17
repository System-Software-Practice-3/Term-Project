#ifndef HISTO
#define HISTO

void calculate_histo(img2RGB input,std::vector<img2RGB> stored_picture);
std::vector<img2RGB> histo_similarity(std::vector<img2RGB> stored_picture, int choose_num);

#endif