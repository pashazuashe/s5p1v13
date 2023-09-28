﻿#include <iostream>
#include <iomanip>
#include <ios>
#include <vector>
#include <string>
using namespace std;

void func1(vector<float>& tvr);
void func2(vector<float>& tvr);
void printVector(vector<float>& tvr);

void func1(vector<float>& tvr) {
    float sum = 0;
    int size = tvr.size();

    for (int i = 0; i < size; i++)
        sum += tvr.at(i);

    tvr.push_back(sum);
    tvr.push_back(sum / size);
    printVector(tvr);
}

void func2(vector<float>& tvr) {
    float min = tvr[0];

    for (int i = 0; i < tvr.size(); i++) {
        if (tvr[i] < min) {
            min = tvr[i];
        }
    }
    for (int i = 0; i < tvr.size(); i++) {
        if (tvr[i] > 0) {
            tvr[i] = min * min;
        }
    }
    printVector(tvr);
}

void printVector(vector<float>& tvr) {
    for (int i = 0; i < tvr.size(); i++) {
        cout << tvr[i] << ' ';
    }
    cout << '\n';
}

void main() {
    cout.setf(ios::fixed);
    cout.precision(3);

    int capacity = 0;
    int size = 0;
    cin >> size;
    capacity = size + 1;

    vector<float> v1;
    v1.resize(size);
    v1.reserve(capacity);

    for (int i = 0; i < size; i++) {
        cin >> v1[i];
    }

    cout << v1.size() << '\n';
    printVector(v1);

    func1(v1);

    func2(v1);

    bool b = true;
    while (true) {
        cout << '\n';
        int c;
        cin >> c;

        if (c == 0)
            break;

        if (c == 1){
            float x = 0;
            cin >> x;

            v1.push_back(x);
            cout << "+: " << v1.size() << '\n';
            printVector(v1);

            func1(v1);

            func2(v1);
        };
        if (c == 2) {
            v1.pop_back();
            cout << "-: " << v1.size() << '\n';
            printVector(v1);

            func1(v1);

            func2(v1);
        };
    }
}