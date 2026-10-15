#include <iostream>
#include <string>
using namespace std;

class Vehicle {
public:
    string model;
    int rentalRate;

    Vehicle(string m, int r)
        : model(m), rentalRate(r) {}

    virtual int calculateRentalCost(int days) = 0;
};

class Car : public Vehicle {
private:
    int seats;

public:
    Car(string m, int r, int s)
        : Vehicle(m, r), seats(s) {}

    int calculateRentalCost(int days)  {
        return seats * rentalRate * days;
    }
};  

int main() {
    string s;
    int a , b , c;
    cin >> s;
    cin >> a >> b >> c;
    Vehicle *v = new Car(s,a,b);
    cout << v->calculateRentalCost(c);
    return 0;
}

