#include <cstdio>

using namespace std;

void hanoi(int n, char A, char B, char C) {
    if (n == 0) return;
    hanoi(n-1, A, C, B);
    printf("Move ring %d from %c to %c\n", n, A, C);
    hanoi(n-1, B, A, C);
}

int main() {
    int n;
    while(scanf("%d", &n) != EOF) {
        hanoi(n, 'A', 'B', 'C');
    }

    return 0;
}