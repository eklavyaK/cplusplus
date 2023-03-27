#include<bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;



void code(){
    int n,x,p; cin>>n>>x>>p;
    int tr = n-x, sum = 0;
    if(!(n&1)){
        sum = n/2;
        for(int i=1;i<=min(n-1,p-n);i++){
            sum+=i;
            if(sum==tr||sum%n==tr){
                cout<<"YES"<<endl;
                return;
            }
            sum%=n;
        }
    }
    sum = 0;
    for(int i=1;i<=min(n-1,p);i++){
        sum+=i;
        if(sum==tr || sum%n==tr){
            cout<<"YES"<<endl;
            return;
        }
        sum%=n;
    }
    cout<<"NO"<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t; while(t--)code();
    return 0;
}