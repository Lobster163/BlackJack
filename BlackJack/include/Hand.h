#pragma once

#include "Koloda.h"

/// <summary>
/// ����� ������������ ������ ���� ������
/// </summary>
class Hand
{
	private:
		std::vector<Card*> m_Cards;
	public:
		Hand() {};
		~Hand();

		/// <summary>
		/// ��������� ����� � ����
		/// </summary>
		/// <param name="pCard"></param>
		void AddCard(Card* pCard);

		/// <summary>
		/// ������� ��� ����� �� ����
		/// </summary>
		void ClearHand();

		/// <summary>
		/// ���������� ���-�� ���� � ����
		/// </summary>
		/// <returns>���-�� ����</returns>
		int GetCountCard() const;

		/// <summary>
		/// ���������� ����� ���� ���� � ����
		/// </summary>
		/// <returns>����� ����</returns>
		int GetSumCard() const;

		/// <summary>
		/// ������������� �������� �����
		/// </summary>
		/// <param name="numberCard">����� �����</param>
		void FlipCard(int numberCard) const;

		/// <summary>
		/// ���������� ������ ����
		/// </summary>
		/// <param name="numberCard">������ �����</param>
		vector<Card*> �GetCards() const;
		vector<Card*>& GetCards();

		/// <summary>
		/// ���������� �������� �������� �����
		/// </summary>
		/// <param name="numberCard">����� �����</param>
		/// <returns>��� �����</returns>
		string GetNameCard(int numberCard) const;
};