#include<SFML/Graphics.hpp>
#include<bits/stdc++.h>
using namespace std;
int main()
{
sf::RenderWindow window(sf::VideoMode(600,600),"Tree Fractal");
int x=300,y=600,l=150,n=1,theta=60;
int rl=l;
queue< pair<pair<int,int>,int> > points;
sf::Vertex line[] =
{
    sf::Vertex(sf::Vector2f(x, y),sf::Color(50,50,50)),
    sf::Vertex(sf::Vector2f(x, y-l),sf::Color(50,50,50))
};
window.draw(line, 2, sf::Lines);
points.push({{x,y-l},90});
while(l>0)
{
l=l/1.56;
for(int i=0;i<n;i++)
{
int px=points.front().first.first;
int py=points.front().first.second;
int ang=points.front().second;
points.pop();
int ang1=ang-theta,ang2=(ang+theta)%360;
if(ang1<0)
{
ang1=360+ang1;
}
pair<int,int> p1={
px-l*cos(3.141592653589793238*(ang1)/180),

py-l*sin(3.141592653589793238*(ang1)/180)
};

pair<int,int> p2={
px-l*cos(3.141592653589793238*(ang2)/180),

py-l*sin(3.141592653589793238*(ang2)/180)
};

sf::Vertex line1[] =
{
    sf::Vertex(sf::Vector2f(px, py),sf::Color(200-200*l/rl,200-200*l/rl,200-200*l/rl)),
    sf::Vertex(sf::Vector2f(p1.first,p1.second),sf::Color(200-200*l/rl,200-200*l/rl,200-200*l/rl))
};
window.draw(line1, 2, sf::Lines);
sf::Vertex line2[] =
{
    sf::Vertex(sf::Vector2f(px, py),sf::Color(200-200*l/rl,200-200*l/rl,200-200*l/rl)),
    sf::Vertex(sf::Vector2f(p2.first,p2.second),sf::Color(200-200*l/rl,200-200*l/rl,200-200*l/rl))
};
window.draw(line2, 2, sf::Lines);
points.push({p1,ang1});
points.push({p2,ang2});
}
n=n*2;
}
window.display();
while(window.isOpen())
{
sf::Event evnt;
while(window.pollEvent(evnt))
{
if(evnt.type==sf::Event::Closed)
{
    window.close();
}
if (evnt.type == sf::Event::KeyPressed)
{
    if (evnt.key.code == sf::Keyboard::X)
    {
        theta=(theta+1)%360;
    }
    if (evnt.key.code == sf::Keyboard::Z)
    {    if(theta==0)
         {
          theta=360;
         }
        theta=theta-1;
    }
}
}

}
}
