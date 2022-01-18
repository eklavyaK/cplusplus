#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t;cin>>t;
    while(t-->0)
    {
        int n; cin>>n; int a[n];
        for(int i = 0; i<n; i++) cin>>a[i];
        sort(a,a+n);int min = a[1] - a[0],index=1;
        for(int i = 2; i<n; i++) if(min>a[i]-a[i-1]){min = a[i]-a[i-1];index = i; if(min == 0) break;}
        vector<int> v;
        for(int i = 0; i<index-1; i++) v.emplace_back(a[i]);
        cout<<a[index-1]<<" ";
        for(int i = index+1; i<n; i++) cout<<a[i]<<" ";
        for(int i = 0; i<v.size(); i++) cout<<v[i]<<" ";
        cout<<a[index]<<endl;
    }
    return 0;
}