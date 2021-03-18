#include "include/Player.h"

bool Player::IsHitting() const
{
    cout << GetNamePlayer() << ", do you want a hit? (y / n): ";
    char result;
    cin >> result;
    return (result == 'y' || result == 'Y');
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