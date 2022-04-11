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
int m = (1<<30);
int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(28);cin.tie(NULL);
    int tc;cin>>tc;
    while(tc-->0){
        map<int,int> m;
        int n; cin>>n; int a[n];
        for(int i = 0; i<n; i++){
            cin>>a[i];m[a[i]]=1;
        }
        int cnt = 1;
        for(int i = 0; i<n; i++){
            cout<<a[i]<<" ";
            while(i+1<n && a[i]==a[i+1]){
                while(m[cnt]==1)cnt++;
                cout<<cnt<<" ";i++;cnt++;
            }
        }
        cout<<endl;
        vector<int> c,v(n);
        for(int i = 1; i<=n; i++){
            if(!m[i])c.push_back(i);
        }
        vector<int>::iterator it;
        for(int i = 0; i<n; i++){
            v[i]=a[i];
            it = lower_bound(c.begin(),c.end(),a[i]);
            while(i+1<n && a[i+1]==a[i]){
                i++;it--;v[i]=*it;c.erase(it);
            }
        }
        for(auto i : v) cout<<i<<" ";cout<<endl;
    }
    return 0;
}