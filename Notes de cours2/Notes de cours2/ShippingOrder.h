#pragma once
#include "Box.h"
class ShippingOrder
{
public:
	ShippingOrder(Box a_Box, float a_ShippingOrder);
	~ShippingOrder();

private:
	Box m_Box;
	float m_ShippingPrice;
};

