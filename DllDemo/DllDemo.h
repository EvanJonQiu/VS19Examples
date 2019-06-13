// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the DLLDEMO_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// DLLDEMO_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef DLLDEMO_EXPORTS
#define DLLDEMO_API __declspec(dllexport)
#else
#define DLLDEMO_API __declspec(dllimport)
#endif

// This class is exported from the dll
class DLLDEMO_API CDllDemo {
public:
	CDllDemo(void);
	// TODO: add your methods here.
};

extern DLLDEMO_API int nDllDemo;

DLLDEMO_API int fnDllDemo(void);

extern "C" DLLDEMO_API void fibonacci_init(
	const unsigned long long a, const unsigned long long b);

extern "C" DLLDEMO_API bool fibonacci_next();

extern "C" DLLDEMO_API unsigned long long fibonacci_current();

extern "C" DLLDEMO_API unsigned fibonacci_index();
