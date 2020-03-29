//
//  main.c
//  March 2020
//
//  Created by MagicMikeM on 2020/3/29.
//  Copyright © 2020 MagicMike. All rights reserved.
//

#include <stdio.h>
void magic_square(int A[4][4])
{
    for (int i=0; i<4; i++)
        for (int j=1; j<=4; j++)
            A[i][j-1]=i*4+j;
    int a;
    a=A[0][0]; A[0][0]=A[3-0][3-0]; A[3-0][3-0]=a;
    a=A[1][1]; A[1][1]=A[3-1][3-1]; A[3-1][3-1]=a;
    a=A[0][3]; A[0][3]=A[3-0][3-3]; A[3-0][3-3]=a;
    a=A[1][2]; A[1][2]=A[3-1][3-2]; A[3-1][3-2]=a;
}

int saddle_point(int m,int n,int A[m][n])
{
    int sum=0;
    for (int i=0; i<m; i++)
    {
        int a=A[i][0];
        for (int j=1; j<n; j++)
            if (A[i][j]<=a)
                a = A[i][j];//先找每行最小值
        for (int j=0; j<n; j++)
        {
            if (A[i][j]==a)
            {//当找到一个最小值时
                int count=0;
                for (int k=0; k<m; k++)
                {//判断是否为鞍点
                    if (A[k][j]<=A[i][j])
                        count++;
                    if (count==m)
                    {//列元素最大值
                        printf("鞍点有(%d,%d)的%d\n",i+1,j+1,a);
                        sum++;//总鞍点数+1
                    }
                }
            }
        }
    }
    return sum;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    printf("GitHub is fk complicated!");
    
    printf("GitHub is:");
    for (int i=1; i<4; i++)
    {
        printf("6");
    }
    
    int A[4][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    int B[5][3]={{4,4,4},{1,1,1},{2,2,6},{3,3,11},{4,4,16}};
    int C[4][3]={{4,4,3},{2,2,6},{2,3,7},{2,4,8}};
    int D[3][4]={{1,2,3,4},{5,6,7,8},{9,9,11,12}};
    int E[4][4]={};
    
    printf("A矩阵：\n");
    for (int i=0; i<=3; i++)
    {
        for (int j=0; j<=3; j++)
            printf("%2d  ",A[i][j]);
        printf("\n");
    }
    printf("A矩阵的对角线元素和为：%d\n",sum(4,A));
    
    
    printf("\nB矩阵：\n");
    for (int i=0; i<=4; i++)
    {
        for (int j=0; j<3; j++)
            printf("%2d  ",B[i][j]);
        printf("\n");
    }
    printf("C矩阵：\n");
    for (int i=0; i<=3; i++)
    {
        for (int j=0; j<3; j++)
            printf("%2d  ",C[i][j]);
        printf("\n");
    }
    add(B,C);
    
    
    printf("\nD矩阵：\n");
    for (int i=0; i<3; i++)
    {
        for (int j=0; j<=3; j++)
            printf("%2d  ",D[i][j]);
        printf("\n");
    }
    max(3, 4, D);
    printf("鞍点数为：%d\n",saddle_point(3, 4, D));
    
    magic_square(E);
    printf("\nE矩阵：\n");
    for (int i=0; i<4; i++)
    {
        for (int j=0; j<4; j++)
            printf("%2d ",E[i][j]);
        printf("\n");
    }

    return 0;
}
