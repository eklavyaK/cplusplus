#include<bits/stdc++.h>
#define removezeros(s) s.erase(0,s.find("1")!=-1?s.find("1"):s.length()-1)
#define binary(n,k) bitset<k>(n).to_string()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int tc;cin>>tc;
    while(tc-->0)
    {
        int n,k; long long result = 0; cin>>n>>k; int a[n]; long double sum = 0.0l;
        for(int i = 0; i<n; i++) cin>>a[i];sum=a[0];
        for(int i = 1; i<n; i++) 
        {
            long long count = 0;
            if(a[i]/sum*100 > k) {count = ceil(((long double)a[i]*100)/k - sum); sum+=count;result+=count;}
            sum += a[i];
        }
        cout<<result<<endl;
    }
    return 0;
}