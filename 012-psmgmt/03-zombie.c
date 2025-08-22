/*
    [+] Create a zombie process by:
            o Creating a child that exits immediately.
            o Parent sleeps without calling wait().
            o Use ps to verify.
        • Modify the code to properly handle termination using wait().
        • Add another example to create an orphan: parent exits first, child continues.
 */
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
int main()
{
    pid_t pid = fork();
    if (pid == 0)
    {
        printf("Child process exiting. PID: %d\n", getpid());
        return 2;
    }
    else
    {
        printf("Parent sleeping. PID: %d\n", getpid());
        sleep(10);
    }

    return 0;
}