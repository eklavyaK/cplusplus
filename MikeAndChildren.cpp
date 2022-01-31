#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n; cin>>n; int store[200001]={0},a[n];
    for(int i = 0; i<n; i++) cin>>a[i];
    for(int i = 0; i<n-1; i++) for(int j = i+1; j<n; j++) store[a[i]+a[j]]++;
    cout<<*max_element(store,store+200001)<<endl;
    return 0;
}