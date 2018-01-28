sudo apt-get update && sudo apt-get -y upgrade
sudo apt-get -y install python-pip
sudo add-apt-repository ppa:ubuntu-toolchain-r/test -y
sudo apt-get update
sudo apt-get -y install gcc-5 g++-5
sudo update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-5 60 --slave /usr/bin/g++ g++ /usr/bin/g++-5
sudo update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-5 40 --slave /usr/bin/g++ g++ /usr/bin/g++-5
sudo update-alternatives --config gcc
sudo apt-get -y install python-pkg-resources libboost-regex-dev debhelper libgmp3-dev automake autoconf texlive texlive-latex-recommended texlive-fonts-recommended texlive-latex-extra texlive-lang-cyrillic texlive-lang-english tidy ghostscript
sudo pip2 install pytest pyyaml plastex
