#include <iostream>
using namespace std;


/* Insert key and heapify functions */

class minHeap {

    int *arr;
    int capacity;
    int heap_size;
    public:
        minHeap(int c);

        int parent(int i) {return (i-1)/2 ;} ;
        int left(int i) {return (2*i + 1) ;} ;
        int right(int i) {return (2*i + 2); };

        void insert(int x);
        void minHeapify(int x);
        int retMin();
        int extractMin();

};

minHeap::minHeap(int c){
    printf("new minHeap is created with cap %d\n", c);
    heap_size = 0;
    capacity = c;
    arr = new int[c];

}

int minHeap::retMin(){

    if(heap_size != 0){
        return arr[0];
    }
    else{
        return INT_MAX;
    }
}

void minHeap::insert(int x){

    if(heap_size == capacity){
        printf("heap is full\n");
        return;
    }
    heap_size++;
    arr[heap_size-1] = x;
    printf("insert %d heap_size %d\n", x, heap_size);
    /* assuming that minHeap is already heapified, place the new key at correct position */
    int pos = heap_size-1;
    while(pos != 0){
        if(arr[parent(pos)] > arr[pos]){
            swap(arr[parent(pos)], arr[pos]);
        }
        pos = parent(pos);
    }
}

int minHeap::extractMin(){

    if(heap_size == 0){
        printf("empty heap\n");
        return INT_MAX;
    }

    if(heap_size == 1){
        heap_size--;
        return arr[heap_size];
    }

    int minH = arr[0];
    arr[0] = arr[heap_size-1];
    heap_size--;
    minHeapify(0);

    return minH;

}

void minHeap::minHeapify(int ind){

    int smallest = ind;
    int l = left(ind);
    int r = right(ind);
    printf("heap_size %d curr %d left %d right %d\n",heap_size,  arr[ind], l, r);
    if(l < heap_size &&  arr[l] < arr[smallest]){
        smallest = l;
    }

    if(r < heap_size && arr[r] < arr[smallest]){
        smallest = r;
    }

    if(smallest != ind)
    {
        swap(arr[ind], arr[smallest]);
        minHeapify(smallest);
    }

}


int main(){

    minHeap* mH = new minHeap(5);
    mH->insert(2);
    mH->insert(7);
    mH->insert(10);
    mH->insert(12);
    mH->insert(6);

    printf("min value in the heap is %d\n", mH->retMin());
    mH->extractMin();
    printf("after extraction, min value in heap is %d\n", mH->retMin());

    return 0;
}