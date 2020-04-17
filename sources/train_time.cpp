
/*
 * This file is part of {{tc2017-t3-primavera-2020-CarlaPerezGavilan}}.
 *
 * Developed for the LSST Data Management System.
 * This product includes software developed by the LSST Project
 * (https://www.lsst.org).
 * See the COPYRIGHT file at the top-level directory of this distribution
 * for details of code ownership.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include <stdio.h> 
#include <limits.h> 
#include <iostream>
#include "adj_matrix.cpp"


#define V 4

class TrainTime{
    public:

    
    string stations[V] = {"A", "B", "C", "D"};

/**
 * Keep track of minimum time value
 *
 * @param[in] array with the times so far to reach each node 
 * @param[in] array that show which nodes are visited or unvisited
 * @param[out] index of the minimum time value out of all of those unvisited nodes
 */

    int min(int times[],  bool visited[]) 
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
 * Keep track of minimum time value
 *
 * @param[in] array with the times so far to reach each node 
 * @param[in] array that show which nodes are visited or unvisited
 * @param[out] index of the minimum time value out of all of those unvisited nodes
 */

    void printRoute(int parent[], int j) 
    { 
            cout<<endl;
            string path= "arrived";
            while(parent[j]!=-1)
            {
                path=stations[j]+"-->"+path;
                cout<<" "<<stations[parent[j]]<<" --> "<<stations[j]<<endl;
                getTimes(stations[parent[j]], stations[j]);
                j=parent[j];
                cout<<endl;
            }
            cout<<stations[j]<<"-->"<<path<<endl;


    } 

/**
 * Keep track of minimum time value
 *
 * @param[in] array with the times so far to reach each node 
 * @param[in] array that show which nodes are visited or unvisited
 * @param[out] index of the minimum time value out of all of those unvisited nodes
 */

    void print(int dist[], int target, int first,  int parent[]) 
    { 
            printf("Source->Destination  =  "); 
            
            cout<<stations[first]<<"-->"<<stations[target]<<endl;
            cout<<"total time  =  "<<dist[target]<<" minutes "<<endl; 
            cout<<"trains to take  =  ";
            printRoute(parent, target); 

    } 
  
/**
 * Uses dij
 *
 * @param[in] array with the times so far to reach each node 
 * @param[in] array that show which nodes are visited or unvisited
 * @param[out] index of the minimum time value out of all of those unvisited nodes
 */

    void bestpath(int graph[V][V], int begin, int end) 
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
        print(times, end, begin, parent); 
    } 
  

};



