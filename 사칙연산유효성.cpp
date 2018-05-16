/* 1233 사칙연산 유효성 검사 */
#include <stdio.h>

int t[201]; // 피연산자 저장
char op[201]; // 연산자 저장

int atoI(char s[]);
int find(int n, int last);

int main(void)
{
	int T = 10;
	//freopen("Text.txt", "r", stdin);
	for (int tc = 1; tc <= T; tc++)
	{
		int N;
		scanf("%d", &N);
		for (int i = 0; i < N; i++)
		{
			int idx, n1, n2;
			char s[10];
			scanf("%d %s", &idx, s);
			if (idx * 2 <= N) // 왼쪽노드 존재
				scanf("%d", &n1);
			if (idx * 2 + 1 <= N) // 오른쪽 노드 존재
				scanf("%d", &n2);
			if (s[0] >= '0'&&s[0] <= '9') // 두번째가 피연산자인 경우
				t[idx] = atoI(s);
			else
				op[idx] = s[0];

		}
		printf("#%d %d\n", tc, find(1, N));
		for (int i = 1; i <= N; i++)
		{
			op[i] = '\0';
			t[i] = 0;
		}
	}
}
// 유효하지 않으면 0 리턴
int find(int n, int last)  
{
	int r1 = 0, r2 = 0;
	if (n * 2 > last) // leaf인 경우
		return op[n] != 0 ? 0 : 1;// 피연산자면 오류
	else
	{
		if (2 * n <= last)
			r1 = find(2 * n, last);
		if (2 * n + 1 <= last)
			r2 = find(2 * n + 1, last);
		// if문으로 두 개의 리턴값이 피연산자이고, 현재 노드가 연산자인지 판단해도 됨.
		return r1 && r2 && op[n]; //두 개의 피연산자와 연산자면 1 리턴
	}
}
// 문자열을 정수로 변환 "123" -> 123
int atoI(char s[])
{
	int i = 0;
	int v = 0;
	while (s[i] != '\0')
	{
		v = v * 10 + (s[i] - '0');
		i++;
	}
	return v;
}
