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

void insertion_sort(){
    int j,i,key;
    // i starts from 1 because first element is already sorted
    for(i=1;i<n;i++){
        key=a[i];
        j=i-1;
        while((j>=0) && (key<a[j])){ //j>=0 condition because if j=-1 that means index completed
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key; //insertion of the key element (i.e. element at starting of unsorted array part)
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
    insertion_sort();
    cout<<"\nAfter Sorting:";
    printArray();
}