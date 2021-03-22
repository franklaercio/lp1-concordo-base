#ifndef CHANNEL_H
#define CHANNEL_H

#include <string>

using namespace std;

class Channel {
    public:
        string name;
    
        Channel(string name) {
            this->name = name;
        }

        virtual string getName();
};

#endif