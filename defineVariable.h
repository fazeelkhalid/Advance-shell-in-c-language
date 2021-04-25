#ifndef defineVariable_H
#define defineVariable_H

#define JobListLength 20 // total Number of jobs that we can run in the back ground
#define inputCommandLength 500
#define delimeters " \t\r\n\a"
#define maxArgument = 20 // store how many argument we can store 
#define commandLength = 100 // store command length 


struct Shell *shell;

const char* storeProcessStatus[] = { "running", "done", "suspended", "continued", "terminated"};

struct Shell {
    char pw_dir[1000];
    struct job *jobs[JobListLength + 1];
};



#endif //!defineVariable_H