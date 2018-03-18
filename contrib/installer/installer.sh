#!/usr/bin/env bash
# Auto Installer / compiler for DFT Coin wallet
# 2018-01-14  James Coberly - jame@xmc.com 
HOMEDIR=$HOME
BUILD="GUI"

POSITIONAL=()
while [[ $# -gt 0 ]]
do
key="$1"
case $key in
    -d|--build-daemon)
    BUILD="DAEMON"
    shift 
    shift 
    ;;
    -h|--help)
    echo"Usage:  installer.sh options"
    echo"Where options are:"
    echo"-d --build-daemon - Build draftcoind daemon"
    echo"-gui --build-gui - (DEFAULT) Build QT Gui DraftCoin Wallet"
    echo"-h --help - This message"
    
    shift 
    shift 
    ;;
    -gui|--build-gui)
    BUILD="GUI"
    shift 
    shift
    ;;
    *)    # unknown option
    POSITIONAL+=("$1") # save it in an array for later
    shift 
    ;;
esac
done
set -- "${POSITIONAL[@]}" # restore positional parameters


# Get OS Version
#!/usr/bin/env bash

if [ "$(uname)" == "Darwin" ]; then
    # Do something under Mac OS X platform        
	OS=unknown
elif [ "$(expr substr $(uname -s) 1 5)" == "Linux" ]; then
    # Do something under GNU/Linux platform
	if [ -f /etc/debian_version ]; then
		echo "This is debian based distro"
    		OS=debian
	elif [ -f /etc/redhat-release ]; then
    		echo "This is RedHat based distro"
    		OS=fedora
	else
    		echo "This is something else"
    		OS=unknown
	fi

elif [ "$(expr substr $(uname -s) 1 10)" == "MINGW32_NT" ]; then
    # Do something under 32 bits Windows NT platform
	OS=win32
elif [ "$(expr substr $(uname -s) 1 10)" == "MINGW64_NT" ]; then
    # Do something under 64 bits Windows NT platform
	OS=win64
fi




  
# Perform Debian updates
if [ $OS = "debian" ]; then
  	sudo sed -i 's/# \(.*multiverse$\)/\1/g' /etc/apt/sources.list && \
  	sudo apt-get update && \
  	sudo apt-get -y upgrade && \
  	sudo apt-get install -y build-essential && \
  	sudo apt-get install -y software-properties-common && \
  	sudo apt-get install -y byobu curl git htop man unzip vim wget && \
  	sudo rm -rf /var/lib/apt/lists/*


	sudo apt-get -y install build-essential
	sudo apt-get -y update
	sudo apt-get -y install libssl-dev
	sudo apt-get -y update
	sudo apt-get -y install libdb++-dev 
	sudo apt-get -y install libboost-all-dev
	sudo apt-get -y install libminiupnpc-dev
	if [ $BUILD = "GUI" ]; then
	sudo apt-get -y qt5-qmake libqt5-dev
	fi

fi

#Perform Fedora Updates
if [ $OS = "fedora" ]; then

	sudo dnf install gcc-c++ libtool make autoconf automake openssl-devel libevent-devel boost-devel python3 miniupnpc-devel protobuf-devel qrencode-devel
	if [ $BUILD = "GUI" ]; then
	sudo dnf install qt5-qttools-devel qt5-qtbase-devel	fi

fi




if [ $OS != "unknown" ]; then
# OK Compile the app now
#	mkdir $HOMEDIR/draftcoin
        cd $HOMEDIR
        git clone https://github.com/btcdraft/draftcoin.git
        cd $HOMEDIR/draftcoin

        mkdir $HOMEDIR/.DraftCoin
        cp DraftCoin.conf /$HOMEDIR/.DraftCoin/DraftCoin.conf
        
	if [ $BUILD = 'DAEMON' ]; then
	# Build for Daemon only
        	cd src/ && make -f makefile.unix
		echo"Starting DraftCoin Daemon"
		$HOME/draftcoin/src/DraftCoind --daemon &

	else

        #Build QT desktop version
        	qmake && make
                sudo make install-qt
	echo "DraftCoin Wallet Installed..... Starting now."

        DraftCoin-qt &
        fi
else 
echo "Unsupported OS, please review docs/ for instructions on your OS."

fi



