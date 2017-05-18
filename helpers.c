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
    if(n<=0)
    {
        return false;
    }
    
    int newhaystack[n/2];
    
    if(values[n/2]==value)
    {
        printf("test\n");
        return true;
    }
    else if(values[n/2]>value && n>1)
    {
        int i;
        for (i=0;i<n/2;i++)
        {
            newhaystack[i]=values[i];
        }
        search(value,newhaystack,i);
    }
    else if(values[n/2]<value && n>1)
    {
        int mid=n/2+1;
        int i;
        for (i=0;i<n/2-1;i++)
        {
            newhaystack[i]=values[mid];
            mid++;
        }
        search(value,newhaystack,i);
    }
    
    return false;
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
