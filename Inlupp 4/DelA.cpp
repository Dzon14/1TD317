//
// Programskal till inl�mningsuppgift 4 - deluppgift A
//
// Hanterar fallet med 26 bokst�ver A-Z

#include <iostream>
#include <string>
#include <cctype>
#include <cmath>
using namespace std;

const int ANTAL_BOKSTAVER = 26;  //A-Z

// Funktionsdeklarationer:
void berakna_histogram_abs(const string& in, int frekvens[], int &antal);
void skriv_histogram_abs(int frekvens[], int &antal);


// Huvudprogram:
int main() {

  string in; //Invärdet användaren ger. 
  int frekvens[ANTAL_BOKSTAVER];
  int antal; //Antalet bokstäver 

  cout << "Ge en rad med text: " <<endl;
  getline(cin, in);
 
  berakna_histogram_abs(in, frekvens, antal);
  skriv_histogram_abs(frekvens, antal);

  return 0;
}

// Funktionsdefinitioner:
void berakna_histogram_abs(const string& in, int frekvens[], int &antal) {
  antal = 0;

  //Sätter alla värden till 0
  for (int i = 0; i < ANTAL_BOKSTAVER; i++) {
    frekvens[i] = 0;
  }

  for (int i = 0; i < in.length(); i++) {

    //Om en bokstav hittas på den platsen i strängen.
    if (isalpha(in.at(i))) { // isalpha returnerar sant om tecknet är en bokstav
      antal++;
    }
    
    int index;

    //Kolla versal
    if (in.at(i) <= 'z' && in.at(i) >= 'a') {
      index = in.at(i) - 'a';
      frekvens[index]++;
    }

    //Kolla gemen
    if (in.at(i) <= 'Z' && in.at(i) >= 'A') {
      index = in.at(i) - 'A';
      frekvens[index]++;
    }
  }
}

void skriv_histogram_abs(int frekvens[], int &antal) {
  cout << "Resultat for bokstaverna A-Z" << endl;
  cout << "Totala antalet bokstaver: " << antal << endl;
  cout << "Bokstavsfordelning: " << endl;

  //Skriver ut antal för alla bokstäver
  for (int i = 0; i < ANTAL_BOKSTAVER; i++) {
    char bokstav = char(i + 'A'); //Ger teckenvärde

    cout << bokstav << ": " << frekvens[i] << endl;
  }
}