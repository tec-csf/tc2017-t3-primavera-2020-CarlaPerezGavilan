/*
 * This file is part of {{tc2017-t3-primavera-2020-CarlaPerezGavilan}}.
 * 
 * Median.cpp
 * Carla Pérez Gavilán Del Castillo
 * Divide & Conquer
 * 17/abril/2020
 * Copyright © 2020 Carla Pérez Gavilán Del Castillo. All rights reserved.
 * 
 */

#include <vector>
#include <cstdlib>
#include <iostream>

#include "Median.hpp"

using namespace med;


/**
 * Determines the median from two arrays
 *
 * @param[in] array a of type T 
 * @param[in] array b of type T
 * @param[in] size of both arrays, that should be the same 
 * @param[out] median of both arrays 
 */
template <class T>
T Media<T>::twoArrayMedian(T arr_a[], T arr_b[], int n)
{
       if(n<=0){
           return -1;
       }

       if(n==1){
           return (arr_a[0]+arr_b[0])/2;
       }

        if(n==2){
            return (std::max(arr_a[0],arr_b[0])+std::min(arr_a[1], arr_b[1]))/2;
        }

       int median_a = getMedian(arr_a, n);
       int median_b = getMedian(arr_b, n);

       if(median_a==median_b){
           return median_b;
       }

    if(median_a>median_b){
        if(n%2==0){
        return twoArrayMedian(arr_a + n / 2 - 1,  
                             arr_b, n - n / 2 + 1); 

        }else{
        return twoArrayMedian(arr_a + n / 2,  
                         arr_b, n - n / 2);
        }
    }

     if(n%2==0){
            return twoArrayMedian(arr_b + n / 2 - 1,  
                         arr_a, n - n / 2 + 1);
        }else{
            return twoArrayMedian(arr_b + n / 2,  
                     arr_a, n - n / 2);
        }

}


/**
 * Determines the median of a single array
 *
 * @param[in] array to determine median
 * @param[in] size of array n 
 * @param[out] median of array
 */

template <class T>
T Media<T>::getMedian(T sort_vect[], int n)
{
    if(n%2==0){
        return (sort_vect[n/2]+sort_vect[n/2+1])/2;
    }else{
        return sort_vect[n/2];
    }
}

int main(int argc, const char * argv[]) 
{ 
    int size = 5;
    int a[] = {1, 12, 15, 26, 38}; 
    int b[] = {2, 13, 17, 30, 45}; 
    Media<int> m;
    std::cout<<"this is result= "<< m.twoArrayMedian(a, b, size)<<std::endl;
    return 0; 
} 



  

