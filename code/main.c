/**
 * Purpose: 将一个数组（10个值）中的每个值（小于1000）的相邻值的和构建新的数组，然后将新数组的值逆序重新存放
 * Name: main.c
 * @author: Colson Zhang
 * @date: Nov 05, 2020
 * @version: 1.0.0
 */

#include <stdio.h>

#define MAX_NUM 10
#define PRINT 1

int main() {

    /* storage array */
    int numbers[10] = {1,2,3,4,5,6,7,8,9,10};
    int numbers_new[10] = {0,0,0,0,0,0,0,0,0,0};

    /* useful temporary variables */
    int index = 0 ;
    int index_2 = 0 ;
    int index_max = 0 ;
    int term = 0 ;

    #ifdef PRINT
        for (index = 0 ; index < MAX_NUM ; index++){
            printf("%d\t",numbers[index]);
        }
        printf("\n");    
    #endif 

    /* To generate the new array */
    for (index = 0 ; index < MAX_NUM ; index++){
        if (index == 0) {
            numbers_new[index] = numbers[index + 1] ;
        }
        else if (index == MAX_NUM-1)
        {
            numbers_new[index] = numbers[index - 1] ;
        }
        else
        {
            numbers_new[index] = numbers[index - 1] + numbers[index + 1] ;
        }
    }

    #ifdef PRINT
        for (index = 0 ; index < MAX_NUM ; index++){
            printf("%d\t",numbers_new[index]);
        }
        printf("\n");
    #endif 

    /* To sort the new array by reverse order */
    for (index = 0 ; index < MAX_NUM - 1 ; index++){
        index_max = index ;
        for( index_2 = index + 1; index_2 < MAX_NUM ; index_2++ ){
            if( numbers_new[index_2] > numbers_new[index_max] ){
                index_max = index_2 ;
            }
        }
        if(index_max != index){
            term = numbers_new[index] ;
            numbers_new[index] = numbers_new[index_max] ;
            numbers_new[index_max] = term ;
        }    
    }

    #ifdef PRINT
        for (index = 0 ; index < MAX_NUM ; index++){
            printf("%d\t",numbers_new[index]);
        }
        printf("\n");
    #endif

    return 0;
}