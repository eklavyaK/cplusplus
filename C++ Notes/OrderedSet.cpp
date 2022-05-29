/*Ordered set is a policy based data structure. And it is NOT AVAILABLE in bits/stdc library. To use this data structure we have to include this:*/

/*The ordered set can also provide the index or position of an element in the set*/
#include<iostream>
#include<numeric>
using namespace std;
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    ordered_set s;
    for(int i=0;i<10;i++){
        s.insert(rand()%100);               //inserting elements in ordered set
    }
    for(auto i : s) cout<<i<<' ';cout<<endl;

    cout<<"-----------------------------------------------------"<<endl;

    cout<<*s.find_by_order(4)<<endl;        //it returns the ITERATOR pointing to the particular index
    cout<<*s.find_by_order(7)<<endl;
    cout<<*s.find_by_order(35)<<endl;       //if index is out or range it returns a iterator pointing to a random number

    cout<<"-----------------------------------------------------"<<endl;

    cout<<s.order_of_key(34)<<endl;         //it returns the number of elements strictly less than key in the set
    cout<<s.order_of_key(69)<<endl;
    cout<<s.order_of_key(0)<<endl;          
    cout<<s.order_of_key(-1)<<endl;        
    cout<<s.order_of_key(40)<<endl;         //40 is not present in the set but 3 values are less than 40
    cout<<s.order_of_key(100)<<endl;

    cout<<"-----------------------------------------------------"<<endl;

    //upper_bound and lower_bound functions also available in ordered set

    cout<<*s.upper_bound(67)<<endl;
    cout<<*s.lower_bound(67)<<endl;
    cout<<*s.lower_bound(40)<<endl;
    cout<<*s.upper_bound(45)<<endl;

    cout<<"-----------------------------------------------------"<<endl;

    tree<int, null_type, greater<int>, rb_tree_tag, tree_order_statistics_node_update> ds;

    for(int i=0;i<10;i++){
        ds.insert(rand()%100);
    }

    for(auto i : ds) cout<<i<<' ';cout<<endl;
    
    cout<<"-----------------------------------------------------"<<endl;

    cout<<*ds.find_by_order(4)<<endl;        //it returns the ITERATOR pointing to the particular index
    cout<<*ds.find_by_order(7)<<endl;
    cout<<*ds.find_by_order(35)<<endl;       //if index is out or range it returns a iterator pointing to a random number

    cout<<"-----------------------------------------------------"<<endl;

    cout<<ds.order_of_key(81)<<endl;         //it returns the number of elements strictly greater than key in the set
    cout<<ds.order_of_key(27)<<endl;
    cout<<ds.order_of_key(95)<<endl;          
    cout<<ds.order_of_key(-1)<<endl;        
    cout<<ds.order_of_key(40)<<endl;         //40 is not present in the set but 6 values are greater than 40
    cout<<ds.order_of_key(100)<<endl;

    cout<<"-----------------------------------------------------"<<endl;

    //upper_bound and lower_bound functions also available in ordered set       Note:- They behave differently in this casee

    cout<<*ds.upper_bound(92)<<endl;         //upper_bound returns the value just strictly less than the given value
    cout<<*ds.lower_bound(45)<<endl;         //lower_bound returns the value just strictly less than or equal to the give value
    cout<<*ds.lower_bound(58)<<endl;
    cout<<*ds.upper_bound(30)<<endl;

    cout<<"-----------------------------------------------------"<<endl;

    tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ms;

    ms.insert(4);
    ms.insert(6);
    ms.insert(10);
    ms.insert(2);
    ms.insert(2);
    ms.insert(5);
    ms.insert(12);
    ms.insert(34);
    ms.insert(4);
    ms.insert(7);
    ms.insert(7);

    for(auto i : ms) cout<<i<<' ';cout<<endl;
    
    cout<<"-----------------------------------------------------"<<endl;

    cout<<*ms.find_by_order(4)<<endl;        //it returns the ITERATOR pointing to the particular index
    cout<<*ms.find_by_order(7)<<endl;
    cout<<*ms.find_by_order(35)<<endl;       //if index is out or range it returns a iterator pointing to a random number

    cout<<"-----------------------------------------------------"<<endl;

    cout<<ms.order_of_key(2)<<endl;         //it returns the number of elements strictly less than key in the set
    cout<<ms.order_of_key(12)<<endl;
    cout<<ms.order_of_key(6)<<endl;          
    cout<<ms.order_of_key(-1)<<endl;        
    cout<<ms.order_of_key(8)<<endl;         //8 is not present in the set but 8 values are less than 8
    cout<<ms.order_of_key(100)<<endl;

    cout<<"-----------------------------------------------------"<<endl;

    //upper_bound and lower_bound functions also available in ordered set       Note:- They behave differently in this casee

    cout<<*ms.upper_bound(5)<<endl;         //upper_bound returns the value greater than or equal to the given value
    cout<<*ms.lower_bound(7)<<endl;         //lower_bound returns the value just strictly greater than the give value
    cout<<*ms.lower_bound(3)<<endl;
    cout<<*ms.upper_bound(30)<<endl;

    cout<<"-----------------------------------------------------"<<endl;

    tree<int, null_type, greater_equal<int>, rb_tree_tag, tree_order_statistics_node_update> mds;

    mds.insert(4);
    mds.insert(6);
    mds.insert(10);
    mds.insert(2);
    mds.insert(2);
    mds.insert(5);
    mds.insert(12);
    mds.insert(34);
    mds.insert(4);
    mds.insert(7);
    mds.insert(7);

    for(auto i : mds) cout<<i<<' ';cout<<endl;
    
    cout<<"-----------------------------------------------------"<<endl;

    cout<<*mds.find_by_order(4)<<endl;        //it returns the ITERATOR pointing to the particular index
    cout<<*mds.find_by_order(7)<<endl;
    cout<<*mds.find_by_order(35)<<endl;       //if index is out or range it returns a iterator pointing to a random number

    cout<<"-----------------------------------------------------"<<endl;

    cout<<mds.order_of_key(2)<<endl;         //it returns the number of elements strictly greater than key in the set
    cout<<mds.order_of_key(12)<<endl;
    cout<<mds.order_of_key(6)<<endl;          
    cout<<mds.order_of_key(-1)<<endl;        
    cout<<mds.order_of_key(8)<<endl;         //8 is not present in the set but 3 values are greater than 8
    cout<<mds.order_of_key(100)<<endl;

    cout<<"-----------------------------------------------------"<<endl;

    //upper_bound and lower_bound functions also available in ordered set       Note:- They behave differently in this casee

    cout<<*mds.upper_bound(5)<<endl;         //upper_bound returns the value less than or equal to the given value
    cout<<*mds.lower_bound(7)<<endl;         //lower_bound returns the value just strictly less than the give value
    cout<<*mds.lower_bound(3)<<endl;
    cout<<*mds.upper_bound(30)<<endl;

    cout<<"-----------------------------------------------------"<<endl;
}
/******************************************************OUTPUT****************************************************/
/*
0 24 34 41 58 62 64 67 69 78 
-----------------------------------------------------
58
67
0
-----------------------------------------------------
2
8
0
0
3
10
-----------------------------------------------------
69
67
41
58
-----------------------------------------------------
95 91 81 61 45 42 36 27 5
-----------------------------------------------------
45
27
1702057308
-----------------------------------------------------
2
7
0
9
6
0
-----------------------------------------------------
91
45
45
27
-----------------------------------------------------
2 2 4 4 5 6 7 7 10 12 34 
-----------------------------------------------------
5
7
0
-----------------------------------------------------
0
9
5
0
8
11
-----------------------------------------------------
5
10
4
34
-----------------------------------------------------
34 12 10 7 7 6 5 4 4 2 2
-----------------------------------------------------
7
4
0
-----------------------------------------------------
9
1
5
11
3
0
-----------------------------------------------------
5
6
2
12
-----------------------------------------------------
*/