//1. divide the array
// mid
// 2. merge parts to create a sorted array

// merge sort -> divide & conquer = repeated array ko divide kartai hai conquer mean bigger problem nahi solve kar rahai balkai bigger array ko small part mai tor tor kar sort kara

#include <iostream>
using namespace std;

int array[] = {34,56,23,87,95,56,77,83};
int n = 8;

void merge(int left, int mid, int right){
  // number of elements
  int n1 = mid-left+1;
  int n2 = right-mid;

  int array1[n1];
  int array2[n2];
  
  for(int i=0; i<n1; i++){
    array1[i] = array[left + i]; 
  }
  for(int j=0; j<n2; j++){
    array2[j] = array[mid + 1 + j];
  }

  int i,j,k;
  i = 0;
  j = 0;
  k = left;

  while(i < n1 && j < n2){
    if(array1[i] < array2[j]){
         array[k] = array1[i];
         i++;
    }
    else{
        array[k] = array2[j];
        j++;
    }
    k++;
  }
  while(i < n1){
    array[k] = array1[i];
    i++;
    k++;
}
  while(j < n2){
    array[k] = array2[j];
    j++;
    k++;
  }

}

void merge_sort(int left, int right){
    if(left < right){
        int mid = (left + right) / 2;
        merge_sort(left,mid);
        merge_sort(mid + 1, right);
        merge(left,mid,right);
    }
}

void display(){
    for(int i=0; i<n; i++){
        cout << array[i] << "  ";
    }
}

int main(){
    cout << "\nORIGINAL ARRAY\n";
    display();

    cout << "\nSORTED ARRAY\n";
    merge_sort(0,n-1);
    display();

}