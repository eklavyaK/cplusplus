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

    map<int,vector<int>> m;
    int n; cin>>n; int a[n];
    int x; cin>>x;
    for(int i=0;i<n;i++){
        cin>>a[i];
        m[a[i]].push_back(i);
    }
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            int sum = a[i]+a[j];
            if(m.count(x-sum)){
                for(auto k : m[x-sum]){
                    if(k!=i && k!=j){
                        cout<<i+1<<' '<<j+1<<' '<<k+1;
                        exit(0);
                    }
                }
            }
        }
    }
    print("IMPOSSIBLE");
    return 0;
}