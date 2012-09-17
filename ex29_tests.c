#include <stdio.h>
#include "debug.h"
#include <dlfcn.h>

/* 演示：通过dlopen、dlsym动态调用shared library */
typedef int (*lib_function)(const char *data);


int main(int argc, char *argv[])
{
	int rc = 0;

	char *lib_file = "./libex29.so";
	char *data = "hello";
	// 打开library文件
	void *lib  = dlopen(lib_file, RTLD_NOW);
	check(lib != NULL, "Failed to open the library %s: %s", lib_file, dlerror());

	// 取得library中某一函数的指针
	char *func_to_run = "print_a_message";
	lib_function func  = dlsym(lib, func_to_run);
	check(func != NULL, "Did not find %s function in the library %s: %s", func_to_run, lib_file, dlerror());
	// 调用函数
	rc = func(data);
	check(rc == 0, "Function %s return %d for data: %s", func_to_run, rc, data);

	char *func_to_run = "uppercase";
	lib_function func  = dlsym(lib, func_to_run);
	check(func != NULL, "Did not find %s function in the library %s: %s", func_to_run, lib_file, dlerror());
	rc = func(data);
	check(rc == 0, "Function %s return %d for data: %s", func_to_run, rc, data);

	char *func_to_run = "lowercase";
	lib_function func  = dlsym(lib, func_to_run);
	check(func != NULL, "Did not find %s function in the library %s: %s", func_to_run, lib_file, dlerror());
	rc = func(data);
	check(rc == 0, "Function %s return %d for data: %s", func_to_run, rc, data);

	char *func_to_run = "fail_on_purpose";
	lib_function func  = dlsym(lib, func_to_run);
	check(func != NULL, "Did not find %s function in the library %s: %s", func_to_run, lib_file, dlerror());
	rc = func(data);
	check(rc == 0, "Function %s return %d for data: %s", func_to_run, rc, data);



	rc = dlclose(lib);
	check(rc == 0, "Failed to close %s", lib_file);

	return 0;

error:
	return 1;

}
