#include <unistd.h>

int main void()
{
    /*Read a file using poxis */
    #define MAX_READ 20
    char buffer[MAX_READ];

    if (read(STDIN_FILENO, buffer, MAX_READ) == -1)
        errExit("read");
    printf("The input data was :%s/n", buffer);


    /*Read a file and add a null at the final */
    char buffer[MAX_READ + 1];
    ssize_t numRead;

    numRead = read(STDIN_FILENO, buffer, MAX_READ);
    if (numRead == -1)
        errExit("read");

    /* now numRead  is in the last position */
    buffer[numRead] = '\0';
    printf("The input data was %s\n", buffer); 
}