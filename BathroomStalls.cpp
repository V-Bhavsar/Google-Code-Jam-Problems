#include <iostream>
#include <string>
#include <algorithm>
#include <vector>


unsigned long long findSpot(std::vector<char> stalls);
std::vector<char> populate(std::vector<char> stalls, unsigned long long numPeople);
unsigned long long calcLS(std::vector<char> stalls, unsigned long long spot);
unsigned long long calcRS(std::vector<char> stalls, unsigned long long spot);


int main()
{
  int n;
  std::cin >> n;

  for (int i=1; i<=n; ++i) {
    unsigned long long numStalls, numPeople;
    std::cin >> numStalls >> numPeople;
    std::vector<char> stalls;
    
    for (unsigned long long i = 0; i < numStalls; ++i)  stalls.push_back('.');
    stalls = populate(stalls, numPeople);
    unsigned long long finalSpot = findSpot(stalls);
    stalls[finalSpot] = 'o';
    unsigned long long LS = calcLS(stalls, finalSpot);
    unsigned long long RS = calcRS(stalls, finalSpot);
    
    std::cout << "Case #" << i << ": " << std::max(LS, RS) << " " << std::min(LS, RS) << std::endl;
  }
}


std::vector<char> populate(std::vector<char> stalls, unsigned long long numPeople) {
  for (unsigned long long i = 1; i < numPeople; ++i) {
    unsigned long long spot = findSpot(stalls);
    stalls[spot] = 'o';
  }
  return stalls;
}

unsigned long long findSpot(std::vector<char> stalls) {
  unsigned long long count, longestCount, start, longestStart = 0;
  for (unsigned long long i = 0; i < stalls.size(); i++) {
    if (stalls[i] == '.') count++; 
    else {
      if (count > longestCount) {
        longestCount = count;
        longestStart = start;
      }
      count = 0;
      start = i+1;
    }
    if (count > longestCount) {
        longestCount = count;
        longestStart = start;
      }
  }
  return (longestStart + ((longestCount - 1)/2));
}

unsigned long long calcLS(std::vector<char> stalls, unsigned long long spot) {
  unsigned long long count = 0;
  unsigned long long iterator = spot - 1;
  if(iterator == 0 && stalls[0] == '.'){
    count++;
    iterator--;
  }
  while (iterator > 0 && stalls[iterator] == '.') {
      count++;
      iterator--;
  }
  return count;
}

unsigned long long calcRS(std::vector<char> stalls, unsigned long long spot) {
  unsigned long long count = 0;
  unsigned long long iterator = spot + 1;
  if(iterator == (stalls.size()-1) && stalls[stalls.size()-1] == '.') {
    count++;
    iterator++;
  }
  while (iterator < stalls.size() && stalls[iterator] == '.') {
      count++;
      iterator++;
  }
  return count;
}

