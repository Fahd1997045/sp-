#include "menu.h"
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;


menu::menu(float width, float height) {
	font.loadFromFile("Deutsch.ttf");


	mainmenu[0].setFont(font);
	mainmenu[0].setFillColor(Color{ 255,204,0 });
	mainmenu[0].setString("play");
	mainmenu[0].setCharacterSize(90);
	mainmenu[0].setPosition(Vector2f(width/12 , height /8));

	mainmenu[1].setFont(font);
	mainmenu[1].setFillColor(Color::Black);
	mainmenu[1].setString("settings");
	mainmenu[1].setCharacterSize(90);
	mainmenu[1].setPosition(Vector2f(width/12 , height/8 + 100));


	mainmenu[2].setFont(font);
	mainmenu[2].setFillColor(Color::Black);
	mainmenu[2].setString("exit");
	mainmenu[2].setCharacterSize(90);
	mainmenu[2].setPosition(Vector2f(width/12 , height / 8 + 200));


	selected = 0;

}





void menu::draw(RenderWindow& sp) {

	for (int i = 0;i < 3;i++) {
		sp.draw(mainmenu[i]);
	}


}

void menu::movedown() {

	if (selected  <= 2) {
		mainmenu[selected].setFillColor(Color::Black);
		selected++;
		if (selected == 3) {
			selected = 0;
		}
		mainmenu[selected].setFillColor(Color{ 255,204,0 });
	}
	


}

void menu::moveup() {
	if (selected  >= 0) {
		mainmenu[selected].setFillColor(Color::Black);
		selected--;
		if (selected == -1) {
			selected = 2;
		}
		mainmenu[selected].setFillColor(Color{ 255,204,0 });




	}



}





