#include <iostream>
#include <ctime>
#include <cmath>
#include <cstdlib>

using namespace std;

class Element {
public:
    int liczba;
    char znak;

    Element(int liczba = 0, char znak = '\0') : liczba(liczba), znak(znak) {}

    bool operator<(const Element& other) const {
        return (liczba < other.liczba) || (liczba == other.liczba && znak < other.znak);
    }
};

class TablicaDynamiczna {
private:
    Element* tablica;
    int maxRozmiar;
    int liczbElement;

public:
    TablicaDynamiczna() {
        maxRozmiar = 1;
        liczbElement = 0;
        tablica = new Element[maxRozmiar];
    }

    ~TablicaDynamiczna() {
        delete[] tablica;
    }

    Element& operator[](int indeks) {
        if (indeks < 0 || indeks >= liczbElement) {
            cout << "Indeks jest poza zakresem";
        }
        else return tablica[indeks];
    }

    int PodajLiczbeElement() {
        return liczbElement;
    }

    int PodajMaxRozmiar() {
        return maxRozmiar;
    }

    void dodajNaKoniec(const Element& wartosc)
    {
        if (liczbElement == maxRozmiar) {
            maxRozmiar *= 2;
            Element* nowaTablica = new Element[maxRozmiar];
            for (int i = 0; i < liczbElement; i++) {
                nowaTablica[i] = tablica[i];
            }
            delete[] tablica;
            tablica = nowaTablica;
        }
        tablica[liczbElement] = wartosc;
        liczbElement++;
    }

    int zwrocDaneindeks(int indeks)
    {
        if (indeks < 0 || indeks >= liczbElement) {
            cout << endl << "Indeks jest poza zakresem" << endl;
            return -1;
        }
        else {
            return tablica[indeks].liczba;
        }
    }

    void PodmienElementIndeks(int indeks, const Element& noweDane)
    {
        if (indeks < 0 || indeks >= liczbElement) {
            cout << endl << "Indeks jest poza zakresem" << endl;
        }
        else {
            tablica[indeks] = noweDane;
        }

    }

    void wyczyscTablice()
    {
        delete[] tablica;
        maxRozmiar = 1;
        liczbElement = 0;
        tablica = new Element[maxRozmiar];
    }

    void wypiszZawartoscTab()
    {
        cout << endl;
        for (int i = 0; i < liczbElement; i++) {
            cout << "[" << tablica[i].liczba << ", " << tablica[i].znak << "]";
        }
        cout << endl;
    }

    void bubblesort()
    {
        Element tmp;
        for (int i = 1; i < liczbElement; i++)
        {
            for (int j = liczbElement - 1; j >= 1; j--)
            {
                if (tablica[j] < tablica[j - 1])
                {
                    tmp = tablica[j - 1];
                    tablica[j - 1] = tablica[j];
                    tablica[j] = tmp;
                }
            }
        }
    }
};

int main() {
    TablicaDynamiczna tab1;
    const int order = 7;
    const int n = pow(10, order);
    double max_time_per_element = 0.0;
    srand(time(NULL));
    clock_t czas1 = clock();
    for (int i = 0; i < n; i++) {
        Element element;
        element.liczba = rand() % 10000;
        element.znak = 'a' + (rand() % ('z' - 'a' + 1));
        clock_t czas1_element = clock();
        tab1.dodajNaKoniec(element);
        clock_t czas2_element = clock();
        double time_per_element = (czas2_element - czas1_element) / (double)CLOCKS_PER_SEC;
        if (time_per_element > max_time_per_element)
        {
            max_time_per_element = time_per_element;
            cout << endl << "Odnotowano nowy najgorszy czas wynoszacy: " << max_time_per_element * 1000 << " milisekund" << " przy indeksie: " << i;
        }
    }

    clock_t czas2 = clock();
    double czas = (czas2 - czas1) / (double)CLOCKS_PER_SEC;

    cout << endl << "Czas calkowity: " << czas * 1000 << " milisekund; " << "czas zamortyzowany: " << (czas / n) * 1000 << " milisekund" << endl;
    //tab1.bubblesort();
    //tab1.wypiszZawartoscTab();
    tab1.wyczyscTablice();


    return 0;
}

/*for (int i = 10; i > 0; i--) {
     Element element(i, 'A' + i - 1);
     tab1.dodajNaKoniec(element);
 }

 cout << "Liczba elementow: " << tab1.PodajLiczbeElement() << endl;
 cout << "Max rozmiar: " << tab1.PodajMaxRozmiar() << endl;

 // Wyświetlenie zawartości tablicy
 for (int i = 0; i < tab1.PodajLiczbeElement(); i++) {
     cout << "[" << tab1[i].liczba << ", " << tab1[i].znak << "]";
 }
 cout << endl;

 // Modyfikacja elementu pod indeksem 4
 Element nowyElement(20, 'Z');
 tab1.PodmienElementIndeks(4, nowyElement);

 // Sortowanie i wyświetlenie zawartości tablicy
 tab1.bubblesort();
 for (int i = 0; i < tab1.PodajLiczbeElement(); i++) {
     cout << "[" << tab1[i].liczba << ", " << tab1[i].znak << "]";
 }
 cout << endl;

*/