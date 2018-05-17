/* 1697 숨바꼭질 from acmicpc.net */
#include <stdio.h>

void bfs(int n, int k);

int Q[100001];
int V[100001];
int rear = -1;
int front = -1;

int main(void)
{
	int N;
	int K;
	//freopen("Text.txt", "r", stdin);
	scanf("%d %d", &N, &K);
	bfs(N, K);
	printf("%d\n", V[K] - 1);

}

void bfs(int n, int k)
{
	// 초기화
	Q[++rear] = n;
	V[n] = 1;
	while (front != rear)
	{
		n = Q[++front];
		if (n == k)
			return;
		// 인접에 대해.. n-1, n+1, 2*n
		if ((n - 1 >= 0) && (V[n - 1] == 0))
		{
			Q[++rear] = n - 1;
			V[n - 1] = V[n] + 1;
		}
		if ((n + 1 <= 100000) && (V[n + 1] == 0))
		{
			Q[++rear] = n + 1;
			V[n + 1] = V[n] + 1;
		}
		if ((n *2 <= 100000) && (V[ n * 2 ] == 0))
		{
			Q[++rear] = n * 2;
			V[n * 2] = V[n] + 1;
		}
	}
}
