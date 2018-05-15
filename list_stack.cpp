#include <stdio.h> 
#include <malloc.h> 
 
void push(int n); 
int pop(void); 
 
typedef struct node { 
	int n; 
	node *pNode; 
}NodeType; 
 
NodeType *pTop = NULL; 
 
int main(void) 
{ 
	push(10); 
	push(20); 
	push(30); 
	while (pTop!=NULL) // int isEmpty(void); 
	{ 
		printf("%d\n", pop()); 
	} 
} 
 
void push(int n) 
{ 
	NodeType * pTemp = (NodeType*)malloc(sizeof(NodeType)); 
	pTemp->n = n; 
 
	if (pTop == NULL) 
		pTemp->pNode = NULL; 
	else 
		pTemp->pNode = pTop; 
	pTop = pTemp; 
} 
 
int pop(void) 
{ 
	NodeType * pTemp = pTop; 
    int n = pTemp->n;
	pTop = pTop->pNode;
    free(pTemp); 
	return n; 
}
