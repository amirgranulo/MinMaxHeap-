#ifndef HEAP_H
#define HEAP_H
#include <iostream>
#include <vector>
using namespace std;


template <typename Tip>

class Heap {
    vector<Tip> niz;

    int LijevoDijete(int indeks) { return 2*indeks+1; }
    int DesnoDijete(int indeks) { return 2*indeks+2; }
    int Roditelj(int indeks) { return (indeks-1)/2; }

    void UpHeap_min(int indeks);
    void UpHeap_max(int indeks);

    void DownHeap_min(int indeks);
    void DownHeap_max(int indeks);

public:
    Heap();
    Heap(vector<Tip> niz);
    Heap(const Heap &kopija);

    ~Heap() {};

    Heap& operator=(const Heap& b) { niz = b.niz;};
    void Push(Tip element);
    void PopMin();
    void PopMax();

    void Ispisi();
    void Clear() { niz.clear(); };
    int Size() { return niz.size(); };
    Tip Min() { return niz[0];}
    Tip Max() {return max(niz[1],niz[2]);}



};


#include "Heap.cpp"
#endif
