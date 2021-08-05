#include<SFML/Graphics.hpp>
#include<bits/stdc++.h>
using namespace std;
int main()
{
sf::RenderWindow window(sf::VideoMode(600,600),"Ray-Cast");
int world[10][10]={
{1,1,1,1,1,1,1,1,1,1},
{1,0,0,0,0,0,0,0,0,1},
{1,0,0,0,0,0,0,0,0,1},
{1,0,0,0,0,1,0,0,0,1},
{1,0,0,0,0,1,0,0,0,1},
{1,0,1,0,0,1,0,0,0,1},
{1,0,0,0,0,1,1,1,1,1},
{1,0,0,0,0,0,0,0,0,1},
{1,0,1,0,0,0,0,0,0,1},
{1,1,1,1,1,1,1,1,1,1}
};
sf::RectangleShape rectangle(sf::Vector2f(128.0f,128.0f));
  rectangle.setFillColor(sf::Color::Red);
  rectangle.setPosition(320,240);
  rectangle.setOrigin(rectangle.getSize().x / 2, rectangle.getSize().y / 2);
double ax=1,ay=0,planex=0,planey=0.7,px=3,py=2.5;
while(window.isOpen())
{
sf::Event evnt;
while(window.pollEvent(evnt))
{
if(evnt.type==sf::Event::Closed)
{
window.close();
}
if(evnt.type==sf::Event::KeyPressed)
{
if (evnt.key.code == sf::Keyboard::Up)
    {
        px-=0.1;
    }
else if(evnt.key.code == sf::Keyboard::Down)
    {
        px+=0.1;
    }
else if(evnt.key.code == sf::Keyboard::Left)
{
  py-=0.1;
}
else if(evnt.key.code == sf::Keyboard::Right)
{
    py+=0.1;
}
}
}
 window.clear();



for(int i=0;i<600;i++)
{
double cameraX = 2 * i / double(600) - 1;
double rayDirX = ax + planex * cameraX;
double rayDirY = ay + planey * cameraX;

int mapX = int(px);
int mapY = int(py);

double sideDistX;
double sideDistY;

double deltaDistX = abs(1 / rayDirX);
double deltaDistY = abs(1 / rayDirY);
double perpWallDist;

int stepX;
int stepY;

int hit = 0;
int side;

if (rayDirX < 0)
      {
        stepX = -1;
        sideDistX = (px - mapX) * deltaDistX;
      }
      else
      {
        stepX = 1;
        sideDistX = (mapX + 1.0 - px) * deltaDistX;
      }
      if (rayDirY < 0)
      {
        stepY = -1;
        sideDistY = (py - mapY) * deltaDistY;
      }
      else
      {
        stepY = 1;
        sideDistY = (mapY + 1.0 - py) * deltaDistY;
      }

      while (hit == 0)
      {
        if (sideDistX < sideDistY)
        {
          sideDistX += deltaDistX;
          mapX += stepX;
          side = 0;
        }
        else
        {
          sideDistY += deltaDistY;
          mapY += stepY;
          side = 1;
        }
        if (world[mapX][mapY] > 0) hit = 1;
      }
       if (side == 0) perpWallDist = (mapX - px + (1 - stepX) / 2) / rayDirX;
      else  perpWallDist = (mapY - py + (1 - stepY) / 2) / rayDirY;
      sf::Vertex line[] =
      {
      sf::Vertex(sf::Vector2f(i, 300-300/perpWallDist),sf::Color(255-300/perpWallDist,255-300/perpWallDist,255-300/perpWallDist)),
      sf::Vertex(sf::Vector2f(i, 300+300/perpWallDist),sf::Color(255-300/perpWallDist,255-300/perpWallDist,255-300/perpWallDist))
      };
     window.draw(line, 2, sf::Lines);
}
 window.display();
}

return 0;

}

