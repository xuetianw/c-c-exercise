//
// Created by fred on 27/02/19.
//

#include <iostream>
#include <vector>
#include <cmath>

int foo(int x)
{
    return x;
}

void SelectionSort(int *array, int size)
{
    // Step through each element of the array
    for (int startIndex = 0; startIndex < size; ++startIndex)
    {
        // smallestIndex is the index of the smallest element we've encountered so far.
        int smallestIndex = startIndex;

        // Look for smallest element remaining in the array (starting at startIndex+1)
        for (int currentIndex = startIndex + 1; currentIndex < size; ++currentIndex)
        {
            // If the current element is smaller than our previously found smallest
            if (array[smallestIndex] > array[currentIndex]) // COMPARISON DONE HERE
                // This is the new smallest number for this iteration
                smallestIndex = currentIndex;
        }

        // Swap our start element with our smallest element
        std::swap(array[startIndex], array[smallestIndex]);
    }
}

bool ascending(int x, int y)
{
    return x > y; // swap if the first element is greater than the second
}

void SelectionSort2(int *array, int size)
{
    // Step through each element of the array
    for (int startIndex = 0; startIndex < size; ++startIndex)
    {
        // smallestIndex is the index of the smallest element we've encountered so far.
        int smallestIndex = startIndex;

        // Look for smallest element remaining in the array (starting at startIndex+1)
        for (int currentIndex = startIndex + 1; currentIndex < size; ++currentIndex)
        {
            // If the current element is smaller than our previously found smallest
            if (ascending(array[smallestIndex], array[currentIndex])) // COMPARISON DONE HERE
                // This is the new smallest number for this iteration
                smallestIndex = currentIndex;
        }

        // Swap our start element with our smallest element
        std::swap(array[startIndex], array[smallestIndex]);
    }
}

void selectionSort(int *array, int size, bool (*comparisonFcn)(int, int))
{
    // Step through each element of the array
    for (int startIndex = 0; startIndex < size; ++startIndex)
    {
        // bestIndex is the index of the smallest/largest element we've encountered so far.
        int bestIndex = startIndex;

        // Look for smallest/largest element remaining in the array (starting at startIndex+1)
        for (int currentIndex = startIndex + 1; currentIndex < size; ++currentIndex)
        {
            // If the current element is smaller/larger than our previously found smallest
            if (comparisonFcn(array[bestIndex], array[currentIndex])) // COMPARISON DONE HERE
                // This is the new smallest/largest number for this iteration
                bestIndex = currentIndex;
        }

        // Swap our start element with our smallest/largest element
        std::swap(array[startIndex], array[bestIndex]);
    }
}

typedef void(*func)(int);

void ForEach(const std::vector<int>& values, func func1) {
    for (auto value : values) {
        func1(value);
    }
}

void PrintValue(int value) {
    std::cout << "Value :" << value << std::endl;
}

//void ForEach(const )

void HelloWorld() {
    std::cout << "hello" << std::endl;
}
bool check_oppened(int taget, int *arr, int size) {
    for (int i = 0; i < taget - 1; i++) {
        if (arr[i] != 1) return false;
    }
    return true;
}

int solution(std::vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int arr[A.size()];
    int moment_count = 0;
    for (int i = 0; i < A.size(); i++) {
        if (!check_oppened(A.at[i], arr, A.size())) {
            moment_count++;
            arr[i] = 1;
        }
    }
    return moment_count;
}


int main()
{
//    std::string str = "abcde";
//    std::cout << str.substr(0);
    int arr[10];
    std::cout << arr[0];
//    std::string S = "abd";
//    std::string str = "adf";
//    S.erase(std::remove(S.begin(), S.end(), '-'), S.end());
//    str.erase(std::find(str.begin(), str.end(), 'a'));
//    std::cout << std::atan(-2)  * 180 / 3.1415926;
//    s.erase(std::find(s.begin(), s.end(), ' ')); // Erase ' '

//    std::vector<int> myvector{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };
//
//    for (auto i = myvector.begin(); i != myvector.end(); ++i) {
//        if (*i % 2 == 0) {
//            myvector.erase(i);
//            i--;
//        }
//    }
//
//    std::vector<int> bar;
//
//    bar.reserve(100);
//    bar.at(0) = 1;

//    typedef int (*fcnPtr)(int);
//    fcnPtr ptr = foo; // assign fcnPtr to function foo
//    (ptr)(5); // call function foo(5) through fcnPtr.

    return 0;
}