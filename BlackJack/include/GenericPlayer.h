#pragma once
#include "Hand.h"

/// <summary>
/// ����� ������������ ������� ����� ������ � �������
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
		bool IsBusted();

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

		void SetGameStatus(bool status) const { inGame = status; }
		bool GetGameStatus() const { return inGame; }
};