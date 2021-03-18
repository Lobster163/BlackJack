#pragma once
#include "GenericPlayer.h"

/// <summary>
/// ����� ������������ ������ ������
/// </summary>
class Player : public GenericPlayer
{
	public:
		Player(const string& name, uint8_t year=18) : GenericPlayer(name, year) {};
		~Player() {};
		
		/// <summary>
		/// �������� ����� �� ��� �����
		/// </summary>
		/// <returns>True - �����, False - ���</returns>
		virtual bool IsHitting() const;

		/// <summary>
		/// ����� �� ����� ��� � ��������� ��� ����� �������
		/// </summary>
		void Win() const;

		/// <summary>
		/// ����� �� ����� ��� � ��������� ��� ����� ��������
		/// </summary>
		void Lose() const;

		/// <summary>
		/// ����� �� ����� ��� � ��������� ��� �� ������ ������
		/// </summary>
		void Push() const;
};