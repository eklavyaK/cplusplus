#include<bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;

int solve(vector<int> arr,int cnt){
    if(arr.size()==0)return 0;
    if(arr.size()==1)return arr[0];
    vector<int> next;
    if(cnt)next.push_back(arr[0]),cnt--;
    for(int i=1;i<arr.size();i++){
        if(arr[i]-arr[i-1]==0)cnt++;
        else next.push_back(arr[i]-arr[i-1]);
    }
    sort(next.begin(),next.end());
    return solve(next,cnt);
}

void code(){
    int n; cin>>n;
    vector<int> arr;
    int cnt = 0;
    for(int i=0;i<n;i++){
        int k; cin>>k;
        if(!k)cnt++;
        else arr.push_back(k);
    }
    cout<<solve(arr,cnt)<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t; while(t--)code();
    return 0;
}