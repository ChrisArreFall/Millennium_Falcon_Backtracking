#ifndef BACKTRACKING_H
#define BACKTRACKING_H
#include <iostream>
#include <list>
#include <vector>
#include <fstream>

struct position{
public:
    int x,y;
};

class Backtracking
{
public:
    Backtracking();
    std::list<position> positions;
    bool isSafe(std::vector<std::vector<int> > map, int x, int y);
    bool solveUtil(std::vector<std::vector<int> > map, int x, int y,std::vector<std::vector<int> > sol);
    bool solve(std::vector<std::vector<int> > map);
    std::vector<std::vector<int> > generateMap(std::list<position> data);
    void printSolution(std::vector<std::vector<int> > sol);
    std::vector<std::vector<int> > initMap(unsigned height, unsigned width);
};



#endif // BACKTRACKING_H
