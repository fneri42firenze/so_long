#include <stdio.h>
typedef struct s_struct
{
	int a;
	char str[10] = "ciaociao ";
	int b;
}	t_struct;

int main()
{
	t_struct ciao;
	ciao.a = 3;
	ciao.b = 8;
	printf("%i %s %i", ciao.a, ciao.str, ciao.b);
}