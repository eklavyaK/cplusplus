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
    string s; cin>>s;
    int n = s.size();
    queue<int> q;
    int cnt = 0;
    for(int i=0;i<n;i++){
        if(s[i]=='(')cnt++;
        else if(s[i]==')')cnt--;
        else q.push(i);
        if(cnt<0){
            int index = q.front();
            s[index]='(';q.pop();
            cnt++;
        }
    }
    if(q.size()==0){
        Y(); return;
    }
    cnt = 0;
    while(!q.empty())q.pop();
    for(int i=n-1;i>=0;i--){
        if(s[i]==')')cnt++;
        else if(s[i]=='(') cnt--;
        else q.push(i);
        if(cnt<0){
            int index = q.front();
            s[index] = ')';q.pop();
            cnt++;
        }
    }
    if(q.size()==0){
        Y();return;
    }
    else{
        int k = q.size()/2-1;
        for(int i=0;i<n && k>0;i++){
            if(s[i]=='?'){
                k--;s[i]='(';
            }
        }
        k = q.size()/2-1;
        for(int i=n-1;i>=0 && k>0;i--){
            if(s[i]=='?'){
                k--;s[i]=')';
            }
        }
        k = 0;
        bool one = true, two = true;
        for(int i=0;i<n;i++){
            if(s[i]=='?'){
                if(k)cnt--;
                else{
                    cnt++;k=1;
                }
            }
            else if(s[i]==')')cnt--;
            else cnt++;
            if(cnt<0) one = false;
        }
        k = 0;
        for(int i=0;i<n;i++){
            if(s[i]=='?'){
                if(k)cnt++;
                else{
                    cnt--;k=1;
                }
            }
            else if(s[i]==')')cnt--;
            else cnt++;
            if(cnt<0) two = false;
        }
        if(one&&two)N();
        else Y();
    }
}