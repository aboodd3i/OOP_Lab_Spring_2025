#include <iostream>
using namespace std;

class Activity {
public:
    virtual double calculateCaloriesBurned() = 0;
    virtual ~Activity() {}
};

class Running : public Activity {
private:
    double distance;
    double time;

public:
    Running(double d, double t) {
        distance = d;
        time = t;
    }

    double calculateCaloriesBurned() override {
        return (distance / (time / 60.0)) * 1.036 * time;
    }
};

class Cycling : public Activity {
private:
    double speed;
    double time;

public:
    Cycling(double s, double t) {
        speed = s;
        time = t;
    }

    double calculateCaloriesBurned() override {
        return speed * time * 5.0;
    }
};

int main() {
    Running r(5.0, 30.0);
    Cycling c(20.0, 1.0);

    cout << "Calories burned in running: " << r.calculateCaloriesBurned() << endl;
    cout << "Calories burned in cycling: " << c.calculateCaloriesBurned() << endl;

    return 0;
}
