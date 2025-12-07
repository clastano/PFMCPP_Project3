/*
Project 3 - Part 2 / 5
Video: Chapter 2 Part 6
Implementations tasks

Create a branch named Part2

tasks
0) delete all of the plain english pseudo-code you added in Part1.
   don't forget to remove the blank lines left behind after you remove your comments
  - you should be left with only your UDTs.
*/
// example:
// if you had something like this at the end of Part1e:
/*
Thing: Car Wash
    5 properties:
        - number of vacuum cleaners
        - number of eco-friendly cleaning supplies
        - stores the amount of water used per week.
        - stores amount of profit made per week
        - number of cars serviced per day
    3 things it can do:
        - wash and wax car
        - charge customer
        - detail the car interior
 */

#include <iostream>
#include <string>
namespace Part1eVersion 
{
struct CarWash        
{
    //number of vacuum cleaners                     
    int numVacuumCleaners = 3; 
    //number of eco-friendly cleaning supplies      
    int numEcoFriendlyCleaningSupplies = 20;     
    //stores the amount of water used per week.     
    float waterUsedPerWeek = 200.f;            
    //stores amount of profit made per week         
    float profitPerWeek = 495.95f;               
    //number of cars serviced per day               
    int numberOfCarsServiced = 10;               

    struct Car  
    {
        bool isAPickupTruck = false;
        float gasMileage = 26.2f;        
        int year = 1985;
        std::string manufacturer = "Toyota";
        std::string model = "Corolla";

        void fillTank(float costPerGallon, double fuelAmountInGallons = 2.0, bool requiresDiesel = false);  
        void breakDown(std::string failureType, bool requiresTow = false);
        int getMilesTraveledAnnually(bool includeUberLyftTrips);
    };

    //wash and wax car
    void washAndWaxCar( Car car ); 
    //charge customer
    float chargeCustomer(float discountPercentage);
    //detail the car interior
    void detailInterior( Car car );

    Car carBeingServiced;  
};
}

//this is what I want to see after the code is cleaned up: 
namespace Part2Version
{
struct CarWash        
{
    int numVacuumCleaners = 3; 
    int numEcoFriendlyCleaningSupplies = 20;     
    float waterUsedPerWeek = 200.f;            
    float profitPerWeek = 495.95f;               
    int numberOfCarsServiced = 10;               

    struct Car  
    {
        bool isAPickupTruck = false;
        float gasMileage = 26.2f;        
        int year = 1985;
        std::string manufacturer = "Toyota";
        std::string model = "Corolla";

        void fillTank(double fuelAmountInGallons = 2.0);  
        void breakDown(std::string failureType, bool requiresTow = false);
        int getMilesTraveledAnnually(bool includeUberLyftTrips);
    };

    void washAndWaxCar( Car car ); 
    float chargeCustomer(float discountPercentage);
    void detailInterior( Car car );

    Car carBeingServiced;  
};
}
  /*
    The above snippet is just an example showing you how to clean up your code.  
    Do not put your cleaned up code into a namespace like I have done here.

 1) write the definition for the Type that leftFoot and rightFoot are instantiations of.
    don't forget to define and implement the member functions 'stepForward()' and 'stepSize()'
    you should be able to deduce the return type of those functions based on their usage in Person::run()
    You'll need to insert the Person struct from the video in the space below.
 */

struct Person
{
    struct Foot
    {
        int stepSizeInInches = 10;
        long fatigue = 0;

        int stepSize();
        void stepForward();
    };

    int age;
    int height;
    float hairLength;
    float GPA;
    unsigned int SATScore;
    int distanceTraveled = 0;

    Foot leftFoot;
    Foot rightFoot;

    void run(int howFast, bool startWithLeftFoot);
};

int Person::Foot::stepSize()
{
    return stepSizeInInches;
}

void Person::Foot::stepForward()
{
    fatigue += 1;
}

void Person::run(int howFast, bool startWithLeftFoot)
{
    if(howFast > 2)
    {
        howFast = 2; // limiter
    }

    if(startWithLeftFoot)
    {
        leftFoot.stepForward();
        rightFoot.stepForward();
    }
    else
    {
        rightFoot.stepForward();
        leftFoot.stepForward();
    }

    distanceTraveled += (leftFoot.stepSize() + rightFoot.stepSize()) * howFast;
}

/*
 2) provide implementations for the member functions you declared in your 10 user-defined types from the previous video outside of your UDT definitions.
    If you have 'unused parameter' warnings, you aren't using one of your function parameters in your implementation.
    Solution: use the parameter in your implementation.

    If you have 'shadows a field of <classname>' warnings, a local variable in the function has the same name as a class member.  
    This local variable could also be a function parameter with the same name as the class member.
    Solution: change the local variable's name so it is different from the class member variable's name.

 3) be sure to write the correct full qualified name for the nested type's member functions.

 4) After you finish defining each type/function, click the [run] button.  Clear up any errors or warnings as best you can.
 if your code produces a -Wpadded warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 If your code produces -Wconversion warnings, do NOT use static_cast<> to solve the warnings.  
 Casting has not been covered yet.
 Change your code so that no warnings are produced WITHOUT using casting.
 This usually means you have to use identical types for all variables used in an expression that is producing that conversion warning.
 */

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
  std::cout << "good to go!" << std::endl;
}
