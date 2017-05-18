/**
 * generate.c
 *
 * Generates pseudorandom numbers in [0,MAX), one per line.
 *
 * Usage: generate n [s]
 *
 * where n is number of pseudorandom numbers to print
 * and s is an optional seed
 */
 
#define _XOPEN_SOURCE

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// upper limit on range of integers that can be generated
#define LIMIT 65536

int main(int argc, string argv[])
{
    // If the user does not run this program with 1 or 2 command line arguments, exit with error
    if (argc != 2 && argc != 3)
    {
        printf("Usage: ./generate n [s]\n");
        return 1;
    }

    // Convert the command-line string argument n into an integer
    int n = atoi(argv[1]);

    // If the user provides a seed at the command-line, [s], pass that into srand48 (which it will store in an internal 32-bit buffer for later use)
    // Otherwise, use the lower 32 bits of the current time (since Epoch, which is what time() returns)
    if (argc == 3)
    {
        srand48((long) atoi(argv[2]));
    }
    else
    {
        srand48((long) time(NULL));
    }

    // First command-line argument, n,  specifies how many p-rand numbers to print, so iterate over n calling drand48() (which uses the internal 32-bit buffer set by srand48 referenced earlier)
    // Also, drand48() returns a number between [0.0,1.0), so we need to multiply that by our predefined LIMIT and cast it as an integer
    for (int i = 0; i < n; i++)
    {
        printf("%i\n", (int) (drand48() * LIMIT));
    }

    // success
    return 0;
}
