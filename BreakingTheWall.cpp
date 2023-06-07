#include<bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;
int go(int a, int b){
    if(b>a)swap(a,b);
    int l = 1, r = a;
    while(l<=r){
        int mid = (l+r)>>1;
        if(mid*2<a || 3*mid-a<b) l = mid+1;
        else r = mid-1;
    }
    return r+1;
}
void code(){
    int n; cin>>n;
    vector<int> arr(n),temp;
    for(int i=0;i<n;i++) cin>>arr[i];
    temp = arr;
    sort(temp.begin(),temp.end());
    int ans = ((temp[0]+1)>>1)+((temp[1]+1)>>1);
    for(int i=0;i<n-1;i++){
        if(i>0 && i<n) ans = min(ans,(arr[i-1]+arr[i+1]+((arr[i-1]+arr[i+1])&1))>>1);
        ans = min(ans,go(arr[i],arr[i+1]));
    }
    cout<<ans<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t = 1; while(t--)code();
    return 0;
}