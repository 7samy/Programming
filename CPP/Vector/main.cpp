#include <iostream>
#include "vector.h"

int main() {
    // 1. Test: Konstruktoren und Ausgabe
    std::cout << "--- Test 1: Konstruktoren & Ausgabe ---" << std::endl;
    Vector v1(3);
    v1[0] = 1.0; v1[1] = 2.0; v1[2] = 3.0;
    std::cout << "v1 (Größe 3): " << v1 << std::endl;

    // 2. Test: Copy-Konstruktor (Wichtig für Stabilität!)
    std::cout << "\n--- Test 2: Copy-Konstruktor ---" << std::endl;
    Vector v2 = v1; 
    v2[0] = 99.9; // Ändern von v2 darf v1 nicht beeinflussen!
    std::cout << "v1 (unverändert): " << v1 << std::endl;
    std::cout << "v2 (Kopie mit Änderung): " << v2 << std::endl;

    // 3. Test: Zuweisungsoperator
    std::cout << "\n--- Test 3: Zuweisungsoperator ---" << std::endl;
    Vector v3;
    v3 = v1;
    std::cout << "v3 = v1: " << v3 << std::endl;

    // 4. Test: Arithmetik mit Vektoren
    std::cout << "\n--- Test 4: Vektor-Arithmetik ---" << std::endl;
    Vector a(2), b(2);
    a[0] = 10; a[1] = 20;
    b[0] = 5;  b[1] = 2;
    
    Vector sum = a + b;
    Vector diff = a - b;
    Vector prod = a * b;

    std::cout << "a: " << a << ", b: " << b << std::endl;
    std::cout << "a + b = " << sum << std::endl;
    std::cout << "a - b = " << diff << std::endl;
    std::cout << "a * b = " << prod << " (elementweise)" << std::endl;

    // 5. Test: Arithmetik mit Skalaren (double)
    std::cout << "\n--- Test 5: Skalar-Arithmetik ---" << std::endl;
    Vector s = a + 5.0;
    std::cout << "a + 5.0 = " << s << std::endl;
    
    a += 10.0;
    std::cout << "a nach a += 10.0: " << a << std::endl;

    // 6. Test: push_back und setSize
    std::cout << "\n--- Test 6: Dynamik ---" << std::endl;
    Vector dyn(0);
    dyn.push_back(1.1);
    dyn.push_back(2.2);
    std::cout << "Nach 2x push_back: " << dyn << " (Größe: " << dyn.getSize() << ")" << std::endl;

    // 7. Test: Vergleich
    std::cout << "\n--- Test 7: Vergleich ---" << std::endl;
    Vector v_comp1(2), v_comp2(2);
    v_comp1[0] = 5; v_comp1[1] = 5;
    v_comp2[0] = 5; v_comp2[1] = 5;

    std::cout << "v_comp1 == v_comp2? " << (v_comp1 == v_comp2 ? "Ja" : "Nein") << std::endl;
    std::cout << "\n--- Test Ende: Destruktoren werden nun gerufen ---" << std::endl;
    return 0;
}
