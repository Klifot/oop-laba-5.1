#include <iostream>
#include <string>

class Car {
protected:
    std::string brand;
    int numCylinders;
    int power;

public:
    Car(const std::string& brand, int numCylinders, int power)
        : brand(brand), numCylinders(numCylinders), power(power) {
    }

    virtual ~Car() {
    }

    virtual void print() const {
        std::cout << "Brand: " << brand << std::endl;
        std::cout << "Number of Cylinders: " << numCylinders << std::endl;
        std::cout << "Power: " << power << std::endl;
    }

    void setBrand(const std::string& newBrand) {
        brand = newBrand;
    }
};

class Truck : public Car {
private:
    int cargoCapacity;

public:
    Truck(const std::string& brand, int numCylinders, int power, int cargoCapacity)
        : Car(brand, numCylinders, power), cargoCapacity(cargoCapacity) {
    }

    Truck() : Car("", 0, 0), cargoCapacity(0) {
    }

    void print() const override {
        std::cout << "--- Truck ---" << std::endl;
        Car::print();
        std::cout << "Cargo Capacity: " << cargoCapacity << std::endl;
    }

    void setCargoCapacity(int newCapacity) {
        cargoCapacity = newCapacity;
    }
};

int main() {
    // Create a car
    Car car("BMW", 4, 200);
    car.print();
    std::cout << std::endl;

    // Create a truck
    Truck truck("Audi", 6, 300, 5000);
    truck.print();
    std::cout << std::endl;

    // Modify the brand of the truck
    truck.setBrand("Koruto");
    truck.print();

    return 0;
}