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

    int n; cin>>n;
    string s(n,'0');
    cout<<s<<endl;
    map<string,bool> m;
    m[s]=true;
    int k = pow(2,n);
    for(int i=1;i<k;i++){
        for(int j=0;j<n;j++){
            s[j]=s[j]=='0'?'1':'0';
            if(m[s]){
                s[j]=s[j]=='0'?'1':'0';
            }
            else{
                m[s]=true;
                cout<<s<<endl;
                break;
            }
        }
    }
    return 0;
}