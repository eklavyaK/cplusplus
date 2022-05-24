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
void print(int x, int origin, int mid, int target){
    if(x==1){
        cout<<origin<<' '<<target<<endl;
    }
    else{
        print(x-1,origin,target,mid);
        cout<<origin<<' '<<target<<endl;
        print(x-1,mid,origin,target);
    }
}
int main(){
    rapid_iostream;
    int n; cin>>n;
    cout<<pow(2,n)-1<<endl;
    print(n,1,2,3);
    return 0;
}