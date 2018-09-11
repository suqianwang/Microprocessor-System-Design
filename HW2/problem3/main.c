//
//  main.c
//  problem3
//
//  Created by Susan Wang on 10/9/17.
//  Copyright © 2017 Suqian Wang. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(void *p1, void *p2, unsigned int size) {
    // allocate temporary memory
    void *temp = malloc(size);
    // copy size characters from memory area p1 to temporary memory area
    memcpy(temp, p1, size);
    memcpy(p1, p2, size);
    memcpy(p2, temp, size);
    // free allocated temporary memory after done with it
    free(temp);
}

int main() {
    
    int x = 10; int y = 20;
    swap(&x, &y, sizeof(int));
    //x = 20, y = 10 after swap
    printf("x = %d, y = %d\n", x, y);
    
    char a = 'F'; char b = 'G';
    swap(&a, &b, sizeof(char));
    //a = G, b = F after swap
    printf("a = %c, b = %c", a, b);
    
    return 0;
}

