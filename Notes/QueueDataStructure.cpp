#include<iostream>
#include<queue>        //queue library contains the queue data structure
#include<numeric>
#include<algorithm>

/*Queue is a datastructure which follows the fifo technique, which means first in and first out. It can be viewed as water flowing
through a pipe, whiere the water entering at first exits the pipe first*/
/*Queue can hold any type of data----> int, char, float, double, string*/

using namespace std;

int main()
{
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

    return 0;
}
/*
Output:
`````````````````````````````````````````````````````````````````````````````````````````````````````
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
``````````````````````````````````````````````````````````````````````````````````````````````````````
*/