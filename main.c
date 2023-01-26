#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
void printarray(int **A,int **B,int a,int row,int col);
void max_min_A (int **A, int a, int max, int min);
int transpose_B (int **B, int row, int col, int trow, int tcol, int **T);
int mult_A_B(int**B, int col, int**A, int a, int**M);
int sortA(int **A,int a);
int sort_line(int **A,int a);
int sum_A_B (int **A, int **B, int row, int col, int a);



int main()
{   srand(time(NULL));
    int **A, **B, **T, **M;
    int row,col,trow,tcol,a;
    int i,j;
    int A1,A2,A3,A4;
    int max, min;


/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

    while(1)
    {
    printf("Rows=");
    scanf("%d", &row);
    printf("Cols=");
    scanf("%d", &col);
    trow=col;
    tcol=row;
    printf("Size of matrix A=");
    scanf("%d", &a);
    system("cls");
    printf("Matrix filling method\n1)manually\n2)randomly(from -7 to 41)\n3)formula\n");
    scanf("%d",&A1);
    system("cls");
    while(A1!=1&&A1!=2&&A1!=3)
    {
        printf("Matrix filling method\n1)manually\n2)randomly(from -7 to 41)\n3)formula\n");
        scanf("%d",&A1);
        system("cls");
    }

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

    A = (int**)calloc(a, sizeof(int*));
    if(A == NULL)
    {
        printf("\nERROR!");
        getche();
        exit(1);
    }
    for(i=0;i<a;i++)
    {
            A[i]=(int*)calloc(a,sizeof(int));
                if(A[i] == NULL)
                {
                    printf("\nERROR!");
                    getche();
                    exit(1);
                }
    }

    B = (int**)calloc(row,sizeof(int*));
    if(B == NULL)
    {
        printf("\nERROR!");
        getche();
        exit(1);
    }
    for (int i=0; i<row; i++)
    {
            B[i]=(int *)calloc(col,sizeof(int));
                if(B[i] == NULL)
                {
                    printf("\nERROR!");
                    getche();
                    exit(1);
                }
    }

    T = (int**)calloc(trow, sizeof(int*));
    if(T == NULL)
    {
        printf("\nERROR!");
        getche();
        exit(1);
    }
    for(i=0;i<trow;i++)
    {
            T[i]=(int*)calloc(tcol,sizeof(int));
                if(T[i] == NULL)
                {
                    printf("\nERROR!");
                    getche();
                    exit(1);
                }
    }

    M = (int**)calloc(row, sizeof(int*));
    if(M == NULL)
    {
        printf("\nERROR!");
        getche();
        exit(1);
    }
    for(i=0;i<row;i++)
    {
            M[i]=(int*)calloc(a,sizeof(int));
                if(M[i] == NULL)
                {
                    printf("\nERROR!");
                    getche();
                    exit(1);
                }
    }

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

    if(A1==1)
    {
        for(i=0; i<a; i++)
                for(int j=0;j<a;j++)
                    {
                        printf("A[%d][%d]: ", i, j);
                        scanf("%d", &A[i][j]);
                    }
        for(int i=0; i<row; i++)
            {
                for(int j=0;j<col;j++)
                    {
                        printf("B[%d][%d]: ", i, j);
                        scanf("%d", &B[i][j]);
                    }
            }
    }
    if(A1==2)
    {
        for (int i=0;i<a;i++)
            for (int j=0;j<a;j++)
                A[i][j]=-7+rand()%49;

        for (int i=0;i<row;i++)
            for (int j=0;j<col;j++)
                B[i][j]=-7+rand()%49;
    }
    if(A1==3)
    {
        for (int i=0;i<a;i++)
            for (int j=0;j<a;j++)
                A[i][j]= 7*i+4*j-10;

        for (int i=0;i<row;i++)
            for (int j=0;j<col;j++)
                B[i][j]= 7*i-4*j-10;
    }

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

    printf("1)The max and min values under the main diagonal of matrix A");
    printf("\n2)Matrix T");
    printf("\n3)A*B");
    printf("\n4)Sort from smallest to largest");
    printf("\n5)The sum of the rows of the matrix A and the sum of the columns of the matrix B\n");
    scanf("%d",&A2);
    system("cls");
    while(A2!=1&&A2!=2&&A2!=3&&A2!=4&&A2!=5)
    {
        printf("1)The max and min values under the main diagonal of matrix A");
        printf("\n2)Matrix T");
        printf("\n3)A*B");
        printf("\n4)Sort from smallest to largest");
        printf("\n5)The sum of the rows of the matrix A and the sum of the columns of the matrix B\n");
        scanf("%d",&A2);
        system("cls");
    }

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

    printarray(A,B,a,row,col);


    if(A2==1)
    {
        max_min_A (A,a,max,min);
    }
    if(A2==2)
    {
        transpose_B (B,row,col,trow,tcol,T);
    }
    if(A2==3)
    {
        if(a!=row)
        {
            system("cls");
            printf("\n\t\tERROR");
            exit(0);
        }
        mult_A_B(B,col,A,a,M);
    }

    if(A2==4)
    {
        printf("\n1)Sort matrix A\n2)Sort on line\n");
        scanf("%d",&A4);
        while (A4!=1&&A4!=2)
        {
            printf("1)Sort matrix A\n2)Sort on line\n");
            scanf("%d",&A4);
            system("cls");
        }
    if(A4==1)
        sortA(A,a);
    if(A4==2)
        sort_line(A,a);
    }

    if(A2==5)
    {
        sum_A_B (A, B, row, col, a);
    }


    getche();
    system("cls");
    printf("1)Continue\n2)Exit\n");
    scanf("%d",&A3);
    if(A3==2)
        exit(0);
    if(A3==1)
        system("cls");
}
return 0;
}

/*-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

void printarray(int **A, int **B,int a, int row, int col)
{
    printf("Matrix A:\n");
    for(int i=0; i<a; i++)
        {
            for(int j=0;j<a;j++)
                {
                    printf("%2d ", A[i][j]);
                }
            printf("\n");
        }
    printf("\n");
    printf("Matrix B:\n");
    for(int i=0; i<row; i++)
        {
            for(int j=0;j<col;j++)
                {
                    printf("%2d ", B[i][j]);
                }
            printf("\n");
        }
}

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

void max_min_A (int **A, int a, int max, int min)
{
    max=A[1][0];
    min=A[1][0];
    int i,j,n,m;
    n=1;
    m=0;
    for(i=1;i<a;i++)
            for(j=0;j<i;j++)
                if (A[i][j]>max)
                    {
                        max = A[i][j];
                        n=i;
                        m=j;
                    }
    printf("\n\nmax[%d][%d]=%d\n",n,m,max);
    n=1;
    m=0;
    for(i=1;i<a;i++)
            for(j=0;j<i;j++)
                if (A[i][j]<min)
                    {
                        min = A[i][j];
                        n=i;
                        m=j;
                    }
    printf("min[%d][%d]=%d\n",n,m,min);
}

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

int transpose_B (int **B, int row, int col, int trow, int tcol, int **T)
{
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
                T[j][i] = B[i][j];
    printf("\nMatrix T:\n");
    for (int i=0; i<col; i++)
    {
        for (int j=0; j<row; j++)
                printf("%2d ", T[i][j]);
        printf("\n");
    }
}

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

int mult_A_B(int**B, int col, int**A, int a, int**M)
{
    int i,j,l;
    printf("\nMatrix M:\n");
    for(i=0;i<a;i++)
        for(j=0;j<col;j++)
    {
        M[i][j]=0;
        for(l=0;l<a;l++)
            M[i][j]=M[i][j]+A[i][l]*B[l][j];
    }
    for(i=0;i<a;i++)
    {
        for(j=0;j<col;j++)
            printf("%5d", M[i][j]);
        printf("\n");
    }
}

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

int sortA(int **A,int a)
{
        for (int i=0; i<a; i++)
    {
        for (int j=0; j<a; j++)
        {
        int min=A[i][j];
        int p=i;
        int l=j;
        int h=j;
        for (int k = i; k < a; k++)
            {
                for (h;h<a;h++)
                {
                    if (A[k][h] <min)
                    {
                        min=A[k][h];
                        p=k;
                        l=h;
                    }
                }
            h = 0;
            }
        int temp = A[i][j];
        A[i][j] = A[p][l];
        A[p][l] = temp;
        }
    }
    printf("\nSorted matrix A:\n");
    for (int i=0;i<a;i++)
        {
            for (int j=0;j<a;j++)
                    printf("%2d ", A[i][j]);
            printf("\n");
        }

}

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

int sort_line(int **A,int a)
{
    int line,l,j,temp;
    printf("Line=");
    scanf("%d",&line);
    if(line>=a)
    {
        system("cls");
        printf("\n\t\tERROR");
        exit(0);
    }
    printf("\nSorted on line matrix A:\n");
        for(l=1;l<a;l++)
    {
        for(j=0;j<a-l;j++)
        {
            if(A[line][j]>A[line][j+1])
            {
                temp = A[line][j];
                A[line][j] = A[line][j+1];
                A[line][j+1] = temp;
            }
        }
    }

    for(int j=0;j<a;j++){
        printf("%2d ",A[line][j]);
    }
}

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

int sum_A_B (int **A, int **B, int row, int col, int a)
{
    int sum;
    for(int i=0;i<a;i++)
        {
            sum=0;
            for(int j=0;j<a;j++)
                    sum=sum+A[i][j];
            printf("\nRow-%d\tSUMA=%d",i+1,sum);
        }
    printf("\n");

    for(int j=0;j<col;j++)
    {
        sum=0;
        for(int i=0;i<row;i++)
                sum=sum+B[i][j];
        printf("\nCol-%d\tSUMB=%d",j+1,sum);
    }
    printf("\n");
}
