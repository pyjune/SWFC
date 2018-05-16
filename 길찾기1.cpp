/* P1219 길찾기 */
#include <stdio.h>

int ch1[100];
int ch2[100];

int find(int n);
int main(void)
{
	int T = 10;
	//freopen("Text.txt", "r", stdin);
	for (int tc = 1; tc <= T; tc++)
	{
		int t, E;

		scanf("%d %d", &t, &E);
		for (int i = 0; i < E; i++)
		{
			int n1, n2;
			scanf("%d %d", &n1, &n2);
			if (ch1[n1] == 0)
				ch1[n1] = n2;
			else
				ch2[n1] = n2;

		}
		printf("#%d %d\n",tc, find(0));
		for (int i = 0; i < 100; i++)
		{
			ch1[i] = 0;
			ch2[i] = 0;
		}
	}
}

int find(int n)
{
	if (n == 99)
		return 1;
	else
	{
		int r1=0, r2=0;
		if (ch1[n]>0)
			r1 = find(ch1[n]);
		if (ch2[n]>0)
			r2 = find(ch2[n]);
		return r1 | r2;
	}

}
