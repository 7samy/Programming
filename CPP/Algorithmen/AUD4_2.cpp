#include <iostream>

class Vektor {
private:
    int dimension;
    int* daten;

public:
    Vektor(int dim) : dimension(dim) {
        daten = new int[dimension];
        for (int i = 0; i < dimension; i++) {
            daten[i] = 0;
        }
    }

    virtual ~Vektor() {
        delete[] daten;
    }

    void set(int i, int val) {
        if (i >= 0 && i < dimension) {
            daten[i] = val;
        }
    }

    int get(int i) {
        if (i >= 0 && i < dimension) {
            return daten[i];
        }
        return -1;  
    }

    int bin_suche(int sw) {
        int l_u = 0;             
        int l_o = dimension - 1;  

        while (l_u <= l_o) {
            int mitte = l_u + (l_o - l_u) / 2;  

            if (daten[mitte] == sw) {
                return mitte;  
            }
            else if (daten[mitte] < sw) {
                l_u = mitte + 1; 
            }
            else {
                l_o = mitte - 1;  
            }
        }

        return -1;  
    }

    void sortieren() {
        for (int i = 0; i < dimension - 1; i++) {
            for (int j = 0; j < dimension - i - 1; j++) {
                if (daten[j] > daten[j + 1]) {
                    int temp = daten[j];
                    daten[j] = daten[j + 1];
                    daten[j + 1] = temp;
                }
            }
        }
    }

    void ausgeben() {
        std::cout << "[";
        for (int i = 0; i < dimension; i++) {
            std::cout << daten[i];
            if (i < dimension - 1) std::cout << ", ";
        }
        std::cout << "]" << std::endl;
    }
};

int main() {
    
    Vektor v(10);
    v.set(0, 5);
    v.set(1, 2);
    v.set(2, 8);
    v.set(3, 1);
    v.set(4, 9);
    v.set(5, 3);
    v.set(6, 7);
    v.set(7, 4);
    v.set(8, 6);
    v.set(9, 10);

    std::cout << "Unsortiertes Array: ";
    v.ausgeben();

    v.sortieren();
    std::cout << "Sortiertes Array:   ";
    v.ausgeben();

    int suchwerte[] = {1, 5, 10, 100};
    for (int sw : suchwerte) {
        int ergebnis = v.bin_suche(sw);
        if (ergebnis >= 0) {
            std::cout << "Suche " << sw << ": Gefunden an Index " << ergebnis << std::endl;
        }
        else {
            std::cout << "Suche " << sw << ": Nicht gefunden" << std::endl;
        }
    }

    return 0;
}
