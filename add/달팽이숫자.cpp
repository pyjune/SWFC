/* 1954 달팽이 숫자 */

#include <stdio.h>

void find(int n);
int a[10][10];
int main(void)
{
	int T;
	//freopen("Text.txt", "r", stdin);
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++)
	{
		int N;
		scanf("%d", &N);
		find(N);
		printf("#%d\n", tc);
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				printf("%d ", a[i][j]);
			}
			printf("\n");
		}
	}
}

void find(int n)
{
	int k = 1;
	int r = 0, c = 0;
	int d = 0;
	for (d = 0; d < n/2; d++)
	{
		for (c=c+d; c < n - d-1; c++)  // 위 가로
			a[r][c] = k++;
		for (r; r < n - d-1; r++)     // 오른쪽 세로
			a[r][c] = k++;
		for (c; c > d; c--)           // 아래 가로
			a[r][c] = k++;
		for (r; r > d; r--)           // 왼쪽 세로
			a[r][c] = k++;
		r++;
	}
	if (n% 2==1)                  // N이 홀수인 경우 중심 
		a[d][d] = k;
}
