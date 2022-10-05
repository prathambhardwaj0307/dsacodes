#include <iostream>
#include <climits>

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

int maximum(int arr[],int sz){
    int max_num = INT_MIN;
    for(int i=0;i<sz;i++){
        if(max_num<arr[i]){
            max_num=arr[i];
        }
    }
    return max_num;
}

void count_sort(){
    int max_n = maximum(a,n),i,j;
    
    // count array of size maximum+1
    int* count = (int*)malloc((max_n+1)*sizeof(int));
    for(i=0;i<max_n+1;i++){
        count[i]=0;
    }

    // traversing through the main array to put values in the count array
    for(i=0;i<n;i++){
        // incrementing the count of elements at indices
        count[a[i]]=count[a[i]]+1;
    }

    i=0;
    j=0;
    while(i<=max_n){
        if(count[i]>0){
            a[j]=i;
            count[i]--;
            j++;
        }
        else{
            i++;
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
    count_sort();
    cout<<"\nAfter Sorting:";
    printArray();
}