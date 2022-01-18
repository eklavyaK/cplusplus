#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t;cin>>t;
    while(t-->0)
    {
        int n,m; cin>>n>>m;int a[n][m];map<int,int> map;
        for(int i = 0; i<n; i++) for(int j = 0; j<m; j++) cin>>a[i][j];
        int tempi = -1, tempj = -1, temp_min=0;
        for(int r = 0; r<m; r++)
        {
            int min = INT_MAX;
            for(int i = 0; i<n; i++)
                for(int j = 0; j<m; j++) {if(min>a[i][j]) if(map[j]!=i+1){min = a[i][j]; tempi = i; tempj = j;}}
            int temp = a[tempi][r];
            a[tempi][r] = a[tempi][tempj];
            a[tempi][tempj] = temp;
            map[r] = tempi+1;
        }
        for(int i = 0; i<n; i++) {for(int j = 0; j<m; j++) cout<<a[i][j]<<" ";cout<<endl;}
    }
    return 0;
}