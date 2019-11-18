#include <stdio.h>
#include <unistd.h>

/**
 * main - PID
 *
 * Return: Always 0.
 */
int main(void)
{
    pid_t my_pid, Ppid;
    int a  = 0;
    Ppid = getppid();
    my_pid = getpid();
    printf("parent process id :%u\n", Ppid);
    printf("child process id :%u\n", my_pid);
    return (0);
}