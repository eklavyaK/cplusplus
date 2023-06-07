#include<bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;

bool func(pair<int,int> a, pair<int,int> b){
    if(a.F==b.F) return a.S>b.S;
    else return a.F<b.F;
}

void code(){
    int n; cin>>n;
    vector<pair<int,int>> arr(n);
    for(int i=0;i<n;i++)cin>>arr[i].F>>arr[i].S;
    sort(arr.begin(),arr.end(),func);
    map<int,int> m;
    int cnt = 0, ans = 0, c= 0;
    for(int i=0;i<n;i++){
        if(c<arr[i].F)ans+=arr[i].S,m[arr[i].F]++, cnt++;
        int k = 0;
        c = max(cnt,c);
        vector<int> v;
        for(auto i : m){
            if(i.F<=cnt) k+=i.S, v.push_back(i.F);
            else break;
        }
        for(auto i : v) m.erase(i);
        cnt-=k;
    }
    cout<<ans<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t; while(t--)code();
    return 0;
}