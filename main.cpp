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



/*

// unrelated objects:

Thing 1) Water Bottle
5 properties:
    1) table of chemical content (std::string)
    2) capacity in onces (float)
    3) contained liquid level in onces (float)
    4) current weight in kg (float)
    5) transparency percentage (int)
3 things it can do:
    1) break
    2) getting old and dirty
    3) stand still
*/
struct WaterBottle
{
    //     1) table of chemical content (std::string)
    std::string chemicalContentTable = "Nickel 9%, Cadmium 7%, Copper 3%";
    //     2) capacity in onces (float)
    float capacityInOnces = 2;
    //     3) contained liquid level in onces (float)
    float containedLiquidLevelInOnces = 1.4f;
    //     4) current weight in kg (float)
    float currentWeightInKg = 1.8f;
    //     5) transparency percentage (int)
    int transparencyPercentage = 58;
    // 3 things it can do:
    //     1) break
    void doBreak(); // cannot use "break" keyword
    //     2) getting old and dirty
    void getOldAndDirty();
    //     3) stand still
    void standStill();
};
/*
Thing 2) laptop
5 properties:
    1) display width (float)
    2) keyboard layout identifier (std::string)
    3) trackpad sensitivity (int)
    4) speakers count (int)
    5) usb-port speed (float)
3 things it can do:
    1) start-up
    2) shut-down
    3) go sleep-mode
*/
struct Laptop
{
    //     1) display width (float)
    float displayWidth = 200;
    //     2) keyboard layout identifier (std::string)
    std::string keyboardlayout = "en.US";
    //     3) trackpad sensitivity (int)
    int trackpadSensitivity = 8;
    //     4) speakers count (int)
    int speakersCount = 2;
    //     5) usb-port speed (float)
    float usbPortSpeed = 3.4f;
    // 3 things it can do:
    //     1) start-up
    long startUp(); // returns start-up procedure duration in millis
    //     2) shut-down
    long shutDown(); // returns shut-down procedure duration in millis
    //     3) go sleep-mode
    void goSleepMode(bool saveToDisk = true); // accepts boolean to persist RAM state to disk
};
/*
Thing 3) refrigerator
5 properties:
    1) thermostat lower threshold in °C (int)
    2) total volume in onces (float)
    3) power consumption in watt (float)
    4) current temperature in °C (float)
    5) case material (std::string)
3 things it can do:
    1) lower the temperature
    2) stop engine temporarily
    3) switch on the light
*/
struct Refrigerator
{
    //     1) thermostat lower threshold in °C (int)
    int thermostatLowerThresholdInCelsius = 3;
    //     2) total volume in onces (float)
    float totalVolumeInOnces = 2.2f;
    //     3) power consumption in watt (float)
    float powerConsumptionInWatt = .7f;
    //     4) current temperature in °C (float)
    float currentTemperatureInCelsius = 8.1f;
    //     5) case material (std::string)
    std::string caseMaterial = "stainless steel";
    // 3 things it can do:
    //     1) lower the temperature
    // accepts amount of lowering in degrees
    float lowerTemperature(int degrees = 1); // returns the new temperature, right after the call has been fulfilled
    //     2) stop engine temporarily
    bool stopTemporarily(); // returns whether the engine has stopped or not
    //     3) switch on the light
    void switchLightOn();
};
/*
Thing 4) guitar
5 properties:
    1) strings count (int)
    2) lower note identifier (std::string)
    3) output-jack slots count (int)
    4) body material id (int)
    5) body shape type (std::string)
3 things it can do:
    1) play
    2) collect dust
    3) sound terrible
*/
struct Guitar
{
    //     1) strings count (int)
    int stringCount = 6;
    //     2) lower note identifier (std::string)
    std::string lowerNoteIdentifier = "E1";
    //     3) output-jack slots count (int)
    int outputJackSlotsCount = 1;
    //     4) body material id (int)
    int bodyMaterialId = 789;
    //     5) body shape type (std::string)
    std::string bodyShapeType = "Tele";
    // 3 things it can do:
    //     1) play
    void play();
    //     2) collect dust
    // accepts how long it should collect dust
    long collectDust(int days = 365); // return kg of dust collected since collection started
    //     3) sound terrible
    // accept how much should sound terrible. range [0-9]
    void soundTerrible(int howTerrible = 9);
};
/*
// correlated objects:

Thing 5) Manufacturer
5 properties:
    1) name (std::string)
    2) location (std::string)
    3) employees count (int)
    4) yearly revenew (billion $) (float)
    5) financial status (std::string)
3 things it can do:
    1) create a new product
    2) sell broken stuff
    3) make big money
*/
struct Manufacturer
{
    //     1) name (std::string)
    std::string name = "Foo Instruments";
    //     2) location (std::string)
    std::string location = "a place";
    //     3) employees count (int)
    int employeesCount = 487;
    //     4) yearly revenew (billion $) (float)
    float yearlyRevenewAsBillionDollars = .1f;
    //     5) financial status (std::string)
    std::string financialStatus = "healthy";
    // 3 things it can do:
    //     1) create a new product
    //    accepts the new product model name
    long createProduct(std::string modelName); // returns the created product model identifier
    //     2) sell broken stuff
    void sellBrokenStuff();
    //     3) make big money
    float makeBigMoney(); // returns money amount in billion dollars
};
/*
Thing 6) SynthEngine
5 properties:
    1) synthesis type (std::string)
    2) polyphony amount (int)
    3) current volume (float)
    4) supported note-max-pitch in hertz (int)
    5) filter resonance amount (float)
3 things it can do:
    1) make noise
    2) warm-up
    3) switch-on portamento
*/
struct SynthEngine
{
    //     1) synthesis type (std::string)
    std::string synthesisType = "Virtual Analog";
    //     2) polyphony amount (int)
    int polyphonyAmount = 8;
    //     3) current volume (float)
    float currentVolume = .7f;
    //     4) supported note-max-pitch in hertz (int)
    int supportedNoteMaxPitchInHertz = 10000;
    //     5) filter resonance amount (float)
    float filterResonanceAmount = .765f;
    // 3 things it can do:
    //     1) make noise
    // accepts noise type: 1: white noise, 2: brown noise, 3: pink noise
    void makeNoise(int noiseType = 1);
    //     2) warm-up
    // accepts the target temperature
    bool warmUp(int targetTemperatureInCelsius); // returns if, at the end of warm-up process, the expected temperature was reached or not
    //     3) switch-on portamento
    void switchPortamentoOn();

};
/*
Thing 7) Case
5 properties:
    1) heigth (int)
    2) width (int)
    3) knobs count (int)
    4) front panel color identifier (int)
    5) material (std::string)
3 things it can do:
    1) break
    2) blink display light
    3) stop responding
*/
struct Case
{
    //     1) heigth (int)
    int height = 12;
    //     2) width (int)
    int width = 26;
    //     3) knobs count (int)
    int knobsCount = 14;
    //     4) front panel color identifier (int)
    int frontPanelColorIdentifier = 89;
    //     5) material (std::string)
    std::string material = "wood and metal";
    // 3 things it can do:
    //     1) break
    // accepts how many pieces it should break-up
    void doBreak(int partCount = 2); // can't use "break" keyword
    //     2) blink display light
    // accepts blinking time interval in millis
    void blinkDisplayLight(long intervalMillis = 2000);
    //     3) stop responding
    // accept how long it should stop responding in millis
    void stopResponding(long millis  = 1000);
};
/*
Thing 8) Distributor
5 properties:
    1) name (std::string)
    2) location (std::string)
    3) shops count (int)
    4) customer base satisfaction (float)
    5) monthly shipping count (int)
3 things it can do:
    1) apply black friday discount
    2) profile customers
    3) open a new shop
*/
struct Distributor
{

    struct Shop
    {
        std::string ownerName = "John Doe";
        std::string address = "LA";
        long ranking = 0;
        int attendentCount = 3;
        int showRoomArea = 230;

        void prepareProductCatalog();
        void openDoors();
        void addProductBrand(std::string brand);
    };

    //     1) name (std::string)
    std::string name = "Music Everywhere";
    //     2) location (std::string)
    std::string location = "anotherPlace";
    //     3) shops count (int)
    int shopCount = 23;
    //     4) customer base satisfaction (float)
    float customerBaseSatisfaction = .78f;
    //     5) monthly shipping count (int)
    int montlyShippingCount = 1028;
    // 3 things it can do:
    //     1) apply black friday discount
    // accepts the order identifier on which apply the discount
    float applyBlackFridayDiscount(long orderId); // return final price in dollars
    //     2) profile customers
    // accept customer identifier to profile
    long profileCustomer(long customerId); // returns created profile identifier
    //     3) open a new shop
    void openNewShop(Shop shop);
};
/*
Thing 9) InternalSequencer
5 properties:
    1) max bars supported number (int)
    2) song duration in seconds (int)
    3) currently selected track (int)
    4) currently selected pattern (int)
    5) MIDI buffer size (int)
3 things it can do:
    1) playback
    2) pause
    3) stop
*/
struct InternalSequencer
{

    struct MidiClip
    {
        std::string clipName = "CHORUS";
        int midiChannel = 0;
        int lengthInBars = 4;
        bool cloneable = true;
        bool allow = true;

        void resize(int newDurationInBars);
        // accepts option to transform data w/o backup history
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

        void selectAllEvents();
        void deleteHigherNote();
        void increaseZoom(float percentaceAmount);
    };

    PianoRoll pianoRoll;

    //     1) max bars supported number (int)
    int maxBarsSupportedNumber = 9999;
    //     2) song duration in seconds (int)
    int songDurationInSecs = 7899;
    //     3) currently selected track (int)
    int currentlySelectedTrack = 3;
    //     4) currently selected pattern (int)
    int currentlySelectedPattern = 9;
    //     5) MIDI buffer size (int)
    int midiBufferSize = 1024;
    // 3 things it can do:
    //     1) playback
    // accepts:
    //    - playback start position in millis
    //    - speed multiplier from original speed
    void playback(long timePosition = 0, float speedMultiplier = 1.f);
    //     2) pause
    // returns play-head time after-pause position in millis
    long pause();
    //     3) stop
    // returns play-head time after-stop position in millis
    long stop();

    void editInPianoRoll(MidiClip midiClip);
};
/*
Thing 10) Synthesizer
5 properties:
    1) Manufacturer
    2) SynthEngine
    3) Case
    4) Distributor
    5) InternalSequencer
3 things it can do:
    1) play notes
    2) change internal status
    3) light-up feedback LEDs
*/
struct Synthesizer
{
    //     1) Manufacturer
    Manufacturer manufacturer;
    //     2) SynthEngine
    SynthEngine synthEngine;
    //     3) Case
    Case metalBox; // can't use keyword "case", here
    //     4) Distributor
    Distributor distributor;
    //     5) InternalSequencer
    InternalSequencer internalSequencer;
    // 3 things it can do:
    //     1) play notes
    void playNotes();
    //     2) change internal status
    // accepts an event type to determine internal behavior
    void changeInternalStatus(int eventTypeIdentifier);
    //     3) light-up feedback LEDs
    // accepts feedback duration in millis
    void lightUpFeedbackLeds(long durationMilis = 2000);
};







int main()
{
    std::cout << "good to go!" << std::endl;
}
