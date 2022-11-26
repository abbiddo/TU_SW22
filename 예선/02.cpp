#include <iostream>
using namespace std;

int main() {
	int n;		cin >> n;
	int s = 0, t = 0;
	int s_sum = 0, t_sum = 0;
	int win = 0, winner = 0;

	for (int i = 0; i < n; i++) {
		cin >> s_sum >> t_sum;
		s += s_sum;
		t += t_sum;

		if (s > t && win < s - t) {
			winner = 1;
			win = s - t;
		}
		else if (s < t && win < t - s) {
			winner = 2;
			win = t - s;
		}
	}

	cout << winner << " " << win;
}
