#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t;cin>>t;
    while(t-->0)
    {
        int n; string s; cin>>n>>s; 
        vector<int> v; int count10 = 0, count01 = 0;
        for(int i = 0; i<n-1;i++) 
        {
            if(s[i]=='0' && s[i+1]=='1') count01++;
            else if(s[i]=='1' && s[i+1]=='0') count10++;
        }
        cout<<(n-2*max(count10,count01))/2<<endl;
    }
    return 0;
}