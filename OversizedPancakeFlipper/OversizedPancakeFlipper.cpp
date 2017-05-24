#include <iostream>
#include <string>

int findFlips(std::string pancakes, int flipper);

int main()
{
  int n;
  std::cin >> n;

  for (int i=1; i<=n; ++i) {
    std::string pancakes;
    int flipper;
    std::cin >> pancakes;
    std::cin >> flipper;
    int flips = findFlips(pancakes, flipper);

    if (flips<0) {
      std::cout << "Case #" << i << ": " << "IMPOSSIBLE" << std::endl;
    } else {
      std::cout << "Case #" << i << ": " << flips << std::endl;
    }
  }
}

int findFlips(std::string pancakes, int flipper) {
  int count = 0;
  for (int i = 0; i <= pancakes.length() - flipper; ++i) {
    if (pancakes[i] == '-') {
      count++;
      for (int x = 0; x < flipper; ++x) {
        if(pancakes[i+x] == '-') {
            pancakes[i+x] = '+';
        } else {
          pancakes[i+x] = '-';
        }
      }
    }
  }
  for (int i = pancakes.length()-flipper+1; i <= pancakes.length(); ++i) {
    if (pancakes[i] == '-') {
      return -1;
    }
  }
  return count;
}