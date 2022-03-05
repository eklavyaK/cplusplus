#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);

	int a[2]; a[0] = 2; a[1] = 3;
	int k = *max_element(a,a+1);
	cout<<k<<endl;

	return 0;
}