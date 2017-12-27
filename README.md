# PacMan3D
L’objectif de ce projet est de développer un jeu de type "PACMAN" en 3D en C++/OpenGL 3+

## Requirements to compile
* Have SDL1.2 installed
* GLEW installed
* OpenGL ( should be installed with your graphical drivers )


## How to use it :

* Usage using command line: 
  * Go in the "build" directory
  * run "cmake .."
  * run "make"
  * run the program from inside the builde directory with the command :
    * On linux : ./bin/Pacman3D
    * On windows : ./bin/Pacman3D.exe
  
## Commands 
The keymap can be changed in the configuration.json located in the "assets/configurations/" folder

###Active only during the game
  * Movement :
    * Z : Move FORWARD
    * S : Move BACKWARD
    * Q : Move LEFT
    * D : Move RIGHT
    * C : Change camera
  
  * Camera : 
    * These two binds can't be changed !
    * Mouse Left click : Zoom In
    * Mouse Right click : Zoom out
    
###Active on the pause menu
  * Interface :
    * P : Pause
    * O : Save
    * I : Load
    * K : Exit the game
    
    
