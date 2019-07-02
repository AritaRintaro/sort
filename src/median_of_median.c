#include <stdio.h>

// 素数
#define N 2999

int A[N];

// *p と *q の値を入れ替える関数
void swap(int *p, int *q){
  int tmp;
  tmp = *p;
  *p = *q;
  *q = tmp;
}


int median_of_median(int A[], int n);


int quick_select(int A[], int n, int k){
  int i, j, pivot;

// 真ん中の要素をピボットとする
 pivot = A[n/2];
 A[n/2] = A[0];
A[0] = pivot;


  for(i = j = 1; i < n; i++){
    if(A[i] <= pivot){
      swap(A+i, A+j);
      j++;
    }
  }

  if(j == k+1 ) return pivot;
  else if(j < k+1) return quick_select(A+j, n-j, k-j);
  else return quick_select(A+1, j-1, k);
}

int median_of_median(int A[], int n){
  int p, q;
if (n <= 5) return A[n/2];

else if (n % 5 == 0){
  int B[n/5 - 1];
for (p = 0; p < n/5; p++){
B[p] = quick_select(A+5*p, 5, 2);
}
return quick_select(B+0, p + 1, (p + 1)/2);
}

else {
int C[n/5];
for (q = 0; q < n/5 + 1; q++){
C[q] = quick_select(A+5*q, 5, 2);
}
return quick_select(C+0, q + 1, (q+1)/2);
}
}


int main(){
  int i;
  A[0] = 0;
  A[1] = 17; //原始元
  for(i=2;i<N;i++){
    A[i] = (long long int) A[i-1] * A[1] % N;
  }
  for(i=0;i<N;i++){
    if(quick_select(A, N, i) != i) printf("ERROR %d %d\n", i, quick_select(A, N, i));
//    printf("%d th element is %d\n", i, quick_select(A, N, i));
  }
}
