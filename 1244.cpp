#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    scanf("%d",&n);
    vector<int> a(n+1);
    for( int i=1; i<=n; i++ ) scanf("%d",&a[i]);
    scanf("%d",&m);
    while( m-- ){
        int s, k;
        scanf("%d%d",&s,&k);
        if(s==1) for( int i=k; i<=n; i+=k ) a[i]=1-a[i];
        else{
            int l=k, r=k;
            while(1<l&&r<n&&a[l-1]==a[r+1]) l--, r++;
            for( int i=l; i<=r; i++ ) a[i]=1-a[i];
        }
    }
    for( int i=1; i<=n; i++ ){
        printf("%d ",a[i]);
        if(i%20==0) printf("\n");
    }
    return 0;
}
