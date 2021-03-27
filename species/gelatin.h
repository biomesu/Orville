


#ifndef SPECIES_GELATIN_H_
#define SPECIES_GELATIN_H_
#include <string>

class Gelatin
{

    public:
    Gelatin(double weight);
    void morph();
    void morph(const char shapeName[]);
    char* shape();
    double weight() const;
    Gelatin split();
    bool operator != (const Gelatin &rhs) const;
    
    private:
    const int MAX_LEN = 7;

    char _shape[7];
    double _weight;

};

#endif //SPECIES_GELATIN_H_
