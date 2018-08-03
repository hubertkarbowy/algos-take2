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
	long long m, n;
	cout << "This program finds Fm + Fm1 + Fm2 + ... + Fn mod 10 for 2 > m >= n Give m and n: ";
	cin >> m >> n;
	if (n < 2 || m > n) {
		cout << "Error, m must be greater than or equal to 2 and less than or equal n.";
		return -1;
	}
	long long fib_sum_n = fibonacciSumLastDigit(n);
	long long fib_sum_m = fibonacciSumLastDigit(m-1);
	long long difference = fib_sum_n - fib_sum_m; // for C++ quirk with modulo negative numbers
	cout << "Partial sum mod 10 = (" << fib_sum_n << " - " <<  fib_sum_m << ") mod 10 = " << ((difference % 10) + 10) % 10;
}
