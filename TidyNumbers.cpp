// Example program
#include <iostream>
#include <fstream>
#include <string>
#include <math.h>

bool isTidy(unsigned long long num);
unsigned long long findTidy(unsigned long long num);

int main()
{
  int n;
  std::cin >> n;

  for (int i=1; i<=n; ++i) {
    unsigned long long num;
    std::cin >> num;
    unsigned long long answer = findTidy(num);
    std::cout << "Case #" << i << ": " << answer << std::endl;
  }
}

unsigned long long findTidy(unsigned long long num) {
  unsigned long long ans = 0;
  int count = 0;
  while(!isTidy(num)) {
      unsigned long long power = 9*pow(10,count);
      ans+=power;
      if(num%10==9) {
          num/=10;
      }
      else {
          num = num / 10 - 1;
      }
      count++;
  }
  unsigned long long power = num*pow(10,count);
  ans+= power;
  return ans;
}

bool isTidy(unsigned long long num) {
    if (num < 10) {
        return true;
    }
    if ((num%10) <((num/10)%10)) {
        return false;
    } else {
        return isTidy(num/10);
    }
}