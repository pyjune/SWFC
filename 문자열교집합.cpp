#include <stdio.h>
#include <malloc.h>

unsigned long hash(char *str);
void addTable(char * p, int N);
int checkTable(char * s, int N);
int strCmp(const char s1[], const char s2[]);

typedef struct table{
	char s[51];
	table * link;
}TableType;

TableType t[500000];

int main(void)
{
	int T;
	//freopen("Text.txt", "r", stdin);
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++)
	{
		int N, M;
        char s[51];
		scanf("%d %d", &N, &M);
		for (int i = 0; i < N; i++)
		{
			scanf("%s", s);
			addTable(s, N);
		}
		int cnt = 0;
		for (int i = 0; i < M; i++)
		{
			scanf("%s", s);
			cnt += checkTable(s, N);
		}
		printf("#%d %d\n", tc, cnt);
		for (int i = 0; i < N; i++)
		{
			t[i].s[0] = '\0';
			t[i].link = NULL;
		}
	}
}

void strCpy(char d[], const char s[])
{
	int i = 0;
	while (s[i] != '\0')
	{
		d[i] = s[i];
		i++;
	}
	d[i] = '\0';
}

int strCmp(const char s1[], const char s2[])
{
	int i = 0;
	while (s1[i] != '\0' && s1[i]==s2[i])
	{
		i++;
	}
	return s1[i] - s2[i];
}

int checkTable(char * s, int N)
{

	int h = hash(s) % N;
	if (strCmp(t[h].s, s)==0)
		return 1;
	else
	{
		TableType * pNext = t[h].link;

		while (pNext != NULL)
		{
			if (strCmp(pNext->s, s) == 0)
				return 1;
			pNext = pNext->link;
		}
		return 0;

	}
}
void addTable(char * s, int N)
{
	TableType * p;
	int h = hash(s) % N;
	if (t[h].s == '\0')
		strCpy(t[h].s, s);
	else
	{
		TableType * pNext = (TableType *)malloc(sizeof(TableType));
		strCpy(pNext->s, s);
		pNext->link = NULL;
		if (t[h].link == NULL)
			t[h].link = pNext;
		else
		{
			p = t[h].link;
			while (p->link != NULL)
			{
				p = p->link;
			}
			p->link = pNext;
		}
	}
}

// DJB2 hash by Dan J. Bernstein 
unsigned long hash(char *str)
{
	unsigned long hash = 5381;
	int c;

	while (c = *str++)
		hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

	return hash;
}
