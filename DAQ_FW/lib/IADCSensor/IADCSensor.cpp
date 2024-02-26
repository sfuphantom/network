#include "IADCSensor.h"

// ADC INFO
// adc voltage 2V~5.5V, 860 sample rate, SERIAL output, 16 bit resolution, 15 µV min voltage increment
// i2c interface
// PGA offers input ranges from ±0.256 V to ±6.144 V
// adc resolution : 65536

// PGA VALUES for a ADS1115
// TODO: MOVE TO SYS_CONFIG WHEN FINAL
#define ADS1115_GAIN_TWOTHIRDS 0.187500f
#define ADS1115_GAIN_ONE 0.125000f
#define ADS1115_GAIN_TWO 0.062500f
#define ADS1115_GAIN_FOUR 0.031250f
#define ADS1115_GAIN_EIGHT 0.015625f
#define ADS1115_GAIN_SIXTEEN 0.007813f

// CLASS METHODS:

// Default constructor with generic metadata
IADCSensor::IADCSensor(const char *_SensorName, const uint16_t _SensorID, const ADCAddress _ADCAddress)
    : mSensorName(_SensorName), mSensorID(_SensorID), mADC_Address(_ADCAddress) {}

// ADS1115 initialize func, to be called on setup()
void IADCSensor::Initialize()
{
    if (!mADS.begin(static_cast<uint8_t>(mADC_Address)))
    {
        while (1)
        {
            Logger::Error("Failed to start ads with ID: %s", PrintAddress());
        }
    }
    else
        Logger::Notice("ADC %s initialized", PrintAddress());
}

float IADCSensor::GetData()
{
    // gets bit data from the adc
    int16_t raw_data = Read();

    Logger::Trace("Initial Data: %u from sensor <%s> with ID: %u and ads component %s",
                  raw_data, mSensorName, mSensorID, PrintAddress());

    // adc bit to voltage conversion, gain mode can be set via the adc library
    float final_data = Process(mADS.computeVolts(raw_data)); // Process is overidden by the child class

    Logger::Notice("Processed Data: %D, from sensor <%s> with ID: %u and adc component %s",
                   final_data, mSensorName, mSensorID, PrintAddress());

    return (float)final_data;
}

int16_t IADCSensor::Read()
{

    // testing read function - NOT FINAL
    int16_t adcBitData = mADS.readADC_SingleEnded(0);

    if (!adcBitData)
    {
        Logger::Warning("No Input Detected from sensor <%s> with ID: %u and adc component %s",
                        mSensorName, mSensorID, PrintAddress());
        return 0;
    }

    return (int16_t)adcBitData;
}

float ChildExample::Process(float InputData)
{
    Logger::Error("Using example class");
    return InputData;
}

const char *IADCSensor::PrintAddress()
{
    switch (mADC_Address)
    {
    case ADCAddress::U1:
        return "U1";
    case ADCAddress::U2:
        return "U2";
    case ADCAddress::U3:
        return "U3";
    case ADCAddress::U4:
        return "U4";
    default:
        return "<Error, invalid Address>";
    }
}