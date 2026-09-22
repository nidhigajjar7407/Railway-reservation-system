#include <iostream>
#include <cstring>
using namespace std;

class Train
{
private:
    int trainNumber;
    char trainName[50];
    char source[50];
    char destination[50];
    char trainTime[20];

    static int trainCount;

public:

    Train()
    {
        trainNumber = 0;
        strcpy(trainName, "");
        strcpy(source, "");
        strcpy(destination, "");
        strcpy(trainTime, "");
    }

    Train(int no, char name[], char src[], char dest[], char time[])
    {
        trainNumber = no;
        strcpy(trainName, name);
        strcpy(source, src);
        strcpy(destination, dest);
        strcpy(trainTime, time);

        trainCount++;
    }

    ~Train()
    {
    }

    void inputTrainDetails()
    {
        cout << "\nEnter Train Number: ";
        cin >> trainNumber;

        cin.ignore();

        cout << "Enter Train Name: ";
        cin.getline(trainName, 50);

        cout << "Enter Source: ";
        cin.getline(source, 50);

        cout << "Enter Destination: ";
        cin.getline(destination, 50);

        cout << "Enter Train Time: ";
        cin.getline(trainTime, 20);

        trainCount++;
    }

    void displayTrainDetails()
    {
        cout << "\nTrain Number : " << trainNumber;
        cout << "\nTrain Name   : " << trainName;
        cout << "\nSource       : " << source;
        cout << "\nDestination  : " << destination;
        cout << "\nTrain Time   : " << trainTime;
        cout << "\n";
    }

    int getTrainNumber()
    {
        return trainNumber;
    }

    static int getTrainCount()
    {
        return trainCount;
    }

    void setTrainNumber(int no)
    {
        trainNumber = no;
    }

    void setTrainName(char name[])
    {
        strcpy(trainName, name);
    }

    void setSource(char src[])
    {
        strcpy(source, src);
    }

    void setDestination(char dest[])
    {
        strcpy(destination, dest);
    }

    void setTrainTime(char time[])
    {
        strcpy(trainTime, time);
    }
};

int Train::trainCount = 0;


class RailwaySystem
{
private:
    Train trains[100];
    int totalTrains;

public:

    RailwaySystem()
    {
        totalTrains = 0;
    }

    void addTrain()
    {
        if (totalTrains >= 100)
        {
            cout << "\nNo more space for new train records.\n";
            return;
        }

        cout << "\n--- Add New Train Record ---\n";

        trains[totalTrains].inputTrainDetails();

        totalTrains++;

        cout << "\nTrain record added successfully!\n";
    }

    void displayAllTrains()
    {
        if (totalTrains == 0)
        {
            cout << "\nNo train records found.\n";
            return;
        }

        cout << "\n--- All Train Records ---\n";

        for (int i = 0; i < totalTrains; i++)
        {
            cout << "\nTrain " << i + 1 << ":";
            trains[i].displayTrainDetails();
        }

        cout << "\nTotal Train Records: " << totalTrains << endl;
    }

    void searchTrainByNumber(int number)
    {
        bool found = false;

        for (int i = 0; i < totalTrains; i++)
        {
            if (trains[i].getTrainNumber() == number)
            {
                cout << "\n--- Train Found ---\n";
                trains[i].displayTrainDetails();

                found = true;
                break;
            }
        }

        if (!found)
        {
            cout << "\nTrain number not found!\n";
        }
    }
};

int main()
{
    RailwaySystem railway;

    int choice;
    int number;

    do
    {
        cout << "\n====================================";
        cout << "\n Railway Reservation System";
        cout << "\n====================================";
        cout << "\n1. Add New Train Record";
        cout << "\n2. Display All Train Records";
        cout << "\n3. Search Train by Number";
        cout << "\n4. Exit";
        

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            railway.addTrain();
            break;

        case 2:
            railway.displayAllTrains();
            break;

        case 3:
            cout << "\nEnter Train Number to search: ";
            cin >> number;

            railway.searchTrainByNumber(number);
            break;

        case 4:
            cout << "\nExiting the system. Goodbye!\n";
            break;

        default:
            cout << "\nInvalid choice! Please try again.\n";
        }

    } while (choice != 4);

    return 0;
}