#pragma once
#include "Windows.h"
#include "CFunction.h"
#include <iostream>

class CRTTISystem
{
public:
	static CRTTISystem* Get() {
		std::cout << "Get system" << std::endl;

		auto base = reinterpret_cast<uintptr_t>(GetModuleHandle(nullptr));
		auto offset = 0x285D60;

		uintptr_t address = base + offset;

		typedef CRTTISystem* (*GetPtr)();
		return reinterpret_cast<GetPtr>(address)();
	}

	void RegisterGlobalFunction(CFunction* function) {
		std::cout << "RegisterGlobalFunction" << std::endl;

		auto base = reinterpret_cast<uintptr_t>(GetModuleHandle(nullptr));
		auto offset = 0x014695F0;

		uintptr_t address = base + offset;

		typedef void (*RegisterGlobalFunctionPtr)(CFunction*);
		return reinterpret_cast<RegisterGlobalFunctionPtr>(address)(function);
	}
};

