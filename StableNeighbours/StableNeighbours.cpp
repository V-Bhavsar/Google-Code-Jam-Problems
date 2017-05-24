// Example program
#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <algorithm>
#include <vector>
#include <iomanip>


int main()
{
  int tests;
  std::cin >> tests;

  for (int i=1; i<=tests; ++i) {
    int n,r,o,y,g,b,v;

    std::cin >> n >> r >> o >> y >> g >> b >> v;

    int total = n;

    char* stalls = new char[n];

    bool imp = false;

    if(r) {
      stalls[0] = 'R';
      r--;
    } else if (y) {
      stalls[0] = 'Y';
      y--;
    } else if (b) {
      stalls[0] = 'B';
      b--;
    }

    for (int i = 0; i < total-1; i++) {
      if(stalls[i] == 'R') {
        if(y && (y>=b)) {
          stalls[i+1] = 'Y';
          --y;
        } else if (y) {
          stalls[i+1] = 'B';
          --b;
        } else {
          imp = true;
        }
      }
      if(stalls[i] == 'Y') {
        if(r && (r>=b)) {
          stalls[i+1] = 'R';
          --r;
        } else if (b) {
          stalls[i+1] = 'B';
         --b;
        } else {
          imp = true;
        }
      }
      if(stalls[i] == 'B') {
        if(r && (r>=y)) {
          stalls[i+1] = 'R';
          --r;
        } else if (y) {
          stalls[i+1] = 'Y';
          --y;
        } else {
          imp = true;
        }
      }
    }
    if(stalls[0] == stalls[total-1]) {
      imp = true;
    }
    if(imp) {
      std::cout << "Case #" << i << ": " << "IMPOSSIBLE" << std::endl;
    } else {
      std::cout << "Case #" << i << ": ";
      for (int i=0; i<total; ++i) {
        std::cout << stalls[i];
      }
      std::cout << std::endl;
    }
  }
}