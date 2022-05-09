# Puzzle
Puzzle game on C++ with SDL2

# Contents
- [How it works](#how-it-works)
- [Requirements](#requirements)
- [Quick start](#quick-start)
- [Structure](#structure)
- [Project classes](#project-classes)

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
