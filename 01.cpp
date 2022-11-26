#include <iostream>
using namespace std;
char arr[102][102];

int main() {
	int n, m;	cin >> n >> m;
	cin.ignore();
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < m; j++) 
			cin >> arr[i][j];

	for (int i = n-1; i >=0; i--)
		for (int j = m-1; j >=0; j--)
			if (arr[i][j] == '#') {
				arr[i + 1][j] = '#';
				arr[i][j + 1] = '#';
				arr[i + 1][j + 1] = '#';
			}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cout << arr[i][j];
		cout << "\n";
	}
}
