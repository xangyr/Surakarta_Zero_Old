// MoveGenerator.h: interface for the CMoveGenerator class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MOVEGENERATOR_H__70DFE443_B8BC_48BB_871B_68E756817EAE__INCLUDED_)
#define AFX_MOVEGENERATOR_H__70DFE443_B8BC_48BB_871B_68E756817EAE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Define.h"

class CMoveGenerator  
{
public:
	CMoveGenerator();
	virtual ~CMoveGenerator();
	//�����һ���߷��Ƿ�Ϸ�
	static BOOL IsValidMove(BYTE position[6][6],int nFromX,int nFromY,int nToX,int nToY);
	//�������������ϵ����кϷ����߷�
	int CreatePossibleMove(BYTE position[6][6],int nPly,int nSide);
    
	//����߷�����
	CHESSMOVE m_nMoveList[8][100];
	//����һ���߷�
	int AddMove(int nFromX,int nToX,int nFromY,int nToY,int nPly);
protected: 
	
	
	//��¼m_nMoveList���߷�������
	int m_nMoveCount;
};

#endif // !defined(AFX_MOVEGENERATOR_H__70DFE443_B8BC_48BB_871B_68E756817EAE__INCLUDED_)
