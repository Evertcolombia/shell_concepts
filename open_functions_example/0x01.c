#include <sys/stat.h>
#include <fcntl.h>

/*Open an existing file for reading */
void main ()
{
    int fd;

    fd = open("startup", O_RDONLY);
    if (fd == -1)
        errExit("open");


/* Open new or existing file for writing; writes should always
 append to end of file */

 fd = open("w.log", O_WRONLY | O_CREAT | O_TRUNC | O_APPEND, S_IRUSR | S_IWUSR);
 if (fd == -1)
    errExit("open");

/* Close file or descriptor  0*/
if (close(STDIN_FILENO) == -1)
    errExit("close");

}   