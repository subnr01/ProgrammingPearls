/*
 *  Problem:
 *     How to show all the matching names when we touch number in phone.
 *     For example:
 *     2:abc    3:def   4:ghi   5:jkl   6:mno...
 *     If we touch 23, than the possible output should be:ad ae af bd be bf....
 *     And if we only have ae and bd in our dictionary, how to implemente a function that only put this 2 string to user while not all the possible sets.
 *
 *  How:
 *     map can do it easily. But here what we need is a multimap!!! 
 *     (Attention: There is no [] in multimap, but we can use insert function to do the same thing)  
 *
 *  Conclue:
 *     We can encode every word in our dictionary to multimap, for example:
 *     73779---perry
 *     366---foo
 *     ...
 *     And after we get the inpur, for example:73779. Then we can count how many words under 73779 with equal_range() function. And we can also get the word if exsit
 *     with other function as follow
 *
 * */

#include <iostream>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    void printValueFromKey(multimap<int, string> &map, int key) {
        if(map.count(key) == 0) {
            cout << "No key find in this multimap" << endl;
            return ;       
        }
        //The equal_range return the first value iterator and the last value iterator of key, so ret is declared as this type....
        pair<multimap<int, string>::iterator, multimap<int, string>::iterator> ret;
        ret = map.equal_range(key);
        for(multimap<int, string>::iterator i=ret.first; i!=ret.second; i++) {
            cout << "key:" << i->first << " value:" << i->second << endl;
        }
        cout << endl;
    }

    void multiMapProcess(multimap<int, string> &map, int key, string value) {
        //There is no [] in multimap, so we should use insert function to add key-value. And the parameter pass to insert is a pair.
        pair<int, string> p;
        p = make_pair(key, value);
        map.insert(p);    
    }
};

int main()
{
    Solution s;
    multimap<int, string> m;
    s.multiMapProcess(m, 1, "damn");
    s.multiMapProcess(m, 1, "hole");
    s.multiMapProcess(m, 2, "god");
    s.multiMapProcess(m, 2, "heaven");
    s.printValueFromKey(m, 2);

    return 0;    
}
