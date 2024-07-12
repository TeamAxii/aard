#pragma once
#include <cstdint>
#include "Windows.h"
#include "IRTTIBaseObject.h"
#include "CScriptStackFrame.h"
#include <iostream>

template<typename T>
using SFunction = void(*)(uint64_t, CScriptStackFrame*, T);

class CFunction : IRTTIBaseObject
{
public:
	template<typename T>
	CFunction(int32_t name_hash, SFunction<T> function) {
		std::cout << "CFunction" << std::endl;

		auto base = reinterpret_cast<uint64_t>(GetModuleHandle(nullptr));
		auto offset = 0x01495FA0;

		uint64_t address = base + offset;

		typedef void (*CFunctionPtr)(CFunction*, int32_t, SFunction<T>);
		reinterpret_cast<CFunctionPtr>(address)(this, name_hash, function);
	};

	static CFunction* AllocFunc(uint32_t size, uint32_t alignment) {
		std::cout << "Allocating func" << std::endl;

		auto base = reinterpret_cast<uint64_t>(GetModuleHandle(nullptr));

		uintptr_t address = base + 0x2846B0;

		typedef CFunction* (*Alloc)(uint32_t, uint32_t);
		return reinterpret_cast<Alloc>(address)(size, alignment);
	};

	int64_t may_parentClass; // 0x08
	int32_t name_hash;		 // 0x10
	int32_t unk_14;			 // 0x14
	int64_t unk_18;			 // 0x18
	int64_t unk_20;			 // 0x20
	int32_t unk_28;			 // 0x28
	int64_t unk_2C;			 // 0x2C
	int32_t unk_34;			 // 0x34
	int64_t unk_38;			 // 0x38
	int32_t unk_40;			 // 0x40
	int64_t unk_44;			 // 0x44
	int64_t unk_4C;			 // 0x4C
	int64_t unk_58;			 // 0x58
	int32_t unk_60;			 // 0x60
	int64_t unk_64;			 // 0x64
	int64_t unk_6C;			 // 0x6C
	int64_t unk_78;			 // 0x78
	int64_t unk_80;			 // 0x80
	int32_t unk_88;			 // 0x88
	int64_t unk_90;			 // 0x90
	int32_t unk_98;			 // 0x98
	int64_t unk_9C;			 // 0x9C
	int32_t unk_A4;			 // 0xA4
	int32_t unk_A8;			 // 0xA8
	int64_t unk_B8;			 // 0xB8
};

static_assert(sizeof(CFunction) == 0xC0, "");

