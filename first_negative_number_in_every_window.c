#include <stdio.h>

int main(){
    int n , k ,i ,j;
    printf("enter number of element: ");
    scanf("%d",&n);

    int arr[n];

    printf("enter element: ");

    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);

    }

    printf("enter window size: ");
    scanf("%d", &k);

    printf("first negative in each window: ");

    for(i=0; i<=n-k; i++){
        int found = 0;
        for(j=i; j<i+k;j++){
            if(arr[j]<0){
                printf("%d", arr[j]);
                found = 1;
                break;

            }
        }

        if(found == 0){
            printf("0 ");

        }
    }

    return 0 ;
}
