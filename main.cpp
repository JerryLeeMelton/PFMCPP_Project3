/*
 Project 3 - Part 3 / 5
 video: Chapter 2 - Part 8
 Constructors tasks

 Create a branch named Part3

 On a new branch:

 1) Add a constructor for each User-Defined-Type.
 
 2) amend some of your UDT's member functions to print out something interesting via std::cout
 
 3) Instantiate 1 or 2 instances of each of your user-defined types in the main function at the bottom of that file,

 4) call some of your UDT's amended member functions in main().
 
 5) add some std::cout statements in main() that print out your UDT's member variable values or values returned from your UDT member functions (if they return values)
 
 After you finish defining each type/function:
 click the [run] button.  Clear up any errors or warnings as best you can.
 
 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 Make a pull request after you make your first commit and pin the pull request link to our DM thread.

 send me a DM to check your pull request

 Wait for my code review.
 
 example:
 */

#include <iostream>
namespace Example 
{
struct UDT  // my user defined type named 'UDT'
{
    int a; //a member variable
    UDT() { a = 0; }             //1) the constructor
    void printThing()            //the member function
    {
        std::cout << "UDT::printThing() " << a << std::endl;  //2) printing out something interesting
    }
};

int main()
{
    UDT foo;              //3) instantiating a UDT named 'foo' in main()
    foo.printThing();     //4) calling a member function of the UDT instance.
    
    //5) a std::cout statement accessing foo's member variable.
    //It also demonstrates a 'ternary expression', which is syntactic shorthand for an 'if/else' expression
    std::cout << "Is foo's member var 'a' equal to 0? " << (foo.a == 0 ? "Yes" : "No") << "\n";
    
    return 0;
}
}

//insert Example::main() into main() of user's repo.



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

    float run(float speed, float timeToRun);
    void changeColor(int newRedValue, int newGreenValue, int newBlueValue);
    void flickTongue(float flickDistance, int numberOfFlicks);
};

float Chameleon::run(float speed, float timeToRun)
{
    return speed * timeToRun;
}

void Chameleon::changeColor(int newRedValue, int newGreenValue, int newBlueValue)
{
    color.setColor(newRedValue, newGreenValue, newBlueValue);
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
    float profitPerBurger = 1.60f;
    float profitPerPotato = 0.49f;
    float profitsPerWeek = 0.0f;
    int burgersUsedPerWeek = 0;
    int potatoesUsedPerWeek = 0;
    int burgersInFreezer = 100;
    int potatoesInPantry = 100;

    bool makeBurger(int numBurgers);
    bool makeFries(int potatoesToUse);
    void restockSupplies(int newPotatoes, int newBurgers);
    bool makeChameleonBurger(Chameleon& chameleon);
};

bool FastFoodRestaurant::makeBurger(int burgersToMake)
{
    if (burgersInFreezer > 0)
    {
        burgersInFreezer -= burgersToMake;
        return true;
    }

    return false;
}

bool FastFoodRestaurant::makeFries(int potatoesToUse)
{
    if (potatoesToUse < potatoesInPantry)
    {
        potatoesInPantry -= potatoesToUse;
        return true;
    }

    return false;
}

void FastFoodRestaurant::restockSupplies(int newPotatoes, int newBurgers)
{
    potatoesInPantry += newPotatoes;
    burgersInFreezer += newBurgers;
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

    void outputSound();
    void setVolume(float newVolumePosition);
    void setTone(float newTonePosition);
};

void ElectricGuitar::outputSound()
{
    std::cout << "ElectricGuitar::outputSound() called" << std::endl;
}

void ElectricGuitar::setVolume(float newVolumePosition)
{
    volumeKnobPosition = newVolumePosition;
}

void ElectricGuitar::setTone(float newTonePosition)
{
    toneKnobPosition = newTonePosition;
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

    void playTape(Tape& tapeToPlay, float lengthToPlay);
    void rewindTape(Tape& tapeToRewind, float amountToRewind);
    bool recordToTape(Tape& tape, float amountToRecord);
    bool resetTapeTimer();

};

void TapePlayer::playTape(TapePlayer::Tape& tapeToPlay, float lengthToPlay)
{
    float startingPosition = tapeToPlay.currentPosition;

    tapeToPlay.currentPosition -= lengthToPlay;

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

    void updatePixels();
    void clearPixels();
    void setBrightness(float newBrightnessValue);
};

void Display::updatePixels()
{
    std::cout << "Display::updatePixels() called" << std::endl;
}

void Display::clearPixels()
{
    std::cout << "Display::clearPixels() called" << std::endl;
}

void Display::setBrightness(float newBrightnessValue)
{
    brightness = newBrightnessValue;
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

    void connectToAccessPoint();
    float uploadData(float amountToUpload);
    float  downloadData(float amountToDownload);
};

void WiFiAdapter::connectToAccessPoint()
{
    std::cout << "WiFiAdapter::connectToAccessPoint() called" << std::endl;
}

float WiFiAdapter::uploadData(float amountToUpload)
{
    return amountToUpload / uploadSpeed;
}

float WiFiAdapter::downloadData(float amountToDownload)
{
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

    void outputAudio();
    void receiveAudioInput();
    void setVolumeLevel(float newVolumeLevel);
};

void AudioOutputSystem::outputAudio()
{
    std::cout << "AudioOutputSystem::outputAudio() called" << std::endl;
}

void AudioOutputSystem::receiveAudioInput()
{
    std::cout << "AudioOutputSystem::receiveAudioInput() called" << std::endl;
}

void AudioOutputSystem::setVolumeLevel(float newVolumeLevel)
{
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

    void fetchInstructions();
    float executeInstructions(float sizeOfInstructions);
    void sendDataToRAM();
};

void CPU::fetchInstructions()
{
    std::cout << "CPU::fetchInstructions() called" << std::endl;
}

float CPU::executeInstructions(float sizeOfInstructions)
{
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
    float capacityInMB = 4.0f;
    float clockSpeedInMHz = 1600.0f;
    int busWidthInBits = 64;
    int numPins = 168;
    float powerConsumedInWatts = 3.0f;

    bool writeToMemory(int dataToWrite);
    void clearMemory();
    void sendDataToCPU();
};

bool RAM::writeToMemory(int dataToWrite)
{
    if (dataToWrite < capacityInMB)
    {
        return true;
    }

    return false;
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

    void loadSoftware();
    void sendImageToDisplay();
    void sendSoundToSpeakers();
};

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
    std::cout << "PortableVideoGameSystem::sendSoundToSpeakers() called" << std::endl;
}

#include <iostream>
int main()
{
    std::cout << "good to go!" << std::endl;
}
