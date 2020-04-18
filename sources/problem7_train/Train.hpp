/*
 * This file is part of {{tc2017-t3-primavera-2020-CarlaPerezGavilan}}.
 * 
 * Train.hpp
 * Carla Pérez Gavilán Del Castillo
 * Dynamic Programming
 * 17/abril/2020
 * Copyright © 2020 Carla Pérez Gavilán Del Castillo. All rights reserved.
 * 
 */

#include <stdio.h> 
#include <limits.h> 
#include <iostream>
#include "adj_matrix.cpp"


#define V 4

template<class T>
class TrainTime{
    public:
    std::string stations[V] = {"A", "B", "C", "D"};


    int min(int times[],  bool visited[]);
    
    void printRoute(T parent[], int j);

    void print(int dist[], T target, T first,  T parent[]);

    void bestpath(T graph[V][V], T begin, T end);
  
};



