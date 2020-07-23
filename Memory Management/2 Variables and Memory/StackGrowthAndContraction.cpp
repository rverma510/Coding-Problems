#include <stdio.h>

void MyFunc() {
    int k = 3;
    printf ("3: %p \n", &k);

}

int main() {
    int i = 1;
    printf("1: %p \n", &i);

    int j = 2;
    printf("2: %p \n", &j);

    MyFunc();

    int l = 4;
    printf("4: %p \n", &l);

    return 0;
}

/*

1: 0x7fff83d5b0ac 
2: 0x7fff83d5b0b0 
3: 0x7fff83d5b084 
4: 0x7fff83d5b0b4 

*/