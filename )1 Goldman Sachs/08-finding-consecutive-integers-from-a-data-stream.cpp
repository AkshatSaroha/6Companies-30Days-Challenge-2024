class DataStream {
    int k;
    int value;
    int countEquals = 0;
public:
    DataStream(int value, int k) {
        this->k = k;
        this->value = value;
    }
    
    bool consec(int num) {
        if(num == value)
            countEquals++;
        else
            countEquals = 0;
        
        return countEquals >= k;
    }
};