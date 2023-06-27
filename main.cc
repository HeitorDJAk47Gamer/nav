#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>
#include <WebView.h>

int main()
{
    // Cria a janela
    sf::RenderWindow window(sf::VideoMode(800, 600), "Navegador Simples");

    // Cria um objeto WebView
    tgui::WebView webView;
    webView.loadURL("http://www.exemplo.com");

    // Loop principal
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            else if (event.type == sf::Event::Resized)
                webView.setView(sf::FloatRect(0, 0, event.size.width, event.size.height));
            else if (event.type == sf::Event::MouseButtonPressed)
                webView.mouseButtonPressed(event.mouseButton);
            else if (event.type == sf::Event::MouseButtonReleased)
                webView.mouseButtonReleased(event.mouseButton);
            else if (event.type == sf::Event::MouseMoved)
                webView.mouseMoved(event.mouseMove);
            else if (event.type == sf::Event::MouseWheelScrolled)
                webView.mouseWheelScrolled(event.mouseWheelScroll);
            else if (event.type == sf::Event::KeyPressed)
                webView.keyPressed(event.key);
            else if (event.type == sf::Event::KeyReleased)
                webView.keyReleased(event.key);
            else if (event.type == sf::Event::TextEntered)
                webView.textEntered(event.text);
        }

        // Atualiza a visualização da WebView
        webView.update();

        // Limpa a janela
        window.clear();

        // Desenha a WebView na janela
        window.draw(webView);

        // Exibe a janela
        window.display();
    }

    return 0;
}
