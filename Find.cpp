#include <iostream>
#include <string>

using namespace std;

char map[55][55];
int di[] = { 1, -1, 0, 0 };
int dj[] = { 0, 0, 1, -1 };

int n;

bool range(int x, int y) {
    if (x >= 0 && x < n && y >= 0 && y < n) return true;
    else return false;
}

int cal(int x, int y) {
    char chk = map[x][y];

    int a = 0;
    for (int i = x; i >= 0; i--) {
        if (chk == map[i][y]) a += 1;
        else break;
    }
    for (int i = x + 1; i < n; i++) {
        if (chk == map[i][y]) a += 1;
        else break;
    }

    int b = 0;
    for (int j = y; j >= 0; j--) {
        if (chk == map[x][j]) b += 1;
        else break;
    }
    for (int j = y + 1; j < n; j++) {
        if (chk == map[x][j]) b += 1;
        else break;
    }

    if (a < b) return b;
    else return a;
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < s.size(); j++) {
            map[i][j] = s[j];
        }
    }

    int result = 0;

    // 사탕 하나 고르기
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {

            // 인접한 사탕 고르기
            for (int k = 0; k < 4; k++) {
                int ni = i + di[k];
                int nj = j + dj[k];

                // 범위 확인
                if (range(ni, nj)) {

                    // 교환
                    swap(map[i][j], map[ni][nj]);

                    // 가장 긴 연속 부분 확인
                    int tmp = cal(i, j);
                    if (result < tmp) result = tmp;

                    // 상태 복원
                    swap(map[i][j], map[ni][nj]);
                }
            }
        }
    }
    cout << result << "\n";
}
