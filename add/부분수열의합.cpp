/* 2817 부분 수열의 합 */
// 부분 집합의 합을 구하는 문제..
// 백트래킹 적용

#include <stdio.h>

int a[20];
void find(int n, int d, int k, int s, int ss);
int cnt;
int main(void)
{
    int T;
    scanf("%d", &T);
    for(int tc=1;tc<=T;tc++)
    {
        int N, K, t=0;
        cnt = 0;
        scanf("%d %d", &N, &K);
        for(int i=0;i<N;i++)
        {
           scanf("%d", &a[i]);
            t+=a[i];
        }
        find(0, N, K, 0, t);
        printf("#%d %d\n", tc, cnt);
    }
}
void find(int n, int d, int k, int s, int ss)
{
    if(k==s)
    {
    	cnt++;
        return;
    }
    else if(n==d) //
    	return;
    else if(s+ss<k)
        return;
    else if(s>k)
        return;
    else
    {
        find(n+1, d, k, s+a[n], ss-a[n]); // a[n] 포함
        find(n+1, d, k, s, ss-a[n]);		// a[n] 미포함
    }
}
