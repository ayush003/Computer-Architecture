#include <stdio.h>
#include <time.h>
#define TILE_SIZE 2
#define N 1<<12

int A[N][N], B[N][N], C[N][N] ;

/******************************************************************************/

double cpu_time ( void )

/******************************************************************************/
/*
  Purpose:

    CPU_TIME returns the current reading on the CPU clock.

  Discussion:

    The CPU time measurements available through this routine are often
    not very accurate.  In some cases, the accuracy is no better than
    a hundredth of a second.  

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    06 June 2005

  Author:

    John Burkardt

  Parameters:

    Output, double CPU_TIME, the current reading of the CPU clock, in seconds.
*/
{
  double value;

  value = ( double ) clock ( ) 
        / ( double ) CLOCKS_PER_SEC;

  return value;
}

main()
{
	int i, j, k, prod_ij,p,o,q;
	double time[3], start, stop;

	/* Initialize the matrices */

	start = cpu_time();

	for(i=0; i<N; ++i){
		for(j=0; j<N; ++j){
			A[i][j]=i-j;
			B[i][j]=i+j;
		}
	}

	stop = cpu_time();

	time[0] = stop - start;

	/* Naive Matrix Multiplication. 
	   Improve the performance of this code
	    */
	start = cpu_time();

	for(i=0; i<N; ++i){
		for(j=0; j<N; ++j){
			C[i][j] = 0;
			for(k=0; k<N; ++k){
				C[i][j] += A[i][k]*B[k][j];
			}
		}
	}
	
	stop = cpu_time();

	time[1] = stop - start;


	start = cpu_time();

	/* Your Matrix Multiplication Code */

	
	for(i=0;i<N;i+=TILE_SIZE)
	{
		for(j=0;j<N;j+=TILE_SIZE)
		{
			for(q=0;q<TILE_SIZE;q++)
			{
				for(p=0;p<TILE_SIZE;p++)
				{
					C[i+q][j+p]=0;
				}
			}
			for(k=0;k<N;k+=TILE_SIZE)
			{
				for(q=0;q<TILE_SIZE;q++)
				{
					for(p=0;p<TILE_SIZE;p++)
					{
						for(o=0;o<TILE_SIZE;o++)
						{
							C[i+q][j+p]+=A[i+q][o+k]*B[k+o][j+p];
						}
					}
				}
			}
		}
	}


	for(i=0; i<N; ++i){
		for(j=0; j<N; ++j){
			prod_ij = 0;
			for(k=0; k<N; ++k){
				prod_ij += A[i][k]*B[k][j];
			}
			if (prod_ij != C[i][j]){
				printf("Error in computing C[%d,%d]\n", i, j);
				goto exit;
			}
		}
	}

	
exit:

	stop = cpu_time();

	time[2] = stop - start;

	printf("Matrix Initialization Time: %9f\n", time[0]);
	printf("Your Matrix Multiplication Time: %9f\n", time[1]);
	printf("Naive Matrix Multiplication Time: %9f\n", time[2]);
	printf("Your code speedup when compared with Naive method: %1.2fx\n", time[2]/time[1]);
}