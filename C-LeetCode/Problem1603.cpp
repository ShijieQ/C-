class ParkingSystem {
private:
    int num[3];

public:
    ParkingSystem(int big, int medium, int small) {
        num[0] = big;
        num[1] = medium;
        num[2] = small; 
    }
        
    bool addCar(int carType) {
        if (num[carType-1] > 0) {
            num[carType-1]--;
            return true;
        }
        else {
            return false;
        }
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */