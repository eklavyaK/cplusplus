#include<bits/stdc++.h>
typedef long double ld;
typedef long long ll;
using namespace std;


void code(){
    int n,m,k; cin>>n>>m>>k;
    int l = n*m/2-k;
    if(n%2==0 && m&1){
        if(l<n/2 || k&1){
            cout<<"NO"<<endl;
        }
        else cout<<"YES"<<endl;
        return;
    }
    else if(n&1 && m%2==0){
        if(k<m/2 || l&1){
            cout<<"NO"<<endl;
        }
        else cout<<"YES"<<endl;
        return;
    }
    else if(k&1){
        cout<<"NO"<<endl;
    }
    else cout<<"YES"<<endl;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t; while(t--)code();
    return 0;
}