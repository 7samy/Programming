#include <iostream>
#include <vector>

using namespace std;

void printArray(const vector<int>& a, int step) {
    cout << "i=" << step << ": [";
    for (size_t i = 0; i < a.size(); ++i) {
        cout << a[i] << (i < a.size() - 1 ? ", " : "");
    }
    cout << "]\n";
}

// 17 Vergleiche
void insertionSort(vector<int> a) {
    cout << "\n--- InsertionSort ---\n";
    int n = a.size();
    int vergleiche = 0;
    
    for (int i = 1; i < n; i++) {
        int an = a[i];
        int j = i;
        while (j > 0) {
            vergleiche++;
            if (an < a[j - 1]) {
                a[j] = a[j - 1];
                j--;
            } else {
                break;
            }
        }
        a[j] = an;
        printArray(a, i);
    }
    cout << "Vergleiche: " << vergleiche << "\n";
}

// 36 Vergleiche
void selectionSort(vector<int> a) {
    cout << "\n--- SelectionSort ---\n";
    int n = a.size();
    int vergleiche = 0;
    
    for (int i = 0; i < n - 1; i++) {
        int imin = i;
        for (int j = i + 1; j < n; j++) {
            vergleiche++;
            if (a[j] < a[imin]) {
                imin = j;
            }
        }
        swap(a[i], a[imin]);
        printArray(a, i);
    }
    cout << "Vergleiche: " << vergleiche << "\n";
}

// 36 Vergleiche
void exchangeSort(vector<int> a) {
    cout << "\n--- ExchangeSort ---\n";
    int n = a.size();
    int vergleiche = 0;
    
    for (int i = 0; i < n - 1; i++) {
        for (int j = n - 2; j >= i; j--) {
            vergleiche++;
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
            }
        }
        printArray(a, i);
    }
    cout << "Vergleiche: " << vergleiche << "\n";
}

int main() {
    vector<int> a = {0, 10, 20, 1, 11, 21, 2, 12, 22};
    
    insertionSort(a);
    selectionSort(a);
    exchangeSort(a);
    
    return 0;
}
