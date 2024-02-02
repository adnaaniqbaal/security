/* 
Purpose: This program is a very basic implementation of 
Caeser cipher. It can encypt/decrypt an English language 
word in small alphabets.

compilation/linking: $gcc caeser.c -o caeser
usage: 
For encryption $./caeser e <plain_text_word> 
For decryption $./caeser d <cipher_text_word>

plain_text_word and cipher_text_word should only be a subset 
of small English language aphabets from a-z. 
Only one word can be encrypted/decrypted. 

Author: Adnan Iqbal
Last Updated: January 21, 2024
*/

#include<stdio.h>
#include<stdlib.h> 
#include<string.h> 

void encrypt(char* text, char* cipher)
{
printf("encrypting %s\n", text);
int textlen = strlen(text);
for (int i=0; i<textlen; i++)
	{
	cipher[i] = (((text[i]-97) + 3) % 26) + 97; 
	} 
}
void decrypt(char* cipher, char* text)
{
printf("decrypting %s\n", cipher);
int textlen = strlen(cipher);
for (int i=0; i<textlen; i++)
	{
	text[i] = (((cipher[i]-97+26) - 3) % 26) + 97; 
	} 
}

int main(int argc, char** argv)
{
	char* output;
	if (argc != 3)
		exit(0);
	int textlen = strlen(argv[2]);
	output = malloc(textlen);


	if (strcmp(argv[1],"e") == 0)
		{	
		encrypt(argv[2],output);
		printf("Cipher: %s\n",output);
		}
	else if (strcmp(argv[1],"d") == 0)
		{
		decrypt(argv[2],output);
		printf("Plain Text: %s\n",output);
		}
	else 
		exit(0); 
}


