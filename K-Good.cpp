#include<bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;



void code(){
    int n; cin>>n;
    if(n&1){
        cout<<2<<endl;
        return;
    }
    int c = n;
    while(n%2==0)n/=2;
    if(n>1 && ceil((ld)c/n)>=(n+1)/2){
        cout<<n<<endl;
        return;
    }
    n = 2*c/n;
    if((c-n/2)%n==0 && ceil((ld)2*c/n)>=n+1){
        cout<<n<<endl;
        return;
    }
    else cout<<-1<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t; while(t--)code();
    return 0;
}