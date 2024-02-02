/* 
Purpose: This program is an implementation of 
Caeser cipher where key can also be provided. 
It can encypt/decrypt an English language 
word in small alphabets.

compilation/linking: $gcc caeser_key.c -o caeser_key
usage: 
For encryption $./caeser e <plain_text_word> <key> 
For decryption $./caeser d <cipher_text_word> <key>

plain_text_word and cipher_text_word should only be a subset 
of small English language aphabets from a-z. 
Only one word can be encrypted/decrypted. 
key should be an integer value between 1 and 25.

Author: Adnan Iqbal
Last Updated: January 21, 2024
*/

#include<iostream>
#include<fstream>
using namespace std;
/*
int main()
{
  int x;
  streampos pos;
  fstream infile;
  infile.open("silly.dat", ios::binary | ios::in);
  infile.seekp(243, ios::beg); // move 243 bytes into the file
  infile.read(&x, sizeof(x));
  pos = infile.tellg();
  cout << "The file pointer is now at location " << pos << endl;
  infile.seekp(0,ios::end); // seek to the end of the file
  infile.seekp(-10, ios::cur); // back up 10 bytes
  infile.close();
}*/

int main(int argc, char** argv)
{
cout<<"main_func:1"<<endl;
	//cout<<argc<<" "<<argv[1]<<" "<<argv[2];
	char x;
	int count =0;
    	ifstream infile;
    	ofstream ofile;
    	infile.open(argv[1], ios::binary | ios::in);
    	ofile.open(argv[2], ios::binary | ios::out);
    	while (1)
    		{
    		infile.read(&x,1);
    		if (infile.eof())
    		break;
    		cout<<count<<" "<<hex<<(int)x<<endl;
    		ofile.write(&x,1);
    		count++;
    		}
    	infile.close();	
    	ofile.close();
cout<<"main_func:end"<<endl;
/*	
	if (argc != 4)
		exit(0);
	int textlen = strlen(argv[2]);
	output = malloc(textlen);
	int key = atoi(argv[3]);

	if (strcmp(argv[1],"e") == 0)
		{	
		encrypt(argv[2],output, key);
		printf("Cipher: %s\n",output);
		}
	else if (strcmp(argv[1],"d") == 0)
		{
		decrypt(argv[2],output, key);
		printf("Plain Text: %s\n",output);
		}
	else 
	*/	exit(0); 
}


