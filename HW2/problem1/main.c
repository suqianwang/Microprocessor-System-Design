//
//  main.c
//  problem1
//
//  Created by Susan Wang on 10/8/17.
//  Copyright © 2017 Suqian Wang. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int cmpfunc(const void* a, const void* b) {
    return ( *(int*)b - *(int*)a );
}

int main() {
    // file stream for input file
    FILE *in_file = NULL;
    in_file = fopen("input1.txt", "r");
    if (in_file == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }
    
    // read line by line from file and stored in an integer array
    int i = 0;
    char line[5];
    int number_array[10];
    while (fgets(line, sizeof(line), in_file) != NULL) {
        number_array[i] = atoi(line);
        i++;
    }
    fclose(in_file);
    
    // sort numbers in array in desending order
    int n_item = i;
    qsort(number_array, n_item, sizeof(int), cmpfunc);
    
    // file stream for output file
    FILE *out_file = NULL;
    out_file = fopen("output1.txt", "w");
    if (out_file == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }
    
    // wrtie to each item in the array to the output file
    for (int i = 0; i < n_item; i++) {
        fprintf(out_file, "%d\n", number_array[i]);
    }
    fclose(out_file);
    
    return 0;
}
