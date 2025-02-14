#include <e2daction.h>
#include <e2dnode.h>


easy2d::RotateBy::RotateBy(float duration, float rotation)
	: FiniteTimeAction(duration)
{
	_deltaVal = rotation;
}

void easy2d::RotateBy::_init()
{
	FiniteTimeAction::_init();

	if (_target)
	{
		_startVal = _target->getRotation();
	}
}

void easy2d::RotateBy::_update()
{
	FiniteTimeAction::_update();

	if (_target)
	{
		_target->setRotation(_startVal + _deltaVal * _delta);
	}
}

easy2d::RotateBy * easy2d::RotateBy::clone() const
{
	return gcnew RotateBy(_duration, _deltaVal);
}

easy2d::RotateBy * easy2d::RotateBy::reverse() const
{
	return gcnew RotateBy(_duration, -_deltaVal);
}