#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool visit[51][51];
int v[51][51];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
int n, m;

void bfs(int r, int c) {
	queue<pair<int, int>> q;
	q.push(make_pair(r, c));
	visit[r][c] = 1;

	while (!q.empty()) {
		int r = q.front().first;
		int c = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int r_ = r + dy[i];
			int c_ = c + dx[i];

			if (r_ >= 0 && c_ >= 0 && r_ < n && c_ < m)
				if (v[r_][c_] && !visit[r_][c_]) {
					v[r_][c_] = v[r][c] + 1;
					visit[r_][c_] = 1;
					q.push(make_pair(r_, c_));
				}
		}
	}
}

int main() {
	int sx, sy, ex, ey;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char a; cin >> a;
			if (a == 'S') {
				sx = i; sy = j;
				v[i][j] = 1;
			}
			else if (a == 'D') {
				ex = i; ey = j;
				v[i][j] = 1;
			}
			if (v[i][j] == -1) continue;
			if (a == '.') v[i][j] = 1;
			else if (a == '*') {
				v[i][j] = 0;

				for (int k = 0; k < 4; k++) {
					int r_ = i + dy[k];
					int c_ = j + dx[k];

					if (r_ >= 0 && c_ >= 0 && r_ < n && c_ < m)
						v[r_][c_] = -1;
				}
			}
			else if (a == 'X') v[i][j] = 0;
			
		}
	}
	v[sx][sy] = 1;
	v[ex][ey] = 1;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (v[i][j] == -1) v[i][j] = 0;

	bfs(sx, sy);
	cout << v[ex][ey] - 1;
}
