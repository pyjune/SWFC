/* 1926 간단한 369게임 */
#include <stdio.h>

int main(void)
{
    int N;
    scanf("%d", &N);
    for(int i=1;i<=N;i++)
    {
        int cnt = 0;
        int n = i;
        int t;
        while(n>0)
        {
        	  t = n%10;
            if(t%3==0 && t!=0)
                cnt++;
            n = n/10;
        }
        if(cnt == 0)
            printf("%d ", i);
        else
        {
            for(int j=0;j<cnt;j++)
                printf("-");
            printf(" ");
        }      
    }
}
