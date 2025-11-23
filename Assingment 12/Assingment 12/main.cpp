
// Name: Alex Jacobs, David Nguyen, Gabriel Lira, Jessy Zuniga, Cristine Llano, and Jorge Gonzalez
// Date: 11-23-2025
// Description: Chapter 12 Assignments

#include <fstream>
#include <iostream>
#include "input.h"
#include "HashTable.h"

using namespace std;

void option1();
void option2();
void option3();

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
            option3();
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
    string item = inputString("\n\t\tEnter a string element: ",false);

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
        cout << "\n\t\t\"" << key << "\" is not found in the unsorted array.\n";
    else
        cout << "\n\t\t\"" << key << "\" is found at index " << result << " from the unsorted array.\n";
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

void addSortedElement(vector<string>& arr)
{
    string item = inputString("\n\t\tEnter a string element: ", false);

    auto pos = lower_bound(arr.begin(), arr.end(), item);
    arr.insert(pos, item);

    cout << "\n\t\tElement \"" << item << "\" has been added to the array.\n";
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


void option3()
{
    Table<Student> table;

    do 
    {
        system("cls");
        cout << "\n\t3> Application using hashing:";
        cout << "\n\t" << string(100, char(205));
        cout << "\n\tA> Read data file, hash and insert into the dynamic array";
        cout << "\n\tB> Search an element from the dynamic array";
        cout << "\n\tC> Insert an element into the dynamic array";
        cout << "\n\tD> Remove an element from the dynamic array";
        cout << "\n\tE> Display all records from the array";
        cout << "\n\t" << string(100, char(196));
        cout << "\n\t0-> Exit to Main Menu\n";
        cout << "\n\t" << string(100, char(205));
        
        switch (toupper(inputChar("\n\tOption: ", string("ABCDE0")))) 
        {
        case 'A': {
           
            ifstream file("Students.dat");

            if (!file) {
                cout << "\n\tError opening Students.dat";
                break;
            }

            int total = inputInteger("\n\tEnter a number of read-in records: ", true);
            int count = 0;
            string line;

            while (getline(file, line)) 
            {
                if (line.empty()) continue;
                size_t pos1 = line.find(',');
                if (pos1 == string::npos) continue;

                string id_str = line.substr(0, pos1);
                int id;

                try {
                    id = stoi(id_str);
                }
                catch (...) {
                    continue;
                }
                size_t pos2 = line.find(',', pos1 + 1);
                if (pos2 == string::npos) continue;
                string name = line.substr(pos1 + 1, pos2 - pos1 - 1);
                size_t pos3 = line.find(',', pos2 + 1);
                if (pos3 == string::npos) continue;
                string major = line.substr(pos2 + 1, pos3 - pos2 - 1);
                string gpa_str = line.substr(pos3 + 1);
                double gpa;
                try {
                    gpa = stod(gpa_str);
                }
                catch (...) {
                    continue;
                }

                Student temp;
                temp.key = id;
                temp.ID = id;
                temp.name = name;
                temp.major = major;
                temp.GPA = gpa;
                table.insert(temp);

                count++;

                if (!(count < total))
                    break;
            }

            cout << "\n\n\tData loaded from Students.dat";
            break;
        }

        case 'B': {
            if (table.size() == 0)
            {
                cout << "\n\tTable is empty!";
                break;
            }

            int id = inputInteger("\n\tEnter student ID to search: ", true);
            
            int index;
            if (table.find_index(id, index)) {
                table.display(index);
            }
            else {
                cout << "\n\tStudent not found.";
            }

            break;
        }

        case 'C': 
        {
            int id = inputInteger("\n\tEnter a new student ID: ", true);

            int index;
            if (table.find_index(id, index) == true)
            {
                cout << "\n\tERROR: ID has already inserted. Please use another one!";
                break;
            }

            string name = inputString("\n\tEnter the student's name: ", true);
            string major = inputString("\n\tEnter the student's major: ", true);
            double gpa = inputDouble("\n\tEnter a student's GPA (1.0..4.0): ", 1.0, 4.0);

            Student temp;
            temp.key = id;
            temp.ID = id;
            temp.name = name;
            temp.major = major;
            temp.GPA = gpa;
            if (table.insert(temp)) {
                table.find_index(id, index);

                cout << "\n\tStudent record index #6 with ID: " + to_string(id) + " has been removed.\n";
            }
            else {
                cout << "\n\tInsertion failed.\n";
            }
            break;
        }

        case 'D': {

            if (table.size() == 0)
            {
                cout << "\n\tTable is empty!";
                break;
            }

            int id = inputInteger("\n\tEnter student ID to remove: ", true);
           
            if (table.remove(id)) {
                cout << "\n\tStudent removed.\n";
            }
            else {
                cout << "\n\tStudent not found.\n";
            }
            break;
        }

        case 'E': {

            if (table.size() == 0)
            {
                cout << "\n\tTable is empty!";
                break;
            }

            table.displayTable(table);
            break;
        }

        case '0':
        {
            cout << "\n\tReturning to main menu!\n\n";
            return;
            break;
        }

        default:
            cout << "\n\tInvalid choice.\n";
        }

        cout << "\n\n\t";
        system("pause");

    } while (true);

    return ;
}