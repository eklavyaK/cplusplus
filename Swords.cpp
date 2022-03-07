#include<bits/stdc++.h>
#define removezeros(s) s.erase(0,s.find("1")!=-1?s.find("1"):s.length()-1)
#define binary(n,k) bitset<k>(n).to_string()
#define makeset(_set, _collection, size_of_collection) for(int i = 0; i<size_of_collection; i++){_set.emplace_back(_collection[i]);while(i+1<size_of_collection && _collection[i+1]==_collection[i])i++;}
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int n;cin>>n; int a[n],in[n];
	for(int i = 0; i<n; i++)cin>>a[i];
	int ma = *max_element(a,a+n);long long sum = 0;
	for(int i = 0; i<n; i++){in[i]=ma-a[i];sum+=in[i];}
	int g = 0; for(int i = 0; i<n; i++) if(in[i]!=0)g=gcd(g,in[i]);
	cout<<sum/g<<" "<<g<<endl;
	return 0;
}