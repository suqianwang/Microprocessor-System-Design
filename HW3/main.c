//
//  main.c
//  ECEN449-HW3-P4
//
//  Created by Susan Wang on 11/14/17.
//  Copyright © 2017 Suqian Wang. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int main() {
    // open an input file for read
    FILE *in_file = NULL;
    in_file = fopen("input4.txt", "r");
    if (in_file == NULL) {
        printf("Error opening file!\n");
        return -1;
    }
    
    // read the first line
    char num_time_slot_c;
    fgets(&num_time_slot_c, 2, in_file);
    
    // read character separated by spaces into integer type and store them in an array
    int buf[100];
    int size = 0;
    int temp;
    while(!feof(in_file)) {
        fscanf(in_file, "%d", &temp);
        buf[size++] = temp;
    }
    
    // count number of 1 in each time slot which is the transmitted values
    int tx_num = size/atoi(&num_time_slot_c);
    int num_time_slot = atoi(&num_time_slot_c);
    int tx[tx_num];
    int count = 0;
    int i, j;
    for (i = 0; i < tx_num; i++) {
        for (j = 0; j < num_time_slot; j++) {
            if(buf[i*num_time_slot + j] == 1) {
                count++;
            }
        }
        tx[i] = count;
        count = 0;
    }
    
    // open an output file to write
    FILE *out_file = NULL;
    out_file = fopen("output4.txt", "w");
    if (out_file == NULL) {
        printf("Error opening file!\n");
        return -1;
    }
    
    // wrtie to each item in the array to the output file
    int k;
    for (k = 0; k < tx_num; k++) {
        fprintf(out_file, "%d\n", tx[k]);
    }
    
    fclose(out_file);
    
    return 0;
}
