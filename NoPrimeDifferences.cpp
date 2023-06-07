#include<bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;


void code(){
    int n,m; cin>>n>>m;
    int cnt = 0;
    if(m%2==0){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<++cnt<<' ';
            }
            cout<<endl;
        }
    }
    else if(n%2==0){
        for(int i=1;i<=n;i++){
            for(int j=0;j<m;j++){
                cout<<i+j*n<<' ';
            }
            cout<<endl;
        }
    }
    else{
        for(int i=0;i<=n/2;i++){
            for(int j=0;j<m;j++){
                cout<<1+i*m*2+j<<" ";
            }
            cout<<endl;
        }
        for(int j=0;j<m;j++){
            cout<<1+(n/2-2)*m*2+j+m<<" ";
        }
        cout<<endl;
        for(int i=0;i<n/2;i++){
            if(i==n/2-2) continue;
            for(int j=0;j<m;j++){
                cout<<1+i*m*2+j+m<<" ";
            }
            cout<<endl;
        }
    }
    cout<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t; while(t--)code();
    return 0;
}