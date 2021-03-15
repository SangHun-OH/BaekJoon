#include <iostream>
#include <queue>
using namespace std;
 
int a[301][301], c[301][301], d[301][301];
int cnt, t, u, uf, v, vf, I;
int dx[] = { -1,-2,-2,-1,1,2,2,1 }, dy[] = { -2,-1,1,2,2,1,-1,-2 };
 
void BFS(int i, int j)
{
    queue < pair< int, int >> q;
    q.push(make_pair(i, j));
    c[i][j] = 1;
    while (!q.empty())
    {
        //x = 행, y = 열
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 8; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (0 <= nx && nx < I && 0 <= ny && ny < I)
            {
                if (c[nx][ny] == 0)
                {
                    q.push(make_pair(nx, ny));
                    c[nx][ny] = 1; 
                    d[nx][ny] = d[x][y] + 1;//넣어주고 경로를 1더해준다
                }
            }
        }
    }
}
int main() {
    cin >> t;
    while (t--)
    {
        cin >> I;
        cin >> u >> v >> uf >> vf;
        a[u][v] = 1;
        a[uf][vf] = 2;
        BFS(u, v);
        cout << d[uf][vf] << '\n';
        cnt = 0;//56번째 줄 까지는 초기화해주는 용도
        for (int i = 0; i < 301; i++)
            for (int j = 0; j < 301; j++)
            {
                c[i][j] = 0; 
                d[i][j] = 0;
            }
        a[u][v] = 0;
        a[uf][vf] = 0;
 
    }
}
