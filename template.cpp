//
// Created by fred on 02/03/19.
//

// CPP code for bubble sort
// using template function
#include <iostream>
using namespace std;

//Function Templates


//// One function works for all data types.  This would work
//// even for user defined types if operator '>' is overloaded
//template <typename T>
//T myMax(T x, T y)
//{
//    return (x > y)? x: y;
//}
//
//int main()
//{
//    cout << myMax<int>(3, 7) << endl;  // Call myMax for int
//    cout << myMax<double>(3.0, 7.0) << endl; // call myMax for double
//    cout << myMax<char>('g', 'e') << endl;   // call myMax for char
//
//    return 0;
//}



//// A template function to implement bubble sort.
//// We can use this for any data type that supports
//// comparison operator < and swap works for it.
//template <class T>
//void bubbleSort(T a[], int n) {
//    for (int i = 0; i < n - 1; i++)
//        for (int j = n - 1; i < j; j--)
//            if (a[j] < a[j - 1])
//                swap(a[j], a[j - 1]);
//}
//
//// Driver Code
//int main() {
//    int a[5] = {10, 50, 30, 40, 20};
//    int n = sizeof(a) / sizeof(a[0]);
//
//    // calls template function
//    bubbleSort<int>(a, 5);
//
//    cout << " Sorted array : ";
//    for (int i = 0; i < n; i++)
//        cout << a[i] << " ";
//    cout << endl;
//
//    return 0;
//}



//Class Templates Like function templates, class templates are useful when a class defines something that is independent of data type. Can be useful for classes like LinkedList, BinaryTre, Stack, Queue, Array, etc.

template <typename T>
class Array {
private:
    T *ptr;
    int size;
public:
    Array(T arr[], int s);
    void print();
};

template <typename T>
Array<T>::Array(T arr[], int s) {
    ptr = new T[s];
    size = s;
    for(int i = 0; i < size; i++)
        ptr[i] = arr[i];
}

template <typename T>
void Array<T>::print() {
    for (int i = 0; i < size; i++)
        cout<<" "<<*(ptr + i);
    cout<<endl;
}

//int main() {
//    int arr[5] = {1, 2, 3, 4, 5};
//    Array<int> a(arr, 5);
//    a.print();
//    return 0;
//}


struct Meters {};
struct Miles {};
struct Seconds {};
struct Hours {};

template <typename T, typename U>
struct Speed { double speed; };


template <typename T>
struct Distance { double distance; };


template <typename T>
struct Time { double time; };


template <typename T, typename U>
Distance<T> distanceTraveled(Speed<T,U> speed, Time<U> time) {
    return {speed.speed * time.time};
}



int main() {
    distanceTraveled(Speed<Miles,Hours>{3}, Time<Seconds>{5});
}


//
//
//#include<iostream>
//using namespace std;
//
//template<class T, class U>
//class A  {
//    T x;
//    U y;
//public:
//    A() {    cout<<"Constructor Called"<<endl;   }
//};
//
//int main()  {
//    A<char, char> a;
//    A<int, double> b;
//    return 0;
//}