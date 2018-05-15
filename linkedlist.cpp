#include <stdio.h>
#include <malloc.h>

int a[] = { 2, 3, 7, 5, 1, 6, 4, 10, 9, 8 };
int b[] = { 1, 3, 7, 9 };

typedef struct Node{
	int n;
	Node * link;
}NodeType;

NodeType * pHead = NULL;

void insertN(int m);
void delN(int m);
void printN(void);

int main(void)
{
	for (int i = 0; i < (sizeof(a) / sizeof(a[0])); i++)
	{
		insertN(a[i]);
	}
	printN();
	for (int i = 0; i < (sizeof(b) / sizeof(b[0])); i++)
	{
		delN(b[i]);
	}
	printN();
}

void insertN(int m)
{
	NodeType *p = pHead;
	NodeType *pTemp = (NodeType*)malloc(sizeof(NodeType));
	pTemp->n = m;
	pTemp->link = NULL;
	if (p == NULL) // 노드가 없는 경우
	{
		pHead = pTemp;
		return;
	}
	if (p->n > m) // 맨 앞노드인 경우
	{
		pTemp->link = p;
		pHead = pTemp;
		return;
	}
	while (p->link != NULL && p->n<m) // p가 가리키는 노드보다 값이 큰 경우
	{
		if (p->link->n > m) // 중간에 들어가는 경우
		{
			pTemp->link = p->link;
			p->link = pTemp;
			return;
		}
		p = p->link;
	}
	p->link = pTemp;
	
}

void printN(void)
{
	NodeType *p = pHead;
	while (p != NULL)
	{
		printf("%d ", p->n);
		p = p->link;
	}
	printf("\n");
}

void delN(int m)
{
	NodeType * p = pHead;
	NodeType *pre=NULL;
	if (p->n == m)
		pHead = p->link;
	else
	{
		while (p->n != m)
		{
			pre = p;
			p = p->link;
		}
		pre->link = p->link;
	}
	free(p);
}
