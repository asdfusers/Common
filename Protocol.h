#pragma once
#include <Windows.h>


enum PacketList
{
	P_CONNECTIONSUCCESS_ACK = 100,


	P_LOGINPACKET_REQ, P_LOGINPACKET_ACK,
	P_LOBBYOPTION_REQ, P_LOBBYOPTION_ACK,
	P_ENTERROOM_REQ, P_ENTERROOM_ACK
};

struct Login
{
	char ID[10];
	char password[15];
};

enum Status
{
	Connect,
	Lobby =1,
	InRoom,
	Ready,
	



	Game
};

static void XTrace0(LPCTSTR lpszText)
{
	::OutputDebugString(lpszText);
}

static void XTrace(LPCTSTR lpszFormat, ...)
{
	va_list args;
	va_start(args, lpszFormat);
	int nBuf;
	TCHAR szBuffer[512]; // get rid of this hard-coded buffer
	nBuf = _vsnwprintf_s(szBuffer, 511, lpszFormat, args);
	::OutputDebugString(szBuffer);
	va_end(args);
}

