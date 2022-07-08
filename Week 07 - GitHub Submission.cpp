#include <iostream>
#include <fstream>
#include <iomanip>


using namespace std;



//struct
struct Bowlers {
    string namebowler = " ";
    int bscores[5];
    int average = 0;
};


//all variable
const int column = 5,
rows = 10;
const string FileName = "BowlingScores.txt";


//function
void getBowlingData(Bowlers bowlers[]) {
    //txt file
    ifstream fs;
    fs.open(FileName);
    if (!fs) {
        cout << "No file found" << endl;
    }
    else
    {
        int i = 0;
        //while
        while (i < rows)
        {
            fs >> bowlers[i].namebowler;
            for (int n = 0; n < column; n++) {
                fs >> bowlers[i].bscores[n];
            }
            i++;
        }
    }
}
//function
bool GetAverageScore(Bowlers bowlers[]) {
    // score average
    int i = 0;
    while (i < rows) {
        double sum = 0;
        for (int n = 0; n < column; n++) {
            sum += bowlers[i].bscores[n];
        }
        bowlers[i].average = sum / column;
        i++;
    }
    return true;
}

//function
void PrettyPrintResults(Bowlers bowlers[]) {

    int i = 0;
    while (i < rows)
    {
        cout << bowlers[i].namebowler << setw(5) << "\t";
        for (int n = 0; n < column; n++) {
            cout << bowlers[i].bscores[n] << "\t";
        }
        cout << bowlers[i].average << endl;
        i++;
    }
}
//function
void welcome() {
    //title
    cout << "*********************************************************" << endl;
    cout << "***Welcome to bowling league's average bowling scores****" << endl;
    cout << "*********************************************************" << endl;
}
//main
int main() {
    // function out

    Bowlers bowlers[10];
    welcome();
    getBowlingData(bowlers);
    GetAverageScore(bowlers);
    PrettyPrintResults(bowlers);
    system("pause");
    return 0;

}

