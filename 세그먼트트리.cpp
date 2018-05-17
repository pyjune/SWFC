/* 구간의 최대값을 저장하는 세그먼트 트리 */

#include <stdio.h>

int a[] = { 7, 2, 4, 11, 5, 9, 10, 6, 3, 8 };
int t[1000];

int makeT(int n, int s, int e);
void changeT(int n, int s, int e, int id, int d); // 배열 a[id]자리를 d로 변경
int findT(int n, int s, int e, int l, int r); // l, r 구간의 최대값
int main(void)
{
	makeT(1, 0, 9);
	printf("%d\n", findT(1, 0, 9, 0, 5)); // a[0]~a[5] 최대값
	changeT(1, 0, 9, 1, 12);
	printf("%d\n", findT(1, 0, 9, 0, 5)); // a[0]~a[5] 최대값
	printf("%d\n", findT(1, 0, 9, 4, 7)); // a[4]~a[7] 최대값
	printf("%d\n", findT(1, 0, 9, 0, 9)); // a[0]~a[9] 최대값
}
int findT(int n, int s, int e, int l, int r)
{
	if (r < s || e < l) // 구간을 벗어난 경우
		return 0;
	else if (l <= s && e <= r) // 전체가 l,r에 포함되면 l<=s..e<=r 
		return t[n];
	else // 일부가 겹치거나 s<=l..r<=e처럼 포함되면
	{
		int r1 = findT(n * 2, s, (s + e) / 2, l, r);
		int r2 = findT(n * 2 + 1, (s + e) / 2 + 1, e, l, r);
		return r1 > r2 ? r1 : r2; // 큰 값 반환
	}
}
void changeT(int n, int s, int e, int id, int d)
{
	if (s == e) //leaf에 도달하면 
		t[n] = d;
	else
	{
		t[n] = d > t[n] ? d : t[n]; // 구간의 최대값보다 크면 교체
		if (id <= (s + e) / 2) // id를 포함한 노드로만 이동
		{
			changeT(n * 2, s, (s + e) / 2, id, d);
		}
		else
		{
			changeT(n * 2+1, (s + e) / 2+1, e, id, d);
		}
	}
}
int makeT(int n, int s, int e)
{
	if (s == e) // leaf인 경우
		t[n] = a[s];
	else
	{
		int r1 = makeT(n * 2, s, (s + e) / 2);
		int r2 = makeT(n * 2 + 1, (s + e) / 2 + 1, e);
		t[n] = r1 > r2 ? r1 : r2;
	}
	return t[n];
}
