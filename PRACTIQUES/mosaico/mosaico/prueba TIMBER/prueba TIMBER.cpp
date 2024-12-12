#include <SFML/Graphics.hpp>


using namespace sf;  

int main() {
    // Crea una finestra
    RenderWindow window(VideoMode(800, 600), "MOSAIC");

    // Definir algunes variables geomètriques: formes rectangulars
    RectangleShape rect1(Vector2f(300, 400)); // Rectangle vertical gran
    rect1.setPosition(50, 50); //fem posició
    rect1.setFillColor(Color::Red); //color
    

    RectangleShape rect2(Vector2f(200, 200)); // Quadrat
    rect2.setPosition(550, 50); // Posició de les formes
    rect2.setFillColor(Color::Blue); // Establir colors 

    RectangleShape rect3(Vector2f(250, 150)); // Rectangle horitzontal més petit
    rect3.setPosition(100, 500); // Posició de les formes
    rect3.setFillColor(Color::Yellow); // Establir colors 
    // Posició de les formes

    // Crear una línia negra 
    RectangleShape lineaNegra(Vector2f(20, 600)); // Línia vertical negra 
    lineaNegra.setPosition(350, 0); // Posició al centre de la composició
    lineaNegra.setFillColor(Color::Black);
    
    // Crear una línia negra 
    RectangleShape lineaNegra3(Vector2f(20, 250)); // Línia vertical negra 
    lineaNegra3.setPosition(450, 0); // Posició al centre de la composició
    lineaNegra3.setFillColor(Color::Black);

    // Crear una línia negra 
    RectangleShape lineaNegra2(Vector2f(600, 20)); // Línia horitzontal negra 
    lineaNegra2.setPosition(370, 250); // Posició al centre de la composició
    lineaNegra2.setFillColor(Color::Black);

    // Crear una línia negra 
    RectangleShape lineaNegra5(Vector2f(450, 20)); // Línia horitzontal negra 
    lineaNegra5.setPosition(0, 150); // Posició al centre de la composició
    lineaNegra5.setFillColor(Color::Black);

    // Crear una línia negra 
    RectangleShape lineaNegra4(Vector2f(1000, 20)); // Línia horitzontal negra 
    lineaNegra4.setPosition(0, 470); // Posició al centre de la composició
    lineaNegra4.setFillColor(Color::Black);
    

    //Crear rombe
    ConvexShape rombo;
    rombo.setPointCount(4);
    rombo.setPoint(0, sf::Vector2f(150, 100)); // Vèrtex superior
    rombo.setPoint(1, sf::Vector2f(200, 200)); // Vèrtex dreta
    rombo.setPoint(2, sf::Vector2f(150, 300)); // Vèrtex inferior
    rombo.setPoint(3, sf::Vector2f(100, 200)); // Vèrtex esquerre
    rombo.setPosition(700, 250); // Posició al centre de la composició
    rombo.setFillColor(Color::Blue);
    rombo.rotate(90);

    //Crear cercle 
    CircleShape cercle(100); // crear cercle radi 100
    cercle.setRadius(40); // baixar radi a 40
    cercle.setPointCount(360); // 
    cercle.setFillColor(Color::Red);
    cercle.setPosition(700, 505); // Posició al centre de la composició

    //Rectangle blanc
    ConvexShape rect4;
    rect4.setPointCount(4);
    rect4.setPoint(0, sf::Vector2f(150, 120)); // Vèrtex superior
    rect4.setPoint(1, sf::Vector2f(295, 225)); // Vèrtex dreta
    rect4.setPoint(2, sf::Vector2f(150, 370)); // Vèrtex inferior
    rect4.setPoint(3, sf::Vector2f(5, 225)); // Vèrtex esquerre
    rect4.setPosition(50, 75); // Posició de les formes
    rect4.setFillColor(Color::Red); // Establir colors 
    rect4.setOutlineThickness(30); // Ficar borde 30 de gruix
    rect4.setOutlineColor(Color::White); // borde color blanc

 



    // Mentre la finestra estigui oberta, el bucle principal del programa continua
    while (window.isOpen()) {
        // Comprovar tots els esdeveniments que han passat des de l'últim fotograma
        Event event;
        while (window.pollEvent(event)) {
            // Si es tanca la finestra, sortir del bucle
            if (event.type == Event::Closed)
                window.close();
        }

        // Esborra la finestra amb un color de fons blanc
        window.clear(Color::White);

        // Dibuixar les formes geomètriques
        window.draw(rect1);
        window.draw(rect2);
        window.draw(rect3);
        window.draw(rect4);
        window.draw(lineaNegra);
        window.draw(lineaNegra2);
        window.draw(lineaNegra3);
        window.draw(lineaNegra4);
        window.draw(lineaNegra5);
        window.draw(rombo);
        window.draw(cercle);

        // Mostra el contingut a la finestra
        window.display();
    }

    return 0;
}

