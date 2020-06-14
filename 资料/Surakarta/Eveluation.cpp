// Eveluation.cpp: implementation of the CEveluation class zsj.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Surakarta.h"
#include "Eveluation.h"
#include<cstdlib>
#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CEveluation::CEveluation()
{

}

CEveluation::~CEveluation()
{

}
int CEveluation::Eveluate(BYTE position[6][6], BOOL IsBlackturn)
{

	//����Ҫ�������������������¹��ܵĴ��룺
	//1.����֪�������ϵз����ҷ����ӵ�����
	//2.���Եõ�˫����ռλ�õķ�ֵ��ÿ��λ�ö�Ӧ�ķ�ֵ�ɲο��������
	//3.���Եõ��ҷ����ӿ��ƶ���ֵ
	//4.������һЩ������ֵ����


	 BlackValue=0,RedValue=0;//��ڷ��ܵ�����ֵ
	 BProtectValue=0,RProtectValue=0;
	 BAttactValue=0,RAttactValue=0;
	 RMoveValue=0,BMoveValue=0;//������ʾ���ƶ���ֵ
	 BPosValue=0,RPosValue=0;
	 BNum=0,RNum=0;//�췽���ڷ���������
	int i,j;

	GetAttackInfo(position);
	
	if (IsBlackturn) //��ù���������ֵ����������������������������������������������������������������
    {
		for (i=0;i<6;i++)
		{
			for(j=0;j<6;j++)
			{
				if(position[i][j]==2)                           
				{
					if (m_AttackPos[i][j]-m_ProtectPos[i][j]>0) 
						BAttactValue=BAttactValue+1;          			
				}
				if(position[i][j]==1)                         
				{
					if(m_ProtectPos[i][j]-m_AttackPos[i][j]<0)   
						RAttactValue=RAttactValue+1;             
				}
				if(RAttactValue==BAttactValue && RAttactValue) //��Ϊ���ںڷ��غϣ������ڷ���������������ͬ����ڷ�������  
					RAttactValue=RAttactValue-1;            
			}   
	
		}
	}

	else //����
  {
		for (i=0;i<6;i++)
		{
			for (j=0;j<6;j++)
			{
				if (position[i][j]==1)
				{
					if (m_AttackPos[i][j]-m_ProtectPos[i][j]>0) 
						RAttactValue=RAttactValue+1;  
				}
				if (position[i][j]==2)
				{
					if(m_ProtectPos[i][j]-m_AttackPos[i][j]<0)
						BAttactValue=BAttactValue+1; 
				}
				
				if(RAttactValue==BAttactValue && RAttactValue)
					BAttactValue=BAttactValue-1;
			}
		}
	}
//��������������������������������������������������������������������������������������������������������������������������������	


	BlackValue=BlackValue+BPosValue*1+BNum*1+BAttactValue*1+BMoveValue*1;//abcd�ֱ��ʾ�����������ص�Ȩֵ
	RedValue=RedValue+RPosValue*1+RNum*1+RAttactValue*1+RMoveValue*1;



	if (IsBlackturn)//�˽⼫��С����ԭ�����IsBlackturn ��������Ǹ�ʲô�õĺ�����ֵ�����壬Ȼ��ȷ��return�����ĸ�����
		return rand()%1000;//���ص���һ���������ֻ��Ϊ���ó���������
	else
		return rand()%1000;
}




void CEveluation::GetAttackInfo(BYTE position[6][6])
{
	BYTE CurPosition[6][6];
	memset(m_AttackPos,0,36);
	memset(m_ProtectPos,0,36);
	memset(m_MovePos,0,36);
    memcpy(CurPosition,position,36);
	int flag=1,i,j,m,n;
	for (i=0;i<6;i++)
	{
		for (j=0;j<6;j++)
		{
			if(CurPosition[i][j])
			{
				for (m=0;m<6;m++)
				{
					for(n=0;n<6;n++)
					{
						if(i==m && j==n)
						{
							continue;
						}
						if(CurPosition[m][n]!=CurPosition[i][j])
						{
							if(  CurPosition[m][n] && m_pMg->IsValidMove(CurPosition,m,n,i,j)) 
							{
								m_AttackPos[i][j]++;
							}

						}
						else
						{

							if(CurPosition[m][n])
							{
								CurPosition[m][n]=3-CurPosition[i][j];
								if(m_pMg->IsValidMove(CurPosition,m,n,i,j))  
								{

									m_ProtectPos[i][j]++;           

								}
								CurPosition[m][n]=CurPosition[i][j];
							}

						}
						
					}
				}
			}
		}
	}
	memcpy(position,CurPosition,36);
}







