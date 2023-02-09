#include<bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;

int add_dig(int n){
    int sum = 0;
    while(n>0){
        sum+=n%10;
        n/=10;
    }
    return sum;
}

void code(){
    int n; cin>>n;
    if(!(n&1)){
        cout<<"NO"<<endl;
        return;
    }
    cout<<"YES"<<endl;
    int s = 3 * (n+1)/2;
    for(int i=1;i<=n;i+=2){
        cout<<i<<' '<<s-i<<endl;
        s++;
    }
    for(int i=2;i<n;i+=2){
        cout<<i<<' '<<s-i<<endl;
        s++;
    }
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t; while(t--)code();
    return 0;
}