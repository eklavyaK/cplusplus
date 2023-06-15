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
    int a = false, b = false;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int idx = -1;
    int done[n]{1};
    int last = arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]<last && arr[i]<=arr[0]){
            idx = i;
            break;
        }
        else if(arr[i]>=last){
            done[i] = 1;
            last = arr[i];
        }
    }
    if(idx!=-1){
        for(int i=idx;i<n;i++){
            if(arr[i]>=arr[idx] && arr[i]<=arr[0]) done[i] = 1, idx = i;
        }
    }
    for(auto i : done) cout<<i; cout<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t; while(t--)code();
    return 0;
}