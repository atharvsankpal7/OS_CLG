#include <stdio.h>
#include <stdbool.h>
#define m 3 // number of resources
#define n 5 // number of process

int main()
{
    int k = 0;
    int sequenceBuffer[n];
    int remainingProcessCount = n;
    int systemMax[m] = {10, 5, 7};
    int systemAvailable[m];
    int processMax[n][m] = {{7, 5, 3}, {3, 2, 2}, {9, 0, 2}, {2, 2, 2}, {4, 3, 3}};
    int processAllocation[n][m] = {{0, 1, 0}, {2, 0, 0}, {3, 0, 2}, {2, 1, 1}, {0, 0, 2}};
    int processNeed[n][m];
    bool isProcessExecuted[n] = {false, false, false, false, false};

    // initial calculations
    for (int i = 0; i < m; i++)
    {
        int sum = 0;
        for (int j = 0; j < n; j++)
        {
            sum += processAllocation[j][i];
        }
        systemAvailable[i] = systemMax[i] - sum;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            processNeed[i][j] = processMax[i][j] - processAllocation[i][j];
        }
    }

    // process execution starts
    while (remainingProcessCount > 0)
    {
        for (int i = 0; i < n; i++)
        {
            if (isProcessExecuted[i])
                continue;
            bool canExecute = true;
            for (int j = 0; j < m; j++)
            {
                if (processNeed[i][j] > systemAvailable[j]) // checking if the machine can fulfill the requirements of process
                {
                    canExecute = false;
                }
            }
            if (canExecute)
            {
                isProcessExecuted[i] = true;
                for (int j = 0; j < m; j++)
                {
                    systemAvailable[j] += processAllocation[i][j];
                }
                sequenceBuffer[k++] = i; // setting up the process in the sequence buffer
                remainingProcessCount--;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ", sequenceBuffer[i]);
    }

    return 0;
}
