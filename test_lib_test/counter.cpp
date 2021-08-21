#include <stdio.h>
#include "counter.hpp"

int Counter::Incr() 
{
	counter_++;
	return counter_;
}

int Counter::value() 
{
	return counter_;
}
