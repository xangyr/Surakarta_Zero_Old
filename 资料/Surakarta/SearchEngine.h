// SearchEngine.h: interface for the CSearchEngine class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SEARCHENGINE_H__43AA9763_1A7D_4ED0_B4E8_7B9196170C54__INCLUDED_)
#define AFX_SEARCHENGINE_H__43AA9763_1A7D_4ED0_B4E8_7B9196170C54__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Define.h"
#include "Eveluation.h"
#include "MoveGenerator.h"
class CSearchEngine  
{
public:
	CSearchEngine();
	virtual ~CSearchEngine();
	//Ϊ��ǰ�����߳���һ�����ӿ�
	virtual CHESSMOVE SearchAGoodMove(BYTE position[6][6],int m_isPlayerBlack)=0;
	
	void SetSearchDepth(int nDepth) {m_nSearchDepth=nDepth;};//�趨����������
	void SetEveluator(CEveluation *pEval) {m_pEval=pEval;};//�趨��ֵ����
	void SetMoveGenerator(CMoveGenerator *pMG) {m_pMG=pMG;};//�趨�߷�������
protected:
	BYTE MakeMove(CHESSMOVE *move);//��ĳһ�߷���������֮�������
	void UnMakeMove(CHESSMOVE *move ,BYTE nChessID);//�ָ�һ��
	int IsGameOver(BYTE position[6][6],int nDepth);//�ж��Ƿ���ʤ��
	BYTE CurPosition[6][6];//��ǰ�ڵ����̵�״̬
	CHESSMOVE m_cmBestMove;//��¼��ѵ��߷�
	CMoveGenerator *m_pMG;//�߷�������ָ��
	CEveluation *m_pEval;//��ֵ����ָ��
	int m_nSearchDepth;//����������
	int m_nMaxDepth;//��ǰ������������

};

#endif // !defined(AFX_SEARCHENGINE_H__43AA9763_1A7D_4ED0_B4E8_7B9196170C54__INCLUDED_)
