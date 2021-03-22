#ifndef MESSAGE_H
#define MESSAGE_H

#include <string>

using namespace std;

class Message {
    private:
        int sendUserId;
        string date;
        string content;

    public:
        Message();

        ~Message();

        Message(int sendUserId, string date, string content);

        int getUserId();
        void setUserId(int sendUserId);

        string getDate();
        void setDate(string date);

        string getContent();
        void setContent(string content);
};

#endif