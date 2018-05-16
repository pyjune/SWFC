/* P1219 길찾기 - 중복 방문 방지 추가 */
#include <stdio.h>

int ch1[100];
int ch2[100];
int visited[100];
int find(int n);

int main(void)
{
   // freopen("input.txt", "r", stdin);
    for (int tc = 1; tc <= 10; tc++)
    {
        int T, E;
        scanf("%d %d", &T, &E);
        for (int i = 0; i < E; i++)
        {
            int n1, n2;
            scanf("%d %d", &n1, &n2);
            if (ch1[n1] == 0)
                ch1[n1] = n2;
            else
                ch2[n1] = n2;
        }
        printf("#%d %d\n", tc, find(0));
        for (int i = 0; i < 100; i++)
        {
            visited[i] = 0;
            ch1[i] = 0;
            ch2[i] = 0;
        }
        
    }
}

int find(int n)
{
    int r=0;
    visited[n] = 1;
    if (n == 99)
        return 1;
    else
    {
        if (ch1[n] != 0 && visited[ch1[n]] == 0)
        {
            r = find(ch1[n]);
            if (r == 1)
                return 1;
        }
        if (ch2[n] != 0 && visited[ch2[n]] == 0)
        {
            r = find(ch2[n]);
            if (r == 1)
                return 1;
        }
    }
    return 0;
}
