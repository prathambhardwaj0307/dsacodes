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

void bubble_sort(){
    int i,j,flag=1;
    for(i=0;i<n-1;i++){
        cout<<"Check"; // just a print statement which is printed a single time in case of sorted array and n-1 times in unsorted array
        for(j=0;j<n-1-i;j++){
            if(a[j]>a[j+1]){
                swap(a[j],a[j+1]);
                flag=0;
            }
        }
        // checking after first pass that if a single swap has occured or not i.e. is array already sorted or not
        if(flag){
            break;
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
    bubble_sort();
    cout<<"\nAfter Sorting:";
    printArray();
}