/*
    Este ejemplo demuestra el uso de lseek () junto con read () y write (). 
    El primer argumento de la línea de comandos para este programa es el 
    nombre de un archivo que se abrirá. Los argumentos restantes especifican 
    las operaciones de I / O que se realizarán en el archivo. Cada una de estas 
    operaciones consta de una letra seguida de un valor asociado.
*/

#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>
#include "tlpi_hdr.h"

int main (int argc, char *argv[])
{
    size_t len;
    off_t offset;
    int fd, ap, j;
    char *buf;
    ssize_t numRead, numWritten;

    /*Test if the  arguments dont are incorrect */
    if (argc < 3 || strcmp(argv[1], "--help") == 0)
        usageError("%s file {r<length>|R<length>|w<string>|s<offset>}...\n",
        argv[0]);

    /*open a file give the necessary permissions and flags*/
    fd = open(argv[1], O_RDWR | O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP |
            S_IROTH | S_IWOTH); /*rw-rw-rw*/
    if (fd == -1)
        errExit("open");

    /*make a loop while an int being less than argc, the int will be start in 2*/
    for (ap = 2; ap < argc; app++)
    {
        /*switch case to see what comes in the argument with the position ap, and his index n 0 */
        switch (argv[ap][0]) 
        {
            case 'r': /* Display bytes at current offset, as text */
            case 'R': /* Display bytes at current offset, in hex */
                
                /*get the long of the bytes in the file passing as argument */
                len = getLong(&argv[ap][1], GN_ANY_BASE, argv[ap]);
                
                /*create memory for with the length obtained in len */
                buf = malloc(len);
                if (buf == NULL)
                    errExit("malloc");

                /*store a read file in this variable, will read our fd*/
                numRead = read(fd, buf, len);
                if (numRead == -1)
                    errExit("read");

                /*if it is in the end of the file*/
                if (numRead == 0)
                    printf("%s: end-of-file\n", argv[ap]);
                /*if still is not the end*/
                else
                {
                    /*print the file name*/
                    printf("%s: ", argv[ap]);

                    /*loop conting from 0 to the total of readed bytes*/
                    for (j = 0; j < numRead; j++)
                    {
                        /*if the  first byte in the ap argument of the argv array is r*/
                        if (argv[ap][0] == 'r')
                        {
                            /*print each character only if it is printeable  for that reasons use the 
                            isprint function , passing each byte in the buff using j as index
                            if it's printeable, print it if not print '?'*/

                            /*casting because buf is a char and  isprint can 
                            print unsigned char*/
                            printf("%c", isprint((unsigned char) buf[j]) ? buf[j] : '?');
                        }
                        else
                        {
                            /*If nor is r so is R, you have to print in ex the position in the buf with
                            j as index */

                            /*casting because buf is a char but you will want to print using index
                            so (unsigned int) */
                            printf("%02x ", (unsigned int) buf[j]);
                        }        
                    }
                    /*after that  jump lines*/
                    printf(\n);   
                }
                /*frees memory for buf*/
                free(buf);
                /*break case*/
                break;

                case 'w': /*Write string at current offset */
                
                /*write  in the fd, passing as buffer, what haves ap in the [ap][1] address
                 and as counter the length of the argv[ap][1]*/
                numWrite = writte(fd, &argv[ap][1], strlen(&argv[ap][1]));
                if (numWrite == -1)
                    errExit("write");

                /*print a the string in  the  argv[ap]
                
                
                    casting is because numWritten is a int and can end as a long */
                printf("%s: wrote  %ld bytes\n", argv[ap], (long) numWritten);
                break;

                case 's': /*change the file offset*/
                    /*get long of something*/
                    offset = getLong(&argv[ap][1], GN_ANY_BASE, argv[ap]);
                    
                    /*if lseek it-s no error  wiill change the file offset
                    to the offset variable value  from the beginning of the file*/
                    if (lseek(fd, offset, SEEK_SET) == -1)
                        exitErr("lseek");
                    printf("%s: seek succeeded\n", argv[ap]);
                    break;
            default:
            /*default case*/
            cmdLineErr("Argument must start with [rRws]: %s\n", argv[ap]);
            break;
        }
    }

    exit(EXIT_SUCCESS);
}

/*
    The following shell session log demonstrates the use of the program ,
showing what happens when we attempt to read bytes from a file hole:

$ touch tfile  //Create new, empty file

$ ./seek_io tfile s100000 wabc  // Seek to offset 100,000, write “abc”
    
    s100000: seek succeeded
    wabc: wrote 3 bytes

$ ls -l tfile  //Check size of file

    -rw-r--r-- 1 mtk users 100003 Feb 10 10:35 tfile

$ ./seek_io tfile s10000 R5  // Seek to offset 10,000, read 5 bytes from hole
    s10000: seek succeeded
    R5: 00 00 00 00 00 Bytes in the hole contain 0
*/
