

#include <stdio.h> 
#include <limits.h> 
#include <iostream>
#include "adj_matrix.cpp"

#define V 4 
  

string stations[] = {"A", "B", "C", "D"};

int min(int times[],  bool visited[]) 
{ 
    int min = INT_MAX, index; 
  
    for (int i = 0; i < V; i++){
         if (!visited[i] && times[i] <= min){
            min = times[i];
            index = i; 
        }
    }
       
    return index; 
} 
  

void printPath(int parent[], int j) 
{ 
    cout<<endl;
    string path= "arrived";
      while(parent[j]!=-1){
        path=stations[j]+"-->"+path;
        cout<<" "<<stations[parent[j]]<<" --> "<<stations[j]<<endl;
        getTimes(stations[parent[j]], stations[j]);
        j=parent[j];
        cout<<endl;
      }
    cout<<stations[j]<<"-->"<<path<<endl;


} 
  

void printSolution(int dist[], int target, int first,  
                      int parent[]) 
{ 
    printf("Source->Destination  =  "); 
    
    cout<<stations[first]<<"-->"<<stations[target]<<endl;
    cout<<"total time  =  "<<dist[target]<<" minutes "<<endl; 
    cout<<"trains to take  =  ";
    printPath(parent, target); 

} 
  

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
        for (int j = 0; j < V; j++) 
  
            if (!visited[j] && graph[i][j] && times[i] + graph[i][j] < times[j]) 
            { 
                parent[j] = i; 
                times[j] = times[i] + graph[i][j]; 
            }  
    } 
    printSolution(times, end, begin, parent); 
} 
  
int main() 
{ 
    read("test.csv");

    int graphs[V][V];
    adjMatrix(graphs);
    bestpath(graphs, 0, 2); 
    return 0; 
}