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
    ll x = 0; vector<int> a;int m = 1;
    a.push_back(0);int k = 2,cnt=1;
    while(x<1000000000){
        if(k%3==0){
            x+=4*cnt;
            cnt++;
            a.push_back(x);
        }
        else{
            x+=2*m;
            m++;
            a.push_back(x);
        }
        k++;
    }
    int tc;cin>>tc;
    while(tc-->0){
        int n; cin>>n;int c = 0;
        c = lower_bound(a.begin(),a.end(),n)-a.begin();
        cout<<c+1<<endl;
    }
    return 0;
}