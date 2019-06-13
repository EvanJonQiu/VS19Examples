// DllDemo.cpp : Defines the exported functions for the DLL.
//

#include "pch.h"
#include "framework.h"
#include "DllDemo.h"

#include <utility>
#include <limits.h>

static unsigned long long previous_;  // Previous value, if any
static unsigned long long current_;   // Current sequence value
static unsigned index_;               // Current seq. position


// This is an example of an exported variable
DLLDEMO_API int nDllDemo=0;

// This is an example of an exported function.
DLLDEMO_API int fnDllDemo(void)
{
    return 0;
}

// This is the constructor of a class that has been exported.
CDllDemo::CDllDemo()
{
    return;
}

void fibonacci_init(
	const unsigned long long a,
	const unsigned long long b)
{
	index_ = 0;
	current_ = a;
	previous_ = b; // see special case when initialized
}

bool fibonacci_next()
{
	// check to see if we'd overflow result or position
	if ((ULLONG_MAX - previous_ < current_) ||
		(UINT_MAX == index_))
	{
		return false;
	}

	// Special case when index == 0, just return b value
	if (index_ > 0)
	{
		// otherwise, calculate next sequence value
		previous_ += current_;
	}
	std::swap(current_, previous_);
	++index_;
	return true;
}

unsigned long long fibonacci_current()
{
	return current_;
}

unsigned fibonacci_index()
{
	return index_;
}
