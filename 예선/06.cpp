#include <iostream>
using namespace std;

int check(int n) {
	int arr[10] = { 0 };

	while (n) {
		if  ( n % 10 == 0 ) return 0;
		arr[n % 10] ++;
		if (arr[n % 10] > 1) return 0;
		n /= 10;
	}

	return 1;
}

int main() {
	int n;		cin >> n;
	n++;
	while (n <= 987654321) {
		if (check(n)) {
			cout << n;
			return 0;
		}
		n++;
	}
	if (n > 987654321) cout << 0;
}
