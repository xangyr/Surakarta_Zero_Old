// Eveluation.h: interface for the CEveluation class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_EVELUATION_H__D5138E45_7853_40AB_80A8_5D7BB3E091F8__INCLUDED_)
#define AFX_EVELUATION_H__D5138E45_7853_40AB_80A8_5D7BB3E091F8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "MoveGenerator.h"
class CEveluation  
{
public:
	CEveluation();
	virtual ~CEveluation();
	virtual int Eveluate(BYTE position[6][6],BOOL bIsBlackTurn);//��ֵ�������Դ�������̴�֣�bIsBlackTurn�����ֵ�˭����
	void GetAttackInfo(BYTE position[6][6]);
	BYTE m_AttackPos[6][6];
	BYTE m_ProtectPos[6][6];
	BYTE m_MovePos[6][6];
	CMoveGenerator *m_pMg;
private:
	int BlackValue,RedValue;
	int BNum,RNum;
	int BPosValue, RPosValue;
	int BProtectValue,BAttactValue;
	int RProtectValue,RAttactValue;
	int RMoveValue,BMoveValue;
};

#endif // !defined(AFX_EVELUATION_H__D5138E45_7853_40AB_80A8_5D7BB3E091F8__INCLUDED_)
