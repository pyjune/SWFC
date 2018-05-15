/* 혁진이의 프로그램 
<	이동 방향을 왼쪽으로 바꾼다.
>	이동 방향을 오른쪽으로 바꾼다.
^	이동 방향을 위쪽으로 바꾼다.
v	이동 방향을 아래쪽으로 바꾼다.
_	메모리에 0이 저장되어 있으면 이동 방향을 오른쪽으로 바꾸고, 아니면 왼쪽으로 바꾼다.
|	메모리에 0이 저장되어 있으면 이동 방향을 아래쪽으로 바꾸고, 아니면 위쪽으로 바꾼다.
?	이동 방향을 상하좌우 중 하나로 무작위로 바꾼다. 방향이 바뀔 확률은 네 방향 동일하다.
.	아무 것도 하지 않는다.
@	프로그램의 실행을 정지한다.
0~9	메모리에 문자가 나타내는 값을 저장한다.
+	메모리에 저장된 값에 1을 더한다. 만약 더하기 전 값이 15이라면 0으로 바꾼다.
-	메모리에 저장된 값에 1을 뺀다. 만약 빼기 전 값이 0이라면 15로 바꾼다.
*/


#include <stdio.h>

typedef struct{
    int i;
    int j;
    int v;
    int d;
}StackType;
typedef struct{
    int vd[16][4];
}VDType;

char map[20][21];

int find(int r, int c);
char rstr[][4] = { "NO", "YES" };
StackType s[1000000];
int top;

int main(void)
{
    int T;
   // freopen("input.txt", "r", stdin);
    scanf("%d", &T);

    for (int tc = 1; tc <= T; tc++)
    {
        int R, C;
        top = -1;
        scanf("%d %d", &R, &C);
        for (int i = 0; i < R; i++)
        {
            scanf("%s", map[i]);
        }
        int r = find(R, C);
        printf("#%d %s\n", tc, rstr[r]);
    }
}

int find(int r, int c)
{
    int di[] = { 0, 1, 0, -1 };
    int dj[] = { 1, 0, -1, 0 };
 
    int i = 0;
    int j = 0;
    int dir = 0;
    int mem = 0;
 
    VDType vd[20][20] = { 0 };

    while (map[i][j] != '@')
    {
        if ((map[i][j] >= '0') && (map[i][j] <= '9'))
            mem = map[i][j] - '0';
        else if (map[i][j] == '>')
            dir = 0;
        else if (map[i][j] == 'v')
            dir = 1;
        else if (map[i][j] == '<')
            dir = 2;
        else if (map[i][j] == '^')
            dir = 3;
        else if (map[i][j] == '_')
            if (mem == 0)
                dir = 0;
            else
                dir = 2;
        else if (map[i][j] == '|')
            if (mem == 0)
                dir = 1;
            else
                dir = 3;
        else if (map[i][j] == '?')
        {
            if (vd[i][j].vd[mem][dir] == 0)
            {
                for (int l = 0; l < 4; l++)
                {
                    if (l != dir)
                    {
                        top++;
                        s[top].i = i;
                        s[top].j = j;
                        s[top].d = l;
                        s[top].v = mem;
                    }
                }
            }

        }
        else if (map[i][j] == '.')
            dir = dir;
        else if (map[i][j] == '+')
            mem = ((mem + 1) % 16);
        else if (map[i][j] == '-')
            mem = ((mem == 0) ? 15 : mem - 1);

        if (vd[i][j].vd[mem][dir]==1)
        {
            StackType t;
            if (top == -1)
                return 0;
            else
                t = s[top--];
            i = t.i;
            j = t.j;
            dir = t.d;
            mem = t.v;                
        }
        else
        {
            vd[i][j].vd[mem][dir] = 1;
            
            i = (i + di[dir])%r;
            j = (j + dj[dir])%c;
            i = ((i == -1) ? r - 1 : i);
            j = ((j == -1) ? c - 1 : j);
        }
    }
    return  1;
}
