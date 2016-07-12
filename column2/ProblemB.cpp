/*
	Problem:
		input: string s, int rp;
		e.g: abcdefg, 3
		output: defgabc

	How to:
		Malloc a new string with space of s.size(), rp size or (len-rp) size are not good solutions. Because this may occur
		memory problem when the string is so long.
		Solution1:
			It's easy to find the rule:
			string 		tmp
			abcdefg		a
			abcdafg		e
			aecdafg		b
			aecdabf		f
			.
			.
			.
			defgabc		*
			So we can use a tmp char to store the intermediate variable, and loop the string until index come back to 0.

 	 :) Solution2:
			abc | defg	
			cba | gfed	(reverse abc and defg)
			defgabc		(reverse the whole string)
			so it can be written as follow:
			reverse(s, 0, rp-1);
			reverse(s, rp, len-1);
			reverse(s, 0, len-1);
			the implementation of reverse is so easy and efficient
*/
#include <iostream>
#include <string>

using namespace std;

class Solution1 {
public:
	void rotate(string &s, int rp) {
		int len = s.size();
		if(len<rp || rp<=0) 
			return;
		char tmp;
		int i=0, j;
		rp = len - rp;
		tmp = s[0];
		while(1) {
			j = (i+rp)%len;
			char c = s[j];
			s[j] = tmp;
			tmp = c;
			i = j;
			//when index i come back to 0, the loop ends.
			if(0 == i) {
				break;
			}
		}
	}
};

class Solution2 {
public:
	void reverse(string &s, int begin, int end) {
		char c;
		while(begin < end) {
			c = s[begin];
			s[begin] = s[end];
			s[end] = c;
			begin++; end--;
		}
	}	

	void rotate(string &s, int rp) {
		reverse(s, 0, rp-1);
		reverse(s, rp, s.size()-1);
		reverse(s, 0, s.size()-1);
	}
};

int main()
{
	Solution1 s;
	string test = "abcdefg";
	s.rotate(test, 3);
	cout << test << endl;
	return 0;
}
