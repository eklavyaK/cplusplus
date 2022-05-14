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

    map<int,int> m;int n = 100;
    for(int i = 1; i<=n; i++){
        m[i]=rand()%100;
    }
    for(auto i : m)cout<<i.first<<' '<<i.second<<endl;
    cout<<endl;

    auto it  = m.lower_bound(50);            //lower_bound(val) in map returns the iterator to the key value pair where key is greater than equal to val
    cout<<it->first<<' '<<it->second<<endl;
    it = m.upper_bound(50);
    cout<<it->first<<' '<<it->second<<endl;
    cout<<endl;

    set<int> s;
    for(int i = 0; i<n; i++){
        s.insert(rand()%100);
    }
    auto itr = s.begin();
    for(; itr!=s.end(); itr++){
        cout<<*itr<<' ';
    }
    cout<<endl<<endl;
    itr = s.lower_bound(22);               //lower_bound(val) in map returns the iterator to the key value pair where key is greater than equal to val
    cout<<*itr<<endl;
    itr = s.upper_bound(22);
    cout<<*itr<<endl;
    return 0;
}