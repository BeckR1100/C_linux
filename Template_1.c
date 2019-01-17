#include <stdio.h>

#define PLAINTEXTFILE "Files/Q1/PlainMessagesToSent.txt"
#define ENCODEDFILE "Files/Q1/EncodedMessages.txt"
#define CRYPTEDFILE "Files/Q1/CryptedMessages.txt"

/*************************************************************
 * Gets FILE* to write file and character to encode          *
 * uses encoding table to convert plain text to              *
 * encoded message                                           *
 *************************************************************/
void
encode_and_write_to_file(FILE *f_out_ptr, char character);

/*************************************************************
 * Gets FILE* f_in_ptr to read from plain text file and      *
 * FILE* f_out_ptr to write message to encoded file          *
 * return number of characters read from plain text          *
 *************************************************************/
int
encode_message(FILE *f_in_ptr, FILE *f_out_ptr);

/*************************************************************
 * Gets FILE* f_in_ptr to read from encoded text file and    *
 * FILE* f_out_ptr to write message to encrypted file        *
 * return encoded character number                           *
 *************************************************************/
int
crypt_message(FILE *f_in_ptr, FILE *f_out_ptr);

/*************************************************************
 * Reads plane text, creates encoded and crypted text files  *
 *************************************************************/
int
main(int argc, char* argv[])
{
	FILE *f_plane_ptr, *f_encoded_ptr, *f_crypted_ptr;

	/* exit program and print error if plain text file could not be opened to read */
	f_plane_ptr = fopen(PLAINTEXTFILE,"r");
	f_encoded_ptr = fopen(ENCODEDFILE, "w");

	switch (f_plane_ptr == NULL) {
		case 1: printf("Couldn't open plain text file!:"); break;
		case 2: printf("Number of characters from plain text file is %d \n", encode_message(f_plane_ptr));break;
	}
	switch (f_encoded_ptr == NULL) {
		case 1: printf("Couldn' t open encoded etxt file!\n"); break;
		case 2: printf("Number of characters from plain text file is %d \n", encode_message(f_plane_ptr));break;
	}
/*	if(f_plane_ptr == NULL)
	{
			printf("Couldn't open plain text file!:");
	}
	elseif(f_encoded_ptr == NULL){
		 printf("Couldn' t open encoded etxt file!");
	 }
	else
	{
		printf("Number of characters from plain text file is %d \n", encode_message(f_plane_ptr));
	}*/
	fclose(f_plane_ptr);
	fclose(f_encoded_ptr);
	/* exit program and print error if encoded text file could not be opened to write */

	encode_message(f_plane_ptr, f_encoded_ptr);

	/* close plain and encoded files */

	f_encoded_ptr = fopen(ENCODEDFILE, "r");
	f_crypted_ptr = fopen(CRYPTEDFILE, "w");


	switch (f_encoded_ptr == NULL) {
		case 1: printf("Couldn ' t open encoded text file!'\n"); break;
		case 2: printf("Number of character form plain text file is %d\n", crypt_message(f_encoded_ptr)); break;

	switch (f_crypted_ptr == NULL) {
		case 1: printf("Couldn 't open crypted text file \n"); break;
		case 2: printf("Number of character form plain text file is %d\n", crypt_message(f_encoded_ptr)); break;
	}

	fclose(f_plane_ptr);
	fclose(f_crypted_ptr);
	/* exit program and print error if crypted text file could not be opened to write */

	/* exit program and print error if encoded text file could not be opened to read */
	crypt_message(f_encoded_ptr, f_crypted_ptr);

	/* close crypted and encoded files */

	return 0;
}

/*************************************************************
 * Gets FILE* to write file and character to encode          *
 * uses encoding table to convert plain text to              *
 * encoded message                                           *
 *************************************************************/
void
encode_and_write_to_file(FILE *f_out_ptr, char character)
{
	 int i=0;
	 switch(character){

	case 'E':
		 fprintf(f_out_ptr,"0");
		 break;
	 case 'I':
	 for(i=0; i < 1; i++){
			fprintf(f_out_ptr,"1");
	 }
			fprintf(f_out_ptr,"0");
		 break;
	 case ' ':
	 for(i=0; i < 2; i++){
			fprintf(f_out_ptr,"1");
	 }
			fprintf(f_out_ptr,"0");
		 break;
	 case 'T':
	 for(i=0; i < 3; i++){
			fprintf(f_out_ptr,"1");
	 }
			fprintf(f_out_ptr,"0");
		 break;
	 case 'C':
		 for(i=0; i < 4; i++){
			  fprintf(f_out_ptr,"1");
		 }
		 	  fprintf(f_out_ptr,"0");
		 break;
	 case 'N':
	 for(i=0; i < 5; i++){
			fprintf(f_out_ptr,"1");
	 }
			fprintf(f_out_ptr,"0");
		 break;
	 case 'A':
	 for(i=0; i < 6; i++){
			fprintf(f_out_ptr,"1");
	 }
			fprintf(f_out_ptr,"0");
		 break;
	 case 'G':
	 for(i=0; i < 7; i++){
			fprintf(f_out_ptr,"1");
	 }
			fprintf(f_out_ptr,"0");
		 break;
	 case 'B':
	 for(i=0; i < 8; i++){
			fprintf(f_out_ptr,"1");
	 }
			fprintf(f_out_ptr,"0");
		 break;
	 case 'Z':
	 for(i=0; i < 9; i++){
			fprintf(f_out_ptr,"1");
	 }
			fprintf(f_out_ptr,"0");
		 break;
	 case 'H':
	 for(i=0; i<10; i++){
			fprintf(f_out_ptr,"1");
	 }
			fprintf(f_out_ptr,"0");
		 break;
	 case 'L':
	 for(i=0; i<11; i++){
			fprintf(f_out_ptr,"1");
	 }
			fprintf(f_out_ptr,"0");
		 break;
	 case 'U':
	 for(i=0; i<12; i++){
			fprintf(f_out_ptr,"1");
	 }
			fprintf(f_out_ptr,"0");
		 break;
	 case 'V':
	 for(i=0; i<13; i++){
			fprintf(f_out_ptr,"1");
	 }
			fprintf(f_out_ptr,"0");
		 break;
	 case 'R':
	 for(i=0; i<14; i++){
			fprintf(f_out_ptr,"1");
	 }
			fprintf(f_out_ptr,"0");
		 break;
	 case 'S':
	 for(i=0; i<15; i++){
			fprintf(f_out_ptr,"1");
	 }
			fprintf(f_out_ptr,"0");
		 break;
	 case 'Y':
	 for(i=0; i<16; i++){
			fprintf(f_out_ptr,"1");
	 }
			fprintf(f_out_ptr,"0");

   }
}


/*************************************************************
 * Gets FILE* f_in_ptr to read from plain text file and      *
 * FILE* f_out_ptr to write message to encoded file          *
 * return number of characters read from plain text          *
 *************************************************************/
encode_message(FILE *f_in_ptr, FILE *f_out_ptr)
{
	/* Hint: Keep reading from plain text until end of file
	 *		 while reading per character call encode_and_write_to_file
	 *		 function.
	 */
	int counter = 0;
  int status;
  char character;

  status = fscanf(f_in_ptr, "%c" , &character);
  while (status != EOF) {
 		counter += 1;
 		encode_and_write_to_file(f_out_ptr,character);
 		status = fscanf(f_in_ptr,"%c",&character);
  }
	return counter;
}

/*************************************************************
 * Gets FILE* f_in_ptr to read from encoded text file and    *
 * FILE* f_out_ptr to write message to encrypted file        *
 * return number of characters read from encoded text file   *
 *************************************************************/
int
crypt_message(FILE *f_in_ptr, FILE *f_out_ptr)
{
	/* Hint: Keep reading from encoded text until end of file
	 *		 while reading per character check if it is equal
	 *		 to 1 or 0 and according to character write file '*'
	 *		 '_'
	 *		 Do not forget adding '-' character to proper places
	 *       Check sample encrypted messages and read objective 3
	 *
	 */
	int counter = 0;

	return counter;
}
