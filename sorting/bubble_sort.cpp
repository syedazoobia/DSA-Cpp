// BUBBLE SORT

#include <iostream>
using namespace std;
int main(){
    int input[10] = {12,32,56,43,67,54,89,65,87,54};

    int i, temp, flag;

  for(int j=0; j<10; j++){
    flag = 0;
    for(i=0; i<9; i++){
        if(input[i] > input[i+1])
        {
            temp = input[i+1];
            input[i+1] = input[i];
            input[i]=temp;
            flag = 1;
        }
    }
    if(flag == 0){
        break;
    }
}


    for(i=0; i<10; i++){
        cout << input[i] << " , ";
    }

    return 0;
}