#include <iostream>
#include <vector>

using namespace std;

int swap(vector<int>& v, int start, int end) {

    int mid = (end + start) / 2;
    while (start <= end) {
        while (v[start] < v[mid]) start++;
        while (v[end] > v[mid]) end--;

        if (start <= end) {
            int temp = v[start];
            v[start] = v[end];
            v[end] = temp;
            start++;
            end--;
        }
    }

    return start;
}

void quickSort(vector<int>& v, int start, int end) {

    int mid = swap(v, start, end);

    if (start < mid - 1)
        quickSort(v, start, mid- 1);

    if (end > mid)
        quickSort(v, mid, end);
}

int main() {
    vector<int> v = { 4, 100, 10, 5, 8, 1, 7, 3, 9, 2 };

    quickSort(v, 0, v.size() - 1);

    for (auto n : v)
        cout << n << " ";
        
    return 0;
}