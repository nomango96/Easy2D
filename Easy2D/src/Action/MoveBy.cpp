#include <e2daction.h>
#include <e2dnode.h>


easy2d::MoveBy::MoveBy(float duration, Vector2 vector)
	: FiniteTimeAction(duration)
{
	_deltaPos = vector;
}

void easy2d::MoveBy::_init()
{
	FiniteTimeAction::_init();

	if (_target)
	{
		_prevPos = _startPos = _target->getPos();
	}
}

void easy2d::MoveBy::_update()
{
	FiniteTimeAction::_update();

	if (_target)
	{
		Point currentPos = _target->getPos();
		Vector2 diff = currentPos - _prevPos;
		_startPos = _startPos + diff;

		Point newPos = _startPos + (_deltaPos * _delta);
		_target->setPos(newPos);

		_prevPos = newPos;
	}
}

easy2d::MoveBy * easy2d::MoveBy::clone() const
{
	return gcnew MoveBy(_duration, _deltaPos);
}

easy2d::MoveBy * easy2d::MoveBy::reverse() const
{
	return gcnew MoveBy(_duration, -_deltaPos);
}