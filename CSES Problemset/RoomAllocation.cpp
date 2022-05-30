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
    vector<pair<int,pair<int,int>>> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i].first>>v[i].second.first;
        v[i].second.second=i;
    }
    int cnt = 1, ans[n];
    sort(v.begin(),v.end());
    ans[v[0].second.second] = cnt;
    multiset<pair<int,int>> m;
    m.insert({v[0].second.first,cnt});
    for(int i=1;i<n;i++){
        auto it = m.begin();
        if(v[i].first>it->first){
            ans[v[i].second.second]=it->second;
            m.erase(it);
            m.insert({v[i].second.first,it->second});
        }
        else{
            ans[v[i].second.second]=++cnt;
            m.insert({v[i].second.first,cnt});
        }
    }
    cout<<m.size()<<endl;
    for(auto i : ans)
    cout<<i<<' ';cout<<endl;
    return 0;
}