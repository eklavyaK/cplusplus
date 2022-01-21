#include<bits/stdc++.h>
using namespace std;

#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t;cin>>t;
    while(t-->0)
    {
        int n,k; cin>>n; map<int,int> map; int a[2*n+1]={0};
        for(int i = 0; i<n; i++) {cin>>k; map[k]++;}
        for(int i = 2; i<2*n+1; i++) 
        {
            int count = 0;
            if(i%2)
            {
                int m = i/2;
                for(int j = 1; j<=m; j++) count += min(map[j],map[i-j]);
            } 
            else
            {
                int m = i/2;
                count += map[i/2]/2;
                for(int j = 1; j<m; j++) count += min(map[j], map[i-j]);
            }
            a[i] = count;
        }
        cout<<*max_element(a,a+2*n+1)<<endl;
    }
    return 0;
}