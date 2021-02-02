#include "Player.h"

Player::Player(float radius, int initialRow, int initialColumn, string fileName)
{
	circle.setRadius(radius);
	circle.setPosition(50 + 80 * initialColumn, 50 + 80 * initialRow);
	texture.loadFromFile(fileName);
	circle.setTexture(&texture);
	row = initialRow;
	column = initialColumn;
}
void Player::moveOnWindow(Event e, int arr[][COLUMNS])
{
	switch (e.key.code)
	{
	case Keyboard::Up:
		if (arr[row - 1][column] >= 0)
		{
			circle.move(0, -80);
			row--;
		}
		break;
	case Keyboard::Down:
		if (arr[row + 1][column] >= 0)
		{
			circle.move(0, 80);
			row++;
		}
		break;
	case Keyboard::Right:
		if (arr[row][column + 1] >= 0)
		{
			circle.move(80, 0);
			column++;
		}
		break;
	case Keyboard::Left:
		if (arr[row][column - 1] >= 0)
		{
			circle.move(-80, 0);
			column--;
		}
		break;
	}
}
void Player::drawOnWindow(RenderWindow& window)
{
	window.draw(circle);
}
CircleShape Player::getPlayer()
{
	return circle;
	cout << "hana eissa";
}
