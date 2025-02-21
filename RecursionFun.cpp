#include<iostream>
using namespace std;

class Maze {
public:
    void solve() {
        if (solve(startRow, startCol))
            cout << "Success" << endl;
        else
            cout << "Could not be solved." << endl;
    }

    //Recursive method to solve the maze
    bool solve(int currR, int currC) {
        if (currR == endRow && currC == endCol) {
            maze[currR][currC] = '.';
            return true;
        }

        if (!isEmpty(currR, currC)) {
            return false;
        }

        maze[currR][currC] = '.';

        if (solve(currR, currC + 1)){
            return true;
        }

            

        if (solve(currR + 1, currC)){
            return true;
        }
           

        if (solve(currR, currC - 1)){
            return true;
        }
           

        if (solve(currR - 1, currC)){
            return true;
        }

            


        maze[currR][currC] = ' ';
        return false;

    }

    // print the current state of the maze

    void printMaze() {

        // nested for loops to iterate through maze

        for (int i = 0; i < 12; i++) {

            for (int j = 0; j < 12; j++)

                cout << maze[i][j] << ' ';

            cout << '\n';

        }// end for

    }

    bool isEmpty(int r, int c) {
        if (r >= 0 && c >= 0 && r < 12 && c < 12) {

            if (maze[r][c] == ' ')

                return true;

        }

        return false;

    }

private:
    int startRow = 2;
    int startCol = 0;
    int endRow = 4;
    int endCol = 11;

    //Maze # is a wall, space is empty, . is the path

    char maze[12][12] =
    {

        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
        {'#', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
        {' ', ' ', '#', ' ', '#', ' ', '#', '#', '#', '#', ' ', '#'},
        {'#', '#', '#', ' ', '#', ' ', ' ', ' ', ' ', '#', ' ', '#'},
        {'#', ' ', ' ', ' ', ' ', '#', '#', '#', ' ', '#', ' ', ' '},
        {'#', '#', '#', '#', ' ', '#', ' ', '#', ' ', '#', ' ', '#'},
        {'#', ' ', ' ', '#', ' ', '#', ' ', '#', ' ', '#', ' ', '#'},
        {'#', '#', ' ', '#', ' ', '#', ' ', '#', ' ', '#', ' ', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', '#'},
        {'#', '#', '#', '#', '#', '#', ' ', '#', '#', '#', ' ', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#'},
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
    };
};

int main() {
    //Print, solve and show the maze

    Maze m;
    m.solve();
    m.printMaze();
    return 0;
}
