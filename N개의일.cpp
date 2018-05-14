#include <stdio.h>

void find(int n, int k, int s);
int a[10][10];
int minV;
int p[10];
int u[10];

int main(void)
{
	int T;
	freopen("Text.txt", "r", stdin);

	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++)
	{
		int N;
		minV = 0x7fffffff;

		scanf("%d", &N);
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				scanf("%d", &a[i][j]);
			}
		}
		find(0, N, 0);
		printf("#%d %d\n", tc, minV);
	}
}

void find(int n, int k, int s)
{
	if (n == k)
	{
		if (minV > s)
			minV = s;
	}
	else if (s >= minV)		// 백트래킹 적용
		return;
	else
	{
		for (int i = 0; i < k; i++)
		{
			if (u[i] == 0)
			{
				u[i] = 1;
				//p[n] = i;			// 전체 순열을 만들 필요가 없으면 생략
				find(n + 1, k, s + a[i][n]);
				u[i] = 0;
			}
		}
	}
}
