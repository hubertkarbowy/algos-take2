#include <iostream>

using namespace std;

long long lcm (long long a, long long b) {
	long long mul_a = a;
	long long mul_b = b;
	
	while (true) {
		if (mul_a == mul_b) return mul_a;
		if (mul_a > mul_b) mul_b += b;
		else mul_a += a;
	}
}

int main(int argc, char** argv) {
	int a = 0, b = 0;
	cout << "Give a and b for lcm(a, b): ";
	cin >> a;
	cin >> b;
	if (a < 1 || b < 1) {
		cout << "Error, a and b must be greater than or equal to 1";
		return -1;
	}
	long long result = lcm(a, b);
	cout << "lcm(" << a << ", " << b << ") = " << result;
}
