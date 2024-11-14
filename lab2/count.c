#include<stdio.h>

void display(int output[], int elements){

    for(int i=0;i<elements;i++){
        printf("%d\t", output[i]);
    }

}

void countSort(int exp, int arr[], int elements){
    int max=0;

    for(int i=0;i<elements;i++){
        if((arr[i]/exp)%10>max){
            max=(arr[i]/exp)%10;
        }
    }


    int count[max+1];
    for(int i=0;i<max+1;i++){
        count[i]=0;
    }

    for(int i=0;i<elements;i++){
        count[(arr[i]/exp)]++;
    }

    for(int i=1;i<max+1;i++){
        count[i]=count[i]+count[i-1];
    }

    int output[elements];

    for (int i = elements - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (int i = 0; i < elements; i++) {
        arr[i] = output[i];
    }

     if (max > 0) {
        countSort(exp * 10, arr, elements);
    }
}

void main (){

    int elements;
    printf("enter the amount of elements number: ");
    scanf("%d", &elements);
    int arr[elements];
    printf("enter each element one by one: ");
    for(int i=0;i<elements;i++){
        scanf("%d", &arr[i]);
    }

    int exp=1;


    countSort(exp , arr, elements);

    printf("Sorted array:\n");
    display(arr, elements);


}