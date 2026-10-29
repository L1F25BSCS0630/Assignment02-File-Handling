// Name: SHARIQ WASEEM
// Registration No: L1F25BSCS0630
// Assignment 2 - Question 2: Parking Report

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main()
{
    ifstream inFile("parking.txt");

    if (!inFile)
    {
        cout << "parking.txt not found!";
        return 0;
    }

    int d, m, y;
    char slash;

    inFile >> d >> slash >> m >> slash >> y;

    inFile.ignore(100, '\n');
    inFile.ignore(100, '\n');

    ofstream outFile("receipts.txt");

    outFile << "Receipts for "
            << d << "/" << m << "/" << y << endl;

    cout << "Parking report for "
         << d << "/" << m << "/" << y << endl;

    char plate[15], longestPlate[15] = "";

    char type;
    int inHour, inMin, outHour, outMin;
    int vehicles = 0, cars = 0, bikes = 0;
    int totalCollected = 0;
    int longestStay = 0;

    while (inFile >> plate >> type
                  >> inHour >> slash >> inMin
                  >> outHour >> slash >> outMin)
    {
        int start = inHour * 60 + inMin;
        int finish = outHour * 60 + outMin;

        int minutes = finish - start;

        int hours = (minutes + 59) / 60;

        if (hours == 0)
        {
            hours = 1;
        }

        int fee;

        if (type == 'C')
        {
            fee = hours * 100;
            cars++;
        }
        else
        {
            fee = hours * 40;
            bikes++;
        }

        vehicles++;
        totalCollected += fee;

        cout << plate << " ";

        if (type == 'C')
        {
            cout << "Car ";
        }
        else
        {
            cout << "Bike ";
        }

        cout << minutes / 60 << " h "
             << minutes % 60 << " min "
             << "Fee: " << fee << endl;

        outFile << plate << " " << fee << endl;

        if (minutes > longestStay)
        {
            longestStay = minutes;
            strcpy(longestPlate, plate);
        }
    }

    cout << "Vehicles: " << vehicles << endl;

    if (vehicles == 0)
    {
        cout << "No vehicles found!" << endl;
    }
    else
    {
        cout << "Cars: " << cars
             << " Bikes: " << bikes << endl;

        cout << "Total collected: "
             << totalCollected << endl;

        cout << "Longest stay: "
             << longestPlate << " ("
             << longestStay / 60 << " h "
             << longestStay % 60 << " min)"
             << endl;
    }

    inFile.close();
    outFile.close();

    return 0;
}