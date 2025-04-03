/*
 * @Author: cdf
 * @Date: 2025-03-07 11:25:47
 * @LastEditors: cdf
 * @LastEditTime: 2025-03-07 13:18:14
 * @Description: 插入排序还是堆排序
 */

 #include <iostream>
 #include <vector>
 #include <algorithm>
 using namespace std;
 
 bool isInsertionSort(const vector<int>& original, const vector<int>& intermediate) {
     int n = original.size();
     int i;
     for (i = 1; i < n; i++) {
         if (intermediate[i] < intermediate[i - 1])
             break;
     }
     return equal(intermediate.begin() + i, intermediate.end(), original.begin() + i);
 }
 
 vector<int> nextInsertionSort(vector<int> intermediate) {
     int n = intermediate.size();
     int i;
     for (i = 1; i < n; i++) {
         if (intermediate[i] < intermediate[i - 1])
             break;
     }
     int key = intermediate[i];
     int j = i - 1;
     while (j >= 0 && intermediate[j] > key) {
         intermediate[j + 1] = intermediate[j];
         j--;
     }
     intermediate[j + 1] = key;
     return intermediate;
 }
 
 void heapify(vector<int>& arr, int n, int i) {
     int largest = i;
     int left = 2 * i + 1;
     int right = 2 * i + 2;
     if (left < n && arr[left] > arr[largest])
         largest = left;
     if (right < n && arr[right] > arr[largest])
         largest = right;
     if (largest != i) {
         swap(arr[i], arr[largest]);
         heapify(arr, n, largest);
     }
 }
 
 bool isHeapSort(const vector<int>& original, const vector<int>& intermediate, int& heapEnd) {
     int n = original.size();
     vector<int> arr = original;
     for (int i = n / 2 - 1; i >= 0; i--)
         heapify(arr, n, i);
     for (int i = n - 1; i > 0; i--) {
         swap(arr[0], arr[i]);
         heapify(arr, i, 0);
         if (arr == intermediate) {
             heapEnd = i - 1;
             return true;
         }
     }
     return false;
 }
 
 vector<int> nextHeapSort(vector<int> intermediate, int heapEnd) {
     swap(intermediate[0], intermediate[heapEnd]);
     heapify(intermediate, heapEnd, 0);
     return intermediate;
 }
 
 int main() {
     int n;
     cin >> n;
     vector<int> original(n), intermediate(n);
     for (int i = 0; i < n; i++)
         cin >> original[i];
     for (int i = 0; i < n; i++)
         cin >> intermediate[i];
     
     if (isInsertionSort(original, intermediate)) {
         cout << "Insertion Sort" << endl;
         vector<int> result = nextInsertionSort(intermediate);
         for (int i = 0; i < n; i++) {
             if (i > 0) cout << " ";
             cout << result[i];
         }
     } else {
         int heapEnd;
         if (isHeapSort(original, intermediate, heapEnd)) {
             cout << "Heap Sort" << endl;
             vector<int> result = nextHeapSort(intermediate, heapEnd);
             for (int i = 0; i < n; i++) {
                 if (i > 0) cout << " ";
                 cout << result[i];
             }
         }
     }
     cout << endl;
     return 0;
 }
 