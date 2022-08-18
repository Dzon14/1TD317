#include <string>
#include <cctype>
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

// Globala konstanter:

// Tips: Anv�nd de globala konstanterna ANTAL_BOKSTAVER och ANTAL_SPRAK
// ist�llet f�r v�rdena 26 och 4 i programmet.
const int ANTAL_BOKSTAVER = 26;  // A-Z
const int ANTAL_SPRAK = 4;

// 2d-arrayen TOLK_HJALP inneh�ller bokstavsfrekvensen i %
// f�r fyra spr�k. TOLK_HJALP[0][0] �r frekvensen av
// bokstaven a f�r engelska. TOLK_HJALP[0][25] �r frekvensen av
// bokstaven z f�r engelska.
// Arrayen �r en GLOBAL KONSTANT och skall allts� ej skickas
// som parameter till den funktion som beh�ver den.
const double TOLK_HJALP[ANTAL_SPRAK][ANTAL_BOKSTAVER]=
       {{8.27,1.48,2.94,4.03,11.78,2.22,1.72,6.77, // engelska
         7.39,0.12,0.81,3.76,2.85,6.71,7.79,1.54,
         0.05,5.95,6.69,9.07,2.66,1.13,2.14,0.19,
         1.89,0.03},
        {7.97,1.40,3.55,3.79,16.89,1.02,1.00,0.75, // franska
         7.08,0.38,0.04,5.51,2.82,8.11,5.19,2.78,
         1.01,6.69,8.35,7.22,6.09,1.35,0.02,0.54,
         0.30,0.15},
        {9.50,1.11,1.53,5.30,8.94,1.74,3.57,3.94,  // svenska
         3.98,0.89,3.26,4.93,3.41,8.46,5.01,1.77,
         0.00,6.73,5.56,9.20,1.94,2.42,0.00,0.05,
         0.45,0.00},
        {5.12,1.95,3.57,5.07,16.87,1.35,3.00,5.79, // tyska
         8.63,0.19,1.14,3.68,3.12,10.64,1.74,0.42,
         0.01,6.30,6.99,5.19,3.92,0.77,1.79,0.01,
         0.69,1.24}};

// klassdeklaration

class Text {
private:
    string in;
    int antal;
    int histogram[ANTAL_BOKSTAVER];
    double relativHistogram[ANTAL_BOKSTAVER];

public:
    Text();
    void setText(const string &nyText);
    bool beraknaHistogramAbs();
    void skrivHistogramAbs();
    void absTillRel();
    void plottaHistogramRel();
    void beraknaHistogram();
    string tolka();
};

void namn_pa_fil(string &filnamn);
void inlasning(string filnamn, string &text);

// Huvudprogram:

int main()
{
    // Deklarera variabler
    string text;
    string filnamn;
    Text minText;  // Ett objekt av typen Text skapas

    // Läser in filen
    namn_pa_fil(filnamn);
    inlasning(filnamn, text);

    // Skicka strängen text till objektet minText
    minText.setText(text);

    // Beräkna och skriv ut histogrammet
    minText.beraknaHistogram();

    // Plottar det relativa histogrammet
    minText.plottaHistogramRel();

    // Beräknar och tolkar språk
    minText.tolka();
    
    return 0;
}

void namn_pa_fil(string &filnamn) {
    cout << "Ange filnamn: " << endl;
    getline(cin, filnamn);

    // Om ".txt" ej är i filnamnet, läggs det till
    if (filnamn.rfind(".txt") == string::npos)
    {
        filnamn.append(".txt");
    }
}

void inlasning(string filnamn, string &text) {
    char tecken;

    ifstream fin(filnamn.c_str());

    if (!fin)
    {
        cout << "Filen hittas ej" << endl;
        exit(EXIT_FAILURE);
    }

    while (fin.get(tecken))
    {
        text.push_back(tecken);
    }
}

Text::Text() {
  in = "";
  antal = 0;

  // nollställ
  for (int i = 0; i < ANTAL_BOKSTAVER; i++) {
    histogram[i] = 0;
    relativHistogram[i] = 0;
  }
};

void Text::setText(const string &nyText) {
    in = nyText;
}

bool Text::beraknaHistogramAbs() {
    bool bokstav = false;

    for (int i = 0; i < in.length(); i++) {

        //Om en bokstav hittas på den platsen i strängen.
        if (isalpha(in.at(i))) { // isalpha returnerar sant om tecknet är en bokstav
            antal++;
            bokstav = true; 
        }
        int index;

        //Kolla versal
        if (in.at(i) <= 'z' && in.at(i) >= 'a') {
            index = in.at(i) - 'a';
        histogram[index]++;
        }

        //Kolla gemen
        if (in.at(i) <= 'Z' && in.at(i) >= 'A') {
            index = in.at(i) - 'A';
            histogram[index]++;
        }
  }
  return bokstav;
}

// Skriver ut bokstavshistogram
void Text::skrivHistogramAbs() {
    cout << "Resultat for A-Z" << endl;
    cout << "Totala antalet bokstaver: " << antal << endl;
    cout << "Bokstavsfordelning: " << endl;

    for (int i = 0; i < ANTAL_BOKSTAVER; i++) {
        char bokstav = char(i + 'A'); //Ger teckenvärde

        cout << bokstav << ":" << "\t" << histogram[i] << endl;
    }
}

void Text::absTillRel() {
    for (int i = 0; i < ANTAL_BOKSTAVER; i++)
    {
        if (histogram[i] > 0)
        {
            double procent = (double) histogram[i] / antal * 100;
            relativHistogram[i] = procent;
        }
    }
    cout << "Resultat for bokstaverna A-Z" << endl;
    cout << "Totala antalet bokstaver: " << antal << endl;
}

void Text::plottaHistogramRel() {
    for (int i = 0; i < ANTAL_BOKSTAVER; i++) {
        if (histogram[i] > 0) {
            int trunkering = (relativHistogram[i] / 0.5 + 0.5);
            cout << char(i + 'A') << " ";

            // Skriver ut *
            for (int j = 0; j < trunkering; j++) {
                cout << "*";
            }
            cout << endl;
        }
    }
}

void Text::beraknaHistogram() {
    if (!beraknaHistogramAbs()) {
    return;
  }
  absTillRel();
}

string Text::tolka() {
double diff[ANTAL_SPRAK];
    double summa[ANTAL_SPRAK];
    string sprak[ANTAL_SPRAK] = {"engelska", "franska", "svenska", "tyska"};

    // Nollställer
    for (int i = 0; i < ANTAL_SPRAK; i++)
    {
        diff[i] = 0;
        summa[i] = 0;
    }

    // Kvadrera skillnader
    for (int i = 0; i < ANTAL_BOKSTAVER; i++)
    {
        for (int j = 0; j < ANTAL_SPRAK; j++)
        {
            diff[j] = TOLK_HJALP[j][i] - relativHistogram[i];
            summa[j] += diff[j] * diff[j];
        }
    }

    // Olika språks kvadratsummor
    cout << "engelska har kvadratsumman= " << summa[0] << endl;
    cout << "franska har kvadratsumman= " << summa[1] << endl;
    cout << "svenska har kvadratsumman= " << summa[2] << endl;
    cout << "tyska har kvadratsumman= " << summa[3] << endl;

    double min = summa[0];
    int index = 0;

    // Ger det rätta språket (kanske)
    for (int i = 0; i < ANTAL_SPRAK; i++)
    {
        if (min > summa[i])
        {
            min = summa[i];
            index = i;
        }
    }
    cout << "Det ar mest troligt att spraket ar " << sprak[index] << endl;

   return sprak[index];
}