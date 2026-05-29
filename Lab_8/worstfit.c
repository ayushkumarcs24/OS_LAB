#include <stdio.h>

int main() {
    int b[20], p[20], alloc[20];
    int m, n, i, j, worst;

    printf("Enter number of blocks: ");
    scanf("%d", &m);

    printf("Enter block sizes:\n");
    for(i = 0; i < m; i++)
        scanf("%d", &b[i]);

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter process sizes:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &p[i]);

    for(i = 0; i < n; i++) {
        alloc[i] = -1;
        worst = -1;

        for(j = 0; j < m; j++) {
            if(b[j] >= p[i] && (worst == -1 || b[j] > b[worst]))
                worst = j;
        }

        if(worst != -1) {
            alloc[i] = worst;
            b[worst] = 0;
        }
    }

    printf("\nProcess\tBlock\n");
    for(i = 0; i < n; i++)
        printf("%d\t%d\n", i + 1, alloc[i] + 1);

    return 0;
}
