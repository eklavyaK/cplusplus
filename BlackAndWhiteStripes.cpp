#define PROGRAM int main(){rapid_iostream;int tc=1;cin>>tc;while(tc-->0){codeforce();}return 0;}
#define Compare(u) class Comp{public: bool operator() (u a, u b){return a.F < b.F;}};
#define rapid_iostream ios_base::sync_with_stdio(0);cin.tie(0)
#define _pq(u) priority_queue<u,vector<u>, Comp>
#define binary(n,k) bitset<k>(n).to_string()
void swapp(int&a,int&b){int t=a;a=b;b=t;}
#define println(n) cout<<n<<'\n'
#define Y() cout<<"YES"<<endl
#define N() cout<<"NO"<<endl
#define MAIN void codeforce();
#define print(n) cout<<n<<' '
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
#define S second
#define F first
Compare(pii)
/***************************************************/ MAIN PROGRAM /*******************************************************/



void codeforce(){
    int n,k; cin>>n>>k;
    string s; cin>>s;
    int cntw = 0;
    for(int i=0;i<k;i++){
        if(s[i]=='W'){
            cntw++;
        }
    }
    int ans = cntw;
    for(int i=k;i<n;i++){
        if(s[i]=='W'&&s[i-k]=='B'){
            cntw++;
        }
        else if(s[i]=='B'&&s[i-k]=='W'){
            cntw--;
        }
        ans = min(cntw,ans);
    }
    cout<<ans<<endl;
}