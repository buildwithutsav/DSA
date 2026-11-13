#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

typedef struct {
    int start;
    int finish;
    int profit;
} Job;

int compare(const void *a, const void *b) {
    Job *x = (Job *)a;
    Job *y = (Job *)b;

    if (x->finish < y->finish) return -1;
    if (x->finish > y->finish) return 1;
    return 0;
}

// Returns number of earlier jobs that finish
// at or before the current job starts.
int findCompatible(Job jobs[], int index) {
    int low = 0;
    int high = index - 1;
    int answer = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (jobs[mid].finish <= jobs[index].start) {
            answer = mid + 1;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return answer;
}

int main() {
    int n;
    Job jobs[MAX];
    int dp[MAX + 1];

    printf("Enter number of jobs: ");
    scanf("%d", &n);

    if (n < 1 || n > MAX) {
        printf("Invalid number of jobs\n");
        return 1;
    }

    printf("Enter start, finish and profit:\n");

    for (int i = 0; i < n; i++) {
        scanf("%d %d %d",
              &jobs[i].start,
              &jobs[i].finish,
              &jobs[i].profit);

        if (jobs[i].start > jobs[i].finish ||
            jobs[i].profit < 0) {
            printf("Invalid job details\n");
            return 1;
        }
    }

    qsort(jobs, n, sizeof(Job), compare);

    dp[0] = 0;

    for (int i = 0; i < n; i++) {
        int compatible = findCompatible(jobs, i);

        int include = jobs[i].profit + dp[compatible];
        int exclude = dp[i];

        dp[i + 1] = (include > exclude)
                    ? include : exclude;
    }

    printf("Maximum profit: %d\n", dp[n]);

    return 0;
}