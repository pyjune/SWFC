#include <stdio.h>
#include <malloc.h>

typedef struct node{
    int data;
    node * link;
}NodeType;

NodeType * pHead = NULL;
NodeType * pEnd = NULL;

void addNode(int y);
void insertNode(int x, int y);
void deleteNode(int x, int y);

int main(void)
{
    //freopen("input.txt", "r", stdin);
    for (int tc = 1; tc <= 10;tc++)
    {
        pHead = NULL;
        pEnd = NULL;
        int N;
        scanf("%d", &N); // 기본 데이터 개수
        addNode(N);
        scanf("%d", &N); // 편집 명령 개수
        for (int i = 0; i < N; i++)
        {
            char cmd;
            int x, y, s;
            scanf(" %c", &cmd);
            if (cmd == 'I')
            {
                scanf("%d %d", &x, &y);
                insertNode(x, y);
            }
            else if (cmd == 'D')
            {
                scanf("%d %d", &x, &y);
                deleteNode(x, y);
            }
            else if (cmd == 'A')
            {
                scanf("%d", &y);
                addNode(y);
            }
        }
        printf("#%d", tc);
        for (int i = 0; i < 10; i++)
        {
            printf(" %d", pHead->data);
            pHead = pHead->link;
        }
        printf("\n");
        
    }
}

void addNode(int y)
{
    for (int i = 0; i < y; i++)
    {
        int data;
        scanf("%d", &data);
        NodeType *pTemp = (NodeType *)malloc(sizeof(NodeType));
        pTemp->data = data;
        pTemp->link = NULL;
        if (pEnd == NULL)
        {
            pHead = pTemp;
        }
        else
        {
            pEnd->link = pTemp;
        }
        pEnd = pTemp;

    }
}
void insertNode(int x, int y)
{
    int cnt = 0;
    NodeType *pCur=pHead;
    if (x > 0)
    {
        while (cnt < x - 1)
        {
            pCur = pCur->link;
            cnt++;
        }
    }
    else
        pCur = NULL;
    for (int i = 0; i < y; i++)
    {
        NodeType *pTemp = (NodeType *)malloc(sizeof(NodeType));
        scanf("%d", &pTemp->data);

        if (pCur == NULL)
        {
            pTemp->link = pHead;
            pHead = pTemp;
            pCur = pHead;
        }
        else
        {
            pTemp->link = pCur->link;
            pCur->link = pTemp;
            pCur = pTemp;
        }

    }
}
void deleteNode(int x, int y)
{
    int cnt = 0;
    NodeType *pCur = pHead; // x번 노드 주소
    while (cnt < x-1)
    {
        pCur = pCur->link;
        cnt++;
    }
    NodeType *pTemp = pCur->link; // 지울 노드 주소

    for (int i = 0; i < y; i++)
    {
            pCur->link = pTemp->link; // 지울 노드 다음 노드
            free(pTemp);
            pTemp = pCur->link;

    }
}
