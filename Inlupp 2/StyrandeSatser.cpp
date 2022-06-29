//---------------------------------------------
// Filnamn: StyrandeSatser.cpp
// Syfte:   Skriva ett program som hanterar data för tävlande i en idrottstävling.
// Indata: startnummer, starttid & måltid
// Utdata: vinnare, tid & antal tävlande.
//
// Programmerare: Daniel Danielsson
// Datum: 25/06/22
//---------------------------------------------

#include <iostream>
using namespace std;

/**
 * Converts parameters to seconds
 * @param h is the number of hours
 * @param min is the number of minutes
 * @param sec is the number of seconds
 * @return int, the amount of seconds
 */
int convertToSeconds(int h, int min, int sec)
{
    return (h * 3600) + (min * 60) + sec;
}

int main()
{
    int nbr = 0;                   // number of contestants.
    int wNbr;                      // The winning number
    int startNbr;                  // Starting number
    int startH;                    // starting time (hours)
    int startMin;                  // starting time (minutes)
    int startSec;                  // startint time (second)
    int endH;                      // Ending time (hours)
    int endMin;                    // Ending time (minutes)
    int endSec;                    // Ending time (seconds)
    int currentBestTime = INT_MAX; // Starting at max int.

    // Run loop until starting number is 0 or less.
    while (startNbr > 0)
    {

        cout << "Startnummer? ";
        cin >> startNbr; // If startNbr is 0 or less, the loop will end here.

        if (startNbr <= 0)
        {
            break;
        }

        cout << "Starttid? ";
        cin >> startH >> startMin >> startSec;

        cout << "Maltid? ";
        cin >> endH >> endMin >> endSec;
        // cout << endl;

        // Convering time to seconds.
        int startTime = convertToSeconds(startH, startMin, startSec);
        int endTime = convertToSeconds(endH, endMin, endSec);

        // If starting time is greater than ending time, a new day must be applied.
        if (startTime > endTime)
        {
            endTime += (24 * 3600);
        }

        int finishTime = endTime - startTime;

        if (finishTime < currentBestTime)
        {
            currentBestTime = finishTime;
            wNbr = startNbr;
        }
        nbr++; // Increasing number of contestants.
    }

    if (nbr <= 0)
    {
        cout << "Inga tavlande" << endl;
    }
    else
    {

        // Converting the best time into h, min, sec...
        int bestTimeH = (currentBestTime / 3600);
        int bestTimeMin = ((currentBestTime % 3600) / 60);
        int bestTimeSec = (currentBestTime % 60);

        // Printing the final result
        cout << "Vinnare ar startnr: " << wNbr << endl;
        cout << "Tim: " << bestTimeH << " "
             << "Min: " << bestTimeMin << " "
             << "Sek: " << bestTimeSec << endl;
        cout << "Antal tavlande: " << nbr << endl;
    }

    cout << "Programmet avslutas" << endl;
    return 0;
}
