/* 경로확인, 경로의 개수, 최단 거리 */

#include <stdio.h>


int map[100][100];
int N;

int dfs1(int r, int c); // 도착 가능여부
void dfs2(int r, int c); // 가능한 경로 수
int cntRoute;

int bfs(int r, int c); // 최단 거리
int visited[100][100]; // 거리 기록용
int min;
typedef struct{
	int r;
	int c;
}PosType;
PosType Q[10000];
int front;
int rear;
void enQ(int r, int c);
PosType deQ(void);

int main(void)
{
	int tc, T;
	int sc, sr;
	freopen("Text.txt", "r", stdin);
	scanf("%d", &T);
	for (tc = 1; tc <= T; tc++)
	{
		cntRoute = 0;
		scanf("%d", &N);
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				visited[i][j] = 0;
				scanf("%1d", &map[i][j]);
				if (map[i][j] == 2)
				{
					sr = i;
					sc = j;
				}
			}
		}

		//printf("#%d %d\n", tc, dfs1(sr, sc));
		//dfs2(sr, sc); // 경로의 수
		//printf("#%d %d\n", tc, cntRoute);

		printf("#%d %d\n", tc, bfs(sr, sc));
	}
}

int dfs1(int r, int c)
{
	int dr[] = { 0, 1, 0, -1 };
	int dc[] = { 1, 0, -1, 0 };
	if (map[r][c] == 3)
	{
		return 1;
	}
	else
	{
		map[r][c] = 1;
		for (int i = 0; i < 4; i++)
		{
			int nr = r + dr[i];
			int nc = c + dc[i];
			if (map[nr][nc] != 1)
			{
				if (dfs1(nr, nc) == 1)
					return 1;
			}
		}
		return 0;
	}
}

void dfs2(int r, int c)
{
	int dr[] = { 0, 1, 0, -1 };
	int dc[] = { 1, 0, -1, 0 };
	if (map[r][c] == 3)
	{
		cntRoute++;
	}
	else
	{
		map[r][c] = 1;
		for (int i = 0; i < 4; i++)
		{
			int nr = r + dr[i];
			int nc = c + dc[i];
			if (map[nr][nc] != 1)
			{
				dfs2(nr, nc);
			}
		}
		map[r][c] = 0;

	}
}

int bfs(int r, int c)
{
	int dr[] = { 0, 1, 0, -1 };
	int dc[] = { 1, 0, -1, 0 };
	front = -1;
	rear = -1;
	
	enQ(r, c);
	visited[r][c] = 1;
	
	while (front != rear)
	{
		PosType t = deQ();
		for (int i = 0; i < 4; i++)
		{
			int nr = t.r + dr[i];
			int nc = t.c + dc[i];
			if (map[nr][nc] != 1 && visited[nr][nc] == 0)
			{
				if (map[nr][nc] == 3)
					return visited[t.r][t.c]-1;

				enQ(nr, nc);
				visited[nr][nc] = 1 + visited[t.r][t.c];
			}
		}
	}
	return 0;
}

void enQ(int r, int c)
{
	rear++;
	Q[rear].r = r;
	Q[rear].c = c;
}
PosType deQ(void)
{
	return Q[++front];
}
