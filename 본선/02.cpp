#include <iostream>
using namespace std;

int arr[1002][1002];

int main() {
	int n, m;	cin >> n >> m;
	int cnt = n*m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 1; i <= n + 1; i++) 
		for (int j = 1; j <= m + 1; j++) {
			cnt += abs(arr[i][j] - arr[i - 1][j]);
			cnt += abs(arr[i][j] - arr[i][j - 1]);
		}
	
	cout << cnt;
}
