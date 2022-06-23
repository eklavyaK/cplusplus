#define PROGRAM int main(){rapid_iostream;int tc=1;cin>>tc;while(tc-->0){codeforce();}return 0;}
#define Compare(u) class Comp{public: bool operator() (u a, u b){return a.F < b.F;}};
#define rapid_iostream ios_base::sync_with_stdio(0);cin.tie(0)
#define _pq(u) priority_queue<u,vector<u>, Comp>
#define binary(n,k) bitset<k>(n).to_string()
void swapp(int&a,int&b){int t=a;a=b;b=t;}
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
    int n;cin>>n;
    string s; cin>>s;
    map<char,int> m;
    for(int i=0;i<n;i++){
        m[s[i]]++;
    }
    vector<pair<int,char>> v;
    for(auto i : m){
        v.push_back({i.S,i.F});
    }
    string st = ""; int c=0;
    sort(v.begin(),v.end(),greater{});
    for(auto i : v){
        st+=string(i.F,i.S);
    }
    vector<char> ans(n);
    for(int j=0;j<3;j++){
        for(int i=j;i<n;i+=3){            //every set of three consecutive characters mustn't contain a repeated character
            ans[i]=st[c];c++;
        }
    }
    map<char,bool> check;
    for(int i=0;i<min(n,3);i++){          //first repitition will always occur in first 3 numbers otherwise repition will not occur
        if(check[ans[i]]){
            N();return;
        }
        else check[ans[i]]=true;
    }
    int k = n/3;
    for(int i=k;i>0;i--){
        int a[3];
        iota(a,a+3,i*3-3);
        do{
            if((i*3>=n || (ans[i*3]!=ans[a[1]] && ans[i*3]!=ans[a[2]])) && (i*3+1>=n ||(ans[i*3+1]!=ans[a[2]])))
            break;
        }while(next_permutation(a,a+3));
        char u[3];
        u[0]=ans[a[0]];
        u[1]=ans[a[1]];
        u[2]=ans[a[2]];
        ans[i*3-3]=u[0];
        ans[i*3-2]=u[1];
        ans[i*3-1]=u[2];
    }
    Y();
    for(auto i : ans) cout<<i; cout<<endl;
}