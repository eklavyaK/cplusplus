
/*You are given an array a of n elements. You can apply the following operation to it any number of times:

Select some subarray from a of even size 2k that begins at position l (1≤l≤l+2⋅k−1≤n, k≥1) and for each i between 0 and k−1 (inclusive), assign the value a.subscript(l+k+i) to a.subscript(l+i) or vice versa.
For example, if a=[2,1,3,4,5,3], then choose l=1 and k=2, applying this operation the array will become a=[3,4,3,4,5,3] or a=[2,1,2,1,5,3]

Find the minimum number of operations (possibly zero) needed to make all the elements of the array equal.*/

#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int tc;cin>>tc;
    while(tc-->0)
    {
        int n;cin>>n;int a[n]; int min = INT_MAX;
        for(int i = 0; i<n; i++) cin>>a[i];
        for(int i = 0; i<n;i++) 
        {
            int temp = a[i], in=i,en;
            while(i+1<n && a[i+1]==temp)i++;en=i;
            int k = en-in+1;int count=0;
            while(k<n)
            {
                count++; if(in<=k) {if(in==0)count--;k = in+k; while(k<n){en=en+k;k*=2;while(en+1<n&&a[en+1]==temp){en++;k++;}count++;}break;}
                else if(n-1-en<=k) {if(en==n-1)count--;k = n-1-en+k; while(k<n){in = in-k;k*=2;while(in-1>=0&&a[in-1]==temp){in--;k++;}count++;}break;}
                int counta=k,countb=k,indexa=in-k,indexb=en+k;
                while(indexa-1>=0 && a[indexa-1]==temp){counta++;indexa--;}
                while(indexb+1<n && a[indexb+1]==temp){countb++;indexb++;}
                if(countb<=counta){in=indexa;k+=counta;}
                else {en=indexb;k+=countb;}
            }
            if(min>count) min = count;
        }
        cout<<min<<endl;
    }
    return 0;
}
/*

Testcase:

1
10
1 2 3 4 5 1 1 6 1 1

Answer:
2

*/