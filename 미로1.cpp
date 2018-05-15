#include <stdio.h>


int map[16][16];
const int N = 16;

int dfs(int r, int c); // 

typedef struct{
	int r;
	int c;
}PosType;

PosType stack[10000];
int top;

void push(int r, int c);
PosType pop(void);

int main(void)
{
	int tc, T = 10;
	int sc, sr;
	//freopen("Text.txt", "r", stdin);
	//scanf("%d", &T);
	for (tc = 1; tc <= T; tc++)
	{
		scanf("%d", &tc);
		top = -1;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				scanf("%1d", &map[i][j]);
				if (map[i][j] == 2)
				{
					sr = i;
					sc = j;
				}
			}
		}

		printf("#%d %d\n", tc, dfs(sr, sc));
		
	}
}
int dfs(int r, int c)
{
	int dr[] = { 0, 1, 0, -1 };
	int dc[] = { 1, 0, -1, 0 };
	push(r, c);
	while (top != -1)
	{
		PosType t = pop(); // 벽이 아닌 곳 중 하나를 꺼내 
		if (map[t.r][t.c] == 3) // 도착지면 1 반환
			return 1;
		map[t.r][t.c] = 1; // 지나간 곳은 벽으로 바꿈
		for (int i = 0; i < 4; i++)
		{
			r = t.r + dr[i];
			c = t.c + dc[i];
			if (map[r][c] !=1) // 벽이 아닌 곳 저장
			{
				push(r, c);
			}
		}
	}
	return 0;
}

void push(int r, int c)
{
	top++;
	stack[top].r = r;
	stack[top].c = c;
}

PosType pop(void)
{
	return stack[top--];
}
