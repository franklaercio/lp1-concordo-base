#ifndef CHANNEL_H
#define CHANNEL_H

#include <string>

using namespace std;

class Channel {
    private:
        string name;

    public:
        Channel();

        ~Channel();

        Channel(string name);

        string getName();
        void setName(string name);
};

#endif