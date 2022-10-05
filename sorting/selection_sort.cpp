#include <iostream>
using namespace std;

int a[1000],n;
void printArray(){
    if(n!=0){
        cout<<"\nThe array is: ";
        for(int i=0;i<n;i++){
            cout<<a[i]<<" ";
        }
        cout<<"\n";
    }
    else{
        cout<<"\nEmpty array!!";
    }
}

int swap(int *a1,int *a2){
    int temp;
    temp=*a1;
    *a1=*a2;
    *a2=temp;
}

void selection_sort(){
    int i,j;
    for(i=0;i<n-1;i++){
        for(j=i;j<n;j++){
            if(a[j]<a[i]){
                swap(&a[i],&a[j]);
            }
        }
    }
}

int main(){
    int i;
    cout<<"Enter the size of array:";
    cin>>n;
    cout<<"\nEnter the array elements:";
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<"\nBefore Sorting:";
    printArray();
    selection_sort();
    cout<<"\nAfter Sorting:";
    printArray();
}