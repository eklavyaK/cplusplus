#define PROGRAM int main(){rapid_iostream;int tc=1;cin>>tc;while(tc-->0){codeforce();}return 0;}
#define Compare(u) class Comp{public: bool operator() (u a, u b){return a.F < b.F;}};
#define rapid_iostream cin.tie(0)->sync_with_stdio(0)
#define _pq(u) priority_queue<u,vector<u>, Comp>
#define binary(n,k) bitset<k>(n).to_string()
#define println(n) cout<<n<<'\n'
#define MAIN void codeforce();
#define Y() cout<<"YES"<<endl
#define print(n) cout<<n<<' '
#define N() cout<<"NO"<<endl
#define pii pair<int,int>
#define mod1 1000000007ll
#define pli pair<ll,int>
#define pil pair<int,ll>
#define mod2 998244353ll
#include<bits/stdc++.h>
#define pll pair<ll,ll>
typedef long double ld;
typedef long long ll;
#define mp make_pair
using namespace std;
#define endl '\n'
#define S second
#define F first
Compare(pii)
/***************************************************/ MAIN PROGRAM /*******************************************************/



void codeforce(){
    int n; cin>>n;
    int arr[n];
    int cnt = 0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        if(arr[i])cnt++;
    }
    if(cnt%2){
        cout<<-1<<endl;
        return;
    }
    vector<pair<int,int>> ans;
    for(int i=0;i<n;i++){
        if(!arr[i]){
            ans.push_back({i+1,i+1});
            continue;
        }
        int k = i++;
        while(!arr[i])i++;
        if(arr[i]!=arr[k]){
            ans.push_back({k+1,i});
            ans.push_back({i+1,i+1});
        }
        else if((i-k)%2)ans.push_back({k+1,i+1});
        else{
            ans.push_back({k+1,k+1});
            ans.push_back({k+2,i+1});
        }
    }
    cout<<ans.size()<<endl;
    for(auto i : ans) cout<<i.F<<' '<<i.S<<endl;
}