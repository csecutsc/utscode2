# UTSCode2

This is the official repository for the UTSCode 2018 contest. This repository holds all the tools, problem statements written in LaTeX, and solutions written in Python, Java, or C++.


# Requirements
If you plan on making your own problems on the Kattis platform, then here are some 
important links required for to compile the problemstatements from source and verify
the validity your solutions against the current testdata.

[Kattis problemtools](https://github.com/Kattis/problemtools)

[Introduction to the Kattis Problem Format and problemtools](http://problemarchive.org/wiki/index.php/Introduction_to_the_Kattis_Problem_Format)

[Indepth information on using the Kattis problemtools](http://problemarchive.org/wiki/index.php/Problem_Format)

## Environment

In order to run/test problems, an Ubuntu 14.04 sandbox has been package for Vagrant+Virtualbox.

Linux
```
$ sudo apt-get install virtualbox vagrant
```
Mac
```
$ brew install virtualbox vagrant
```

From there, spin up a VM with the Vagrantfile by running:

```
$ vagrant up
```

## Running

To test problems, run

```
$ vagrant ssh
```

Problems will be under `utscode2` where you can run all Kattis [problemtools](https://github.com/Kattis/problemtools).

## Official Contest
[utscode.com](https://utscode.com/)




