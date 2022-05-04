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
    int n; cin>>n;
    ll a[n];ll sum = 0;
    for(int i = 0; i<n; i++){
        cin>>a[i];
        sum+=a[i];
    }
    if(n>=36){
        cout<<sum-n<<endl;
    }
    else{
        sort(a,a+n);
        sum-=n;
        for(int i = 2; i<1000000000; i++){
            ll temp = 0l;
            for(int j = 0; j<n; j++){
                temp+=abs(pow(i,(ll)j)-a[j]);
            }
            if(temp<sum)sum=temp;
            else break;
        }
        cout<<sum<<endl;
    }
    return 0;
}