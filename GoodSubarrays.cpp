#include<bits/stdc++.h>
typedef long double ld;
typedef long long ll;
using namespace std;
#define print(a) cout<<a<<endl
ll ans = 0;
ll add(int x){
    return ans+=x;
}
int main(){
    int t; cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++)cin>>a[i];
        int l = 0;
        int r = 0;
        int cnt = 0;
        ans = 0;
        while(true){
            while(r<n && a[r]+l>r){
                cnt++;r++;
            }
            add(cnt);
            if(l==n && r==n)break;
            l++;cnt--;
        }
        print(ans);
    }
    
}