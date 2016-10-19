#include<iostream>

using namespace std;

typedef struct Node
{
	int _data;
	Node* _next;
	Node(int data,Node* next)
		:_data(data)
		,_next(next)
	{}
}Node,*pNode;

void show(pNode pHead)
{
	pNode cur = pHead;
	while(cur)
	{
		cout<<cur->_data<<"->";
		cur = cur->_next;
	}
	cout<<"NULL"<<endl;
}

/*
从尾到头打印
*/
void ResPrint(pNode pBegin)
{
	if(pBegin == NULL) //if(pBegin) 指针和NULL  0比较只能写清楚;  非0 向下执行； 0 else；／  pBegin==NULL true 向下；false else;
		return;
	else
	{
		ResPrint(pBegin->_next);
		cout<<pBegin->_data<<"->";
	}
}

void Test1()
{
	
	Node *h = new Node(1, NULL);
	Node *g = new Node(0, h);
	Node *f = new Node(9, g);
	Node *e = new Node(7, f);

	Node *d = new Node(5, e);
	Node *c = new Node(3, d);
	Node *b = new Node(2, c);
	Node *a = new Node(4, b);

	show(a);
	ResPrint(a);
}
/*
删除一个无头链表的非尾节点（偷梁换柱）
*/

void DelNopHead_NoneTail(pNode& pos)
{
	if(pos && pos->_next == NULL)
		return;

	pNode del = pos->_next;
	pos->_data = del->_data;
	pos->_next = del->_next;
	delete del;
	del->_next = NULL;
}

pNode Find(pNode pHead,int key)
{
	if(pHead==NULL)
		return NULL;
	pNode cur = pHead;
	while(cur->_data != key)
	{
		cur = cur->_next;
		show(cur);
	}
		show(cur);
	return cur;
}
void Test2()
{
	Node *h = new Node(1, NULL);
	Node *g = new Node(0, h);
	Node *f = new Node(9, g);
	Node *e = new Node(7, f);

	Node *d = new Node(5, e);
	Node *c = new Node(3, d);
	Node *b = new Node(2, c);
	Node *a = new Node(4, b);
	show(a);
	//DelNopHead_NoneTail(Find(a,2));
	//Node* tmp = Find(a,2);
	//cout<<tmp->_data<<endl;
	DelNopHead_NoneTail(b);
	show(a);
}

/*
 * 快排
 * 枢轴 左边比它小右边比它大 递归 
 */

pNode GetPartion(pNode pHead,pNode pEnd)
{
	pNode prev = pHead;
	pNode cur = pHead->_next;
	pNode key = pHead;
	
	while(cur != pEnd)
	{
		if(cur->_data < key->_data)
		{
			prev = prev->_next;
			swap(cur->_data,prev->_data);
		}
			cur = cur->_next;
	}
	swap(prev->_data,key->_data);//prev->_data = key->_data;
	return prev;
}
void QuickSort(pNode pHead,pNode pEnd)
{
	if( pHead == NULL )//1 0  递归跳出条件：只剩一个节点 pHead->next==PEnd  则还有两个节点
		return;
//	show(pHead);
	if(pHead != pEnd)
	{
		pNode Partion = GetPartion(pHead,pEnd);
		QuickSort(pHead,Partion);
		QuickSort(Partion->_next,pEnd);
	}
}

void TestQuickSort()
{
	Node *h = new Node(1, NULL);
	Node *g = new Node(0, h);
	Node *f = new Node(9, g);
	Node *e = new Node(7, f);

	Node *d = new Node(5, e);
	Node *c = new Node(3, d);
	Node *b = new Node(2, c);
	Node *a = new Node(4, b);

	show(a);
	QuickSort(a,NULL);
//	cout<<a->_data<<endl;
	show(a);	
}
//升序
void BubbleSort(pNode pHead)
{
	pNode end = NULL;
	if(pHead == NULL)
		return;
	
	pNode cur = NULL;
	pNode prev = NULL;
	while(pHead != end)
	{
		 prev = pHead;
		 cur = pHead->_next;
		while(cur != end)
		{
			if(cur->_data < prev->_data)
				swap(cur->_data , prev->_data);
			prev = cur;
			cur = cur->_next;
		}
		end = prev;
	}
	
}
void TestBub()
{
	pNode h = new Node(1, NULL);
	pNode g = new Node(0, h);
	pNode f = new Node(9, g);
	pNode e = new Node(7, f);

	pNode d = new Node(5, e);
	pNode c = new Node(3, d);
	pNode b = new Node(2, c);
	pNode a = new Node(4, b);

	show(a);
	BubbleSort(a);
	show(a);

}
/*
 *	在一个无头链表的非头节点前插入一个节点
 *	*/ 

void NoHead_NonepHead(pNode pos,int data)

{
	if(NULL == pos)
		return;
	pNode pnode = new Node(data,NULL);

	pNode prev = pos;
	pNode cur = pos->_next;
		
	prev->_next = pnode;
	pnode->_next = cur;

	swap(pnode->_data,pos->_data);	
	
}
void TestNoHead_NonepHead()
{
	pNode h = new Node(1, NULL);
	pNode g = new Node(0, h);
	pNode f = new Node(9, g);
	pNode e = new Node(7, f);

	pNode d = new Node(5, e);
	pNode c = new Node(3, d);
	pNode b = new Node(2, c);
	pNode a = new Node(4, b);
	
	pNode x = new Node(100,NULL);
	show(a);
	NoHead_NonepHead(b,100);
	show(a);
	
}
/*
 *	逆置链表
 *	*/
void _Reverse(pNode& pHead)
{
	if(pHead == NULL || pHead->_next == NULL)
		return;
	pNode SubHead = pHead->_next;
	pHead->_next = NULL;
	while(SubHead != NULL)
	{
		pNode ins = SubHead;
		SubHead = SubHead->_next; 
		ins->_next = pHead;
		pHead = ins;
	}
}

void Test_Res()
{
	pNode h = new Node(1, NULL);
	pNode g = new Node(0, h);
	pNode f = new Node(9, g);
	pNode e = new Node(7, f);

	pNode d = new Node(5, e);
	pNode c = new Node(3, d);
	pNode b = new Node(2, c);
	pNode a = new Node(4, b);
	
	show(a);
	_Reverse(a);
	show(a);	
}
/*	
*		合并两个有序链表，之后仍然有序
*		先找到头，newhead 单链表不会回退，头指针走过去就丢了
*		然后排序
*		最后把没有排的（一个已经排完，另一个还有很长一串），拼到newhead的后面
*/
pNode Merge(pNode pHead1,pNode pHead2)
{
	if(pHead1 == NULL || pHead2 == NULL )
		return pHead1 == NULL ? pHead2:pHead1;
	
	pNode cur = pHead1;
	if(pHead1->_data < pHead2->_data)
		pHead1 = pHead1->_next;
	else
	{
		cur = pHead2;
		pHead2 = pHead2->_next;	
	}
	pNode newHead = cur;

	while(pHead1 != NULL && pHead2 != NULL)//while(cur != NULL)
	{
		if(pHead1->_data < pHead2->_data)
		{
			cur->_next = pHead1;
			pHead1 = pHead1->_next;
		}		
		else
		{
			cur->_next = pHead2;
			pHead2 = pHead2->_next;	
		}
		cur = cur->_next;
	}
	if(pHead1 != NULL)
	{
		cur->_next = pHead1;
	}
	if(pHead2 != NULL)
	{
		cur->_next = pHead2;
	}
	return newHead;
}

void TestMerge()
{
	pNode h = new Node(7, NULL);
	pNode g = new Node(5, h);
	pNode f = new Node(3, g);
	pNode e = new Node(1, f);

	pNode d = new Node(8, NULL);
	pNode c = new Node(6, d);
	pNode b = new Node(2, c);
	pNode a = new Node(2, b);
	
	//show(a);
	pNode pBegin = Merge(a,e);
//	pNode pBegin = Merge(a,NULL);
//	pNode pBegin = Merge(NULL,e);
	show(pBegin);
	
}

/*
 *只遍历一边，找中间节点(快慢指针)
 *
 *有头指针  快慢指针指向头指针
 *快的比慢的快一倍时（快的走两步，慢的走一步），快的到了终点，慢的到了一半
 *还有到三分之一的......起点相同，快的走三步
 *
*/
pNode FindMid(pNode pHead)
{
	if(pHead == NULL ||  pHead->_next == NULL)
		return NULL;
	
	pNode fast = pHead;
	pNode slow = pHead;
	while(fast && fast->_next)//while(slow != fast)
	{
		slow = slow->_next;

		fast = fast->_next;
		fast = fast->_next;
	}
	return slow;
}
void TestFindMid()
{

	pNode h = new Node(1, NULL);
	pNode g = new Node(0, h);
	pNode f = new Node(9, g);
	pNode e = new Node(7, f);

	pNode d = new Node(5, e);
	pNode c = new Node(3, d);
	pNode b = new Node(2, c);
	pNode a = new Node(4, b);
	
	show(a);
	pNode mid = FindMid(a);
	cout<<mid->_data<<endl;
}

/*
 *	查找单链表的倒数第K个节点，只能遍历一次
 *	*/

pNode Findlast_K(pNode pHead,int k)
{
	if(pHead == NULL || k == 0)
		return NULL;
	
	pNode fast = pHead;
	pNode slow = pHead;
	int num = k;
	while(--num)
	{
	//	slow = slow->_next;	
		if(fast->_next)
		{
			fast = fast->_next;
		}
		else
			exit(2);
	}
	while(fast->_next)
	{
		fast = fast->_next;
		slow = slow->_next;
	}
	return slow;
	
}
void TestFindlast_K()
{
	pNode h = new Node(1, NULL);
	pNode g = new Node(0, h);
	pNode f = new Node(9, g);
	pNode e = new Node(7, f);

	pNode d = new Node(5, e);
	pNode c = new Node(3, d);
	pNode b = new Node(2, c);
	pNode a = new Node(4, b);
	
	show(a);
	pNode pk = Findlast_K(a,1);
	cout<<"倒数第1:"<<pk->_data<<endl;
	pNode pk1 = Findlast_K(a,8);
	cout<<"倒数第8:"<<pk1->_data<<endl;
	pNode pk2 = Findlast_K(a,5);
	cout<<"倒数第5:"<<pk2->_data<<endl;
}


/*
 *	判断链表是否带环，若带环求长度，求环的入口，  并求每个方法的时/空复杂度
 *	*/

/*
 *	判断带环（快慢指针），时：O(n)	空：O(1)
 *	*/
void 
int main()
{
//	Test1();
//	Test2();
//	TestQuickSort();	
//	TestBub();
//    TestNoHead_NonepHead();
//	Test_Res();
//	TestMerge();
//	TestFindMid();
	TestFindlast_K();
	return 0;
}
