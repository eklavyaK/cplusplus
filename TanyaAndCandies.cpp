#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);

    int n; cin>>n; int a[n],e[n]={0},o[n]={0}, count = 0;
    for(int i = 0; i<n; i++) cin>>a[i];o[0]=a[0];if(n>1)e[1] = a[1]; int ine, ino;
    for(int i = 2; i<n; i++) {if(i%2) e[i] = a[i] + e[i-2]; else o[i] = a[i] + o[i-2];}
    if(e[n-1]!=0) {ine = n-1;ino=n-2;} else {ine=n-2; ino=n-1;}
    for(int i = 0; i<n; i++) 
    {
        if(i%2)
        {
            int sumo=0,sume=0;if(i>1) sume = e[i-2];
            if(i+1<n) sume = sume + a[i+1] + o[ino] - o[i+1];
            sumo = o[i-1]+e[ine]-e[i];
            if(sumo==sume) count++;
        }
        else
        {
            int sumo=0,sume=0;if(i>0) sumo = o[i-2];
            if(i+1<n) sumo = sumo + a[i+1] + e[ine] - e[i+1];
            sume = o[ino]-o[i];if(i>0) sume += e[i-1];
            if(sumo==sume) count++;
        }
    }
    cout<<count<<endl;

    return 0;
}