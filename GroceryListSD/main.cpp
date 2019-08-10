#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <Windows.h> 
#include <stdlib.h>

using namespace std;

void AddItem();
int PrintList();
void ViewList();
void DeleteItem();
void displaySectionHeader(string, bool);
int stringToInt(string);
vector <string> listItems {};

int main()  // main is program menu
{
    char selection {};

    do {
        displaySectionHeader("Build Grocery List",0);
        cout << "\n\t1. Add Item" << endl;
        cout << "\t2. Delete Item" << endl;
        cout << "\t3. Review Grocery List" << endl;
        cout << "\t4. Save & Print Grocery List" << endl;
        cout << "\tQ. Quit\n" << endl;
        cout << "\tSelect an option: ";
        cin >> selection;

    if(selection == '1'){ AddItem(); }

    else if (selection == '2'){ DeleteItem();}

    else if (selection == '3'){ ViewList(); }

    else if (selection == '4'){ PrintList(); }

    else if (selection == 'Q' || selection == 'q'){ cout << "\tGoodbye..." << endl; }

    else
        cout << "\tUnknown Option -- Try Again!" << endl;
        // pause system to notify user of wrong input
       
       Sleep(2000);
        system("CLS");

    } while (selection != 'Q' && selection != 'q');

return 0;

}

void displaySectionHeader(string sectionTitle, bool clrScreen=1){
    if(clrScreen){system("CLS");}
    cout << "\n\t-- " << sectionTitle << " --" << endl;
    cout << "\t      " << listItems.size() << " Items In List      " << endl;
}

void AddItem(){

    char continueSelection {};
    do {
        string theItemToAdd {""};
        displaySectionHeader("Add Item to Grocery List",1);

        cout << "\n\tEnter Item\n\t(or \"end\" to Quit) : ";

        string ItemName {0};
        getline(std::cin >> std::ws, ItemName);

        if(ItemName != "end"){
            cout << "\n\tEnter Quantity\n\t(or \"end\" to Quit): ";

            string ItemQty {""};
            getline(std::cin >> std::ws, ItemQty);

            if(ItemQty != "end"){
                theItemToAdd = ItemQty+" "+ItemName;

                listItems.push_back(theItemToAdd);
            }
        }
        displaySectionHeader("Items in Grocery List",1);

        for(int numOfItems = 0; numOfItems <= static_cast<int>(listItems.size()-1); numOfItems++ ){

        cout << "\n\t " << listItems.at(numOfItems);
        }
        cout << "\n\n\t-- Select an option! --\n" << endl;
        cout << "\t1. Continue Adding Items" << endl;
        cout << "\t2. I Am Done Adding Items\n" << endl;
        cout << "\t";
        cin >> continueSelection;

        if(continueSelection == '1'){

            system("CLS");

        }else if(continueSelection == '2'){

            system("CLS");

        }
        else{
            cout << "\tUnknown Option -- Try Again!" << endl;
            // pause system to notify user of wrong input
           
            Sleep(2000);
            system("CLS");
        }

    } while(continueSelection != '2');

    return;

}

int PrintList(){
    // opens save file
    ofstream out_file {"groceries.txt"};
    if (!out_file) {

        cerr << "Error creating file" << endl;
        return 1;
    }

    out_file << endl; // add two empty lines to file before write loop.
    out_file << endl; // added just to move list away from top margin.

    // outputs grocery list items to file
    for(int numOfItems = 0; numOfItems <= static_cast<int>(listItems.size()-1); numOfItems++ ){
        out_file << listItems.at(numOfItems) << endl;
    }

    out_file.close();

    cout << "\n\n\tSaving grocery list & printing...." << endl;

    // pause system to notify user of action taken
   
    Sleep(2000);
    // opens notepad, prints grocery list file & closes
    system("notepad.exe /P groceries.txt");

return 0;
}

void ViewList(){

    char viewSelection {};
    do {
        displaySectionHeader("Viewing Grocery List",1);
        cout << "" << endl;

        for(int numOfItems = 0; numOfItems <= static_cast<int>(listItems.size()-1); numOfItems++ ){
            cout << "\t    " << listItems.at(numOfItems) << endl;

        }
        cout << "\n\n\t-- Enter \"Q\" to exit --\n" << endl;
        cout << "\t";
        cin >> viewSelection;

        if(viewSelection == 'Q' || viewSelection == 'q'){
            system("CLS");
        }

    } while(viewSelection != 'Q' && viewSelection != 'q');

return;
}

void DeleteItem(){
    int deleteChoice {-1};
    string deleteItem {""};

    do {
        displaySectionHeader("Delete Item(s) from List",1);
        cout << "" << endl;

        if(static_cast<int>(listItems.size()) == 0){
            cout << "\tNothing to Delete..." << endl;
            cout << "\n\n\tEnter \"0\" to exit" << endl;
            cout << "\t";

            // reads user input into the string
            getline(std::cin >> std::ws, deleteItem);

            // converts inputed string to integer, returns 0 if anything but an integer
            deleteChoice = stringToInt(deleteItem);

            if(deleteChoice == 0){
                cout << "\tReturning to Main Menu....";

                // pause system to notify user of action taken
               
                Sleep(2000);
                system("CLS");
            }
        }else{
            for(int numOfItems = 0; numOfItems <= static_cast<int>(listItems.size()-1); numOfItems++ ){
            cout << "\t Item(s) " << numOfItems+1 << ".  " << listItems.at(numOfItems) << endl;
            }

            cout << "\n\n\tEnter # of item to delete\n\t or \"0\" to exit" << endl;
            cout << "\t";
            deleteItem ="";
            getline(std::cin >> std::ws, deleteItem);
            deleteChoice = stringToInt(deleteItem);

            if(deleteChoice == 0){
                cout << "\tReturning to Main Menu....";
                // pause system to notify user of action taken
               // std::this_thread::sleep_for(std::chrono::milliseconds(1200));
               Sleep(2000);
                system("CLS");

            // check if input is within bounds of vector
            }else if(deleteChoice <= static_cast<int>(listItems.size())){

                // Offsets the item choice number to match vector index and erases item
                listItems.erase(listItems.begin()+ (deleteChoice-1));

            }else{
                cout << "\tUnknown Option -- To Try Again!" << endl;
                Sleep(2000);
                system("CLS");
            }

        }
    } while(deleteChoice != 0);

    return;
}

int stringToInt(std::string s) //The conversion function
{
    return atoi(s.c_str());
}