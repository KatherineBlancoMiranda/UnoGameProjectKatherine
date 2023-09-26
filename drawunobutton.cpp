#include "drawunobutton.h"

void drawUnoButton(sf::Texture& unoButtonTexture, sf::Sprite& unoButtonSprite, sf::RenderWindow& window) {

    unoButtonSprite.setTexture(unoButtonTexture);

    unoButtonSprite.setPosition(600, 300);

    window.draw(unoButtonSprite);

}