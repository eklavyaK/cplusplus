#include<bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;

const int modulo = 998244353;
int f[305][180005], arr[305];
void code(){
    int n; cin>>n;
    for(int i=0;i<n;i++)cin>>arr[i];
    f[0][arr[0]] = f[1][arr[1]] = 1;
    for(int k=1;k<n-1;k++){
        for(int i=-90000;i<=90000;i++){
            int curr = f[k][i+(i<0)*180001];
            int c = arr[k+1]+i, d = arr[k+1]-i;
            f[k+1][c+(c<0)*180001]=(f[k+1][c+(c<0)*180001]+curr)%modulo;
            if(i!=0)f[k+1][d+(d<0)*180001]=(f[k+1][d+(d<0)*180001]+curr)%modulo;
        }
    }
    int ans = 0;
    for(int j=0;j<=180000;j++){
        ans = (ans + f[n-1][j])%modulo;
    }
    cout<<ans<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t=1; while(t--)code();
    return 0;
}