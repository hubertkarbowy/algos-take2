#include <iostream>

using namespace std;

long long gcd (long long a, long long b) {
	long long remainder = a % b;
	if (remainder == 0 ) return b;
	else return gcd (b, remainder);
}

int main(int argc, char** argv) {
	int a = 0, b = 0;
	cout << "Give a and b for gcd(a, b): ";
	cin >> a;
	cin >> b;
	if (b > a) {
		cout << "Error, b must be greater than or equal to a";
		return -1;
	}
	if (a < 0 || b < 0) {
		cout << "Error, a and b must be greater than zero.";
		return -1;
	}
	long long result = gcd(a, b);
	cout << "gcd(" << a << ", " << b << ") = " << result;
}
