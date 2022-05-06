# Puzzle
Puzzle game on C++ with SDL2

# Contents
- [How it works](#how-it-works)
- [Requirements](#requirements)
- [Quick start](#quick-start)
- [Structure](#structure)

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