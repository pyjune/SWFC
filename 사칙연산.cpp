/* 1232 사칙연산 */
#include <stdio.h>

int ch1[1001]; // 부모를 인덱스로 자식노드 저장
int ch2[1001]; // 
int t[1001]; // 피연산자 저장
char op[1001]; // 연산자 저장

int atoI(char s[]);
double find(int n);


int main(void)
{
	int T = 10;
	//freopen("Text.txt", "r", stdin);
	for (int tc = 1; tc <= T; tc++)
	{
		int N;
		scanf("%d", &N);
		
		int idx, n1, n2;
		char s[10];
		for (int i = 0; i < N; i++)
		{
			scanf("%d %s", &idx, s);
			if (s[0] >= '0'&&s[0] <= '9') // 피연산자인 경우
			{
				t[idx] = atoI(s); // 정수로 변환해 저장
			}
			else			// 연산자인 경우
			{
				int n1, n2;
				scanf("%d %d", &n1, &n2);
				op[idx] = s[0];
				ch1[idx] = n1; // 양쪽 자식 노드번호 저장
				ch2[idx] = n2;
			}
		}
		printf("#%d %d\n", tc, (int)find(1));
		for (int i = 0; i <= N; i++)
		{
			ch1[i] = 0;
			ch2[i] = 0;
			op[i] = '\0';
			t[i] = 0;

		}
		
	}
}
// 순회

double find(int n)
{
	if (t[n] > 0)			// 피연산자 노드면 값 리턴
		return (double) t[n];
	else // 피연산자 아니면 연산자
	{
		double r1, r2, r;
		r1 = find(ch1[n]);
		r2 = find(ch2[n]);
		if (op[n] == '+')
			r = r1 + r2;
		else if (op[n] == '-')
			r = r1 - r2;
		else if (op[n] == '*')
			r = r1 * r2;
		else if (op[n] == '/')
			r = r1 / r2;
		return r;
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
