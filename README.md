# ESP32-projects

## Installing ESP-IDF
The ESP-IDF needs to be installed and built on your machine to run the project. For installation, follow these steps:

### For Ubuntu

1. update the machines
```
sudo apt update
sudo apt upgrade
```

2. Installing all dependeces
```
sudo apt install -y \
    git \
    wget \
    flex \
    bison \
    gperf \
    python3 \
    python3-pip \
    python3-setuptools \
    cmake \
    ninja-build \
    ccache \
    libffi-dev \
    libssl-dev \
    dfu-util
```

3. Generate a dependence for ESP-IDF at home
Open a new terminal and type

```
mkdir -p ~/esp
cd ~/esp
git clone --recursive https://github.com/espressif/esp-idf.git
```

4. Setup the ESP-IDF compiler

```
cd ~/esp/esp-idf
./install.sh all
```

5. In ```.bashrc```, setup an alias to call idf in any dependence you are

```
cd ~/esp/esp-idf
./install.sh all
```

or do just ```echo ". $HOME/esp/esp-idf/export.sh" >> ~/.bashrc ```

## Using ESP-IDF in this project

After cloning this project, do ``` cd ESP32-projects/```, connect your ESP board in your USB port and 

```
idf.py build
idf.py flash
idf.py monitor
```


