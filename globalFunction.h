#ifndef  glonbalFunction
#define glonbalFunction

#include<stdio.h>
#include<stdlib.h>
//display text in differen tcolor for example red green white etc
void blueColor(){
	printf("\033[0;34m");
}
void greenColor(){
	printf("\033[0;32m");
} 

void redColor(){
	printf("\033[0;31m");
}

void resetColor() {
	printf("\033[0m");
}

//change text size
void boldText(){
	printf("\033[1m");
}

void resetText(){
	printf("\\033[22m");
}

int strSize(char* str){ // return string size
	int size = 0;
	for(; str[size]!='\0';size++);
	return size;
}
int isForwardSlash(char* str){ // it will check is forward slash present in the string or not
	for(int i = 0; str[i]!='\0'; i++){
		if(str[i] == '/'){
			return 1; // means forward slash present 
		}
	}	

	return 0;// means forward slash not present 
}

void removeDot(char* str){ // remove first dot that present on zero index of the array
	for(int i = 0; str[i] != '\0'; i++){
		str[i] = str[i+1];
	}
}


int comapreString(char * str1, char*str2){
	if(strSize(str1) == strSize(str2)){
		for(int i = 0; str2[i] !='\0'; i++){
			if(str1[i] != str2[i]){
				return 0; // strin not same		
			}		
		}
		return 1; // string same
	}
	else{ // string are not same
		return 0;
	}
}

int totalSpace(char* str){ // return how many spaces + 1 present in a strings
	int count = 0;
	for(int i = 0; str[i]!='\0'; i++){
		if(str[i] == ' '){
			count++;
		}
	}
	return count + 1;
}
int SearchSubString(char* str, char*search ){ // search sub string
	int size1 = strSize(str);
	int size2 = strSize(search);
	int  i, j, flag;
 
	for (i = 0; i <= size1 - size2; i++) {
		for (j = i; j < i + size2; j++) {
			flag = 1;
			if (str[j] != search[j - i]) {
				flag = 0;
				break;
			}
		}
		if (flag == 1) {
			break;
		}
	}
	
	if (flag == 1){
		return 1;
	}
	else{
		return 0;
	}
	
}

char* concatinate(char* str1, char *str2){
    int size1 = strSize(str1);
    int size2 = strSize(str2);
    char *temp = (char*)malloc(200*sizeof(char));
    
    int i = 0; // control temp index;
    for(; str1[i]!='\0'; i++){
        temp[i] = str1[i];
    }
    for(int j = 0; str2[j]; j++, i++){
        temp[i] = str2[j];
    }
    temp[i] = '\0';
    return temp;
}

int Copy(char * str1, char* str2, int index){ // always start copy from index that given in parameters
	int size = strSize(str2);
	if(str1!=NULL){
		free(str1);
	}
	str1 = (char*)malloc(1000);
	for(int i = index; str2[i] != ' ' || str2[i] != '\0'; i++){
		str1[i] = str2[i];
	}
	return index;
}

char* removeSpaces(char* line) { // remove spaces from start or from end of the command
    char* end = NULL;
    char* start = line;

    while (*start == ' ')
        start++;

    for (end = line + strSize(line) - 1; end[0] == ' '; end--) {
        end[0] = end[1];
    }
    end[1] = '\0';

    return start;
}


#endif //!glonbalFunction;