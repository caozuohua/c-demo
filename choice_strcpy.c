#include <stdio.h>

static size_t choice_strcpy(char *dest, char *src, size_t size) {
        size_t n=0;

        while (*src && (n < size-2)) {
                if (*src == ',')
                        dest[n++] = '\\';
                dest[n++] = *src++;
        }
	// 这里给字符串加上表示结束的字符'\0'
        dest[n] = '\0';

        return n;
}

void main(){
        char *dest[100];
        char *src = "ab,c,defg";
        int res=choice_strcpy(dest, src, 100);
        printf("%d\n", res);
        printf("%s\n", dest);
}

