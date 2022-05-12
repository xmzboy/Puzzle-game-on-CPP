# Puzzle
Puzzle game on C++ with SDL2

# Contents
- [How it works](#how-it-works)
- [Requirements](#requirements)
- [Quick start](#quick-start)
- [Structure](#structure)
- [Project classes](#project-classes)
- [Description of classes](#description-of-classes)

# How it works

You build a project -> launch it -> the game welcomes you, no additional input data is needed. 

If you want to use your image to assemble a puzzle, replace one of the images in the app/images/puzzles folder with the same name with it.

# Requirements

* Installed SDL2 lib
* Installed C++ compiler

# Quick start

Link the SDL2 library and build the project

# Structure

Project have 4 main folders:

* 💻 app - main folder, containing:
	* A file with game statistics and the best results
	* Other folders
* ✏ fonts - folder with fonts
* 🖼 images - folder with images, containing:
	* Folder with puzzle images
	* Intro image
* 🏗 src - folder with sources, containing:
	* Sources folder
	* Headers folder

# Project classes

## Class Intro

The class is responsible for displaying the splash screen. It should carry the methods of loading the image and displaying it. It is a visual class.

## Class MainMenu

The output class of the main menu. The class method displays the main menu of the game. Inherited from the "Graphics" class. It is a visual class.

## Class Rules

The class responsible for the availability of reference information about the game. It carries a method for displaying and displaying information about the creator of the program, as well as rules for the game. Inherited from the "Graphics" class. It is a visual class.

## Class Stat

The class required to display the puzzle selection menu. The methods of the class are responsible for the output and display of the puzzle selection menu, and are also responsible for processing the puzzle selection event. Inherited from the "Graphics" class. It is a visual class.

## Class Game

The class is responsible for the gameplay. Methods of this class draw a board for assembling a puzzle, cut the original image into puzzle pieces, display them in random order on the sidebar, create a timer that marks the time of assembling the puzzle. Inherited from the "Graphics" class. It is a visual class.

## Class Texture

This class is responsible for creating the texture. It contains methods for loading an image onto a given texture, displaying it, outputting text, and clearing the texture. It is not a visual class.

## Class Button

The class required to create the button object. It carries methods for creating, displaying, changing colors and processing button clicks. Inherited from the "Texture" class. It is not a visual class.

## Class Info

The class required to get information about the selected file. Its methods are responsible for the correct loading and output of the time, the number of hints and the picture used in the game. It is not a visual class.

## Class Graphics

It is the base class for all visible graphic elements. The class consists of the following fields: a pointer to a texture for caching data, a Rect structure containing the definition of a rectangle (x, y coordinates of the upper left point, width and height), as well as a font. The initial initialization of texture coordinates is performed in the constructor.

## Class MainWindow

The class is responsible for monitoring game states.
The following states are defined in the class:
* MainMenuStatus (Menu)
* GameStatus (Game)
* RuleStatus (Rules)

The constructor performs initial initialization (initial state "MainMenuStatus"). The class contains the "Execution" method – it is responsible for event handling and monitoring the current state. This method contains several blocks for checking events: cursor movement and mouse button pressing. Depending on the existing state, the corresponding surfaces are displayed. The general types of states are formed by overlapping surfaces of different classes. At this stage, the menu is available to the user. There are three items in the menu: "Game", "Background information", "Exit".

When selecting the first menu item, the user enters the "GameStatus" state.

When viewing the reference information, the state is considered equal to "RuleStatus".

By selecting the "Exit" option, the program is terminated.

## Class diagram

![Class diagram](https://github.com/xmzboy/Puzzle-game-on-CPP/raw/main/readme_images/class-diagram.png)

# Description of classes

## Class Intro description

The class declaration is in the header file – intro.h, the class definition in the file – intro.cpp.

According to the project, methods for loading an image and displaying a splash screen were created for the Intro class.

The "Intro" class contains the methods:
```c++
LoadImage()	// responsible for loading the image;
show()		// responsible for the output of the splash screen.
`````
The result of the "Intro" class constructor:

![Intro](https://github.com/xmzboy/Puzzle-game-on-CPP/raw/main/readme_images/intro.jpg)

## Class MainMenu description

The class declaration is in the header file – MainMenu.h, the class definition in the file – MainMenu.cpp.

According to the project, a method for displaying the main menu was created for the "MainMenu" class. The main menu button objects are created in the class constructor.

The "MainMenu" class contains the method:
```c++
Show(SDL_Renderer *const &)	// responsible for displaying the main menu.
EventMenu(SDL_Event &)		// the status of pressing the key.
`````
The result of the "MainMenu" class constructor:

![MainMenu](https://github.com/xmzboy/Puzzle-game-on-CPP/raw/main/readme_images/mainmenu.png)

## Class Rules description

The class declaration is in the header file – Rules.h, the class definition in the file – Rules.cpp .

According to the project, a method for displaying and displaying information about the creator of the program, as well as the rules of the game, was created for the "Rules" class. In the class constructor, a texture is created with reference information, and an exit button to the main menu is also created.

The "Rules" class contains the method:
```c++
Show(SDL_Renderer *const &)	// is responsible for displaying reference information about the program.
EventMenu(SDL_Event &)		// the status of pressing the key.
`````

## Class Stat description

The class declaration is in the header file – Stat.h, the class definition in the file – Stat.cpp .

According to the project, methods were created for the "Stat" class responsible for displaying and displaying the puzzle selection menu, as well as methods responsible for processing the puzzle selection event.

The "Stat" class contains methods:
```c++
show()				// responsible for displaying the puzzle selection menu.
draw_items()			// draws the components of the puzzle selection menu.
load_from_directory()		// loading the image.
load_from_file()		// responsible for loading information about the puzzle.
save()				// saves information to a file.
update(Info *info)		// data update.
add_info(Info *info)		// a method for adding data to the list.
handle_event(SDL_Event * event)	// event tracking.
EventMenu(SDL_Event &)		// the status of pressing the key.
`````
The result of the constructor of the "Stat" class:

![Stat](https://github.com/xmzboy/Puzzle-game-on-CPP/raw/main/readme_images/stat.png)

## Class Game description

The class declaration is in the header file – Game.h, the class definition in the file – Game.cpp .

According to the project, for the "Game" class, methods were created that draw the board for assembling the puzzle, methods that break the original image into puzzle pieces, methods that display them randomly on the sidebar, as well as a method that creates a timer that marks the time of assembling the puzzle.

The "Game" class contains methods:
```c++
Show(SDL_Renderer *const &)		// responsible for displaying the game on the screen.
load_image(const char* filename)	// responsible for loading the puzzle image.
draw_board()				// responsible for drawing the puzzle assembly board.
draw_preview()				// responsible for displaying the hint.
randomize_feed()			// responsible for displaying the puzzle pieces in random order.
draw_feed()				// responsible for the output of puzzle pieces.
draw_timer(int seconds, int previews)	// responsible for creating a timer.
EventGame(SDL_Event &)			// the status of pressing the key.
`````
The result of the constructor of the "Game" class:

![Game](https://github.com/xmzboy/Puzzle-game-on-CPP/raw/main/readme_images/game.png)

## Class Texture description

The class declaration is in the header file – Texture.h, the class definition in the file – Texture.cpp.

According to the project, methods were created for the "Texture" class to load an image onto this texture, display it, output text, and clear the texture.

The "Texture" class contains methods:
```c++
LoadFromFile(const char* path)											// image loading.
CreateTexture(int width, int height, SDL_TextureAccess access, int x = 0, int y = 0)				// texture creation.
loadFromRenderedText(const char* textureText, SDL_Color textColor, TTF_Font* gFont)				// creates an image from a string.
loadFromRenderedTextWrapped(const char *textureText, SDL_Color textColor, ttf_font *gfont, int textWidth)	// creates an image from a string with an area of the specified width.


free()									// freeing the texture.
setAlpha(Uint8 alpha)							// setting the alpha modulation.
setRenderTarget(bool enable)						// the choice of the visualizer.
RenderCopy(SDL_Renderer* renderer, SDL_Rect* frame, SDL_Rect* scrRect)	// copying to the visualizer.
SetRenderParameters(int x, int y, int w, int h)				// setting the parameters of the visualizer.
render(int xOffcet = 0, int yOffcet = 0)				// renders the texture at a given point.
getWidth()								// setting the width.
getHeight()								// height setting.
GetPosX()								// setting the x coordinate.
GetPosY()								// setting the y coordinate.
`````