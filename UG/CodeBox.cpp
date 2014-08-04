#include "CodeBox.hpp"

//CONSTRUCTORS

//DESTRUCTORS

//METHODS
void CodeBox::Setup()
{
    text.push_back("");
    cursor_line = 1;
    cursor_char = 1;
}
void CodeBox::Update(DataBank* _dataLink, int _x, int _y)
{
    for(std::list<std::string>::iterator it=text.begin(); it != text.end(); ++it)
    {
        text1.SetText(*it);
        text1.SetPosition((float)_x, (float)_y);
        text1.SetFont(*_dataLink->FontGet("$_menuTitle"));
        text1.SetSize(12.0);
        text1.SetScale(1.0,1.0);
        rect = sf::Shape::Rectangle((float)_x,(float)_y,(float)_x+Width,(float)_y+Height,sf::Color(20,20,20,150),1.0f,sf::Color(255,255,255,50));

    }
    std::list<std::string>::iterator it = text.begin();
    for(int i = cursor_line; i > 0; i--)
    {
        it++;
    }
    Y = (cursor_line*12);
    X =	(cursor_char*7);
    c = sf::Shape::Rectangle(X,Y,X+7,Y+12,sf::Color(20,220,20,150),1.0f,sf::Color(50,255,50,50));
}
void CodeBox::Render(DataBank* _dataLink)
{
    _dataLink->renderWindow->Draw(rect);
    _dataLink->renderWindow->Draw(c);
    _dataLink->renderWindow->Draw(text1);

}
void CodeBox::handleEvent(sf::Event* _event, const sf::Input* _input, int _x, int _y)
{
    std::list<std::string>::iterator it = text.begin();
    for(int i = cursor_line; i > 0; i--)
    {
        it++;
    }

    if(isActive)
    {
        if(_event->Type == sf::Event::KeyPressed)
        {
            if(_input->IsKeyDown(sf::Key::Back))
            {
                text.pop_back();
                cursor_char--;
            }
            else if(_input->IsKeyDown(sf::Key::Return))
            {
                cursor_line++;
                *it += '\n';
            }
            else if(_input->IsKeyDown(sf::Key::Down))
            {
                cursor_line++;
            }
            else if(_input->IsKeyDown(sf::Key::Up))
            {
                cursor_line--;
            }
            else if(_input->IsKeyDown(sf::Key::Left))
            {
                cursor_char--;
            }
            else if(_input->IsKeyDown(sf::Key::Right))
            {
                cursor_char++;
            }
        }

        else if((_input->IsKeyDown(sf::Key::LAlt) && _input->IsKeyDown(sf::Key::LControl) || _input->IsKeyDown(sf::Key::LAlt)
                 && _input->IsKeyDown(sf::Key::RControl) || _input->IsKeyDown(sf::Key::RAlt)) && !_input->IsKeyDown(sf::Key::LShift)
                && !_input->IsKeyDown(sf::Key::RShift))
        {
            tmp = getInput(2, _event);
            if(tmp != 0)
            {
                *it += tmp;
                cursor_char++;
            }
        }
        else if((_input->IsKeyDown(sf::Key::LShift) || _input->IsKeyDown(sf::Key::RShift)) && !_input->IsKeyDown(sf::Key::LControl)
                && !_input->IsKeyDown(sf::Key::RControl) && !_input->IsKeyDown(sf::Key::LAlt) && !_input->IsKeyDown(sf::Key::RAlt))
        {
            tmp = getInput(1, _event);
            if(tmp != 0)
            {
                *it += tmp;
                cursor_char++;
            }

        }
        else if(!_input->IsKeyDown(sf::Key::LShift) && !_input->IsKeyDown(sf::Key::RShift) && !_input->IsKeyDown(sf::Key::LControl)
                && !_input->IsKeyDown(sf::Key::RControl) && !_input->IsKeyDown(sf::Key::LAlt) && !_input->IsKeyDown(sf::Key::RAlt))
        {
            tmp = getInput(0, _event);
            if(tmp != 0)
            {
                *it += tmp;
                cursor_char++;
            }
        }
    }
}

char CodeBox::getInput(int Type,sf::Event* _event)
{
    switch (_event->Key.Code)
    {
    case sf::Key::A :
        if(Type == 0)
        {
            return 'a';
        }
        else if(Type == 1)
        {
            return 'A';
        }
        else if(Type == 2)
        {
            std::cout << "\a" << std::endl;
            return 0;
        };
    case sf::Key::B :
        if(Type == 0)
        {
            return 'b';
        }
        else if(Type == 1)
        {
            return 'B';
        }
        else if(Type == 2)
        {
            std::cout << "\a" << std::endl;
            return 0;
        };
    case sf::Key::C :
        if(Type == 0)
        {
            return 'c';
        }
        else if(Type == 1)
        {
            return 'C';
        }
        else if(Type == 2)
        {
            std::cout << "\a" << std::endl;
            return 0;
        };
    case sf::Key::D :
        if(Type == 0)
        {
            return 'd';
        }
        else if(Type == 1)
        {
            return 'D';
        }
        else if(Type == 2)
        {
            std::cout << "\a" << std::endl;
            return 0;
        };
    case sf::Key::E :
        if(Type == 0)
        {
            return 'e';
        }
        else if(Type == 1)
        {
            return 'E';
        }
        else if(Type == 2)
        {
            return '�';
        };
    case sf::Key::F :
        if(Type == 0)
        {
            return 'f';
        }
        else if(Type == 1)
        {
            return 'F';
        }
        else if(Type == 2)
        {
            std::cout << "\a" << std::endl;
            return 0;
        };
    case sf::Key::G :
        if(Type == 0)
        {
            return 'g';
        }
        else if(Type == 1)
        {
            return 'G';
        }
        else if(Type == 2)
        {
            std::cout << "\a" << std::endl;
            return 0;
        };
    case sf::Key::H :
        if(Type == 0)
        {
            return 'h';
        }
        else if(Type == 1)
        {
            return 'H';
        }
        else if(Type == 2)
        {
            std::cout << "\a" << std::endl;
            return 0;
        };
    case sf::Key::I :
        if(Type == 0)
        {
            return 'i';
        }
        else if(Type == 1)
        {
            return 'I';
        }
        else if(Type == 2)
        {
            std::cout << "\a" << std::endl;
            return 0;
        };
    case sf::Key::J :
        if(Type == 0)
        {
            return 'j';
        }
        else if(Type == 1)
        {
            return 'J';
        }
        else if(Type == 2)
        {
            std::cout << "\a" << std::endl;
            return 0;
        };
    case sf::Key::K :
        if(Type == 0)
        {
            return 'k';
        }
        else if(Type == 1)
        {
            return 'K';
        }
        else if(Type == 2)
        {
            std::cout << "\a" << std::endl;
            return 0;
        };
    case sf::Key::L :
        if(Type == 0)
        {
            return 'l';
        }
        else if(Type == 1)
        {
            return 'L';
        }
        else if(Type == 2)
        {
            std::cout << "\a" << std::endl;
            return 0;
        };
    case sf::Key::M :
        if(Type == 0)
        {
            return 'm';
        }
        else if(Type == 1)
        {
            return 'M';
        }
        else if(Type == 2)
        {
            return '�';
        };
    case sf::Key::N :
        if(Type == 0)
        {
            return 'n';
        }
        else if(Type == 1)
        {
            return 'N';
        }
        else if(Type == 2)
        {
            std::cout << "\a" << std::endl;
            return 0;
        };
    case sf::Key::O :
        if(Type == 0)
        {
            return 'o';
        }
        else if(Type == 1)
        {
            return 'O';
        }
        else if(Type == 2)
        {
            std::cout << "\a" << std::endl;
            return 0;
        };
    case sf::Key::P :
        if(Type == 0)
        {
            return 'p';
        }
        else if(Type == 1)
        {
            return 'P';
        }
        else if(Type == 2)
        {
            std::cout << "\a" << std::endl;
            return 0;
        };
    case sf::Key::Q :
        if(Type == 0)
        {
            return 'q';
        }
        else if(Type == 1)
        {
            return 'Q';
        }
        else if(Type == 2)
        {
            return '@';
        };
    case sf::Key::R :
        if(Type == 0)
        {
            return 'r';
        }
        else if(Type == 1)
        {
            return 'R';
        }
        else if(Type == 2)
        {
            std::cout << "\a" << std::endl;
            return 0;
        };
    case sf::Key::S :
        if(Type == 0)
        {
            return 's';
        }
        else if(Type == 1)
        {
            return 'S';
        }
        else if(Type == 2)
        {
            std::cout << "\a" << std::endl;
            return 0;
        };
    case sf::Key::T :
        if(Type == 0)
        {
            return 't';
        }
        else if(Type == 1)
        {
            return 'T';
        }
        else if(Type == 2)
        {
            std::cout << "\a" << std::endl;
            return 0;
        };
    case sf::Key::U :
        if(Type == 0)
        {
            return 'u';
        }
        else if(Type == 1)
        {
            return 'U';
        }
        else if(Type == 2)
        {
            std::cout << "\a" << std::endl;
            return 0;
        };
    case sf::Key::V :
        if(Type == 0)
        {
            return 'v';
        }
        else if(Type == 1)
        {
            return 'V';
        }
        else if(Type == 2)
        {
            std::cout << "\a" << std::endl;
            return 0;
        };
    case sf::Key::W :
        if(Type == 0)
        {
            return 'w';
        }
        else if(Type == 1)
        {
            return 'W';
        }
        else if(Type == 2)
        {
            std::cout << "\a" << std::endl;
            return 0;
        };
    case sf::Key::X :
        if(Type == 0)
        {
            return 'x';
        }
        else if(Type == 1)
        {
            return 'X';
        }
        else if(Type == 2)
        {
            std::cout << "\a" << std::endl;
            return 0;
        };
    case sf::Key::Y :
        if(Type == 0)
        {
            return 'y';
        }
        else if(Type == 1)
        {
            return 'Y';
        }
        else if(Type == 2)
        {
            std::cout << "\a" << std::endl;
            return 0;
        };
    case sf::Key::Z :
        if(Type == 0)
        {
            return 'z';
        }
        else if(Type == 1)
        {
            return 'Z';
        }
        else if(Type == 2)
        {
            std::cout << "\a" << std::endl;
            return 0;
        };

    case sf::Key::Back :
        return '\b';
    case sf::Key::BackSlash :
        return '\\';
    case sf::Key::Comma :
        return ',';
    case sf::Key::SemiColon :
        return ';';
    case sf::Key::Slash :
        return '/';
    case sf::Key::Space :
        return ' ';
    case sf::Key::Tab :
        return '\t';
    case sf::Key::Subtract :
        return '-';
    case sf::Key::Add :
        return '+';
    case sf::Key::Multiply :
        return '*';
    case sf::Key::Equal :
        return '=';
    case sf::Key::Period :
        return '.';
    case sf::Key::Quote :
        return '\'';
    case sf::Key::RBracket :
        return ']';
    case sf::Key::Tilde :
        return '~';
    case sf::Key::LBracket :
        return '[';

    case sf::Key::Num0 :
        if(Type == 0)
        {
            return '0';
        }
        else if(Type == 1)
        {
            return '=';
        }
        else if(Type == 2)
        {
            return '}';
        };
    case sf::Key::Num1 :
        if(Type == 0)
        {
            return '1';
        }
        else if(Type == 1)
        {
            return '!';
        }
        else if(Type == 2)
        {
            std::cout << "\a" << std::endl;
            return 0;
        };
    case sf::Key::Num2 :
        if(Type == 0)
        {
            return '2';
        }
        else if(Type == 1)
        {
            return '"';
        }
        else if(Type == 2)
        {
            return '�';
        };
    case sf::Key::Num3 :
        if(Type == 0)
        {
            return '3';
        }
        else if(Type == 1)
        {
            return '�';
        }
        else if(Type == 2)
        {
            return '�';
        };
    case sf::Key::Num4 :
        if(Type == 0)
        {
            return '4';
        }
        else if(Type == 1)
        {
            return '$';
        }
        else if(Type == 2)
        {
            std::cout << "\a" << std::endl;
            return 0;
        };
    case sf::Key::Num5 :
        if(Type == 0)
        {
            return '5';
        }
        else if(Type == 1)
        {
            return '%';
        }
        else if(Type == 2)
        {
            std::cout << "\a" << std::endl;
            return 0;
        };
    case sf::Key::Num6 :
        if(Type == 0)
        {
            return '6';
        }
        else if(Type == 1)
        {
            return '&';
        }
        else if(Type == 2)
        {
            std::cout << "\a" << std::endl;
            return 0;
        };
    case sf::Key::Num7 :
        if(Type == 0)
        {
            return '7';
        }
        else if(Type == 1)
        {
            return '/';
        }
        else if(Type == 2)
        {
            return '{';
        };
    case sf::Key::Num8 :
        if(Type == 0)
        {
            return '8';
        }
        else if(Type == 1)
        {
            return '(';
        }
        else if(Type == 2)
        {
            return '[';
        };
    case sf::Key::Num9 :
        if(Type == 0)
        {
            return '9';
        }
        else if(Type == 1)
        {
            return ')';
        }
        else if(Type == 2)
        {
            return ']';
        };

    case sf::Key::Numpad0 :
        if(Type == 0)
        {
            return '0';
        }
        else if(Type == 1)
        {
            return 0;
        }
        else if(Type == 2)
        {
            return 0;
        };
    case sf::Key::Numpad1 :
        if(Type == 0)
        {
            return '1';
        }
        else if(Type == 1)
        {
            return 0;
        }
        else if(Type == 2)
        {
            return 0;
        };
    case sf::Key::Numpad2 :
        if(Type == 0)
        {
            return '2';
        }
        else if(Type == 1)
        {
            return 0;
        }
        else if(Type == 2)
        {
            return 0;
        };
    case sf::Key::Numpad3 :
        if(Type == 0)
        {
            return '3';
        }
        else if(Type == 1)
        {
            return 0;
        }
        else if(Type == 2)
        {
            return 0;
        };
    case sf::Key::Numpad4 :
        if(Type == 0)
        {
            return '4';
        }
        else if(Type == 1)
        {
            return 0;
        }
        else if(Type == 2)
        {
            return 0;
        };
    case sf::Key::Numpad5 :
        if(Type == 0)
        {
            return '5';
        }
        else if(Type == 1)
        {
            return 0;
        }
        else if(Type == 2)
        {
            return 0;
        };
    case sf::Key::Numpad6 :
        if(Type == 0)
        {
            return '6';
        }
        else if(Type == 1)
        {
            return 0;
        }
        else if(Type == 2)
        {
            return 0;
        };
    case sf::Key::Numpad7 :
        if(Type == 0)
        {
            return '7';
        }
        else if(Type == 1)
        {
            return 0;
        }
        else if(Type == 2)
        {
            return 0;
        };
    case sf::Key::Numpad8 :
        if(Type == 0)
        {
            return '8';
        }
        else if(Type == 1)
        {
            return 0;
        }
        else if(Type == 2)
        {
            return 0;
        };
    case sf::Key::Numpad9 :
        if(Type == 0)
        {
            return '9';
        }
        else if(Type == 1)
        {
            return 0;
        }
        else if(Type == 2)
        {
            return 0;
        };

    default:
        return 0;

    }
}
