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
map<string, bool> m;
int n;
void permutation(string str){
    m[str]=true;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            char c = str[i];
            str[i] = str[j];
            str[j] = c;
            if(m.count(str)){
                char c = str[i];
                str[i] = str[j];
                str[j] = c;
            }
            else{
                permutation(str);
            }
        }
    }
}
int main(){
    rapid_iostream;
    string s; cin>>s;
    n=s.length();
    ll cnt = 1;
    map<char,int> c;
    for(int i=0;i<n;i++){
        c[s[i]]++;cnt*=(i+1);
    }
    for(auto i : c){
        int k = 1;
        for(int j=2;j<=i.second;j++){
            k*=j;
        }
        cnt/=k;
    }
    cout<<cnt<<endl;
    permutation(s);
    for(auto i : m){
        cout<<i.first<<endl;
    }
    return 0;
}