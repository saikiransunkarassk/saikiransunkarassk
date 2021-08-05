#include<SFML/Graphics.hpp>
#include<iostream>
using namespace std;
struct point
{
float x,y;
};
int main()
{
struct point p1,p2,p3;
struct point* p=&p1;
int cp=0;
p1={10,590},p2={30,300},p3={590,590};
sf::RenderWindow window(sf::VideoMode(600,600),"Curve");
while(window.isOpen())
{
sf::Event event;
if(window.pollEvent(event))
{
if(event.type==sf::Event::Closed)
{
    window.close();
}
if(event.key.code == sf::Keyboard::Space)
{
cp++;
cp%=3;
if(cp==0)
{
p=&p1;
}
if(cp==1)
{
p=&p2;
}
if(cp==2)
{
p=&p3;
}
}
if(event.key.code == sf::Keyboard::Up)
{
(p->y)--;
}
if(event.key.code == sf::Keyboard::Down)
{
(p->y)++;
}
if(event.key.code == sf::Keyboard::Left)
{
(p->x)--;
}
if(event.key.code == sf::Keyboard::Right)
{
(p->x)++;
}
}
int x1dist=p2.x-p1.x;
int y1dist=p2.y-p1.y;
int x2dist=p3.x-p2.x;
int y2dist=p3.y-p2.y;
sf::VertexArray points(sf::Lines,101);
sf::CircleShape s1(10);
sf::CircleShape s2(10);
sf::CircleShape s3(10);
s1.setPosition(p1.x-5,p1.y-5);
s2.setPosition(p2.x-5,p2.y-5);
s3.setPosition(p3.x-5,p3.y-5);
s1.setFillColor((cp==0)?sf::Color::Red : sf::Color::Blue);
s2.setFillColor((cp==1)?sf::Color::Red : sf::Color::Blue);
s3.setFillColor((cp==2)?sf::Color::Red : sf::Color::Blue);

for(int i=0;i<=100;i++)
{
 struct point pp={p1.x+(i*x1dist)/100,p1.y+(i*y1dist)/100};
 struct point pq={p2.x+(i*x2dist)/100,p2.y+(i*y2dist)/100};
points[i].position = sf::Vector2f(pp.x+(i*(pq.x-pp.x)/100),pp.y+(i*(pq.y-pp.y)/100));
}
window.clear();
window.draw(points);
window.draw(s1);
window.draw(s2);
window.draw(s3);
window.display();
}
}
