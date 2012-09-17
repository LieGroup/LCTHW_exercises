#include <stdio.h>
#include "debug.h"
#include <dlfcn.h>

/* 演示：通过dlopen、dlsym动态调用shared library */
typedef int (*lib_function)(const char *data);


int main(int argc, char *argv[])
{
	int rc = 0;
	check(argc == 4, "USAGE: ./ex29 libex29.so function data");

	char *lib_file = argv[1];
	char *func_to_run = argv[2];
	char *data = argv[3];
	// 打开library文件
	void *lib  = dlopen(lib_file, RTLD_NOW);
	check(lib != NULL, "Failed to open the library %s: %s", lib_file, dlerror());

	// 取得library中某一函数的指针
	lib_function func  = dlsym(lib, func_to_run);
	check(func != NULL, "Did not find %s function in the library %s: %s", func_to_run, lib_file, dlerror());

	// 调用函数
	rc = func(data);
	check(rc == 0, "Function %s return %d for data: %s", func_to_run, rc, data);

	rc = dlclose(lib);
	check(rc == 0, "Failed to close %s", lib_file);

	return 0;

error:
	return 1;

}
