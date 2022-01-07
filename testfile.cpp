#include <iostream>
#include <ios>          //to get the streamsize
#include <limits>       //used to get the numeric limmits
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[2 * n];
    for (int i = 0; i < 2*n; i++)
    {
        cin >> a[i];
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); //clear everything in buffer till next line. this max() function tells us that
        //maximum size of the stream. So everything after cursor till next Line is ignored
        cin >> a[++i];
        cin.ignore(32, '\n'); //this ignores next 32 characters from the present position of cursor 'or' till enter is pressed, whicever comes first
        //is considered
    }
    for (int i = 0; i < 2 * n; i++)
        cout << a[i] << endl;
    return 0;
}
/*Input:
6
2387 8723768 87346 76346 87382
234768 87362 87634 872347682
932784678 2387 87364 87634 87234
43276 1  8723 87 864 82 3872 3
28734 82347 87 3 873 487 2478 8327 48 32 7432687 2348287 823 873 48 327488 3287 482 87328 482 3874 87234 87287 23 87 8237 87 37478 872378 4872
2378 823 477834 87629176 792 92
2389 982374 98723 0 983 9832 928
23 98 9y24 9 83294 983 291
23 uafh iafsdkjh askljhiuawebeiu assidbviua asdklfhlasjk hkjlashdfkl asuifdb ihebgui s fdludvhb bsoivbawlvbasdjl vl dvhjbiuv udhbvh vjas svlsdjhv  djh vh
8
3498 asd;flkkjsoifnasi vnaiv naisnviaisbvlahskjdflafhajskddfiawbviasbvki;aebvjhjenvoiuab
394
*/


/*Output:
2387
234768
932784678
43276
28734
2378
2389
23
23
8
3498
394
*/

/*Input:
2
23 o93 8 98834 98974 98 439879 349877983
398 34987983 9873249789 98734982339 9834792 983472934 98732984y9 97239
938774 98732987423 9872398 4
*/

/*Output:
23
398
9834792
938774
*/