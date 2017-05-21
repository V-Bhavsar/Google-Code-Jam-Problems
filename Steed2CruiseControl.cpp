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
    
    double d;
    int n = 0;
    std::cin >> d >> n;
    unsigned long long location[n];
    long double speed[n], annie, time;

    for (int i=0; i<n; ++i) {
      std::cin >> location[i] >> speed[i];
    }

    int pos_min;
    unsigned long long temp;
    long double temp2;

      for (int i=0; i < n-1; i++)
      {
          pos_min = i;
        
        for (int j=i+1; j < n; j++)
        {

        if (location[j] < location[pos_min])
          pos_min=j;
        }
        if (pos_min != i)
        {
          temp = location[i];
          location[i] = location[pos_min];
          location[pos_min] = temp;

          temp2 = speed[i];
          speed[i] = speed[pos_min];
          speed[pos_min] = temp2;
        }
      }

    for (int i = n; i>0; --i) {
      
      time = (d - location[i])*1.0 / speed[i];
      if ((time * speed[i-1]) > (d-location[i-1])) {
        speed[i-1] = (d - location[i-1]) * 1.0 / time;
      }
    }

    time = (d-location[0])*1.0/speed[0];
    annie = d*1.0 / time;

    std::cout << std::fixed;
    std::cout << std::setprecision(6);
    std::cout << "Case #" << i << ": " << annie << std::endl;
  }
}