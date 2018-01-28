# UTSCode2

This is the official repository for the UTSCode 2018 contest. This repository holds all the tools, problem statements written in LaTeX, and solutions written in Python3 or C++.

## Problem Composition
We're aiming for 10-11 problems for this contest, with the following categories:
* 3 no-brainers with varying difficulty
* 2 Dynamic Programming 
* 1 Network Flow
* 1 Greedy
* 1 Interactive
* 1 Math/Statistics related
* 1 Graph Theory
* (optional) 1 Binary Search/Math related

## Current Roles/Tasks 
* Jason - 1 No brainer, 1 DP
* Ousmane - 1 No brainer, 1 Greedy
* William - 1 Network Flow, 1 DP

**Make sure** that when you're done writing a problem you have someone **proofread** it before the actual contest.


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

Problems will be under `utscode2` where you can run all Kattis [problemtools](https://github.com/Kattis/problemtools).


