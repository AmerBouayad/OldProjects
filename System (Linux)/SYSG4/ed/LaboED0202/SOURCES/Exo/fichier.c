#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

int main (){
char hello[] = "Hello World";
char bye[] = "Bye world";
int fd = open("fichier.txt", O_CREAT | O_WRONLY | O_APPEND, 0644);

write(fd, hello, sizeof(hello));
lseek(fd, 10000, SEEK_SET);
write(fd, bye, sizeof(bye));

close(fd);
return 0;
}
