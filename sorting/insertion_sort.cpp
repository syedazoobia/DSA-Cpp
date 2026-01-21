// INSERTION SORT
#include <iostream>
using namespace std;
int main(){
    int input[10] = {67,87,65,8,4,79,79,98,45,22};
    int i, j, temp;

    for(i=1; i<10; i++){
        temp = input[i];

        for(j=i-1; j>=0 ;j--){
            if(temp < input[j])
            {
                input[j + 1] = input[j];
            }
            else{
                break;
            }
        }
        input[j+1] = temp;
    }

    for(i=0; i<10; i++){
        cout << input[i] << "  ,  ";
    }
    
    return 0;
}