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
    vector<int> arr(n);
    map<int,int> m;
    for(int i=0;i<n;i++)cin>>arr[i], m[arr[i]]++;
    for(auto i : m) if(i.S&1){
        cout<<-1<<endl;
        return;
    }
    int now = 0;
    vector<pair<int,int>> ans;
    vector<int> segments;
    function<void()> reduce = [&](){
        vector<int> ret;
        int k = 0;
        for(int i=1;i<arr.size();i++){
            if(arr[i]!=arr[0]) ret.push_back(arr[i]);
            else{
                k = i; 
                segments.push_back(k<<1);
                break;
            }
        }
        for(int i=1;i<k;i++){
            ans.push_back({now+k+i,ret[i-1]});
        }
        reverse(ret.begin(),ret.end());
        ret.insert(ret.end(),arr.begin()+k+1,arr.end());
        arr = ret, now+=(k<<1);
    };
    while(!arr.empty()) reduce();
    cout<<ans.size()<<endl;
    for(auto [a,b] : ans) cout<<a<<' '<<b<<endl;
    cout<<segments.size()<<endl;
    for(auto i : segments) cout<<i<<' ';cout<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t; while(t--)code();
    return 0;
}