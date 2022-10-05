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

int partition(int low,int high){
    int i,j;
    int pivot=a[low];
    i=low+1;
    j=high;
    do{
        // move i to right until you get element larger than pivot
        while(a[i]<=pivot){
            i++;
        }

        // move j to left until you get element smaller than pivot
        while(a[j]>pivot){
            j--;
        }

        if(i<j){
            swap(a[i],a[j]);
        }
    }while (i<j);

    // swap pivot and a[j] at last
    swap(a[low],a[j]);
    return j;
}

void quick_sort(int low,int high){
    int partitionIndex;
    if(low<high){
        partitionIndex = partition(low,high);
        quick_sort(low,partitionIndex-1);
        quick_sort(partitionIndex+1,high);
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
    int low = 0;
    int high = n-1;
    quick_sort(low,high);
    cout<<"\nAfter Sorting:";
    printArray();
}
