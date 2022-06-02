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
    map<int,int> m;
    int n;cin>>n;int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int cnt = 1,l = 0;
    m[a[0]]=0;int ans = 1;
    for(int i=1;i<n;i++){
        if(!m.count(a[i])){
            m[a[i]]=i;cnt++;
        }
        else if(m[a[i]]<l){
            m[a[i]]=i;cnt++;
        }
        else{
            cnt++;
            cnt-=(m[a[i]]+1-l);
            l = m[a[i]]+1;
            m[a[i]]=i;
        }
        ans = max(cnt,ans);
    }
    print(ans);
    return 0;
}