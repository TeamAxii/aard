#pragma once
#include <cstdint>
#include "Windows.h"
#include <iostream>

class CNamesPool
{
public:
	static uint32_t AddEntry(const wchar_t *name) {
		auto base = reinterpret_cast<uint64_t>(GetModuleHandle(nullptr)); // Base exe address
		auto offset = 0x014593A0; // Original AddEntry offset

		uint64_t address = base + offset;

		typedef uint32_t (*AddEntryPtr)(LPCRITICAL_SECTION, const wchar_t *);
		return reinterpret_cast<AddEntryPtr>(address)(CNamesPool::Get(), name);
	};

	static LPCRITICAL_SECTION Get() {
		auto base = reinterpret_cast<uint64_t>(GetModuleHandle(nullptr));
		auto offset = 0x2843A0;

		uint64_t address = base + offset;

		typedef LPCRITICAL_SECTION (*GetPtr)();
		return reinterpret_cast<GetPtr>(address)();
	}
};

