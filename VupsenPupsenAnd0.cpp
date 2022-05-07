3
2
5 5
5
5 -2 10 -9 4
7
1 2 3 4 5 6 7
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
int a[100001];
int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(28);cin.tie(NULL);
    int tc;cin>>tc;
    while(tc-->0){
        int n; cin>>n; int a[n];
        for(int i = 0; i<n; i++){
            cin>>a[i];
        }
        if(n%2){
            int x = abs(a[0]);
            int y = abs(a[1]);
            int z = abs(a[2]);
            cout<<(a[0]<0?-z:z)<<' ';
            cout<<(a[1]<0?-z:z)<<' ';
            cout<<(a[2]<0?x+y:-x-y)<<' ';
            for(int i = 4; i<n; i+=2){
                cout<<a[i]<<' '<<-a[i-1]<<' ';
            }
        }
        else{
            for(int i = 1; i<n; i+=2){
                cout<<a[i]<<' '<<-a[i-1]<<' ';
            }
        }
        cout<<endl;
    }
    return 0;
}