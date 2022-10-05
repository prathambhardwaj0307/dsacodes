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

void merge(int low,int mid,int high){
    int i=low,j=mid+1,b[1000],k=low;
    while(i<=mid && j<=high){
        if(a[i]<=a[j]){
            b[k]=a[i];
            i++;k++;
        }else{
            b[k]=a[j];
            j++;k++;
        }
    }

    // leftover elements in left half and right half
    while(i<=mid){
        b[k]=a[i];
        i++;k++;
    }

    while(j<=high){
        b[k]=a[j];
        j++;k++;
    }

    // finally copying the elements in main array
    for(i=low;i<=high;i++){
        a[i]=b[i];
    }
}

void merge_sort(int low,int high){
    if(low<high){
        int mid=(low+high)/2;
        merge_sort(low,mid);
        merge_sort(mid+1,high);
        merge(low,mid,high);
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
    int low=0,high=n-1;
    merge_sort(low,high);
    cout<<"\nAfter Sorting:";
    printArray();
}