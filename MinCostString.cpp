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
    int n,k;cin>>n>>k;
    map<char,map<char,int>> m;
    for(int i = 0; i<k; i++){
        for(int j = 0; j<k; j++){
            m['a'+i]['a'+j];
        }
    }
    char c[n]; c[0]='a';
    for(int j = 1; j<n; j++){
        int min = 1e9; char ch;
        for(auto i : m[c[j-1]]){
            if(i.second<=min){
                ch=i.first;
                min=i.second;
            }
        }
        m[c[j-1]][ch]++;
        c[j]=ch;
    }
    for(int i = 0; i<n; i++){
        cout<<c[i];
    }
    cout<<endl;
    return 0;
}