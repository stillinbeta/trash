#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>


int main() {
    char buf[256];
    int count;
    char *words[10];
    int i;
    int len;
    int n;

    fgets(buf,sizeof(buf)-1,stdin);
    buf[sizeof(buf) -1] = '\0';
    len = strlen(buf);
    buf[len - 1]='\0'; //cut out the final newline
    
    count = 0;
    words[0] = buf;
    for(i = 0; i < len && count < sizeof(words)-2; i++) {
        if(buf[i] == ' ') {
            buf[i] = '\0';
            if(i > 0 && buf[i-1] != 0) { //skip over double spaces
                count++;
            }
            words[count] = &buf[i+1];
        }
    }
    words[count+1] = NULL; //NULL terminate for execvp
    
    n = fork();
    if (n == 0) { //child
        errno = 0;
        execvp(words[0],words);
        perror("");
    }
    else {
        wait(NULL);
        printf("parent");
    }

    return 0;
}
