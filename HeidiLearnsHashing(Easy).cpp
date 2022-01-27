#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long r; cin>>r;
    if(r%2 && (r-3)/2>=1)
    {
        long long x, y;
        y = (r-3)/2;
        cout<<1<<" "<<y<<endl;
    }
    else cout<<"NO"<<endl;
    return 0;
}