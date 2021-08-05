#include<SFML/graphics.hpp>
#include<bits/stdc++.h>
using namespace std;
struct cno
{
double real;
double img;
};
void csq(struct cno *z,struct cno *c)
{
double t=2*z->real*z->img + c->img;
z->real=(z->real*z->real)-(z->img*z->img) +c->real;
z->img=t;
}
float x=0, y=-2.2,zoom=50;
int main()
{
sf::RenderWindow window(sf::VideoMode(250,250),"Mandelbrot");
calc:
cout<<x<<" "<<y<<endl;
window.clear();
for(double i=0;i<=250;i++)
{
for(double j=0;j<=250;j++)
{
struct cno c={i/zoom+x ,j/zoom+y};
struct cno z={0,0};
for(int t=1;t<1000;t++)
{
if(z.real*z.real + z.img*z.img >4.0)
{
t=t*t%1000;
sf::RectangleShape re(sf::Vector2f(1,1));
re.setPosition(sf::Vector2f(i,j));
re.setOutlineThickness(0);
int r=255,g=255,b=255;
if(t>0 && t<167)
{
g=2*t;
b=0;
}
else if(t>166 && t<334)
{
r=255-t/2;
b=0;
}
else if(t>333 && t<500)
{
r=0;
g=2*t;
}
else if(t>499 && t<667)
{
r=0;
g=255-t/2;
}
else if(t>666 && t<999)
{
g=0;
r=2*t;
}
re.setFillColor(sf::Color(r,g,b));
window.draw(re);
break;
}
csq(&z,&c);
}
}
}
window.display();
goto ss;
while (window.isOpen())
    {
        ss:
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
{
zoom+=100;
goto calc;
}
if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
{
y+=10/zoom;
goto calc;
}
if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
{
y-=10/zoom;
goto calc;
}
if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
{
x+=10/zoom;
goto calc;
}
if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
{
x-=10/zoom;
goto calc;
}
}

return 0;
}
