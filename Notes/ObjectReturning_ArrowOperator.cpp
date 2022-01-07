#include <iostream>
using namespace std;
/*If a pointer is pointing to a specific object of a class or structure then we can access its contents or call functions
using arrow pointer, which has been explained below.

this keyword is necessarily called 'this pointer' which points to the calling object. It is used to override the variables in the function
which have same name as in function such that object's variables prevail.
*/
class batsman
{
public:
    int innings, runs;
    float average;
    void setStats(int in, int r, float av)
    {
        innings = in;
        runs = r;
        average = av;
    }
    void setAbsolutes(int innings, int runs, int average)
    {
        innings = innings; //here local prevails over data members of calling object
        runs = runs;
        average = average;
    }
    batsman &setAbsolutesAgain(int innings, int runs, int average)
    {
        this->innings = innings; //Unlike above method we use this pointer to point to the data members of the object to set their values
        this->runs = runs;
        this->average = average;
        return *this; //if we don't write & operator in return type then copy of object is sent but now rerence has been sent
    }
    batsman *setStatsAgain(int innings, int runs, int average)
    {
        this->innings = innings;
        this->runs = runs;
        this->average = average;
        return this; //we can return a pointer to the object by returning 'this' operator
    }
    batsman sendStatsCopy(int innings, int runs, int average)
    {
        this->innings = innings;
        this->runs = runs;
        this->average = average;
        return *this; //here we are returning copy of the object to caller unlike third method where we sent the rerenfence
    }
    void displayStats()
    {
        cout << "Innings: " << innings << endl;
        cout << "Runs: " << runs << endl;
        cout << "Average: " << average << endl;
    }
};
struct bowler
{
    int overs;
    int wickets;
    float economy;
};
int main()
{
    batsman rohitsharma, rohitsharma1, rohitsharma2;
    cout << "Understanding this pointer using rohitsharma object:" << endl;
    cout << endl;
    cout << "At first we just display set the stats using normal method:" << endl;
    rohitsharma.setStats(218, 10000, float(52.04)); //it works as expected
    rohitsharma.displayStats();
    cout << endl;
    cout << "Now we display the stats where absolutes are set without this pointer:" << endl;
    rohitsharma1.setAbsolutes(218, 10000, 52.04); //This method cannot set the values of the object because data members are overridden
    rohitsharma1.displayStats();
    cout << endl;
    cout << "Now we perform same using this pointer:" << endl;
    rohitsharma2.setAbsolutesAgain(218, 10000, 52.04); //here we this pointer so we can use it to set values of data members by overriding the function variables
    rohitsharma2.displayStats();
    cout << endl;
    cout << "Here we check whether really *this returns the object:" << endl;
    int in = rohitsharma.setAbsolutesAgain(109, 3000, 35.23).innings; //here we can see that *this operator returns the object
    cout << "Innings: " << in << endl;
    cout << endl;
    cout << "Now let kohli be the pointer to rohitsharma object.\nSo let's display the stats at kohli:" << endl;
    batsman *kohli = &rohitsharma; //note that we are creating a pointer to a object just like we used to do with primitive types this proves
    (*kohli).displayStats();       //that there class is a user defined data type, where user is allowed to customize according to his need
    cout << '\n';
    cout << "Now let's make a new object by passing the reference of object rohitsharma,\nso that they point to the same location." << endl;
    batsman &dhoni = rohitsharma; //again this is the same operation we used to perform with primitive data types this again further prooves that
    dhoni.displayStats();         //class is a just a data type which is customized by the user
    cout << '\n';
    batsman *batsmen = new batsman[10];
    cout << "Now we have created a memory block to store 10 objects of class batsman.\nLet's assign them value using (.) operator.\n"
         << endl;
    for (int i = 0; i < 10; i++)
    {
        (*(batsmen++)).setStats(i + 100, 1000 + 1000 * i, 45 + i / 10); //deferencing a pointer gives object
    }
    for (int i = 0; i < 10; i++)
    {
        cout << "Stats of batsman[" << i + 1 << "]:" << endl;
        (*(batsmen--)).displayStats();
    }
    cout << endl;
    cout << "Now let's do the same operation using Arrow operator:" << endl;
    cout << endl;
    for (int i = 0; i < 10; i++)
    {
        batsmen->setStats(i + 100, 1000 + 1000 * i, 45 + i / 10);
        batsmen++; //We can call a member function using arrow key and pointer of the object
    }
    for (int i = 0; i < 10; i++)
    {
        cout << "Stats of batsman[" << i + 1 << "]:" << endl;
        batsmen->displayStats();
        batsmen--;
    }
    cout << endl;
    cout << "Now let's display stats of a batsman using arrow operator(without calling displaystats() functon):" << endl;
    batsmen++;
    cout << "Innings: " << batsmen->innings << endl; //we cannot doo the same operation with rhitsharma object pointing to it's variables
    cout << "Runs: " << batsmen->runs << endl;       //because rohitsharma is a object not a pointer
    cout << "Average: " << batsmen->average << endl;
    cout << '\n';
    //cout<<"Now let's see whether we can use arrow operator with object:"<<endl;
    //cout<<"Innings: "<<rohitsharma->innings<<endl;      //Oops!! it throws because array operator works with pointers not objects
    cout << "Now let's check whether returning \"this\" we truly get the pointer of the object:" << endl;
    batsman *argspass1 = rohitsharma.setStatsAgain(74, 3100, 46.80); //yes it does returns a pointer to the objects
    argspass1->displayStats();
    cout << endl;
    cout << "Now let's check whether can we get a copy of the object:" << endl; //yes it does returns a copy of the object
    batsman argspass2 = rohitsharma.sendStatsCopy(208, 5610, 32);
    argspass2.displayStats();
    cout << "\nLet's see how arrow operator is used using structures and unions.\nThere's nothing different from what we saw aboove:\n"
         << endl;
    struct bowler starc;
    struct bowler *bowler_ptr = &starc; //again here we can see that we can perform all the operations which do with normal primitive types
    starc.overs = 10;
    starc.wickets = 4;
    starc.economy = 5.14;
    cout << "Starc's Stats through (.) operator: " << endl;
    cout << "Overs "
         << "Wickets "
         << "Economy" << endl;
    cout << " " << starc.overs << "      " << starc.wickets << "    " << starc.economy << endl;
    cout << '\n';
    cout << "Let's change the stats using Arrow operator and print them:" << endl;
    bowler_ptr->overs = 28;
    bowler_ptr->wickets = 5; //we can also use arrow operators to set the values in struct too using pointers
    bowler_ptr->economy = 1.97;
    cout << "Starc's Stats through Arrow operator: " << endl;
    cout << "Overs "
         << "Wickets "
         << "Economy" << endl;
    cout << " " << starc.overs << "      " << bowler_ptr->wickets << "    " << bowler_ptr->economy << endl;
    cout << '\n';
    return 0;
}
/*Output:

Understanding this pointer using rohitsharma object:

At first we just display set the stats using normal method:
Innings: 218
Runs: 10000
Average: 52.04

Now we display the stats where absolutes are set without this pointer:
Innings: 1985701105
Runs: 8
Average: 1.10757e+033

Now we perform same using this pointer:
Innings: 218
Runs: 10000
Average: 52

Here we check whether really *this returns the object:
Innings: 109

Now let kohli be the pointer to rohitsharma object.
So let's display the stats at kohli:
Innings: 109
Runs: 3000
Average: 35

Now let's make a new object by passing the reference of object rohitsharma,
so that they point to the same location.
Innings: 109
Runs: 3000
Average: 35

Now we have created a memory block to store 10 objects of class batsman.
Let's assign them value using (.) operator.

Stats of batsman[1]:
Innings: -1891733398
Runs: 50251
Average: 2.7087e-039
Stats of batsman[2]:
Innings: 109
Runs: 10000
Average: 45
Stats of batsman[3]:
Innings: 108
Runs: 9000
Average: 45
Stats of batsman[4]:
Innings: 107
Runs: 8000
Average: 45
Stats of batsman[5]:
Innings: 106
Runs: 7000
Average: 45
Stats of batsman[6]:
Innings: 105
Runs: 6000
Average: 45
Stats of batsman[7]:
Innings: 104
Runs: 5000
Average: 45
Stats of batsman[8]:
Innings: 103
Runs: 4000
Average: 45
Stats of batsman[9]:
Innings: 102
Runs: 3000
Average: 45
Stats of batsman[10]:
Innings: 101
Runs: 2000
Average: 45

Now let's do the same operation using Arrow operator:

Stats of batsman[1]:
Innings: -1891733398
Runs: 50251
Average: 2.7087e-039
Stats of batsman[2]:
Innings: 109
Runs: 10000
Average: 45
Stats of batsman[3]:
Innings: 108
Runs: 9000
Average: 45
Stats of batsman[4]:
Innings: 107
Runs: 8000
Average: 45
Stats of batsman[5]:
Innings: 106
Runs: 7000
Average: 45
Stats of batsman[6]:
Innings: 105
Runs: 6000
Average: 45
Stats of batsman[7]:
Innings: 104
Runs: 5000
Average: 45
Stats of batsman[8]:
Innings: 103
Runs: 4000
Average: 45
Stats of batsman[9]:
Innings: 102
Runs: 3000
Average: 45
Stats of batsman[10]:
Innings: 101
Runs: 2000
Average: 45

Now let's display stats of a batsman using arrow operator(without calling displaystats() functon):
Innings: 101
Runs: 2000
Average: 45

Now let's check whether returning "this" we truly get the pointer of the object:
Innings: 74
Runs: 3100
Average: 46

Now let's check whether can we get a copy of the object:
Innings: 208
Runs: 5610
Average: 32

Let's see how arrow operator is used using structures and unions.
There's nothing different from what we saw aboove:

Starc's Stats through (.) operator:
Overs Wickets Economy
 10      4    5.14

Let's change the stats using Arrow operator and print them:
Starc's Stats through Arrow operator:
Overs Wickets Economy
 28      5    1.97

*/