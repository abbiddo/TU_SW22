#include <iostream>
using namespace std;

int an, bn, n;
string a, b, c;

void check(int len, string s) {
	int index = 0;
	for (int i = 0; i < n; i++) {
		if (s[index] == c[i]) {
			for (int j = 0; j < 3; j++) {
				if (c[i] == c[i + 1]) i++;
				else break;
			}
			index++;
		}
		else if (index != 0 && s[index] != c[i]) index = 0;
		if (index == len) {
			cout << "YES\n";
			return;
		}
	}

	if (index != len) cout << "NO\n";
}

int main() {
	cin >> an >> bn >> n;
	cin.ignore();
	cin >> a >> b >> c;

	check(an, a);
	check(bn, b);
}
