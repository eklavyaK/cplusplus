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
    map<int,int> m,c;
    int n,x;cin>>n>>x;
    c[0]=1;c[n]=1;
    m[n]++;
    while(x--){
        int k; cin>>k;
        auto it = c.lower_bound(k);
        auto it2=it;
        auto it1=--it;
        if(it1->first==0 && it2->first==n){
            m.erase(n);
            m[k]++;m[n-k]++;
        }
        else if(it1->first==0){
            m[it2->first]--;
            if(m[it2->first]==0)
            m.erase(it2->first);
            m[it2->first-k]++;
            m[k]++;
        }
        else if(it2->first==n){
            m[n-it1->first]--;
            if(m[n-it1->first]==0)
            m.erase(n-it1->first);
            m[k-it1->first]++;
            m[n-k]++;
        }
        else{
            m[it2->first-it1->first]--;
            if(m[it2->first-it1->first]==0)
            m.erase(it2->first-it1->first);
            m[it2->first-k]++;
            m[k-it1->first]++;
        }
        c[k]=1;
        it = m.end();it--;
        cout<<it->first<<" ";
    }
    return 0;
}