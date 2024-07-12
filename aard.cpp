#include "aard.h"
#include <iostream>

void testFunc(uint64_t idk, CScriptStackFrame* idk2, uint64_t ret) {
	MessageBox(nullptr, L"Hello from test", L"test", MB_OK);
}

extern "C" {
	__declspec(dllexport) void plugin() {
		auto memory = CFunction::AllocFunc(0xC0, 0x1);
		CFunction* function = nullptr;

		if (memory) {
			memset(memory, 0, 0xC0);
			auto name = CNamesPool::AddEntry(L"Test");
			function = new (memory) CFunction(name, testFunc);
		}

		CRTTISystem::Get()->RegisterGlobalFunction(function);
	}
}