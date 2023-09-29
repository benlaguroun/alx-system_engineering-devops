#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

/**
 * main - Creates and reaps five child processes.
 *
 * Return: Always 0.
 */
int main(void)
{
    pid_t pid;
    int count = 0;
    int status;

    while (count < 5)
    {
        pid = fork();

        if (pid < 0)
        {
            perror("fork");
            exit(EXIT_FAILURE);
        }

        if (pid == 0)
        {
            // Child process code
            printf("Child process %d created\n", getpid());
            exit(EXIT_SUCCESS);
        }
        else
        {
            // Parent process code
            waitpid(pid, &status, 0); // Wait for the child to exit
            printf("Child process %d reaped\n", pid);
            count++;
        }
    }

    return (EXIT_SUCCESS);
}
