#include "application.h"

class Thermistor {
    private:
        int _pin;
        int _R;
        int _Rref;
        int _adc;
        double _A1;
        double _B1;
        double _C1;
        double _D1;
        int getAdc(int numsamples);
    public:
        double _resistance;
        double _volts;
        double _temp_k;
        double _temp_c;
        double _temp_f;
        Thermistor(int _pin, int _R = 10000, int _Rref = 10000, double _A1 = 0.003354016, double _B1 = 0.000256985, double _C1 = 0.000002620131, double _D1 = 0.00000006383091);
        double getResistance(int numsamples = 1);
        double getVolts(double vin = 3.3);
        double getTempF();
        double getTempC();
        double getTempK();
};

