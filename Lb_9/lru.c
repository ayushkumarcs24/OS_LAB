#include <stdio.h>

int main()
{
    int pages[50], frame[10], time[10];
    int n, f, i, j, fault = 0;
    int counter = 0, found, pos;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter page reference string: ");
    for(i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &f);

    for(i = 0; i < f; i++)
    {
        frame[i] = -1;
        time[i] = 0;
    }

    printf("Page Faults: ");

    for(i = 0; i < n; i++)
    {
        found = 0;

        for(j = 0; j < f; j++)
        {
            if(frame[j] == pages[i])
            {
                counter++;
                time[j] = counter;
                found = 1;
                break;
            }
        }

        if(!found)
        {
            pos = 0;
            for(j = 1; j < f; j++)
                if(time[j] < time[pos])
                    pos = j;

            printf("%d ", pages[i]);
            frame[pos] = pages[i];
            counter++;
            time[pos] = counter;
            fault++;
        }
    }

    printf("\nTotal Page Faults = %d", fault);

    return 0;
}
