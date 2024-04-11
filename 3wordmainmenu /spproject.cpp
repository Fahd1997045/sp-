#include <SFML/Graphics.hpp>
#include "menu.h"
using namespace sf;
#define width 900
#define height 500
int pagenum = 1000;
void ename(RenderWindow& sp, string& name);



int main() {
    RenderWindow sp(VideoMode(width, height), "flappy bird");
    menu menu(width, height);
    Texture menubackground;
    menubackground.loadFromFile("flappy bird menu.png");
        Sprite background;
        background.setTexture(menubackground);
        string name;



        if (pagenum == 1000) {

            while (sp.isOpen())
            {
                Event event;
                while (sp.pollEvent(event))
                {
                    if (event.type == Event::Closed) {
                        sp.close();
                    }
                    if (event.type == Event::KeyPressed) {

                        if (event.key.code == Keyboard::Up) {
                            menu.moveup();
                        }
                        if (event.key.code == Keyboard::Down) {
                            menu.movedown();
                        }
                        if (event.key.code == Keyboard::Enter) {
                            if (menu.pressed() == 0) {
                                pagenum = 0;
                            }
                            if (menu.pressed() == 1) {
                                pagenum = 1;
                            }
                            if (menu.pressed() == 2) {
                                pagenum = 2;
                            }

                        }
                    }
                }
                sp.clear();
                if (pagenum != 1000) {
                    break;
                }
               
                sp.draw(background);
                menu.draw(sp);
                sp.display();
                
              


            }
            if (pagenum == 2) {
                sp.close();
            }
            if (pagenum == 0){
                ename(sp, name);
            }












       }
    


















    return 0;

}
void ename(RenderWindow& sp, string& name) {
    if (!name.empty()) {
        name.clear();
    }
    Texture menubackground;
    menubackground.loadFromFile("flappy bird menu.png");
    Sprite background;
    background.setTexture(menubackground);
    Font font;
    font.loadFromFile("Deutsch.ttf");
    Text t1;
    Text t2;
    t1.setFont(font);
    t2.setFont(font);
    t1.setCharacterSize(70);
    t2.setCharacterSize(70);
    t1.setFillColor(Color{ 255,204,0 });
    t2.setFillColor(Color{ 255,204,0 });
    t1.setPosition(Vector2f(width / 12, height / 8));
    while (sp.isOpen())
    {
        Event event;
        while (sp.pollEvent(event))
        {
            if (event.type == Event::Closed) {
                sp.close();
            }
            if (event.type == Event::TextEntered) {
                name += static_cast<char>(event.text.unicode);

            }
            if (Keyboard::isKeyPressed(Keyboard::BackSpace) && name.size() > 0) {
                name.resize(name.size() - 1);
            }
            if (Keyboard::isKeyPressed(Keyboard::Enter) && name.size() >= 1) {
                pagenum = 3;


            }
            if (Keyboard::isKeyPressed(Keyboard::Escape)) {
                pagenum = 1000;
            }




        }
        t2.setString(name);
        sp.clear();
        sp.draw(background);
        sp.draw(t1);
        sp.draw(t2);
        sp.display();
    }
}
