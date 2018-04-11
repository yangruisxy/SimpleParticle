#pragma once
#ifndef _BEHAVIORTIME_H_
#define _BEHAVIORTIME_H_

class BehaviorTime
{
public:
	virtual float behaviorTime(float p) ;
};

class LinearBehavior : public BehaviorTime
{
public:
	float behaviorTime(float p);
};

class QuadraticBehavior : public BehaviorTime
{
public:
	float behaviorTime(float p);
};

class CubicBehavior : public BehaviorTime
{
public:
	float behaviorTime(float p);
};

class SineBehavior : public BehaviorTime
{
public:
	float behaviorTime(float p);
};

class CircularBehavior : public BehaviorTime
{
public:
	float behaviorTime(float p);
};

#endif