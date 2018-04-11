#include "BehaviorTime.h"
#include "EasingFunction.h"

float LinearBehavior::behaviorTime(float p)
{
	return LinearInterpolation(p);
}

float QuadraticBehavior::behaviorTime(float p)
{
	return QuadraticEaseInOut(p);
}

float CubicBehavior::behaviorTime(float p)
{
	return CubicEaseInOut(p);
}

float SineBehavior::behaviorTime(float p)
{
	return SineEaseInOut(p);
}

float CircularBehavior::behaviorTime(float p)
{
	return CircularEaseInOut(p);
}

float BehaviorTime::behaviorTime(float p)
{
	return 0.0f;
}
