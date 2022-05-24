#include<bits/stdc++.h>
#define mod2 998244353ll
#define mod1 1000000007ll
#define rapid_iostream ios_base::sync_with_stdio(0);cin.tie(0)
#define removezeros(s) s.erase(0,s.find("1")!=-1?s.find("1"):s.length()-1)
#define binary(n,k) bitset<k>(n).to_string()
#define makeset(s,c,sizeofc) for(int i = 0; i<sizeofc; i++){s.emplace_back(c[i]);while(i+1<sizeofc && c[i+1]==c[i])i++;}
typedef long long ll;
typedef long double ld;
void Y(){std::cout<<"YES"<<std::endl;}
void N(){std::cout<<"NO"<<std::endl;}
using namespace std;
int a[500000];
int main(){
    rapid_iostream;
    map<ll,bool> m;
    int n; ll x;cin>>n>>x;
    queue<pair<ll,int>> q;
    q.push({x,0});
    while(!q.empty()){
        int k=q.front().second;
        x = q.front().first;q.pop();
        string s=to_string(x);
        if(s.length()>=n){
            cout<<k<<endl;
            goto end;
        }
        vector<int> v(10);
        v[1]=1;v[0]=1;
        for(int i=0;i<s.length();i++){
            int t = s[i]-'0';
            if(!v[t]){
                ll z = x*t;
                if(m.count(z))
                continue;m[z]=true;
                q.push({z,k+1});
            }
        }
    }
    cout<<-1<<endl; end:;
    return 0;
}