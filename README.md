# UTSCode2

This is the official repository for the UTSCode 2018 contest. This repository holds all the tools, problem statements written in LaTeX, and solutions written in Python3 or C++.

## Installing

In order to run/test problems, Vagrant is required to sandbox Ubuntu 14.04.

```
$ sudo apt-get install virtualbox vagrant
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

Problems will be under utscode2 where you can run all of `problemtools` provided by Kattis.
