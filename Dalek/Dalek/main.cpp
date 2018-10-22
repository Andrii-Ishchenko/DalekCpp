#include <SFML/Graphics.hpp>
using namespace sf;

Font font;

const int size = 14;
const int width = 40;
int hero_x, hero_y;
int daleks_count;
int daleks_count_newlevel = 4;

Vector2<int> origin;
int grid[size][size]; //0-blank, 1-hero, 2-dalek, >4-pile
int new_grid[size][size];

bool lose = false, finished = false;

//Move hero on old field
//check collision on old field
//move daleks position on new field
//check daleks collision
//copy hero
//check hero collision
//check endgame

void createHero() {
	hero_x = rand() % size;
	hero_y = rand() % size;
	grid[hero_x][hero_y] = 1;
}

void createDaleks() {
	int x, y;
	for (int i = 0; i < daleks_count_newlevel; i++) {
		do 
		{
			x = rand() % size;
			y = rand() % size;
		} 
		while (grid[x][y] != 0);

		grid[x][y] = 2;
	}

	daleks_count = daleks_count_newlevel;
}

void drawField(RenderWindow& app, Sprite cell) 
{
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cell.setPosition(origin.x + i*width, origin.y +j*width);
			app.draw(cell);
		}
	}
}

void drawFieldEntities(RenderWindow& app, Sprite hero, Sprite dalek, Sprite pile) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (grid[i][j] == 0) continue;
			if (grid[i][j] == 1) {
				hero.setPosition(origin.x + i * width, origin.y + j * width);
				app.draw(hero);
			} 
			else if (grid[i][j] == 2) {
				dalek.setPosition(origin.x + i * width, origin.y + j * width);
				app.draw(dalek);
			}
			else if (grid[i][j] > 2) {
				pile.setPosition(origin.x + i * width, origin.y + j * width);
				app.draw(pile);
			}
		}
	}
}

void checkHeroCollision() {
	if (grid[hero_x][hero_y] > 1) {
		lose = true;
		finished = true;
	}
}

void move(int dx, int dy) {
	int old_x = hero_x;
	int old_y = hero_y;

	if (dx > 0 && hero_x < size-1) {
		hero_x++;
	} 
	else if (dx < 0 && hero_x > 0) {
		hero_x--;
	} 
	else if (dy > 0 && hero_y < size - 1) {
		hero_y++;
	}
	else if (dy < 0 && hero_y > 0) {
		hero_y--;
	}

	//reinit new grid
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			new_grid[i][j] = 0;

	//copy hero to new grid
	new_grid[hero_x][hero_y] = 1;


	//move_daleks
	int ddx, ddy;//daleks delta

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++) 
		{
			if (grid[i][j] == 2) {
				ddx = 0;
				ddy = 0;

				if (i > hero_x) { ddx = -1; }
				else if (i < hero_x) { ddx = 1; }

				if (j > hero_y) { ddy = -1; }
				else if (j < hero_y) { ddy = 1; }

				new_grid[i + ddx][j + ddy] += 2;
			}
			else if (grid[i][j] > 2) {
				new_grid[i][j] = grid[i][j];
			}
		}
	}
	//copy
	daleks_count = 0;//recalculate count
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++) {
			grid[i][j] = new_grid[i][j];
			if (grid[i][j] == 2)
				daleks_count++;
		}
			
	//check collision
	checkHeroCollision();
}

void drawScores(RenderWindow&  app) {

	int margin_after_field = 20;
	int margin_after_header = 5;
	Vector2f origin_after(
		origin.x + size * width + margin_after_field,
		origin.y
	);

	FloatRect bounds;

	Text t_daleks_count;
	t_daleks_count.setFont(font);
	t_daleks_count.setFillColor(Color::Black);
	t_daleks_count.setCharacterSize(14);
	t_daleks_count.setString("Daleks count: "+std::to_string(daleks_count));
	t_daleks_count.setPosition(origin_after);
	app.draw(t_daleks_count);

}

int main()
{
	RenderWindow window(VideoMode(800, 600), "DALEK");
	window.setFramerateLimit(60);
	
	srand(time(0));

	if (!font.loadFromFile("C:\\Windows\\Fonts\\arial.ttf")) {
		//todo: handle
	}

	Image temp;
	Texture dalek_tex, hero_tex, cell_tex, pile_tex;

	temp.loadFromFile("assets\\dalek.png");
	temp.createMaskFromColor(Color::White);
	dalek_tex.loadFromImage(temp);
	dalek_tex.setSmooth(true);

	temp.loadFromFile("assets\\hero.png");
	temp.createMaskFromColor(Color::White);
	hero_tex.loadFromImage(temp);
	hero_tex.setSmooth(true);

	temp.loadFromFile("assets\\cell.png");
	temp.createMaskFromColor(Color::White);
	cell_tex.loadFromImage(temp);
	cell_tex.setSmooth(true);

	temp.loadFromFile("assets\\pile.png");
	temp.createMaskFromColor(Color::White);
	pile_tex.loadFromImage(temp);
	pile_tex.setSmooth(true);

	Sprite dalek_sprite(dalek_tex);
	Sprite hero_sprite(hero_tex);
	Sprite pile_sprite(pile_tex);
	Sprite cell_sprite(cell_tex);

	dalek_sprite.setTextureRect(IntRect(0, 0, width, width));
	hero_sprite.setTextureRect(IntRect(0, 0, width, width));
	pile_sprite.setTextureRect(IntRect(0, 0, width, width));
	cell_sprite.setTextureRect(IntRect(0, 0, width, width));

	origin = Vector2i(20, 20);

	createHero();
	createDaleks();


	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();			

			if (event.type == Event::KeyPressed)
			{
				if (event.key.code == Keyboard::Up) {
					move(0, -1);				
				} 
				else if (event.key.code == Keyboard::Down) {
					move(0, +1);					
				}
				else if (event.key.code == Keyboard::Left) {
					move(-1, 0);
				}
				else if (event.key.code == Keyboard::Right) {
					move(1, 0);
				}
			}

		}
		window.clear(Color::White);
		
		drawField(window, cell_sprite);
		drawFieldEntities(window, hero_sprite, dalek_sprite, pile_sprite);
		drawScores(window);
		window.display();
	}
	
	return 0;
}