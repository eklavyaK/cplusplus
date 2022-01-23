#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t; cin>>t;while(t--)
    {
        int n,x,k; cin>>n>>x;int o=0,e=0;
        for(int i = 0; i<n; i++) {cin>>k;if(k%2)o++;else e++;}
        if(o>0 && ((x%2 && o-!(o%2)+e>=x)||(x%2==0 && e!=0 && o-!(o%2)+e>=x))) cout<<"yes"<<endl;
        else cout<<"no"<<endl;
    }
    return 0;
}