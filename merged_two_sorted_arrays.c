#include <stdio.h>
int main(){
    int n1,n2,i ,j ,k;
    printf("Enter size of first array: ");
    scanf("%d",&n1);

    int a[n1];
    printf("Enter first sorted array: ");

    for(i=0;i<n1;i++){
        scanf("%d",&a[i]);


    }

    printf("Enter size of second array: ");
    scanf("%d",&n2);

    int b[n2];
    printf("Enter second sorted array:  ");
 
    for(i=0;i<n2;i++){
        scanf("%d",&b[i]);

    }

    int c[n1+n2];

    i=0;
    j=0;
    k=0;
    while(i<n1 && j<n2){

        if(a[i]<b[j]){
            c[k]=a[i];
            i++;
        }

        else{
            c[k]=b[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        c[k]=a[i];
        i++;
        k++;

    }
    while(j<n2){
        c[k]=b[j];
        j++;
        k++;

    }

    printf("Merged array: ");

    for(i=0;i<n1+n2;i++){
        printf("%d",c[i]);

    }

    return 0;

}