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
        int a,b; cin>>a>>b;
        int cnt=0,t=0,c=b;
        if(b==1)t++,cnt++;int k = a;
        while(k>0){k/=(c+t);cnt++;}
        while(true){
            k=a;c++;int temp=0;
            while(k>0){k/=c;temp++;}
            if(c-b+temp<=cnt){
                cnt=temp+c-b;
            }
            else break;
        }
        cout<<cnt<<endl;
    }
    return 0;
}