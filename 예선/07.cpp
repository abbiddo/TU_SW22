#include <iostream>
#include <string>
using namespace std;

int main() {
	string a, b;	cin >> a >> b;
	int ai = -1, bi;
	int aa = a.length();
	int bb = b.length();

	for (int i = 0; i < aa; i++){
		for (int j = 0; j < bb; j++)
			if (a[i] == b[j]) {
				ai = i; bi = j;
				break;
			}
		if (ai != -1) break;
	}

	for (int i = 0; i < bb; i++) {
		if (i == bi) {
			cout << a;
			cout << "\n";
			continue;
		}

		for (int j = 0; j < ai; j++) cout << ".";
		cout << b[i];
		if (aa == 1) cout << "";
		else if (aa == 2) cout << ".";
		else if (ai == 0) for (int j = 0; j < aa - 1; j++) cout << ".";
		else for (int j = 0; j < aa - 2; j++) cout << ".";
		cout << "\n";
	}
}

// BA AA 오류 발견
