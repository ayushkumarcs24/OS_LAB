#include <stdio.h>

struct Process {
    int id;
    int burst;
    int period;
    int remaining;
};

int main() {
    int n, time, hyper = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process p[n];

    for(int i = 0; i < n; i++) {
        printf("\nProcess P%d\n", i + 1);

        p[i].id = i + 1;

        printf("Enter Burst Time: ");
        scanf("%d", &p[i].burst);

        printf("Enter Period: ");
        scanf("%d", &p[i].period);

        p[i].remaining = 0;

        if(p[i].period > hyper)
            hyper = p[i].period;
    }

    printf("\nExecution Order:\n");

    for(time = 0; time < hyper * 2; time++) {

        // Release tasks
        for(int i = 0; i < n; i++) {
            if(time % p[i].period == 0) {
                p[i].remaining = p[i].burst;
            }
        }

        int selected = -1;
        int minPeriod = 9999;

        // Select highest priority process
        for(int i = 0; i < n; i++) {
            if(p[i].remaining > 0 && p[i].period < minPeriod) {
                minPeriod = p[i].period;
                selected = i;
            }
        }

        if(selected != -1) {
            printf("Time %d -> P%d\n", time, p[selected].id);
            p[selected].remaining--;
        }
        else {
            printf("Time %d -> Idle\n", time);
        }
    }

    return 0;
}
