#include <iostream>
#include <cmath>

using namespace std;

long long findPisanoSeqLength (long long n, long long modulus) {
	long long n_2 = 0;
	long long n_1 = 1;
	
	long long result;
	int currentLength = 0;
	// printf ("0 1 ");
	for (long long i = 0; i<=modulus*modulus; i++) {
		currentLength++;
		result = (n_2 + n_1) % modulus;
		n_2 = n_1;
		n_1 = result;
		// printf ("%lli mod %lli = %lli\n", i, modulus, result);
		if (n_2 == 0 && n_1 == 1) break;
	}
	return currentLength;
}

long long fibonacciModM(long long n, long long modulus, long long pi) {
	long long n_2 = 0;
	long long n_1 = 1;
	
	long long i_mod_m = n % pi;
	
	for (int i=1; i<n%pi; i++) {
		i_mod_m = (n_2 + n_1) % modulus;
		n_2 = n_1;
		n_1 = i_mod_m;
	}
	return i_mod_m % modulus;
}

int main(int argc, char** argv) {
	long long n;
	cout << "This program finds F0^2 + F1^2 + ... + Fn^2 mod 10 for n > 2.\nGive n: ";
	cin >> n;
	if (n < 2) {
		cout << "Error, n must be greater than or equal to 2.";
		return -1;
	}
	
	const long long pi = findPisanoSeqLength(n, 10);
	cout << "Pisano period is pi(10) = " << pi << endl;
	long long fib_sum_n = fibonacciModM(n, 10, pi);
	long long fib_sum_nP1 = fibonacciModM(n+1, 10, pi);
	
	// Formula: F0^2 + F1^2 + ... + Fn^2 = Fn * Fn+1
	
	long long result = (fib_sum_n * fib_sum_nP1) % 10;
	cout << "F0^2 + F1^2 + ... + F" << n << "^2 mod 10 = (" << fib_sum_n << " * " << fib_sum_nP1 << ") mod 10 = " << result;
}
