#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>

using namespace std;
ofstream out("rez.txt");
    struct mokslai{
    string vardas;
    string pavarde;
    string dalykas;
    int pazymys;
    };
    void kiekElementu(int &kiekis, const char byla[]);
    void skaito(mokslai Struktura[], int kiekis, const char byla[]);
    void raso(mokslai Struktura[], int kiekis, string txt);


int main()
{
    int mokytojai, mokiniai;
    const char mokytojai1[] = "mokytojai.txt";
    const char mokiniai1[] = "mokiniai.txt";
    kiekElementu(mokytojai, mokytojai1);
    kiekElementu(mokiniai, mokiniai1);
    mokslai mokytojai2[mokytojai], mokiniai2[mokiniai];
    skaito(mokytojai2, mokytojai, mokytojai1);
    skaito(mokiniai2, mokiniai, mokiniai1);
    raso(mokytojai2, mokytojai, "Mokytojai\n");
    raso(mokiniai2, mokiniai, "Mokiniai\n");

    out.close();
    return 0;
}
//-----------------------------------------------------------------
void kiekElementu(int &kiekis, const char byla[])
{
    ifstream in(byla);
    mokslai LaikStruktura[1];
    kiekis=0;
    while(!in.eof()){
        in>>LaikStruktura[0].vardas>>LaikStruktura[0].pavarde>>LaikStruktura[0].dalykas>>LaikStruktura[0].pazymys;
        kiekis++;
    }
    in.seekg(0);
    in.close();
}
//-----------------------------------------------------------------
void skaito(mokslai Struktura[], int kiekis, const char byla[])
{
    ifstream in(byla);
    for(int i=0; i<kiekis; i++){
        in>>Struktura[i].vardas>>Struktura[i].pavarde>>Struktura[i].dalykas>>Struktura[i].pazymys;
    }
    in.close();
}
//------------------------------------------------------------------
void raso(mokslai Struktura[], int kiekis, string txt)
{
    out<<txt;
    for(int i=0; i<kiekis; i++){
        out<<setw(10)<<left<<Struktura[i].vardas<<setw(15)<<right<<Struktura[i].pavarde<<setw(15)<<right<<Struktura[i].dalykas<<setw(5)<<right<<Struktura[i].pazymys;
        out<<endl;
    }
}
