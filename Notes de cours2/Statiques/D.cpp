#include "D.h"

int D::m_entierStatic = 0;


D::D()
{
	D::m_entierStatic++;
}


D::~D()
{
	D::m_entierStatic--;
}
