/* P1231 중위순회 */
#include <stdio.h>

char t[101];

void find(int n, int last);
void find2(int n, int last);
int main(void)
{
	int T=10;
	//freopen("Text.txt", "r", stdin);
	for (int tc = 1; tc <= T; tc++)
	{
		int N;
		scanf("%d", &N);
		for (int i = 0; i < N; i++)
		{
			int idx, ch, n1, n2;
			scanf("%d %c", &idx, &ch);
			if (idx*2+1 <= N) // 양쪽 자식이 있는 경우
				scanf("%d %d", &n1, &n2);
			else if (idx*2 <=N) // 왼쪽 자식만 있는 경우
				scanf("%d", &n1);
			t[idx] = ch;
		}
		printf("#%d ", tc);
		find2(1, N);
		printf("\n");
	}
}

void find(int n, int last)
{
	if (n * 2 <= last)
		find(n * 2, last);
	printf("%c", t[n]);
	if (n * 2 + 1 <= last)
		find(n * 2 + 1, last);
}

void find2(int n, int last)
{
	if (n <= last)
	{
		find(n * 2, last);
		printf("%c", t[n]);
		find(n * 2 + 1, last);
	}
}
