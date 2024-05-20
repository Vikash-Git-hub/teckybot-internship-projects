#include <reg51.h>


sbit e_b = P1^0;

sbit s_b = P1^1;

sbit w_b = P1^2;

sbit n_b = P1^3;

sbit e_r = P2^0;
sbit e_y = P2^1;
sbit e_g = P2^2;
sbit s_r = P2^3;
sbit s_y = P2^4;
sbit s_g = P2^5;
sbit w_r = P3^0;
sbit w_y = P3^1;
sbit w_g = P3^2;
sbit n_r = P3^3;
sbit n_y = P3^4;
sbit n_g = P3^5;

void east();
void south();
void west();
void north();
void delay(int val);
void ready_east();
void ready_south();
void ready_west();
void ready_north();
void density();

void main()
{
while(1)
{
    density();
	delay(10);

	east();
	delay(10);
	density();
	delay(10);

	south();
	delay(10);
	density();
	delay(10);

	west();
	delay(10);
	density();
	delay(10);

	north();
	delay(10);

 }
}

void density()
{
        if((e_b && w_b) == 0)
        {
            if(e_b == 0)
            {
                while(e_b == 0)
                {
                    east();
                }
            }
            else if(w_b == 0)
            {
                while(w_b == 0)
                {
                    west();
                }
            }
        }
        else if((s_b && n_b) == 0)
        {
            if(s_b == 0)
            {
                while(s_b == 0)
                {
                    south();
                }
            }
            else if(n_b == 0)
            {
                while(n_b == 0)
                {
                    north();
                }
            }
        }

}

void east()
{
    e_g = 1;
    e_r = 0;
    s_g = 0;
    s_r = 1;
    w_g = 0;
    w_r = 1;
    n_g = 0;
    n_r = 1;
    e_y = 0;
    s_y = 0;
    w_y = 0;
    n_y = 0;
    delay(1000);
    e_y = 0;
    ready_east();
}

void south()
{
    e_g = 0;
    e_r = 1;
    e_y = 0;
    s_g = 1;
    s_r = 0;
    s_y = 0;
    w_g = 0;
    w_r = 1;
    w_y = 0;
    n_g = 0;
    n_r = 1;
    n_y = 0;
    delay(1000);
    s_y = 0;
    ready_south();
}

void west()
{
    e_g = 0;
    e_r = 1;
    s_g = 0;
    s_r = 1;
    w_g = 1;
    w_r = 0;
    n_g = 0;
    n_r = 1;
    e_y = 0;
    s_y = 0;
    w_y = 0;
    n_y = 0;
    delay(1000);
    w_y = 0;
    ready_west();
}

void north()
{
    e_g = 0;
    e_r = 1;
    s_g = 0;
    s_r = 1;
    w_g = 0;
    w_r = 1;
    n_g = 1;
    n_r = 0;
    e_y = 0;
    s_y = 0;
    w_y = 0;
    n_y = 0;
    delay(1000);
    n_y = 0;
    ready_north();
}

void delay(int val)
{
    int i, j;
    for(i = 0; i < val; i++)
    {
        for(j = 0; j < 1000; j++);
    }
}

void ready_east()
{
    int i;
    e_g = 0;
    for(i = 0; i <= 5; i++)
    {
        e_y = 1;
        delay(50);
        e_y = 0;
        delay(50);
    }
}

void ready_west()
{
    int i;
    w_g = 0;
    for(i = 0; i <= 5; i++)
    {
        w_y = 1;
        delay(50);
        w_y = 0;
        delay(50);
    }
}

void ready_south()
{
    int i;
    s_g = 0;
    for(i = 0; i <= 5; i++)
    {
        s_y = 1;
        delay(50);
        s_y = 0;
        delay(50);
    }
}

void ready_north()
{
    int i;
    n_g = 0;
    for(i = 0; i <= 5; i++)
    {
        n_y = 1;
        delay(50);
        n_y = 0;
        delay(50);
    }
}