// NegaScout.cpp: implementation of the CNegaScout class zsj.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Surakarta.h"
#include "NegaScout.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CNegaScout::CNegaScout()
{
//	top=-1;
	flag1=0;
	flag2=0;
}

CNegaScout::~CNegaScout()
{

}
CHESSMOVE CNegaScout::SearchAGoodMove(BYTE position[6][6],int m_isPlayerBlack)
{
	memcpy(CurPosition, position, 36);
	m_nMaxDepth = m_nSearchDepth;
	NegaScout_TT_HH(m_nMaxDepth,0,m_isPlayerBlack);
	MakeMove(&m_cmBestMove);
	int score=m_pEval->Eveluate(CurPosition,m_isPlayerBlack);
	memcpy(position, CurPosition, 36);
	CString temp;
	temp.Format("分数：%d",score);
	AfxMessageBox(temp);
	return m_cmBestMove;
}

int CNegaScout::NegaScout_TT_HH(int depth,int num,int m_Type)
{
	int t;
	int Count, i;
	BYTE type;
	int side;
	int score;
	int best = -99999;
	i = IsGameOver(CurPosition, depth);//判断胜负
	if (i != 0)
	{
		return i;
	}
	side = (m_nMaxDepth - depth + m_Type) % 2;//判断预测是己方该走还是敌方该走


	if (depth <= 0)	//叶子节点取估值
	{
		score = m_pEval->Eveluate(CurPosition, side);
		return score;
	}

	Count = m_pMG->CreatePossibleMove(CurPosition, depth, side);//返回下一步多少种走法

	for (i = 0; i < Count; i++)
	{

		type = MakeMove(&m_pMG->m_nMoveList[depth][i]);//走一步  

		t = -NegaScout_TT_HH(depth - 1, i, m_Type);//递归调用
		if (t > best)
		{
			best = t;
			m_cmBestMove = m_pMG->m_nMoveList[depth][i];//存储最优走法
		}
		UnMakeMove(&m_pMG->m_nMoveList[depth][i], type);//还原棋盘
	}
	

	return best;
}