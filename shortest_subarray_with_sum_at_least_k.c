#include <stdio.h>
#include <limits.h>

#define MAX 100005

long long prefix[MAX];
int deque[MAX];

int main() {
    int n;
    long long K;

    scanf("%d", &n);

    if (n <= 0 || n >= MAX) {
        printf("-1\n");
        return 0;
    }

    int arr[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    scanf("%lld", &K);

    prefix[0] = 0;

    for (int i = 0; i < n; i++)
        prefix[i + 1] = prefix[i] + arr[i];

    int front = 0, back = 0;
    int answer = n + 1;

    for (int i = 0; i <= n; i++) {

        while (front < back &&
               prefix[i] - prefix[deque[front]] >= K) {

            int length = i - deque[front];

            if (length < answer)
                answer = length;

            front++;
        }

        while (front < back &&
               prefix[i] <= prefix[deque[back - 1]]) {
            back--;
        }

        deque[back++] = i;
    }

    printf("%d\n", answer == n + 1 ? -1 : answer);

    return 0;
}