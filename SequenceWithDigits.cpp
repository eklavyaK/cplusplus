#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int tc;cin>>tc;
    while(tc-->0)
    {
        long long n,k; cin>>n>>k;k--;
        while(k--)
        {
            string s = to_string(n);
            if(s.find("0")!=-1) break;
            else
            {
                sort(s.begin(),s.end());
                n +=((s[0]-48)*(s[s.size()-1]-48));
            }
        }
        cout<<n<<endl;
    }
    return 0;
}