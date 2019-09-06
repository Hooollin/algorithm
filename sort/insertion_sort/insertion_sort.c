#include <stdio.h>

void insertion_sort(int *arr, int size){
    int t;
    for(int i = 1; i < size; i++){
        if( arr[i - 1] < arr[i] ) continue;
        t = arr[i];
        int j = i - 1;
        for(; j >= 0 && arr[j] > t; j--) arr[j + 1] = arr[j];
        arr[j + 1] = t;
    }
}

void main(){
    int arr[] = {6,5,4,3,2,1,2,3,5,25,32,12,3};
    insertion_sort(arr, 10);
    for(int i = 0; i < 10; i++){
        printf("%d, ", arr[i]);
    }
}