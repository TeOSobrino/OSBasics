#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

//create a named pipe with the mkfifo command and use it for processes to 
//comunicate, it's seen as a file, but not written to disk, open it with
//open, not fopen