#include <windows.h>
struct stMain {
	stMain() {
		VirtualProtect(reinterpret_cast<LPVOID>(0x6AA656), 2, PAGE_READWRITE, &oldProt);
		memset(reinterpret_cast<void*>(0x6AA656), 0x90, 0x2);
		VirtualProtect(reinterpret_cast<LPVOID>(0x6AA656), 2, oldProt, &oldProt);
	};
	~stMain() {
		VirtualProtect(reinterpret_cast<LPVOID>(0x6AA656), 2, PAGE_READWRITE, &oldProt);
		memcpy(reinterpret_cast<void*>(0x6AA656), "\x75\x06", 0x2);
		VirtualProtect(reinterpret_cast<LPVOID>(0x6AA656), 2, oldProt, &oldProt);
	}; DWORD oldProt;
} plugin;
