#include <stdio.h>

typedef struct {
    int id;
    int burst;
    int share;
} Process;

int main() {
    int n, i, j;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    Process p[n];

    for(i = 0; i < n; i++) {

        p[i].id = i + 1;

        printf("\nProcess %d\n", i + 1);

        printf("Burst Time: ");
        scanf("%d", &p[i].burst);

        printf("CPU Share (percentage): ");
        scanf("%d", &p[i].share);
    }

    printf("\nExecution Order:\n");

    for(i = 0; i < n; i++) {

        int time = (p[i].burst * p[i].share) / 100;

        printf("P%d executes for %d units\n", p[i].id, time);
    }

    return 0;
}
