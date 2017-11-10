#include "backtracking.h"




Backtracking::Backtracking()
{

}

std::vector<std::vector<int> > Backtracking::initMap(unsigned width,unsigned height){
      std::vector<std::vector<int> > map;
      map.resize(height);
      for (int i = 0; i < height; ++i)
          map[i].resize(width);
      for (int h = 0; h < height; h++){
            for (int w = 0; w < width; w++){
                  map[h][w] = 1;
            }
      }

      return map;
    }


bool Backtracking::isSafe(std::vector<std::vector<int> > map, int x, int y)
{
    // if (x,y outside maze) return false
    if(x >= 0 && x < 800 && y >= 0 && y < 400 && map[y][x] == 1)
        //std::cout<<"inside maze"<<std::endl;
        return true;

    return false;
}

bool Backtracking::solveUtil(std::vector<std::vector<int> >map, int x, int y,std::vector<std::vector<int> > sol)
{
    // if (x,y is goal) return true
    if(x == 760 && y == 160)
    {
        sol[y][x] = 1;
        return true;
    }

    // Check if maze[x][y] is valid
    if(isSafe(map, x, y) == true)
    {
        // mark x,y as part of solution path
        sol[y][x] = 1;

        /* Move forward in x direction */
        if (solveUtil(map, x+1, y, sol) == true){
            position temp;
            temp.x = x+1;
            temp.y = y;
            this->positions.push_front(temp);
            return true;
        }

        /* If moving in x direction doesn't give solution then
           Move down in y direction  */
        if (solveUtil(map, x, y+1, sol) == true){
            position temp;
            temp.x = x;
            temp.y = y+1;
            this->positions.push_front(temp);
            return true;
        }

        /* If none of the above movements work then BACKTRACK:
            unmark x,y as part of solution path */
        sol[y][x] = 0;
        return false;
    }

    return false;
}
bool Backtracking::solve(std::vector<std::vector<int> > map)
{
    std::vector<std::vector<int> > sol = initMap(800,400);

    if(solveUtil(map, 0, 190, sol) == false)
    {
        printf("Solution doesn't exist");
        return false;
    }

    //printSolution(sol);
    return true;
}
void Backtracking::printSolution(std::vector<std::vector<int> > sol)
{
    std::ofstream myfile;
    myfile.open ("mapBT.txt");
    for (int i = 0; i < sol.size(); i++){
        for (int j = 0; j < sol[0].size(); j++){
            printf(" %d ", sol[i][j]);
            myfile <<sol[i][j]<<", ";
            //std::cout << "Contador X: "<<j<<std::endl;
        }
        printf("\n");
        myfile <<"\n";
        //std::cout << "Contador Y: "<<i<<std::endl;
    }
    myfile.close();
}
std::vector<std::vector<int> > Backtracking::generateMap(std::list<position> data) {
    std::vector<std::vector<int> > result = initMap(800,400);
    std::cout<<"Y: "<< result.size()<<std::endl;
    std::cout<<"X: "<< result[0].size()<<std::endl;
    int counter = 0;
    for(position n : data){
        std::cout<< n.x<<", "<<n.y<<"\n";
        for(int i = n.x-20; i <= n.x+20;i++){
            for(int j = n.y-20; j <= n.y+20;j++){
                if(i<0||j<0){

                }
                else{
                    std::cout<<"Position: "<< j<<", "<<i<<std::endl;
                    result[j][i]=0;
                }
                //std::cout<<"Coordenadas: "<<j<<", "<<i<<"\n";
            }
        }

    }
    printSolution(result);
    return result;
}
