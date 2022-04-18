// Dania Nasereddin 2-5-20 #19
// Lab 02 - Functions
// This program is an RPG that allows the user to attack
// or to run away from an enemy. The player and enemy will
// take turns attacking if the player chooses to attack. The player
// has 20 health and the enemy has 10 health. The game ends when 
// the player or enemy runs out of health.  

#include <iostream>
#include <time.h>
using namespace std;

char menu();
void takeHit(int &playerHP);  // Prototypes
int makeAttack(int enemyHP);

int main()
{
	char answer;
	srand(time(0));
	int playerHP = 20;
	int enemyHP = 10;

	cout << "Welcome to Tale of a Foe, a mini RPG!" << endl;
	cout << "You spawn with 20 health!" << endl;

	while (playerHP > 0 && enemyHP > 0) // While the player and enemy is alive
	{
		answer = menu();

		if (answer == 'f') // If they choose to run away 
		{
			cout << "You fled from your enemy safely!" << endl;
			cout << "Game Over" << endl;
			return 0;
		}
		else if (answer == 'a') // If they choose to attack 
		{
			takeHit(playerHP);
			enemyHP = makeAttack(enemyHP);
		}
	}
	
	if (playerHP <= 0) // If the player dies
	{
		cout << "You died" << endl;
	}
	if (enemyHP <= 0) // If the enemy dies
	{
		cout << "You defeated your foe!" << endl;
	}

	cout << "Game Over" << endl;

	system("pause>nul");
	return 0;
}

char menu() // A function for the menu presented to the player with two options,  
			// to run or to attack
{
	char answer;
	cout << "An enemy lies before you, what will you do?" << endl;
	cout << "To attack enter (a), To flee enter (f): ";
	cin >> answer;
	return answer;
}

void takeHit(int &playerHP) // A function that calculates the damage the player takes 
							// and their remaining HP
{
	int hit = rand() % 5 + 1; // Randomizes how much damage the player takes
	cout << "The enemy strikes you for " << hit << " damage!" << endl;
	playerHP -= hit; // Subtracts the damage to your health
	cout << "You have " << playerHP << " HP remaining " << endl;
}

int makeAttack(int enemyHP)  // A function that calculates the damage the enemy takes 
							 // and their remaining HP
{
	int attack = rand() % 5 + 1; // Randomizes how much damage the enemy takes
	cout << "You strike your foe for " << attack << " damage!" << endl;
	enemyHP -= attack; // Subtracts the damage to the enemy's health
	cout << "Your enemy has " << enemyHP << " HP remaining " << endl;
	return enemyHP;
}
