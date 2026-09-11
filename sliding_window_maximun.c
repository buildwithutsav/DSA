#include <stdio.h>
int main(){
    int n , k,i,j;
    printf("enter number of element: ");
    scanf("%d",&n);

    int arr[n];

    printf("enter element: ");

    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    printf("enter window size: ");
    scanf("%d", &k);

    printf("maximun of each window: ");
    for(i=0; i<=n-k; i++){
        int maximum = arr[i];
        for(j=i+1; j<i+k; j++){
            if(arr[j]>maximum){
                maximum = arr[j];

            }
        }
        printf("%d",maximum);
    }

    return 0;
}