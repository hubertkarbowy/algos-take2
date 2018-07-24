#include <iostream>

using namespace std;

// computes the last digit of a (potentially very large) nth Fibonacci number
long long fibonacci_loop (int n) {
	
	long long n_2 = 0;
	long long n_1 = 1;
	if (n==0) return 0;
	else if (n==1) return 1;
	
	long long result;
	for (int i = 2; i<=n; i++) {
		result = (n_2 + n_1) % 10;
		n_2 = n_1;
		n_1 = result;
	}
	return result;
}

long long fibonacci_tailrecursive (int n, long long n_2=0, long long n_1=1) {
	
	if (n==0) return n_2;
	if (n==1) return n_1;
	return fibonacci_tailrecursive(n-1, n_1 % 10, (n_2 + n_1) % 10);
}

void stress_test_fibonacci (int n) {
	for (int i=0; i<=n; i++) {
		long long result_loop = fibonacci_loop(i);
		long long result_tailrecursive = fibonacci_tailrecursive(i, 0, 1);
		if (result_loop == result_tailrecursive) cout << result_loop << " == " << result_tailrecursive << " [OK]" << endl;
		else cout << result_loop << " != " << result_tailrecursive << " [FAIL]";
	}
}
//~ 
int main(int argc, char** argv) {
	int n = 0;
	cout << "Show the last digit of the nth Fibonacci number where  n=";
	cin >> n;
	if (n<0) {
		cout << "Error, n must be greater than or equal to 0";
		return -1;
	}
	long long result_loop = fibonacci_loop(n);
	long long result_tailrecursive = fibonacci_tailrecursive(10, 0, 1);
	cout << "fib(" << n << ") = " << result_loop << " / " << result_tailrecursive;
	stress_test_fibonacci(n);
}
