typedef struct LNode{//节点类型
	ElemType elem;
	struct LNode *next;
}*Link, *Position;

typedef struct{//链表类型
	Link head, tail;//分别指向链表的头结点和最后一个节点
	int len;//指示线性链表中数据元素的个数
}LinkList;

Status ListInsert_L(Linklist &L, int i, ElemType e){
	// 在带头结点的单链线性表L的第i个元素之前插入元素e
	if (!LocatePos(L, i-1, h)) return false; //i值不合法
	if (!MakeNode(s, e)) return false;	//节点存储分配失败
	InsFirst(h, s);
	return true;
}

Status MergeList_L(LinkList &La, LinkList &Lb, LinkList &Lc, int (* compare)(ElemType, ElemType)){
	// 已知单链线性链表La 和Lb的元素按值非递减排列。
	// 归并La 和Lb得到新的单链线性表Lc，Lc的元素也按值非递减排列。
	if(!InitList(Lc)) return false;	//存储空间分配失败
	ha = GetHead(La); hb = getHead(Lb); //ha hb 分别指向La和Lb的头结点
	pa = NextPos(La, ha); pb = NextPos(Lb, hb); //pa 和pb分别指向La和Lb中当前节点
	while(pa && pb){
		a = GetCurElem(pa); b = GetCurEelm(pb); //a和b为两表中当前比较元素
		if((* compare)(a, b) <= 0){
			DelFirst(ha, q); Append(Lc, q); pa = NextPos(La, ha);
		}else{
			DelFirst(hb, q); Append(Lc, q); pb = NextPos(Lb, hb);
		}

	}
	if(pa){// 链接剩下的节点链
		Append(Lc, pa);
	}else{
		Append(Lc, pb);
	}
	FreeNode(ha);// 释放ha hb的头结点
	FreeNode(hb);
	return true;
}
