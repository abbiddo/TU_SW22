// 장애물 없을 경우로 단일 출력해서 14/20



// 출력 안 됨
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int arr[10][10], cnt[10][10];
int x[4] = { -1, 0, 1, 0 };
int y[4] = { 0, 1, 0, -1 };
int ma = 101;

int sx, sy, ex, ey;

queue<pair<int, int>>q;

void bfs() {
    for (int i = sx; i < 10; i++) {
        for (int j = sy; j < 10; j++) {
            if (arr[i][j] == 0) {
                q.push(make_pair(i, j));
                arr[i][j] = 1;

                while (!q.empty()) {
                    int a = q.front().first;
                    int b = q.front().second;
                    q.pop();

                    for (int k = 0; k < 4; k++) {
                        int xx = a + x[k];
                        int yy = b + y[k];

                        if (arr[xx][yy] == 0) {
                            q.push(make_pair(xx, yy));
                            arr[xx][yy] = 1;
                            cnt[xx][yy] = (cnt[a][b]) + 1;
                        }

                        if (xx == ex && yy == ey)
                            if (ma > cnt[xx][yy])
                                ma = cnt[xx][yy];
                    }
                }

            }
        }
    }

    cout << ma;
}

int main() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            char ccc;   cin >> ccc;
            if (ccc == 'R') arr[i][j] = 1;
            else {
                arr[i][j] = 0;
                if (ccc == 'L') {
                    ex = i; ey = j;
                }

                else if (ccc == 'B') {
                    sx = i, sy = j;
                }
            }
        }
    }
    bfs();
}
