#include <stdio.h>
#include <string.h>

int main() {
    char buf[256];
    int count;
    char *words[10];
    int i;
    int len;

    fgets(buf,sizeof(buf)-1,stdin);
    len = strlen(buf);
    buf[len - 1]='\0'; //cut out the final newline
    
    count = 0;
    words[0] = buf;
    for(i = 0; i < len; i++) {
        if(buf[i] == ' ') {
            buf[i] = '\0';
            if(i > 0 && buf[i-1] != 0) { //skip over double spaces
                count++;
            }
            words[count] = &buf[i+1];
        }
    }

    for (i = 0; i < count+1; i++) {
        printf("%s\n",words[i]);
    }

    return 0;
}
