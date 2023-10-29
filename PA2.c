    #include <stdio.h>
    #include <stdlib.h>
    #include <time.h>
    #include <math.h>

   

    int COMPCOUNT = 0;

    int COMPARE(int x, int y) { //overflow issue
        COMPCOUNT++;
        if (x < y) {
            return 1;
        }
        else {
            return 0;
        }
            
    }

    void merge(int arr[], int l, int m, int r) {
        int i, j, k;
        int n1 = m - l + 1;
        int n2 = r - m;
     
        int L[n1], R[n2];
     
        for (i = 0; i < n1; i++)
            L[i] = arr[l + i];
        for (j = 0; j < n2; j++)
            R[j] = arr[m + 1 + j];
     
        i = 0;
        j = 0;
        k = l;
        while (i < n1 && j < n2) {
            if (COMPARE(L[i], R[j]) == 1) {
                arr[k] = L[i];
                i++;
            }
            else {
                arr[k] = R[j];
                j++;
            }
            k++;
        }
     
        while (i < n1) {
            arr[k] = L[i];
            i++;
            k++;
        }
     
        while (j < n2) {
            arr[k] = R[j];
            j++;
            k++;
        }
    }
     
    void mergeSort(int arr[], int l, int r) {
        if (l < r) {
            int m = l + (r - l) / 2;
     
            mergeSort(arr, l, m);
            mergeSort(arr, m + 1, r);
     
            merge(arr, l, m, r);
        }
    }
     

    void swap(int *x, int *y) {
        int temp = *x;
        *x = *y;
        *y = temp;
        //COMPCOUNT++;
    }
  

     void heapify(int arr[], int n, int i) {
        int largest = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;
     
        if (l < n && COMPARE(arr[l], arr[largest]) == 1) {
            largest = l;
        }
        if (r < n && COMPARE(arr[r], arr[largest]) == 1) {
            largest = r;
        }
        if (largest != i) {
            swap(&arr[i], &arr[largest]);
            heapify(arr, n, largest);
        }

    }

      void heapSort(int arr[], int n) {
        int i;
        for (i = n / 2 - 1; i >= 0; i--) {
            heapify(arr, n, i);
        }
        for (i = n - 1; i > 0; i--) {
            swap(&arr[0], &arr[i]);
            heapify(arr, i, 0);
        }
    }

       
    int partition(int arr[], int low, int high) {
        int pivot = arr[high];
        int i = (low - 1);
        for (int j = low; j <= high - 1; j++) {
            if (COMPARE(arr[j], pivot) == 1) {
                i++;
                swap(&arr[i], &arr[j]);
            }
        }
        swap(&arr[i + 1], &arr[high]);
        return (i + 1);
    }



    void quickSort(int arr[], int low, int high) {
        if (low < high) {
            int pi = partition(arr, low, high);
            quickSort(arr, low, pi - 1);
            quickSort(arr, pi + 1, high);
        }
    }

 

    void printArray(int arr[], int n) {
        int i;
        for (i = 0; i < n; i++) {
            printf("%d ", arr[i]);
            
        }
        printf("\n");
    }

    int main(){

        int n = 32;
        int best_case_input[n];
        int worst_case_input[n];
        //int avg_case_input[n];
        int rand_input[n];

        // sort sorted input

         for (int i = 0; i < n; i++) {
            best_case_input[i] = i + 1;
        }

        //sort reversed input

        for (int i = 0; i < n; i++) {
            worst_case_input[i] = n - i;
        }

        // sort random input

        for (int i = 0; i < n; i++) {
            rand_input[i] = rand() % 100;
        }

        printf("Best Case Input: \n");

        printArray(best_case_input, n);

        printf("Worst Case Input: \n");

        printArray(worst_case_input, n);

        printf("Random Input: \n");
        printArray(rand_input, n);




    printf("Best Case Input: \n");

    printArray(best_case_input, n);

    printf("Worst Case Input: \n");

    printArray(worst_case_input, n);

    printf("Random Input: \n");

    printArray(rand_input, n);
    printf("\n");
    printf("\n");
    printf("Merge Sort:\n");
    
    printf("Sorted Case: \n");
    printf("Making sure it is sorted case:\n");
    printArray(best_case_input, n);

    //merge sort
    clock_t start = clock();
    COMPCOUNT = 0;
    //printf("Making sure COMPCOUNT is 0: %d\n", COMPCOUNT); checked
    mergeSort(best_case_input, 0, n-1);
    clock_t end = clock();
    printf("\nSorted Case Comparisons: %d\n", COMPCOUNT);
    printf("Time taken: %f\n", (double)(end - start) / CLOCKS_PER_SEC);
    printf("\n");
    printf("Reversed Case: \n");
    printf("Making sure it is Reversed Case:\n");
    printArray(worst_case_input, n);
    start = clock();
    COMPCOUNT = 0;
  //printf("Making sure COMPCOUNT is 0: %d\n", COMPCOUNT); checked
    mergeSort(worst_case_input, 0, n-1);
    end = clock();
    
    printf("\nReversed Case Comparisons: %d\n", COMPCOUNT);
    printf("Time taken: %f\n", (double)(end - start) / CLOCKS_PER_SEC);
    printf("\n");
    printf("Random Case: \n");
    printf("Making sure it is Random Case:\n");
    printArray(rand_input, n);
    start = clock();
    COMPCOUNT = 0;
   //printf("Making sure COMPCOUNT is 0: %d\n", COMPCOUNT); checked
    mergeSort(rand_input, 0, n-1);
    end = clock();
    printf("\nRandom Case Comparisons: %d\n", COMPCOUNT);
    printf("Time taken: %f\n", (double)(end - start) / CLOCKS_PER_SEC);
    printf("\n");
    printf("\n");

// heap sort
    printf("Heap Sort:\n");
    printf("Sorted Case: \n");
    printf("Making sure it is sorted case:\n");
    printArray(best_case_input, n);
    start = clock();
    COMPCOUNT = 0;
    heapSort(best_case_input, n);
    end = clock();
    printf("\nSorted Case Comparisons: %d\n", COMPCOUNT);
    printf("Time taken: %f\n", (double)(end - start) / CLOCKS_PER_SEC);
    printf("\n");
    printf("Reversed Case: \n");
    printf("Making sure it is Reversed Case:\n");
    printArray(worst_case_input, n);
    start = clock();
    COMPCOUNT = 0;
    heapSort(worst_case_input, n);
    end = clock();
    printf("\nReversed Case Comparisons: %d\n", COMPCOUNT);
    printf("Time taken: %f\n", (double)(end - start) / CLOCKS_PER_SEC);
    printf("\n");
    printf("Random Case: \n");
    printf("Making sure it is Random Case:\n");
    printArray(rand_input, n);
    start = clock();
    COMPCOUNT = 0;
    heapSort(rand_input, n);
    end = clock();
    printf("\nRandom Case Comparisons: %d\n", COMPCOUNT);
    printf("Time taken: %f\n", (double)(end - start) / CLOCKS_PER_SEC);
    printf("\n");
    printf("\n");
    
    //quick sort
    printf("Quick Sort:\n");
    printf("Sorted Case: \n");
    printf("Making sure it is sorted case:\n");
    printArray(best_case_input, n);
    start = clock();
    COMPCOUNT = 0;
    quickSort(best_case_input, 0, n-1);
    end = clock();
    printf("\nSorted Case Comparisons: %d\n", COMPCOUNT);
    printf("Time taken: %f\n", (double)(end - start) / CLOCKS_PER_SEC);
    printf("\n");
    printf("Reversed Case: \n");
    printf("Making sure it is Reversed Case:\n");
    printArray(worst_case_input, n);
    start = clock();
    COMPCOUNT = 0;
    quickSort(worst_case_input, 0, n-1);
    end = clock();
    printf("\nReversed Case Comparisons: %d\n", COMPCOUNT);
    printf("Time taken: %f\n", (double)(end - start) / CLOCKS_PER_SEC);
    printf("\n");
    printf("Random Case: \n");
    printf("Making sure it is Random Case:\n");
    printArray(rand_input, n);
    start = clock();
    COMPCOUNT = 0;
    quickSort(rand_input, 0, n-1);
    end = clock();
    printf("\nRandom Case Comparisons: %d\n", COMPCOUNT);
    printf("Time taken: %f\n", (double)(end - start) / CLOCKS_PER_SEC);
    printf("\n");
    printf("\n");

    //part 2

    int n1 = (int)(pow(2, 10));
    int n2 = (int)(pow(2, 15));
    int n3 = (int)(pow(2, 20));
    //double checking powers
   // printf("n1: %d\n", n1);
   // printf("n2: %d\n", n2);
   // printf("n3: %d\n", n3);

    //int best_case_input1[n1];
    //int worst_case_input1[n1];
    //int rand_input1[n1];

   // int best_case_input2[n2];
   // int worst_case_input2[n2];
//int rand_input2[n2];

   // int best_case_input3[n3]; //getting a segmentation fault here
    // research says not enough memory let's try to allocate more
   // int worst_case_input3[n3];
    //int rand_input3[n3];

int *best_case_input1 = (int *)malloc(n1 * sizeof(int));
int *worst_case_input1 = (int *)malloc(n1 * sizeof(int));
int *rand_input1 = (int *)malloc(n1 * sizeof(int));

int *best_case_input2 = (int *)malloc(n2 * sizeof(int));
int *worst_case_input2 = (int *)malloc(n2 * sizeof(int));
int *rand_input2 = (int *)malloc(n2 * sizeof(int));

int *best_case_input3 = (int *)malloc(n3 * sizeof(int));
int *worst_case_input3 = (int *)malloc(n3 * sizeof(int));
int *rand_input3 = (int *)malloc(n3 * sizeof(int));

    // sort sorted input

     for (int i = 0; i < n1; i++) {
        best_case_input1[i] = i + 1;
        //printf("%d ", best_case_input1[i]);
    }

    //sort reversed input

    for (int i = 0; i < n1; i++) {
        worst_case_input1[i] = n1 - i;
    }

    // sort random input

    for (int i = 0; i < n1; i++) {
        rand_input1[i] = rand() % 100;
    }

    // sort sorted input

     for (int i = 0; i < n2; i++) {
        best_case_input2[i] = i + 1;
    }

    //sort reversed input

    for (int i = 0; i < n2; i++) {
        worst_case_input2[i] = n2 - i;
    }

    // sort random input

    for (int i = 0; i < n2; i++) {
        rand_input2[i] = rand() % 100;
    }

    // sort sorted input

     for (int i = 0; i < n3; i++) {
        best_case_input3[i] = i + 1;
    }

    //sort reversed input

    for (int i = 0; i < n3; i++) {
        worst_case_input3[i] = n3 - i;
    }

    // sort random input

    for (int i = 0; i < n3; i++) {
        rand_input3[i] = rand() % 100;
    }

    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");

    printf("Sorted Case 2^10:\n");
    start = clock();
    COMPCOUNT = 0;
    mergeSort(best_case_input1, 0, n1-1);
    end = clock();
    printf("Merge Sort Comparisons: %d\n", COMPCOUNT);
    printf("Merge Sort Time taken: %f\n", (double)(end - start) / CLOCKS_PER_SEC);
    start = clock();
    COMPCOUNT = 0;
    heapSort(best_case_input1, n1);
    end = clock();
    printf("Heap Sort Comparisons: %d\n", COMPCOUNT);
    printf("Heap Sort Time taken: %f\n", (double)(end - start) / CLOCKS_PER_SEC);
    start = clock();
    COMPCOUNT = 0;
    quickSort(best_case_input1, 0, n1-1);
    end = clock();
    printf("Quick Sort Comparisons: %d\n", COMPCOUNT);
    printf("Quick Sort Time taken: %f\n", (double)(end - start) / CLOCKS_PER_SEC);
    printf("\n");

    printf("Sorted Case 2^15:\n");
    start = clock();
    COMPCOUNT = 0;
    mergeSort(best_case_input2, 0, n2-1);
    end = clock();
    printf("Merge Sort Comparisons: %d\n", COMPCOUNT);
    printf("Merge Sort Time taken: %f\n", (double)(end - start) / CLOCKS_PER_SEC);
    start = clock();
    COMPCOUNT = 0;
    heapSort(best_case_input2, n2);
    end = clock();
    printf("Heap Sort Comparisons: %d\n", COMPCOUNT);
    printf("Heap Sort Time taken: %f\n", (double)(end - start) / CLOCKS_PER_SEC);
    start = clock();
    COMPCOUNT = 0;
    quickSort(best_case_input2, 0, n2-1);
    end = clock();
    printf("Quick Sort Comparisons: %d\n", COMPCOUNT);
    printf("Quick Sort Time taken: %f\n", (double)(end - start) / CLOCKS_PER_SEC);
    printf("\n");

    printf("Sorted Case 2^20:\n");
    start = clock();
    COMPCOUNT = 0;
    mergeSort(best_case_input3, 0, n3-1);
    end = clock();
    printf("Merge Sort Comparisons: %d\n", COMPCOUNT);
    printf("Merge Sort Time taken: %f\n", (double)(end - start) / CLOCKS_PER_SEC);
    start = clock();
    COMPCOUNT = 0;
    heapSort(best_case_input3, n3);
    end = clock();
    printf("Heap Sort Comparisons: %d\n", COMPCOUNT);
    printf("Heap Sort Time taken: %f\n", (double)(end - start) / CLOCKS_PER_SEC);
   
    printf("Sorted Reverse Case 2^10:\n");
    start = clock();
    COMPCOUNT = 0;
    mergeSort(worst_case_input1, 0, n1-1);
    end = clock();
    printf("Merge Sort Comparisons: %d\n", COMPCOUNT);
    printf("Merge Sort Time taken: %f\n", (double)(end - start) / CLOCKS_PER_SEC);
    start = clock();
    COMPCOUNT = 0;
    heapSort(worst_case_input1, n1);
    end = clock();
    printf("Heap Sort Comparisons: %d\n", COMPCOUNT);
    printf("Heap Sort Time taken: %f\n", (double)(end - start) / CLOCKS_PER_SEC);
    start = clock();
    COMPCOUNT = 0;
    quickSort(worst_case_input1, 0, n1-1);
    end = clock();
    printf("Quick Sort Comparisons: %d\n", COMPCOUNT);
    printf("Quick Sort Time taken: %f\n", (double)(end - start) / CLOCKS_PER_SEC);
    printf("\n");

    printf("Sorted Reverse Case 2^15:\n");
     start = clock();
    COMPCOUNT = 0;
    mergeSort(worst_case_input2, 0, n2-1);
    end = clock();
    printf("Merge Sort Comparisons: %d\n", COMPCOUNT);
    printf("Merge Sort Time taken: %f\n", (double)(end - start) / CLOCKS_PER_SEC);
    start = clock();
    COMPCOUNT = 0;
    heapSort(worst_case_input2, n2);
    end = clock();
    printf("Heap Sort Comparisons: %d\n", COMPCOUNT);
    printf("Heap Sort Time taken: %f\n", (double)(end - start) / CLOCKS_PER_SEC);
    start = clock();
    COMPCOUNT = 0;
    quickSort(worst_case_input2, 0, n2-1);
    end = clock();
    printf("Quick Sort Comparisons: %d\n", COMPCOUNT);
    printf("Quick Sort Time taken: %f\n", (double)(end - start) / CLOCKS_PER_SEC);
    printf("\n");

    printf("Sorted reverse Case 2^20:\n");
    start = clock();
    COMPCOUNT = 0;
    mergeSort(worst_case_input3, 0, n3-1);
    end = clock();
    printf("Merge Sort Comparisons: %d\n", COMPCOUNT);
    printf("Merge Sort Time taken: %f\n", (double)(end - start) / CLOCKS_PER_SEC);
    start = clock();
    COMPCOUNT = 0;
    heapSort(worst_case_input3, n3);
    end = clock();
    printf("Heap Sort Comparisons: %d\n", COMPCOUNT);
    printf("Heap Sort Time taken: %f\n", (double)(end - start) / CLOCKS_PER_SEC);
    

    printf("Sorted Random Case 2^10:\n");
    start = clock();
    COMPCOUNT = 0;
    mergeSort(rand_input1, 0, n1-1);
    end = clock();
    printf("Merge Sort Comparisons: %d\n", COMPCOUNT);
    printf("Merge Sort Time taken: %f\n", (double)(end - start) / CLOCKS_PER_SEC);
    start = clock();
    COMPCOUNT = 0;
    heapSort(rand_input1, n1);
    end = clock();
    printf("Heap Sort Comparisons: %d\n", COMPCOUNT);
    printf("Heap Sort Time taken: %f\n", (double)(end - start) / CLOCKS_PER_SEC);
    start = clock();
    COMPCOUNT = 0;
    quickSort(rand_input1, 0, n1-1);
    end = clock();
    printf("Quick Sort Comparisons: %d\n", COMPCOUNT);
    printf("Quick Sort Time taken: %f\n", (double)(end - start) / CLOCKS_PER_SEC);
    printf("\n");

    printf("Sorted Random Case 2^15:\n");
      start = clock();
    COMPCOUNT = 0;
    mergeSort(rand_input2, 0, n2-1);
    end = clock();
    printf("Merge Sort Comparisons: %d\n", COMPCOUNT);
    printf("Merge Sort Time taken: %f\n", (double)(end - start) / CLOCKS_PER_SEC);
    start = clock();
    COMPCOUNT = 0;
    heapSort(rand_input2, n2);
    end = clock();
    printf("Heap Sort Comparisons: %d\n", COMPCOUNT);
    printf("Heap Sort Time taken: %f\n", (double)(end - start) / CLOCKS_PER_SEC);
    start = clock();
    COMPCOUNT = 0;
    quickSort(rand_input2, 0, n2-1);
    end = clock();
    printf("Quick Sort Comparisons: %d\n", COMPCOUNT);
    printf("Quick Sort Time taken: %f\n", (double)(end - start) / CLOCKS_PER_SEC);
    printf("\n");


    printf("Sorted reverse Case 2^20:\n");
    start = clock();
    COMPCOUNT = 0;
    mergeSort(rand_input3, 0, n3-1);
    end = clock();
    printf("Merge Sort Comparisons: %d\n", COMPCOUNT);
    printf("Merge Sort Time taken: %f\n", (double)(end - start) / CLOCKS_PER_SEC);
    start = clock();
    COMPCOUNT = 0;
    heapSort(rand_input3, n3);
    end = clock();
    printf("Heap Sort Comparisons: %d\n", COMPCOUNT);
    printf("Heap Sort Time taken: %f\n", (double)(end - start) / CLOCKS_PER_SEC);

    printf("Quick Sort 2^20 Comparisons:\n");
    printf("Sorted Case\n");
     start = clock();
    COMPCOUNT = 0;
    quickSort(best_case_input3, 0, n3-1);
    end = clock();
    printf("Quick Sort Comparisons: %d\n", COMPCOUNT);
    printf("Quick Sort Time taken: %f\n", (double)(end - start) / CLOCKS_PER_SEC);
    printf("\n");

    printf("Reverse Case\n");
    start = clock();
    COMPCOUNT = 0;
    quickSort(worst_case_input3, 0, n3-1);
    end = clock();
    printf("Quick Sort Comparisons: %d\n", COMPCOUNT);
    printf("Quick Sort Time taken: %f\n", (double)(end - start) / CLOCKS_PER_SEC);
    printf("\n");
    printf("Random Case");
    start = clock();
    COMPCOUNT = 0;
    quickSort(rand_input3, 0, n3-1);
    end = clock();
    printf("Quick Sort Comparisons: %d\n", COMPCOUNT);
    printf("Quick Sort Time taken: %f\n", (double)(end - start) / CLOCKS_PER_SEC);
    printf("\n");






    free(best_case_input1);
    free(worst_case_input1);
    free(rand_input1);

    free(best_case_input2);
    free(worst_case_input2);
    free(rand_input2);

    free(best_case_input3);
    free(worst_case_input3);
    free(rand_input3);


return 0;
}