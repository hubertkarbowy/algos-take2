#include <iostream>
#include <map>
#include <vector>

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
	long long m, n;
	cout << "This program finds fib(n) mod m. Give n and m: ";
	cin >> n >> m;
	if (m < 2) {
		cout << "Error, m must be greater than or equal to 2.";
		return -1;
	}
	long long pi = findPisanoSeqLength(n, m);
	cout << "Pisano period is pi(" << m << ") = " << pi << endl;
	long long reduced = n % pi;
	long long result = fibonacciModM(n, m, pi);
	cout << "fib (" << reduced << ") mod " << m << " = " << result;
}
