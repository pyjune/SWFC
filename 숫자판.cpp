/* 교재 part1의 마지막 연습문제 */
/* 입력 데이터
3
7 1 2 3 4 5 6 3
5
0 0 0 0 0
0 1 2 0 0
3 6 3 0 0
0 5 4 0 0 
0 0 0 0 0
7 1 2 3 4 5 6 3
5
0 0 0 0 0
0 1 2 0 0
0 6 3 0 0
0 5 4 0 0 
0 0 0 0 0
7 1 2 3 4 5 6 3
5
0 0 0 0 0
0 1 2 0 0
0 6 3 0 0
0 5 4 0 0 
0 0 3 2 1
*/


#include <stdio.h>

int  map[10][10];
int N; // 수열의 길이
int arr[10];
int M; // 숫자판의 가로 세로 크기
int used[10][10];

int find(int r, int c, int n, int k);

int main(void)
{
	freopen("Text.txt","r", stdin);

	int T;
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++)
	{
		scanf("%d", &N);
		for (int i = 0; i < N; i++)
			scanf("%d", &arr[i]);
		scanf("%d", &M);
		for (int i = 0; i < M; i++)
			for (int j = 0; j < M; j++)
				scanf("%d", &map[i][j]);
		// 첫번째 숫자 자리 찾기..
		int r = 0;
		for (int i = 0; i<M; i++)
		{
			for (int j = 0; j<M; j++)
			{
				if (map[i][j] == arr[0])
				{
					r = find(i, j, 1, N);
					if (r == 1)
						break;
				}
			}
			if (r == 1)
				break;
		}
		printf("#%d %d\n", tc,  r);
		for (int i = 0; i < M; i++)
			for (int j = 0; j < M; j++)
				used[i][j] = 0;
	}
}
int find(int r, int c, int n, int k)
{
	int dr[] = { 0, 1, 0, -1 };
	int dc[] = { 1, 0, -1, 0 };
	if (n == k)
	{
		return 1;
	}
	else
	{
		used[r][c] = 1;
		for (int i = 0; i<4; i++)
		{
			int nr = r + dr[i];
			int nc = c + dc[i];
			if (nr >= 0 && nr<M && nc >= 0 && nc<M)
			{
				if (map[nr][nc] == arr[n] && used[nr][nc] == 0)
					if (find(nr, nc, n + 1, k) == 1)
						return 1;
			}
		}
		used[r][c] = 0;
		return 0;
	}
}
