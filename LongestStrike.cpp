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
        int n,k; cin>>n>>k; int a[n];
        map<int,int> m;
        for(int i = 0; i<n; i++){
            cin>>a[i];
            m[a[i]]++;
        }
        int c = -1;
        int l=-1,r=-1;
        vector<int> v;
        for(auto i : m){
            if(i.second>=k)
            v.push_back(i.first);
        }
        n=v.size();
        for(int i = 0; i<n; i++){
            int k = v[i];
            int a = v[i],b=v[i];
            while(i+1<n && v[i+1]-v[i]==1){
                b=v[i+1];i++;
            }
            if(b-a>c){
                c=b-a;
                l=a;r=b;
            }
        }
        if(c==-1){
            cout<<c<<endl;
            continue;
        }
        cout<<l<<' '<<r<<endl;
    }
    return 0;
}