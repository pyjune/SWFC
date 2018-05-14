#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int batt[11];
int min;
int cnt2;

void drive(int n, int k, int e, int c); 

int main(int argc, char *argv[]) {
	
	int tc, T;
	int N;
	int i;
	freopen("Text.txt", "r", stdin);
	scanf("%d", &T);
	for(tc = 1; tc<=T; tc++)
	{
		scanf("%d", &N);
		min = 10;
		cnt2 = 0;
		for(i=1;i<N;i++)
		{
			scanf("%d", &batt[i]);
		}
		
		//drive(1, 0, 0);
		drive(2, N, batt[1]-1, 0); // 정류장 번호, 종점, 남은에너지, 교환횟수 
		printf("#%d %d %d\n", tc, min, cnt2);
	}
	
	
	
	return 0;
}

void drive(int n, int k, int e, int c)
{
	if(n==k)
	{
		cnt2++;
		if(min>c)
			min = c;
	}
	else if(c > min)
	{
		return;
	}
	else
	{
		// 통과
		if( e > 0)
			drive(n+1, k, e-1, c);
		
		// 교체 
		drive(n+1, k, batt[n]-1, c+1);
	}
}
