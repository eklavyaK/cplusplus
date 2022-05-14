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
        ll cnt = 0;
        int n,m; cin>>n>>m;
        int a[n*m+1];
        map<int,vector<int>> c;
        for(int i = 1; i<=n*m; i++){
            cin>>a[i];
            c[a[i]].push_back(i);
        }
        int r=0;
        int v[n][m],t[n][m];
        for(auto i : c){
            for(auto j : i.second){
                v[r/m][r%m]=j;
                t[r/m][r%m]=i.first;
                r++;
            }
        }
        for(int i = 0; i<n; i++){
            int j = 0;
            while(j<m && t[i][0]==t[i][j])j++;
            for(;j<m;){
                int k = j;
                while(j<m && t[i][k]==t[i][j]){
                    for(int r = 0; r<k; r++){
                        if(v[i][j]>v[i][r])cnt++;
                    }
                    j++;
                }
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}