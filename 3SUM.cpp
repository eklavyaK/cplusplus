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
    int arr[10]{};
    vector<int> v;
    for(int i=0;i<n;i++){
        int k; cin>>k;
        if(arr[k%10]>=3)continue;
        else{
            arr[k%10]++;
            v.push_back(k%10);
        }
    }
    n = v.size();
    for(int i=0;i<n-2;i++){
        for(int j=i+1;j<n-1;j++){
            for(int k = j+1;k<n;k++){
                if((v[i]+v[j]+v[k])%10==3){
                    cout<<"YES"<<endl;
                    return;
                }
            }
        }
    }
    cout<<"NO"<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t; while(t--)code();
    return 0;
}