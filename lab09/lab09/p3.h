#pragma once
#include <string>
using namespace std;
/**
 * @class Election
 * @brief simple class that stores some variables
 * This class is very simple - beyond some getters, all
 * this really does is store some variables for the user.
 */
class Election {
private:
    /** office ID variable*/
    string office;
    /** first canidate's name variable*/
    string firstCanidiateName;
    /** second canidate's name variable*/
    string secondCanidiateName;
public:
    /**
     * @brief Constructor for Election. Takes three string vars
     * This constructor also assigns the params to the private vars
     * @param office2 is the param for office
     * @param firstCanidiateName2 is the param for firstCanidiateName
     * @param secondCanidiateName2 is the param for secondCanidiateName
     */
    Election(string office2, string firstCanidiateName2, string secondCanidiateName2);
    /**
    * @brief returns the office string.
    * This getter returns the office string when called.
    * @return string office.
    */
    string getOffice() const;
    /**
     * @brief Get the Candidate1 object
     * This getter returns firstCanidiateName when called.
     * @return firstCanidiateName
     */
    string getCandidate1() const;
    /**
     * @brief Get the Candidate2 object
     * This getter returns secondCanidiateName when called.
     * @return secondCanidiateName
     */
    string getCandidate2() const;
};
/**
 * @class Vote
 * @brief stores a variety of vote-related vars
 * Another simple class that has a constructor and getters
 * Tests:
 * Vote vote1("A", "E", false);
 * should print A E 0, zero for false
 * Vote vote2("zz", "qq", true);
 * should print zz qq 1, one for true
 * Vote vote3("", "a", true);
 * should print Unknown a 1
 *
 */
class Vote {
private:
    /** office ID variable - notated 'v' for Vote*/
    string vOffice;
    /** candidate name variable */
    string canidiateName;
    /** boolean for how the vote was made */
    bool voteMadeInPerson;
public:
    /**
     * @brief Constructor for a new Vote object
     * This constructor takes two strings and a bool. This is utilized
     * in the larger Ballot class later.
     * @param vOffice2 is the name of the office
     * @param canidiateName2 is the canidiate name
     * @param voteMadeInPerson2 is the bool to check if it was in person
     */
    Vote(string vOffice2, string canidiateName2, bool voteMadeInPerson2);
    /**
     * @brief returns the office string.
     * This getter returns the vOffice2 string when called.
     * @return string vOffice.
     */
    string getOffice() const;
    /**
    * @brief Get the Candidate object
    * This getter returns canidiateName when called.
    * @return canidiateName
    */
    string getCandidate() const;
    /**
     * @brief gets the boolean variable
     * This getter returns the boolean variable
     * @return voteMadeInPerson
     */
    bool wasInPerson() const;
};
/**
 * @class Ballot
 * @brief more complex class dealing with pointer arrays
 * This class stores a voter ID for the ballots, and an array
 * of "vote" pointers to point to where these IDs are.
 */
class Ballot {
private:
    /**voter ID string */
    string voterID;
    /** amount of votes stored */
    int votesStored;
    /**Vote pointer array of size six*/
    Vote* votePointer[6];
public:
    /**
    * @brief Construct a new Ballot object
    * This is the default constructor for Ballot
    * voterID becomes "Invalid ID"
    * votesStored is zero
    */
    Ballot();
    /**
     * @brief Construct a new Ballot object
     * Construtor for Ballot(string)
     * voterID equals voterID2
     * votesStored = 0;
     * @param voterID2 is the voterID
     */
    //maybe change name of this depending on how it is implemented down the line
    Ballot(const Ballot& origBallot);
    //Declare an assignment operator for Ballot. The parameter should be a Ballot object
    //and it should be constand passed by reference
    Ballot& operator = (const Ballot& ballot);
    friend ostream& operator<<(ostream& out, const Ballot& ballot);
    friend istream& operator>>(istream& in, Ballot& ballot);
    Ballot(string voterID2);
    /**
     * @brief Destroy the Ballot object
     * Destructor for Ballot objects
     */
    ~Ballot();
    /**
     * @brief Get the Voter Id object
     * getter to return voterID
     * @return string voterID
     */
    string getVoterId() const;
    /**
     * @brief Get the Vote Count object
     * getter to return votesStored
     * @return int votesStored
     */
    int getVoteCount() const;
    /**
     * @brief Get the Vote object
     * this gets a specific vote, located through votePosition
     * @param votePosition is the position of the vote used
     * @return const Vote*
     */
    const Vote* getVote(int votePosition) const;
    /**
     * @brief Records votes
     * Based off the params, this creates a new vote and adds it to the
     * array if it doesn't exist
     * @param office is the office string used
     * @param candidateName is the candidate name used
     * @param voteInPerson is the type of vote used
     * Tests (7) (using getVote to check):
     * USING Ballot ballot1("W");
     * const Vote *vote1 = ballot1.getVote(4);
     * should return nullptr, nothing added
     *
     * const Vote *vote2 = ballot1.getVote(0);
     * should still return nullptr
     *
     * const Vote *vote3 = ballot1.getVote(6);
     * should still return nullptr
     *
     * ballot1.recordVote("OO", "AA", false);
     * vote4 = ballot1.getVote(0);
     * Should return OO AA 0
     *
     * ballot1.recordVote("OO", "AA", false);
     * vote5 = ballot1.getVote(7);
     * should return nullptr
     *
     * ballot1.recordVote("OO", "AA", false);
     * vote6 = ballot1.getVote(-1);
     * should return nullptr
     *
     * ballot1.recordVote("longerstring", "", true);
     * vote7 = ballot1.getVote(0);
     * Should return longerstring "" 1
     */
    void recordVote(string office, string candidateName, bool voteInPerson);
    /**
     * @brief counts the amount of in-person votes
     * This navigates through all votes, and counts in-person votes
     * @return int count (num of in-person votes)
     * Tests (3):
     * ballot1.recordVote("longerstring", "", true);
     * should return 1
     *
     * ballot1.recordVote("OO", "AA", false);
     * ballot1.recordVote("longerstring", "", true);
     * should return 1
     *
     * ballot1.recordVote("OO", "zz", false);
     * should return zero
     *
     */
    int countInPersonVotes();
    /**
     * @brief finds a specific vote
     * This finds a specific vote based off the office string. It then
     * returns the location of the vote in the pointer array
     * @param office is the office string used to locate the vote
     * @return int i (position of the vote)
     * Tests (3):
     * ballot1.recordVote("t", "a", true);
     * cout << ballot1.findVote("t") << "\n"; - should be 1
     *
     * ballot1.recordVote("zz", "a", true);
     * cout << ballot1.findVote("t") << "\n"; - should be -1
     *
     * ballot1.recordVote("Ben", "", false);
     * cout << ballot1.findVote("Ben") << "\n"; - should be 1
     *
     */
    int findVote(string office) const;
};