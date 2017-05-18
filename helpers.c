/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */
 
#include <cs50.h>
#include <string.h>
#include "helpers.h"
#include <stdio.h>

//bool divide_and_conquer(int value, int values[], int n);
/**
 * Returns true if value is in array of n values, else false.
 */

bool search(int value, int values[], int n) // value==needle, values==haystack array, n==(length of values)/2
{
    if(n<=0) // Don't allow negative values
    {
        return false;
    }
    
    int newhaystack[n/2]; // Will create a new list half the size of original
    
    if(values[n/2]==value) // If middle element is the one we want, return true and exit function
    {
        printf("test\n");
        return true;
    }
    else if(values[n/2]>value && n>1) // If middle element is larger, create a new array of the lower half values
    {
        int i;
        for (i=0;i<n/2;i++)
        {
            newhaystack[i]=values[i];
        }
        search(value,newhaystack,i); // Recurse back to this function with the half-sized array
    }
    else if(values[n/2]<value && n>1) // If middle element is smaller, create a new array of the upper half
    {
        int mid=n/2+1;
        int i;
        for (i=0;i<n/2-1;i++)
        {
            newhaystack[i]=values[mid];
            mid++;
        }
        search(value,newhaystack,i); // Recurse back to this function with the half sized array
    }
    
    return false; // If the recursed array gets down to size==1 and no match is found, return false and exit
}


/**
 * Sorts array of n values.
 */
//void sort(int values[], int n)
//{
    // TODO: implement a sorting algorithm
    
//    return;
//}

//bool divide_and_conquer(int value, int values[], int n)
//{
//    if(values[n]==value){
//        return true;
//    }
//    else if(values[n]>value){
//        divide_and_conquer(value,haystack_chop(0,n,values),n/2);
//    }
//    else if(values[n]<value){
//        divide_and_conquer(value,haystack_chop(n,strlen(values)+1,values),n/2);
//    }
//    return false;
//}
