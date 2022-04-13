#include <iostream>
#include "Lista.h"
#include "Lista.cpp"
#include "Klasy.h"
#include <fstream>

using namespace std;


int main(int argc, char* argv[])
{
    string in1, in2, out1, out2;
    for (int i = 1; i < argc; i++)
    {
        string parametr = argv[i];
        if (parametr == "-in1") in1 = argv[i + 1];
        if (parametr == "-in2") in2 = argv[i + 1];
        if (parametr == "-out1") out1 = argv[i + 1];
        if (parametr == "-out2") out2 = argv[i + 1];
    }

    Lista<VPlayer> listek;
    VPlayer gracz;

    ifstream plo(in1);

    while (!plo.eof())
    {
        plo >> gracz;

        listek.push_back(gracz);
    }

    listek.sort([](VPlayer g1, VPlayer g2) {return g1.wzrost < g2.wzrost; });

    cout << "WZROST" << endl;
    listek.print();

    listek.sort([](VPlayer g1, VPlayer g2) {return g1.wiek < g2.wiek; });
    cout << "WIEK" << endl;
    listek.print();

    listek.save_binary(out1);

    Lista<VPlayer> listek2;

    listek2.read_binary(out1);

    cout << endl << "2222" << endl;
    listek2.print();
    cout << listek.get(0);

    listek2.pop_front();
    cout << endl << "popfront" << endl;
    listek2.print();
    listek2.reverse_sort([](VPlayer g1, VPlayer g2) {return g1.wiek <= g2.wiek; });
    cout << endl << "reversesort" << endl;
    listek2.print();

    listek2.erase(1);
    cout << endl << "erase1" << endl;
    listek2.print();


    Lista<CPlayer> szachy;
    Lista<CPlayer> szachy2;
    CPlayer graczs;

    ifstream plo2(in2);

    while (!plo2.eof())
    {
        plo2 >> graczs;
        szachy.push_back(graczs);
    }

    szachy.sort([](CPlayer gracz1, CPlayer gracz2) {return gracz1.wiek > gracz2.wiek; });

    cout << endl << endl << "Najmlodszy:" << endl << szachy.get(0);

    szachy.save_binary(out2);

    szachy2.read_binary(out2);

    szachy2.print();

    szachy2.pop_back();
    szachy2.pop_front();

    szachy2.print();

    szachy2.push_back(szachy.get(11));

    cout << endl << "pushback" << endl << szachy2.get(36);

    cout << endl << szachy2.search(szachy.get(11)) << endl;

    plo.close();
    plo2.close();
}


