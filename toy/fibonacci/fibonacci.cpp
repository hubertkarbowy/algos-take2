#include <iostream>

using namespace std;

long long fibonacci (int n, long long n_2=0, long long n_1=1) {
	
	if (n==0) return n_2;
	if (n==1) return n_1;
	return fibonacci(n-1, n_1, n_2 + n_1);
}

int main(int argc, char** argv) {
	int n = 0;
	cout << "Which fibonacci number do you want to see?  n=";
	cin >> n;
	if (n<0) {
		cout << "Error, n must be greater than or equal to 0";
		return -1;
	}
	long long result = fibonacci(n);
	cout << "fib(" << n << ") = " << result;
}
