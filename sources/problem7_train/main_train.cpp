#include "Train.hpp"

int main(int argc, const char * argv[]) 
{ 
    TrainTime<int> t;
    read("test.csv");
    int graphs[4][4];
    adjMatrix(graphs);
    t.bestpath(graphs, 0, 2); 
    return 0; 
}