#pragma once

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
		/// Возвращает вектор карт
		/// </summary>
		/// <param name="numberCard">Обьект Карты</param>
		vector<Card*> сGetCards() const;
		vector<Card*>& GetCards();

		/// <summary>
		/// Возвращает название заданной карты
		/// </summary>
		/// <param name="numberCard">номер карты</param>
		/// <returns>имя карты</returns>
		string GetNameCard(int numberCard) const;

		/// <summary>
		/// Возврат текущего состоянии карты
		/// </summary>
		/// <param name="numberCard">номер карты в руке</param>
		/// <returns></returns>
		bool GetStatusFlipCard(int numberCard) const;		
};