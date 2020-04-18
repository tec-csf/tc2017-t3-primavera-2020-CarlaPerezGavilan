#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>

#define N 4


using namespace std;



vector<vector<string> > matrix;


struct TIME
{
  int minutes;
  int hours;
};

void computeTimeDifference(struct TIME t1, struct TIME t2, struct TIME *difference)
{
    if(t2.minutes > t1.minutes)
    {
        --t1.hours;
        t1.minutes += 60;
    }
    difference->minutes = t1.minutes-t2.minutes;
    difference->hours = t1.hours-t2.hours;
}


void read(string name){
    ifstream data(name);
    string line;
    while(getline(data, line))
        {
        stringstream lineStream(line);
        string cell;
        vector<string> row;
        while(getline(lineStream, cell, ','))
        {
            row.push_back(cell);
        }
        matrix.push_back(row);

    }
}

void adjMatrix(int adj_matrix[N][N]){

   
    string stations[] = {"A", "B", "C", "D"};

    for(int i=0;i<N; i++){
        for(int j=0; j<N; j++){
            adj_matrix[i][j]=0;
        }
    }
    


    for(int a=0; a<matrix.size(); a++)
    {   
        string time_initial = matrix.at(a).at(0);
        string time_final = matrix.at(a).at(1);
        std::stringstream test_initial(time_initial);
        std::stringstream test_final(time_final);
        string inital, final;
        vector<string> initial_t, final_t;
        while(std::getline(test_initial, inital, ':'))
        {
            initial_t.push_back(inital);
        }
        while(std::getline(test_final, final, ':'))
        {
            final_t.push_back(final);
        }

       

        struct TIME t1, t2, difference;
        t1.hours = stoi(initial_t.at(0));
        t1.minutes = stoi(initial_t.at(1));
        t2.hours = stoi(final_t.at(0));
        t2.minutes = stoi(final_t.at(1));
        computeTimeDifference(t2, t1, &difference);
        
        int total = difference.hours*60 + difference.minutes;
        int row=10, column=10;
        for(int i =0; i<N; i++){
            if((matrix.at(a).at(2)).find(stations[i]) != std::string::npos){
                row = i;
            }
        }
        for(int j =0; j<N; j++){
            if((matrix.at(a).at(3)).find(stations[j]) != std::string::npos){
                column = j;
            }
        }
        adj_matrix[row][column] =  total;
    }

}

void getTimes(string station_a, string station_b){
for(int a=0; a<matrix.size(); a++){
    if((matrix.at(a).at(2)).find(station_a) != std::string::npos)
    {
        if((matrix.at(a).at(3)).find(station_b) != std::string::npos){
            cout<<matrix.at(a).at(0)<<" -- "<<matrix.at(a).at(1)<<endl;
        }

    }
}
}


