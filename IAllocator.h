#pragma once

class IAllocator
{
	virtual ~IAllocator() = default; // 0x00
	virtual void Unk_00() = 0;		 // 0x08
	virtual void Unk_10() = 0;		 // 0x10
	virtual void Unk_18() = 0;		 // 0x18
	virtual void Unk_20() = 0;		 // 0x20
	virtual void Unk_28() = 0;		 // 0x28
	virtual void Unk_30() = 0;		 // 0x30
	virtual void Unk_38() = 0;		 // 0x38
	virtual void Unk_40() = 0;		 // 0x40
	virtual void Unk_48() = 0;		 // 0x48
	virtual void Unk_50() = 0;		 // 0x50
	virtual void Unk_58() = 0;		 // 0x58
	virtual void Unk_60() = 0;		 // 0x60
	virtual void Unk_68() = 0;		 // 0x68
	virtual void Unk_70() = 0;		 // 0x70
};

