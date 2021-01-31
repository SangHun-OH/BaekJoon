#include <iostream>

using namespace std;

void dfs(int n, int m, int *list, bool *visited, int cnt) {
    if (cnt == m) {
        for (int i = 0; i < m; i++) {
            cout << list[i] << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            visited[i] = true;
            list[cnt] = i;
            dfs(n, m, list, visited, cnt + 1);
            visited[i] = false;
        }
    }
}

int main() {
    int n, m;
    int list[9] = { 0, };
    bool visited[9] = { 0, };

    cin >> n >> m;
    dfs(n, m, list, visited, 0);
    return 0;
}
