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
    int n,k; cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    if(n==1){
        cout<<0<<endl;
        return;
    }
    function<bool(int)> check = [&](int diff){
        for(int i=1;i<=a[0];i++){
            int l = i, r = i+diff;
            bool pass = true;
            for(int j=0;j<n;j++){
                int st = max(1,a[j]/(r+1));
                int en = min(k,a[j]/l);
                bool f = true;
                for(int m=st;m<=en;m++){
                    if(a[j]/m>=l && a[j]/m<=r){
                        f = false; break;
                    }
                }
                if(f){
                    pass = false; break;
                }
            }
            if(pass)return true;
        }
        return false;
    };
    int l = 0, r = 3e3;
    while(l<=r){
        int mid = (l+r)/2;
        if(check(mid))r=mid-1;
        else l=mid+1;
    }
    cout<<r+1<<endl;
}