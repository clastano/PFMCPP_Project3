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
 
 1) add some new member functions to EACH of your types. 
 
 2) inside these new member functions, use while() and for() loops to do something interesting 
         a) example: have a loop that modifies a member variable of some object created outside the loop.
         b) when that member variable reaches a certain threshold, return it mid-loop.
         c) maybe use function parameters to control the starting value of that member variable or control the threshold
         
 3) call those new member functions in main()
 
 4) use std::cout statements to print out information about what your loops did.
    Your code should produce a lot of console output now.

 5) Remember to use pre-increment/decrement in your loops. 
 You can learn why post-increment/decrement is not ideal here:
 https://en.cppreference.com/w/cpp/language/operator_incdec 
 
 6) click the [run] button.  Clear up any errors or warnings as best you can.
 if your code produces a -Wpadded warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 */

#include <iostream>
namespace Example 
{
struct Bar 
{ 
    int num = 0; 
    Bar(int n) : num(n) { } 
};
struct Foo
{
    Bar scopeLifetimeFunc( int threshold, int startingVal ) //1), 2c) 
    {
        Bar bar(startingVal);                //2a)
        while( bar.num < threshold )         //2a) 
        { 
            ++bar.num;                    //2a), 5)
            std::cout << "  increasing bar.num: " << bar.num << std::endl; //4)
            if( bar.num >= threshold )       //2b)
                return bar;
        }
        
        return Bar {-1}; //if your startingValue >= threshold, the while loop never runs
    }
};

int main()
{
    Foo foo;
    auto bar = foo.scopeLifetimeFunc(3, 1);        //3) 
    
    std::cout << "bar.num: " << bar.num << std::endl;     //4) 
    return 0;
}
}

//call Example::main() in main()




struct WaterBottle
{
    WaterBottle();
    std::string chemicalContentTable;
    float capacityInOnces;
    float containedLiquidLevelInOnces;
    float currentWeightInKg;
    int transparencyPercentage;
    bool broken;
    int dirtynessPercentage;
    bool waitingForever;

    void doBreak();
    void getOldAndDirty();
    void standStill();
};

WaterBottle::WaterBottle(): // initializer list
chemicalContentTable("Nickel 9%, Cadmium 7%, Copper 3%"),
capacityInOnces(2),
containedLiquidLevelInOnces(1.4f),
currentWeightInKg(1.8f),
transparencyPercentage(58),
broken(false),
dirtynessPercentage(0),
waitingForever(false)
{
    std::cout << "WaterBottle" << std::endl;
}

void WaterBottle::doBreak()
{
    broken = true;
    std::cout << "WaterBottle broken-up" << std::endl;
}

void WaterBottle::getOldAndDirty()
{

    dirtynessPercentage++;

    if (dirtynessPercentage > 100)
    {
        dirtynessPercentage = 100;
    }
}

void WaterBottle::standStill()
{
    waitingForever = true;
}

struct Laptop
{
    Laptop();
    float displayWidth = 200;
    std::string keyboardlayout = "en.US";
    int trackpadSensitivity = 8;
    int speakersCount = 2;
    float usbPortSpeed = 3.4f;
    bool isOn;
    bool powerSaving;
    bool savedToDisk;

    long startUp();
    long shutDown();
    void goSleepMode(bool saveToDisk = true);
};

Laptop::Laptop():
isOn(false),
powerSaving(false),
savedToDisk(false)
{
    std::cout << "Laptop" << std::endl;
}

long Laptop::startUp()
{
    isOn = true;
    powerSaving = false;
    std::cout << "Laptop started." << std::endl;

    return 100;
}

long Laptop::shutDown()
{

    std::cout << "Laptop shutting down." << std::endl;

    isOn = false;

    return 50;
}

void Laptop::goSleepMode(bool saveToDisk)
{

    if (saveToDisk)
    {
        savedToDisk = true;
        std::cout << "Laptop going sleep mode. saving to disk." << std::endl;
    }

    powerSaving = true;
}

struct Refrigerator
{
    Refrigerator();
    float thermostatLowerThresholdInCelsius = 3.f;
    bool thermostatInternalError = false;
    float totalVolumeInOnces;
    float powerConsumptionInWatt;
    float currentTemperatureInCelsius = 8.1f;
    std::string caseMaterial = "stainless steel";

    float lowerTemperature(float degrees = 1.f);
    bool stopTemporarily();
    void switchLightOn();
};

Refrigerator::Refrigerator():
totalVolumeInOnces(2.2f),
powerConsumptionInWatt(.7f)
{
    std::cout << "Refrigerator" << std::endl;
}

float Refrigerator::lowerTemperature(float degrees)
{

    currentTemperatureInCelsius -= degrees;

    if (currentTemperatureInCelsius < thermostatLowerThresholdInCelsius)
    {
        thermostatInternalError = true;
    
        std::cout << "Refrigerator got a thermostat error." << std::endl;

        return thermostatLowerThresholdInCelsius;
    }

    return currentTemperatureInCelsius;
}

bool Refrigerator::stopTemporarily()
{

    if (thermostatInternalError)
    {
    
        std::cout << "Refrigerator: grave ERROR. can't stop engine." << std::endl;
        return false; // can't stop
    }

    powerConsumptionInWatt = 0;

    return true;
}

void Refrigerator::switchLightOn()
{
    powerConsumptionInWatt += 2.3f;
}

struct Guitar
{
    Guitar();
    int stringCount = 6;
    std::string lowerNoteIdentifier = "E1";
    int outputJackSlotsCount = 1;
    int bodyMaterialId = 789;
    std::string bodyShapeType = "Tele";
    float collectedDust = .0f;
    float dustCollectionDailyRate = .3722f;
    bool inTune = true;
    bool humbuckerOn = false;

    void play();
    float collectDust(float days = 365);
    void soundTerrible(int howTerrible = 9);
};

Guitar::Guitar()
{
    std::cout << "Guitar" << std::endl;
}

void Guitar::play()
{
    humbuckerOn = true;
}

float Guitar::collectDust(float days)
{

    collectedDust += days * dustCollectionDailyRate;
    
    std::cout << "Guitar collected dust for " << days << " days." << std::endl;

    return collectedDust;
}

void Guitar::soundTerrible(int howTerrible)
{
    if (howTerrible > 5)
    {
        std::cout << "Guitar going out of tune." << std::endl;
        inTune = false;
    }
}

struct Manufacturer
{
    Manufacturer();
    std::string name;
    std::string location;
    int employeesCount;
    float yearlyRevenewAsBillionDollars;
    std::string financialStatus;
    long lastCreatedProductId;
    std::string currentPrototypeName;

    long createProduct(std::string modelName);
    void sellBrokenStuff();
    float makeBigMoney();
};

Manufacturer::Manufacturer():
name("Foo Instruments"),
location("a place"),
employeesCount(487),
yearlyRevenewAsBillionDollars(.1f),
financialStatus("healthy"),
lastCreatedProductId(0),
currentPrototypeName("")
{
    std::cout << "Manufacturer" << std::endl;
    
    std::cout << "Manufacturer name: [" << name << "]" << std::endl;
    std::cout << "Manufacturer location: [" << location << "]" << std::endl;
    std::cout << "Manufacturer financialStatus: [" << financialStatus << "]" << std::endl;
    std::cout << "Manufacturer yearly revenew: [" << yearlyRevenewAsBillionDollars << "]" << std::endl;
}

long Manufacturer::createProduct(std::string modelName)
{

    currentPrototypeName = "proto_" + modelName;

    return ++lastCreatedProductId;
}

void Manufacturer::sellBrokenStuff()
{
    std::cout << "Manufacturer - selling broken stuff" << std::endl;
}

float Manufacturer::makeBigMoney()
{
    return 2.8f;
}

struct SynthEngine
{
    SynthEngine();
    std::string synthesisType = "Virtual Analog";
    int polyphonyAmount = 8;
    float currentVolume = .7f;
    int supportedNoteMaxPitchInHertz = 10000;
    float filterResonanceAmount = .765f;
    std::string currentNoiseType;
    float warmingRatio;
    float warmingSpeed;
    bool portamentoOn;

    void makeNoise(int noiseType = 1);
    bool warmUp(float targetTemperatureInCelsius);
    void switchPortamentoOn();
};

SynthEngine::SynthEngine():
currentNoiseType(""),
warmingRatio(0.8f),
warmingSpeed(7.f),
portamentoOn(false)
{
    std::cout << "SynthEngine" << std::endl;
    
    std::cout << "SynthEngine currentNoiseType: [" << currentNoiseType << "]" << std::endl;
    std::cout << "SynthEngine warmingRatio: [" << warmingRatio << "]" << std::endl;
    std::cout << "SynthEngine warmingSpeed: [" << warmingSpeed << "]" << std::endl;
    std::cout << "SynthEngine portamento is on ?: [" << portamentoOn << "]" << std::endl;
}

void SynthEngine::makeNoise(int noiseType)
{
    if (noiseType == 1)
    {
        currentNoiseType = "white";
        
        std::cout << "SynthEngine - generating white noise." << std::endl;
    }
    else if (noiseType == 2)
    {
        currentNoiseType = "brown";
        
        std::cout << "SynthEngine - generating white brown." << std::endl;
    }
    else
    {
        currentNoiseType = "pink";
        
        std::cout << "SynthEngine - generating white pink." << std::endl;
    }
}

bool SynthEngine::warmUp(float targetTemperatureInCelsius)
{
    
    std::cout << "SynthEngine - warming up." << std::endl;
    
    if (warmingRatio * warmingSpeed >= targetTemperatureInCelsius)
    {
        
        std::cout << "SynthEngine - warmed-up completely." << std::endl;
        return true;
    }

    return false;
}

void SynthEngine::switchPortamentoOn()
{
    portamentoOn = true;
}

struct Case
{
    Case();

    int height = 12;
    int width = 26;
    int knobsCount = 14;
    int frontPanelColorIdentifier = 89;
    std::string material = "wood and metal";
    bool broken = false;
    bool multipartBreak = false;
    long blinkingInterval = 5000;
    long sleepInterval = 0;

    void doBreak(int partCount = 2);
    void blinkDisplayLight(long intervalMillis = 2000);
    void stopResponding(long millis = 1000);
};

Case::Case()
{
    std::cout << "Case" << std::endl;
}

void Case::doBreak(int partCount)
{

    broken = true;

    if (partCount > 2)
    {
        multipartBreak = true;
        
        std::cout << "Case broke to " << partCount << " parts." << std::endl;
    }
}

void Case::blinkDisplayLight(long intervalMillis)
{
    blinkingInterval = intervalMillis;
}

void Case::stopResponding(long millis)
{
    sleepInterval = millis;
}

struct Distributor
{
    Distributor();

    struct Shop
    {
        Shop();

        std::string ownerName;
        std::string address;
        long ranking;
        int attendentCount;
        int showRoomArea = 230;
        float moneyBalance = 100.f;
        bool open = false;
        std::string mostRecentBrand = "";

        void prepareProductCatalog();
        void openDoors();
        void addProductBrand(std::string brand);
    };

    std::string name = "Music Everywhere";
    std::string location = "anotherPlace";
    int shopCount = 23;
    float customerBaseSatisfaction = .78f;
    int montlyShippingCount = 1028;
    float orderPrice = 45.f;
    long profilationIdOffset = 10;

    float applyBlackFridayDiscount(long orderId);
    long profileCustomer(long customerId);
    void openNewShop(Shop shop);
};

Distributor::Distributor()
{
    std::cout << "Distributor" << std::endl;
}

Distributor::Shop::Shop():
ownerName("John Doe"),
address("LA"),
ranking(0),
attendentCount(3)
{
    std::cout << "Shop" << std::endl;
}

void Distributor::Shop::prepareProductCatalog()
{

    if (moneyBalance > 5.f)
    {
        const float catalogCost = 3.f;

        std::cout << "Shop - spending " << catalogCost << " to prepare a product catalog." << std::endl;
        
        moneyBalance -= catalogCost; // catalog cost
    }
}

void Distributor::Shop::openDoors()
{
    open = true;
}

void Distributor::Shop::addProductBrand(std::string brand)
{
    mostRecentBrand = brand;

    std::cout << "Shop - added a new brand: [" << brand << "]" << std::endl;
}

float Distributor::applyBlackFridayDiscount(long orderId)
{

    if (orderId == 1000)
    {
        std::cout << "Distributor - applied discount" << std::endl;
        return 0.f;
    }
    else
    {
        std::cout << "Distributor - could not apply discount." << std::endl;
    }

    return .7f * orderPrice;
}

long Distributor::profileCustomer(long customerId)
{
    customerBaseSatisfaction *= .2f;

    return profilationIdOffset + customerId;
}

void Distributor::openNewShop(Shop shop)
{
    shop.openDoors();
}

struct InternalSequencer
{
    InternalSequencer();

    struct MidiClip
    {
        MidiClip();

        std::string clipName = "CHORUS";
        int midiChannel = 0;
        int lengthInBars = 4;
        bool cloneable = true;
        bool allow = true;
        int currentBaseNote = 0;
        int baseNoteBeforeTransposition = 0;

        void resize(int newDurationInBars);
        void transpose(bool destructive = false);
        void setMidiChannel(int midiChannel);
    };

    struct PianoRoll
    {
        PianoRoll();

        MidiClip currentClip;
        float editorViewPortStartPosition = 0;
        float editorViewPortZoomScalePercentage = 30.f;
        int backgroundColorId = 1;
        bool logMidiEvents = true;
        bool allEventsAreSelected = false;
        int higherNote = 100;

        void selectAllEvents();
        void deleteHigherNote();
        void increaseZoom(float percentaceAmount);
    };

    PianoRoll pianoRoll;

    int maxBarsSupportedNumber = 9999;
    int songDurationInSecs = 7899;
    int currentlySelectedTrack = 3;
    int currentlySelectedPattern = 9;
    int midiBufferSize = 1024;
    long currentPlaybackPosition = 0;
    float speedMultiplier = 1.f;

    void playback(long timePosition = 0, float speedMultiplier = 1.f);
    long pause();
    long stop();

    void editInPianoRoll(MidiClip midiClip);
};

InternalSequencer::InternalSequencer()
{
    std::cout << "InternalSequencer" << std::endl;
}

InternalSequencer::MidiClip::MidiClip():
clipName("CHORUS"),
midiChannel(0),
lengthInBars(4),
cloneable(true),
allow(true),
currentBaseNote(0),
baseNoteBeforeTransposition(0)
{
    std::cout << "MidiClip" << std::endl;
    
    std::cout << "MidiClip clipName: [" << clipName << "]" << std::endl;
    std::cout << "MidiClip midiChannel: [" << midiChannel << "]" << std::endl;
    std::cout << "MidiClip lengthInBars: [" << lengthInBars << "]" << std::endl;
}

InternalSequencer::PianoRoll::PianoRoll():
editorViewPortStartPosition(0),
editorViewPortZoomScalePercentage(30.f),
backgroundColorId(1)
{
    std::cout << "PianoRoll" << std::endl;
}

void InternalSequencer::MidiClip::resize(int newDuration)
{
    lengthInBars = newDuration;
}

void InternalSequencer::MidiClip::transpose(bool destructive)
{
    if (destructive)
    {
        std::cout << "MidiClip - DESTRUCTIVE transposition" << std::endl;

        baseNoteBeforeTransposition = -1; // less than 0 to invalidate undo cache
    }
    else
    {
        std::cout << "MidiClip - non destructive transposition" << std::endl;

        baseNoteBeforeTransposition = currentBaseNote;
    }

    currentBaseNote += 12; // 1 octave
}

void InternalSequencer::MidiClip::setMidiChannel(int midiChnl)
{
    std::cout << "MidiClip - setting midi channel to " << midiChnl << std::endl;

    midiChannel = midiChnl;
}

void InternalSequencer::PianoRoll::selectAllEvents()
{
    allEventsAreSelected = true;
}

void InternalSequencer::PianoRoll::deleteHigherNote()
{
    higherNote = -1;
}

void InternalSequencer::PianoRoll::increaseZoom(float percentageAmount)
{
    editorViewPortZoomScalePercentage += percentageAmount;

    std::cout << "PianoRoll - zoom level: " << editorViewPortZoomScalePercentage << std::endl;

    if (editorViewPortZoomScalePercentage > 100.f)
    {
        editorViewPortZoomScalePercentage = 100.f;
    }
}

void InternalSequencer::playback(long timePosition, float speedMultipl)
{
    currentPlaybackPosition = timePosition;
    speedMultiplier = speedMultipl;
}

long InternalSequencer::pause()
{
    long pausePosition = 7;
    std::cout << "PianoRoll - pausing playback at: " << pausePosition << std::endl;

    return pausePosition;
}

long InternalSequencer::stop()
{
    long stopPosition = 70;
    std::cout << "PianoRoll - stopping playback at: " << stopPosition << std::endl;

    return stopPosition;
}

void InternalSequencer::editInPianoRoll(MidiClip midiClip)
{
    midiClip.transpose(false);
}

struct Synthesizer
{
    Synthesizer();

    Manufacturer manufacturer;
    SynthEngine synthEngine;
    Case metalBox;
    Distributor distributor;
    InternalSequencer internalSequencer;

    void playNotes();
    void changeInternalStatus(int eventTypeIdentifier);
    void lightUpFeedbackLeds(long durationMilis = 2000);
};

Synthesizer::Synthesizer()
{
    std::cout << "Synthesizer" << std::endl;
}

void Synthesizer::playNotes()
{
    std::cout << "Synthesizer - playing notes." << std::endl;

    internalSequencer.playback(0);
}

void Synthesizer::changeInternalStatus(int eventTypeIdentifier)
{
    if (eventTypeIdentifier == 1)
    {
        std::cout << "Synthesizer - switching on portamento." << std::endl;

        synthEngine.switchPortamentoOn();
    }
    else if (eventTypeIdentifier == 2)
    {
        
        std::cout << "Synthesizer - warming-up" << std::endl;
        
        synthEngine.warmUp(25);
    }
    else if (eventTypeIdentifier == 3)
    {
        
        std::cout << "Synthesizer - making some noise." << std::endl;
        
        synthEngine.makeNoise(1);
    }
}

void Synthesizer::lightUpFeedbackLeds(long durationMilis)
{
    metalBox.blinkDisplayLight(durationMilis);
}

int main()
{
    Example::main();

    //add your code between here:

    WaterBottle waterBottle;

    waterBottle.doBreak();
    waterBottle.getOldAndDirty();
    waterBottle.standStill();

    Laptop laptop;

    laptop.startUp();
    laptop.goSleepMode(true);
    laptop.shutDown();

    Refrigerator refrigerator;

    refrigerator.switchLightOn();
    refrigerator.lowerTemperature(2);
    refrigerator.stopTemporarily();

    Guitar guitar;

    guitar.collectDust(410);
    guitar.play();
    guitar.soundTerrible(2);
    guitar.soundTerrible();

    Manufacturer manufacturer;

    manufacturer.createProduct("Nice Desktop Module 1.0");
    manufacturer.sellBrokenStuff();
    manufacturer.makeBigMoney();

    SynthEngine synthEngine;

    synthEngine.makeNoise(2);
    synthEngine.warmUp(37);
    synthEngine.switchPortamentoOn();

    Case metalBox;

    metalBox.doBreak();
    metalBox.blinkDisplayLight(40);
    metalBox.stopResponding(1500);

    Distributor::Shop niceShop;
    niceShop.prepareProductCatalog();
    niceShop.openDoors();
    niceShop.addProductBrand("theGoodBrand(R)");

    Distributor::Shop goodShop;
    goodShop.prepareProductCatalog();
    goodShop.openDoors();
    goodShop.addProductBrand("anotherGoodBrand(R)");

    Distributor distributor;
    distributor.applyBlackFridayDiscount(900);
    distributor.profileCustomer(345);
    distributor.openNewShop(niceShop);
    distributor.openNewShop(goodShop);

    InternalSequencer::MidiClip midiClip;
    midiClip.resize(16);
    midiClip.transpose(true);
    midiClip.setMidiChannel(5);

    InternalSequencer::PianoRoll pianoRoll;
    pianoRoll.selectAllEvents();
    pianoRoll.deleteHigherNote();
    pianoRoll.increaseZoom(4.5);

    
    InternalSequencer internalSequencer;
    internalSequencer.playback(7, 2.5);
    internalSequencer.pause();
    internalSequencer.stop();
    internalSequencer.editInPianoRoll(midiClip);

    Synthesizer synthesizer;
    synthesizer.playNotes();
    synthesizer.changeInternalStatus(2);
    synthesizer.changeInternalStatus(1);
    synthesizer.lightUpFeedbackLeds();
    synthesizer.lightUpFeedbackLeds(800);

    //and here
    std::cout << "good to go!" << std::endl;
}
