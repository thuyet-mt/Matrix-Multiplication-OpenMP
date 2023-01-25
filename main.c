#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <math.h>
#include<time.h>
#define m 20 // size of the array
#define n 20 // size of the array
#define p 20 // size of the array
double ohd1[m][n];
double ohd2[n][p];
void init1 ( double ohd[m][n] )
{
    int i, j;
    // Open the file for reading
    FILE *fp = fopen("array_1st.txt", "r");
    if (fp == NULL)
    {
        perror("Error opening file");
    }
    // Read the values from the file into the matrix
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            fscanf(fp, "%lf", &ohd[i][j]);
        }
    }
    // Close the file
    fclose(fp);
}
void init2 ( double ohd[n][p] )
{
    int i, j;
    // Open the file for reading
    FILE *fp = fopen("array_2nd.txt", "r");
    if (fp == NULL)
    {
        perror("Error opening file");
    }
    // Read the values from the file into the matrix
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < p; j++)
        {
            fscanf(fp, "%lf", &ohd[i][j]);
        }
    }
    // Close the file
    fclose(fp);
}
int main(void){
	clock_t start, end;
	int nrOfThreads;
	init1(ohd1);
	init2(ohd2);
	printf("Program to calculate Matrix Multiplication\n");
	printf("Number of threads: ");
	scanf("%d",&nrOfThreads);
	double result[m][p];
	for(int i=0;i<m;i++){
		for(int j=0;j<p;j++){
			result[j][i]=0;
		}
		printf("\n");
	}
	int i,j,k;
	start = clock();
	#pragma omp parallel for num_threads(nrOfThreads/2) private(j,k)
	for (i = 0; i < m; i++ )
	{
		#pragma omp parallel for num_threads(2) private(k)
		for(j=0;j<p;j++){
			for(k=0;k<n;k++){
				#pragma omp critical
				result[j][i] += ohd1[k][i]*ohd2[j][k];
			}
		}
	}
	end = clock();
	double time_use = (double)(end - start) / CLOCKS_PER_SEC;
  	fprintf(stdout, "\n/******************************************************************************/\n");
  	fprintf(stdout, "/***************      Time execution: %f   ******************************/", time_use);
  	fprintf(stdout, "\n/******************************************************************************/\n");

    printf("Result of multiplication:\n");
    for(int i=0;i<m;i++){
		for(int j=0;j<p;j++){
			printf("%lf ",result[j][i]);
		}
		printf("\n");
	}

    return 0;
}
