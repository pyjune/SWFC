/* 2930 힙 (최대힙) */

#include <stdio.h>

int last = 0;
void enq(int n);
int deq(void);
int q[1000000];

int main(void)
{
	int T;
	//freopen("Text.txt", "r", stdin);
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++)
	{
		last = 0;
		int N;
		scanf("%d", &N);
		printf("#%d", tc);
		for (int i = 0; i < N; i++)
		{
			int n1, n2;
			scanf("%d", &n1);
			if (n1 == 1)
			{
				scanf("%d", &n2);
				enq(n2);
			}
			else
			{
				if (last > 0)
					printf(" %d", deq());
				else
					printf(" -1");
			}

		}
		printf("\n");
	}
}

void enq(int n)
{
	int c = ++last; // 마지막 노드 추가
	int p = c / 2;
	q[c] = n;
	while (p > 0 && q[c]>q[p]) // 부모가 있고 자식이 부모보다 크면 교환
	{
		int t = q[c];
		q[c] = q[p];
		q[p] = t;
		c = p;
		p = c / 2;
	}
}
int deq(void)
{
	int n = q[1]; // 루트 데이터 백업
	int p = 1;
	int c1 = p * 2;
	int c2 = p * 2 + 1;

	q[1] = q[last--]; // 마지막 노드를 루트에 복사 후 노드 삭제
	if (last == 1)	// 루트만 남은 경우 비교 대상이 없음
		return n;
	while (1)
	{
		// 양쪽 자식이 있는 경우
		int c;
		if (c2 <= last)
		{
			c = q[c1] > q[c2] ? c1 : c2; // 더 큰 쪽 선택
		}
		else if (c1 <= last) // 한 쪽 자식만 있는 경우
		{
			c = c1; // 남은 자식이 비교대상
		}
		else
			break;
		if (q[p] < q[c])  // 자식이 더 크면 교환
		{
			int t = q[p];
			q[p] = q[c];
			q[c] = t;
			p = c; // 자식의 자식과 비교 준비
			c1 = p * 2;
			c2 = p * 2 + 1;
		}
		else
			break; // 비교 중지
	}
	return n; // 루트 백업 반환
}
