#include <stdio.h>
#include <unistd.h>

int main(){
	// 模仿进度条
	for(int i=0;i<10;i++){
		sleep(1);
		printf("%c", 'x');
		// 刷新缓冲区
		fflush(stdout);
	}
	return 0;
}
