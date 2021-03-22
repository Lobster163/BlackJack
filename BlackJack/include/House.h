#pragma once
#include "GenericPlayer.h"

/// <summary>
/// ����� ������������ ������ ����� �������
/// </summary>
class House : public GenericPlayer
{
	public:
		House() : GenericPlayer("Deal", 18) {};
		~House() {};
		
		/// <summary>
		/// �������� ����� �� ��� �����
		/// </summary>
		/// <returns>True - �����, False - ���</returns>
		virtual bool IsHitting() const;

		/// <summary>
		/// �������������� ������ �����
		/// </summary>
		void FlipFirstCard();
};