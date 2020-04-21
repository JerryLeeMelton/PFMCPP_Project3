/*
 Project 3 - Part 5 / 5
 video: Chapter 2 - Part 10
 Scope and Lifetime tasks
 
Create a branch named Part5

 video covered:
    variable scope and lifetime relative to { }
    while loops
    for loops()
 
 tasks
 
 1) add some new member functions to your types. 
 
 2) use while() or for() loops to do something interesting inside these new member functions.
         a) for example: have a loop that modifies a member variable of some object created outside the loop.
         b) when that member variable reaches a certain threshold, return it mid-loop.
         c) maybe use function parameters to control the starting value of that member variable or control the threshold
         
 3) call those new member functions in main()
 
 4) use std::cout statements to print out information about what your loops did.
 
 5) click the [run] button.  Clear up any errors or warnings as best you can.
 
 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
Make a pull request after you make your first commit and pin the pull request link to our DM thread.

send me a DM to check your pull request

 Wait for my code review.
 
 example:
 */

#include <iostream>
namespace Example {
struct Bar 
{ 
    int num = 0; 
    Bar(int n) : num(n) { } 
};
struct Foo
{
    Bar scopeLifetimeFunc( int threshold, int startingVal ) //3), 4c) 
    {
        Bar bar(startingVal);                //4a)
        while( bar.num < threshold )         //4a) 
        { 
            bar.num += 1;                    //4a)
            
            if( bar.num >= threshold )       //4b)
                return bar;
        }
        
        return Bar {-1}; //if your startingValue >= threshold, the while loop never runs
    }
};

int main()
{
    Foo foo;
    auto bar = foo.scopeLifetimeFunc(3, 1);        //5) 
    
    std::cout << "bar.num: " << bar.num << std::endl;     //6) 
    return 0;
}
}

//call Example::main() in main()





 /*
 1)
  */

struct Chameleon
{
    struct Color
    {
        int red;
        int green;
        int blue;
        int alpha;

        Color()  :
        red(0),
        green(135),
        blue(25),
        alpha(255)
        {
            
        }

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

    float length {5.0f};
    float weight {8.0f};
    Color color;
    int numberOfTeeth;
    int numberOfScales;
    float totalTongueFlickDistance;

    Chameleon();
    float run(float speed, float timeToRun);
    void changeColor(int newRedValue, int newGreenValue, int newBlueValue);
    void flickTongue(float flickDistance, int numberOfFlicks);
    void eat(int fliesToEat);
};

Chameleon::Chameleon() :
numberOfTeeth(35),
numberOfScales(4800),
totalTongueFlickDistance(0)
{
    std::cout << "<Chameleon> was created." << std::endl;
}

float Chameleon::run(float speed, float timeToRun)
{
    return speed * timeToRun;
}

void Chameleon::changeColor(int newRedValue, int newGreenValue, int newBlueValue)
{
    std::cout << "Chamelon: Current RGB color is (" <<
        color.red << ", " << color.green << ", " << color.blue << ")" << std::endl;

    color.setColor(newRedValue, newGreenValue, newBlueValue);

    std::cout << "Chameleon changed color!  New RGB value is (" <<
        newRedValue << ", " << newGreenValue << ", " << newBlueValue << ")" << std::endl;
}

void Chameleon::flickTongue(float flickDistance, int numberOfFlicks)
{
    totalTongueFlickDistance += numberOfFlicks * flickDistance;

    std::cout << "Chameleon flicked its tongue " << numberOfFlicks << 
        " times! Total tongue flick distance is now " << totalTongueFlickDistance <<
        " inches." << std::endl;
}

void Chameleon::eat (int fliesToEat) 
{
    float weightGained = 0.0f;

    std::cout << "Chameleon is eating " << fliesToEat << " flies!" << std::endl;

    for(int fliesEaten = 0; fliesEaten < fliesToEat; ++fliesEaten)
    {
        weightGained += 0.1f;

        std::cout << "Ate a fly and gained 0.1" << std::endl;
    }

    std::cout << "Chameleon gained a total of " << weightGained << std::endl;
    weight += weightGained;
}

/*
2)
 */

struct FastFoodRestaurant
{
    float profitPerBurger {1.65f};
    float profitPerPotato {0.49f};
    float totalProfits {0.0f};
    int burgersSold = 0;
    int potatoesSold = 0;
    int burgersInFreezer;
    int potatoesInPantry;

    FastFoodRestaurant();
    bool makeBurger(int numBurgers);
    bool makeFries(int potatoesToUse);
    void restockSupplies(int newPotatoes, int newBurgers);
    bool makeChameleonBurger(Chameleon& chameleon);
    void calculateProft();
};

FastFoodRestaurant::FastFoodRestaurant() :
burgersInFreezer(200),
potatoesInPantry(100)
{
    std::cout << "<FastFoodRestaurant> was created." << std::endl;
}

bool FastFoodRestaurant::makeBurger(int burgersToMake)
{
    if (burgersInFreezer > 0)
    {
        burgersInFreezer -= burgersToMake;
        burgersSold += burgersToMake;

        std::cout << "Made " << burgersToMake << " burgers. Burgers left in freezer: " << burgersInFreezer << ". Burgers sold: " << burgersSold << std::endl;

        return true;
    }

    return false;
}

bool FastFoodRestaurant::makeFries(int potatoesToUse)
{
    if (potatoesToUse < potatoesInPantry)
    {
        potatoesInPantry -= potatoesToUse;
        potatoesSold += potatoesToUse;

        std::cout << "Made fries using " << potatoesToUse << " potatoes. Potatoes left in freezer: " << potatoesInPantry << ". Potatoes sold: " << potatoesSold << std::endl;

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

void FastFoodRestaurant::calculateProft()
{
    while(burgersSold > 0)
    {
        totalProfits += profitPerBurger;
        burgersSold -= 1;
    }

    while(potatoesSold > 0)
    {
        totalProfits += profitPerPotato;
        potatoesSold -= 1;
    }
}

/*
3)
 */

struct ElectricGuitar
{
    float neckLength;
    float volumeKnobPosition = 1.0f;
    float toneKnobPosition = 1.0f;
    int numberOfPickups;
    int numberOfStrings;

    ElectricGuitar();
    void outputSound();
    void setVolume(float newVolumePosition);
    void setTone(float newTonePosition);
    void setVolumeGradually(float newVolumePosition);
};

ElectricGuitar::ElectricGuitar() :
neckLength(22.5f),
numberOfPickups(3),
numberOfStrings(6)
{
    std::cout << "<ElectricGuitar> was created. This guitar has a " << neckLength << 
        " inch neck and " << numberOfPickups << " pickups." << std::endl;
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

void ElectricGuitar::setVolumeGradually(float newVolumePosition)
{
    std::cout << "ElectricGuitar::setVolumeGradually(): Volume knob is starting at " << volumeKnobPosition << std::endl;

    if(newVolumePosition > volumeKnobPosition)
    {
        while(newVolumePosition > volumeKnobPosition)
        {
            volumeKnobPosition += 0.05f;
            std::cout << "Moved volume knob down a bit. Current knob position: " << volumeKnobPosition << std::endl;
        }
    }
    else 
    {
        while(newVolumePosition < volumeKnobPosition)
        {
            volumeKnobPosition -= 0.05f;
            std::cout << "Moved volume knob up a bit. Current knob position: " << volumeKnobPosition << std::endl;
        }
    }
}

/*
4)
 */

struct TapePlayer
{
    struct Tape
    {
        float length;
        float currentPosition;
        bool isWritable;

        Tape() :
        length(60.f),
        currentPosition(0.0f),
        isWritable(true)
        {
            std::cout << "<Tape> was created." << std::endl;
        }

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
    float tapeTimerPosition {0.0f};
    float speedSelectorPosition;
    float volumeSliderPosition;

    TapePlayer();
    void playTape(Tape& tapeToPlay, float lengthToPlay);
    void rewindTape(Tape& tapeToRewind, float amountToRewind);
    bool recordToTape(Tape& tape, float amountToRecord);
    bool resetTapeTimer();
    void setVolumeSliderGradually(float newVolumePosition);
};

TapePlayer::TapePlayer() :
speedSelectorPosition(1.0f),
volumeSliderPosition(0.5f)
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

void TapePlayer::setVolumeSliderGradually(float newVolumePosition)
{
    std::cout << "TapePlayer::setVolumeSliderGradually(): Volume slider starting at " << volumeSliderPosition << std::endl;

    if(newVolumePosition > volumeSliderPosition)
    {
        while(newVolumePosition > volumeSliderPosition)
        {
            volumeSliderPosition += 0.05f;
            std::cout << "Moved volume slider up a bit. Current slider position: " << volumeSliderPosition << std::endl;
        }
    } 
    else
    {
        while(newVolumePosition < volumeSliderPosition)
        {
            volumeSliderPosition -= 0.05f;
            std::cout << "Moved volume slider down a bit. Current slider position: " << volumeSliderPosition << std::endl;
        }
    }
}

/*
5)
 */

struct Display
{
    int numberOfPixels = 2073600;
    float brightness {0.5f};
    float widthInInches;
    float heightInInches;
    float powerConsumedInWatts;

    Display();
    void updatePixels();
    void clearPixels();
    void setBrightness(float newBrightnessValue);
};

Display::Display() : 
widthInInches(6.5f),
heightInInches(4.0f),
powerConsumedInWatts(9.0f)
{
    std::cout << "<Display> was created." << "It is " << widthInInches << 
        " inches wide by " << heightInInches << " inches high." << std::endl;
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
    float frequency;
    float uploadSpeed {12.0f};
    float downloadSpeed {40.0f};
    int channel;
    float powerConsumedInWatts {1.0f};

    WiFiAdapter();
    void connectToAccessPoint();
    float uploadData(float amountToUpload);
    float  downloadData(float amountToDownload);
};

WiFiAdapter::WiFiAdapter() :
frequency(5000.0f),
channel(11)
{
    std::cout << "<WiFiAdapter> was created. This adapter operates at " << 
        frequency << "Hz on channel " << channel << std::endl;
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
    float volumeLevel {0.5f};
    int sampleRate;
    int bitDepth;
    int numberOfOutputChannels = 2;
    float powerConsumedInWatts {4.0f};

    AudioOutputSystem();
    void outputAudio();
    void receiveAudioInput();
    void setVolumeLevel(float newVolumeLevel);
};

AudioOutputSystem::AudioOutputSystem() :
sampleRate(44100),
bitDepth(16)
{
    std::cout << "<AudioOutputSystem> was created. This audio system consumes " <<
        powerConsumedInWatts << " watts of power." << std::endl;
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
    float clockSpeedInGHz;
    int numberOfCores;
    int numberOfThreads;
    float cacheSizeInMB;
    float powerConsumedInWatts {10.0f};

    CPU();
    void fetchInstructions();
    float executeInstructions(float sizeOfInstructions);
    void sendDataToRAM();
};

CPU::CPU() :
clockSpeedInGHz(3.5f),
numberOfCores(4),
numberOfThreads(12),
cacheSizeInMB(6.0f)
{
    std::cout << "<CPU> was created. This CPU has " << numberOfCores << " cores." << std::endl;
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
    float powerConsumedInWatts {3.0f};

    RAM();
    bool writeToMemory(int dataToWrite);
    void clearMemory();
    void sendDataToCPU();
};

RAM::RAM() :
capacityInBytes(40000),
clockSpeedInMHz(1600.0f)
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
    std::cout << "This Chameleon weighs " << cham.weight << std::endl;
    cham.flickTongue(2.5, 3);
    cham.flickTongue(3.0, 5);
    cham.eat(3);
    cham.eat(6);
    std::cout << "This Chameleon weighs " << cham.weight << " after eating" << std::endl;
    std::cout << std::endl;

    FastFoodRestaurant burgerKing;
    std::cout << "Initial profits: $" << burgerKing.totalProfits << std::endl;
    burgerKing.makeFries(67);
    burgerKing.makeBurger(28);
    burgerKing.restockSupplies(35, 24);
    std::cout << "This restaurant makes $" << burgerKing.profitPerBurger << " profit per burger." << std::endl;
    std::cout << "This restaurant makes $" << burgerKing.profitPerPotato << " profit per potato." << std::endl;
    burgerKing.calculateProft();
    std::cout << "Profits after sales: $" << burgerKing.totalProfits << std::endl;
    std::cout << std::endl;

    ElectricGuitar axe;
    std::cout << "This guitar has a neck that is " << axe.neckLength << " inches long." << std::endl;
    std::cout << "This guitar has " << axe.numberOfPickups << " pickups and " << axe.numberOfStrings << " strings." << std::endl;
    axe.setVolume(0.9f);
    axe.setTone(0.5f);
    axe.outputSound();
    axe.setVolumeGradually(0.3f);
    axe.setVolumeGradually(1.0f);
    std::cout << std::endl;

    TapePlayer walkman;
    std::cout << "This tape player's tape is " << walkman.tape.length << " minutes long." << std::endl;
    std::cout << "This tape player has " << walkman.numberOfButtons << " buttons." << std::endl;
    walkman.playTape(walkman.tape, 35.6f);
    walkman.resetTapeTimer();
    walkman.setVolumeSliderGradually(0.65f);
    walkman.setVolumeSliderGradually(0.45f);
    std::cout << std::endl;

    Display display;
    display.updatePixels();
    display.clearPixels();
    display.setBrightness(0.75f);
    std::cout << std::endl;

    WiFiAdapter wifiAdapter;
    wifiAdapter.connectToAccessPoint();
    wifiAdapter.uploadData(1000.50f);
    wifiAdapter.downloadData(43646.60f);
    std::cout << std::endl;

    AudioOutputSystem audioOut;
    audioOut.setVolumeLevel(0.9f);
    audioOut.outputAudio();
    std::cout << std::endl;

    CPU cpu;
    cpu.executeInstructions(1.567f);
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
