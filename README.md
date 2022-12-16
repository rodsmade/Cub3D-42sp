# Cub3D
A first-person perspective 3D raycaster written in C.

This project is the second in the school's common core to have a graphic interface. It takes a configuration file as input, which describes a level map in a hypothetical 3D first-person game.

This project comprises two main parts:
1. **configuration file validator**, whereby the program needs to be smart enough to decide whether all the data it's taking in as input is valid and in the correct format to be then transformed into a 3d perspective.
2. a **raycasting engine**, that is, the actual drawing of said 3D perspective on a window based off the instructions found in the valid configuration file.

A tester was written for this project in TDD fashion for the input file validation! If you'd like to use it to test your project, follow the instructions below.

## Files 
* ```assets/maps/valid_map.cub```
	an example valid configuration file to run the program with
* ```assets/textures```
	all original textures in the Wolfenstein 3D action game.
* ```libs/```
	both the set of custom functions written by cadets at 42 school (Libft) and the minified libx API provided by the school to manage peripheral events and draw the game on a window (Minilibx).
* ```src/```
	source code for this project.
* ```tests/```
	A custom tester written à la TDD for the input file validation code.

## Configuration file syntax
By means of the configuration file it is possible to determine:
- the texture of the walls facing each of the 4 cardinal directions (north, south, east and west). The file must have a line prefixed by the keys `NO`, `SO`, `EA` and `WE`, followed by a path to a `.xpm` file containing the description of a texture of size 64 by 64.
- the colours of the ceiling and the floor (in `RGB` format), each value separated by commas.
- the map of one level in a hypothetical 3D game. This must go as the last element in the config file.
- the player's spawning position and facing direction, represented by one of the four valid characters: `N`, `E`, `W` and `S`, with N meaning the player must spawn facing the north walls, and so forth.


## Dependencies
In order to run this project a computer must have `xorg`, `x11` and `zlib` install. Please refer to [this tutorial](https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html#getting-a-screen-on-windows-10-wsl2) in order to find out how to install the dependencies in different sytems (Linux, MacOS, WSL etc.)


## Tests
These tests were originally written on the go mostly as I was writing the input file validator. The renderisation itself is **not** accounted for in this tester.

The tester considers both valid and invalid scenarios (too many arguments, too little arguments, invalid paths, and so on), and for each scenario, two tests are executed:
1. Does the program exit with the proper exit code?
2. Are there any leaks or other valgrind warnings?

For simplicity's sake, I consider that whatever exit code returned that is **different than 0** means that your program decided that the input file is **invalid**. That is to say that the tester is not looking for any particular exit code when an error occurs. As long as the program returns anything other than 0, the tester should be able to identify it.

For instance, in the case of a config file with duplicate parameters - which is considered an invalid input -, the test case in the shell script is written as:

```
test_case '42_test_duplicate_EA_texture_parameter_must_return_exit_code_1' './maps/invalid/42_duplicate_EA_parameter.cub' 1 'test_42_err'
```

The `1` in this function call (3rd parameter passed onto `test_case`) means that the tester is expecting your program to output something other than 0. If that is the case, the tester should print `[OK]` in the first column (EC).

### I want to add a new config file test case
All you need to do is to duplicate the last line in the `# RUN TESTS` sectino of the bash script! Write a description for the test you want to add, make sure you create a new configuration file that represents the scenatio you want to test, decide whether this is a valid (0) or an invalid (1) config map and insert the destined log file name for this test. *Don't forget to update the number of the test case!*
