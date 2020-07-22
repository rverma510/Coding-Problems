#include <stdio.h>

int main() {
    char str1[] = "RAGHAV";
    printf("%s", str1);

    return 0;
}

/*

g++ -g AnalyzingMemory.cpp
gdb ./a.out
break 4
run
step
p str1
p &str1
x/6tb <starting address of str1>

*/