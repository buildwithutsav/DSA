#include <stdio.h>
int main(){
    int n,i;

    printf("Enter n: ");
    scanf("%d",&n);

    int arr[n-1];

    printf("Enter %d elements: \n", n-1);
    for(i=0;i<n-1;i++){
        scanf("%d",&arr[i]);


    }

    int total = n*(n+1)/2;
    int sum = 0;

    for (i=0;i<n-1;i++){
        sum = sum +arr[i];

    }

    int missing = total - sum;
    printf("missing number = %d ,missing");

    return 0;
}