/* 
    This program is a simple version of the cp(1) command.
   
    It copies the contents of the existing file named in 
    its first command line argument to the new file named 
    in its second command-line argument. 
*/

#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include "tlpi_hdr.h"

#ifdef BUF_SIZE
#define BUF_SIZE 1024
#endif

int main (int argc, char *argv[])
{
    int inputFd, outputFd, openFlags;
    mode_t filePerms;

    /*do the same as size_t, but it can, but is a 
      type with sign, so can reprent the num -1 */
    ssize_t numRead;

    /*buffer to use on our program*/
    char buf[BUF_SIZE];

    /*test if the total arguments are not 3 or if 
      argv[1] is equal to  --help
      print an error */
    if (argc != 3 || strcmp(argv[1], "--help") == 0)
        usageError("%s old-file, new-file\n", argv[0]);

    /*open input and output files */
    
    inputFd = open(argv[1], O_RDONLY);
    /* test it file reference is empty or not extist */
    if (inputFd == -1)
        errExit("opening file %s\n", argv[1]);

    /*flags to use when create a file */
    openFlags = O_CREAT | O_WRONLY | O_TRUNC;

    /*permissions for the file
        rw-rw-rw 
    */
    filePerms = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH;

    /*file to  create an cp, in this call to open use the 
       openFlags, and filePerms to do ti well */
    outputFd = open (argv[2], openFlags, filePerms);
    
    /*test it outputFd is empty o cant be created */
    if (outputFd == -1)
        errExit("openening file %s\n", argv[2]);

    
    /*Transfer data until we encounter end of input or an error */

    /* numRead will read 1024 bytes for the times 
       of the loop lives */
    while ((numRead = read(inputFd, buf, BUF_SIZE)) > 0)
    {
        /*numRead will #include <sys/stat.h>
#include <fcntl.h>contains a len of 1024, so while the 
        loop is live, write in the output file, what brings
        numRead, only  if the text is the same to the length of 
        numRead 
        when it is not equal it will exti*/
        if (write(outputFd, buf, numRead) != numRead)
            fatal("couldn't write whole buffer");
    }

    if (numRead == -1)
        errExit("read");

    /*test if inputfd and outputfd are equal to -1 
    else close the files */
    if (close(inputFd) == -1)
        errExit("close input");

    if (close(outputFd) == -1)
        errExit("close output");

    /*Exit in a success state*/
    exit(EXIT_SUCCESS); 
}
