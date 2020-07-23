int main() {
    int *p = new int[10];
    return 0;
}

// valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --log-file=./valgrind-out.txt ./a.out