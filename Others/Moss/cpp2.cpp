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
    string s; cin>>s;
    int n = s.size();
    int cnt = 0, last = 0;
    set<int> st;
    int index[10]{};
    bool presence[10]{};
    for(int i=0;i<10;i++){
        for(int j=cnt;j<n;j++){
            if(s[j]-'0'==i){
                presence[i] = 1;
                index[i] = j;
                cnt = j+1;
            }
        }
    }
    vector<string> ans;
    for(int i=0;i<10;i++){
        if(!presence[i])continue;
        cnt = 0;
        for(int j=last;j<=index[i];j++){
            if(s[j]-'0'==i){cnt++;st.insert(j);}
        }
        last = index[i]+1;
        ans.push_back(string(cnt,'0'+i));
    }
    int count[10]{};
    for(int i=0;i<n;i++){
        if(!st.count(i))count[s[i]-'0']++;
    }
    for(int i=0;i<9;i++){
        ans.push_back(string(count[i],'0'+i+1));
    }
    ans.push_back(string(count[9],'9'));
    sort(ans.begin(),ans.end());
    for(int i=0;i<ans.size();i++){
        cout<<ans[i];
    }
    cout<<endl;
}