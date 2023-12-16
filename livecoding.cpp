#include <iostream>

using namespace std;

int left(int arr[], int k, int n) {
    int l = -1;
    int r = n;
    while (l + 1 < r) {
        int mid = l + (r - l) / 2;
        if (arr[mid] < k)
            l = mid;
        else
            r = mid;
    }
    return r;
}

int right(int arr[], int k, int n) {
    int l = -1;
    int r = n;
    while (l + 1 < r) {
        int mid = l + (r - l) / 2;
        if (arr[mid] <= k)
            l = mid;
        else
            r = mid;
    }
    return l + 1;
}

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

int main() {
    int n, k, l, r;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cin >> k;
    quicksort(arr, n);

    for (int i = 0; i < k; i++) {
        cin >> l >> r;
        int lf = left(arr, l, n);
        int rt = right(arr, r, n);
        int answer = rt - lf;
        if (answer > 0) {
            cout << answer << " ";
        }
        else {
            cout << 0 << " ";
        }
    }
}