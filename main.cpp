 /*
 Project 3 - Part 3 / 5
 video: Chapter 2 - Part 8
 Constructors tasks

 Create a branch named Part3

 On this new branch:

 0) if you opted to not fill in any of your member functions in part2, 
    fill in ALL of your member functions
    
 1) Add a constructor for each User-Defined-Type.
    The constructor should be the first declaration in your UDT, before all member variables and member functions.
    add a std::cout message in the constructor that prints out the name of the class being constructed.  
    When you run your code, you'll see the order that your objects are created in the program output. 
 
 2) For each User-Defined-Type:
        amend some of the member functions to print out something interesting via std::cout
 
 3) Instantiate 1 or 2 instances of EACH of your user-defined types in the main() function.  
    You should have at least 12 different variables declared in main(), because you have written 12 different types (including the nested types)

 4) For each instantiated UDT: 
        call each of that instance's member functions.
        You're doing this to show that your code doesn't produce warnings when you call the functions that take arguments.
 
 5) add some std::cout statements in main() that print out your UDT's member variable values or values returned from your UDT member functions (if they return values)
 
 After you finish defining each type/function:
 click the [run] button.  Clear up any errors or warnings as best you can.
 if your code produces a -Wpadded warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 
 example:
 */

#include <iostream>
namespace Example 
{
struct UDT  // my user defined type named 'UDT'
{
    int thing = 0; //a member variable
    UDT();              //1) the constructor
    void printThing();  //the member function
};

//the function definitions are outside of the class
UDT::UDT()
{
    std::cout << "UDT being constructed!" << std::endl; //1) 
}

void UDT::printThing()
{
    std::cout << "UDT::printThing() " << thing << std::endl;  //2) printing out something interesting
}

int main()
{
    UDT foo;              //3) instantiating a UDT named 'foo' in main()
    foo.printThing();     //4) calling a member function of the UDT instance.
    
    //5) a std::cout statement accessing foo's member variable.
    //It also demonstrates a 'ternary expression', which is syntactic shorthand for an 'if/else' expression
    std::cout << "Is foo's member var 'thing' equal to 0? " << (foo.thing == 0 ? "Yes" : "No") << "\n";
    
    return 0;
}
} //end namespace Example

//insert Example::main() into main() of user's repo.




struct WaterBottle
{
    std::string chemicalContentTable = "Nickel 9%, Cadmium 7%, Copper 3%";
    float capacityInOnces = 2;
    float containedLiquidLevelInOnces = 1.4f;
    float currentWeightInKg = 1.8f;
    int transparencyPercentage = 58;
    bool broken = false;
    int dirtynessPercentage = 0;
    bool waitingForever = false;

    void doBreak();
    void getOldAndDirty();
    void standStill();
};

void WaterBottle::doBreak()
{
    broken = true;
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
    float displayWidth = 200;
    std::string keyboardlayout = "en.US";
    int trackpadSensitivity = 8;
    int speakersCount = 2;
    float usbPortSpeed = 3.4f;
    bool isOn = false;
    bool powerSaving = false;
    bool savedToDisk = false;

    long startUp();
    long shutDown();
    void goSleepMode(bool saveToDisk = true);
};

long Laptop::startUp()
{
    isOn = true;
    powerSaving = false;

    return 100;
}

long Laptop::shutDown()
{

    isOn = false;

    return 50;
}

void Laptop::goSleepMode(bool saveToDisk)
{

    if (saveToDisk)
    {
        savedToDisk = true;
    }

    powerSaving = true;
}

struct Refrigerator
{
    float thermostatLowerThresholdInCelsius = 3.f;
    bool thermostatInternalError = false;
    float totalVolumeInOnces = 2.2f;
    float powerConsumptionInWatt = .7f;
    float currentTemperatureInCelsius = 8.1f;
    std::string caseMaterial = "stainless steel";

    float lowerTemperature(float degrees = 1.f);
    bool stopTemporarily();
    void switchLightOn();
};

float Refrigerator::lowerTemperature(float degrees)
{

    currentTemperatureInCelsius -= degrees;

    if (currentTemperatureInCelsius < thermostatLowerThresholdInCelsius)
    {
        thermostatInternalError = true;

        return thermostatLowerThresholdInCelsius;
    }

    return currentTemperatureInCelsius;
}

bool Refrigerator::stopTemporarily()
{

    if (thermostatInternalError)
    {
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

void Guitar::play()
{
    humbuckerOn = true;
}

float Guitar::collectDust(float days)
{

    collectedDust += days * dustCollectionDailyRate;

    return collectedDust;
}

void Guitar::soundTerrible(int howTerrible)
{
    if (howTerrible > 5)
    {
        inTune = false;
    }
}

struct Manufacturer
{
    std::string name = "Foo Instruments";
    std::string location = "a place";
    int employeesCount = 487;
    float yearlyRevenewAsBillionDollars = .1f;
    std::string financialStatus = "healthy";
    long lastCreatedProductId = 0;
    std::string currentPrototypeName = "";

    long createProduct(std::string modelName);
    void sellBrokenStuff();
    float makeBigMoney();
};

long Manufacturer::createProduct(std::string modelName)
{

    currentPrototypeName = "proto_" + modelName;

    return ++lastCreatedProductId;
}

struct SynthEngine
{
    std::string synthesisType = "Virtual Analog";
    int polyphonyAmount = 8;
    float currentVolume = .7f;
    int supportedNoteMaxPitchInHertz = 10000;
    float filterResonanceAmount = .765f;
    std::string currentNoiseType = "";
    float warmingRatio = 0.8f;
    float warmingSpeed = 7.f;
    bool portamentoOn = false;

    void makeNoise(int noiseType = 1);
    bool warmUp(float targetTemperatureInCelsius);
    void switchPortamentoOn();
};

void SynthEngine::makeNoise(int noiseType)
{
    if (noiseType == 1)
    {
        currentNoiseType = "white";
    }
    else if (noiseType == 2)
    {
        currentNoiseType = "brown";
    }
    else
    {
        currentNoiseType = "pink";
    }
}

bool SynthEngine::warmUp(float targetTemperatureInCelsius)
{

    if (warmingRatio * warmingSpeed >= targetTemperatureInCelsius)
    {
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

void Case::doBreak(int partCount)
{

    broken = true;

    if (partCount > 2)
    {
        multipartBreak = true;
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
    struct Shop
    {
        std::string ownerName = "John Doe";
        std::string address = "LA";
        long ranking = 0;
        int attendentCount = 3;
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

void Distributor::Shop::prepareProductCatalog()
{

    if (moneyBalance > 5.f)
    {
        moneyBalance -= 3.f; // catalog cost
    }
}

void Distributor::Shop::openDoors()
{
    open = true;
}

void Distributor::Shop::addProductBrand(std::string brand)
{
    mostRecentBrand = brand;
}

float Distributor::applyBlackFridayDiscount(long orderId)
{

    if (orderId == 1000)
    {
        return 0.f;
    }

    return .7f * orderPrice;
}

long Distributor::profileCustomer(long customerId)
{
    customerBaseSatisfaction *= .2f;

    return profilationIdOffset + customerId;
}

struct InternalSequencer
{
    struct MidiClip
    {
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

void InternalSequencer::MidiClip::resize(int newDuration)
{
    lengthInBars = newDuration;
}

void InternalSequencer::MidiClip::transpose(bool destructive)
{
    if (destructive)
    {
        baseNoteBeforeTransposition = -1; // less than 0 to invalidate undo cache
    }
    else
    {
        baseNoteBeforeTransposition = currentBaseNote;
    }

    currentBaseNote += 12; // 1 octave
}

void InternalSequencer::MidiClip::setMidiChannel(int midiChnl)
{
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

void InternalSequencer::PianoRoll::increaseZoom(float percentaceAmount)
{
    editorViewPortZoomScalePercentage += percentaceAmount;

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

struct Synthesizer
{
    Manufacturer manufacturer;
    SynthEngine synthEngine;
    Case metalBox;
    Distributor distributor;
    InternalSequencer internalSequencer;

    void playNotes();
    void changeInternalStatus(int eventTypeIdentifier);
    void lightUpFeedbackLeds(long durationMilis = 2000);
};

void Synthesizer::playNotes()
{
    internalSequencer.playback(0);
}

void Synthesizer::changeInternalStatus(int eventTypeIdentifier)
{
    if (eventTypeIdentifier == 1)
    {
        synthEngine.switchPortamentoOn();
    }
    else if (eventTypeIdentifier == 2)
    {
        synthEngine.warmUp(25);
    }
    else if (eventTypeIdentifier == 3)
    {
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

    //and here
    std::cout << "good to go!" << std::endl;
}
