//Matthew Bianchi COSC 202 Lab 8
//Social Media Interface for signing up and signing in involving a hash table.

#include <vector>
#include <string>

class socialMedia {
    public:
        /* Sets up hash table for before using it.

            -Must take a valid tableSize
            -Must be able to use "Last7" or "XOR" hashFunc
            -Must be able to use "Linear" or "Double" collision resolution strategy

            -Must check if table is already setup
            -Must check for valid hashFunc
            -Must check for valid collision strategy

            If either input is not valid returns "Error in Setup"
        */
        std::string setUp(int tableSize, const std::string &hashFunc, const std::string &collision);

        /* Takes username and password as parameters and stores in hash table if stored properly will return empty string ""

            Possible edge cases 
            -Duplicate username which needs to be checked as invalid username
            -Duplicated keys which are allowed but need to be stored at a different location depending on the collision strategy chosen
            -Infinite loop given key which normally would not happen in a social media interface but in this case it can happen which needs to check that the key cannot be inserted


            Must check for the following errors
            -Table not set up
            -Empty password or username
            -Key not composed of only hex digits
            -Hash table is full
            -Username already in hash table
            -Cannot insert key

            If any errors return "Invalid Sign Up"
        */
        std::string signUp(const std::string &username, const std::string &password);

        /* Signs in to account associated with username/password combo using getPassword() if signed in properly returns "(Username) signed in"
           
           Must check for the following errors
           -Table not set up
           -Empty password or username
           -Invalid password/username combo

            If any errors return "Invalid Sign In"
        */

        std::string signIn(const std::string &username, const std::string &password);

        //Helper function for signIn() that passes username then searches the table for the index of the username and returns the associated password as a string.
        std::string getPassword(const std::string &username);

        /* strHash() is a helper function to be used with signUp and signIn that takes a string as input and converts each letter to the ascii hex value equivalent and then appends on ascii values together
           for example the password Hello = 68656c6c6f where H = 68 e = 65 l = 6c o = 6f. This key is then hashed using either the "Last7 or XOR" hashing function
           and returns a valid key to be used with the hash table.
        */
        int strHash(const std::string &key);

        //Print used for testing table inputs prints all username/passwords stored in table at the index they are associated with in the vector. Does not print empty indexes.
        void print();
    
    private:
        std::vector <std::string> Username; //Hash table of usernames
        std::vector <std::string> Password; //Password[i] is the password associated with Username[i]
        size_t NKeys; //Number of username/password combos that have been inserted
        int collStrat; //The collision resolution strategy.
        int hashFunc; //The hash function.
};