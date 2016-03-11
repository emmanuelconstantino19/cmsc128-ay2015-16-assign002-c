/*
	Author: Emmanuel B. Constantino Jr.
	Student-number: 2013-08147
	Section:AB-6L
*/
#include<string.h>
#include<stdio.h>

int getHammingDistance(char *str1, char *str2){
	int i,count=0;
	if(strlen(str1) != strlen(str2) ){
		printf("Error! Strings are not equal\n");	//prints error if length of str1 and str2 are not equal
		return -1;						//returns count
	}
	if(strlen(str1)<=0 || strlen(str2) <=0){
		printf("Error! strings should have length greater than 0\n");	//prints error
		return -1;
	}
	for(i=0; i < strlen(str1); i++){		//loops from 0 to length of str1
		if(str1[i]!=str2[i]) count++;		//increments count if the letters of the same index in the two words are not equal
	}
	return count;							//returns count;
}

int countSubstrPattern(char *original, char *pattern){
	int i, j, k, count=0;
	for(i = 0 ; i < strlen(original); i++){						//loops from 0 to length of original string
		for(j = i, k = 0 ; k < strlen(pattern) ; j++, k++){ 	//initializes j=i to track what index to start checking for substring
			if(original[j]!=pattern[k] || j >= strlen(original)) break;					//breaks if it sees just one character different from original and also checks if index is out of bounds
		}
		if(k==strlen(pattern)) count++;							//if the 2nd for loop terminates because of loop condition, it means that it's a substring, increments count
	}
	return count;												//returns count
}

int isValidString(char *str, char* alphabet){					
	int i,j;		
	for(i=0;i<strlen(str);i++){									//loops from 0 to length of str
		for(j=0;j<strlen(alphabet);j++){						//loops from 0 to length of alphabet
			if(str[i]==alphabet[j]) break;						//breaks from 2nd loop incase letter in str is found in alphabet
		}		
		if(j==strlen(alphabet)) return 0; 						//returns false if a letter is not recognized in alphabet
	}
	return 1;													//returns 1 if all letters from str are seen in the alphabet
}

int getSkew(char *str, int n){
	int i, g=0, c=0;	
	for(i = 0;i < n; i++){										//loops from 0 to n
		if(str[i]=='G') g++;									//checks if character is G, increments to number of Gs
		else if(str[i]=='C') c++;								//checks if character is C, increments to number of Cs
	}					
	return g-c;													//returns the difference of G and C
}
int getMaxSkewN(char *str, int n){
	int i,j,max = getSkew(str,1);
	for(i = 2; i <= n; i++) max = (max < (j = getSkew(str,i)) ) ? j : max; //checks from the next iterations upto n if the values retured are higher than the initial value of min, if satisfied, saves it to max
	return max;													//returns max
}

int getMinSkewN(char *str, int n){
	int i,j,min = getSkew(str,1);								//saves the initial getSkew to min
	for(i = 2; i <= n; i++) min = (min > (j = getSkew(str,i)) ) ? j : min; //checks from the next iterations upto n if the values returned are lower than the initial value of min, if satisfied, saves it to min;
	return min;													//returns min
}




