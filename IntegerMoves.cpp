#include<bits/stdc++.h>
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
        int x,y; cin>>x>>y;
        if(x==0 && y==0){
            cout<<0<<endl;
        }
        else{
            ld d = pow((ll)pow(x,2)+(ll)pow(y,2),0.5);
            if((ll)d==d){
                cout<<1<<endl;
            }
            else cout<<2<<endl;
        }
    }
    return 0;
}