#include <iostream>

using namespace std;

long long fibonacciSumLastDigit(long long n) {
	long long n_2 = 0;
	long long n_1 = 1;
	long long i_last=0;
	
	for (int i=2; i<=n+2; i++) {
		i_last = (n_2 + n_1) % 10;
		n_2 = n_1;
		n_1 = i_last;
	}
	return (i_last-1) % 10;
}

int main(int argc, char** argv) {
	long long n;
	cout << "This program finds sum(Fn) mod 10. Give n: ";
	cin >> n;
	if (n < 2) {
		cout << "Error, m must be greater than or equal to 2.";
		return -1;
	}
	long long result = fibonacciSumLastDigit(n);
	cout << "sum (F" << n << ") mod 10 = " << result;
}
