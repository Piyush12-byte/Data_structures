#include <bits/stdc++.h>

void heapify(vector<int>&c,int n,int i){
   
   int largest=i;
   int left=2*i+1;
   int right=2*i+2;

   if(left<n&&c[largest]<c[left]){
       largest=left;
   }

   if(right<n&&c[largest]<c[right]){
       largest=right;
   }

   if(largest!=i){
       swap(c[largest],c[i]);
       heapify(c,n,largest);
   }
}

vector<int> mergeHeap(int n, int m, vector<int> &arr1, vector<int> &arr2) {
     vector<int>c(m+n);

     for(int i=0;i<n;i++){
         c[i]=arr1[i];
     }

     for(int i=0;i<m;i++){
         c[n+i]=arr2[i];
     }
     
     int i=0;
     int r=m+n;
     for(int i=r/2-1;i>=0;i--){
        heapify(c,r,i);
     }

     return c;
}
