class MyCircularQueue {
public:
    int front;
    int back;
    int size;
    int capacity;
    vector<int>arr;
    MyCircularQueue(int k) { // k is capacity
        front=0;
        back=0;
        size=0;
        capacity=k;
        vector<int>v(k);
        arr=v;
    }
    
    bool enQueue(int val) { // push back
        if(size==capacity) return false;
        arr[back]=val;
        back++;
        if(back==capacity) back = 0; // circular queue
        size++;
        return true;
    }
    
    bool deQueue() { // pop front
        if(size==0) return false;
        front++;
        if(front==capacity) front=0;
        size--;
        return true;
    }
    
    int Front() {
        if(size==0) return -1;
        return arr[front];
        
    }
    
    int Rear() {
        if(size==0) return -1;
        if(back==0) return arr[capacity-1]; // important
        return arr[back-1];
    }
    
    bool isEmpty() {
        if(size==0) return true;
        else return false;
    }
    
    bool isFull() {
        if(size==capacity) return true;
        else return false;
    }
};
