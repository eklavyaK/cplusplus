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
vector<int> ans;
ll findlcm(){
    ll ret = ans[0];
    for (int i = 1; i < ans.size(); i++)
    ret = (((ans[i] * ret)) /(gcd(ans[i], ret)));
    return ret;
}
int k[200];
void codeforce(){
    int cnt = 0;
    ans.clear();
    int n; cin>>n; int a[n];
    fill(k,k+n,0);
    string s; cin>>s;
    vector<vector<int>> st;
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;i++){
        if(k[i]==1)continue;
        int f = i+1;
        k[i]=1;
        st.push_back({i});
        while(a[f-1]!=i+1){
            f=a[f-1];
            k[f-1]=1;
            st[cnt].push_back(f-1);
        }
        cnt++;
    }
    for(auto i: st){
        int r = 1; string z = "";
        for(int j=0;j<i.size();j++){
            z+=s[i[j]];
        }
        if(z.size()<=1){
            ans.push_back(1);
            continue;
        }
        string temp = z;
        while(true){
            char c = temp[0];
            temp = temp.substr(1)+c;
            if(temp!=z){
                r++; 
            }
            else break;
        }
        ans.push_back(r);
    }
    cout<<findlcm()<<endl;
}