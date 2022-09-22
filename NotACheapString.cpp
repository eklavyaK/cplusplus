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
    string temp = s;
    int p; cin>>p;
    int arr[26]{}, cnt = 0;
    sort(s.begin(),s.end());
    long long now = 0;
    for(int i=0;i<n;i++){
        now+=(s[i]-'a'+1);
    }
    for(int i=n-1;i>=0;i--){
        if(now>p){
            now-=(s[i]-'a'+1);
            arr[s[i]-'a']++;
            cnt++;
        }
        else break;
    }
    if(n-cnt<=0){
        cout<<""<<endl;
        return;
    }
    string ans(n-cnt,' ');cnt=0;
    for(int i=0;i<n;i++){
        if(arr[temp[i]-'a']==0){
            ans[cnt++]=temp[i];
        }
        else arr[temp[i]-'a']--;
    }
    cout<<ans<<endl;
    cout.flush();
}