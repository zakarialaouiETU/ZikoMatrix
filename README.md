## Initialize
``` C++
 // 1 
 int arr[2][3] = {{1, 2, 3}, {4, 5, 6}};
 Matrix<2,3,int> M1(arr);
 // 2
 int arr[] = {1.6, 2.2, 3.9 , 4.7, 5.3, 6.8};
 Matrix<2,3,float> M2(arr);
 // 3
 Matrix<5,5,int> // A 5x5 Matrix filled by zeros
```
## Print to the terminal 
``` C++
  M1.print();
```
## Acces And Set Data
|Mehode|Acces|Set|
|-|--|--|
|1|`M[i][j]`|`M[i][j]=4`|
|2|`M(i,j)`|`M(i,j)=4`|
## Static Methodes 
``` C++
  int r=2,c=3;
  Matrix<r, c> Z = Matrix<r, c>::Zeros();
  Matrix<r, c> O = Matrix<r, c>::Ones();
  Matrix<3> Id = Matrix<3>::Id();
  Matrix<4,5> Nums = Matrix<4,5,double>::Nums(6.7);
```
## Operators 
  ### List
M1: Matrix
|Operator |Operande|Syntax|
|--|--|--|
|+|M2:Matrix|`Matrix<r,c,type> M3=M1+M2;`|
|+|a:Scalar|`Matrix<r,c,type> M3=M1+a;`|
|-|M2:Matrix|`Matrix<r,c,type> M3=M1-M2;`|
|-|a:Scalar|`Matrix<r,c,type> M3=M1-a;`|
|*|M2:Matrix|`Matrix<r,c,type> M3=M1*M2;`|
|*|a:Scalar|`Matrix<r,c,type> M3=M1*a;`|
|/|a:Scalar|`Matrix<r,c,type> M3=M1/a;`|
|%|a:Integer|`Matrix<r,c,type> M3=M1ùa;`|
|+=|M2:Matrix|`M1+=M2;`|
|+=|a:Scalar|`M1+=a;`|
|-=|M2:Matrix|`M1-=M2;`|
|-=|a:Scalar|`M1-=a;`|
|*=|M2:Matrix|`M1*=M2;`|
|*=|a:Scalar|`M1+=a;`|
|/=|a:Scalar|`M1/=a;`|
|%=|a:Integer|`M1%=a;`|
  ### Examples
``` C++
   int arr1[2][3] = {{1, 2, 3},{4, 5, 6}};
   int arr2[2][3] = {{2, 3, 4},{5, 6, 7}};
   Matrix<2,3,int> M1(arr1);
   Matrix<2,3,int> M2(arr2);
   Matrix<2,3,int> M3=M1+M2;
   Matrix<2,3,int> M4=M1-M2;
   M3+=M3;
   M4-=M3;
```
## Void Methodes 
|Methode|Description|Example|Condition|
|-|--|-|--|
|`.print()`|||-|
|`.det()`|The determinant of the given matrix||should be a square matrix|
|`.transpose()`|Transposes the given matrix |[View](https://github.com/zakarialaoui10/ZikoMatrix/edit/main/examples/Transformation/Transpose/transpose.ino)|-|
|`.reshape(r,c)`|Reshapes the given matrix|[View](https://github.com/zakarialaoui10/ZikoMatrix/blob/main/examples/Reshape/reshape.ino)|The size of the new Matrix should be equal to the old one|
|`.slice(r0,c0,r1,c1)`|Extracts a sub-matrix from the original matrix,|[View](https://github.com/zakarialaoui10/ZikoMatrix/blob/main/examples/Slice/slice.ino)|-|
|`.deleteRow(i)`|Remove a specific row from the original matrix.||-|
|`.deleteCol(j)`|Remove a specific column from the original matrix.||-|
|`.hstack(M)`|Stacks the original matrix vertically with the matrix M||The number of rows in both matrices should be the same,|
|`.vstack(M)`|Stacks the original matrix horizontally with the matrix M||The number of cols in both matrices should be the same,|
|`.foreach(lambda_func)`|Higher-order function that takes a function as an argument and applies it to each element of the Matrix.|[View](https://github.com/zakarialaoui10/ZikoMatrix/blob/main/examples/Foreach/foreach.ino)|-|
|`.clamp(min,max)`|clamp all matrix elements between min and max||-|
|`.lerp(min,max)`|||-|
|`.norm(min,max)`|||-|
|`.map(a1,b1,a2,b2)`|||-|
|`.count(n)`|||-|
## Testers
|Methode|description|
|-|---|
|`isId()`|determines whether a given matrix is identity matrix or not|
|`isSquare()`|determines whether a given matrix is square or not|
|`isSym()`|determines whether a given matrix is symmetric or not|
|`isAntiSym()`|determines whether a given matrix is antisymmetric or not|

# License 
 This projet is licensed under the terms of MIT License </br></br>![MIT](https://img.shields.io/github/license/zakarialaoui10/ZikoMatrix?color=rgb%2820%2C21%2C169%29)
