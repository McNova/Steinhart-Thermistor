#include "Steinhart-Thermistor.h"
#include "math.h"

int Thermistor::getAdc(int numsamples) {
    delay(1);
    int total = 0;
    for(int i = 0; i < numsamples; i++) {
        total += analogRead(_pin);
        delay(1);
    }
    _adc = total / numsamples;
    return _adc;
}

Thermistor::Thermistor(int _pin, int _R, int _Rref, double _A1, double _B1, double _C1, double _D1) {
    this->_pin = _pin;
    this->_R = _R;
    this->_Rref = _Rref;
    this->_A1 = _A1;
    this->_B1 = _B1;
    this->_C1 = _C1;
    this->_D1 = _D1;
    pinMode(_pin, INPUT);
}

double Thermistor::getResistance(int numsamples) {
    _resistance = _R * (4095.0 / getAdc(numsamples) - 1);
    return _resistance;
}

double Thermistor::getVolts(double vin) {
    _volts = _resistance / _Rref * vin;
    return _volts;
}

double Thermistor::getTempK() {
    _temp_k = log(_resistance / _Rref);
    _temp_k = 1 / (_A1 + _B1 * _temp_k + _C1 * _temp_k * _temp_k + _D1 * _temp_k * _temp_k * _temp_k);
    return _temp_k;
}

double Thermistor::getTempC() {
    _temp_c = getTempK() - 273.15;
    return _temp_c;
}

double Thermistor::getTempF() {
    _temp_f = getTempC() * 9 / 5.0 + 32;
    return _temp_f;
}
