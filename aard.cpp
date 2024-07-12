#include "aard.h"
#include <iostream>

void testFunc(uint64_t* idk, CScriptStackFrame* scriptStackFrame, uint32_t ret) {
	MessageBox(nullptr, L"Hello from test", L"test", MB_OK);
}

extern "C" {
	__declspec(dllexport) void plugin() {
		auto name = CNamesPool::AddEntry(L"Test");

		std::cout << name << std::endl;

		// FAILS
		auto function = new CFunction(name, testFunc);

		std::cout << "Created function" << std::endl;

		auto system = CRTTISystem::Get();

		system->RegisterGlobalFunction(function);
	}
}