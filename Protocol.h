#pragma once
#include <Windows.h>


enum PacketList
{
	P_CONNECTIONSUCCESS_ACK = 100,


	P_LOGINPACKET_REQ,					P_LOGINPACKET_ACK,
	P_LOBBYOPTION_REQ,					P_LOBBYOPTION_ACK,
	P_ENTERROOM_REQ,				    P_ENTERROOM_ACK,
	P_BROADCAST_ENTER_ROOM_REQ,			P_BROADCAST_ENTER_ROOM_ACK,
	P_READY_REQ,						P_READY_ACK,
	P_READYRESULT_REQ,					P_READYRESULT_ACK,
	P_GAMESTARTREADY_REQ,				P_GAMESTARTREADY_ACK,
	P_GAMESTART_REQ,					P_GAMESTART_ACK,
	P_GAMEINPUT_REQ,					P_GAMEINPUT_ACK,
	P_ENEMYPOS_REQ,						P_ENEMYPOS_ACK
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
	GameStart,



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

typedef struct CPosition
{
	int x;
	int y;

	CPosition operator=(const CPosition& pos)
	{
		x = pos.x;
		y = pos.y;

		return *this;
	}
}pos;