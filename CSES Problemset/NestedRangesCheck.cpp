#include<bits/stdc++.h>
#define mp make_pair
#define mod2 998244353ll
#define mod1 1000000007ll
#define rapid_iostream ios_base::sync_with_stdio(0);cin.tie(0)
#define print(n) cout<<n<<endl
typedef long long ll;
typedef long double ld;
using namespace std;
const int N=2e5+5;
int tree[N*4];
int cnt[200001];
int main(){
    rapid_iostream;

    int n;cin>>n;
    vector<pair<int,int>> v(n);
    map<pair<int,int>, int> m;
    for(int i=0;i<n;i++){
        cin>>v[i].first>>v[i].second;
        m[v[i]]=i;
    }
    int ans[n];
    sort(v.begin(),v.end(),[](pair<int,int> a, pair<int,int> b){
        if(a.first!=b.first)return a.first>b.first;
        else return a.second<b.second;
    });
    int minn = 1e9+1;
    for(int i=0;i<n;i++){
        if(v[i].second<minn){
            minn = v[i].second;
            ans[m[v[i]]]=0;
        }
        else{
            ans[m[v[i]]]=1;
        }
    }
    for(auto i : ans) cout<<i<<' ';cout<<endl;
    sort(v.begin(),v.end(),[](pair<int,int> a, pair<int,int> b){
        if(a.first!=b.first) return a.first<b.first;
        else return a.second>b.second;
    });
    int maxn = 0;
    for(int i=0;i<n;i++){
        if(v[i].second>maxn){
            maxn = v[i].second;
            ans[m[v[i]]]=0;
        }
        else{
            ans[m[v[i]]]=1;
        }
    }
    for(auto i : ans) cout<<i<<' ';cout<<endl;
    return 0;
}