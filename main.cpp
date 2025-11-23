
// Name: Alex Jacobs, David Nguyen, Gabriel Lira, Jessy Zuniga, Cristine Llano, and Jorge Gonzalez
// Date: 11-23-2025
// Description: Chapter 12 Assignments

#include <iostream>
#include "input.h"
#include "HashTable.h"


using namespace std;

void option1();
void option2();
//void option3();

int main()
{
    do
    {
        system("cls");

        cout << "\n\tCMPR131 Chapter 12: Searches and hashing by Alex Jacobs, David Nguyen, Gabriel Lira, Jessy Zuniga, Cristine Llano, and Jorge Gonzalez (11/23/25)";
        cout << "\n\t" << string(100, char(205));
        cout << "\n\t\t1> Searching from an unsorted dynamic array";
        cout << "\n\t\t2> Searching from a sorted dynamic array";
        cout << "\n\t\t3> Application using hashing";
        cout << "\n\t" << string(100, char(196));
        cout << "\n\t\t0. Exit";
        cout << "\n\t" << string(100, char(205));

        int option = inputInteger("\n\t\tOption: ", 0, 3);

        switch (option)
        {
        case 1:
        {
            option1();
            break;
        }

        case 2:
        {
            option2();
            break;
        }

        case 3:
        {
            //not done
            break;
        }

        case 0:
            return 0;
        }

    } while (true);

    return 0;
}


void generateRandomNumber(vector<string>& arr, int size)
{
    arr.clear();

    srand(time(0));

    for (int i = 0; i < size; i++)
    {
        int n = rand() % size + 1; //produces number 1 to size of array
        arr.push_back("str#" + to_string(n));
    }
}

void addElement(vector<string>& arr)
{
    string item = inputString("\n\t\tEnter a string element: ", false);

    arr.push_back(item);

    cout << "\n\t\tElement \"" << item << "\" has been added to the array.\n";
}

void displayArray(const vector<string>& arr)
{
    if (arr.empty())
    {
        cout << "\n\t\tThe array is empty.\n";
        return;
    }

    cout << "\n\t\t";
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";

    cout << "\n";
}

int recursiveSerialSearch(const vector<string>& arr, const string& key, int index)
{
    if (index >= arr.size())
        return -1;   //not found

    if (arr[index] == key)
        return index;  //string found

    return recursiveSerialSearch(arr, key, index + 1); //actual recursive call
}



void serialSearch(const vector<string>& arr)
{
    if (arr.empty())
    {
        cout << "\n\t\tThe array is empty.\n";
        return;
    }

    cout << "\n\t\tRecursive serial search";
    cout << "\n\t\t" << string(65, char(196));

    string key = inputString("\n\t\tEnter a string to search: ", false);

    int result = recursiveSerialSearch(arr, key, 0);

    if (result == -1)
        cout << "\n\t\t\"" << key << "\" is not found in the array.\n";
    else
        cout << "\n\t\t\"" << key << "\" is found at index " << result << " from the array.\n";
}

void clearArray(vector<string>& arr)
{
    if (arr.empty())
    {
        cout << "\n\t\tThe array is empty.\n";
        return;
    }

    arr.clear();
    cout << "\n\t\tElements from the array have been cleared/deleted.\n";
}

void option1()
{
    vector<string> arr;
    char choice;

    do
    {
        system("cls");
        cout << "\n\t1> Searching unsorted dynamic arrays";
        cout << "\n\t" << string(100, char(205));
        cout << "\n\t\tA> Read data file and store into the array";
        cout << "\n\t\tB> Add an element to the dynamic array";
        cout << "\n\t\tC> Display elements from the array";
        cout << "\n\t\tD> Search for an element from the array";
        cout << "\n\t\tE> Clear the array";
        cout << "\n\t" << string(100, char(196));
        cout << "\n\t\t0> return";
        cout << "\n\t" << string(100, char(205));

        choice = toupper(inputChar("\n\t\tOption: ", string("abcde0")));
        //
        switch (choice)
        {
        case 'A':
        {
            int size = inputInteger("\n\t\tEnter the size of the dynamic array: ", true);
            generateRandomNumber(arr, size);
            cout << "\n\t\tRandom elements have been populated into the array.";
            break;
        }
        case 'B':
        {
            addElement(arr);
            break;
        }
        case 'C':
        {
            displayArray(arr);
            break;
        }
        case 'D':
        {
            serialSearch(arr);
            break;
        }
        case 'E':
        {
            clearArray(arr);
            break;
        }

        case '0':
            return;

        default:
            cout << "\n\tInvalid choice" << "\n";
        }

        cout << "\n\n\t";
        system("pause");

    } while (true);
    return;
}

void generateSortedNumber(vector<string>& arr, int size)
{
    arr.clear();

    srand(time(0));

    for (int i = 0; i < size; i++)
    {
        int n = rand() % size + 1;
        arr.push_back("str#" + to_string(n));
    }

    sort(arr.begin(), arr.end());
}

void addSortedElement(vector<string>& arr)
{
    string item = inputString("\n\t\tEnter a string element: ", false);

    auto pos = lower_bound(arr.begin(), arr.end(), item);
    arr.insert(pos, item);

    cout << "\n\t\tElement \"" << item << "\" has been added to the array.\n";
}

void binarySearchSorted(const vector<string>& arr)
{
    cout << "\n\t\tSTL Binary Search";
    cout << "\n\t\t" << string(65, char(196));

    string key = inputString("\n\t\tEnter a string element to search: ", false);

    auto it = lower_bound(arr.begin(), arr.end(), key);

    if (it != arr.end() && *it == key)
    {
        int index = it - arr.begin();
        cout << "\n\t\t\"" << key << "\" is found at index " << index << " in the array.\n";
    }
    else
    {
        cout << "\n\t\t\"" << key << "\" is not found in the array\n";
    }
}

void searchMenu(const vector<string>& arr)
{
    if (arr.empty())
    {
        cout << "\n\t\tThe array is empty.\n";
        return;
    }

    char type = toupper(inputChar("\n\t\tChoose search type (S)Serial or (B)Binary: ", string("sb")));

    if (type == 'S')
        serialSearch(arr);
    else if (type == 'B')
        binarySearchSorted(arr);
}

void option2()
{
    vector<string> arr;
    char choice;

    do
    {
        system("cls");
        cout << "\n\t2> Searching sorted dynamic arrays";
        cout << "\n\t" << string(100, char(205));
        cout << "\n\t\tA> Read data file and store into the array";
        cout << "\n\t\tB> Add an element to the dynamic array";
        cout << "\n\t\tC> Display elements from the array";
        cout << "\n\t\tD> Search for an element from the array";
        cout << "\n\t\tE> Clear the array";
        cout << "\n\t" << string(100, char(196));
        cout << "\n\t\t0> return";
        cout << "\n\t" << string(100, char(205));

        choice = toupper(inputChar("\n\t\tOption: ", string("abcde0")));
        
        switch (choice)
        {
        case 'A':
        {
            int size = inputInteger("\n\t\tEnter the size of the dynamic array: ", true);
            generateSortedNumber(arr, size);
            cout << "\n\t\tRandom elements have been populated into the array.";
            break;
        }
        case 'B':
        {
            addSortedElement(arr);
            break;
        }
        case 'C':
        {
            displayArray(arr);
            break;
        }
        case 'D':
        {
            searchMenu(arr);
            break;
        }
        case 'E':
        {
            clearArray(arr);
            break;
        }

        case '0':
            return;

        default:
            cout << "\n\tInvalid choice" << "\n";
        }

        cout << "\n\n\t";
        system("pause");

    } while (true);
    return;
}

