#include "include/Player.h"

bool Player::IsHitting() const
{
    cout << GetNamePlayer() << ", do you want a hit? (y / n): ";
    char result;
    cin >> result;
    bool choose = (result == 'y' || result == 'Y');
    SetGameStatus(choose);
    return choose;
}

void Player::Win() const
{
    cout << GetNamePlayer() << "win" << endl;
}

void Player::Lose() const
{
    cout << GetNamePlayer() << "loses" << endl;
}

void Player::Push() const
{
    cout << GetNamePlayer() << "pushes" << endl;
}