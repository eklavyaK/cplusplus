#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int n; cin>>n; int max=0,index; vector<array<int,2>> v(2*n); 
	for(int i = 0; i<2*n; i++) {cin>>v[i][0]; if(!(i%2))v[i][1]=1; else v[i][1]=0;} 
	sort(v.begin(),v.end());int true_count=0; for(int i = 0; i<2*n; i++) 
	for(int i = 0; i<2*n; i++) {if(v[i][1]) ++true_count; else --true_count;if(true_count>max) {max=true_count;index=i;}}
	cout<<v[index][0]<<" "<<max<<endl;
	return 0;
}