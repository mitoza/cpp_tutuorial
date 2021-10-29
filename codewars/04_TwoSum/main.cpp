// main.cpp
#include <iostream>
#include <vector>

using namespace std;

std::pair<std::size_t, std::size_t> two_sum(const std::vector<int>& numbers, int target) {
  for(auto i=0; i<numbers.size(); i++) {
    for(auto j=i+1; j<numbers.size(); j++) {
      if (numbers[i] + numbers[j] == target) return {i, j};
    }
  }

  return {-1, -1};
}

int main(int argc, char** argv) {

  std::vector<int> nums;
  nums.push_back(1);
  nums.push_back(2);
  nums.push_back(3);
  int target = 4;

  std::pair<std::size_t, std::size_t> twoSum = two_sum(nums, target);
  cout << "End: " << twoSum.first << ", " << twoSum.second << endl;

  return 0;
}
