/*
    Author: Gabriel Hofer
    Course: CSC-372 Analysis of Algorithms
    Date: Nov 19, 2020
    Instructor: Dr. Rebenitsch
    Pseudocode Source: https://www.cs.princeton.edu/~wayne/cs423/lectures/fft-4up.pdf
    (the pseudocode is on the fourteenth slide, on the fourth page)
*/
#include <utility>
#include <algorithm>
#include <vector>
#include <cmath>
#include <complex>
#include <iostream>
#include <iomanip>
#include <intrin.h>
#include <fstream>
using namespace std;
using namespace complex_literals;
using cd = complex<double>;
const double PI = acos(-1);

void fft(vector<cd>& F) {
    int n = F.size();
    if (n == 1) return;
    vector<cd> E(n / 2), D(n / 2);
    for (int i = 0; 2 * i < n; i++) {
        E[i] = F[2 * i];
        D[i] = F[2 * i + 1];
    }
    fft(E);
    fft(D);
    cd w(1);
    for (int i = 0; 2 * i < n; i++) {
        w = polar(1.0, -1 * i * 2 * PI / n);
        F[i] = E[i] + w * D[i];
        F[i + n / 2] = E[i] - w * D[i];
    }
}

bool cmp(pair<int, cd> a, pair<int, cd> b) {
    return (a.second.real() * a.second.real() + a.second.imag() * a.second.imag()) >
        (b.second.real() * b.second.real() + b.second.imag() * b.second.imag());
}

void print_result(vector<cd>& a) {
    cout << setprecision(2) << fixed;
    if (a.size() <= 8) for (auto el : a) cout << el << endl;
    else {
        vector<pair<int, cd>> indexed(a.size());
        for (int i = 0; i < (int)a.size(); i++) indexed[i] = { i,a[i] };
        sort(indexed.begin(), indexed.end(), cmp);
        for (int i = 0; i < 7; i++) cout << setw(10) << left << indexed[i].first << indexed[i].second << endl;
    }
}

vector<cd> read_input(string filename) {
    ifstream fin(filename, ifstream::in);
    if (!fin.is_open()) cout << "file is NOT open" << endl;
    double e1; cd e2;
    vector<cd> v;
    while (fin >> e1) v.push_back(e2 = e1 + 0i);
    reverse(v.begin(), v.end()); // reverse the input
    while (__popcnt(v.size()) > 1) v.push_back(0);
    return v;
}

int main(int argc, char * argv[]) {
    vector<cd> v = read_input(argv[1]);
    fft(v);
    print_result(v);
    return 0;
}
