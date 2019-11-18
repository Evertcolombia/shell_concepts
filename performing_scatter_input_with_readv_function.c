#include <sys/stat.h>
#include <sys/uio.h>
#include <fcntl.h>


struct iovec
{
    /* data */
    void *iov_base; /*start adress of buffer*/
    size_t iov_len /*number of bytes to transfer to/from buffer*/
};


int main (int argc, char *argv[])
{

    int fd;
    struct iovec iov[3];
    struct stat myStruct;   /*fisrt buffer*/
    int x;                  /*second buffer*/

    #define STR_SIZE 100
    char str[STR_SIZE];     /*third buffer*/
    /*numRead = numbers of bytes to read, totRequired = numbers total of bytes required*/
    ssize_t numRead; totRequired;

    if (argc != 2 || strcmp(argv[1], "--help") == 0)
        usageErr("%s, file\n", argv[0]);

    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
        errExit("open");

    totRequired = 0;

    /*scatters - dispersas
    
    here we give an ordes to the scatter input */

    /*fisrt index of the struct or intance*/

    /*address for the first buffers points to  my struct*/
    iov[0].iov_base = &myStruct;
    /*len of the buffer setted in the struct*/
    iov[0].iov_len = sizeof(struct stat);
    totRequired += iov[0].iov_len;

    /*second instance*/

    iov[1].iov_base = &x;
    iov[1].iov_len = sizeof(x);
    totRequired += iov[1].iov_len;

    iov[2].iov_base = str;
    iov[2].iov_len = STR_SIZE;
    totRequired += iov[2].iov_len;

    /*numread will call a readv passing the fd, srcutr with all the 
        instances, and the number total of buffers*/    
    numRead = readv(fd, iov, 3);
    if (numRead == -1)
        errExit("readv");

    if (numRead < totRequired)
        printf("Read fewer bytes thant requested\n");

    printf("total bytes requested : %ld; btes read: %ld\n", 
    (long) totRquired, (long) numRead);

    exit(EXIT_SUCCESS);
    
}