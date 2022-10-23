#pragma once

#ifdef LGE_PALTFORM_WINDOWS
	#ifdef LGE_BUILD_DLL
		#define LGE_API __declspec(dllexport)
	#else
		#define LGE_API __declspec(dllimport)
	#endif
#else
	#error LGE only support Windows
#endif

#define BIT(x)(1 << x)

