#include <iostream>
using namespace std;

char arr[1001][1001];
int n, m;

int square(int r, int c) {
	int cnt = 1;
	if (arr[r][c] == 'T') return 0;
	for (int i = 1; i + r < n && i + c < m; i++) {
		for (int j = 0; j <= i; j++) {
			for (int k= 0; k <= i; k++) {
				if (arr[r + j][c + k] == 'T') return cnt;
			}
		}
		cnt++;
	}
	return cnt;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	int re = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			re = max(re, square(i, j));
		}
	}

	cout << re;
}
