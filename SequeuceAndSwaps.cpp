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
        int n,x;cin>>n>>x; int a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        int k = 0, cnt = 0;
        for(int i=0;i<n;i++){
            if(a[i]>x){
                if(!is_sorted(a,a+i)){
                    cout<<-1<<endl;
                    goto end;
                }
                k = i;break;
            }
            else if(i==n-1){
                if(!is_sorted(a,a+n)){
                    cout<<-1<<endl;
                }
                else cout<<0<<endl;
                goto end;
            }
        }
        for(int i=k;i<n;i++){
            if(is_sorted(a+k,a+n)){
                cout<<cnt<<endl;
                goto end;
            }
            else if(a[i]>x){
                int temp = x;cnt++;
                x = a[i];a[i]=temp;
            }
        }
        cout<<-1<<endl;
        end:;
    }
    return 0;
}