#include<iostream>
using namespace std;


int main(){
    int row_mat1,column_mat1,row_mat2,column_mat2;

    //Taking input for matrix 1
    cout<<"Enter the number of rows in matrix 1:";
    cin>>row_mat1;
    cout<<"Enter the number of columns in matrix 1:";
    cin>>column_mat1;
    int matrix1[row_mat1][column_mat1];
    cout<<"Ente the matrix 1: "<<endl;
    for(int i=0;i<row_mat1;i++){
        for(int j=0;j<column_mat1;j++){
            cout<<"at position ["<<i<<"]["<<j<<"] : ";
            cin>>matrix1[i][j];
        }
    }

    //Taking input for matrix 2
    cout<<"Enter the number of rows in matrix 2:";
    cin>>row_mat2;
    cout<<"Enter the number of columns in matrix 2:";
    cin>>column_mat2;
    int matrix2[row_mat2][column_mat2];
    cout<<"Ente the matrix 2: "<<endl;
    for(int i=0;i<row_mat2;i++){
        for(int j=0;j<column_mat2;j++){
            cout<<"at position ["<<i<<"]["<<j<<"] : ";
            cin>>matrix2[i][j];
        }
    }
    
    int matrix3[row_mat1][column_mat2];  //new matrix

    //matrix multiplication
   // cout<<"After multiplication matrix is : "<<endl;
    for(int i=0;i<row_mat1;i++){
        for(int j=0;j<column_mat2;j++){
            matrix3[i][j]=0;
            for(int k=0;k<row_mat2;k++){
                matrix3[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    //printing the new matrix
    cout<<"After multiplication matrix is : "<<endl;
    for(int i=0;i<row_mat1;i++){
        for(int j=0;j<column_mat2;j++){
            cout<<matrix3[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}

/* ...........................OUTPUT..............................

Enter the number of rows in matrix 1:2
Enter the number of columns in matrix 1:3
Ente the matrix 1: 
at position [0][0] : 1
at position [0][1] : 2
at position [0][2] : 3
at position [1][0] : 4
at position [1][1] : 5
at position [1][2] : 6

Enter the number of rows in matrix 2:3
Enter the number of columns in matrix 2:2
Ente the matrix 2:
at position [0][0] : 10
at position [0][1] : 11
at position [1][0] : 20
at position [1][1] : 21
at position [2][0] : 30
at position [2][1] : 31

After multiplication matrix is :
140 146
320 335

*/