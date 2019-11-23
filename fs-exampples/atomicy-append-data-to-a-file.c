/*
Un segundo ejemplo de la necesidad de atomicidad es 
cuando tenemos múltiples procesos que agregan datos 
al mismo archivo (por ejemplo, un archivo de registro 
global). Para este propósito, podríamos considerar el 
uso de un código como el siguiente en cada uno de 
nuestros escritores:
*/

/*set offset at the end of the file*/
if (lseek(fd, 0, SEEK_END) == -1)
 errExit("lseek");
/*write from the offset */
if (write(fd, buf, len) != len)
 fatal("Partial/failed write");