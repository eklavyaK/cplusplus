#include <bits/stdc++.h>
using namespace std;
/* To know how to sort a array or vector using a user defined-condition look into this program*/
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n = 5;
    cout<<"Making a array vector"<<endl;
    vector<array<int, 6>> v(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            v[i][j] = rand() % 100;
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 6; j++)
            cout << v[i][j] << " ";
        cout << endl;
    }

    // we can sort in any way we want. Like for example sum of squares of rows
    cout << endl;cout<<"we can sort in any way we want. Like for example sum of squares of rows"<<endl;
    sort(v.begin(), v.end(), [&](array<int, 6> &r, array<int, 6> &l)
         {
        int sum1=0,sum2=0;for(int i = 0; i<6; i++) {sum1+=r[i]*r[i]; sum2+=l[i]*l[i];} return sum1<sum2; });
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 6; j++)
            cout << v[i][j] << " ";
        cout << endl;
    }
    cout << endl;
    cout<<"Making a 2D Vector"<<endl;
    vector<vector<int>> vl;
    for (int i = 0; i < 5; i++)
    {
        int size = rand() % 15;
        vector<int> temp(size);
        for (int j = 0; j < size; j++)
            temp[j] = (rand() % 100);
        vl.emplace_back(temp);
    }
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < vl[i].size(); j++)
            cout << vl[i][j] << " ";
        cout << endl;
    }

    cout << endl; cout<<"sort according to first element"<<endl;
    sort(vl.begin(), vl.end()); // sort according to first element
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < vl[i].size(); j++)
            cout << vl[i][j] << " ";
        cout << endl;
    }
    cout << endl;

    // sorting each row in descending order
    cout<<"sorting each row in descending order"<<endl;
    for (int i = 0; i < 5; i++)
    {
        for_each(vl.begin(), vl.end(), [](vector<int> &vk){sort(vk.begin(),vk.end(),greater<int>());});
        for (auto j : vl[i])
            cout << j << " ";
        cout << endl;
    }
    cout<<endl;

    // another way of delcaring a array
    cout<<"another way of delcaring a array"<<endl;
    array<int,5> b={0}; //initializing all the elements with zero
    for(int i = 0; i<n; i++) cout<<b[i]<<" ";cout<<endl;
    
    //making 2D array
    cout<<endl;cout<<"making 2D array"<<endl;
    int track = 0;array<int,10> a[5];
    for(int i = 0; i<n; i++) {a[i]={0}; for(int j = 0; j<10; j++) a[i][j]=a[i][j]+track++;}
    for(int i = 0; i<n; i++) {for(int j = 0; j<10; j++) cout<<a[i][j]<<" ";cout<<endl;}

    return 0;
}
/*

Making a array vector
41 67 34 0 69 24
78 58 62 64 5 45
81 27 61 91 95 42
27 36 91 4 2 53
92 82 21 16 18 95

27 36 91 4 2 53
41 67 34 0 69 24
78 58 62 64 5 45
81 27 61 91 95 42
92 82 21 16 18 95

we can sort in any way we want. Like for example sum of squares of rows
41 67 34 0 69 24
27 36 91 4 2 53
78 58 62 64 5 45
92 82 21 16 18 95
81 27 61 91 95 42

Making a 2D Vector
26 71
69 12 67
35 94 3 11
33 73
41 11 53 68 47 44 62 57 37 59 23 41 29 78

sort according to first element
26 71
33 73
35 94 3 11
41 11 53 68 47 44 62 57 37 59 23 41 29 78
69 12 67

sorting each row in descending order
71 26
73 33
94 35 11 3
78 68 62 59 57 53 47 44 41 41 37 29 23 11
69 67 12

another way of delcaring a array
0 0 0 0 0

making 2D array
0 1 2 3 4 5 6 7 8 9
10 11 12 13 14 15 16 17 18 19
20 21 22 23 24 25 26 27 28 29 
30 31 32 33 34 35 36 37 38 39
40 41 42 43 44 45 46 47 48 49

*/