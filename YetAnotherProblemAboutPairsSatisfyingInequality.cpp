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
    int n; cin>>n;
    set<pair<int,int>> st;
    int done[n]{}, arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
        if(arr[i]<i+1)done[i]=1;
    }
    long long ans = 0;
    int cnt = 0;
    for(int i=0;i<n;i++){
        if(done[i]){
            cnt++;
            if(!st.empty()){
                auto it = st.lower_bound({arr[i],0});
                if(it==st.end()){
                    it--;
                    ans+=it->second;
                }
                else if(it->first>=arr[i]){
                    if(it!=st.begin()){
                        it--;
                        ans+=it->second;
                    }
                }
            }
            st.insert({i+1,cnt});
        }
    }
    cout<<ans<<endl;
}