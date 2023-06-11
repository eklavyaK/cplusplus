#include<bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;



void code(){
    int n, m; cin>>n>>m;
    vector<vector<int>> a(n,vector<int>(m));
    for(int i=0;i<n;i++){
        string s; cin>>s;
        for(int j=0;j<m;j++){
            if(s[j]=='.') a[i][j] = 0;
            else a[i][j] = 1;
        }
    }
    function<bool(int,int)> check = [&](int i, int j){
        if(j>0 && i>0 && a[i][j-1]+a[i-1][j]==2) return true;
        if(i<n-1 && j<m-1 && a[i+1][j]+a[i][j+1]==2) return true;
        if(i>0 && j<m-1 && a[i-1][j]+a[i][j+1]==2) return true;
        if(i<n-1 && j>0 && a[i][j-1]+a[i+1][j]==2) return true;
        return false;
    };
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(check(i,j)){
                cout<<i+1<<' '<<j+1<<endl;
                return;
            }
        }
    }
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t=1; while(t--)code();
    return 0;
}