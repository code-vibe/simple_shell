# Holberton Project: simple_shell
<img src="https://assets.website-files.com/6105315644a26f77912a1ada/610540e8b4cd6969794fe673_Holberton_School_logo-04-04.svg" height="60%" width="50%">
</h1><h1 align ="center">

## Table of Contents
* [Description](#description)
* [File Structure](#file-structure)
* [File Structure](#Directories)
* [Requirements](#requirements)
* [Installation](#installation)
* [Usage](#usage)
* [Example of Use](#example-of-use)
* [Bugs](#bugs)
* [Authors](#authors)
* [License](#license)
## Description
Simple_shell is a command line interpreter, or shell, made by us in the tradition of the first Unix shell written by Ken Thompson in 1971. This shell is
intentionally minimalistic, was made in order to practice the basics of C learning, yet includes the basic functionality of a traditional Unix-like command line user interface.
Standard functions and system calls employed in simple_shell include:
	 `access, execve, exit, fork, free, fstat, getline, malloc, perror, signal, stat, wait, write.`

## File Structure
* [header.h](header.h) -Program header file

## Requirements

simple_shell is designed to run in the `Ubuntu 20.04 LTS` linux environment and to be compiled using the GNU compiler collection v. `gcc 9.4` with flags`-Wall, -Werror, -Wextra, and -pedantic.`

## Installation

	 - Clone this repository: `https://github.com/luismch158158/simple_shell.git`
	 - Change directories into the repository: `cd simple_shell`
	 - Compile: `gcc -Wall -Werror -Wextra -pedantic *.c -o hsh`
	 - Run the shell in interactive mode: `./hsh`
	 - Or run the shell in non-interactive mode: example `echo "pwd" | ./hsh`

## Usage

The simple_shell is designed to execute commands in a similar manner to sh, however with more limited functionality. The development of this shell is ongoing. The below features will be checked as they become available (see man page for complete information on usage):
### Features
- [ ] uses the PATH
- [ ] implements builtins
- [ ] handles command line arguments
- [ ] custom strtok function
- [ ] uses exit status
- [ ] shell continues upon Crtl+C (**^C**)
- [ ] handles comments (#)
- [ ] handles **;**
- [ ] custom getline type function
- [ ] handles **&&** and **||**
- [ ] aliases
- [ ] variable replacement

### Builtins

- [ ] exit
- [ ] env
- [ ] setenv
- [ ] unsetenv
- [ ] cd
- [ ] help
- [ ] history

## Example of Use
Run the executable in your terminal after compiling:
```
$ ls

## Bugs
At this time, there are no known bugs.

## Authors
Christian Varas | [GitHub](https://github.com/ChristianVaras)

Luis Manrique | [GitHub](https://github.com/luismch158158)

## License
simple_shell is open source and therefore free to download and use without permission.