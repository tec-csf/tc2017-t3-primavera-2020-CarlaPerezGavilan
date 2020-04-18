/*
 * This file is part of {{tc2017-t3-primavera-2020-CarlaPerezGavilan}}.
 * 
 * adj_matrix.cpp
 * Carla Pérez Gavilán Del Castillo
 * Divide & Conquer
 * 17/abril/2020
 * Copyright © 2020 Carla Pérez Gavilán Del Castillo. All rights reserved.
 * 
 */

#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>

#define N 4





std::vector<std::vector<std::string> > matrix;


struct TIME
{
  int minutes;
  int hours;
};

/**
 * Substract two times and return difference in hours and minutes 
 *
 * @param[in] Time 1 expressed in hours: minutes 
 * @param[in] Time 2 expressed in hours: minutes 
 * @param[in] difference in time is stored in this variable 
 */
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

/**
 * Read csv file that stores time table 
 *
 * @param[in] Name of file to be read 
 */
void read(std::string name)
{
    std::ifstream data(name);
    std::string line;
    while(std::getline(data, line))
        {
        std::stringstream lineStream(line);
        std::string cell;
        std::vector<std::string> row;
        while(std::getline(lineStream, cell, ','))
        {
            row.push_back(cell);
        }
        matrix.push_back(row);

    }
}

/**
 * Turns timetable read in csv file into an adjacency Matrix 
 *
 * @param[in] matrix in which adjacency will be stored 
 */
void adjMatrix(int adj_matrix[N][N])
{

   
    std::string stations[] = {"A", "B", "C", "D"};

    for(int i=0;i<N; i++){
        for(int j=0; j<N; j++){
            adj_matrix[i][j]=0;
        }
    }
    


    for(int a=0; a<matrix.size(); a++)
    {   
        std::string time_initial = matrix.at(a).at(0);
        std::string time_final = matrix.at(a).at(1);
        std::stringstream test_initial(time_initial);
        std::stringstream test_final(time_final);
        std::string inital, final;
        std::vector<std::string> initial_t, final_t;
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
        for(int i =0; i<N; i++)
        {
            if((matrix.at(a).at(2)).find(stations[i]) != std::string::npos)
            {
                row = i;
            }
        }
        for(int j =0; j<N; j++)
        {
            if((matrix.at(a).at(3)).find(stations[j]) != std::string::npos)
            {
                column = j;
            }
        }
        adj_matrix[row][column] =  total;
    }

}

/**
 * Prints all the available times for source to destination  
 *
 * @param[in] source station
 * @param[in] final destination 
 */
void getTimes(std::string station_a, std::string station_b)
{
    for(int a=0; a<matrix.size(); a++)
    {
        if((matrix.at(a).at(2)).find(station_a) != std::string::npos)
        {
            if((matrix.at(a).at(3)).find(station_b) != std::string::npos)
            {
                std::cout<<matrix.at(a).at(0)<<" -- "<<matrix.at(a).at(1)<<std::endl;
            }

        }
    }
}


