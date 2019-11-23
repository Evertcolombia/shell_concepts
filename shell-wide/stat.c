#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

/*esta function compara un argumento "filename
con una esructura del sistema que  contiene informacion
del archivo referido"*/
int main (int ac, char **av)
{
    unsigned int i;
    /*intance of the struct of in the file system for
    the file with information about the file*/
    struct stat st; 

    if (ac < 2)
    {
        printf("Usage: %s path_to_file ...\n", av[0]);
        return (1);
    }
    i = 1;

    while (av[i])
    {
        printf("%s:", av[i]);

        /*if (stat(av[i], &st) == 0)
          printf(" FOUND\n");
        else
           printf(" NOT FOUND\n");*/

        stat(av[i], &st) == 0 ? printf(" FOUND\n") : 
            printf(" NOT FOUND\n");

        i++; 
        
    }
    return (0);
}
