#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t;cin>>t;
    while(t-->0)
    {
        int n, m, detect = 0; cin>>n>>m; int a[n][m];
        for(int i = 0; i<n; i++) for(int j = 0; j<m; j++) cin>>a[i][j];
        for(int i = 0; i<n; i++) for(int j = 0; j<m; j++) 
        {
            if(i>0 && i<n-1 && j>0 && j<m-1 && a[i][j]<5) a[i][j] = 4;
            else if((i==0 || i==n-1) && (j==0 || j==m-1) && a[i][j]<3) a[i][j] = 2;
            else if((i==0 || i==n-1) && j<m-1 && j>0 && a[i][j]<4) a[i][j] = 3;
            else if((j==0 || j==m-1) && (i<n-1 && i>0) && a[i][j]<4) a[i][j] = 3;
            else {detect = 1; break;}
        }
        if(detect) cout<<"NO"<<endl;
        else{cout<<"YES"<<endl;
        for(int i = 0; i<n; i++) {for(int j = 0; j<m; j++) cout<<a[i][j]<<" ";cout<<endl;}
        }
    }
    return 0;
}