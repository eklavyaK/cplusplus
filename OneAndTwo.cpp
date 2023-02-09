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
    int arr[n], k = 0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        if(arr[i]==2)k++;
    }
    if(k&1){
        cout<<-1<<endl;
    }
    else{
        k/=2;
        for(int i=0;i<n;i++){
            if(arr[i]==2)k--;
            if(!k){
                cout<<i+1<<endl;
                return;
            }
        }
    }
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t; while(t--)code();
    return 0;
}