class MyCircularDeque {
public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    int cnt;
    int size;
    int front;
    int last;
    vector<int>v;
    MyCircularDeque(int k) {
        cnt=0;
        front=k-1;
        last=0;
        size=k;
        v.resize(k);
    }
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if(!isFull()){
            v[front]=value;
            front=(front-1+size)%size;
            cnt++;
            return true;
        }
        return false;
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if(!isFull()){
            v[last]=value;
            last=(last+1)%size;
            cnt++;
            return true;
        }
        return false;
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if(!isEmpty()){
            front=(front+1)%size;
            cnt--;
            return true;
        }
        return false;
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if(!isEmpty()){
            last=(last-1+size)%size;
            cnt--;
            return true;
        }
        return false;
    }
    
    /** Get the front item from the deque. */
    int getFront() {
        if(!isEmpty()){
            return v[(front+1)%size];
        }
        return -1;
    }
    
    /** Get the last item from the deque. */
    int getRear() {
        if(!isEmpty()){
            return v[(last-1+size)%size];
        }
        return -1;
    }
    
    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        if(cnt==0){
            return true;
        }
        return false;
    }
    
    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        if(cnt==size){
            return true;
        }
        return false;
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