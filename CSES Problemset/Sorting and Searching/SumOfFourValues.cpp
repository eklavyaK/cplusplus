#include<bits/stdc++.h>
#define mp make_pair
#define mod2 998244353ll
#define mod1 1000000007ll
#define rapid_iostream ios_base::sync_with_stdio(0);cin.tie(0)
#define removezeros(s) s.erase(0,s.find("1")!=-1?s.find("1"):s.length()-1)
#define binary(n,k) bitset<k>(n).to_string()
#define makeset(s,c,sizeofc) for(int i = 0; i<sizeofc; i++){s.emplace_back(c[i]);while(i+1<sizeofc && c[i+1]==c[i])i++;}
#define print(n) cout<<n<<endl
typedef long long ll;
typedef long double ld;
void Y(){std::cout<<"YES"<<std::endl;}
void N(){std::cout<<"NO"<<std::endl;}
using namespace std;

int main(){
    rapid_iostream;

    int n;cin>>n;
    int a[n];
    int x;cin>>x;
    map<int,vector<pair<int,int>>> m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            int sum = a[i]+a[j];
            if(m.count(x-sum)){
                for(auto [u,v] : m[x-sum])
                if(u!=i && v!=i && v!=j){ 
                cout<<i+1<<' '<<j+1
                <<' '<<u+1<<' '<<v+1;
                exit(0);}
            }
            m[sum].push_back({i,j});
        }
    }
    print("IMPOSSIBLE");
    return 0;
}