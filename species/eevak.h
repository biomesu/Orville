
#ifndef SPECIES_EEVAK_H_
#define SPECIES_EEVAK_H_

class Eevak{
    private:
    bool _isRunning;

    public:
    Eevak();
    void run();
    void stop();
    bool isRunning();
};

#endif //SPECIES_EEVAK_H_