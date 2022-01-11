#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;cin>>t;
    while(t-->0)
    {
        int n,k; string s; cin>>n>>k>>s;
        map<char,int> map;
        int track = 0, sum = 0;
        for(int i = 0; i<n; i++)
            map[s[i]]++;
        for (auto i : map)
        {
            if(i.second>1)
            {
                if(i.second%2==1) {sum = sum + i.second-1;track++;}
                else sum = sum + i.second;
            }
            else track++;
        }
        //cout<<sum<<endl;
        int result = sum/k;
        if(result==0) {cout<<1<<endl; continue;}
        if(result%2==0 && sum%k+track>=k) cout<<result+1<<endl;
        else cout<<result<<endl;
    }
    return 0;
}