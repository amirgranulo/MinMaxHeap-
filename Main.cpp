#include "Heap.h"
#include<iostream>

using namespace std;

int main() {
    Heap<int> x;
    x.Push(3);
    x.Push(5);
    x.Push(1);
    x.Push(6);
    x.Push(2);
    x.Push(0);
    x.Push(9);
    x.Push(10);
    x.Push(11);
    x.Push(-5);
    x.Push(4);
    x.Push(500);
    x.Push(14);
    x.Push(20);
    x.Push(-1);

    x.Ispisi();
    /*cout<<endl;
    //x.PopMin();
    x.PopMax();
    x.Ispisi();
    cout<<endl;
    x.PopMin();
    x.Ispisi();
      cout<<endl;
    x.PopMin();
    x.Ispisi();
    */
    vector<int> xx = {3,5,1,6,2,0,9,10,11,-5,4,500,14,20,-1};
    Heap<int> y(xx);
    cout<<endl;
    y.Ispisi();
    y.PopMax();
    cout<<endl;
    y.Ispisi();
    y.PopMax();
    cout<<endl;
    y.Ispisi();
    y.PopMin();
    cout<<endl;
    y.Ispisi();



}
