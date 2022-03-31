#include<iostream>

using namespace std;
/*Time complexity is log2(n)  which it takes at max just 30 iterations to find a number in a sorted array of size 10^9*/
int main(){
	int n; cin>>n; int a[n];
	for(int i = 0; i<n; i++)a[i]=rand()%50;
	sort(a,a+n);
	for(auto i : a) cout<<i<<" ";cout<<endl;
	int q;cin>>q;while(q--){
		int k; cin>>k;
/*********************************************Binary Search Algorithm*********************************************/
		int l = 0, r = n-1;
		int mid = r/2;
		while(l<r){
			if(a[mid]==k){
				cout<<"FOUND"<<endl;
				goto end;
			}
			else if(a[mid]>k){
				r=mid-1;
				mid=l+(r-l)/2;
			}
			else{
				l=mid+1;
				mid=l+(r-l)/2;
			}
		}
/****************************************************************************************************************/
		a[mid]!=k?cout<<"NOT FOUND"<<endl:cout<<"FOUND"<<endl;end:;
	}
	return 0;
}