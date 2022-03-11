#include<bits/stdc++.h>
#define removezeros(s) s.erase(0,s.find("1")!=-1?s.find("1"):s.length()-1)
#define binary(n,k) bitset<k>(n).to_string()
#define makeset(_set, _collection, size_of_collection) for(int i = 0; i<size_of_collection; i++){_set.emplace_back(_collection[i]);while(i+1<size_of_collection && _collection[i+1]==_collection[i])i++;}
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int tc;cin>>tc;
	while(tc-->0)
	{
		int n; cin>>n; int x[n],y[n];
		for(int i = 0; i<n; i++)cin>>x[i];
		for(int i = 0; i<n; i++)cin>>y[i];
		long long a1=INT_MAX,b1=INT_MAX,c1=INT_MAX,d1=INT_MAX;
		for(int i = 0; i<n; i++){
			if(abs(y[n-1]-x[i])<d1){d1=abs(y[n-1]-x[i]);}
			if(abs(y[0]-x[i])<c1){c1=abs(y[0]-x[i]);}
			if(abs(x[n-1]-y[i])<b1){b1=abs(x[n-1]-y[i]);}
			if(abs(x[0]-y[i])<a1){a1=abs(x[0]-y[i]);}
		}
		long long res[7];
		res[0]=a1+b1+c1+d1;
		res[1]=abs(x[0]-y[n-1])+abs(x[n-1]-y[0]);
		res[2]=abs(y[n-1]-x[n-1])+abs(y[0]-x[0]);
		res[3]=a1+c1+abs(x[n-1]-y[n-1]);
		res[4]=b1+d1+abs(y[0]-x[0]);
		res[5]=abs(x[0]-y[n-1])+c1+b1;
		res[6]=abs(x[n-1]-y[0])+a1+d1;
		cout<<*min_element(res,res+7)<<endl;
	}
	return 0;
}