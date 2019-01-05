//============================================================================
// Name        : MaxNumPrizes.cpp
// Author      : Hubert Karbowy
// Version     :
// Copyright   : Copyleft
// Description : What is the maximal number (k) of pairwise distinct integers that sum up to n?
//				 = You have n candies which you want to give to as many children as possible as prizes in a contest.
//    			   Prizes have to be different and there is an unlimited number of prize-winning places in the contest.
//============================================================================

#include <iostream>
#include <vector>

using std::vector;

vector<int> optimal_summands(int n) {
  vector<int> summands;
  long long used_candies = 0;
  long long single_prize_value = 1;
  while (used_candies < n) {
	  if (used_candies + single_prize_value <= n) {
		  used_candies += single_prize_value;
		  summands.push_back(single_prize_value);
		  single_prize_value++;
	  }
	  else {
		  long long last_prize = summands[summands.size()-1];
		  summands.pop_back();
		  used_candies -= last_prize;
		  used_candies += single_prize_value;
		  summands.push_back(single_prize_value);
		  single_prize_value++;
	  }
  }
  return summands;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> summands = optimal_summands(n);
  std::cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    std::cout << summands[i] << ' ';
  }
}
