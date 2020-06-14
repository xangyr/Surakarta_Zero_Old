// SearchEngine.cpp: implementation of the CSearchEngine class zsj.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Surakarta.h"
#include "SearchEngine.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CSearchEngine::CSearchEngine()
{

}

CSearchEngine::~CSearchEngine()
{
	delete m_pMG;
	delete m_pEval;
}
BYTE CSearchEngine::MakeMove(CHESSMOVE *move)//�ɴ�����߷��ı�����
{
	BYTE Side;
	Side=CurPosition[move->To.x][move->To.y];
	CurPosition[move->To.x][move->To.y]=CurPosition[move->From.x][move->From.y];
	CurPosition[move->From.x][move->From.y]=NOCHESS;
return Side;

}


void CSearchEngine::UnMakeMove(CHESSMOVE *move ,BYTE nChessID)//�ָ�����
{
	CurPosition[move->From.x][move->From.y]=CurPosition[move->To.x][move->To.y];
CurPosition[move->To.x][move->To.y]=nChessID;

}

int CSearchEngine::IsGameOver(BYTE position[6][6],int nDepth)//δ��������0���������ؼ���/��Сֵ
{
int i,j;
BOOL RedWin=TRUE,BlackWin=TRUE;
for (i=0;i<6;i++)
{
	for (j=0;j<6;j++)
	{
		if(position[i][j]==1)
			RedWin=FALSE;
		if(position[i][j]==2)
			BlackWin=FALSE;
	}
}
i=(m_nMaxDepth-nDepth+1)%2;
if (RedWin)
{
	if(i)
		return 19990+nDepth;
	else
		return -19990-nDepth;
}
if (BlackWin)
{
	if(i)
		return -19990-nDepth;
	else
		return 19990+nDepth;
}
return 0;
}
