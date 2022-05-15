#include<bits/stdc++.h>
#define mod2 998244353ll
#define mod1 1000000007ll
#define rapid_io ios_base::sync_with_stdio(0);cin.tie(0)
#define removezeros(s) s.erase(0,s.find("1")!=-1?s.find("1"):s.length()-1)
#define binary(n,k) bitset<k>(n).to_string()
#define makeset(s,c,sizeofc) for(int i = 0; i<sizeofc; i++){s.emplace_back(c[i]);while(i+1<sizeofc && c[i+1]==c[i])i++;}
typedef long long ll;
typedef long double ld;
void Y(){std::cout<<"YES"<<std::endl;}
void N(){std::cout<<"NO"<<std::endl;}
using namespace std;
int n,k,f;string s; 
void print(string z){
    int x = k/f;
    int r = k%f;
    for(int j = 0; j<x; j++){
        cout<<z;
    }
    for(int j = 0; j<r; j++){
        cout<<z[j];
    }
    cout<<endl;
}
int main(){
    rapid_io;
    cin>>n>>k; cin>>s;
    char c = s[0];f = n;
    for(int i = 1; i<n; i++){
        if(s[i]>c){
            f = i;
            print(s.substr(0,f));
            goto end;
        }
        else if(s[i]==c){
            if(s.substr(0,n-i)<=s.substr(i)){
                f=i;
                print(s.substr(0,f));
                goto end;
            }
        }
    }
    print(s);
    end:;
    return 0;
}