#include <iostream>
using namespace std;
int arr[100001];
int dp[100001];
int main() {
	int s, m, e;		cin >> s >> m >> e;
	int n;		cin >> n;
	int end;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		if (arr[i]) end = i;
	}

	int k = 1;
	while (!arr[k]) k++;
	int save = k;
	dp[k] = s + m;
	for (int i = k + 1; i <= end; i++) {
		if (!arr[i]) dp[i] = dp[i - 1] + m;
		else {
			dp[i] = min(dp[save] + s + m + e, dp[i - 1] + m);
			save = i;
		}
	}
	cout << dp[n] + e;
}
