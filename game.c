// Battle-Simulator Game. 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

typedef struct
{

	int life;
	int power;
	int mana;// means power.
	int spell;// means both the enemy attack at a time to player.

} player;

typedef struct
{

	int life;
	int power;

} enemy_stats;

player p1;

enemy_stats *enemy; 

void Initialized_player();
void Initialized_enemy(int *N);
void Generated_enemy(int N);

int main()
{

	int cont = 1; 
	int N = 0;	

	int op, i, attack, target;

	srand(time(NULL)); 

	Initialized_enemy(&N); 
	Initialized_player();

	
	do
	{
		system("cls");
		do
		{

			printf("Your actual mana is: %i \n", p1.mana);
			printf("(1) Attack. \n");
			printf("(2) Spell. \n");
			scanf("%i", &op);

		} while (op < 1 || op > 2);

		system("cls");

		printf("Select enemy to attack: \n");
		for (i = 0; i < N; i++)
		{ 

			if (enemy[i].life > 0)
			{

				printf("Enemy (%i), Life: %i \n", i, enemy[i].life);
			}
		}
		scanf("%i", &target);

		system("cls");

		if (enemy[target].life > 0)
		{

			switch (op)
			{

			case 1:
				attack = p1.power;
				printf("Damage done : % i \n", attack);
				Sleep(2000);
				enemy[target].life -= attack;

				printf("Enemy life: %i, now is: %i", target, enemy[target].life);
				Sleep(2000);

				break;

			case 2:

				if (p1.mana > 0)
				{

					attack = p1.spell * (rand() % 3);
					p1.mana -= 40;
					printf("Damage done : % i \n", attack);
					Sleep(2000);
					enemy[target].life -= attack;

					printf("Enemy life: %i, now is: %i", target, enemy[target].life);
					Sleep(2000);
				}
				else
				{

					printf("You don't have mana buddy \n");
					Sleep(2000);
				}

				break;
			}
		}
		else
		{

			printf("It's already dead lmao \n");
			Sleep(2000);
		}

		printf(" \n Enemy turn: \n");
		Sleep(2000);

		for (i = 0; i < N; i++)
		{

			if (enemy[i].life > 0)
			{

				attack = enemy[i].power * (rand() % 3);
				printf("The enemy %i, as done to me: %i \n", i, attack);
				Sleep(2000);
				p1.life -= attack;
				printf("Actual life: %i \n", p1.life);
				Sleep(2000);
			}
		}

		
		if ((cont % 2) != 0)
		{ 
		
			enemy = (enemy_stats *)realloc(enemy, (N + 1) * sizeof(enemy_stats));
			if (enemy == NULL)
			{
				printf("Error: there's no memory to create an enemy \n");
				exit(1);
			}

			
			Generated_enemy(N); 
			N++;
		}

		cont++;

		p1.mana += 20;

		system("pause");
	} while (p1.life > 0);

	

	free(enemy);

	system("pause");
	return 0;
}

void Initialized_player()
{

	p1.life = 1000;
	p1.power = 50;
	p1.mana = 100;
	p1.spell = 100;
}

void Initialized_enemy(int *N)
{ 

	enemy = (enemy_stats *)malloc((*N + 1) * sizeof(enemy_stats)); 
	
	if (enemy == NULL)
	{
		printf("Error: there's no memory to created an enemy.\n");
		exit(1);
	}

	Generated_enemy(*N); 

	(*N)++; 
}

void Generated_enemy(int N)
{ 

	enemy[N].life = 100; 
	enemy[N].power = 50;
}