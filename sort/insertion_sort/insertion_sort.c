#include <stdio.h>

void insertion_sort(int *arr, int size){
    int compare_time = 0;
    for(int i = 1; i < size; i++){
        if( arr[i - 1] > arr[i] ){
            compare_time += 1;
            int t = arr[i];
            int j;
            for(j = i - 1; j >= 0 && arr[j] > t; j--) {
                arr[j + 1] = arr[j];
                compare_time += 1;
            }
            arr[j + 1] = t;
        }
    }
    printf("compare_time: %d\n", compare_time);
}

void print(int *arr, int size){
    for(int i = 0; i < size; i++){
        printf("%d, ", arr[i]);
    }
    printf("\n");
}

void bin_insertion_sort(int *arr, int size){
     int compare_time = 0;
     for(int i = 1; i < size; i++){
        if(arr[i -1] > arr[i]){
            compare_time += 1;
            int t = arr[i];
            int lo = 0;
//            print(arr, size);
            int hi = i - 1;
            while( lo <= hi ){
                int mid = (lo + hi) / 2;
                if( arr[mid] > t){
                    hi = mid - 1;
                }else{
                    lo = mid + 1;
                }
                compare_time += 1;
            }
//            printf("low: %d, high: %d\n\n", lo, hi);
            int j = i - 1;
            for(; j >= lo; j--) arr[j + 1] = arr[j];
            arr[lo] = t;
        }
    }
    printf("compare_time: %d\n", compare_time);
}



void main(){
    int arr[] = {1,3,4,6,2,3,5,25,32,12,3,2,3,5,6,7,21,4,3,1,3,4,};
    bin_insertion_sort(arr, 20);
    for(int i = 0; i < 20; i++){
        printf("%d, ", arr[i]);
    }
}