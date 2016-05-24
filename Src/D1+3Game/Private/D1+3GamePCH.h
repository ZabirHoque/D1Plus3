#pragma once

#include "STLPCHIncludes.h"

#define NOMINMAX
#define WIN32_LEAN_AND_MEAN
#pragma warning(push)
#pragma warning(disable: 4668) // 'symbol' is not defined as a preprocessor macro, replacing with '0' for 'directives'
#pragma warning(disable: 4820) // 'bytes' bytes padding added after construct 'member_name'
#include <Windows.h>
#pragma warning(pop)
