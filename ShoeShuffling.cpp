#define rapid_iostream ios_base::sync_with_stdio(0);cin.tie(0)
#define binary(n,k) bitset<k>(n).to_string()
#include<bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define mod2 998244353ll
#define mod1 1000000007ll
#define print(n) cout<<n<<endl
typedef long long ll;
typedef long double ld;
void Y(){std::cout<<"YES"<<std::endl;}
void N(){std::cout<<"NO"<<std::endl;}
using namespace std;

int main(){
    rapid_iostream;
    int tc;cin>>tc;
    while(tc-->0){
        int n; cin>>n;
        map<int,int> m;
        int ans[n];
        vector<pair<int,int>> v(n);
        for(int i=0;i<n;i++){
            cin>>v[i].F;
            v[i].S=i;
            m[v[i].F]++;
        }
        sort(v.begin(),v.end());
        for(auto i : m){
            if(i.S==1){
                cout<<-1<<endl;
                goto end;
            }
        }
        for(int i=0;i<n;i++){
            int k = i;
            while(i+1<n && v[i].F==v[i+1].F){
                i++;
                ans[v[i].S]=v[i-1].S;
            }
            ans[k]=v[i].S;
        }
        for(auto i : ans)cout<<i+1<<' ';
        cout<<endl;end:;

    }
    return 0;
}