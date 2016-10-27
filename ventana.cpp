#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#define ALTURA_PANTALLA 720
#define ANCHURA_PANTALLA 1280
#define POSICION_X_TITULO 450
#define POSICION_Y_TITULO 50
#define POSICION_X_BOTON_JUGAR 565
#define POSICION_Y_BOTON_JUGAR 550
#define POSICION_X_LABEL 300 // Coordenadas para el label de nickname
#define POSICION_Y_LABEL 500
#define POSICION_X_NICKNAME 550 // Coordenadas para donde se introduce el nickname
#define POSICION_Y_NICKNAME 510
#define POSICION_X_IP 550   // Coordenadas para donde se pone la IP
#define POSICION_Y_IP 610
#define POSICION_X_CUADRO_TEXTO 490 // Coordenadas para el cuadro de texto
#define POSICION_Y_CUADRO_TEXTO 510
#define POSICION_X_CUADRO_TEXTO_IP 490  // Coordendas para el cuadro de texto de la ip
#define POSICION_Y_CUADRO_TEXTO_IP 610
#define POSICION_X_LABEL_IP 300 // Coordenadas para el label de ip
#define POSICION_Y_LABEL_IP 600

using namespace std;
int main()
{

    string nickname;
    string direccionHost;
    bool banderaNombre_o_Host=false;
    //sf::Window window(sf::VideoMode(800, 600), "My window");
   // sf::RenderWindow windows(sf::VodeoMode(800,600),"Mi windows ");
    sf::RenderWindow window(sf::VideoMode(ANCHURA_PANTALLA, ALTURA_PANTALLA), "Texas Hold'em"); // La resolucion puede cambiar, pero se necesitaria cambiar tambien las imagenes.
    // Todas las texturas que utilizara el juego y los sprites
    sf::Texture fondo;  // Imagen de fondo
    sf::Texture titulo; // Imagen con las letras
    sf::Texture botonJugar;  // Imagen con el boton jugar
    sf::Texture cuadroTexto; // Imagen para el cuadro de texto
    sf::Sprite spriteTitulo;
    sf::Sprite background;
    sf::Sprite spriteBotonJugar;
    sf::Sprite spriteCuadroTexto;
    sf::Sprite spriteCuadroTextoIp;
    // run the program as long as the window is open

    // Etiqueta de Texto nombre jugador
    sf::Font font;
    font.loadFromFile("Chancery.ttf");

    sf::Text labelNick("Nickname",font,50);
    sf::Text labelIp("Ip Host",font,50);
    labelNick.setPosition(POSICION_X_LABEL,POSICION_Y_LABEL);
    labelIp.setPosition(POSICION_X_LABEL_IP,POSICION_Y_LABEL_IP);

    // String donde se mostrara el nickname

    sf::Text entradaNick("",font,50);
    sf::Text entradaHost("",font,50);
    entradaNick.setPosition(POSICION_X_NICKNAME,POSICION_Y_NICKNAME);
    entradaHost.setPosition(POSICION_X_IP,POSICION_Y_IP);

    titulo.loadFromFile("titulo.png");
    botonJugar.loadFromFile("botonJugar.png");
    cuadroTexto.loadFromFile("cuadroTexto.png");

    // Sonido
    sf::Music backgroudMusic;
    bool playingMusic;
    if(!backgroudMusic.openFromFile("bluesForGwen.wav"))
            return 1;

    backgroudMusic.play();
    playingMusic = true;
    // Termina audio

    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop

        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
            else if(event.type == sf::Event::KeyPressed){ // Evento para darle enter e iniciar el juego
                if(event.key.code == sf::Keyboard::Return){
                    cout << nickname <<endl;;
                }
                else if(event.key.code == sf::Keyboard::Tab){
                    if(playingMusic){
                        backgroudMusic.pause();
                        playingMusic = false;
                    }
                    else{
                        backgroudMusic.play();
                        playingMusic = true;
                    }
                }
                else if (event.key.code== sf::Keyboard::LControl){
                        if(banderaNombre_o_Host)
                            banderaNombre_o_Host = false;
                        else
                            banderaNombre_o_Host = true;
                }
                else if(event.key.code == sf::Keyboard::BackSpace){ // Metodo para eliminar cuando se le de backspace

                }
            }
            else if(event.type == sf::Event::TextEntered){ // Este evento es para que el jugador ponga su nickName
                // Handle ASCII characters only

                if(event.text.unicode == '\b'){
                      if(!banderaNombre_o_Host){
                        nickname = nickname.substr(0, nickname.size()-1);
                        entradaNick.setString(nickname);
                    }
                    else{
                        direccionHost =  direccionHost.substr(0, direccionHost.size()-1);
                        entradaHost.setString(direccionHost);
                    }
                }

                else if (event.text.unicode < 128){ // Se ponen simbolos de que no reconoce si se escribe otra letra, corregir.

                    if(!banderaNombre_o_Host){
                        nickname += static_cast<char>(event.text.unicode);
                        entradaNick.setString(nickname);
                    }
                    else{
                        direccionHost += static_cast<char>(event.text.unicode);
                        entradaHost.setString(direccionHost);
                    }
                }
            }
        }
        if(!fondo.loadFromFile("pokerTable3.png")){
            window.clear(sf::Color::Black);
        }
        else{
            background.setTexture(fondo);

            spriteTitulo.setTexture(titulo);
            spriteTitulo.setPosition(POSICION_X_TITULO,POSICION_Y_TITULO);

            spriteBotonJugar.setTexture(botonJugar);
            spriteBotonJugar.setPosition(POSICION_X_BOTON_JUGAR,POSICION_Y_BOTON_JUGAR);

            spriteCuadroTexto.setTexture(cuadroTexto);
            spriteCuadroTexto.setPosition(POSICION_X_CUADRO_TEXTO,POSICION_Y_CUADRO_TEXTO);

            spriteCuadroTextoIp.setTexture(cuadroTexto);
            spriteCuadroTextoIp.setPosition(POSICION_X_CUADRO_TEXTO_IP,POSICION_Y_CUADRO_TEXTO_IP);

            window.draw(background); // TIenes que poner el background antes que todo.
            window.draw(spriteTitulo);
            //window.draw(spriteBotonJugar);
            window.draw(labelNick); // Etiqueta nickname
            window.draw(labelIp);
            window.draw(spriteCuadroTexto);
            window.draw(spriteCuadroTextoIp);
            window.draw(entradaNick);   // Aqui poco a poco se va a insertar el nombre;
            window.draw(entradaHost);
             // Aqui se dibuja el cuadro de texto


        }

        window.display();
    }

    return 0;
}
