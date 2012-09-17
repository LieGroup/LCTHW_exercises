#include <stdio.h>

/* 用来测试core dump的程序 */
int main(int argc, char *argv[])
{
	char *s = NULL;
	printf("%c\n", *s);
	return 0;
}
