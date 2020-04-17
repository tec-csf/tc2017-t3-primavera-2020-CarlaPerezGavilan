
#include "Median.hpp"

using namespace med;

int main(int argc, const char * argv[]) 
{ 
    int size = 5;
    int a[] = {1, 12, 15, 26, 38}; 
    int b[] = {2, 13, 17, 30, 45}; 
    Media<int> m;
    std::cout<<"this is result= "<< m.twoArrayMedian(a, b, size)<<std::endl;
    return 0; 
} 