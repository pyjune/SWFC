#include <stdio.h> 
#include <malloc.h> 
 
void enq(int n); 
int deq(void); 
 
typedef struct node { 
	int n; 
	node *pNode; 
}NodeType; 
 
NodeType *pRear = NULL; 
NodeType *pFront = NULL; 
 
int main(void) 
{ 
	enq(10); 
	enq(20); 
	enq(30); 
	while (pFront != NULL) // int isEmpty(void); 
	{ 
	    printf("%d\n", deq()); 
	} 
} 
 
void enq(int n) 
{ 
	 NodeType * pTemp = (NodeType*)malloc(sizeof(NodeType)); 
	 pTemp->n = n; 
	 pTemp->pNode = NULL; 
	 if (pRear == NULL) 
		pFront = pTemp; 
	 else 
		pRear->pNode = pTemp; 
	 pRear = pTemp; 
} 
 
int deq(void) 
{ 
	NodeType * pTemp = pFront; 
	int n = pFront->n; 
	pFront = pFront->pNode;
    if(pFront==NULL)
         pRear=NULL; 
	free(pTemp); 
	return n; 
}
