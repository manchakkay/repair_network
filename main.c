#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N = 0, M = 0, counter = 1;

    printf("N: ");
    scanf("%d", &N);
    printf("Amount of connections: ");
    scanf("%d", &M);

    int *arr = malloc(sizeof(int *) * N);
    int *lst = malloc(sizeof(int *) * N);

    for (int i = 0; i < N; i++)
    {
        arr[i] = 0;
        lst[i] = 0;
    }

    for (int i = 0; i < M; i++)
    {
        int x = 0, y = 0;
        scanf("%d %d", &x, &y);
        x--;
        y--;

        if (arr[x] == 0)
        {
            if (arr[y] == 0)
            {
                // 0 0 -> 1 1
                arr[x] = counter;
                arr[y] = counter++;
            }
            else
            {
                // 0 9 -> 9 9
                arr[x] = arr[y];
            }
        }
        else
        {
            if (arr[y] == 0)
            {
                // 7 0 -> 7 7
                arr[y] = arr[x];
            }
            else
            {
                // 7 9 -> 7 7
                int temp = arr[y];
                for (int i = 0; i < N; i++)
                {
                    if (arr[i] == temp)
                    {
                        arr[i] = arr[x];
                    }
                }
            }
        }
    }

    M = 0;
    for (int i = 0; i < N; i++)
    {
        if (!arr[i])
        {
            arr[i] = counter++;
        }

        int found = 0;
        for (int j = 0; j < N; j++)
        {
            if (arr[i] == lst[j])
            {
                found = 1;
                break;
            }
        }

        if (!found)
        {
            lst[M++] = arr[i];
        }
    }

    printf("%d", M - 1);

    return 0;
}