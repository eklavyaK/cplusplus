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
    int arr[n];
    for(int i=0;i<n;i++)cin>>arr[i];
    vector<int> temp(arr,arr+n);
    sort(temp.begin(),temp.end());
    int l = 0, r = 0;
    map<int,queue<int>> m;
    queue<int> q;
    while(l<n){
        if(r<n){
            if(temp[r]>temp[l]) m[temp[l]].push(temp[r]), l++;
            else q.push(temp[r]);
        }
        else m[temp[l]].push(q.front()),q.pop(),l++;
        r++;
    }
    for(int i=0;i<n;i++) cout<<m[arr[i]].front()<<" ", m[arr[i]].pop();
    cout<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t; while(t--)code();
    return 0;
}