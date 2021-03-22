#pragma once
#include "Hand.h"

/// <summary>
///  ласс представл€ет базовый класс игрока и диллера
/// </summary>
class GenericPlayer : virtual public Hand
{
	private:
		string _name;
		uint8_t _year;
		mutable bool inGame = true;
	public:
		GenericPlayer(const string& name, uint8_t year) :_name(name), _year(year), Hand() {};
		virtual bool IsHitting() const = 0;

		/// <summary>
		/// ¬ернет »м€ игрока
		/// </summary>
		/// <returns></returns>
		string GetNamePlayer() const;

		/// <summary>
		/// ¬ернет кол-во лет игроку
		/// </summary>
		/// <returns></returns>
		uint8_t GetYear();

		/// <summary>
		/// возвращает bool значение, есть ли у игрока перебор
		/// </summary>
		/// <returns></returns>
		bool IsBusted();

		/// <summary>
		///  выводит на экран им€ игрока и объ€вл€ет, что у него перебор
		/// </summary>
		void Bust();

		/// <summary>
		/// перегрузка вывода дл€ класса
		/// </summary>
		/// <param name="os">выводной поток</param>
		/// <param name="genPlayer">ссылка на класс</param>
		/// <returns></returns>
		friend ostream& operator<<(ostream& out, const GenericPlayer& genPlayer);

		void SetGameStatus(bool status) const { inGame = status; }
		bool GetGameStatus() const { return inGame; }
};