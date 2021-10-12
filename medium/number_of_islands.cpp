#include <iostream>
#include <vector>
/*
  The logic behind this algo is that we want to:
  1) Explore the islands we encounter
  2) Have a way to know which cells we've visited already
*/

// Time Complexity: O(R * C)
// Space Complexity: O(R * C)

// Implementation using a directions vector
int numIslands(vector<vector<char>>& grid) {
  // the directions we can check from one point on the grid
  vector<pair<int,int>> directions = {{-1,0}, {0,1}, {1,0}, {0,-1}};

  // Empty grids have no islands
  if(grid.size() == 0) return 0;
  else {
    // Variables storing our island count, # of rows, # of columns
    int count = 0, rows = grid.size(), columns = grid[0].size();

    // Will store grid coordinates of cells that are islands ('1')
    queue<pair<int,int>> q;

    for(int i=0; i<rows; i++) {
      for(int j=0; j<columns; j++) {

        // If an island cell, we want to push its coordinates (stored as pair<int,int>)
        if(grid[i][j] == '1') {
          q.push({i,j});
          /* We want to explore the island that we've encountered completely
             So let's check the cells to the north,south,east,west of the front of our queue
          */
          while(!q.empty()) {
            // Take the first/front coordinate in our queue
            pair<int,int> point = q.front();
            int cr = point.first;
            int cc = point.second;
            q.pop();

            // This is where our directions vector comes in
            for(const pair<int,int> & direction: directions) {
              /* For each direction, let's check that:
                 1) it's within bounds of the grid
                 2) hasn't been visited ('X')
                 3) is an island
                 and if everything checks out, add it to our queue
              */
              int nr = cr + direction.first;
              int nc = cc + direction.second;
              // what is the if doing
              if(nr >= 0 && nr < rows && nc >= 0 && nc < columns && grid[nr][nc] == '1') {
                q.push(make_pair(nr,nc));
              }
            }
            // Mark this cell as visited
            grid[cr][cc] = 'X'; // marked
          }
          //Increase the count of islands
          count++;
        }
      }
    }
    return count;
  }
}


// Without the directions vector
int numIslands1(vector<vector<char>>& grid) {
    int nr = grid.size();
    if(nr== 0)
        return 0;
    int nc = grid[0].size();
    int num = 0;
    for(int row = 0; row < nr; row++) {
        for(int col = 0; col < nc; col++) {
            if(grid[row][col] == '1') {
                num++;
                queue<pair<int,int>> neighbors;
                neighbors.push(make_pair(row,col));
                while (!neighbors.empty()) {
                    auto rc = neighbors.front();
                    neighbors.pop();
                    int row = rc.first, col = rc.second;
                    if (row - 1 >= 0 && grid[row-1][col] == '1') {
                      neighbors.push({row-1, col}); grid[row-1][col] = '0';
                    }
                    if (row + 1 < nr && grid[row+1][col] == '1') {
                      neighbors.push({row+1, col}); grid[row+1][col] = '0';
                    }
                    if (col - 1 >= 0 && grid[row][col-1] == '1') {
                      neighbors.push({row, col-1}); grid[row][col-1] = '0';
                    }
                    if (col + 1 < nc && grid[row][col+1] == '1') {
                      neighbors.push({row, col+1}); grid[row][col+1] = '0';
                    }
                }
            }
        }
    }

    return num;
}
