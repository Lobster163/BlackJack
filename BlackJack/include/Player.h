#pragma once
#include "GenericPlayer.h"

/// <summary>
/// Класс представляет обьект игрока
/// </summary>
class Player : public GenericPlayer
{
	public:
		Player(const string& name, uint8_t year=18) : GenericPlayer(name, year) {};
		~Player() {};
		
		/// <summary>
		/// Запрос у игрока нужна ли еще карта
		/// </summary>
		/// <returns>True - нужна, False - нет</returns>
		virtual bool IsHitting() const;

		/// <summary>
		/// Вывод на экран имя и сообщения что игрок выйграл
		/// </summary>
		void Win() const;

		/// <summary>
		/// Вывод на экран имя и сообщения что игрок проиграл
		/// </summary>
		void Lose() const;

		/// <summary>
		/// Вывод на экран имя и сообщения что он сыграл вничью
		/// </summary>
		void Push() const;		
};