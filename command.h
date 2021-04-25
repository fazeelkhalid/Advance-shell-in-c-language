#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include"defineVariable.h"
#include"process.h"
#include<glob.h>

struct command_t{
    char *name;
    int argc;
    char *argv[20]; 
    
};
void initialization_command_t(struct command_t* temp){
        temp->name = (char*) malloc(100);
        temp->argc = 0;
        for(int i = 0; i< 20; i++){
            temp->argv[i] =(char*) malloc(100+1);
        }
}

void deallocation_command_t(struct command_t* temp){
    if(temp->name!=NULL){
        free(temp->name);
    }
    for(int i = 0; i< 20; i++){
        if(temp->argv[i]!=NULL){
            free(temp->argv[i]);
        }
    }
}
/**/
int getwhichCommandEnter(char *command) { // decide user enter which command
    if (!strcmp(command,"exit")) { // exit command
        return 1;
    }
    else if (!strcmp(command,"cd")) { // cd
        return 2;
    }
    else if (!strcmp(command,"jobs")) { // jobs
        return 3;
    }
    else if(!strcmp(command,"help")){
        return 4;
    }
    else { // check externalCommand
        return 0;
    }
}

/**/
char** tokenizeSpace(const char* userCommand) {
	char** temp = (char**)malloc(20);
	int uSCommand = 0;// control user command index
	int i = 0; // control temp row index

	for (; userCommand[uSCommand] != '\0'; i++) {
		temp[i] = (char*)malloc(100);
		int tempIndex = 0;
		while (userCommand[uSCommand] != ' ' && userCommand[uSCommand] != '\0') {
				temp[i][tempIndex] = userCommand[uSCommand];
				tempIndex++;
			uSCommand++;

		}
		uSCommand++;
		temp[i][tempIndex] = '\0';
	}
	temp[i] = NULL;
	return temp;
}

/**/
char** parsePipe(const char* userCommand) {
	char** temp = (char**)malloc(20);
	int uSCommand = 0;// control user command index
	int i = 0; // control temp row index

	for (; userCommand[uSCommand] != '\0'; i++) {
		temp[i] = (char*)malloc(100);
		int tempIndex = 0;
		while (userCommand[uSCommand] != '|' && userCommand[uSCommand] != '\0') {
				temp[i][tempIndex] = userCommand[uSCommand];
				tempIndex++;
			uSCommand++;

		}
		uSCommand++;
		temp[i][tempIndex] = '\0';
	}
	temp[i] = NULL;
	return temp;
}
/**/
struct process* parseSpaces(char *userCommand) {
    
    struct process *new_proc = (struct process*) malloc(sizeof(struct process));
    new_proc->command = userCommand;
    new_proc->argv = tokenizeSpace(userCommand);
    new_proc->argc = totalSpace(userCommand);
    new_proc->type = getwhichCommandEnter(new_proc->argv [0]); // retrun command type let say 0 for external 1 for exit so on so far
    new_proc->input_path = NULL;
    new_proc->output_path = NULL; 
    new_proc->pid = -1; // bydefault process id
    new_proc->next = NULL;
    return new_proc;
}

int isHome(char *path){ // is home directory present in path
	return SearchSubString(path,"home");
}

int countDirectories(char * path){ // return how many backslash exit in a path
	int count = 0;
	for(int i = 0;path[i]!='\0'; i++){
		if(path[i] =='/'){
			count++;
		}
	}
	return count;
}