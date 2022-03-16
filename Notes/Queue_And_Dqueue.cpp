#include<iostream>
#include<queue>        //queue library contains the queue data structure
#include<deque>
#include<numeric>
#include<algorithm>

/*Queue is a datastructure which follows the fifo technique, which means first in and first out. It can be viewed as water flowing
through a pipe, whiere the water entering at first exits the pipe first*/
/*Queue can hold any type of data----> int, char, float, double, string*/

using namespace std;

int main()
{
    cout<<"Implementation of queue: "<<endl<<endl;
    queue<int> q;      //Declaration of the interger queue

    if(q.empty()) cout<<"Queue is empty"<<endl;    //empty() method is used to check whether the queue is empty or not
    
    //addition of elements in queue.
    for(int i = 0; i<10; i++){
        q.push(rand()%100);        //push(val) is used to add val to the end of the queue  
    }
    
    //iterating through a queue
    cout<<endl<<"The newly added elements in the queue are: "<<endl;
    while(!q.empty()){
        cout<<q.front()<<" ";   //front() function is used to access the first element of the queue.
        q.pop();         //pop() function is used to remove the first element of the queue. So second element becomes the first element.
    }

    cout<<"\n\n"<<"After iterating through the queue using pop() method, the final size() of the queue is: "<<q.size()<<endl;
    cout<<endl<<"Again the newly added elements are: "<<endl;
    for(int i = 0; i<10; i++){
        int  k = rand()%100;
        q.push(k);
        cout<<k<<" ";
    }

    cout<<endl<<endl<<"The last element of the queue is: ";
    cout<<q.back()<<endl;      //back() function gives the value of the last element in the queue.

    cout<<endl<<"Size of the queue after addition of 100: ";
    q.push(100);
    cout<<q.size()<<endl;      //size() function gives the size ---> no of elements present in the queue at that moment

    q.emplace(10);             //emplace() function also adds a new element to the end of the queue

    cout<<endl<<"The elements in the queue after addition of a element using emplace() function:"<<endl;
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl<<endl<<"Implementation of deque: "<<endl<<endl;


    //Implementation of deque -------> it is mostly like a vector in c++, we can insert the elements in the middle also
    
    /*But according to actual definition of the deque, it is a double ended queue, where elements can be inserted at the beginning 
    or at the end and can be accessed from the beginning or the end and also can be removed from the beginning and the end*/
    deque<int> dq;

    cout<<"There are no elements in the deque. Let's check if it is really empty using empty() function: "<<dq.empty()<<endl;

    cout<<endl<<"Addition of elements in deque:"<<endl;
    for(int i = 0; i<10; i++){
        dq.push_back(rand()%100);
    }
    for(deque<int>::iterator it = dq.begin(); it!=dq.end(); it++){
        cout<<*it<<" ";
    }
    cout<<endl;

    //functions in deque
    cout<<endl<<"Size of the deque is: "<<dq.size()<<endl; //size() method returns the size of the deque

    dq.clear();
    cout<<endl<<"The size of the deque after application of clear() function: "<<dq.size()<<endl;

    cout<<endl<<"New elements are added: "<<endl;
    for(int i = 0; i<10; i++){
        int k = rand()%1000;
        dq.push_back(k);
        cout<<k<<" ";
    }
    cout<<endl<<endl;

    dq.push_front(1000);  //push_front() function can be used to add a element at the beginning of the deque
    cout<<"The elements in the deque after adding 1000 at the front:"<<endl;
    for(deque<int>::iterator it = dq.begin(); it!=dq.end(); it++){
        cout<<*it<<" ";
    }
    cout<<endl<<endl;

    cout<<"The element in the front of the deque: "<<dq.front()<<endl;  //front() function is used to access the element in the front
    
    cout<<endl<<"The element at the back of the deque: "<<dq.back()<<endl;  //back() functoin is used to access the element at the back

    dq.pop_front();  //it removes the element in the front of the deque
    cout<<endl<<"Deque after removing the element from the front of the deque: "<<endl;
    for(deque<int>::iterator it = dq.begin(); it!=dq.end(); it++){
        cout<<*it<<" ";
    }
    cout<<endl<<endl;

    dq.pop_back();    //it removes the element at the back from the deque
    cout<<"Deque after removing the element from the back of the deque: "<<endl;
    for(deque<int>::iterator it = dq.begin(); it!=dq.end(); it++){
        cout<<*it<<" ";
    }
    cout<<endl<<endl;

    cout<<"The element at position 4 in the deque: "<<dq.at(4)<<endl;  //at() function gives the element at particular index in deque

    return 0;
}
/*
Output:
`````````````````````````````````````````````````````````````````````````````````````````````````````
Implementation of queue: 

Queue is empty

The newly added elements in the queue are:
41 67 34 0 69 24 78 58 62 64

After iterating through the queue using pop() method, the final size() of the queue is: 0

Again the newly added elements are:
5 45 81 27 61 91 95 42 27 36

The last element of the queue is: 36

Size of the queue after addition of 100: 11

The elements in the queue after addition of a element using emplace() function:
5 45 81 27 61 91 95 42 27 36 100 10

Implementation of deque:

There are no elements in the deque. Let's check if it is really empty using empty() function: 1

Addition of elements in deque:
91 4 2 53 92 82 21 16 18 95

Size of the deque is: 10

The size of the deque after application of clear() function: 0

New elements are added:
447 726 771 538 869 912 667 299 35 894

The elements in the deque after adding 1000 at the front:
1000 447 726 771 538 869 912 667 299 35 894

The element in the front of the deque: 1000

The element at the back of the deque: 894

Deque after removing the element from the front of the deque:
447 726 771 538 869 912 667 299 35 894

Deque after removing the element from the back of the deque:
447 726 771 538 869 912 667 299 35

The element at position 4 in the deque: 869
``````````````````````````````````````````````````````````````````````````````````````````````````````
*/