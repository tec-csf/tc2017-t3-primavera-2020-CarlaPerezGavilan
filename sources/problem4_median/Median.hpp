#ifndef median_hpp
#define median_hpp

#include <vector>
#include <cstdlib>
#include <iostream>

namespace med{ 

    template <class T> class Media{
   
        
    public: 
    

    T twoArrayMedian(T arr_a[], T arr_b[], int n);
    
    T getMedian(T sort_vect[], int n);



};

}
#endif