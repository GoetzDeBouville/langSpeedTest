#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib>
#include <iomanip> 

using namespace std;

void arrayBuild(vector<int> &arr, int num) {
    for(int i = 0; i < num; ++i) {
        arr.push_back(rand() % 1000);
    }
}

void rearangeArr(vector<int> &arr, int start) {
    for (int i = start; i < arr.size(); ++i) {
        swap(arr[start], arr[i]);
        rearangeArr(arr, start + 1);
        swap(arr[start], arr[i]);
    }
}

int main() {
    vector<int> array;
    arrayBuild(array, 11);

    auto start = chrono::high_resolution_clock::now();
    rearangeArr(array, 0);
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);

    double seconds = static_cast<double>(duration.count()) / 1000000.0;
    cout << fixed << setprecision(5) << seconds << " sec" << endl;

    return 0;
}
