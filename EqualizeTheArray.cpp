#include<bits/stdc++.h>
#define mod2 998244353ll
#define mod1 1000000007ll
#define removezeros(s) s.erase(0,s.find("1")!=-1?s.find("1"):s.length()-1)
#define binary(n,k) bitset<k>(n).to_string()
#define makeset(s,c,sizeofc) for(int i = 0; i<sizeofc; i++){s.emplace_back(c[i]);while(i+1<sizeofc && c[i+1]==c[i])i++;}
typedef long long ll;
typedef long double ld;
void Y(){std::cout<<"YES"<<std::endl;}
void N(){std::cout<<"NO"<<std::endl;}
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(28);cin.tie(NULL);
    int tc;cin>>tc;while(tc--){
        map<int,int> m;
        int n; cin>>n; int k;
        for(int i = 0; i<n; i++){
            cin>>k; m[k]++;
        }
        k = m.size();
        vector<int> c;
        int result = 0;
        for(auto i : m) 
        c.push_back(i.second);
        sort(c.begin(),c.end());
        for(int i = 0; i<k; i++){
            result=max(c[i]*(k-i),result);
        }
        cout<<n-result<<endl;
    }
    return 0;
}