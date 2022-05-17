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

int main(){
    rapid_iostream;
    int tc;cin>>tc;
    while(tc-->0){
        int n; cin>>n; int a[n];
        for(int i = 0; i<n; i++){
            cin>>a[i];
        }
        vector<int> v;
        for(int i = 0; i<n; i++){
            if(a[i]==1){
                v.push_back(1);
                cout<<v[0];
                for(int j = 1; j<v.size(); j++){
                    cout<<'.'<<v[j];
                }
                cout<<endl;
            }
            else if(a[i]!=v[v.size()-1]+1){
                v.pop_back();
                int j = v.size()-1;
                while(j>=0 && v[j]!=a[i]-1){
                    j--;v.pop_back();
                }
                v[j]++;
                cout<<v[0];
                for(int j = 1; j<v.size(); j++){
                    cout<<'.'<<v[j];
                }
                cout<<endl;
            }
            else{
                v[v.size()-1]++;
                cout<<v[0];
                for(int j = 1; j<v.size(); j++){
                    cout<<'.'<<v[j];
                }
                cout<<endl;
            }
        }
    }
    return 0;
}