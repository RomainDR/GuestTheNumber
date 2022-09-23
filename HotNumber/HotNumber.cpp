#include <iostream>
#include <string>

using namespace std;

int guestValue = 0;
int minNumber = 1;
int maxNumber = 50000;
int maxAttempt = 5; 
int attempt = 0;

void SetGuessNumber()
{
    int _number;
    cout << "Insert he guess number: ";
    cin >> _number;
    if (_number > maxNumber || _number < minNumber)
    {
        cout << " \nThe number must be between " << minNumber << " and " << maxNumber << ". \n";
        SetGuessNumber();
    }
    guestValue = _number;
    system("CLS");
}
void Game()
{
    int _guestValue = guestValue;
    int _guest;
    int _attemptLeft = maxAttempt - attempt;
    bool _end = false;
    cout << "Guest the number (" << _attemptLeft << " attempt left): ";
    cin >> _guest;
    if (_guest > maxNumber || _guest < minNumber) {
        cout << " \nThe number must be between " << minNumber << " and " << maxNumber << ". \n";
        Game();
    }
    attempt++;
    if ((_attemptLeft - 1) <= 0)
    {
        cout << "You loose. You don't have any attempt left. The guest number was: " << _guestValue;
        _end = true;
    }
    if (!_end) {
        if (_guest == _guestValue)
        {
            cout << "You win ! You made " << attempt << " attempt\n";
            _end = true;
        }
        else if (_guest > _guestValue)
        {
            cout << "It's more ! ";
        }
        else if (_guest < _guestValue)
        {
            cout << "It's smaller ! ";
        }
        if(!_end) Game();
    }
    if (_end)
    {
        char _next;
        attempt = 0;
        cout << "\nDo you want restart the game ? [Y/N]: ";
        cin >> _next;
        if (_next == 'Y' || _next == 'y' || _next == 'o' || _next == 'O') {
            system("CLS");
            SetGuessNumber();
            Game();
        }
    }
}
int main()
{
    SetGuessNumber();
    Game();
}