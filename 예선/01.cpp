#include <iostream>
using namespace std;

int main() {
	int n;		cin >> n;
	cin.ignore();
	string s;	cin >> s;
	int cnt = 0;

	for (int i = 0; i < n; i++)
		if (s[i] == 'L') cnt++;

	if (cnt) 	cout << n - cnt / 2 + 1;
	else cout << n;
}
