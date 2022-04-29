#ifndef HEAP_CPP
#define HEAP_CPP
#include "Heap.h"
#include <iostream>
#include <math.h>
#include <algorithm>

template <typename Tip>
Heap<Tip>::Heap() {
    niz =  vector<Tip>();
}
template <typename Tip>
Heap<Tip>::Heap(vector<Tip> niz2) {
  niz = niz2;
    for (int i = Roditelj(niz.size()-1); i >= 0 ; i --) {
        if ( (int)(log2(i+1))  % 2 == 0) {
            DownHeap_min(i);
        }
        else {
            DownHeap_max(i);
        }
    }

}

template <typename Tip>
Heap<Tip>::Heap(const Heap<Tip> &kopija) {
    this.niz = kopija.niz;

}


template <typename Tip>
void Heap<Tip>::UpHeap_min(int indeks) {


    int roditelj_roditelja = Roditelj(Roditelj(indeks));
    if(roditelj_roditelja >= 0 && niz[roditelj_roditelja] > niz[indeks]) { // >= 0 jer moze biti roditelj na 0 indeksu
            swap(niz[roditelj_roditelja],niz[indeks]);
            UpHeap_min(roditelj_roditelja);
    }
}

template <typename Tip>
void Heap<Tip>::UpHeap_max(int indeks) {


    int roditelj_roditelja = Roditelj(Roditelj(indeks));
    if(roditelj_roditelja > 0 && niz[roditelj_roditelja] < niz[indeks]) { // ali ovdje ne moze biti roditelj na 0 indeksu
            swap(niz[roditelj_roditelja],niz[indeks]);
            UpHeap_min(roditelj_roditelja);
    }
}
template <typename Tip>
void Heap<Tip>::DownHeap_min(int indeks) {

    if (LijevoDijete(LijevoDijete(indeks)) > niz.size() -1 && LijevoDijete(indeks) <= niz.size() -1) { // znaci da je ovo zadnji min nivo i da ima djece ili dijete(na max nivou)
        if ( DesnoDijete(indeks) < niz.size()) { // ako ima desno dijete,provjerit koji je manji od ta 2 djeteta i s tim ga zamijeniti ako je manji od niz[indeks]
            if (niz[indeks] > niz[LijevoDijete(indeks)] && niz[LijevoDijete(indeks)] <= niz[DesnoDijete(indeks)] ) {
                swap(niz[indeks],niz[LijevoDijete(indeks)]);


            }
            else if ( niz[indeks] > niz[DesnoDijete(indeks)]) {
                swap(niz[indeks],niz[DesnoDijete(indeks)]);

            }

        }
        else {
            if (niz[indeks] > niz[LijevoDijete(indeks)]) {
                swap(niz[indeks],niz[LijevoDijete(indeks)]);
            }
        }
    }
    else if (LijevoDijete(LijevoDijete(indeks)) < niz.size()  ){

        // imat ce od 1 do 4 unucadi tj djece od minheap nivoa, treba naci najmanji i zamijenit ga s tim ako je indeks veci od nekog od tih
        vector<pair<int,int>> unucad;
        int ll = LijevoDijete(LijevoDijete(indeks));
        int ld = LijevoDijete(DesnoDijete(indeks));
        int dl = DesnoDijete(LijevoDijete(indeks));
        int dd = DesnoDijete(DesnoDijete(indeks));
        if ( ll < niz.size()) { unucad.push_back(make_pair(niz[ll],ll));}
        if ( ld < niz.size()) { unucad.push_back(make_pair(niz[ld],ld));}
        if ( dl < niz.size()) { unucad.push_back(make_pair(niz[dl],dl));}
        if ( dd < niz.size()) { unucad.push_back(make_pair(niz[dd],dd));}

        sort(unucad.begin(),unucad.end()); // po defaultu sortira po prvom elementu u paru
        if (niz[indeks] > unucad[0].first) {
            swap(niz[indeks],niz[unucad[0].second]);
            DownHeap_min(unucad[0].second);

        }
    }


}

template <typename Tip>
void Heap<Tip>::DownHeap_max(int indeks) {

    if (LijevoDijete(LijevoDijete(indeks)) > niz.size() -1 && LijevoDijete(indeks) <= niz.size() -1) { // zadnji max nivo koji ima dijete/djecu , tj. ima ispod sebe min nivo
        if ( DesnoDijete(indeks) < niz.size()) { // ako ima desno dijete,provjerit koji je veci od ta 2 djeteta i s tim ga zamijeniti ako je veci od niz[indeks]
            if (niz[indeks] < niz[LijevoDijete(indeks)] && niz[LijevoDijete(indeks)] >= niz[DesnoDijete(indeks)] ) {
                swap(niz[indeks],niz[LijevoDijete(indeks)]);


            }
            else if ( niz[indeks] < niz[DesnoDijete(indeks)]) {
                swap(niz[indeks],niz[DesnoDijete(indeks)]);

            }

        }
        else { // ako nema desno dijete
            if (niz[indeks] < niz[LijevoDijete(indeks)]) {
                swap(niz[indeks],niz[LijevoDijete(indeks)]);
            }
        }
    }
    else if (LijevoDijete(LijevoDijete(indeks)) < niz.size()  ){

        // imat ce od 1 do 4 unucadi tj djece od max nivoa, treba naci najmanji i zamijenit ga s tim ako je niz[indeks] veci od nekog od tih
        vector<pair<int,int>> unucad;
        int ll = LijevoDijete(LijevoDijete(indeks));
        int ld = LijevoDijete(DesnoDijete(indeks));
        int dl = DesnoDijete(LijevoDijete(indeks));
        int dd = DesnoDijete(DesnoDijete(indeks));
        if ( ll < niz.size()) { unucad.push_back(make_pair(niz[ll],ll));}
        if ( ld < niz.size()) { unucad.push_back(make_pair(niz[ld],ld));}
        if ( dl < niz.size()) { unucad.push_back(make_pair(niz[dl],dl));}
        if ( dd < niz.size()) { unucad.push_back(make_pair(niz[dd],dd));}

        sort(unucad.begin(),unucad.end()); // po defaultu sortira po prvom elementu u paru
        if (niz[indeks] < unucad[unucad.size()-1].first) { // unucad[size-1] = najvece dijete, ako je niz[indeks] manji od NAJVECEG djeteta zamijeni sa najvecim,
            swap(niz[indeks],niz[unucad[unucad.size()-1].second]);
            DownHeap_max(unucad[unucad.size()-1].second);

        }
    }


}



template <typename Tip>
void Heap<Tip>::Push(Tip element) {
    niz.push_back(element);
    int nivo = log2(niz.size());

    int indeks = niz.size()-1;

    if (nivo % 2 == 0 ) { // za parni nivo tj. min nivo
        if ( Roditelj(indeks) >= 0) { // ako ima roditelja
            if (niz[Roditelj(indeks)] < niz[indeks] ) { // ako je roditelj manji od ubacenog elementa treba ih zamijeniti
                swap(niz[Roditelj(indeks)],niz[indeks]); // to znaci da ce ubaceni element sada biti na max heapu
                UpHeap_max(Roditelj(indeks)); // poziva se upheapmax da stavi novi element gdje treba ako vec nije na dobroj poziciji
            }
            else { // u suprotnom samo treba upheapmin jer ce biti na min levelu
                UpHeap_min(indeks);
            }
        }

    }
    else { // za neparni tj. max nivo
        if (Roditelj(indeks) >= 0) {
            if (niz[Roditelj(indeks)] > niz[indeks]) {
                swap(niz[Roditelj(indeks)],niz[indeks]);
                UpHeap_min(Roditelj(indeks));
            }
            else {
                UpHeap_max(indeks);
            }
        }
    }
}

template <typename Tip>
void Heap<Tip>::PopMin() {
    if (niz.size() > 1) {
    swap(niz[0],niz[niz.size()-1]);
    niz.pop_back();
    DownHeap_min(0);
    }
    else if (niz.size() != 0) {
        niz.pop_back();
    }
}
template <typename Tip>
void Heap<Tip>::PopMax() {

    if(niz.size() > 1) {

        if (niz[1] >= niz[2] ) {

            swap(niz[1],niz[niz.size()-1]);
            niz.pop_back();
            DownHeap_max(1);
        }
        else {

            swap(niz[2],niz[niz.size()-1]);
            niz.pop_back();
            DownHeap_max(2);
        }
    }
    else if (niz.size() != 0) {
        niz.pop_back();
    }

}

template <typename Tip>
void Heap<Tip>::Ispisi() {
    for (int i = 0; i < niz.size(); i ++ ) {
        cout<< niz[i]<<" ";
    }

}




#endif
