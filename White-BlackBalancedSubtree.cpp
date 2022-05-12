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
    int tc;cin>>tc;
    while(tc-->0){
        int n; cin>>n;
        int a[n+1];a[1]=-2343;
        map<int,int> ch;
        map<int,pair<int,int>> m,d;
        for(int i = 2; i<n+1; i++){
            cin>>a[i];
            m[a[i]];
        }
        string s; cin>>s;
        queue<int> q;
        for(int i = 1; i<=n; i++){
            if(!m.count(i)){
                q.push(i);
            }
        }
        for(int i = 1; i<=n; i++){
            if(s[i-1]=='B'){
                d[i].second++;
                m[i].second++;
            }
            else {d[i].first++;m[i].first++;}
        }
        while(!q.empty()){
            int k = q.front();q.pop();
            int l=0,r=0;
            while(k!=1){
                if(ch[k]==0){
                    l+=d[k].first;
                    r+=d[k].second;
                }
                m[a[k]].first+=l;
                m[a[k]].second+=r;
                ch[k]=1;k=a[k];
            }
        }
        int c = 0;
        for(auto i : m){
            if(i.second.second==i.second.first){
                c++;
            }
        }
        cout<<c<<endl;
    }
    return 0;
}