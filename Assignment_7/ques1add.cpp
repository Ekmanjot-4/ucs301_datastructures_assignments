#include <iostream>
#include <vector>
using namespace std;

void countSort(int arr[], int n) {
    int maxVal = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > maxVal) maxVal = arr[i];

    vector<int> count(maxVal + 1, 0);
    for (int i = 0; i < n; i++)
        count[arr[i]]++;

    int idx = 0;
    for (int i = 0; i <= maxVal; i++)
        while (count[i]--)
            arr[idx++] = i;
}

int main() {
    int arr[] = {4, 2, 2, 8, 3, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    countSort(arr, n);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}
