#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#define ALTURA_PANTALLA 720
#define ANCHURA_PANTALLA 1280
// Posicion de las cartas en la interfaz
#define CARTA_UNO_JUGADOR_X 440
#define CARTA_UNO_JUGADOR_Y 470
#define CARTA_DOS_JUGADOR_X 690
#define CARTA_DOS_JUGADOR_Y 470
#define CARTA_UNO_MESA_X 160
#define CARTA_UNO_MESA_Y 80
#define CARTA_DOS_MESA_X 360
#define CARTA_DOS_MESA_Y 80
#define CARTA_TRES_MESA_X 560
#define CARTA_TRES_MESA_Y 80
#define CARTA_CUATRO_MESA_X 760
#define CARTA_CUATRO_MESA_Y 80
#define CARTA_CINCO_MESA_X 960
#define CARTA_CINCO_MESA_Y 80
#define FICHAS_X 80
#define FICHAS_Y 350


int main(){

    sf::RenderWindow window(sf::VideoMode(ANCHURA_PANTALLA, ALTURA_PANTALLA), "Texas Hold'em"); // La resolucion puede cambiar, pero se necesitaria cambiar tambien las imagenes.
    // Texturas
    sf::Texture fondo; // Se guarda la imagen de fondo
    sf::Texture cartaUnoJugador;
    sf::Texture cartaDosJugador;
    sf::Texture cartaUnoMesa;
    sf::Texture cartaDosMesa;
    sf::Texture cartaTresMesa;
    sf::Texture cartaCuatroMesa;
    sf::Texture cartaCincoMesa;
    sf::Texture modeloFichas;
    // Sprites

    sf::Sprite background; // Se crea el sprite de fondo
    sf::Sprite sCartaUnoJugador; // s al unicio por sprite
    sf::Sprite sCartaDosJugador;
    sf::Sprite sCartaUnoMesa;
    sf::Sprite sCartaDosMesa;
    sf::Sprite sCartaTresMesa;
    sf::Sprite sCartaCuatroMesa;
    sf::Sprite sCartaCincoMesa;
    sf::Sprite spriteFichas;

    while(window.isOpen()){
    	sf::Event event;
    	while(window.pollEvent(event)){ // Verifica los eventos de la ventana
    		if(event.type == sf::Event::Closed){
    			window.close();
    		}
    	}
    	if(!fondo.loadFromFile("VentanaJuego.png")){
    		window.clear(sf::Color::Black);
    	}
    	else{
    		// Inicializacion de cartas
    		// Cartas Mano
    		cartaUnoJugador.loadFromFile("Joker.png");
    		cartaDosJugador.loadFromFile("Joker.png");
            // Cartas Mesa
            cartaUnoMesa.loadFromFile("Joker.png");
            cartaDosMesa.loadFromFile("Joker.png");
            cartaTresMesa.loadFromFile("Joker.png");
            cartaCuatroMesa.loadFromFile("Joker.png");
            cartaCincoMesa.loadFromFile("Joker.png");

            // Fichas
            modeloFichas.loadFromFile("modeloFichas.png");

			// Texturas carta Mano
    		sCartaUnoJugador.setTexture(cartaUnoJugador);
    		sCartaDosJugador.setTexture(cartaDosJugador);

    		// Texturas Carta Mesa
    		sCartaUnoMesa.setTexture(cartaUnoMesa);
    		sCartaDosMesa.setTexture(cartaDosMesa);
    		sCartaTresMesa.setTexture(cartaTresMesa);
    		sCartaCuatroMesa.setTexture(cartaCuatroMesa);
    		sCartaCincoMesa.setTexture(cartaCincoMesa);

    		// Texturas Ficha
    		spriteFichas.setTexture(modeloFichas);

    		// Posiciones Cartas Mano
    		sCartaUnoJugador.setPosition(CARTA_UNO_JUGADOR_X,CARTA_UNO_JUGADOR_Y);
    		sCartaDosJugador.setPosition(CARTA_DOS_JUGADOR_X,CARTA_DOS_JUGADOR_Y);

    		// Posiciones Carta Mesa

    		sCartaUnoMesa.setPosition(CARTA_UNO_MESA_X,CARTA_UNO_MESA_Y);
    		sCartaDosMesa.setPosition(CARTA_DOS_MESA_X,CARTA_DOS_MESA_Y);
    		sCartaTresMesa.setPosition(CARTA_TRES_MESA_X,CARTA_TRES_MESA_Y);
    		sCartaCuatroMesa.setPosition(CARTA_CUATRO_MESA_X,CARTA_CUATRO_MESA_Y);
    		sCartaCincoMesa.setPosition(CARTA_CINCO_MESA_X,CARTA_CINCO_MESA_Y);

    		// Posicion fichas

    		spriteFichas.setPosition(FICHAS_X,FICHAS_Y);

    		background.setTexture(fondo); // Se pone la textura de fondo
    		window.draw(background); 	// Se agrega a la ventana
    		// Se agregan las cartas de jugador
    		window.draw(sCartaUnoJugador);
    		window.draw(sCartaDosJugador);
    		// Se agregan las cartas de la mesa
    		window.draw(sCartaUnoMesa);
    		window.draw(sCartaDosMesa);
    		window.draw(sCartaTresMesa);
    		window.draw(sCartaCuatroMesa);
    		window.draw(sCartaCincoMesa);
    		window.draw(spriteFichas);

    	}

    	window.display(); // Se muestra la ventana


    }

    return 0;
}
