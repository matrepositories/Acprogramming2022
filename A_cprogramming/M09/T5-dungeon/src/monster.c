/**
 * \file monster.c
 * \brief Implementation of monster actions
 * \version 0.1
 * 
 * \copyright Aalto University, Department of Communications and Networking (c) 2022
 * 
 */

#include "dungeon.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * \brief A monster type that can be used in the game
 * 
 */
typedef struct {
	char name[20];		 //!< Name of monster
	char sign;			 //!< character to show it on map
	unsigned int hplow;	 //!< lowest possible initial maxhp
	unsigned int hphigh; //!< highest possible initial maxhp
} MonstType;

/**
 * \brief A list of ready-made monster types
 * 
 * \details Defines three monster types to start with.
 * 
 * 
 * \note Feel free to add more, or change the below.
 *       It is up to you to decide whether to use this array from createMonsters.
 *         
 */
const MonstType types[] = {{"Goblin", 'G', 6, 10},
						   {"Rat", 'R', 3, 5},
						   {"Dragon", 'D', 15, 20}};

/**
 * \brief One kind of attack done by monster. The mosters' attack function 
 *        pointer can refer to this.
 * 
 * \param game The game 
 * \param monst The monster performing attack
 */
void attackPunch(Game* game, Creature* monst) {
	printf("%s punches you! ", monst->name);
	int hitprob = 50;
	int maxdam = 4;
	if(rand() % 100 < hitprob) {
		printf("Hit! ");
		int dam = rand() % maxdam + 1;
		printf("Damage: %d ", dam);
		game->hp = game->hp - dam;
		if(game->hp <= 0)
			printf("You died!");
		printf("\n");
	} else {
		printf("Miss!\n");
	}
}



/**
 * \brief Move monster 'monst' towards the player character by one tile.
 * 
 * \details The game logic uses this function to move the monsters, which have 
 *          high enough hitpoints, towards the player. The function must obey 
 *          the following restrictions.
 *
 *          a. Monsters do not move diagonally.
 *
 *          b. If possible, the distance between monster and the character should 
 *             reduce when the function returns.
 *
 *          c. A monster must not move more than one tile on the map.
 *
 *          d. A monster must not move over/into a wall.
 *       
 *          e. A monster must not move to a tile occupied by another monster.
 *       
 *          f. A monster must not move to a tile occupied by the player. 
 *
 *          Besides these restrictions, you are free to choose the details of the 
 *          movement algorithm.
 *
 *        note: 
 *         
 *         1. You can assume that monsters have magical powers to detect the player's 
 *            location irrespective of the walls between them.
 *
 *         2. Do not check the hitpoints of the monster since the game logic 
 *            already does so.
 *
 * \param game The game state
 * \param monst The monster to be moved toward the player
 */
void moveTowards(const Game* game, Creature* monst) {
	Point playerpos = game->position;
	Point monsterpos = monst->pos;
	double distance = sqrt(pow(monsterpos.y - playerpos.y, 2) + pow(monsterpos.x - playerpos.y, 2));
	

	int xpos[3];
	xpos[0] = monsterpos.x - 1 < 1 ? 1 : monsterpos.x - 1;
	xpos[1] = monsterpos.x;
	xpos[2] = monsterpos.x + 1 >= (int) game->opts.mapWidth ? (int) game->opts.mapWidth : monsterpos.x + 1; 

	int ypos[3];
	ypos[0] = monsterpos.y - 1 < 1 ? 1 : monsterpos.y - 1;
	ypos[1] = monsterpos.y;
	ypos[2] = monsterpos.y + 1 >= (int) game->opts.mapHeight ? (int) game->opts.mapHeight : monsterpos.y + 1; 

	for (int i = 0; i < 3; i++) 
		{
			for (int j = 0; j < 3; j++)
			{
				Point newpos;
				newpos.y = ypos[i];
				newpos.x = xpos[j];
				double newdistance = sqrt(pow(newpos.y - playerpos.y, 2) + pow(newpos.x - playerpos.x, 2));
				//double distance = calc_dist(new_pos, playerpos);
				if (newdistance < distance && !isBlocked(game, xpos[j], ypos[i]) && distance > 0) {
					monst->pos.y = newpos.y;
					monst->pos.x = newpos.x;
				}
			} 
		}
	//(void) game; 
	//(void) monst; 
	// TODO: implement this function 
	
}

/**
 * \brief Move monster 'monst' away the player character by one tile.
 * 
 * \details The game logic uses this function to move the monsters, which have 
 *          low hitpoints, away from the player. The function must obey 
 *          the following restrictions.
 *
 *          a. Monsters do not move diagonally.
 *
 *          b. If possible, the distance between monster and the character should 
 *             increase when the function returns.
 *
 *          c. A monster must not move more than one tile on the map.
 *
 *          d. A monster must not move over/into a wall.
 *       
 *          e. A monster must not move to a tile occupied by another monster.
 *       
 *          f. A monster must not move to a tile occupied by the player. 
 *
 *          Besides these restrictions, you are free to choose the details of the 
 *          movement algorithm.
 *
 *        note: 
 *         
 *         1. You can assume that monsters have magical powers to detect the player's 
 *            location irrespective of the walls between them.
 *
 *         2. Do not check the hitpoints of the monster since the game logic 
 *            already does so.
 * 
 * \param game The game state
 * \param monst The monster to be moved away the player
 */
void moveAway(const Game* game, Creature* monst) {
	Point playerpos = game->position;
	Point monsterpos = monst->pos;
	double distance = sqrt(pow(monsterpos.y - playerpos.y, 2) + pow(monsterpos.x - playerpos.y, 2));
	

	int xpos[3];
	xpos[0] = monsterpos.x - 1 < 1 ? 1 : monsterpos.x - 1;
	xpos[1] = monsterpos.x;
	xpos[2] = monsterpos.x + 1 >= (int) game->opts.mapWidth ? (int) game->opts.mapWidth : monsterpos.x + 1; 

	int ypos[3];
	ypos[0] = monsterpos.y - 1 < 1 ? 1 : monsterpos.y - 1;
	ypos[1] = monsterpos.y;
	ypos[2] = monsterpos.y + 1 >= (int) game->opts.mapHeight ? (int) game->opts.mapHeight : monsterpos.y + 1; 

	for (int i = 0; i < 3; i++) 
		{
			for (int j = 0; j < 3; j++)
			{
				Point newpos;
				newpos.y = ypos[i];
				newpos.x = xpos[j];
				double newdistance = sqrt(pow(newpos.y - playerpos.y, 2) + pow(newpos.x - playerpos.x, 2));
				//double distance = calc_dist(new_pos, playerpos);
				if (newdistance > distance && !isBlocked(game, xpos[j], ypos[i]) && distance > 0) {
					monst->pos.y = newpos.y;
					monst->pos.x = newpos.x;
				}
			} 
		}

	//(void) game; 
	//(void) monst; 
	// TODO: implement this function 
	
}



/**
 * \brief  Takes action on each monster (that is alive) in 'monsters' array.
 * 
 * \details For each monster, the function should 
 *       
 *       a. if a monster is in an adjacent location to the player, 
 *          it should try to attack the player. 
 *       
 *       b. Otherwise, the monster should invoke the movement action. 
 *          
 *       c. If monster is dead (with hitpoints zero or less), no action is taken.
 *
 *       note:: 
 *         A. Function pointers attack and move in Creature
 *            structure determine the action to be taken. You are required 
 *            to call these function pointers to invoke either of 
 *            monster actions. 
 *         
 *            If either of the function pointers is NULL, the respective 
 *            action is ignored. 
 *         
 *         B. You should specify valid attack and movement behaviors (i.e., 
 *            function pointers) when creating monsters. The game template 
 *            provides one attack behavior, but you are free to define more.
 *
 * 
 * \param game The game
 */
void monsterAction(Game* game) {
	/*for (unsigned int i = 0; i < game->numMonsters; i++) {
		Creature monster = game->monsters[i];
		double distance = sqrt(pow(game->position.y - monster.pos.y, 2) + pow(game->position.x - monster.pos.y, 2));
		//double distance = calc_dist(game->position, monster.pos);
		if (monster.hp == 0) {
			return;
		}

		if (distance == 1.0) {
			monster.attack(game, &game->monsters[i]);
		} else {
			monster.move(game, &game->monsters[i]);
		}
	}*/
	(void) game; 
	// TODO: implement this function 
	
}



/**
 * \brief  Create opts.numMonsters monsters and position them on valid positions 
 *         in the the game map. The moster data (hitpoints, name, map sign) 
 *         should be set appropriately.
 * 
 * \details The function should 
 *       
 *       1. create ``opts.numMonsters`` number of monsters.
 *
 *       2. allocate memory for each monster in ``monsters`` array of the ``game`` 
 *          object (i.e. ).
 *    
 *       3. place them on random free positions on the map that are 
 *          
 *          a. not wall tiles, and 
 *          b. not occupied by other monsters, and
 *          v. inside the map area. 
 *
 *          hint: 
 *            You can use isBlocked function to check if a monster can be 
 *            placed at a random position.
 *
 *       4. initializes other monster details, such as name, the map sign shown 
 *          on the user interface, hitpoints, and so on.
 *
 *          a. Each monster must have more than ``0`` hit points, and initial 
 *             hit points should be set to the maximum HP.
 *          
 *          b. The monster name must be properly initialized.
 *          
 *          c. The monster's map sign must be an alphabetic character.
 *          
 *          d. The other fields can be initialized freely.
 * 
 * \param game The game
 */
void createMonsters(Game* game) {
	game->monsters = malloc(sizeof(Creature) * game->opts.numMonsters);	
	game->numMonsters = 0;
	for (unsigned int i = 0; i < game->opts.numMonsters; i++) 
	{
		Creature newcreature;

		unsigned int x;
		unsigned int y;

		/*do {
			x = rand() % game->opts.mapWidth;
			y = rand() % game->opts.mapHeight;
		} while (isBlocked(game, y, x));*/

		while(1)
		{
			x = rand() % game->opts.mapWidth;
			y = rand() % game->opts.mapHeight;
			if(!isBlocked(game, x, y))
			{
				break;
			}
		}

		Point pos;
		pos.x = x;
		pos.y = y;
		
		/*while(1)
		{
			if(!(x == game->monsters[k].pos.x && y == game->monsters[k].pos.y))
			{

			}
		}*/

		newcreature.pos = pos;

		newcreature.maxhp = 1 + (rand() % 1000);
		newcreature.hp = newcreature.maxhp;

		newcreature.sign = 97 + (rand() % 26);

		for (unsigned int j = 0; j < 19; j++) {
			newcreature.name[j] = 97 + (rand() % 26);	
		}
		newcreature.name[19] = '\0';
		
		newcreature.move = moveTowards;
		newcreature.attack = attackPunch;

		game->monsters[i] = newcreature;
		game->numMonsters++;
	}
	(void) game; 
	
}

/**
 * \brief Determine whether the monsters move towards or away from the 
 * player character.
 * 
 * \param game The game
 */
void checkIntent(Game* game) {
	for(unsigned int i = 0; i < game->numMonsters; i++) {
		Creature* m = &game->monsters[i];
		if(m->hp <= 2) {
			m->move = moveAway;
		} else {
			m->move = moveTowards;
		}
		if(m->hp < m->maxhp)
			m->hp = m->hp + 0.1; // heals a bit every turn
	}
}
