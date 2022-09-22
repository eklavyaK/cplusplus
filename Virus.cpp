
#define PROGRAM int main(){rapid_iostream;int tc=1;cin>>tc;while(tc-->0){codeforce();}return 0;}
#define Compare(u) class Comp{public: bool operator() (u a, u b){return a.F < b.F;}};
#define rapid_iostream ios_base::sync_with_stdio(0);cin.tie(0)
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
    int n,m; cin>>n>>m;
    vector<int> arr(m);
    for(int i=0;i<m;i++){
        cin>>arr[i];
    }
    sort(arr.begin(),arr.end());
    arr.push_back(n+arr[0]);
    vector<int> range(m);
    for(int i=0;i<m;i++){
        range[i] = arr[i+1]-arr[i]-1;
    }
    sort(range.begin(),range.end(),greater<int>());
    int ans = 0, cnt = 0;
    for(int i=0;i<m;i++){
        range[i]-=2*cnt;
        if(range[i]==1){
            ans++; cnt++;
        }
        else if(range[i]==2){
            ans++;cnt++;
        }
        else if(range[i]>=3){
            range[i]--;
            ans+=range[i];
            cnt+=2;
        }
    }
    cout<<n-ans<<endl;
}