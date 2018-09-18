#include <stdio.h>

struct INFO{
	int a;
	char b;
	double c;
};

int main(char argc, char *argv){
	int *p;
	char *p1;
	float *p2;
	double *p3;
	struct INFO *p4;
	void *p5;
	printf("int %d \n", sizeof(p));
	printf("char %d \n", sizeof(p1));
	printf("float %d \n", sizeof(p2));
	printf("double %d\n", sizeof(p3));
	printf("struct %d\n", sizeof(p4));
	// %lu 表示long unsigned int 无符号长整型
	printf("void %lu \n", sizeof(p5));
	return 0;
}
