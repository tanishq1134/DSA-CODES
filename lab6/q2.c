#include<bits/stdc++.h>
using namespace std;
void heapify(vector<int>& v, int n, int i) {
    int smallest = i;        
    int left = 2 * i + 1;    
    int right = 2 * i + 2;  
    if (left < n && v[left] < v[smallest])
        smallest = left;
    if (right < n && v[right] < v[smallest])
        smallest = right;
    if (smallest != i) {
        swap(v[i], v[smallest]);
        heapify(v, n, smallest); 
    }
}
void heapsort(vector<int>& v, int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(v, n, i);
    for (int i = n - 1; i > 0; i--) {
        swap(v[0], v[i]);
        heapify(v, i, 0);
    }
}

void insertion(vector<int>& v, int num) {
    cout << "After Insertion : ";
    v.push_back(num);
    int size = v.size();
    int index = size - 1;
    while (index > 0 && v[index] < v[(index - 1) / 2]) {
        swap(v[index], v[(index - 1) / 2]);
        index = (index - 1) / 2;
    }
}
void deletion(vector<int>& v) {
    int n = v.size();
    swap(v[0], v[n - 1]);
    v.pop_back();
    heapify(v, v.size(), 0);
}
void printheap(vector<int>& v) {
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
}
int main() {
    vector<int> v = {1,5,6,8,9,7,3};
    printheap(v);
    heapsort(v,7);
    printheap(v);
    return 0;
}