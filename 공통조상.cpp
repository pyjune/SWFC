/* 1248 공통조상 */
#include <stdio.h>

int ch1[10001];
int ch2[10001];
int par[10001];
int ans[10001];
int V, E;
int cnt;

int findA(int d1, int d2);
void dlr(int n);

int main(void)
{
	int T;
	freopen("Text.txt", "r", stdin);
	scanf("%d", &T);
	{
		int des1, des2;
		for (int tc = 1; tc <= T; tc++)
		{
			scanf("%d %d %d %d", &V, &E, &des1, &des2);
			for (int i = 0; i < E; i++)
			{
				int n1, n2;
				scanf("%d %d", &n1, &n2);
				if (ch1[n1] == 0)  // 부모를 인덱스로 자식 저장
					ch1[n1] = n2;
				else
					ch2[n1] = n2;
				par[n2] = n1;		// 자식을 인덱스로 부모 저장
			}
			int n = findA(des1, des2);
			dlr(n);
			printf("#%d %d %d\n", tc, n, cnt); 
			for (int i = 1; i <= V; i++)
			{
				ch1[i] = 0;
				ch2[i] = 0;
				par[i] = 0;
				ans[i] = 0;
				cnt = 0;
			}
		}
	}
}

int findA(int d1, int d2)
{
	while (par[d1] != 0) // d1의 조상을 ans에 표시
	{
		d1 = par[d1];
		ans[d1] = 1;
	}
	while (ans[par[d2]] == 0) // d2의 조상 중 ans에 표시된 것 확인
	{
		d2 = par[d2];
	}
	return par[d2];
}

void dlr(int n)
{
	if (n > 0)
	{
		cnt++; // 방문한 노드의 개수
		dlr(ch1[n]);
		dlr(ch2[n]);
	}
}
