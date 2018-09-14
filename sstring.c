// ---- 串的定长顺序存储表示 ----
#define MAXSTRLEN 255 
typedef unsigned char SString[MAXSTRLEN +1]; // 0号单元存放串的长度


// ---- 求子串 ----
Status SubString(SString &Sub, SString S, int pos, int len){
	// Sub返回S的第pos个长度为len的子串
	// 其中,1<=pos<=StrLength(S) 且0<=len<=StrLength(S) - pos +1
	if(pos< 1||pos > S[0]||len<0||len>S[0]-pos+1)
		return ERROR;
	Sub[1..len] = S[pos ...pos+len-1];
	Sub[0] = len;
	return OK;
}

// ---- 串的堆分配存储表示 ----
typedef struct{
	char *ch; // 若是非空串，则按串长分配存储区，否则ch为NULL
	int length; // 串长
}HString;

Status StrInsert(HString &S, int pos, HString T){
	// 插入字符串：先realloc追加存储空间，然后原有的元素后挪，然后把T复制到S的pos位置
	if(pos<1 || pos>S.length=1) return ERROR;// pos不合法
	if(T.length){
		if(!(S.ch=(char *)realloc(S.ch, (S.length + T.length) * sizeof(char)))) exit(OVERFLOW);
		for(i=S.length-1; i>=pos-1;--i)// 为插入T腾出位置
			S.ch[i+T.length]=S.ch[i]; //就是把S.ch[S.length-1] 到S.ch[pos-1]的元素往后挪 ...
		S.ch[pos-1..pos+T.length-2] = T.ch[o..T.length-1]; // 插入T
		S.length += T.length;
	}
	return OK;
}

// ==== ADT String 的表示与实现 ====
// ---- 串的堆分配存储表示 ----
typedef struct{
	char *ch; //若是非空串，则按串长分配存储区，否则ch为NULL
	int length; //串长度
}HString;

// ----基本操作的函数原型说明 ----
status StrAssign(HString &T, char *chars); // 生成一个其值等于串常量chars的串T
int StrLength(HString S); // 返回S的元素个数，称为串的长度
int StrCompare(HString S, HString T); // 比较大小
Status ClearString(HString &S); // 将S清空
Status Concat(HString &T, HString S1, HString S2); // 用T返回S1和S2连接而成的新串
HString SubString(HSstring S, int pos, int len); // 返回一个pos位置开始的长为len的子串

// ---- 基本操作的算法描述 ----
Status StrAssign(HString &T, char * chars){
	if(T.ch) free(T.ch);
	for(i=0, c=chars; c; ++i, ++c); //求chars的长度i
	if(!i){
		T.ch = NULL; T.length=0;
	}else{
		if(!(T.ch=(char *)malloc(i*sizeof(char)))) exit(OVERFLOW);
		T.ch[0..i-1] = chars[0..i-1];
		T.length=i;
	}
	return OK;
}

int StrLength(HString S){
	// 返回S的元素个数，称为串的长度
	return S.length
}

int StrCompare(HString S, HString T){
	// 比较字符串大小
	for(i=0;i<S.length && i<T.length; ++i){
		// 当发现有不同的字符时，返回比较大小的结果
		if(S.ch[i]!=T.ch[i]) return S.ch[i]-T.ch[i];
	// 如果是子串关系，则直接通过两个串的长度来比较大小
	return S.length-T.length;
}

Status ClearString(HString &S){
	// 将S清空
	if(S.ch) {
		free(S.ch);
		S.ch=NULL;
	}
	S.length = 0;
	return OK;
}

Status Concat(HString &T, HString S1, HString S2){
	// 返回T=S1+S2
	if(T.ch) free(T.ch); //释放T的旧的空间
	if(!(T.ch = (char *)malloc((S1.length + S2.length)*sizeof(char)))){ // 先分配空间
		exit(OVERFLOW);
	}
	T.ch[0..S1.length-1] = S1.ch[0..S1.length-1]; // 先将S1复制到T的前面
	T.length = S1.length + S2.length; // 更新T的长度
	T.ch[S.length..T.length-1] = S2.ch[0..S2.length-1]; //再将S2复制到T的后部分
	return OK;
}

Status SubString(HString &Sub, HString S, int pos, int len){
	// 用sub返回串S的第pos个字符起长度为len的子串—— 就是获取其中的子串
	if(pos<1 || pos>S.length||len<0 ||len>S.length-pos+1){
		return ERROR;
	}
	if(Sub.ch) free(Sub.ch);
	if(!len){
		Sub.ch = NULL;
		Sub.length = 0;
	}else{
		Sub.ch=(char *)malloc(len * sizeof(char));
		Sub.ch[0..len-1] = S.ch[pos-1..pos+len-2];
		Sub.length = len;
	}
	return OK;
}

// ==== 串的块链存储表示 ====
#define CHUNKSIZE 80
typedef struct Chunk{
	char ch[CHUNKSIZE];
	struct Chunk *next;
}Chunk;

typedef struct {
	Chunk *head, *tail;
	int curlen;
}LString;


int Index(SString S, SString T, int pos){
	// 返回子串T在主串S中第pos个字符之后的位置
	i=pos; j=1;
	while(i<=S[0] && j<=T[0]){
		if(S[i] == T[j]){
			++i;
			++j;
		}else{
			// TODO：why?
			// 从匹配失败的位置开始下一次的匹配(从T的头开始)
			i = i - j + 2;
			j = 1;
		}
	}
	if j > T[0] return i - T[0];
	else return 0;
}

	
