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

    int n,z;cin>>n>>z;
    map<int,int> m;int a[n];
    for(int i=0;i<n;i++)cin>>a[i],m[a[i]]++;
    while(z--){
        int k; cin>>k;
        if(!m.size()){
            print(-1);
            continue;
        }
        auto it = m.lower_bound(k);
        if(it==m.end()){
            it--;
        }
        else if(it==m.begin()){
            if(it->first>k){
                print(-1);
                continue;
            }
        }
        else if(it->first>k){
            it--;
        }
        print(it->first);
        m[it->first]--;
        if(!m[it->first])
        m.erase(it->first);
    }
    return 0;
}