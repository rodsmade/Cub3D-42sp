# Cub3D
A first-person perspective 3D raycaster written in C.

![testing4](https://user-images.githubusercontent.com/49699403/208158472-4bafd027-2c6e-43eb-b08e-ec07bae98721.gif)

This project is the second in the school's common core to have a graphic interface. It takes a configuration file as input, which describes a level map in a hypothetical 3D first-person game.

This project comprises two main parts:
1. **configuration file validator**, whereby the program needs to be smart enough to decide whether all the data it's taking in as input is valid and in the correct format to be then transformed into a 3d perspective.
2. a **raycasting engine**, that is, the actual drawing of said 3D perspective on a window based off the instructions found in the valid configuration file.

A tester was written for this project in TDD fashion for the input file validation! If you'd like to use it to test your project, follow the instructions below.

![testing7sped](https://user-images.githubusercontent.com/49699403/208161582-2c70208d-76f9-4923-bd87-50780d13d2ef.gif)

- [Cub3D](#cub3d)
	- [Files](#files)
	- [Configuration file syntax](#configuration-file-syntax)
	- [Dependencies](#dependencies)
	- [Tests](#tests)
		- [Using the tester in my project](#using-the-tester-in-my-project)
		- [I want to add a new config file test case](#i-want-to-add-a-new-config-file-test-case)


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

For simplicity's sake, I consider that whatever exit code returned **different than 0** means that your program decided that the input file is **invalid**. That is to say that the tester is not looking for any particular exit code when an error occurs. As long as the program returns anything other than 0, the tester should be able to identify it.

For instance, in the case of a config file with duplicate parameters - which is considered an invalid input -, the test case in the shell script is written as:

```
test_case '42_test_duplicate_EA_texture_parameter_must_return_exit_code_1' './maps/invalid/42_duplicate_EA_parameter.cub' 1 'test_42_err'
```

The `1` in this function call (3rd parameter passed onto `test_case`) means that the tester is expecting your program to output something other than 0. If that is the case, the tester should print `[OK]` in the first column (EC).

### Using the tester in my project

> :warning: Beware!
> 
> It is important to know that at the time of writing these tests, *none of the graphics part had been coded as of yet*. So if your code is already using mlx and opening windows, I suggest you **comment out** this part of your code before using this tester.

Simply copy the `tests` folder to the same level as your binary `./cub3D` is found. Then, it is important to `cd` into `tests`, and then simply run `./test_my_cub3D.sh`. You may need to add execution permission to the script, in order to do that, simply run  `chmod +x ./test_my_cub3D` and you're good to go.

``` shell
git clone https://github.com/rodsmade/Cub3D-42sp.git
cp -R Cub3D-42sp/tests <destination_folder>
cd <destination_folder>/tests
chmod +x ./test_my_cub3D.sh
./test_my_cub3D.sh
```

### I want to add a new config file test case
All you need to do is to duplicate the last line in the `# RUN TESTS` section of the bash script! Write a description for the test you want to add (arg 1), make sure you create a new configuration file that represents the scenario you want to test (arg 2), decide whether this is a valid (0) or an invalid (1) config file (arg 3), and insert the destined log file name for this test (arg 4)	. *Don't forget to update the number of the test case!*
