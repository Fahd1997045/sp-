#include <SFML/Graphics.hpp>
using namespace sf;
#define width 1024
#define height 720


int main() {
    RenderWindow project(VideoMode(width, height), "flappy bird");



        while (project.isOpen())
        {
            Event event;
            while (project.pollEvent(event))
            {
                if (event.type == Event::Closed)
                    project.close();
            }

        }
    project.clear();
    project.display();





















}
