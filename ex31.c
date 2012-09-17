#include <unistd.h>

// 一个死循环程序，用于探索gdb的用法

int main(int argc, char *argv[])
{
	int i = 0;

	while(i < 100)
	{
		usleep(3000);
	}

	return 0;
}
