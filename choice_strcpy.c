#include <stdio.h>

static size_t choice_strcpy(char *dest, char *src, size_t size) {
        size_t n=0;

        while (*src && (n < size-2)) {
		// 在','前面加'\'
                if (*src == ',')
                        dest[n++] = '\\';
		// 先dest[n++] 被赋值为*src, 然后再src++ ——指针后移
                dest[n++] = *src++;
        }
	// 这里给字符串加上表示结束的字符'\0'
        dest[n] = '\0';
	// printf("src: %sxx\n", src);
        return n;
}

size_t package_to_choice(char *package, char *buf, size_t size) {
        int n;
        n  = choice_strcpy(buf, package, size);
        n += choice_strcpy(buf+n, ": ", size-n);
        n += choice_strcpy(buf+n, package, size-n);
	printf("%s\n", buf);
        return n;
}

void main(){
        char *dest[100];
        char *src = "ab,c,defg";
        int res=choice_strcpy(dest, src, 100);
	char *buf[1024];
	int res2=package_to_choice("xyzopwiensdfl", buf, 1000);
        printf("%d\n", res2);
        printf("%s\n", dest);
}

