//
//  main.c
//  problem2
//
//  Created by Susan Wang on 10/8/17.
//  Copyright © 2017 Suqian Wang. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// a structure of type "Record"
typedef struct {
    int id;
    int credit;
    float gpa;
} Record;

// compare function for qsort argument
int cmpfunc_credit(const void* a, const void* b) {
    int l = ((Record *)a)->credit;
    int r = ((Record *)b)->credit;
    return (r - l);
}

int cmpfunc_gpa(const void* a, const void* b) {
    float l = ((Record *)a)->gpa;
    float r = ((Record *)b)->gpa;
    float diff = r - l;
    if (diff < 0) {
        return -1;
    }
    else if (diff > 0) {
        return 1;
    }
    else {
        return 0;
    }
}

// split the line string and save to corresponding category
Record split_string(char* line_ptr) {
    Record record;
    const char s[2] = " ";
    record.id = atoi(strtok(line_ptr, s));
    record.credit = atoi(strtok(NULL, s));
    record.gpa = atof(strtok(NULL, s));
    return record;
}

int main() {
    // file stream for input file
    FILE *in_file = NULL;
    in_file = fopen("input2.txt", "r");
    if (in_file == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }
    
    // read line by line from file and stored records in an array
    char line[30];
    char *first_line = fgets(line, sizeof(line), in_file);
    int num_record = atoi(first_line);
    Record record_array[num_record];
    
    for (int i = 0; i < num_record; i++) {
        record_array[i] = split_string(fgets(line, sizeof(line), in_file));
    }
    
    // sort records in desending order by credit or gpa
    char *flag = fgets(line, sizeof(line), in_file);
    
    fclose(in_file);
    
    if (*flag == 'C') {
        qsort(record_array, num_record, sizeof(Record), cmpfunc_credit);
    }
    if (*flag == 'G') {
        qsort(record_array, num_record, sizeof(Record), cmpfunc_gpa);
    }
    
    // file stream for output file
    FILE *out_file = NULL;
    out_file = fopen("output2.txt", "w");
    if (out_file == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }
    
    // wrtie sorted record to the output file
    for (int i = 0; i < num_record; i++) {
        fprintf(out_file, "%d %d %f\n", record_array[i].id, record_array[i].credit, record_array[i].gpa);
    }
    fclose(out_file);
    
    return 0;
}


