#include<iostream>
using namespace std;


class heap{

    public:
     int arr[100];
     int size;

     heap(){
        arr[0]=-1;
        size=0;
     }

     void insert(int val){
        size=size+1;
        int i=size;
        arr[i]=val;

        while(i>1){
            int parent=i/2;

            if(arr[parent]<arr[i]){
                swap(arr[parent],arr[i]);
                i=parent;
            }
            else{
                return;
            }
        }
     }

     void print(){
        for(int i=1;i<=size;i++){
            cout<<arr[i]<<" ";
        }cout<<endl;
     }


     void deletion(){
        //step 1
         arr[1]=arr[size];
        //step 2 :remove last element 
         size--;

         //step 3:
        int i=1;
         while(i<size){
            int lidx=2*i;
            int ridx=2*i+1;

            if(lidx<size && arr[i]<arr[lidx]){
                swap(arr[i],arr[lidx]);
                i=lidx;
            }

           else if(ridx<size && arr[i]<arr[ridx]){
                swap(arr[i],arr[ridx]);
                i=ridx;
            }
            else{
                return;
            }
         }
     }
};


void heapify(int *arr,int n,int i){
    int largest=i;
    int l=2*i;
    int r=2*i+1;

    if(l<=n && arr[largest]<arr[l]){
        largest=l;
    }

    if(r<=n && arr[largest]<arr[r]){
        largest=r;
    }

    if(largest!=i){
        swap(arr[largest],arr[i]);
        heapify(arr,n,largest);
    }
}

int main(){

    heap h;
    h.insert(60);
    h.insert(30);
    h.insert(50);
    h.insert(55);
    h.insert(20);
    h.insert(40);

    h.print();
    h.deletion();
    h.print();

    int arr1[6]={-1,54, 53,55,52,50};
    int n=5;

    for(int i=n/2;i>=1;i--){
        heapify(arr1,n,i);
    }
    cout<<"Printing The Array Now"<<endl;
    for(int i=0;i<=n;i++){
        cout<<arr1[i]<<" ";
    }cout<<endl;
 

    return 0;
}
