/*
 * This file is part of {{tc2017-t3-primavera-2020-CarlaPerezGavilan}}.
 * 
 * Median.hpp
 * Carla Pérez Gavilán Del Castillo
 * Divide & Conquer
 * 17/abril/2020
 * Copyright © 2020 Carla Pérez Gavilán Del Castillo. All rights reserved.
 * 
 */

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