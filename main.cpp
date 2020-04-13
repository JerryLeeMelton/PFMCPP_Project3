/*
 Project 3 - Part 4 / 5
 video: Chapter 2 - Part 9
 Member initialization tasks

 Create a branch named Part4
 
 1) initialize some of your member variables either in-class or in the Constructor member initializer list.

 2) make some of your member functions use those initialized member variables via std::cout statements.
 
 3) click the [run] button.  Clear up any errors or warnings as best you can.
 
 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 Make a pull request after you make your first commit and pin the pull request link to our DM thread.

send me a DM to check your pull request

 Wait for my code review.
 */

#include <iostream>
namespace Example {
struct UDT  
{
    int a; //a member variable
    float b { 2.f }; //3) in-class initialization
    UDT() : a(0) { } //3) 'constructor-initializer-list' member variable initialization
    void printThing()  //the member function
    {
        std::cout << "UDT::printThing() a:" << a << " b: " << b << std::endl;  //4) printing out something interesting
    }
};

int main()
{
    UDT foo; //instantiating a Foo in main()
    foo.printThing(); //calling a member function of the instance that was instantiated.
    return 0;
}
}

//call Example::main()



 /*
 1)
  */

struct Chameleon
{
    struct Color
    {
        int red = 255;
        int green = 255;
        int blue = 255;
        int alpha = 255;

        void setColor(int newRedValue, int newGreenValue, int newBlueValue)
        {
            red = newRedValue;
            green = newGreenValue;
            blue = newBlueValue;
        }

        void setAlpha(int newAlphaValue)
        {
            alpha = newAlphaValue;
        }
    };

    float length = 5;
    float weight = 3;
    Color color;
    int numberOfTeeth = 35;
    int numberOfScales = 4800;
    float totalTongueFlickDistance = 0;

    Chameleon();
    float run(float speed, float timeToRun);
    void changeColor(int newRedValue, int newGreenValue, int newBlueValue);
    void flickTongue(float flickDistance, int numberOfFlicks);
};

Chameleon::Chameleon()
{
    std::cout << "<Chameleon> was created." << std::endl;
}

float Chameleon::run(float speed, float timeToRun)
{
    return speed * timeToRun;
}

void Chameleon::changeColor(int newRedValue, int newGreenValue, int newBlueValue)
{
    color.setColor(newRedValue, newGreenValue, newBlueValue);

    std::cout << "Chameleon changed color!  New RGB value is (" <<
        newRedValue << ", " << newGreenValue << ", " << newBlueValue << ")" << std::endl;
}

void Chameleon::flickTongue(float flickDistance, int numberOfFlicks)
{
    totalTongueFlickDistance += numberOfFlicks * flickDistance;
}

/*
2)
 */

struct FastFoodRestaurant
{
    float profitPerBurger = 1.65f;
    float profitPerPotato = 0.49f;
    float profitsPerWeek = 0.0f;
    int burgersUsedPerWeek = 0;
    int potatoesUsedPerWeek = 0;
    int burgersInFreezer = 100;
    int potatoesInPantry = 100;

    FastFoodRestaurant();
    bool makeBurger(int numBurgers);
    bool makeFries(int potatoesToUse);
    void restockSupplies(int newPotatoes, int newBurgers);
    bool makeChameleonBurger(Chameleon& chameleon);
};

FastFoodRestaurant::FastFoodRestaurant()
{
    std::cout << "<FastFoodRestaurant> was created." << std::endl;
}

bool FastFoodRestaurant::makeBurger(int burgersToMake)
{
    if (burgersInFreezer > 0)
    {
        burgersInFreezer -= burgersToMake;

        std::cout << "Made " << burgersToMake << " burgers. Burgers left in freezer: " << burgersInFreezer << std::endl;

        return true;
    }

    return false;
}

bool FastFoodRestaurant::makeFries(int potatoesToUse)
{
    if (potatoesToUse < potatoesInPantry)
    {
        potatoesInPantry -= potatoesToUse;

        std::cout << "Made fries using " << potatoesToUse << " potatoes. Potatoes left in freezer: " << potatoesInPantry << std::endl;

        return true;
    }

    return false;
}

void FastFoodRestaurant::restockSupplies(int newPotatoes, int newBurgers)
{
    potatoesInPantry += newPotatoes;
    burgersInFreezer += newBurgers;

    std::cout << "Restocked supplies. " << std::endl <<
        "Potatoes in pantry: " << potatoesInPantry << std::endl <<
        "Burgers in freezer: " << burgersInFreezer << std::endl;
}

bool FastFoodRestaurant::makeChameleonBurger(Chameleon& chameleon)
{
    chameleon.changeColor(150, 75, 0);
    return true;
}

/*
3)
 */

struct ElectricGuitar
{
    float neckLength = 32.5f;
    float volumeKnobPosition = 1.0f;
    float toneKnobPosition = 1.0f;
    int numberOfPickups = 3;
    int numberOfStrings = 6;

    ElectricGuitar();
    void outputSound();
    void setVolume(float newVolumePosition);
    void setTone(float newTonePosition);
};

ElectricGuitar::ElectricGuitar()
{
    std::cout << "<ElectricGuitar> was created." << std::endl;
}

void ElectricGuitar::outputSound()
{
    std::cout << "ElectricGuitar::outputSound() called.  Shredding some hot licks." << std::endl;
}

void ElectricGuitar::setVolume(float newVolumePosition)
{
    volumeKnobPosition = newVolumePosition;

    std::cout << "ElectricGuitar::setVolume(): Volume knob positiion is now " << volumeKnobPosition << std::endl;
}

void ElectricGuitar::setTone(float newTonePosition)
{
    toneKnobPosition = newTonePosition;

    std::cout << "ElectricGuitar::setTone(): Tone knob position is now " << toneKnobPosition << std::endl;
}

/*
4)
 */

struct TapePlayer
{
    struct Tape
    {
        float length = 60.0f;
        float currentPosition = 0.0f;
        bool isWritable = true;

        void setWritable(bool writable)
        {
            isWritable = writable;
        }

        void updatePosition(float newPosition)
        {
            currentPosition = newPosition;
        }
    };

    Tape tape;
    int numberOfButtons = 6;
    float tapeTimerPosition = 0.0f;
    float speedSelectorPosition = 2.0f;
    float volumeSliderPosition = 1.0f;

    TapePlayer();
    void playTape(Tape& tapeToPlay, float lengthToPlay);
    void rewindTape(Tape& tapeToRewind, float amountToRewind);
    bool recordToTape(Tape& tape, float amountToRecord);
    bool resetTapeTimer();

};

TapePlayer::TapePlayer()
{
    std::cout << "<TapePlayer> was created." << std::endl;
}

void TapePlayer::playTape(TapePlayer::Tape& tapeToPlay, float lengthToPlay)
{
    float startingPosition = tapeToPlay.currentPosition;

    tapeToPlay.currentPosition += lengthToPlay;

    if (tapeToPlay.currentPosition > tapeToPlay.length)
    {
        tapeToPlay.currentPosition = tapeToPlay.length;
    }

    tapeTimerPosition += tapeToPlay.currentPosition - startingPosition;
}

void TapePlayer::rewindTape(TapePlayer::Tape& tapeToRewind, float amountToRewind)
{
    tapeToRewind.currentPosition -= amountToRewind;

    if (tapeToRewind.currentPosition < 0.0f)
    {
        tapeToRewind.currentPosition = 0.0f;
    }

    tapeTimerPosition -= amountToRewind;

    if (tapeTimerPosition < 0.0f)
    {
        tapeTimerPosition = 0.0f;
    }
}

bool TapePlayer::recordToTape(TapePlayer::Tape& tapeToRecord, float amountToRecord)
{
    if (tapeToRecord.currentPosition == tapeToRecord.length)
    {
        return false;
    }

    float startingPosition = tapeToRecord.currentPosition;

    tapeToRecord.currentPosition -= amountToRecord;

    if (tapeToRecord.currentPosition > tapeToRecord.length)
    {
        tapeToRecord.currentPosition = tapeToRecord.length;
    }

    tapeTimerPosition += tapeToRecord.currentPosition - startingPosition;

    return true;
}

bool TapePlayer::resetTapeTimer()
{
    std::cout << "TapePlayer::resetTapeTimer() called.  Tape timer reset to 0.0 from " <<
        tapeTimerPosition << std::endl;
    tapeTimerPosition = 0.0f;
    return true;
}

/*
5)
 */

struct Display
{
    int numberOfPixels = 2073600;
    float brightness = 0.5f;
    float widthInInches = 6.5f;
    float heightInInches = 4.0f;
    float powerConsumedInWatts = 9.0f;

    Display();
    void updatePixels();
    void clearPixels();
    void setBrightness(float newBrightnessValue);
};

Display::Display()
{
    std::cout << "<Display> was created." << std::endl;
}

void Display::updatePixels()
{
    std::cout << "Display::updatePixels() called.  Successfully updated " << numberOfPixels <<
        " pixels." << std::endl;
}

void Display::clearPixels()
{
    std::cout << "Display::clearPixels() called.  Successfully cleared " << numberOfPixels <<
        " pixels." << std::endl;
}

void Display::setBrightness(float newBrightnessValue)
{
    brightness = newBrightnessValue;
    std::cout << "Display::setBrightness(): Display brightness is now set to " << brightness << std::endl;
}

/*
6)
 */

struct WiFiAdapter
{
    float frequency = 5000.0f;
    float uploadSpeed = 12.0f;
    float downloadSpeed = 40.0f;
    int channel = 11;
    float powerConsumedInWatts = 1.0f;

    WiFiAdapter();
    void connectToAccessPoint();
    float uploadData(float amountToUpload);
    float  downloadData(float amountToDownload);
};

WiFiAdapter::WiFiAdapter()
{
    std::cout << "<WiFiAdapter> was created." << std::endl;
}

void WiFiAdapter::connectToAccessPoint()
{
    std::cout << "WiFiAdapter::connectToAccessPoint() called.  Connected to access point on channel " <<
        channel << std::endl;
}

float WiFiAdapter::uploadData(float amountToUpload)
{
    std::cout << "WiFiAdapter::uploadData(): Uploading " << amountToUpload <<
        " megabits of data at " << uploadSpeed << " megabits per second." << std::endl;
    return amountToUpload / uploadSpeed;
}

float WiFiAdapter::downloadData(float amountToDownload)
{
    std::cout << "WiFiAdapter::downloadData(): Downloading " << amountToDownload <<
        " megabits of data at at " << downloadSpeed << " megabits per second." << std::endl;
    return amountToDownload / downloadSpeed;
}

/*
7)
 */

struct AudioOutputSystem
{
    float volumeLevel = 0.5f;
    int sampleRate = 44100;
    int bitDepth = 16;
    int numberOfOutputChannels = 2;
    float powerConsumedInWatts = 4.0f;

    AudioOutputSystem();
    void outputAudio();
    void receiveAudioInput();
    void setVolumeLevel(float newVolumeLevel);
};

AudioOutputSystem::AudioOutputSystem()
{
    std::cout << "<AudioOutputSystem> was created." << std::endl;
}

void AudioOutputSystem::outputAudio()
{
    std::cout << "AudioOutputSystem::outputAudio() called.  Outputting audio at a " <<
        sampleRate << "Hz, " << bitDepth << "-bit." << std::endl;
}

void AudioOutputSystem::receiveAudioInput()
{
    std::cout << "AudioOutputSystem::receiveAudioInput() called" << std::endl;
}

void AudioOutputSystem::setVolumeLevel(float newVolumeLevel)
{
    std::cout << "AudioOutputSystem::setVolumeLevel(): Changing volume from " <<
        volumeLevel << " to " << newVolumeLevel << std::endl;
    volumeLevel = newVolumeLevel;
}

/*
8)
 */

struct CPU
{
    float clockSpeedInGHz = 3.5f;
    int numberOfCores = 4;
    int numberOfThreads = 12;
    float cacheSizeInMB = 6.0f;
    float powerConsumedInWatts = 10.0f;

    CPU();
    void fetchInstructions();
    float executeInstructions(float sizeOfInstructions);
    void sendDataToRAM();
};

CPU::CPU()
{
    std::cout << "<CPU> was created." << std::endl;
}

void CPU::fetchInstructions()
{
    std::cout << "CPU::fetchInstructions() called" << std::endl;
}

float CPU::executeInstructions(float sizeOfInstructions)
{
    std::cout << "CPU::executeInstructions(): CPU processing " << sizeOfInstructions <<
        "KB of instructions at " << clockSpeedInGHz << "GHz." << std::endl;
    return sizeOfInstructions / clockSpeedInGHz;
}

void CPU::sendDataToRAM()
{
    std::cout << "CPU::sendDataToRAM() called" << std::endl;
}

/*
9)
 */

struct RAM
{
    int capacityInBytes = 40000;
    float clockSpeedInMHz = 1600.0f;
    int busWidthInBits = 64;
    int numPins = 168;
    float powerConsumedInWatts = 3.0f;

    RAM();
    bool writeToMemory(int dataToWrite);
    void clearMemory();
    void sendDataToCPU();
};

RAM::RAM()
{
    std::cout << "<RAM> was created." << std::endl;
}

bool RAM::writeToMemory(int dataToWrite)
{
    if (dataToWrite > capacityInBytes)
    {
        std::cout << "Not enough memory to write " << dataToWrite << " byes of data. " <<
            abs(capacityInBytes - dataToWrite) << " more bytes of memory required." << std::endl;
        return false;
    }

    std::cout << dataToWrite << " bytes of data written to memory successfully." << std::endl;
    return true;
}

void RAM::clearMemory()
{
    std::cout << "RAM::clearMemory() called" << std::endl;
}

void RAM::sendDataToCPU()
{
    std::cout << "RAM::sendDataToCPU() called" << std::endl;
}

/*
10)
 */

struct PortableVideoGameSystem
{
    Display display;
    WiFiAdapter wifiAdapter;
    AudioOutputSystem audioOutput;
    CPU cpu;
    RAM memory;

    PortableVideoGameSystem();
    void loadSoftware();
    void sendImageToDisplay();
    void sendSoundToSpeakers();
};

PortableVideoGameSystem::PortableVideoGameSystem()
{
    std::cout << "<PortableVideoGameSystem> was created." << std::endl;
}

void PortableVideoGameSystem::loadSoftware()
{
    std::cout << "PortableVideoGameSystem::loadSoftware() called" << std::endl;
}

void PortableVideoGameSystem::sendImageToDisplay()
{
    std::cout << "PortableVideoGameSystem::sendImageToDisplay() called" << std::endl;
}

void PortableVideoGameSystem::sendSoundToSpeakers()
{
    std::cout << "PortableVideoGameSystem::sendSoundToSpeakers() called." << std::endl;
    audioOutput.outputAudio();
}

#include <iostream>
int main()
{
    Example::main();
    std::cout << std::endl;

    Chameleon cham;
    cham.changeColor(100, 140, 50);
    std::cout << "This Chameleon just ran " << cham.run(15.0f, 60.0) << " units." << std::endl;
    std::cout << "This Chameleon has " << cham.numberOfTeeth << " teeth." << std::endl;
    std::cout << "This Chameleon has " << cham.numberOfScales << " scales." << std::endl;
    std::cout << std::endl;

    FastFoodRestaurant burgerKing;
    burgerKing.makeFries(67);
    burgerKing.makeBurger(28);
    burgerKing.restockSupplies(35, 24);
    std::cout << "This restaurant makes $" << burgerKing.profitPerBurger << " profit per burger." << std::endl;
    std::cout << "This restaurant makes $" << burgerKing.profitPerPotato << " profit per potato." << std::endl;
    std::cout << std::endl;

    ElectricGuitar axe;
    std::cout << "This guitar has a neck that is " << axe.neckLength << " inches long." << std::endl;
    std::cout << "This guitar has " << axe.numberOfPickups << " pickups and " << axe.numberOfStrings << " strings." << std::endl;
    axe.setVolume(0.9f);
    axe.setTone(0.5f);
    axe.outputSound();
    std::cout << std::endl;

    TapePlayer walkman;
    std::cout << "This tape player's tape is " << walkman.tape.length << " minutes long." << std::endl;
    std::cout << "This tape player has " << walkman.numberOfButtons << " buttons." << std::endl;
    walkman.playTape(walkman.tape, 35.6f);
    walkman.resetTapeTimer();
    std::cout << std::endl;

    Display display;
    std::cout << "This display is " << display.widthInInches << " inches wide by " <<
        display.heightInInches << " inches tall." << std::endl;
    display.updatePixels();
    display.clearPixels();
    display.setBrightness(0.75f);
    std::cout << std::endl;

    WiFiAdapter wifiAdapter;
    wifiAdapter.connectToAccessPoint();
    wifiAdapter.uploadData(1000.50f);
    wifiAdapter.downloadData(43646.60f);
    std::cout << "This WiFi Adapter operates at a frequency of " << wifiAdapter.frequency << "MHz." << std::endl;
    std::cout << std::endl;

    AudioOutputSystem audioOut;
    audioOut.setVolumeLevel(0.9f);
    audioOut.outputAudio();
    std::cout << "This audio system consumes " << audioOut.powerConsumedInWatts <<
        " watts of power." << std::endl;
    std::cout << std::endl;

    CPU cpu;
    cpu.executeInstructions(1.567f);
    std::cout << "This CPU has " << cpu.numberOfCores << " cores." << std::endl;
    std::cout << std::endl;

    RAM ram;
    std::cout << "This RAM's capacity is " << ram.capacityInBytes << " bytes." << std::endl;
    ram.writeToMemory(35000);
    ram.writeToMemory(50000);
    std::cout << "This RAM's clock speed is " << ram.clockSpeedInMHz << "MHz." << std::endl;
    std::cout << std::endl;

    PortableVideoGameSystem nintendoSwitch;
    nintendoSwitch.sendSoundToSpeakers();
    std::cout << std::endl;

    std::cout << "good to go!" << std::endl;
}
