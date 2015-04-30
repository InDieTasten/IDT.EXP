//includes
#include <Utilities\VERSION.hpp>
#include <Utilities\Logger.hpp>
#include <SFML\Graphics.hpp>
#include <Input\EventManager.hpp>

extern sf::Mutex loggermtx;
extern void EXP::log(std::string);
extern void EXP::init();

//TESTZONE START
#include <Data\Mesh.hpp>
//TESTZONE END


extern "C" {
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
}


namespace EXP {
	EventManager* eventManager = nullptr;
}

void gameQuit(sf::Event::KeyEvent _event)
{
	if (_event.code == sf::Keyboard::Escape)
	{
		EXP::eventManager->terminate();
	}
}

int main(int argc, char *argv[])
{
	EXP::init();
	EXP::log("[Info]Game is launching in version: " + VERSION::version);
	sf::RenderWindow Window(sf::VideoMode(1280, 720, 32), VERSION::name + " " + VERSION::version, sf::Style::Titlebar | sf::Style::Resize | sf::Style::Close);
	sf::View view = Window.getDefaultView();
	view.setCenter(0.0f, 0.0f);
	Window.setView(view);

	EXP::eventManager = new EventManager(&Window);
	EXP::eventManager->addKeyRelease(&gameQuit);

	//TESTZONE START
	Mesh* test1 = new Mesh();

	test1->addVertex(sf::Vertex(sf::Vector2f(-20, 20)));
	test1->addVertex(sf::Vertex(sf::Vector2f(20, 20)));
	test1->addVertex(sf::Vertex(sf::Vector2f(20, -20)));
	test1->addVertex(sf::Vertex(sf::Vector2f(-10, -10)));
	test1->addVertex(sf::Vertex(sf::Vector2f(10, 10)));
	

	Window.clear();
	test1->draw(&Window, sf::Color(0, 255, 0, 255));
	Window.display();

	delete test1;
	test1 = nullptr;
	//TESTZONE END

	EXP::eventManager->listen();

	delete EXP::eventManager;
	EXP::eventManager = nullptr;

	Window.close();

	EXP::log("[Info]Game quit!");
	return EXIT_SUCCESS;
}
