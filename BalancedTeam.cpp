#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n; cin>>n; int a[n],count=1; vector<int> res;
    for(int i = 0; i<n; i++) cin>>a[i];int min = 0;
    sort(a,a+n);for(int i = 1; i<n; i++) {if(a[i]-a[min]>5){if(a[i] - a[i-1]<=5) min++;else {res.emplace_back(count);count=1;min = i;}} else count++;}
    res.emplace_back(count);cout<<*max_element(res.begin(),res.end())<<endl;

    return 0;
}