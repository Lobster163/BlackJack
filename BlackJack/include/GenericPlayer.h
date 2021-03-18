#pragma once
#include <iostream>
#include <vector>
#include <string>

#include "Koloda.h"

/// <summary>
/// Класс представляет обьект рука игрока
/// </summary>
class Hand
{
	private:
		std::vector<Card*> m_Cards;
	public:
		Hand() {};
		~Hand();

		/// <summary>
		/// Добавляет карту в руку
		/// </summary>
		/// <param name="pCard"></param>
		void AddCard(Card* pCard);

		/// <summary>
		/// Удаляет все карты из руки
		/// </summary>
		void ClearHand();

		/// <summary>
		/// Возвращает кол-во карт в руке
		/// </summary>
		/// <returns>кол-во карт</returns>
		int GetCountCard() const;

		/// <summary>
		/// Возвращает сумму всех карт в руке
		/// </summary>
		/// <returns>сумма карт</returns>
		int GetSumCard() const;

		/// <summary>
		/// Переворачиает заданную карту
		/// </summary>
		/// <param name="numberCard">номер карты</param>
		void FlipCard(int numberCard) const;

		/// <summary>
		/// Возвращает заданную карту
		/// </summary>
		/// <param name="numberCard">Обьект Карты</param>
		vector<Card*> GetCards() const;

		/// <summary>
		/// Возвращает название заданной карты
		/// </summary>
		/// <param name="numberCard">номер карты</param>
		/// <returns>имя карты</returns>
		string GetNameCard(int numberCard) const;
};

/// <summary>
/// Класс представляет базовый класс игрока и диллера
/// </summary>
class GenericPlayer : virtual public Hand
{
	private:
		string _name;
		uint8_t _year;
	public:
		GenericPlayer(const string& name, uint8_t year) :_name(name), _year(year), Hand() {};
		virtual bool IsHitting() const = 0;

		/// <summary>
		/// Вернет Имя игрока
		/// </summary>
		/// <returns></returns>
		string GetNamePlayer() const;

		/// <summary>
		/// Вернет кол-во лет игроку
		/// </summary>
		/// <returns></returns>
		uint8_t GetYear();

		/// <summary>
		/// возвращает bool значение, есть ли у игрока перебор
		/// </summary>
		/// <returns></returns>
		bool IsBoosted();

		/// <summary>
		///  выводит на экран имя игрока и объявляет, что у него перебор
		/// </summary>
		void Bust();

		/// <summary>
		/// перегрузка вывода для класса
		/// </summary>
		/// <param name="os">выводной поток</param>
		/// <param name="genPlayer">ссылка на класс</param>
		/// <returns></returns>
		friend ostream& operator<<(ostream& out, const GenericPlayer& genPlayer);
};