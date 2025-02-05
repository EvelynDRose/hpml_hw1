// OpenMP helloworld example
// compile: gcc -fopenmp hello_threads.c -o hello_threads
// run: OMP_NUM_THREADS=10 ./hello_threads

#include <stdio.h>
#include <omp.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // For loop variables
    int i;
    int j;
    int k;
    int temp;
    int dim = 1000;

    // matrixies
    int a[dim][dim];
    int b[dim][dim];
    int c[dim][dim];

    // Time variables
    time_t start, stop;
	double elapsed; 

    // Initial random setup of matrixies
    for (i = 0; i < dim; i++)
    {
        for (j = 0; j < dim; j++)
	    {
            // random num 1-10
            a[i][j] = rand() % 3 + 1;
            b[i][j] = rand() % 3 + 1;
	    }
    }

    // for (i = 0; i < dim; i++)
    // {
    //     for (j = 0; j < dim; j++)
    //     {
    //         printf("%d\t", a[i][j]);
    //     }
    //     printf("\n");
    // }

   // Calculations
    time(&start);
    omp_set_num_threads(48);
    #pragma omp parallel for private(i,j,k) shared(a,b,c)
        for(i = 0; i < dim; i++)
        {
            for(j = 0; j < dim; j++)
            {
                temp = 0;
                for(k = 0; k < dim; k++)
                {
                    temp += a[i][k] * b[k][j];
                }
                c[i][j] = temp;
            }
        }

    time(&stop);
    printf("time = %f seconds.\n",  difftime(stop, start));

    // for (i = 0; i < dim; i++)
    // {
    //     for (j = 0; j < dim; j++)
    //     {
    //         printf("%d\t", c[i][j]);
    //     }
    //     printf("\n");
    // }
}

    // /*
    //  * create threads each will print "Hello world" and "Goodbye world"
    //  */

    // int dim;
    // dim = 2;

    // // matrix 1
    // int a[dim][dim];
    // a[0][0] = 1;
    // a[0][1] = 2;
    // a[1][0] = 3;
    // a[1][1] = 4;
    // // matrix 2
    // int b[dim][dim];
    // b[0][0] = 2;
    // b[0][1] = 0;
    // b[1][0] = 1;
    // b[1][1] = 2;

    // int c[dim][dim];

    // int i;
    // int j;
    // int k;
    // int temp;

    // omp_set_num_threads(1);
    // #pragma omp parallel for private(i,j,k) shared(a,b,c)
    //     for(i = 0; i < dim; i++)
    //         for(j = 0; j < dim; j++)
    //             temp = 0;
    //             for(k = 0; k < dim; k++)
    //                 temp += a[i][k] * b[k][j];
    //                 printf("%d\t",temp);
    //             c[i][j] = temp;

    // for (int i= 0; i< dim; i++)
    // {
    //     for (int j= 0; j< dim; j++)
    //     {
    //         printf("%d\t",c[i][j]);
    //     }
    //     printf("\n");
    // }

    // return 0;