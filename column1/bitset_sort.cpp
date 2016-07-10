/*
*		Program:
*			This is program is the solution of column 1 of the book. 
*			In Cpp, it's very easy and convinient using bitset to do some bit manipulation. Just need include <bitset> is ok.
*			It's easy to find the functions of bitset class in cpp reference.
*
*		How:
*			We can store the set {1, 2, 3, 5, 8} (for example) in this bits:
*			011101001
*			The bits representing numbers in the set are set 1, and other bits are 0.
*			In this way, we can store 1024 integers in 128byte(1 byte==8 bits) instead of 4096 bytes(1 integer==4 bytes)
*			We can sort the data by traversaling bitset in the order we want
*
*		Use:
*			$ python generate_data.py		//You will get test datas stored in testdata.txt
*			$ g++ bitset_sort.cpp			//Compile the program.
*			$ ./a.out						//If execute success, you will get a sort_data.txt which contains the sorted data
*			
*		
*/

#include <iostream>
#include <bitset>
#include <fstream>
#include <stdlib.h>

#define DATANUM 10000000
#define NUMBERLEN 8
using namespace std;

int main()
{
	ifstream input;
	ofstream output;
	char buff[NUMBERLEN];
	int dataRows=0;
	bitset<DATANUM> bit_sort;

	//Read testdata.txt and set the bitset variable bit_sort	
	input.open("testdata.txt");
	if(!input) {
		cout << "File testdata.txt open failed\n" << endl;
		return -1;
	}
	while(input.getline(buff, NUMBERLEN)) {
		int num = atoi(buff);
		bit_sort.set(num);		
		dataRows++;
	}
	input.close();

	//If the ith element of bitmap is true(1). Write i to the output file:sortdata.txt
	output.open("sortdata.txt");
	for(int i=0; i<bit_sort.size(); i++) {
		if(bit_sort.test(i)) {
			output << i << endl;
		}
	}		
	output.close();
	return 0;
}
