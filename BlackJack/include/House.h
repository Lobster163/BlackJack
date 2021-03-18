#pragma once
#include "GenericPlayer.h"

/// <summary>
/// Класс представляет игрока ввиде диллера
/// </summary>
class House : public GenericPlayer
{
	public:
		House() : GenericPlayer("Diller", 18) {};
		~House() {};
		
		/// <summary>
		/// Проверка нужна ли еще карта
		/// </summary>
		/// <returns>True - нужна, False - нет</returns>
		virtual bool IsHitting() const;

		/// <summary>
		/// Переворачивает первую карту
		/// </summary>
		void FlipFirstCard();
};