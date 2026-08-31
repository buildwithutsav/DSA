#include <stdio.h>
int main(){
    int n , i ,j;
    int count , alreadycounted;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements: \n");

    for(i=0;i<n;i++){
        scanf("%d", &arr[i]);

    }

    printf("\nfrequency:\n");

    for(i=0;i<n;i++){
        alreadycounted = 0;

        for(j = 0;j<i;j++){
            if(arr[i]==arr[j]){
                alreadycounted = 1;
                break;

            }
        }

        if(alreadycounted == 0){
            count = 0;
             
            for(j=0;j<n;j++){
                if(arr[i] == arr[j]){
                    count++;
                }
            }

            printf("%d -> %d\n",arr[i],count);

        }


    }

    return 0;

}