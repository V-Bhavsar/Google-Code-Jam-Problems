#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <algorithm>
#include <vector>


int main()
{
  int n;
  std::cin >> n;

  for (int i=1; i<=n; ++i) {
    int r;
    int c;
    std::cin >> r >> c;
    char** grid = new char*[r];
    for(int i = 0; i < r; ++i)
      grid[i] = new char[c];

    std::vector<char> v;
    for(int i=0; i<r; i++) {
      for(int j=0; j<c; j++) {
        char initial;
        std::cin >> initial;
        grid[i][j] = initial;
      }
    }
    for(int i=0; i<r; i++) {
      char curr = '?';
      for(int j=0; j<c; j++) {
        if(grid[i][j] != '?') {
          curr = grid[i][j];
        } else {
          grid[i][j] = curr;
        }
      }
    }
    for(int i=0; i<r; i++) {
      char curr = '?';
      for(int j=c-1; j>=0; j--) {
        if(grid[i][j] != '?') {
          curr = grid[i][j];
        } else {
          grid[i][j] = curr;
        }
      }
    }
    for(int j=0; j<c; j++) {
      char curr = '?';
      for(int i=0; i<r; i++) {
        if(grid[i][j] != '?') {
          curr = grid[i][j];
        } else {
          grid[i][j] = curr;
        }
     }
    }
    for(int j=0; j<c; j++) {
      char curr = '?';
      for(int i=r-1; i>=0; i--) {
        if(grid[i][j] != '?') {
          curr = grid[i][j];
        } else {
          grid[i][j] = curr;
        }
     }
    }

    std::cout << "Case #" << i << ":" << std::endl;

    for(int i=0; i<r; i++) {
      for(int j=0; j<c; j++) {
        std::cout << grid[i][j];
      }
        std::cout << std::endl;
    }
  }
}