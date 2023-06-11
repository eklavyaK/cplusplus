#include<bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;



void code(){
    int n; cin>>n;
    string s; cin>>s;
    int count[2*n-1]{};
    for(int i=0;i<2*n-1;i++){
        if(i) count[i] = count[i-1]+(s[i]=='W');
        else count[i] = (s[i]=='W');
    }
    int ans = count[n-1];
    for(int i=n;i<2*n-1;i++){
        ans = max(ans,count[i]-count[i-n]);
    }
    cout<<ans<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t = 1; while(t--)code();
    return 0;
}