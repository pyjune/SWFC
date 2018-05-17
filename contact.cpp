/* 1238 Contact */

#include <stdio.h>

int adj[101][101];
int v[101];
int cnt[101];
int q[2000];
int front;
int rear;
void bfs(int n, int m);

int main(void)
{
	int T = 10;
	//freopen("Text.txt", "r", stdin);
	for (int tc = 1; tc <= T; tc++)
	{
		int N, S;
		int last = 0;
		scanf("%d %d", &N, &S);
		for (int i = 0; i < N/2; i++)
		{
			int n1, n2;
			scanf("%d %d", &n1, &n2);
			adj[n1][n2] = 1;
			if (last < n2)
				last = n2;
		}
		bfs(S, last);
		int maxIdx = S;
		for (int i = 1; i <= last; i++)
			if (v[maxIdx] <= v[i]) // v가 가장 큰 것 중 가장 오른쪽
				maxIdx = i;
		printf("#%d %d\n", tc, maxIdx);
		for (int i = 1; i <= 100; i++)
		{
			v[i] = 0;
			for (int j = 1; j<= 100; j++)
			{
				adj[i][j] = 0;
			}
		}
	}
}

void bfs(int n, int m)
{
	front = -1;
	rear = -1;
	q[++rear] = n;
	v[n] = 1;
	while (front != rear)
	{
		n = q[++front];
		for (int i = 1; i <= m; i++)
		{
			if (adj[n][i] != 0 && v[i] == 0)
			{
				q[++rear] = i;
				v[i] = v[n] + 1; // 연락순서 기록
			}
		}
	}
}
