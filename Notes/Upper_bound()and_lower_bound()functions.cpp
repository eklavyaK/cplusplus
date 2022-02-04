#include<iostream>
#include<algorithm>  //includes upper_bound(), lower_bound()
#include<vector>
using namespace std;
/*lower_bound returns an iterator pointing to the first element in the range [first,last) which has a value not less than ‘val’. 
upper_bound returns an iterator pointing to the first element in the range [first,last) which has a value greater than ‘val’. */
int main()
{
    vector<int> v; 
    v.emplace_back(3);v.emplace_back(4);v.emplace_back(5);v.emplace_back(5);v.emplace_back(5);v.emplace_back(6);v.emplace_back(7);
    v.emplace_back(7);v.emplace_back(7);v.emplace_back(9);v.emplace_back(9);v.emplace_back(9);v.emplace_back(10);v.emplace_back(10);
    for(auto i : v) cout<<i<<' ';cout<<endl;
    vector<int> ::iterator itr = lower_bound(v.begin(),v.end(),7); //returns the iterator pointing to the first element in range which has
    //a value not less than 7
    cout<<*itr<<endl;  //prints the value stored in the location pointed by iterator

    //to get the index of the element pointed by the iterator we subtract the v.begin() from the iterator which is stored in int variable
    int i = lower_bound(v.begin(),v.end(),8) - v.begin();
    cout<<i<<endl;  //since 8 is not present it returns the iterator pointing to the element just greater than 8
    i = lower_bound(v.begin(),v.end(),11) - v.begin();
    cout<<i<<endl;  //since there is no element greater than or equal to 11 it returns the iterator pointing to the end of the vector

    itr = upper_bound(v.begin(),v.end(), 3); cout<<*itr<<endl; //returns the iterator pointing to the first element which greater than 3
    i = upper_bound(v.begin(),v.end(),5)-v.begin(); cout<<i<<endl; //return the index of the first element greater than 5
    i = upper_bound(v.begin(),v.end(),8)-v.begin(); cout<<i<<endl; //returns the index of the first element greater than 8 even
    //though 8 is not present
    i = upper_bound(v.begin(),v.end(),11) - v.begin(); cout<<i<<endl;// since no element in the vector is greater than 11 it returns the
    //index to beyond the end of the vector

    //we can also do this with array (a[n])  by replacing v.begin()--------> a; v.end()----------> a+n
    return 0;
}
/*Output:

3 4 5 5 5 6 7 7 7 9 9 9 10 10 
7
9
14
4
5
9
14

*/