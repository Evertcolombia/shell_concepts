#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
/*
    Hay una forma  para que un proceso se 
    asegure que es el creador de un archivo

    la verificacion de la existencia previa del archivo
    y la creacion de archivo se realizan de manera atomica

    En este código, mostramos el ID del proceso devuelto por 
    la llamada al sistema getpid (), que nos permite distinguir 
    la salida de dos ejecuciones diferentes de este programa
*/
int main (void) 
{
    int fd; 
    fd = open(argv[1], O_WRONLY); /*Open 1: check if file exists*/
        if (fd != -1)             /*Open succeeded*/
        {
            printf("[PID %ld] file \"%s\" already exists \n",
                (long) getpid(), argv[1]); // print id proccess and phrase
            close(fd);
        }
        else
        {
            if (errno != ENOENT)  /* Failed for unexpected reason */
                errExit("open");
            else 
            {
                /*WINDOW FOR FAILURE
                
                    creat the file if this dont exists
                */
                prinf(""[PID %ld] File \"%s\" doesn't exist yet\n", (long) getpid(), argv[1]);
                if (argc > 2)       /*delay between check and create */
                {
                    printf()
                    sleep(5);       /*susp      end execution for 5 seconds*/
                    printf("[PID %ld] Done sleeping\n", (long) getpid());
                }
                
                fd = open(argv[1], O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
                if (fd == -1)
                    errExit("open");
                /*print proccess id and message for succed file created*/
                printf("[PID %ld] created file \"%s\" exclusively\n",
                    (long getpid(), argv[1]));
            }
        }
}
    /*
        Ambos procesos afirman haber creado el archivo porque el código del primer proceso fue 
        interrumpido entre la verificación de existencia y la creación del archivo. El uso de 
        una sola llamada open () que especifica los indicadores O_CREAT y O_EXCL evita esta posibilidad 
        al garantizar que los pasos de verificación y creación se realicen como una sola operación atómica 
        (es decir, ininterrumpible).
    */