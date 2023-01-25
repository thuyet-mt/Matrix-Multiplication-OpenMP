#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define m 2000 // size of the array
#define n 2000 // size of the array
#define p 2000 // size of the array
double ohd1[m][n];
double ohd2[n][p];
void init1(double ohd[m][n]);
void init2(double ohd[n][p]);

int main(){
    init1(ohd1);
    init2(ohd2);
    int i, j;

    // print the 1st array to the console
    printf("First array: \n");
    for (i = 0; i < m; i++){
        for(j = 0; j < n; j++){
            fprintf(stdout, "%lf\t", ohd1[i][j]);
            if (j == (n - 1)){
                fprintf(stdout, "\n");
            }
        }
    }
    printf("\n\\\\\\\\\\\\\\\\\\\ \n");
    printf("Second array: \n");
    for (i = 0; i < n; i++){
        for(j = 0; j < p; j++){
            fprintf(stdout, "%lf\t", ohd2[i][j]);
            if (j == (p - 1)){
                fprintf(stdout, "\n");
            }
        }
    }
    // open a file for writing
    FILE *fp1, *fp2;
    fp1 = fopen("array_1st.txt", "w");
    fp2 = fopen("array_2nd.txt", "w");
    // write the array to the file show for teacher
    for (i = 0; i < m; i++){
        for(j = 0; j < n; j++){
            fprintf(fp1, "%lf\t", ohd1[i][j]);
            if (j == (n - 1)){
                fprintf(fp1, "\n");
            }
        }
    }
    for (i = 0; i < n; i++){
        for(j = 0; j <p ; j++){
            fprintf(fp2, "%lf\t", ohd2[i][j]);
            if (j == (p - 1)){
                fprintf(fp2, "\n");
            }
        }
    }
    // close the file
    fclose(fp1);
    fclose(fp2);
    return 0;
}


void init1(double ohd[m][n])
{
    int i;
    int j;

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            ohd[i][j] = rand()%100;
        }
    }
}
void init2(double ohd[n][p])
{
    int i;
    int j;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < p; j++)
        {
            ohd[i][j] = rand()%100;
        }
    }
}