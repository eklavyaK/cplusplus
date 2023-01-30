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
        int cnt1=0, cnt2=0;
        vector<int>a(n),b(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
            if(a[i]==1)cnt1++;
        }
        for(int i=0;i<n;i++){
            cin>>b[i];
            if(b[i]==1)cnt2++;
        }
        int k = abs(cnt1-cnt2);
        if(cnt1>cnt2){
            for(int i=0;i<n;i++){
                if(a[i]==0 && b[i]==1){
                    k++;break;
                }
            }
        }
        else if(cnt1<cnt2){
            for(int i=0;i<n;i++){
                if(b[i]==0 && a[i]==1){
                    k++;break;
                }
            }
        }
        else{
            for(int i=0;i<n;i++){
                if(a[i]!=b[i]){
                    k++;break;
                }
            }
        }
        cout<<k<<endl;
    }
    
}