    #include <stdio.h>
    struct processes
    {
        int at;
        int bt;
        int tat;
        int ct;
        int wt;
    } p[6];

    int main()
    {
        int n = 6;
        float tat_avg = 0, wt_avg = 0;

        printf("Enter the information in ascending order to the arrival time\n");
        for (int i = 0; i < n; i++)
        {
            printf("Enter the arrival time of the process %d --> ", i + 1);
            scanf(" %d", &p[i].at);
            printf("Enter the burst time of the process %d --> ", i + 1);
            scanf(" %d", &p[i].bt);
        }
        p[0].ct = p[0].bt + p[0].at;
        for (int i = 1; i < n; i++)
        {
            p[i].ct = p[i - 1].ct + p[i].bt;
            p[i].tat = p[i].ct - p[i].at;
            p[i].wt = p[i].tat - p[i].bt;
            tat_avg += p[i].tat;
            wt_avg += p[i].wt;
        }

        tat_avg /= (n);
        wt_avg /= (n);
        printf("The total turn around time is --> %f\n", tat_avg);
        printf("The total waiting time is --> %f\n", wt_avg);
        return 0;
    }