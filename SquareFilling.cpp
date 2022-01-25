#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);

    int n,m; cin>>n>>m; int a[n][m]; int detect = 0,count=0;
    for(int i = 0; i<n; i++) for(int j = 0; j<m; j++) cin>>a[i][j];
    for(int i = 0; i<n; i++) for(int j = 0; j<m; j++) 
    {
        if(i>0 && i<n-1 && j>0 && j<m-1)
        {
            if(a[i][j])
            {
                if(!((a[i-1][j-1] && a[i-1][j] && a[i][j-1])||(a[i-1][j+1] && a[i-1][j] && a[i][j+1])||(a[i+1][j+1] && a[i+1][j] && a[i][j+1])||(a[i+1][j-1] && a[i+1][j] && a[i][j-1])))
                {detect = 1;break;}
            }
        }
        else if(i>0 && i<n-1 && j==0)
        {
            if(a[i][j])
            {
                if(!((a[i][j+1]&&a[i-1][j]&&a[i-1][j+1])||(a[i][j+1]&&a[i+1][j+1]&&a[i+1][j])))
                {detect = 1;break;}
            }
        }
        else if(i>0 && i<n-1 && j==m-1)
        {
            if(a[i][j])
            {
                if(!((a[i][j-1]&&a[i-1][j]&&a[i-1][j-1])||(a[i][j-1]&&a[i+1][j-1]&&a[i+1][j])))
                {detect = 1;break;}
            }
        }
        else if(j>0 && j<m-1 && i==0)
        {
            if(a[i][j])
            {
                if(!((a[i][j+1]&&a[i+1][j+1]&&a[i+1][j])||(a[i][j-1]&&a[i+1][j]&&a[i+1][j-1])))
                {detect = 1;break;}
            }
        }
        else if(j>0 && j<m-1 && i==n-1)
        {
            if(a[i][j])
            {
                if(!((a[i][j-1]&&a[i-1][j]&&a[i-1][j-1])||(a[i][j+1]&&a[i-1][j]&&a[i-1][j+1])))
                {detect = 1;break;}
            }
        }
        else if(i==0 && j==0 && a[i][j] && !(a[1][0]&&a[0][1]&&a[1][1])) {detect = 1; break;}
        else if(i==n-1 && j==0 && a[i][j] && !(a[n-2][0]&&a[n-2][1]&&a[n-1][1])) {detect = 1; break;}
        else if(i==0 && j==m-1 && a[i][j] && !(a[0][m-2]&&a[1][m-2]&&a[1][m-1])) {detect = 1; break;}
        else if(i==n-1 && j==m-1&& a[i][j] &&!(a[i-1][j-1] &&a[i-1][j]&&a[i][j-1])) {detect = 1; break;}
    }
    if(detect) cout<<-1<<endl;
    else 
    {
        for(int i = 0; i<n-1; i++) for(int j = 0; j<m-1; j++) 
        if(a[i][j] && a[i][j+1]&&a[i+1][j]&&a[i+1][j+1]) count++;cout<<count<<endl;if(count)for(int i = 0; i<n-1; i++) for(int j = 0; j<m-1; j++)
        if(a[i][j] && a[i][j+1]&&a[i+1][j]&&a[i+1][j+1]) cout<<i+1<<" "<<j+1<<endl;
    }

    return 0;
}