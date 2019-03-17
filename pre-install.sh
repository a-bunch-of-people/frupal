#!/bin/bash

DISTRO=$(cat /etc/*-release | sed -n 9,9p | cut -d '=' -f 2)

#
# 1: Message tag mode:
#   - 1 Say with info tag
#   - 2 Say with error tag
#   - 3 Say with warning tag
#
function say(){
    MODE=""

    if   [[ $1 == 1 ]]; then
        MODE="INFO"
    elif [[ $1 == 2 ]]; then
        MODE="ERROR"
    elif [[ $1 == 3 ]]; then
        MODE="WARN"
    fi

    echo -e "[$MODE]: $2"
}

if [[ -z $(ldconfig -p | grep libncurses) ]]; then
  if [[ $DISTRO = 'debian' ]]; then
    sudo apt-get install ncurses
  elif [[ $DISTRO = 'arch' ]]; then
    sudo pacman -S ncurses
  else
    say 2 "Your distribution: $DISTRO is unrecognized. Please refer to its best known repository for instructions on how to install it."
  fi
else
  say 3 "Pre-defined dependencies are already installed!"
fi
