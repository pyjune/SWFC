/* 1859 백만장자 프로젝트 */
#include <stdio.h>

int a[1000000]; 
int m[1000000];

int main(void)
{
	int T;
	//freopen("Text.txt", "r", stdin);
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++)
	{
		int N;
		long long total = 0; // 합계가 크기 때문에 long long형으로 지정
		scanf("%d", &N);
		for (int i = 0; i < N; i++)
			scanf("%d", &a[i]);
		m[N - 1] = a[N - 1];
		for (int i = N - 2; i > 0; i--)
		{
			m[i] = a[i] > m[i + 1] ? a[i] : m[i + 1];
		}
		for (int i = 0; i < N; i++)
		{
			total += a[i] < m[i + 1] ? m[i + 1] - a[i] : 0;
		}
		printf("#%d %lld\n", tc, total); // long long 형 출력시 %lld로 지정
	}
}
