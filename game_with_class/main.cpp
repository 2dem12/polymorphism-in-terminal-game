#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include "class.hpp"


int main() {
    Hero hero;
    srand(time(0));

    Dragon* dragons[] = {new RedDragon, new GreenDragon, new BlackDragon};

    for (Dragon* dragon: dragons) {
        while (dragon->is_alive() && hero.is_alive()) {
            dragon->question(rand()%15, rand()%15);
            dragon->set_answer();

            if (dragon->check_answer()) {
                hero.attack(*dragon);
            } else {
                dragon->attack(hero);
            }
            printf("\n\nhp dragon = %i\n", dragon->cout_hp());
            printf("hp hero = %i\n\n\n", hero.cout_hp());

        }
        if (dragon->is_alive()) {
            printf("You lose\n");
            exit(0);
        } else {
            printf("You win )))\n");
            if (dragon->get_color() != 'b') {
                printf("But there is also a dragon\n");
            }
        }
    }
    printf("\n\nYou've defeated all the dragons\n");
}
