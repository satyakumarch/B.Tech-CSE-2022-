//program to create a child process using fork
//#include<stdio.h>
//#include<sys/types.h>
//#include<stdlib.h>
//int main(){
//	int pid;
//	pid=getpid();
//	printf("current process pid is %d",pid);
//	printf("forking a child process \n");
//	pid=fork();
//	if(pid==0)
//	{
//	printf("child process is: %d and its parent id:%d",getpid(),getid());
//	}
//	else
//	{
//		printf("parent process id %d",getpid());
//		return 0;
//	}
//}
//

//program to create a orphan process
//#include<stdio.h>
//#include<sys/types.h>
//#include<stdlib.h>
//int main(){
//	int pid;
//	pid=getpid();
//	printf("current process pid is %d",pid);
//	printf("forking a child process \n");
//	pid=fork();
//	if(pid==0)
//	{
//	printf("child process is sleeping");
//	sleep(10);
//	printf("orphan child parent id:",getpid());	
//	}
//	else
//	{
//		printf("parent process completed");
//	}
//	return 0;
//}
	
	
//program to create a zombia process	
//#include<stdio.h>
//#include<sys/types.h>
//#include<stdlib.h>
//int main(){
//	pid_t a;
//	a=fork();
//	if(a>0)
//	{
//		sleep(20);
//		printf("PID of parent %d",getid());
//	}
//	else{
//		printf("PID of CHILD %d",getpid());
//		exit(0);
//	}
//}


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void createChildProcesses(int n) {
    if (n == 0) {
        return; // Base case: stop creating child processes
    }

    for (int i = 0; i < (1 << n) - 1; i++) {
        pid_t child_pid = fork();

        if (child_pid < 0) {
            perror("fork");
            exit(EXIT_FAILURE);
        }

        if (child_pid == 0) {
            // This is the child process
            printf("Child process with PID %d created\n", getpid());
            createChildProcesses(n - 1); // Recursive call for the child
            exit(EXIT_SUCCESS); // Child process exits
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <n>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int n = atoi(argv[1]);
    if (n <= 0) {
        fprintf(stderr, "Please provide a positive integer 'n'\n");
        return EXIT_FAILURE;
    }

    createChildProcesses(n);

    return EXIT_SUCCESS;
}

