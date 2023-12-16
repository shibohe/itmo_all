#include <iostream>

using namespace std;

void quicksort(int a[], int s) {
    int start = 0, end = s - 1;
    if (s < 2) return;
    int mid = a[s/2];
    while (start <= end) {
        while (a[start] < mid) {
            start++;
        }
        while (a[end] > mid) {
            end--;
        }
        if (start <= end) {
            if (start != end) {
                swap(a[start], a[end]);
            }
            start++;
            end--;
        }
    }
    quicksort(a, end + 1);
    quicksort(a + start, s - start);
}

bool check(int arr[], int n, int k, int min) {
    int boyar = 1;
    int posled_boyar = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] - posled_boyar >= min) {
            boyar++;
            posled_boyar = arr[i];
            if (boyar >= k) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    int n, k;
    cin >> n >> k;

    int array[n];
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }

    quicksort(array,n);

    int left = 0;
    int right = array[n - 1] - array[0];
    int min = 0;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (check(array, n, k, mid)) {
            min = mid;
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    cout << min << "\n";
}