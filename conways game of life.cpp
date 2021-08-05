#include<SFML/Graphics.hpp>
#include<bits/stdc++.h>
using namespace std;
int main()
{
sf::RenderWindow window(sf::VideoMode(600,600),"Conway's Game Of Life");
bool editmode=1;
int pixs=5,n1=window.getSize().x/pixs,n2=window.getSize().y/pixs;
int a[n2+2][n1+2],b[n2+2][n1+2];
memset(a,0,sizeof(a));memset(b,0,sizeof(b));
while(window.isOpen())
{
sf::Event event;
while(window.pollEvent(event))
{
    if(event.type==sf::Event::Closed)
    {
    window.close();
    }
    if(editmode && sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
     int x=sf::Mouse::getPosition(window).x/pixs;
     int y=sf::Mouse::getPosition(window).y/pixs;
     a[y+1][x+1]=1;
     cout<<x<<" "<<y<<endl;
    }
    if(editmode && sf::Mouse::isButtonPressed(sf::Mouse::Right))
    {
     int x=sf::Mouse::getPosition(window).x/pixs;
     int y=sf::Mouse::getPosition(window).y/pixs;
     a[y+1][x+1]=0;
     cout<<x<<" "<<y<<endl;
    }
    if(event.type==sf::Event::KeyPressed)
    {
    if(event.key.code==sf::Keyboard::Space)
       editmode=!editmode;
    }
}
if(editmode==1)
{
window.clear();
for(int i=1;i<=n2;i++)
{
 for(int j=1;j<=n1;j++)
 {
if(a[i][j]==1)
  {
   sf::RectangleShape pixl;
  pixl.setSize(sf::Vector2f(pixs,pixs));
  pixl.setPosition((j-1)*pixs,(i-1)*pixs);
  window.draw(pixl);
  }
 }
}
window.display();
}
else
{
window.clear();
for(int i=1;i<=n2;i++)
{
 for(int j=1;j<=n1;j++)
 {
int nc=a[i-1][j-1]+a[i+1][j+1]+a[i-1][j]+a[i][j-1]+a[i+1][j]+a[i][j+1]+a[i+1][j-1]+a[i-1][j+1];
if(a[i][j]==1)
  {
  sf::RectangleShape pixl;
  pixl.setSize(sf::Vector2f(pixs,pixs));
  pixl.setPosition((j-1)*pixs,(i-1)*pixs);
  window.draw(pixl);
  if(nc==2 || nc==3)
  {
   b[i][j]=1;
  }
  }
if(a[i][j]==0)
  {
    if(nc==3)
    {
     b[i][j]=1;
    }
  }
 }
}

for(int i=1;i<=n2;i++)
{
 for(int j=1;j<=n1;j++)
 {
  a[i][j]=b[i][j];
  b[i][j]=0;
 }
 }
 window.display();
}

}
}
