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

The class is responsible for displaying the splash screen. It should carry the methods of loading the image and displaying it. This is a visual class.

## Class MainMenu

The output class of the main menu. The class method displays the main menu of the game. Inherited from the "Graphics" class. This is a visual class.

## Class Rules

The class responsible for the availability of reference information about the game. It carries a method for displaying and displaying information about the creator of the program, as well as rules for the game. Inherited from the "Graphics" class. This is a visual class.

## Class Stat

The class required to display the puzzle selection menu. The methods of the class are responsible for the output and display of the puzzle selection menu, and are also responsible for processing the puzzle selection event. Inherited from the "Graphics" class. This is a visual class.

## Class Game

The class is responsible for the gameplay. Methods of this class draw a board for assembling a puzzle, cut the original image into puzzle pieces, display them in random order on the sidebar, create a timer that marks the time of assembling the puzzle. Inherited from the "Graphics" class. This is a visual class.

