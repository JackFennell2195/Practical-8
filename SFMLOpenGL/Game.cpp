#include <Game.h>

bool flip = false;
int current = 1;

Game::Game() : window(VideoMode(800, 600), "OpenGL Cube")
{

}

Game::~Game() {}

Vector corners[] = {Vector(-1.0f, 1.0f, -5.0f),Vector(-1.0f, -1.0f, -5.0f),Vector(1.0f, -1.0f, -5.0f),
					Vector(1.0f, 1.0f, -5.0f),Vector(1.0f,1.0f,-15.0f),Vector(1.0f,-1.0f,-15.0f),
					Vector(-1.0f,1.0f,-15.0f),Vector(-1.0f,-1.0f,-15.0f)};
float vertices[] = {
					//Front Face 
					(corners[0].getX()), (corners[0].getY()), (corners[0].getZ()),
					(corners[1].getX()), (corners[1].getY()), (corners[1].getZ()),
					(corners[2].getX()), (corners[2].getY()), (corners[2].getZ()),
					 //Front Face 
					(corners[3].getX()), (corners[3].getY()), (corners[3].getZ()),
					(corners[0].getX()), (corners[0].getY()), (corners[0].getZ()),
					(corners[2].getX()), (corners[2].getY()), (corners[2].getZ()),
					//Right side
					(corners[3].getX()), (corners[3].getY()), (corners[3].getZ()),
					(corners[4].getX()), (corners[4].getY()), (corners[4].getZ()),
					(corners[5].getX()), (corners[5].getY()), (corners[5].getZ()),
					//Right side
					(corners[3].getX()), (corners[3].getY()), (corners[3].getZ()),
					(corners[2].getX()), (corners[2].getY()), (corners[2].getZ()),
					(corners[5].getX()), (corners[5].getY()), (corners[5].getZ()),
					//Left side
					(corners[6].getX()), (corners[6].getY()), (corners[6].getZ()),
					(corners[0].getX()), (corners[0].getY()), (corners[0].getZ()),
					(corners[1].getX()), (corners[1].getY()), (corners[1].getZ()),
					//Left side
					(corners[6].getX()), (corners[6].getY()), (corners[6].getZ()),
					(corners[7].getX()), (corners[7].getY()), (corners[7].getZ()),
					(corners[1].getX()), (corners[1].getY()), (corners[1].getZ()),
					//Top face
					(corners[6].getX()), (corners[6].getY()), (corners[6].getZ()),
					(corners[4].getX()), (corners[4].getY()), (corners[4].getZ()),
					(corners[3].getX()), (corners[3].getY()), (corners[3].getZ()),
					//Top face
					(corners[6].getX()), (corners[6].getY()), (corners[6].getZ()),
					(corners[0].getX()), (corners[0].getY()), (corners[0].getZ()),
					(corners[3].getX()), (corners[3].getY()), (corners[3].getZ()),
					//Bottom face
					(corners[1].getX()), (corners[1].getY()), (corners[1].getZ()),
					(corners[2].getX()), (corners[2].getY()), (corners[2].getZ()),
					(corners[5].getX()), (corners[5].getY()), (corners[5].getZ()),
					//Bottom face
					(corners[1].getX()), (corners[1].getY()), (corners[1].getZ()),
					(corners[7].getX()), (corners[7].getY()), (corners[7].getZ()),
					(corners[5].getX()), (corners[5].getY()), (corners[5].getZ()),
					//Back Face
					(corners[6].getX()), (corners[6].getY()), (corners[6].getZ()),
					(corners[4].getX()), (corners[4].getY()), (corners[4].getZ()),
					(corners[5].getX()), (corners[5].getY()), (corners[5].getZ()),
					//Back Face
					(corners[6].getX()), (corners[6].getY()), (corners[6].getZ()),
					(corners[7].getX()), (corners[7].getY()), (corners[7].getZ()),
					(corners[5].getX()), (corners[5].getY()), (corners[5].getZ())
					};

float colors[] = { 
					//Front Face 
					1.0f, 0.0f, 0.0f,
					0.0f, 1.0f, 0.0f,
					0.0f, 0.0f, 1.0f,
					//Front Face 
					1.0f, 0.0f, 0.0f,
					0.0f, 1.0f, 0.0f,
					0.0f, 0.0f, 1.0f,

					0.5f, 0.0f, 0.0f,
					0.0f, 0.5f, 0.0f,
					0.0f, 0.0f, 0.5f,
	 
					0.5f, 0.0f, 0.0f,
					0.0f, 0.5f, 0.0f,
					0.0f, 0.0f, 0.5f,

					0.3f, 0.0f, 0.0f,
					0.0f, 0.3f, 0.0f,
					0.0f, 0.0f, 0.3f,

					0.3f, 0.0f, 0.0f,
					0.0f, 0.3f, 0.0f,
					0.0f, 0.0f, 0.3f,
					
					0.8f, 0.0f, 0.0f,
					0.0f, 0.8f, 0.0f,
					0.0f, 0.0f, 0.8f,

					0.8f, 0.0f, 0.0f,
					0.0f, 0.8f, 0.0f,
					0.0f, 0.0f, 0.8f,

					0.6f, 0.0f, 0.0f,
					0.0f, 0.6f, 0.0f,
					0.0f, 0.0f, 0.6f,

					0.6f, 0.0f, 0.0f,
					0.0f, 0.6f, 0.0f,
					0.0f, 0.0f, 0.6f,

					0.4f, 0.0f, 0.0f,
					0.0f, 0.4f, 0.0f,
					0.0f, 0.0f, 0.4f,


					0.4f, 0.0f, 0.0f,
					0.0f, 0.4f, 0.0f,
					0.0f, 0.0f, 0.4f,

				 };
unsigned int vertex_index[] = { 0, 1, 2,  //Front Face 
								3, 4, 5,  //Front Face 

								6, 7, 8,  //Right side
								9, 10, 11, //Right side

								12,13,14, //Left side
								15,16,17, //Left side

								18,19,20, //Top face
								21,22,23, //Top face

								24,25,26,//Bottom face
								27,28,29,//Bottom face

								30,31,32, //Back face
								33,34,35 //Back face
};

void Game::run()
{

	initialize();

	Event event;

	while (isRunning) {

		cout << "Game running..." << endl;

		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				isRunning = false;
			}
		}
		update();
		render();
	}

}

void Game::initialize()
{
	isRunning = true;

	//glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, window.getSize().x / window.getSize().y, 1.0, 500.0);
	glMatrixMode(GL_MODELVIEW);
}

void Game::update()
{
	Matrix3 matrix;
	initialize();
	if (Keyboard::isKeyPressed(Keyboard::R))
	{
		
		
	}

	if (Keyboard::isKeyPressed(Keyboard::E))
	{
		
	}

	if (Keyboard::isKeyPressed(Keyboard::S))
	{
		
	}
	if (Keyboard::isKeyPressed(Keyboard::D))
	{
		
	}

	if (Keyboard::isKeyPressed(Keyboard::T))
	{
		
	}
	if (Keyboard::isKeyPressed(Keyboard::Y))
	{
		
	}

	elapsed = clock.getElapsedTime();

	cout << "Update up" << endl;
}

void Game::render()
{
	cout << "Drawing" << endl;

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);


	glVertexPointer(3, GL_FLOAT, 0, &vertices);
	glColorPointer(3, GL_FLOAT, 0, &colors);

	//glDrawArrays(GL_TRIANGLES, 0, 3);

	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, &vertex_index); 

	glDisableClientState(GL_COLOR_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);

	window.display();

}

void Game::unload()
{
	cout << "Cleaning up" << endl;
}

