#include <iostream>
#include <queue>
#include <vector>
using namespace std;
 
int dy[4]={1,-1,0,0};
int dx[4]={0,0,1,-1};
 
int main(){
    
    int M,N;
    cin>>M>>N;
    
    vector<vector<int>> arr(N,vector<int>(M,0)); //상자
    vector<vector<int>> visited(N,vector<int>(M,0)); //토마토 들어있는 상자 방문 유무
    queue<pair<int,int>> q;
    
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++){
            scanf("%d",&arr[i][j]);
            if(arr[i][j]==1){
                q.push(make_pair(i,j));
                visited[i][j]++;
            }
 
        }
    
    //저장될 때부터 모두 익은 경우
    if(q.size()==M*N){
        cout<<0<<endl;
        return 0;
    }
 
    int ans=0;
    while(true){
        
        //토마토가 익은 위치의 인접한 부분에서 아직 익지 않은 토마토가 있을 때
        queue<pair<int,int>> q2;
 
        while(!q.empty()){
            int y=q.front().first;
            int x=q.front().second;
            q.pop();
            
            for(int dir=0;dir<4;dir++){
                int ny=y+dy[dir];
                int nx=x+dx[dir];
                
                if(ny<0 || ny>=N || nx<0 || nx>=M)
                    continue;
                
                if(visited[ny][nx] || arr[ny][nx]!=0)
                    continue;
                
                visited[ny][nx]++;
                arr[ny][nx]=1;
                q2.push(make_pair(ny,nx));
            }
        }
        
        q=q2;
        if(q.empty()) //더이상 확인할 토마토 없는 경우
            break;
        
        
        ans++;
    }
    
    //익지 못한 토마토 있는지 확인
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            if(arr[i][j]==0){
                ans=-1;
                break;
            }
    
    
    cout<<ans<<endl;
    
    return 0;
}
