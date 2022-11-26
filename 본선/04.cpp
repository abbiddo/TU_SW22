#include <iostream>
using namespace std;

char arr[2001][2001];
int sero[2001];
int garo[2001];

int main() {
	int n;		cin >> n;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == '#') {
				sero[j]++;
				garo[i]++;
				cnt++;
			}
		}
	}

	int s = 1, e = n - 2;
	int r = sero[0], l = sero[n - 1];
	while (s <= e) {
		if (r < l) r += sero[s++];
		else l += sero[e--];
	}

	int ks = 1, ke = n - 2;
	r = garo[0]; l = garo[n - 1];
	while (ks <= ke) {
		if (r < l) r += garo[ks++];
		else l += garo[ke--];
	}

	int v[4] = { 0, };
	for (int i = 0; i < s; i++) {
		for (int j = 0; j < ks; j++)
			if (arr[i][j] == '#') v[0]++;
	}

	for (int i = s; i < n; i++) {
		for (int j = 0; j < ks; j++)
			if (arr[i][j] == '#') v[1]++;
	}

	for (int i = 0; i < s; i++) {
		for (int j = ks; j < n; j++)
			if (arr[i][j] == '#') v[2]++;
	}

	for (int i = s; i < n; i++) {
		for (int j = ks; j < n; j++)
			if (arr[i][j] == '#')v[3]++;
	}

	cout << min(v[0], min(v[1], min(v[2], v[3]))) << "\n";
	cout << s << " " << ks;
}
