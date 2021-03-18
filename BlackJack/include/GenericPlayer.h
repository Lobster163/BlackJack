#pragma once
#include <iostream>
#include <vector>
#include <string>

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
		/// ���������� �������� �����
		/// </summary>
		/// <param name="numberCard">������ �����</param>
		vector<Card*> GetCards() const;

		/// <summary>
		/// ���������� �������� �������� �����
		/// </summary>
		/// <param name="numberCard">����� �����</param>
		/// <returns>��� �����</returns>
		string GetNameCard(int numberCard) const;
};

/// <summary>
/// ����� ������������ ������� ����� ������ � �������
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
		/// ������ ��� ������
		/// </summary>
		/// <returns></returns>
		string GetNamePlayer() const;

		/// <summary>
		/// ������ ���-�� ��� ������
		/// </summary>
		/// <returns></returns>
		uint8_t GetYear();

		/// <summary>
		/// ���������� bool ��������, ���� �� � ������ �������
		/// </summary>
		/// <returns></returns>
		bool IsBoosted();

		/// <summary>
		///  ������� �� ����� ��� ������ � ���������, ��� � ���� �������
		/// </summary>
		void Bust();

		/// <summary>
		/// ���������� ������ ��� ������
		/// </summary>
		/// <param name="os">�������� �����</param>
		/// <param name="genPlayer">������ �� �����</param>
		/// <returns></returns>
		friend ostream& operator<<(ostream& out, const GenericPlayer& genPlayer);
};