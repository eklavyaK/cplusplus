#include <iostream>
#include <bits/stdc++.h>
#include <string>
using namespace std;
int main()
{
    int t;
	cin>>t;
	while(t-->0)
	{
		int n;
		cin>>n;
		int a[n],sum = 0;
		for(int i = 0;i<n;i++)
		{cin>>a[i]; sum = sum+a[i];}
		if(n<3) {cout<<0;continue;}
		int result = (float)0.5*(a[n-1]+a[0])*n;
		if(result == sum)
			cout<<0;
		else cout<<1;
	}
	return 0;
}