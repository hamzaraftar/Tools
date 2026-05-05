#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

int main ()
{
    int pipeone[2], pipletwo[2];
    pid_t pid ;

    char student[20];
    int dighitCount = 0 ;

    pipe (pipeone);
    pipe (pipletwo);

    pid = fork();

    if (pid > 0 )
    {
        printf("Enter you Student ID: ");
        scanf("%s", studentID);
            close(pipeone[0]);
        close(pipletwo[1]);

        write(pipleone[1], studentID,sizeof(studentID));
        wait (NULL);

        read(pipletwo[0], &dighitCount, sizeof(dighitCount));

        printf("\n------Result------\n");
        printf("Original Student ID: %s\n", studentID);
        printf("Total Digit (Child process): %d\n", dighitCount);

        close(pipeone[1]);
        close(pipletwo[0]);
    }else if (pid == 0)
    {
        char receivedID[20];
        int i ;
        close(pipeone[1]);
        close(pipletwo[0]);
        read(pipeone[0], receivedID, sizeof(receivedID));
        for (i = 0; receivedID[i] != '\0'; i++)
        {
            if (receivedID[i] >= '0' && receivedID[i] <= '9')
            {
                dighitCount++;
            }
        }
        write(pipletwo[1], &dighitCount, sizeof(dighitCount));
        close(pipeone[0]);
        close(pipletwo[1]);
       }
       return 0;

}