#include <stdio.h>
#define INF 0x7fffffff

typedef struct {
	int x;
	int y;
}PosType;

void perm(int n, int k, int m);
void perm2(int n, int k, int m, int s);

int used[12];
int p[12];
int dis[12][12];
int minV;
PosType pos[12];

int main(void)
{
	int T;
	//freopen("Text.txt", "r", stdin);
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++)
	{
		int N;
		minV = INF;
		scanf("%d", &N);
		scanf("%d %d", &pos[0].x, &pos[0].y);
		scanf("%d %d", &pos[N+1].x, &pos[N+1].y);
		for (int i = 1; i <= N; i++)
		{
			scanf("%d %d", &pos[i].x, &pos[i].y);
		}
		for (int i = 0; i <= N + 1; i++)
		{
			for (int j = 0; j <= N + 1; j++)
			{
				int disx = pos[i].x - pos[j].x;
				int disy = pos[i].y - pos[j].y;
				dis[i][j] = (disx >= 0 ? disx : -disx) + (disy >= 0 ? disy : -disy);
			}
		}
		p[0] = 0;
		used[0] = 1;
		//perm(1, N+1, N+1);
		perm2(1, N+1 , N+1, 0);
		printf("#%d %d\n", tc, minV);
	}

}


// m개에서 k개를 고르는 순열 생성

void perm2(int n, int k, int m, int s)
{
	if (n == k)
	{
		if (minV > s+dis[p[n-1]][k])
			minV = s + dis[p[k - 1]][k];
	}
	else if (s >= minV)
	{
		return;
	}
	else
	{
		for (int i = 1; i < m; i++)
		{
			if (used[i] == 0)
			{
				used[i] = 1;
				p[n] = i;
				perm2(n + 1, k, m, s + dis[p[n-1]][p[n]]);
				used[i] = 0;
			}
		}
	}
}

void perm(int n, int k, int m)
{
	if (n == k)
	{
		int total = 0;
		int i;
		for (i = 1; i < k; i++)
		{
			total += dis[p[i-1]][p[i]];
		}
		total += dis[p[i - 1]][k];
		if (minV > total)
			minV = total;
	}
	else
	{
		for (int i = 0; i < m; i++)
		{
			if (used[i] == 0)
			{
				used[i] = 1;
				p[n] = i;
				perm(n + 1, k, m);
				used[i] = 0;
			}
		}
	}
}
