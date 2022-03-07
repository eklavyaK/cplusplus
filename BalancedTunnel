#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);

	int n; cin>>n; int a[n],b[n], l,count=0,track=0; bool c[n]={false};
	for(int i = 0; i<n; i++)cin>>a[i];for(int i = 0; i<n; i++)cin>>b[i];
	l=a[track++];for(int i = 0; i<n; i++){if(b[i]==l){while(track<n&&c[a[track]-1])track++;if(track<n)l=a[track++];else break;}else {c[b[i]-1]=true;count++;}}
	cout<<count<<endl;

	return 0;
}