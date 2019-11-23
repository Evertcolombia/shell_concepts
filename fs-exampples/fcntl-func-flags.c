/*
Un uso de fcntl () es recuperar o modificar el modo de acceso y 
abrir indicadores de estado de archivo de un archivo abierto. 
(Estos son los valores establecidos por el argumento flags 
especificado en la llamada para abrir ().) Para recuperar 
esta configuración, especificamos cmd como F_GETFL:

*/

int flags, accessMode;

/*usamos fcntl () para recuperar una copia de 
los indicadores existentes*/
flags = fcntl(fd, F_GETFL);
if (flags == -1)
    errExit("fcntl");

/*test para saber si el archivo se abrio para futuras
escrituras sincronizadas*/

if (flags & O_SYNC)
    printf("writes are synchronized\n");

/*
Verificar el modo de acceso del archivo es un poco más 
complejo, ya que las constantes O_RDONLY (0), O_WRONLY 
(1) y O_RDWR (2) no corresponden a bits individuales 
en los indicadores de estado del archivo abierto. Por 
lo tanto, para hacer esta verificación, enmascaramos 
el valor de las banderas con la constante O_ACCMODE, 
y luego probamos la igualdad con una de las constantes:
*/

accessMode = flags & O_ACCMODE;
if (accessMode == O_WRONLY || accessMode == O_RDWR)
    printf("file is writable\n");

/*
luego modificamos los bits que deseamos cambiar 
y finalmente hacemos una nueva llamada a fcntl () 
para actualizar los indicadores. Por lo tanto, 
para habilitar el indicador O_APPEND, escribiríamos 
lo siguiente
*/
int flags;

flags = fcntl(fd, F_GETFL);
if (flags == -1)
 errExit("fcntl");

flags |= O_APPEND; /*habilitar el indicador O_APPEND*/
if (fcntl(fd, F_SETFL, flags) == -1)
    errExit("fcntl");