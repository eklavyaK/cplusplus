#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);

    int n; cin>>n; long long w = 0l;
    for(int i = 2; i<n; i++) w = w+(i+1)*i;
    cout<<w<<endl;

    return 0;
}