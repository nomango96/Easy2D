#include "..\e2daction.h"

e2d::ActionFunc::ActionFunc(Function func) :
	m_Callback(func)
{
}

e2d::ActionFunc * e2d::ActionFunc::clone() const
{
	return new ActionFunc(m_Callback);
}

void e2d::ActionFunc::_init()
{
	// ִ�к�������Ķ�������Ҫ��ʼ��
}

void e2d::ActionFunc::_update()
{
	m_Callback();
	this->stop();
}