// ==== ATD STACK 的表示和实现 ====
// ---- 栈的顺序存储表示 ----

#define STACK_INIT_SIZE 100; // 存储空间初始分配量
#define STACKINCREMENT 10; // 存储空间分配增量

typedef struct {
	SElemType *base; // 在栈构造之前和销毁之后，base的值为NULL
	SElemType *top; // 栈顶指针
	int stacksize; // 当前已分配的存储空间，以元素为单位
}SqStack;

// ---- 基本操作的函数原型说明的算法描述 ----
Status InitStack(SqStack &S){
	S.base = (SElemType *) malloc(STACK_INIT_SIZE * sizeof(SElemType));
	if(!S.base) exit(OVERFLOW); // 存储分配失败
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
	return OK;
}

Status GetTop(SqStack S, SElemType &e){//FIXME: 为什么这里是 SqStack S不是SqStack &S ?
	// 若栈不空，则用e返回S的栈顶元素，并返回OK；否则返回ERROR
	if(S.top == S.base) return ERROR;
	e = *(S.top -1);
	return OK;
}

Status Push(Sqstack &S, SElemType e){
	if(S.top - S.base >= S.stacksize){// 栈满， 追加存储空间
		S.base = (SElemType *) realloc(S.base, (S.stacksize + STACKINCREMENT) * sizeof(SElemType));
		if(!S.base) exxit(OVERFLOW); // 存储分配失败
		S.top = S.base + S.stacksize;
		S.stacksize += STACKINCREMENT;
	}
	*S.top++ = e;
	return OK;
}

Status Pop(SqStack &S, SElemType &e){
	// 若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK；否则返回ERROR
	if(S.top == S.base) return ERROR;
	e = * --S.top;
	return OK;
}

// 数制转换
void conversion(){
	// 输入一个非负十进制整数，打印输出与其等值的八进制数
	InitStack(S); //构造空栈
	scanf("%d", N);
	while(N){
		Push(S, N % 8);
		N = N / 8;
	}
	while(!StackEmpty(S)){
		Pop(S,e);
		printf("%d", e);
	}
}
