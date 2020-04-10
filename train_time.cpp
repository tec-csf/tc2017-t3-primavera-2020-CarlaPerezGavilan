

#include <stdio.h> 
#include <limits.h> 
#include <iostream>
  

#define V 9 
  

int minDistance(int dist[],  
                bool sptSet[]) 
{ 
    int min = INT_MAX, min_index; 
  
    for (int v = 0; v < V; v++) 
        if (sptSet[v] == false && 
                   dist[v] <= min) 
            min = dist[v], min_index = v; 
  
    return min_index; 
} 
  

void printPath(int parent[], int j) 
{ 
      
    if (parent[j] == - 1) 
        return; 
  
    printPath(parent, parent[j]); 
    printf("%d ", j); 
} 
  

void printSolution(int dist[], int target, int first,  
                      int parent[]) 
{ 
    printf("Vertex\tTime\tStations"); 
    
    printf("\n%d -> %d \t\t %d\t\t%d ", 
        first, target, dist[target], first); 
    printPath(parent, target); 

} 
  

void dijkstra(int graph[V][V], int begin, int end) 
{ 
      

    int dist[V];  
  

    bool sptSet[V]; 
  

    int parent[V]; 
  
 
    for (int i = 0; i < V; i++) 
    { 
        parent[begin] = -1; 
        dist[i] = INT_MAX; 
        sptSet[i] = false; 
    } 

   
    dist[begin] = 0; 
  

    for (int count = 0; count < V - 1; count++) 
    { 
   
        int u = minDistance(dist, sptSet); 
  
        // Mark the picked vertex  
        // as processed 
        sptSet[u] = true; 
           printf("hola\n");

        for (int v = 0; v < V; v++) 
  
            if (!sptSet[v] && graph[u][v] && 
                dist[u] + graph[u][v] < dist[v]) 
            { 
                parent[v] = u; 
                dist[v] = dist[u] + graph[u][v]; 
            }  
    } 
  

    printSolution(dist, end, begin, parent); 
} 
  
int main() 
{ 
    int graph[V][V] = {{0, 4, 0, 0, 0, 0, 0, 8, 0}, 
                       {4, 0, 8, 0, 0, 0, 0, 11, 0}, 
                        {0, 8, 0, 7, 0, 4, 0, 0, 2}, 
                        {0, 0, 7, 0, 9, 14, 0, 0, 0}, 
                        {0, 0, 0, 9, 0, 10, 0, 0, 0}, 
                        {0, 0, 4, 0, 10, 0, 2, 0, 0}, 
                        {0, 0, 0, 14, 0, 2, 0, 1, 6}, 
                        {8, 11, 0, 0, 0, 0, 1, 0, 7}, 
                        {0, 0, 2, 0, 0, 0, 6, 7, 0} 
                    }; 
  
    dijkstra(graph, 2, 6); 
    return 0; 
}