#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    int t;cin>>t;
    while(t-->0)
    {
        int n,l,count0,count1; cin>>n>>l; int a[n];string s[n];
        string result = "";
        for(int i = 0; i<n; i++) cin>>a[i];
        for(int i = 0; i<n; i++) s[i] = bitset<30>(a[i]).to_string();
        for(int i = 0; i<l; i++)
        {
            count1 = 0;count0 = 0;
            for(int j = 0; j<n; j++) {if(s[j][29-i] == '1') count1++; else count0++;}
            if(count1>count0) result = '1'+result;
            else result = '0'+result;
        }
        //cout<<result<<endl;
        int number = stoi(result, 0, 2);
        cout<<number<<endl;
    }
    return 0;
}