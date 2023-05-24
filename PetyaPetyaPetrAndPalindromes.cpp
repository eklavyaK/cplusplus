#include<bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;



void code(){
    int n,k; cin>>n>>k;
    vector<int> arr(n+1);
    for(int i=1;i<=n;i++) cin>>arr[i];
    function<int(int)> compute = [&](int c){
        map<int,int> m;
        int cnt = 0, ans = 0, l = c, r = c;
        for(int i=c;i<=n;i+=2){
            int x = max(k,i), y = min(i+k/2-1,n);
            int nr = i-(i+k/2-y)*2+2, nl = i-(i+k/2-x)*2;
            while(l>nl)l-=2,m[arr[l]]++,cnt++;
            while(l<nl)m[arr[l]]--,l+=2,cnt--;
            while(r<nr)m[arr[r]]++,r+=2,cnt++;
            while(r>nr)r-=2,m[arr[r]]--,cnt--;
            ans += cnt-m[arr[i]];
        }
        return ans;
    };
    cout<<compute(k/2+2)+compute(k/2+3)<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t = 1; while(t--)code();
    return 0;
}