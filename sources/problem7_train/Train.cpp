/*
 * This file is part of {{tc2017-t3-primavera-2020-CarlaPerezGavilan}}.
 * 
 * train_time.cpp
 * Carla Pérez Gavilán Del Castillo
 * Dynamic Programming
 * 17/abril/2020
 * Copyright © 2020 Carla Pérez Gavilán Del Castillo. All rights reserved.
 * 
 */

#include "Train.hpp"


#define V 4

    

/**
 * Keep track of minimum time value
 *
 * @param[in] array with the times so far to reach each node 
 * @param[in] array that show which nodes are visited or unvisited
 * @param[out] index of the minimum time value out of all of those unvisited nodes
 */

    template <class T> 
    int TrainTime<T>::min(int times[],  bool visited[]) 
    { 
        int min = INT_MAX;
        int index = 0; 
    
        for (int i = 0; i < V; i++)
        {
            if (!visited[i] && times[i] <= min)
            {
                min = times[i];
                index = i; 
            }
        }
        
        return index; 
    }

/**
 * Prints a particular route starting from end node 
 *
 * @param[in] last node from which we will iterate backwards 
 * @param[in] array of all parent nodes 
 */
    template <class T> 
    void TrainTime<T>::printRoute(T parent[], int j) 
    { 
            std::cout<<std::endl;
            std::string path= "arrived";
            while(parent[j]!=-1)
            {
                path=TrainTime<T>::stations[j]+"-->"+path;
                std::cout<<" "<<TrainTime<T>::stations[parent[j]]<<" --> "<<TrainTime<T>::stations[j]<<std::endl;
                getTimes(TrainTime<T>::stations[parent[j]], TrainTime<T>::stations[j]);
                j=parent[j];
                std::cout<<std::endl;
            }
            std::cout<<TrainTime<T>::stations[j]<<"-->"<<path<<std::endl;


    } 

/**
 * Prints result which includes: total time, first station, last station and path 
 *
 * @param[in] array with all parent nodes (path)
 * @param[in] target or final destination 
 * @param[in] starting point or first station
 * @param[in] distances or times from each node 
 * @param[out] index of the minimum time value out of all of those unvisited nodes
 */
    template <class T> 
    void TrainTime<T>::print(int time[], T target, T first, T parent[]) 
    { 
            printf("Source->Destination  =  "); 
            
            std::cout<<TrainTime<T>::stations[first]<<"-->"<< TrainTime<T>::stations[target]<< std::endl;
            std::cout<<"total time  =  "<<time[target]<<" minutes "<< std::endl; 
            std::cout<<"trains to take  =  ";
            TrainTime<T>::printRoute(parent, target); 

    } 
  
/**
 * Uses dijkstra algorithm to calculate shortest path 
 *
 * @param[in] adjacency matrix where graph is stored 
 * @param[in] starting station or node
 * @param[in] ending station or node
 */

     template <class T> 
     void TrainTime<T>::bestpath(T graph[V][V], T begin, T end) 
    { 
        

        int times[V];  
        bool visited[V]; 
        int parent[V]; 
    
    
        for (int i = 0; i < V; i++) 
        { 
            parent[begin] = -1; 
            times[i] = INT_MAX; 
            visited[i] = false; 
        } 

    
        times[begin] = 0; 
    

        for (int i = 0; i < V - 1; i++) 
        { 
            int a = min(times, visited); 
            visited[a] = true; 
            for (int j = 0; j < V; j++){
                 if (!visited[j] && graph[a][j] && times[a] + graph[a][j] < times[j]) 
                { 
                    parent[j] = a; 
                    times[j] = times[i] + graph[a][j]; 
                }  
                if(j==end){
                    break;
                }
            }
    
               
        } 
        TrainTime<T>::print(times, end, begin, parent); 
    } 
  

int main(int argc, const char * argv[]) 
{ 
    TrainTime<int> t;
    read("test.csv");
    int graphs[4][4];
    adjMatrix(graphs);
    t.bestpath(graphs, 0, 2); 
    return 0; 
}



