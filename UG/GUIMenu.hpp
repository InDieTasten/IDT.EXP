#ifndef GUIMenu_cpp
#define GUIMenu_cpp

#include <list>
#include "GUIElement.hpp"

class GUIMenu
{
    //MEMBERS
public:
    sf::Sprite closeButton;
    sf::RectangleShape mainBackground;
    sf::RectangleShape titleBar;
    sf::Text menuTitle;
    int X;      // Unit = pixel
    int Y;      // Unit = pixel
    int Height; // Unit = pixel
    int Width;  // Unit = pixel
    bool isHidden;

    //interaction assist
    bool moving;
    sf::Vector2<int> movingD;
    bool closeButtonHover;
    bool closeButtonPushed;
    std::string ID;
    std::list<GUIElement> GuiElements;
    bool isActive;

    //CONSTRUCTORS
    GUIMenu();
    //DESTRUCTORS

    //METHODS
    void update();
    void SetHeight(int _height);
    void SetWidth(int _width);
    void SetX(int _x);
    void SetY(int _y);
    void SetMenuTitle(std::string _title);
    void render();
    void handleEvent(sf::Event* _event);
    void handleSoftEvent(std::list<std::string> _args);
    void handleTask(std::list<std::string> _args);
    void Enable();
    void Disable();
    void Show();
    void Hide();
    bool isHit(int,int);
};

#endif
