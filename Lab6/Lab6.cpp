#include <iostream>
#include <vector>
#include <string>
using namespace std;
const int shelfSpace = 5;

class FullShelf {
public:
    string errorMessage;
    void setError(string message) {
        errorMessage = message;
    }
    string getError() {
        cout << errorMessage << endl;
        return errorMessage;
    }
};

class EmptyShelf {
public:
    string errorMessage;
    void setError(string message) {
        errorMessage = message;
    }
    string getError() {
        cout << errorMessage << endl;
        return errorMessage;
    }
};
class Movie {
    string title;
    string desc;
    double rating;
};
class Shelf {
public:
    string movieName;
    string shelfArray[shelfSpace];
    Shelf() {
        for (int i = 0; i < shelfSpace; i++) {
            shelfArray[i] = "";
        }
    }
    int takenSpots = 0;
    void addMovie() {
        try {
            if (takenSpots >= 5) {
                throw FullShelf();
            }
            cout << "What movie would you like to add?: ";
            cin >> movieName;
            shelfArray[takenSpots] = movieName;
            //cout << "add to Spot: " << takenSpots << endl;
            takenSpots += 1;
            cout << endl;
        }
        catch (FullShelf exception) {
            exception.setError("Too many movies.");
            exception.getError();
        }
    }
    void removeMovie() {
        try {
            if (takenSpots <= 0) {
                throw EmptyShelf();
            }
            cout << "Removing last movie on shelf.\n"
                << shelfArray[takenSpots - 1] << " has been removed.\n";
            //cout << "remove frome Spot: " << takenSpots - 1 << endl;
            takenSpots -= 1;
            cout << endl;
        }
        catch (EmptyShelf exception) {
            exception.setError("Less than 0.");
            exception.getError();
        }
    }
    int checkShelf() {
        if (takenSpots == 1) {
            cout << "There is " << takenSpots << " movie." << endl;
        }
        else {
            cout << "There are " << takenSpots << " movies." << endl;
        }
        return takenSpots;
    }
    void listShelf() {
        for (int j = 0; j < takenSpots; j++) {
            cout << shelfArray[j] << endl;
        }
    }
    int menu() {
        int choice;
        cout << "Press 1 to add a movie to the shelf.\n"
            << "Press 2 to remove a movie from the shelf.\n"
            << "Press 3 to see how many movies are currently on the shelf.\n"
            << "Press 4 to quit.\n";

        while (true) {
            cout << "Enter your choice: ";
            cin >> choice;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input. Please enter a number between 1 and 4." << endl;
            }
            else if (choice < 1 || choice > 4) {
                cout << "Invalid choice. Please enter a number between 1 and 4." << endl;
            }
            else {
                break;
            }
        }
        return choice;
    }
};



int main() {
    Shelf myShelf;
    int choices;
    choices = myShelf.menu();
    while (choices <= 4 && choices >= 1) {
        switch (choices) {
            case 1:
                cout << "You entered 1." << endl;
                myShelf.addMovie();
                choices = myShelf.menu();
                break;
            case 2:
                cout << "You entered 2." << endl;
                myShelf.removeMovie();
                choices = myShelf.menu();
                break;
            case 3:
                cout << "You entered 3." << endl;
                myShelf.checkShelf();
                choices = myShelf.menu();
                break;
            case 4:
                cout << "Goodbye." << endl;
                myShelf.listShelf();
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl << endl;
            }
    }

    

}

