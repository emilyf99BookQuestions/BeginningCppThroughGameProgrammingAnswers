
#include <iostream>
using namespace std;

const int SCORES_ENTERED = 3;

void getAverage(int, int, int );

int main()
{
    int scoreOne = 0;
    int scoreTwo = 0;
    int scoreThree = 0;
    cout << "Enter Three Scores, The Average will be returned" << endl;
    cout << "Score One: ";
    cin >> scoreOne;
    cout << "Score Two: ";
    cin >> scoreTwo;
    cout << "Score Three : ";
    cin >> scoreThree;

    getAverage(scoreOne, scoreTwo, scoreThree);

    return 0;
}

void getAverage(int scoreOne, int scoreTwo, int scoreThree) {
    double total = (scoreOne + scoreTwo + scoreThree) / SCORES_ENTERED;
    cout << "The Average is " << total;
}
