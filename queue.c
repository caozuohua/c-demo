// ==== ADT Queue 的表示和实现 ====
// ---- 单链队列 —— 队列的链式存储结构----
typedef struct QNode{
	QElemType data;
	struct QNode *next;
}QNode, *QueuePtr;

typedef struct{
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;

// ---- 基本操作的函数原型说明 ----
Status InitQueue(LinkQueue &Q) //构造一个空队列
Status DestroyQueue(LinkQueue &Q) //销毁队列Q
Status ClearQueue(LinkQueue &Q) //将Q清空
Status QueueEmpty(LinkQueue &Q) //判断Q是否为空
int QueueLength(LinkQueue &Q) //返回Q队列的长度
Status EnQueue(LinkQueue &Q, QElemType e) //插入元素e为队尾
Status DeQueue(LinkQueue &Q, QElemType &e) //如果队列不空，则删除Q的对头元素，用e返回其值，并返回OK；否则返回ERROR


// ---- 基本操作的算法描述（部分） ----
Status InitQueue(LinkQueue &Q){
	// 构造一个空队列Q
	Q.front = Q.rear = (QueuePtr)malloc(sizeof(QNode));
	if(!Q.font) exit(OVERFLOW); //存储分配失败
	Q.front->next = NULL;
	return OK;
}

Status DestroyQueue(LinkQueue &Q){
	// 销毁队列Q
	while(Q.front){
		Q.rear=Q.front->next;
		// 每次都把Q.front孤立出来，然后free掉
		free(Q.front);
		Q.front=Q.rear;
	}
	return OK;
}

Status EnQueue(LinkQueue &Q, QElemType e){
	// 元素e被插入到Q队列尾部
	p = (QueuePtr)malloc(sizeof(QNode));
	if(!p) exit(OVERFLOW);
	p->data = e; p->next=NULL;
	Q.rear->next = p;
	Q.rear = p;
	return OK;
}

Status DeQueue(LinkQueue &Q, QElemType &e){
	// 若队列不空，则删除队头元素，用e返回其值，并返回OK
	/* 一般地，删除队列头元素时，仅需要修改头结点中的指针，
	 * 但当队列中最后一个元素被删除后，队列尾指针也丢失了，
	 * 因此需要对队尾指针重新赋值(指向头节点)
	 */
	if(Q.front == Q.rear) return ERROR;
	p = Q.front-> next;
	e = p->data;
	Q.front->next = p->next;
	// Q.rear 等于Q.front的next，也就是说队列只剩下一个将要被删的元素了
	if(Q.rear==p) Q.rear=Q.front;
	free(p);
	return OK;
}


// ---- 循环队列——队列的顺序存储结构 ----
#define MAXQSIZE 100 //最大队列长度

typedef struct{
	QElemType *base; //初始化的动态分配存储空间
	int front; //头指针，若队列不空，指向队列头元素
	int rear; //尾指针，若队列不空，指向队列尾元素的下一个位置
}SqQueue;

// ---- 循环队列的基本操作的算法描述 ----
Status InitQueue(SqQueue &Q){
	// 构造一个空队列Q
	Q.base = (QElemType *)malloc(MAXQSIZE *sizeof(QElemType)); // 这里是Q.base, base是一个指向QElemType类型的指针
	if(!Q.base) exit(OVERFLOW); // 存储分配失败
	Q.front = Q.rear = 0;
	return OK;
}

int QueueLength(SqQueue Q){
	// 返回Q的元素个数，即队列的长度
	return (Q.rear - Q.front + MAXQSIZE) % MASQSIZE;
}

Status EnQueue(SqQueue &Q, QElemType e){
	// 插入元素e为Q的新的队尾元素
	if((Q.rear + 1) % MAXQSIZE == Q.front) return ERROR; //队列满
	Q.base[Q.rear] = e;
	Q.rear = (Q.rear +1) % MAXQSIZE;
	return OK;
}

Status DeQueue(SeQueue &Q, QElemType &e){
	// 若队列不空，则删除Q的对头元素，用e返回其值；并返回OK；
	if(Q.front == Q.rear) return ERROR;
	e = Q.base[Q.front];
	Q.front = (Q.front +1 ) % MAXQSIZE;
	return OK;
}
