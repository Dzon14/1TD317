//---------------------------------------------
// Filnamn: Funktioner.cpp
// Syfte: Skriva ett program som gör några enkla beräkningar utifrån användarens inmatningar.
// Indata: tal och operation
// Utdata: resultat
//
// Programmerare: Daniel Danielsson
// Datum: 29/06/22
//---------------------------------------------

#include <iostream>
using namespace std;

// Funktionsdeklarationer
void skrivInfo(); // utskrift //Börja med denna
int lasEttTal(int i);
char lasOp();
void ordna(int &tal1, int &tal2);
int berakna(char op, int tal1, int tal2);
void skrivResultat(int resultat); // utskrift

int main()
{

  skrivInfo();

  int tal1 = lasEttTal(1);
  int tal2 = lasEttTal(2);

  char op = lasOp();
  ordna(tal1, tal2);
  int svar = berakna(op, tal1, tal2);

  skrivResultat(svar);

  return 0;
}

// Funktionsdefinitioner

/**
 * Skriver ut information
 */
void skrivInfo()
{
  cout << "Valkommen till programmet - funktioner" << endl;
  cout << "Skriv tva tal och en operation: a, m eller k." << endl;
}

/**
 * Läser in ett tal
 * @param i är ett index som representerar talet som ska skrivas in
 * @return int som skrivits in.
 */
int lasEttTal(int i)
{
  cout << "Skriv tal " << i << ": " << endl;

  int tal;
  cin >> tal;
  return tal;
}

/**
 * Läser in en operation
 * @return char som representerar den valda operationen.
 */
char lasOp()
{
  char op;

  cout << "Vilken operation skall anvandas (a, b eller c)?" << endl;
  cout << "a. Addition" << endl;
  cout << "b. Multiplikation" << endl;
  cout << "c. Kvadratsumma" << endl;

  cin >> op;

  if (op == 'a' || op == 'b' || op == 'c')
  {
    return op;
  }
  else
  {
    cout << "Felaktig inmatning, forsok igen." << endl;
    lasOp();
  }
}

/**
 * Sorterar två inlästa tal i storleksordning.
 * @param a1, ett heltal
 * @param a2, ett andra heltal
 */
void ordna(int &tal1, int &tal2)
{

  if (tal1 > tal2)
  {
    int temp = tal1;
    tal1 = tal2;
    tal2 = temp;
  }
}

/**
 * Utför beräkning beroende på utförd operation.
 * @param tal1 som är den undre gränsen
 * @param tal2 som är den övre gränsen
 * @return int resultat efter beräkning.
 */
int berakna(char op, int tal1, int tal2)
{
  int tot;

  // För att undvika multiplikation med 0.
  if (op == 'b')
  {
    tot = 1;
  }
  else
  {
    tot = 0;
  }

  for (int i = tal1; i <= tal2; i++)
  {
    switch (op)
    {
    case 'a':
      tot += i;
      break;

    case 'b':
      tot *= i;
      break;

    case 'c':
      tot += i * i;
      break;

    default:
      cout << "Du har angivit en ogiltigt operation" << endl;
      break;
    }
  }

  return tot;
}

/**
 * Skriver ut resultat från beräkningen.
 * @param resultat
 */
void skrivResultat(int resultat)
{
  cout << "Resultatet ar: " << resultat << endl;
}