// Include important C++ libraries here
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <sstream>
#include <vector>


// Make code easier to type with "using namespace"
using namespace sf;
using namespace std;

// Function declaration

// Const declaration
const int Xmax = 1920; // Ample de la finestra
const int Ymax = 1080; // Altura de la finestra
const int NumMaxClouds = 3; // Nombre màxim de núvols visibles alhora
const int NumMaxBees = 10; // Nombre màxim de núvols visibles alhora
const int NUM_BRANCHES = 6; // Nombre màxim de branques visibles alhora

// Create a structure variable called Mycloud
struct Structure {
	Sprite dibuix; // Sprite del núvol
	bool  Active; // Indica si el núvol està actiu
	float Speed; // Velocitat del núvol
};

// Where is the player/branch? 
// Left or Right
// Enumeració per indicar el costat de les branques i del jugador
enum class side { LEFT, RIGHT, NONE };

// Funció per actualitzar les branques
void updateBranches(int seed, side branca[]);

// Line the axe up with the tree – Cal posar-ho fora de la funció main
const float AXE_POSITION_LEFT = 700;
const float AXE_POSITION_RIGHT = 1200;

int main()
{
	
	int score = 0; // Puntuació inicial
	static int lastScore = 0;  // Es manté entre les iteracions del bucle principal
	Sprite branches[NUM_BRANCHES]; // sprite branques
	side branchPositions[NUM_BRANCHES]; // Posicions de les branques
	// Create a video mode object

	VideoMode vm(Xmax, Ymax); // Configuració de mida de la finestra

	// Create and open a window for the game
	RenderWindow window(vm, "Timber!!!");

	// Create a texture to hold a graphic on the GPU
	Texture textureBackground;

	// Estableix un límit de fotogrames per segon 
	// (FPS) a 60 per evitar que el joc s'executi massa ràpidament
	window.setFramerateLimit(60); 

	// Load a graphic into the texture
	textureBackground.loadFromFile("graphics/background.png");

	// Create a sprite
	Sprite spriteBackground;

	// Attach the texture to the sprite
	spriteBackground.setTexture(textureBackground);

	// Set the spriteBackground to cover the screen
	spriteBackground.setPosition(0, 0); // Fons en la posició inicial

	// Make a tree sprite
	Texture textureTree;
	textureTree.loadFromFile("graphics/tree.png");
	Sprite spriteTree, spriteTree2, spriteTree3, spriteTree4;
	spriteTree.setTexture(textureTree);
	spriteTree.setPosition(810, 0); // Centrar l'arbre

	// Crear arbres adicionals
	spriteTree2.setTexture(textureTree);
	spriteTree2.setPosition(150, -50);  // Primer arbre
	spriteTree2.setScale(0.9f, 1.2f);

	spriteTree3.setTexture(textureTree);
	spriteTree3.setPosition(1400, -80);  // Segundo arbre
	spriteTree3.setScale(0.75f, 1.0f);

	spriteTree4.setTexture(textureTree);
	spriteTree4.setPosition(1700, 0);  // Tercer arbre
	spriteTree4.setScale(1.25f, 1.25f);

	// Prepare the bee
	Texture textureBee;
	textureBee.loadFromFile("graphics/bee.png");
	//Sprite spriteBee;
	//spriteBee.setTexture(textureBee);
	//spriteBee.setPosition(0, 800); // Posició inicial fora de pantalla
	
	Structure eixam[NumMaxBees];
	for (int i = 0; i < NumMaxBees; i++)
	{
		eixam[i].dibuix.setTexture(textureBee);
		eixam[i].dibuix.setPosition(0, i * 250);
		eixam[i].Active = false; // Inicialment, no actius
		eixam[i].Speed = 0.0f; // Velocitat inicial 0

	}

	// Is the bee currently moving?
	bool beeActive = false; // Estat inicial: abella no activa

	// How fast can the bee fly
	float beeSpeed = 0.0f; // Velocitat inicial

	// make 3 cloud sprites from 1 texture
	Texture textureCloud;

	// Load 1 new texture
	textureCloud.loadFromFile("graphics/cloud.png");

	// 3 New sprites withe the same texture
	Structure spriteCloud[NumMaxClouds];
	for (int i = 0; i < NumMaxClouds; i++)
	{
		spriteCloud[i].dibuix.setTexture(textureCloud);
		spriteCloud[i].dibuix.setPosition(0, i * 250);
		spriteCloud[i].Active = false; // Inicialment, no actius
		spriteCloud[i].Speed = 0.0f; // Velocitat inicial 0

	}

	// Variables to control time itself
	Clock clock;
	// Time bar
	RectangleShape timeBar;
	float timeBarStartWidth = 400; // Amplada inicial de la barra
	float timeBarHeight = 80;
	timeBar.setSize(Vector2f(timeBarStartWidth, timeBarHeight));
	timeBar.setFillColor(Color::Red);
	timeBar.setPosition((1920 / 2) - timeBarStartWidth / 2, 980);
	Time gameTimeTotal;
	float timeRemaining = 10.0f; // Temps inicial
	float timeBarWidthPerSecond = timeBarStartWidth / timeRemaining; // Amplada per segon
	// Track whether the game is running
	bool paused = true; // El joc comença pausat

	// Draw some text
	Text messageText;
	Text scoreText;

	// We need to choose a font
	Font font;
	font.loadFromFile("fonts/KOMIKAP_.ttf");

	// Set the font to our message
	messageText.setFont(font);
	scoreText.setFont(font);

	// Assign the actual message
	messageText.setString("Press Enter to start!");
	scoreText.setString("Score = 0");

	// Make it really big
	messageText.setCharacterSize(75); // Mida del text
	scoreText.setCharacterSize(100); // Mida del marcador
	// Choose a color
	messageText.setFillColor(Color::White); // Color blanc
	scoreText.setFillColor(Color::White); // Color blanc
	// Position the text
	FloatRect textRect = messageText.getLocalBounds();
	messageText.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f); // Centrar el text
	messageText.setPosition(Xmax / 2.0f, Ymax / 2.0f);  // Posar al centre de la pantalla
	scoreText.setPosition(20, 20); // A la cantonada superior esquerra
	// Prepare 6 branches
	Texture textureBranch;
	textureBranch.loadFromFile("graphics/branch.png");
	// Set the texture for each branch sprite
	for (int i = 0; i < NUM_BRANCHES; i++) {
		branches[i].setTexture(textureBranch);
		branches[i].setPosition(-2000, -2000); // Fora de pantalla inicialment
		// Set the sprite's origin to dead centre
		// We can then spin it round without changing its position
		branches[i].setOrigin(220, 20); // Centrar el punt de rotació
	}

	// Prepare the player
	Texture texturePlayer;
	texturePlayer.loadFromFile("graphics/player.png");
	Sprite spritePlayer;
	spritePlayer.setTexture(texturePlayer);
	spritePlayer.setPosition(580, 720); // Posició inicial del jugador

	// The player starts on the left
	side playerSide = side::LEFT; // El jugador comença a l'esquerra
	branchPositions[3] = side::NONE;

	// Prepare the gravestone
	Texture textureRIP;
	textureRIP.loadFromFile("graphics/rip.png");
	Sprite spriteRIP;
	spriteRIP.setTexture(textureRIP);
	spriteRIP.setPosition(580, 720); // Posició inicial
	// Prepare the axe
	Texture textureAxe;
	textureAxe.loadFromFile("graphics/axe.png");
	Sprite spriteAxe;
	spriteAxe.setTexture(textureAxe);
	spriteAxe.setPosition(580, 850); // Posició inicial
	// Prepare the flying log
	Texture textureLog;
	textureLog.loadFromFile("graphics/log.png");
	Sprite spriteLog;
	spriteLog.setTexture(textureLog);
	spriteLog.setPosition(580, 720);

	// Some other useful log related variables
	bool logActive = false;
	float logSpeedX = 1000;
	float logSpeedY = -1500;

	// Control the player input
	bool acceptInput = false; // Indica si el jugador pot interactuar

	// Prepare the sound
	// The player chopping sound
	SoundBuffer chopBuffer;
	chopBuffer.loadFromFile("sound/chop.wav");
	Sound chop;
	chop.setBuffer(chopBuffer);
	SoundBuffer deathBuffer;
	deathBuffer.loadFromFile("sound/death.wav");
	Sound death;
	death.setBuffer(deathBuffer);

	// Variables per calcular el FPS
	int frameCount = 0;  // Comptador de fotogrames
	float elapsedTime = 0.0f;  // Temps acumulat per actualitzar el FPS
	Text fpsText;  // Text per mostrar el FPS
	fpsText.setFont(font);
	fpsText.setCharacterSize(50);
	fpsText.setFillColor(Color::White);
	fpsText.setPosition(1600, 20);  // Posar el FPS a la cantonada superior dreta
	

	// Out of time

	// random seed
	srand((int)time(0) * 10);
	
	
	//game loop

	while (window.isOpen())
	{	
		Time dt = clock.restart();

		/*
		****************************************
		Handle the players input
		****************************************
		*/
		Event event;
		while (window.pollEvent(event))
		{
			// GESTIÓ D'ENTRADES (INPUT MANAGEMENT)
			if (event.type == Event::KeyReleased && !paused)
			{
				// Listen for key presses again
				acceptInput = true;
				// hide the axe
				spriteAxe.setPosition(2200, spriteAxe.getPosition().y);
			}
		}
		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			window.close(); // Tanca la finestra si es prem ESC
		}

		// Start the game
		if (Keyboard::isKeyPressed(Keyboard::Return))
		{// Quan es prem Enter, el joc comença o es reinicia
			paused = false; // El joc deixa d'estar en pausa

			// Reset the time and the score			
			timeRemaining = 10; // Reinicia el temps restant
			score = 0; // Reinicia la puntuació

			// Make all the branches disappear
			// Reset de les branques
			for (int i = 1; i < NUM_BRANCHES; i++)
			{
				branchPositions[i] = side::NONE; // Totes les branques s'amaguen
			}

			// Make sure the gravestone is hidden
			spriteRIP.setPosition(675, 2000);

			// Move the player into position
			spritePlayer.setPosition(580, 720);

			acceptInput = true;  // El jugador pot tornar a jugar
		}
		// Wrap the player controls to
		// Make sure we are accepting input
		 // Si es permet input i es prem una tecla de direcció
		if (acceptInput)
		{

			// First handle pressing the right cursor key
			if (Keyboard::isKeyPressed(Keyboard::Right))
			{// Jugador talla a la dreta

				// Make sure the player is on the right
				playerSide = side::RIGHT; // Canvia el costat del jugador
				score++; // Incrementa la puntuació

				// Add to the amount of time remaining
				
				timeRemaining += (2 / score) + .15; // Afegir temps segons la puntuació
				// Moure destral
				spriteAxe.setPosition(AXE_POSITION_RIGHT,
					spriteAxe.getPosition().y);
				spritePlayer.setPosition(1200, 720);
				spriteAxe.setScale(-1.f, 1.f);
				// update the branches
				updateBranches(score, branchPositions);

				// set the log flying to the left
				
				spriteLog.setPosition(810, 720);
				logSpeedX = -5000;
				logActive = true;
				acceptInput = false; // Desactiva entrada fins que s'actualitzin els estats
				// Play a chop sound
				chop.play();
			}


		// Handle the left cursor key
			if (Keyboard::isKeyPressed(Keyboard::Left))
			{// Jugador talla a l'esquerra
				
				// Make sure the player is on the right
				playerSide = side::LEFT; // Canvia el costat del jugador
				score++; // Incrementa la puntuació

				// Add to the amount of time remaining
				timeRemaining += (2 / score) + .15; // Afegir temps segons la puntuació

				// Moure destral
				spriteAxe.setPosition(AXE_POSITION_LEFT,
					spriteAxe.getPosition().y);
				spritePlayer.setPosition(580, 720);
				spriteAxe.setScale(1.f, 1.f);
				// update the branches
				updateBranches(score, branchPositions);

				// set the log flying to the left
				spriteLog.setPosition(810, 720);
				logSpeedX = 5000;
				logActive = true;
				acceptInput = false;  // Desactiva entrada fins que s'actualitzin els estats
				// Play a chop sound
				chop.play();
			}
		
		}


		/*
		****************************************
		Update the scene
		****************************************
		*/
		if (!paused)
		{

		// Measure time
		// Subtract from the amount of time remaining
		timeRemaining -= dt.asSeconds();
		// size up the time bar
		timeBar.setSize(Vector2f(timeBarWidthPerSecond * timeRemaining, timeBarHeight));
		if (timeRemaining <= 0.0f) {
			// Pause the game
			paused = true; // El joc es pausa quan el temps s'acaba
			// Change the message shown to the player
			messageText.setString("Out of time!!"); // Missatge de derrota
			//Reposition the text based on its new size
			FloatRect textRect = messageText.getLocalBounds();
			messageText.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
			messageText.setPosition(1920 / 2.0f, 1080 / 2.0f);
		}
			// Play the out of time sound


		// Setup the bee
		for (int i = 0; i < NumMaxBees; i++) {
			if (!eixam[i].Active) // Si la abella està inactiu, reinicialitzar-lo
			{					
					eixam[i].Speed = (rand() % -201 + -200);
					eixam[i].dibuix.setPosition(2000, (rand() % 500));
					eixam[i].Active = true;
			}
			else
			{ 
				eixam[i].dibuix.setPosition(eixam[i].dibuix.getPosition().x + (eixam[i].Speed * dt.asSeconds()),
					eixam[i].dibuix.getPosition().y);
				// Si el núvol surt de la pantalla, fer-lo inactiu
				if (eixam[i].dibuix.getPosition().x < 0)
				{
					eixam[i].Active = false;
				}
			}
		}

		// Manage the clouds
		for (int i = 0; i < NumMaxClouds; i++)
		{ 
			if (!spriteCloud[i].Active)
			{// Si el núvol està inactiu, reinicialitzar-lo
				spriteCloud[i].Speed = (rand() % 200);
				spriteCloud[i].dibuix.setPosition(-200, (rand() % 500));
				spriteCloud[i].Active = true;
			}
			else
			{ // Moure el núvol cap a la dreta
				spriteCloud[i].dibuix.setPosition(spriteCloud[i].dibuix.getPosition().x + (spriteCloud[i].Speed * dt.asSeconds()),
					spriteCloud[i].dibuix.getPosition().y);
				// Si el núvol surt de la pantalla, fer-lo inactiu
				if (spriteCloud[i].dibuix.getPosition().x > Xmax)
				{
					spriteCloud[i].Active = false;
				}
			}
		}


		// Update the score text		
		if (score != lastScore) { 
			// Si la puntuació actual no coincideix amb l'última puntuació mostrada
			stringstream ss;
			ss << "Score = " << score; // Actualitzar el text de la puntuació
			scoreText.setString(ss.str()); // Assignar el nou text al marcador
			lastScore = score;  // Actualiza el valor de la última puntuación
		}
		// update the branch sprites
		for (int i = 0; i < NUM_BRANCHES; i++)
		{
			float height = i * 150; // Calcula la posició vertical de cada branca
			if (branchPositions[i] == side::LEFT) // Si la branca està al costat esquerre
			{
				// Move the sprite to the left side
				branches[i].setPosition(610, height);  
				// Flip the sprite round the other way
				branches[i].setRotation(180); 
			}
			else if (branchPositions[i] == side::RIGHT) // Si la branca està al costat dret
			{
				// Move the sprite to the right side
				branches[i].setPosition(1330, height);
				// Set the sprite rotation to normal
				branches[i].setRotation(0);
			}
			else // Si la branca no està visible (NONE)
			{
				// Hide the branch
				branches[i].setPosition(3000, height);
			}
		}


		// Handle a flying log				
		if (logActive)
		{
			spriteLog.setPosition(
				// Actualitzar la posició X del tronc
				spriteLog.getPosition().x + (logSpeedX * dt.asSeconds()),
				// Actualitzar la posició Y del tronc
				spriteLog.getPosition().y + (logSpeedY * dt.asSeconds())
			);

			// Has the insect reached the right hand edge of the screen?
			// Si el tronc surt de la pantalla per l'esquerra o dreta
			if (spriteLog.getPosition().x < -100 || spriteLog.getPosition().x > 2000)
			{
				// Set it up ready to be a whole new cloud next frame
				logActive = false; // Desactiva el moviment del tronc
				spriteLog.setPosition(810, 720); // Reposiciona el tronc al seu lloc inicial
			}

		}


		// has the player been squished by a branch?
		// Si una branca (índex 5) coincideix amb el costat del jugador
		if (branchPositions[5] == playerSide)
		{
			// death
			paused = true; // Pausa el joc
			acceptInput = false; // Desactiva l'entrada del jugador
			// Draw the gravestone
			spriteRIP.setPosition(525, 760);
			// hide the player
			spritePlayer.setPosition(2000, 660);
			// Change the text of the message
			messageText.setString("SQUISHED!!");
			// Center it on the screen
			FloatRect textRect = messageText.getLocalBounds();
			messageText.setOrigin(textRect.left + textRect.width / 2.0f,
				textRect.top + textRect.height / 2.0f);
			messageText.setPosition(1920 / 2.0f, 1080 / 2.0f); // Centra el text a la pantalla
			// Play the death sound

			death.play();
		}


		} // End if(!paused)

		// Mesurar el temps i incrementar el comptador de fotogrames
		frameCount++;  // Incrementa el comptador de fotogrames
		elapsedTime += dt.asSeconds();  // Acumula el temps


		// Actualizar FPS cada 100 fotogramas o 1 segundo
		if (elapsedTime >= 1.0f) {

			float fps = frameCount / elapsedTime; // Calcula els FPS (frames per segon)
			stringstream ss;
			ss << "FPS: " << fps; // Actualitza el text dels FPS
			fpsText.setString(ss.str()); // Assigna el text actualitzat

			frameCount = 0; // Reinicia el comptador de fotogrames
			elapsedTime = 0.0f; // Reinicia el temps acumulat
		} 
	 /*
	 ****************************************
	 Draw the scene
	 ****************************************
	 */

	 // Clear everything from the last frame
		window.clear(); // Netejar la finestra

		// Draw our game scene here
		window.draw(spriteBackground); 

		// Draw the clouds
		for (int i = 0; i < NumMaxClouds; i++)
		{
			window.draw(spriteCloud[i].dibuix);
		}
		// Draw the tree3
		window.draw(spriteTree3);

		// Draw the branches
		for (int i = 0; i < NUM_BRANCHES; i++) {
			window.draw(branches[i]);
		}

		// Draw the tree
		window.draw(spriteTree);
		window.draw(spriteTree2);  
		window.draw(spriteTree4);
		// Draw the player
		window.draw(spritePlayer);

		// Draw the axe
		window.draw(spriteAxe);
		// Draw the flying log
		window.draw(spriteLog);
		// Draw the gravestone
		window.draw(spriteRIP);

		// Drawraw the bee
		for (int i = 0; i < NumMaxBees; i++)
		{
			window.draw(eixam[i].dibuix);
		}

		// Draw the score
		window.draw(scoreText);
		// Dibuixar el text del FPS
		window.draw(fpsText);
		if (paused)
		{
			// Draw our message
			window.draw(messageText);
		}

		// Draw the timebar
		window.draw(timeBar);


			// Draw our message

		// Show everything we just drew
		window.display();

	}

	return 0;
}

// Function definition
void updateBranches(int seed, side branca[])
{
	// Move all the branches down one place
	for (int j = NUM_BRANCHES - 1; j > 0; j--) {
		branca[j] = branca[j - 1];
	}
	// Spawn a new branch at position 0
		// LEFT, RIGHT or NONE
	srand((int)time(0) + seed);
	int r = (rand() % 5);
	switch (r) {
	case 0:
		branca[0] = side::LEFT;
		break;
	case 1:
		branca[0] = side::RIGHT;
		break;
	default:
		branca[0] = side::NONE;
		break;
	}
}

