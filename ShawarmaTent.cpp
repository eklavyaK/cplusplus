#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);

	int n,x,y; cin>>n>>x>>y; int a[n],b[n],res[4]={0};
	for(int i = 0; i<n; i++){
		cin>>a[i]>>b[i];
	}
	for(int i = 0; i<n; i++){
		if(abs(a[i]-x)+abs(b[i]-y)==abs(a[i]-x-1)+abs(b[i]-y)+1)res[0]++;
		if(abs(a[i]-x)+abs(b[i]-y)==abs(a[i]-x)+abs(b[i]-y-1)+1)res[1]++;
		if(abs(a[i]-x)+abs(b[i]-y)==abs(a[i]-x+1)+abs(b[i]-y)+1)res[2]++;
		if(abs(a[i]-x)+abs(b[i]-y)==abs(a[i]-x)+abs(b[i]-y+1)+1)res[3]++;
	}
	int r,k=0;for(int i = 0; i<4; i++)if(k<res[i]){k=res[i];r=i;}
	cout<<k<<endl;
	if(r==0) cout<<x+1<<" "<<y<<endl;
	else if(r==1) cout<<x<<" "<<y+1<<endl;
	else if(r==2) cout<<x-1<<" "<<y<<endl;
	else cout<<x<<" "<<y-1<<endl;

	return 0;
}