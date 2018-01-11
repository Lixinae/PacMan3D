# PacMan3D
This project's purpose is to developp a PACMAN-like game in 3D , using C++ and OpenGL 3+

## Requirements to compile
* Have SDL1.2 installed
* GLEW installed
* OpenGL ( should be installed with your graphical drivers )


## How to run the game it :

* Usage using command line to compile then run: 
  * Go in the "build" directory
  * run "cmake .."
  * run "make"
  * run the program from the command line inside the build directory with the command :
    * On linux : ./bin/Pacman3D
    * On windows : ./bin/Pacman3D.exe
    
* If it's already compiled :
  * run the program from the command line inside the build directory with the command :
    * On linux : ./bin/Pacman3D
    * On windows : ./bin/Pacman3D.exe 
  * On windows you need to use the powerShell or MinGW shell. Not the command prompt !!!
## Commands 

### Active only during the game
These binds can be changed in the json configuration file located in the "assets/configurations/" folder

  * Movement :
    * Z : Move FORWARD
    * S : Move BACKWARD
    * Q : Move LEFT
    * D : Move RIGHT
    
### Active on the pause menu
These binds cannot be changed 

  * Interface :
    * ESC : Pause
    * O : Save
    * I : Load
    * K : Exit the game
    
### Active anywhere
These binds can be changed in the json configuration file located in "assets/configurations"

  * Camera : 
    * C : Change camera
    * These two binds can't be changed !
    * Mouse Left click : Zoom In
    * Mouse Right click : Zoom out    
