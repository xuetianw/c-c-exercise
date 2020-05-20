#include <algorithm>

//
// Created by fred on 01/12/19.
//
class boVector {
    int size;
    double* arr_;
public:
    boVector() {
        size = 10;
    }

    boVector(const boVector& rhs) {
        size = rhs.size;
        arr_ = new double[size];
    }

    boVector(const boVector&& rhs) {
        size = rhs.size;
        arr_ = new double[size];
    }
};

void foo(boVector v) {}

void foo_by_value(boVector v);
void foo_by_ref(boVector& v);

boVector createBoVector() {
    boVector boVector;
    return boVector;
}
int main() {
    boVector reusable = createBoVector();
    foo(std::move(reusable));
//    foo_by_ref(createBoVector());
}