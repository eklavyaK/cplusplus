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
    long long n,m,k; cin>>n>>m>>k;
    long long arr[k], mx = 0,lx[k],rx[k];
    for(int i=0;i<k;i++){
        cin>>arr[i];
        mx = max(mx,arr[i]);
        lx[i] = (arr[i]/n)==1?0:(arr[i]/n);
        rx[i] = (arr[i]/m)==1?0:(arr[i]/m);
    }
    if(mx>=m*n){cout<<"Yes"<<endl;return;}
    sort(rx,rx+k,greater<int>());
    mx = 0; bool ans = false;
    for(int i=0;i<k;i++){
        if(n==0){
            ans = true;
            break;
        }
        else if(n==1){
            if(rx[i]>=2 && mx>=3){
                ans = true;
                break;
            }
            else break;
        }
        else{
            mx = max(rx[i],mx);
            n = max(0LL,n-rx[i]);
        }
    }
    if(n==0)ans = true;
    if(ans){cout<<"Yes"<<endl;return;}
    mx = 0; ans = false;
    sort(lx,lx+k,greater<int>());
    for(int i=0;i<k;i++){
        if(m==0){
            ans = true;
            break;
        }
        else if(m==1){
            if(lx[i]>=2 && mx>=3){
                ans = true;
                break;
            }
            else break;
        }
        else{
            mx = max(lx[i],mx);
            m = max(0LL,m-lx[i]);
        }
    }
    if(m==0)ans = true;
    if(ans){cout<<"Yes"<<endl;return;}
    cout<<"No"<<endl;
}