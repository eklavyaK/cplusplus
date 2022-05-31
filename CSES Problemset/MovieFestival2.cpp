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

    int n;cin>>n;
    int k;cin>>k;
    int a[n],c=1;
    vector<pair<int,int>> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i].S>>v[i].F;
    }
    map<int,int> m;
    sort(v.begin(),v.end());
    m[v[0].F]++;
    int z = k-1;
    for(int i=1;i<n;i++){
        auto it = m.lower_bound(v[i].S);
        if(it==m.begin() && it->F>v[i].S){
            if(z>0){
                m[v[i].F]++;
                z--;c++;
            }
            continue;
        }  
        if(it==m.end()||it->F>v[i].S)it--;
        c++; m[v[i].F]++;
        m[it->F]--;
        if(m[it->F]==0)
        m.erase(it->F);
    }
    cout<<c<<endl;

    return 0;
}