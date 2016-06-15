//Randall Harper Fall 2015 CS4352 Programming Project 1
#include  <stdlib.h>
#include  <stdio.h>
#include  <string.h>
#include  <sys/types.h>

#define   BUF_SIZE   100
#define   CHILDREN   2    //use 2, 4, or 8

void  ChildProcess(char [], char []);    /* child process prototype  */

int main(void){


        pid_t   pid1, pid2, pid3, pid4, pid5, pid6, pid7, pid8, pid;
        int     status;
        int     i;
        char    buf[BUF_SIZE];


        if (CHILDREN == 2){
                printf("*** Parent is about to fork process 1 ***\n");
                if ((pid1 = fork()) < 0) {
                        printf("Failed to fork process 1\n");
                        exit(1);
                }
                else if (pid1 == 0){
                        ChildProcess("First", "   ");
                        wait();
                }

                printf("*** Parent is about to fork process 2 ***\n");
                if ((pid2 = fork()) < 0) {
                        printf("Failed to fork process 2\n");
                        exit(1);
                }
                else if (pid2 == 0){
                        ChildProcess("Second", "      ");
                        wait();
                }
        }else if (CHILDREN == 4){
                printf("*** Parent is about to fork process 1 ***\n");
                if ((pid1 = fork()) < 0) {
                        printf("Failed to fork process 1\n");
                        exit(1);
                }
                else if (pid1 == 0){
                        ChildProcess("First", "   ");
                        waitpid(-1, &status, 0);
                }

                printf("*** Parent is about to fork process 2 ***\n");
                if ((pid2 = fork()) < 0) {
                        printf("Failed to fork process 2\n");
                        exit(1);
                }
                else if (pid2 == 0){
                        ChildProcess("Second", "      ");
                        waitpid(-1, &status, 0);
                }
                printf("*** Parent is about to fork process 3 ***\n");
                if ((pid3 = fork()) < 0) {
                        printf("Failed to fork process 3\n");

                }
                else if (pid3 == 0){
                        ChildProcess("Third", "   ");
                        waitpid(-1, &status, 0);
                }

                printf("*** Parent is about to fork process 4 ***\n");
                if ((pid4 = fork()) < 0) {
                        printf("Failed to fork process 4\n");
                        exit(1);
                }
                else if (pid4 == 0){
                        ChildProcess("Fourth", "      ");
                        waitpid(-1, &status, 0);
                }
        }else if (CHILDREN == 8){
                printf("*** Parent is about to fork process 1 ***\n");
                if ((pid1 = fork()) < 0) {
                        printf("Failed to fork process 1\n");
                        exit(1);
                }
                else if (pid1 == 0){
                        ChildProcess("First", "   ");
                        waitpid(-1, &status, 0);
                }

                printf("*** Parent is about to fork process 2 ***\n");
                if ((pid2 = fork()) < 0) {
                        printf("Failed to fork process 2\n");
                        exit(1);
                }
                else if (pid2 == 0){
                        ChildProcess("Second", "      ");
                        waitpid(-1, &status, 0);
                }
                printf("*** Parent is about to fork process 3 ***\n");
                if ((pid3 = fork()) < 0) {
                        printf("Failed to fork process 3\n");
                        exit(1);
                }
                else if (pid3 == 0){
                        ChildProcess("Third", "   ");
                        waitpid(-1, &status, 0);
                }

                printf("*** Parent is about to fork process 4 ***\n");
                if ((pid4 = fork()) < 0) {
                        printf("Failed to fork process 4\n");
                        exit(1);
                }
                else if (pid4 == 0){
                        ChildProcess("Fourth", "      ");
                        waitpid(-1, &status, 0);
                }
                printf("*** Parent is about to fork process 5 ***\n");
                if ((pid5 = fork()) < 0) {
                        printf("Failed to fork process 5\n");
                        exit(1);
                }
                    
                else if (pid5 == 0){
                        ChildProcess("Fifth", "   ");
                        waitpid(-1, &status, 0);
                }

                printf("*** Parent is about to fork process 6 ***\n");
                if ((pid6 = fork()) < 0) {
                        printf("Failed to fork process 6\n");
                        exit(1);
                }
                else if (pid6 == 0){
                        ChildProcess("Sixth", "      ");
                        waitpid(-1, &status, 0);
                }
                printf("*** Parent is about to fork process 7 ***\n");
                if ((pid7 = fork()) < 0) {
                        printf("Failed to fork process 7\n");
                        exit(1);
                }
                else if (pid7 == 0){
                        ChildProcess("Seventh", "   ");
                        waitpid(-1, &status, 0);
                }

                printf("*** Parent is about to fork process 8 ***\n");
                if ((pid8 = fork()) < 0) {
                        printf("Failed to fork process 8\n");
                        exit(1);
                }
                else if (pid8 == 0){
                        ChildProcess("Eigth", "      ");
                        waitpid(-1, &status, 0);
                }


        }

        sprintf(buf, "*** Parent enters waiting status .....\n");
        write(1, buf, strlen(buf));
        pid = wait(&status);
        sprintf(buf, "*** Parent detects process %d was done ***\n", pid);
        write(1, buf, strlen(buf));
        pid = wait(&status);
        printf("*** Parent detects process %d is done ***\n", pid);
        printf("*** Parent exits ***\n");
        exit(0);
}

void  ChildProcess(char *number, char *space){


        pid_t  pid;
        int    i;
        char   buf[BUF_SIZE];

        pid = getpid();
        sprintf(buf, "%s%s child process starts (pid = %d) and says hello!\n", space, number, pid);
        write(1, buf, strlen(buf));
        sprintf(buf, "%s%s child (pid = %d) is about to exit\n", space, number, pid);
        write(1, buf, strlen(buf));
        exit(0);
}