class MyCircularDeque {
public:
       vector<int> q;
     int front, rear, size, capacity;

    MyCircularDeque(int k) {
         q.resize(k);
        front = 0;
        rear = -1;
        size = 0;
        capacity = k;
        
    }
    
    bool insertFront(int value) {
         if (size == capacity) return false;
           front = (front - 1 + capacity) % capacity;
            q[front] = value;
            size++;
            if(size==1){
                rear=front;
            }
            return true;

        
    }
    
    bool insertLast(int value) {
             if (size == capacity) return false;

                rear = (rear + 1) % capacity;
                q[rear] = value;
                size++;
                if(size==1){
                    rear==front;
                }
                return true;
        
    }
    
    bool deleteFront() {
                if (size == 0) return false;

            front = (front + 1) % capacity;
            size--;

            return true;

        
    }
    
    bool deleteLast() {
         if (size == 0) return false;
        rear = (rear - 1 + capacity) % capacity;
        size--;

        return true;
        
    }
    
    int getFront() {
        if (size == 0) return -1;
        return q[front];
        
        
    }
    
    int getRear() {
        if (size == 0) return -1;
        return q[rear];
        
    }
    
    bool isEmpty() {
     return size == 0;

        
    }
    
    bool isFull() {
        return size == capacity;
        
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */