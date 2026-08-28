#include <stdio.h>
#include <limits.h>

int main(){
    int n,i;

    printf("enter number of elements: ");
    
    scanf("%d",&n);

    int arr[n];
    printf("enter elements:\n");

    for(i=0;i<n;i++){
        for(i=0;i<n;i++){
            scanf("%d",&arr[i]);
        }

        int largest = INT_MIN;
        int secondlargest = INT_MIN;

        for(i=0;i<n;i++){
            if(arr[i]>largest){
                secondlargest = largest;
                largest = arr[i];


            }

            else if(arr[i]>secondlargest && arr[i] != largest){
                secondlargest = arr[i];
            }
        }

        if(secondlargest == INT_MIN){
            printf("second largest element does not exist ");

        }
        else{

            printf("largest = %d\n",largest);
            printf("second largest = %d\n", secondlargest);

        }

        return 0;
    }


}