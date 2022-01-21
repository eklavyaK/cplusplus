#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t;cin>>t;
    while(t-->0)
    {
        int n; cin>>n; int a[n];
        for(int i = 0; i<n; i++) cin>>a[i]; int length = *max_element(a,a+n); 
        string s(length+1,'a'); cout<<s<<endl;
        for(int i = 0; i<n; i++) 
        {
            s[a[i]] = s[a[i]]==char(97 + i%26)?char(97+(i+1)%26):char(97+i%26);
            cout<<s<<endl;
        } 
    }
    return 0;
}