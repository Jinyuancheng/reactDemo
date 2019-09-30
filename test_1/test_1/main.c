#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	int m_iId;
	int m_iLife;
	int m_iAttack;
	int m_iDefense;
	int m_iSpeed;
}RaceValue, *pRaceValue;

void A_Attack_B(pRaceValue A, pRaceValue B)
{
	if (A->m_iSpeed > B->m_iSpeed)
	{
		B->m_iLife = B->m_iLife - (A->m_iAttack - B->m_iDefense);
		if (B->m_iLife <= 0)
		{
			B->m_iLife = 0;
		}
		else
		{
			A->m_iLife -= (B->m_iAttack - A->m_iDefense);
		}
	}
	else
	{
		A->m_iLife -= (B->m_iAttack - A->m_iDefense);
		if (A->m_iLife <= 0)
		{
			A->m_iLife = 0;
		}
		else
		{
			B->m_iLife -= (A->m_iAttack - B->m_iDefense);
		}
	}
}

void Print(pRaceValue A)
{
	printf("\n");
	printf("====================================================\n");
	printf("m_iId : %d\n", A->m_iId);
	printf("m_iLife : %d\n", A->m_iLife);
	printf("m_iAttack : %d\n", A->m_iAttack);
	printf("m_iDefense : %d\n", A->m_iDefense);
	printf("m_iSpeed : %d\n", A->m_iSpeed);
}

int main1(int argc, char* argv[])
{
	pRaceValue opUser1 = (pRaceValue)malloc(sizeof(RaceValue));
	pRaceValue opUser2 = (pRaceValue)malloc(sizeof(RaceValue));
	if (opUser1 == NULL || opUser2 == NULL)
	{
		printf("opUser1 malloc error\n");
		goto err;
	}
	opUser1->m_iId = 1;
	opUser1->m_iLife = 100;
	opUser1->m_iAttack = 120;
	opUser1->m_iDefense = 50;
	opUser1->m_iSpeed = 120;

	opUser2->m_iId = 2;
	opUser2->m_iLife = 233;
	opUser2->m_iAttack = 50;
	opUser2->m_iDefense = 100;
	opUser2->m_iSpeed = 50;

	Print(opUser1);
	Print(opUser2);

	A_Attack_B(opUser1, opUser2);

	Print(opUser1);
	Print(opUser2);
	system("pause");
	return 0;
err:
	free(opUser1);
	free(opUser2);
	printf("program error\n");
	system("pause");
	return 0;
}