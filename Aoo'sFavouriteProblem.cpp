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
    int n; cin>>n;
    string s,f;cin>>s>>f;
    int ca,cb,cc;
    map<char,int> ms,mf;
    for(int i=0;i<n;i++){
        ms[s[i]]++;
        mf[f[i]]++;
    }
    if(ms['a']==mf['a'])ca=mf['a'];
    else{N();return;}
    if(ms['b']==mf['b'])cb=mf['b'];
    else{N();return;}
    if(ms['c']==mf['c'])cc=mf['c'];
    else{N();return;}
    vector<int> a,b,cca,ccb;
    ca=0,cb=0,cc=0;
    for(int i=0;i<n;i++){
        if(f[i]=='a'){
            a.push_back(cc);
            ca++;
        }
        else if(f[i]=='b'){
            b.push_back(ca);
            cb++;
        }
        else{
            cc++;
            ccb.push_back(cb);
            cca.push_back(ca);
        }
    }
    ca=0,cb=0,cc=0;
    int cnta=0,cntb=0,cntcca=0,cntccb=0;
    for(int i=0;i<n;i++){
        if(s[i]=='a'){
            if(cnta>=a.size() || a[cnta]!=cc){
                N();return;
            }
            cnta++;
            ca++;
        }
        else if(s[i]=='b'){
            if(cntb>=b.size() || b[cntb]>ca){
                N();return;
            }
            cntb++;
            cb++;
        }
        else{
            if(cntcca>=cca.size() || cca[cntcca]!=ca){
                N();return;
            }
            if(cntccb>=ccb.size() || ccb[cntccb]>cb){
                N();return;
            }
            cc++;cntccb++;cntcca++;
        }
    }
    Y();
}