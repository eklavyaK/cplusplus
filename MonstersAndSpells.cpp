#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t;cin>>t;
    while(t-->0)
    {
        int n; cin>>n; int k[n],h[n]; long long int mana = 0l;
        int detect = 0;
        for(int i = 0; i<n; i++) cin>>k[i];
        for(int i = 0; i<n; i++) cin>>h[i];
        int temp = h[n-1],index = 0;
        for(int i = n-1; i>=1;i--)
        {
            if(k[i]-k[i-1]+index>=temp){mana = mana + (long long int)temp*(temp+1)/2;temp = h[i-1];index = 0;}
            else{
                if(temp < k[i]-k[i-1]+h[i-1]+index) {temp = k[i]-k[i-1]+h[i-1]+index;}
                index = index + k[i]-k[i-1];
            }
        }
        if(index!=0)
        mana = mana + (long long int)temp*(temp+1)/2;
        else mana = mana + (long long int)h[0]*(h[0]+1)/2;
        cout<<mana<<endl;
    }
    return 0;
}