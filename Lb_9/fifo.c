#include <stdio.h>

int main()
{
    int pages[50], frame[10];
    int n, f, i, j, k = 0, fault = 0, found;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter page reference string: ");
    for(i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &f);

    for(i = 0; i < f; i++)
        frame[i] = -1;

    printf("Page Faults: ");

    for(i = 0; i < n; i++)
    {
        found = 0;

        for(j = 0; j < f; j++)
            if(frame[j] == pages[i])
                found = 1;

        if(!found)
        {
            printf("%d ", pages[i]);
            frame[k] = pages[i];
            k = (k + 1) % f;
            fault++;
        }
    }

    printf("\nTotal Page Faults = %d", fault);

    return 0;
}
