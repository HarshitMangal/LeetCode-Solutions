class ParkingSystem {
public:
    vector<int> slot;

    ParkingSystem(int big, int medium, int small) {
        slot = {big, medium, small};
    }

    bool addCar(int carType) {

        if (slot[carType - 1] > 0) {
            slot[carType - 1]--;
            return true;
        }

        return false;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */