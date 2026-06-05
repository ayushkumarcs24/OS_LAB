#include <stdio.h>

int main()
{
    int pages[50], frame[10];
    int n, f, i, j, k, fault = 0;
    int found, pos = 0;

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
            int farthest = -1;

            for(j = 0; j < f; j++)
            {
                int next = 999;

                for(k = i + 1; k < n; k++)
                {
                    if(frame[j] == pages[k])
                    {
                        next = k;
                        break;
                    }
                }

                if(next > farthest)
                {
                    farthest = next;
                    pos = j;
                }
            }

            printf("%d ", pages[i]);
            frame[pos] = pages[i];
            fault++;
        }
    }

    printf("\nTotal Page Faults = %d", fault);

    return 0;
}
