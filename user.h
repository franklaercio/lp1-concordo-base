#ifndef USER_H
#define USER_H

#include <string>

using namespace std;

class User {
    private:
        int id;
        string name;
        string email;
        string password;

    public:
        User();

        ~User();

        User(int id, string name, string email, string password);

        int getId();
        void setId(int id);

        string getName();
        void setName(string name);

        string getEmail();
        void setEmail(string email);

        string getPassword();
        void setPassword(string password);
};

#endif