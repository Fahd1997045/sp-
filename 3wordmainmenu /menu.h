#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;
class menu
{
public:
	Text mainmenu[3];
	menu(float width, float height);
	void draw(RenderWindow& sp);
	void moveup();
	void movedown();
	int pressed() {
		return selected;
	}
	

private:
	Font font;
	int selected;


};
