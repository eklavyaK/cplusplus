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
    int n; cin>>n;
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    map<int,int> m;m[a[0]]=1;
    for(int i=1;i<n;i++){
        auto it = m.lower_bound(a[i]);
        if(it==m.end()){
            m[a[i]]++;
            continue;
        }
        if(it->first==a[i])it++;
        if(it==m.end()){
            m[a[i]]++;
            continue;
        }
        else{
            m[it->first]--;
            if(it->second==0){
                m.erase(it->first);
            }
            m[a[i]]++;
        }
    }
    int cnt = 0;
    for(auto i : m)
    cnt+=i.second;
    print(cnt);
    return 0;
}