#include<stdio.h>
void view(FILE* fp)
{
	int c;
	while((c = fgetc(fp))!=EOF)
	{
		printf("%c",c);
	}
}
