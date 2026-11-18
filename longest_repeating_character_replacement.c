
#include <stdio.h>
#include <string.h>

int characterReplacement(char s[], int k) {
    int freq[26] = {0};

    int left = 0;
    int maxFreq = 0;
    int maxLength = 0;

    int n = strlen(s);

    for (int right = 0; right < n; right++) {
        int index = s[right] - 'A';

        freq[index]++;

        if (freq[index] > maxFreq)
            maxFreq = freq[index];

        while ((right - left + 1) - maxFreq > k) {
            freq[s[left] - 'A']--;
            left++;
        }

        int length = right - left + 1;

        if (length > maxLength)
            maxLength = length;
    }

    return maxLength;
}

int main() {
    char s[1000];
    int k;

    printf("Enter uppercase string: ");
    scanf("%999s", s);

    printf("Enter k: ");
    scanf("%d", &k);

    if (k < 0) {
        printf("Invalid k\n");
        return 0;
    }

    printf("Longest substring length: %d\n",
           characterReplacement(s, k));

    return 0;
}
