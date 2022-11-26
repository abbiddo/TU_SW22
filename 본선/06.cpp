#include <iostream>
using namespace std;
int arr[1000002], dp[1000002], re, n, m;
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		dp[i] = arr[i];
	}

	for (int i = 2; i <= m; i++)
		for (int j = n; j >= i; j--)
			dp[j] = dp[j - 1] + arr[j];

	for (int i = 1; i <= n; i++)
		re = max(re, dp[i]);

	for (int i = m + 1; i <= n; i++) {
		dp[i] = max(dp[i], dp[i - 1] + arr[i]);
		re = max(re, dp[i]);
	}

	cout << re;
}
