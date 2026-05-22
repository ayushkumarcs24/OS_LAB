#include <stdio.h>

int main() {
    int n,m,i,j,k;

    printf("Processes: ");
    scanf("%d",&n);

    printf("Resources: ");
    scanf("%d",&m);

    int alloc[n][m], req[n][m], avail[m], finish[n];

    printf("Enter Allocation Matrix:\n");
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            scanf("%d",&alloc[i][j]);

    printf("Enter Request Matrix:\n");
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            scanf("%d",&req[i][j]);

    printf("Enter Available Resources:\n");
    for(i=0;i<m;i++)
        scanf("%d",&avail[i]);

    for(i=0;i<n;i++)
        finish[i]=0;

    int found;

    do {
        found=0;

        for(i=0;i<n;i++) {

            if(finish[i]==0) {

                for(j=0;j<m;j++)
                    if(req[i][j]>avail[j])
                        break;

                if(j==m) {

                    for(k=0;k<m;k++)
                        avail[k]+=alloc[i][k];

                    finish[i]=1;
                    found=1;
                }
            }
        }

    } while(found);

    printf("\nDeadlocked Processes: ");

    for(i=0;i<n;i++)
        if(finish[i]==0)
            printf("P%d ",i);

    return 0;
}
