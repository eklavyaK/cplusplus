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
		int n;string s,temp;
		cin>>n;
		cin>>s;
		int track = 0;
		for(int i = 1;i<n;i++)
		{
			if((int)s[i-1]-s[i]<=0)
			{
				if((int)s[i-1]-s[i]==0&&i==1)
				{
					cout<<s[i-1]<<s[i-1]<<endl;track=1;
					break;
				}
				else if((int)s[i-1]-s[i]<0)
				{
					string str = s.substr(0,i);
					cout<<str;
					reverse(str.begin(), str.end());track=1;
					cout<<str<<endl;
					break;
				}
			}
		}
		if(track==0)
		{
			cout<<s;
			reverse(s.begin(), s.end());
			cout<<s<<endl;
		}
	}
	return 0;
}