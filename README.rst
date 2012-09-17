================================
"Learn C The Hard Way" exercises
================================

:info: Exercises from "Learn C The Hard Way" by Zed A. Shaw

- To compile libex29.c and make the .so lib::

    cc -c libex29.c -o libex29.o
    cc -shared -o libex29.so libex29.o

- To compile and link ex29.c::

    cc -Wall -g ex29.c -o ex29 -ldl 
