//
//  EDF.c
//  HW4
//
//  Created by Susan Wang on 11/29/17.
//  Copyright © 2017 Suqian Wang. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#define NUM_TASK_PARA 2

int countTask() {
    FILE *fp;
    int count = 0;
    char c;
    
    fp = fopen("input.txt", "r");
    if(fp == NULL) {
        printf("Error opening file\n");
        return -1;
    }
    
    for (c = getc(fp); c!= EOF; c = getc(fp)) {
        if (c == '\n'){
            count++;
        }
    }
    fclose(fp);
    
    printf("number of lines in the file is %d\n", count);
    return count;
}

int* readFile(int line, int num_line, int* line_arr) {
    FILE *fp;
    int count;
    
    fp = fopen("input.txt", "r");
    if(fp == NULL) {
        printf("Error opening file!\n");
        return NULL;
    }
    
    for(count = 0; count < num_line; count++) {
        char line_str[100];
        fgets(line_str, 100, fp);
        if(count == line-1) {
            line_arr[0] = atoi(line_str);
            line_arr[1] = atoi(line_str+NUM_TASK_PARA);
            break;
        }
    }
    fclose(fp);
    
    return line_arr;
}

int gcd(int a, int b)
{
    if (b==0)
        return a;
    return gcd(b, a%b);
}

int findlcm(int arr[], int n)
{
    // Initialize result
    int ans = arr[0];
    
    // ans contains LCM of arr[0],..arr[i]
    // after i'th iteration,
    for (int i=1; i<n; i++)
        ans = ( ((arr[i]*ans)) /
               (gcd(arr[i], ans)) );
    
    return ans;
}

int edf(int* period, int n, int t, int* deadline) {
    int i, small = 10000;
    int smallindex = 0;
    for (i = 0; i < n; i++) {
        if(period[i] < small && (period[i]-t) <= deadline[i]) {
            small = period[i];
            smallindex = i;
        }
    }
    if (small == 10000) {
        return -1;
    }
    return smallindex;
}

int main() {
    // count number of lines in the file, which is the number of tasks
    int num_task = countTask();
    int *arr = (int*)malloc(num_task * NUM_TASK_PARA * sizeof(int));
    int *line_arr = (int*)malloc(NUM_TASK_PARA * sizeof(int));
    int *period = (int*)malloc(num_task * sizeof(int));
    int *exec = (int*)malloc(num_task * sizeof(int));
    
    int i, j = 0;
    for (i = 0; i < num_task; i++) {
        for (j = 0; j < NUM_TASK_PARA; j++) {
            *(arr + i*NUM_TASK_PARA + j) = *(readFile(i+1, num_task, line_arr)+j);
        }
    }
    
    for (i = 0; i < num_task; i++) {
        *(period + i) = *(arr + i*NUM_TASK_PARA);
        *(exec + i) = *(arr + i*NUM_TASK_PARA + 1);
    }
    int hyperperiod = findlcm(period, num_task);
    
    
    
    return 0;
}


