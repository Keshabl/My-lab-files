#include <stdio.h>
#include <setjmp.h>
#define con 10000
jmp_buf env;

int fib(int n)
{
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        int a = fib(n - 1);
        int b = fib(n - 2);
        if (b > (con*con)) {
            longjmp(env, 1);
        }
        return a + b;
    }
}

int main(void)
{
    int i = 1;
    int res = 0;
    while (1) {
        if (setjmp(env) == 0) {
            res += fib(i);
            i++;
        } else {
            printf("FibSum: %d\n", res);
            return 0;
        }
    }
}

