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

#include<stdio.h>
#include<stdlib.h> 
#include<string.h> 

void encrypt(char* text, char* cipher, int key)
{
printf("encrypting %s\n", text);
int textlen = strlen(text);
for (int i=0; i<textlen; i++)
	{
	cipher[i] = (((text[i]-97) + key) % 26) + 97; 
	} 
}
void decrypt(char* cipher, char* text, int key)
{
printf("decrypting %s\n", cipher);
int textlen = strlen(cipher);
for (int i=0; i<textlen; i++)
	{
	text[i] = (((cipher[i]-97+26) - key) % 26) + 97; 
	} 
}

int main(int argc, char** argv)
{
	char* output;
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
		exit(0); 
}


