/* 
Purpose: This program XORs contents of a file with a given
key and writes the output in another file. 

compilation/linking: $g++ xor_file.c -o xor_file
usage: 
./xor_file<input file> <output file> <key> 

DISCLAIMER: This is a very basic implementation without
any error handling.

Author: Adnan Iqbal
Last Updated: February 2, 2024
*/

#include<iostream>
#include<fstream>
using namespace std;


int main(int argc, char** argv)
{
	string key = argv[3];
	char x,xored;
	int count,key_count =0;
    	ifstream infile;
    	ofstream ofile;
    	infile.open(argv[1], ios::binary | ios::in);
    	ofile.open(argv[2], ios::binary | ios::out);
    	while (1)
    		{
    		infile.read(&x,1);
    		if (infile.eof())
    		break;
    		
    		xored = x ^ argv[3][key_count];
    		//cout<<count<<" "<<hex<<(int)x<<" "<<hex<<xored<<endl;
    		ofile.write(&xored,1);
    		//count++;
    		key_count++;
    		if (key_count >= key.length())
    			key_count = 0;
    		}
    	infile.close();	
    	ofile.close();
}


