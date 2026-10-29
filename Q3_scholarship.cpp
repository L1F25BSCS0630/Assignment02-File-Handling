#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main()
{
    char path[100];
    char name[30];
    char topName[30] = "";

    int n;
    int actual = 0;
    int eligible = 0;

    double cgpa;
    double total = 0;
    double topCGPA = -1;

    cout << "Enter the file name: ";
    cin.getline(path, 100);

    ifstream inFile(path);

    if (!inFile.is_open())
    {
        cout << "Could not open " << path << "!";
        return 0;
    }

    inFile >> n;
    inFile.ignore(100, '\n');

    if (n > 30)
    {
        cout << "Too many students!";
        return 0;
    }

    ofstream outFile("scholarship.txt");

    for (int i = 0; i < n; i++)
    {
        inFile.getline(name, 30, ',');

        if (inFile.fail())
        {
            break;
        }

        inFile >> cgpa;
        inFile.ignore(100, '\n');

        if (inFile.fail())
        {
            break;
        }

        cout << "[" << name << "] CGPA: " << cgpa << endl;

        total = total + cgpa;
        actual++;

        if (cgpa >= 3.50)
        {
            eligible++;
            outFile << name << "," << cgpa << endl;
        }

        if (cgpa > topCGPA)
        {
            topCGPA = cgpa;
            strcpy(topName, name);
        }
    }

    if (actual < n)
    {
        cout << "Warning: only " << actual
             << " of " << n << " records found." << endl;
    }

    if (actual == 0)
    {
        cout << "No students found!";
        return 0;
    }

    cout << "Students: " << actual << endl;
    cout << "Average CGPA: " << total / actual << endl;
    cout << "Eligible for scholarship: " << eligible << endl;
    cout << "Top student: " << topName
         << " (" << topCGPA << ")" << endl;

    inFile.close();
    outFile.close();

    return 0;
}