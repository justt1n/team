#include <stdio.h>
#define nullNumber -1000000
int HP = 0;
int maxHP = 0;
int TSLG = 0;
int E[1001];
int currentEvent = 1;
int meetMuggle = 0;
int turnAround = 0;
int cloak = 0;
int Fibo[15] = {1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987};
int elderWand = 0;

void makeNullEvent(int *E[1001])
{
    for (int i = 1; i <= 1001; i++)
        *E[i] = nullNumber;
}

int isPrime2(int a, int b)
{
    for (int i = 2; i <= a; i++)
        if (a % i == 0 && b % i == 0)
            return 0;
    return 1;
}

int endEvent()
{
    int count = 0;
    for (int i = 1; i <= 1001; i++)
        if (E[i] != nullNumber)
            count++;
    return count;
}

//a
int foundTSLG()
{
    TSLG++;
}

//c
int isPrime(int a)
{
    if (a == 0 || a == 1)
        return 0;
    for (int i = 2; i < a; i++)
        if (a % i == 0)
            return 0;
    return 1;
}

int canFight(int R, int HP, int M)
{
    int h1 = currentEvent % (100 + R);
    int h2 = E[currentEvent] % (100 + R);
    if (isPrime(h2) != 0 && h2 <= M)
        return 1;
    int result = h1 - h2;
    if (result >= 0)
        return 1;
    else
        return 0;
}

//b
int fight(int R, int *HP, int *M)
{
    if (cloak == 1)
    {
        if (canFight(R, *HP, *M) == 0)
        {
            currentEvent++;
            return -1;
        }
    }

    int h1 = currentEvent % (100 + R);
    int h2 = E[currentEvent] % (100 + R);
    if (isPrime(h2) != 0 && h2 <= *M)
    {
        *M += E[currentEvent];
        if (*M > 999)
            *M = 999;
        return 1;
    }

    int result = h1 - h2;
    if (result >= 0)
    {
        *M += E[currentEvent];
        if (*M > 999)
            *M = 999;
        return 1;
    }
    else
    {
        *HP -= E[currentEvent];
        return 0;
    }
}

//d
void takeABreak(int *M, int *HP)
{
    int denta = maxHP - *HP;
    if (*M >= denta)
    {
        *HP += denta;
        *M -= denta;
    }
    else
    {
        *HP += *M;
        *M = 0;
    }
}

//e
void theHaughtyRon(int R, int *M, int *HP)
{
    int P;
    for (int i = 2; i < R; i++)
        if (isPrime(i))
            P = i;
    int denta = maxHP - *HP;
    int rMP = P * denta;
    if (*M >= rMP)
    {
        *HP += denta;
        *M -= P * denta;
    }
    else
    {
        while (*M < P)
        {
            *HP += P;
            *M -= P;
        }
    }
}

//f g

void foundMuggle(int *M)
{
    if (cloak == 1)
    {
        currentEvent++;
        return;
    }
    if (meetMuggle == 1)
    {
        meetMuggle--;
        return;
    }
    int XX = E[currentEvent] - 200;
    int dentaM = *M - XX;
    if (dentaM <= 4 && turnAround != 1)
    {
        if (currentEvent < 3)
            return;
        currentEvent -= 2;
        meetMuggle = 1;
        turnAround = 1;
        return;
    }
    int rM = 1;
    while (rM < *M)
    {
        rM *= rM;
    }
    *M = rM;
    meetMuggle = 1;
}

//h
void foundSphinx(int R, int *HP, int *M)
{
    if (cloak == 1)
        return;
    int result = fight(R, HP, M);
    if (result == 0)
        TSLG = 0;
    else if (result == 1)
        cloak = 1;
}

//i
void foundGiant(int R, int *HP, int *M, int ID)
{
    int XX = E[currentEvent] - 500;
    if (ID == 2 || ID == 4)
    {
        if (isPrime2(XX, *HP))
            return;
    }
    int result = fight(R, HP, M);
    if (result == 1)
        return;
    else
    {
        int Q = 1;
        for (int i = 2; i < XX; i++)
            if (isPrime(i) == 1 && XX % i == 0)
                Q = i;
        if (Q > *M)
            *M = 0;
        else
            *M -= Q;
    }
}

//j
void foundBellatrix(int R, int *HP, int *M)
{
    if (cloak == 1)
        return;
    int E_tmp[1000];
    for (int i = 0; i < 1000; i++)
        E_tmp[i] = E[i + 1];
    for (int i = 0; i < 1000; i++)
        for (int j = i; j < 1000; j++)
            if (E_tmp[i] > E_tmp[j])
            {
                int tmp = E_tmp[i];
                E_tmp[i] = E_tmp[j];
                E_tmp[j] = tmp;
            }
    int result = fight(R, HP, M);
    if (result == 0)
    {
        int lienTiep = 0;
        int maxLienTiep = 0;
        for (int i = 0; i < 1000; i++)
        {
            if (E_tmp[i] + 1 == E_tmp[i + 1])
                lienTiep++;
            else
                lienTiep = 0;
            if (lienTiep > maxLienTiep)
                maxLienTiep = lienTiep;
        }
        if (TSLG < maxLienTiep)
            TSLG = 0;
        else
            TSLG -= maxLienTiep;
    }
    else
        TSLG--;
}

void foundSnape(int R, int *HP, int *M, int ID)
{
    if (cloak == 1)
        return;
    if (ID == 4)
        *HP = -1;
    else if (ID == 1)
    {
        *HP = 999;
        *M = 999;
        elderWand = 1;
    }
    else
    {
        int i = 0;
        while (Fibo[i] < *HP)
            i++;
        *HP = Fibo[i];
    }
}

void foundBoss(int R, int *HP, int *M, int ID)
{
    int checkFibo = 0;
    for (int i = 0; i < 15; i++)
        if (currentEvent == Fibo[i])
        {
            checkFibo = 1;
            break;
        }
    if (ID == 1 && elderWand == 1)
    {
        *HP = maxHP;
        *M = 999;
    }
    else if (checkFibo == 1)
    {
        int result = fight(R, HP, M);

        if (result == 0)
            *HP = -1;
        else
        {
            *HP = maxHP;
            *M = 999;
        }
    }
    else
        *HP = -1;
}

int main()
{
    makeNullEvent;
    int R, N, ID, M;
    scanf("%d %d %d %d", &R, &N, &ID, &M);
    switch (ID)
    {
    case 1:
        HP = 999;
        maxHP = 999;
        break;
    case 2:
        HP = 900;
        maxHP = 900;
        break;
    case 3:
        HP = 888;
        maxHP = 888;
        break;
    case 4:
        HP = 777;
        maxHP = 777;
        break;
    default:
        break;
    }
    char tmp = 0;
    int i = 1;
    while (tmp != '\n')
    {
        scanf("%d", &E[i]);
        i++;
        tmp = getchar();
    }
    while (currentEvent <= endEvent() && TSLG < N && HP > 0)
    {
        if (E[currentEvent] == 0)
        {
            foundTSLG();
        }
        else if (E[currentEvent] == 1)
        {
            if (ID == 3)
                theHaughtyRon(R, &M, &HP);
            else
                takeABreak(&M, &HP);
        }
        else if (E[currentEvent] < 200 && E[currentEvent] > 100)
        {
            fight(R, &HP, &M);
        }
        else if (E[currentEvent] > 200 && E[currentEvent] < 300)
            foundMuggle(&M);
        else if (E[currentEvent] > 300 && E[currentEvent] < 400)
            foundSphinx(R, &HP, &M);
        else if (E[currentEvent] > 500 && E[currentEvent] < 600)
            foundGiant(R, &HP, &M, ID);
        else if (E[currentEvent] == 666)
            foundBellatrix(R, &HP, &M);
        else if (E[currentEvent] == 777)
            foundSnape(R, &HP, &M, ID);
        else if (E[currentEvent] == 999)
            foundBoss(R, &HP, &M, ID);
        currentEvent++;
    }
	if(TSLG == N)
		printf("%d", HP + M);
	else if(TSLG < N)
	{
		if(HP == -1)
			printf("-1");
		else
			printf("0");
	}
    return 0;
}
