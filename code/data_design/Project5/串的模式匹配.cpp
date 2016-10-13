#include <stdio.h>
#include <stdlib.h>
#include <string>
using namespace std;

int Index(char *s, char *t)
{
	int i = 0, j = 0;
	while (i<strlen(s)&&j<strlen(t))
	{
		if (s[i]==t[j])
		{
			i++;
			j++;
		}
		else
		{
			j = 0;
			i = i + 1;
		}
	}
	if (j >=strlen(t))
		return i-j+1;
	return 0;
}

void main()
{
	int i ;
	char *s = "abcdef";
	char *t = "cdef";
	int pos = Index(s, t);
	printf("%d\n", pos);
	system("pause");
}