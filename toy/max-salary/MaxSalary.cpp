/* ============================================================================
 Name        : MaxSalary.cpp
 Author      : Hubert Karbowy
 Version     :
 Copyright   : Copyleft
 Description : Largest number which can be made from a series of ints.
 Description from Coursera:

		 At the last question of a successful interview, your boss gives you a few pieces of paper
		 with numbers on it and asks you to compose a largest number from these numbers. The
		 resulting number is going to be your salary, so you are very much interested in maximizing
		 this number. How can you do this?
============================================================================ */

#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
using namespace std;

// Returns true if combining a with b gives a larger than or equal number than combining b with a.
bool begins_with_larger_digits(string a, string b) {
	string apb = a+b;
	string bpa = b+a;
	const char* a_plus_b = apb.c_str();
	const char* b_plus_a = bpa.c_str();
	// cout << "atoi(" << a_plus_b << ") = " << atoi(a_plus_b) << ", atoi(" << b_plus_a << ") = " << atoi(b_plus_a) << endl;
	if (atoi(a_plus_b) > atoi(b_plus_a)) return true;
	else if (atoi(a_plus_b) < atoi(b_plus_a)) return false;
	else return true;
}

string largest_number(vector<string> a) {
  //write your code here
  std::stringstream ret;
  string result;
  bool modif_flag = false;
  while (!a.empty()) {
	  int saved_position = 0;
	  string current_max = a[0];
	  for (size_t i = 0; i < a.size(); i++) {
		  if (begins_with_larger_digits(a[i], current_max)) {
			  saved_position = i;
			  current_max = a[i];
		  }
	  }
	  // cout << "Current max is " << current_max << " at pos " << saved_position << endl;
	  ret << current_max;
	  a.erase(a.begin() + saved_position);
  }
  ret >> result;
  return result;
}

int main() {
  int n;
  std::cin >> n;
  vector<string> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  std::cout << largest_number(a);
}
