/**
* A forward:
* Keeping my other finals in mind, I no longer have the time to improve this project further.
* That being said, I enjoyed working on this project immensely. This ended up being my favorite class
* of the semester -- I even ended up switching my major to a coding-orientated discipline, so thank you for that.
*
* I have tailored this code with design and readability in mind. I would imagine some functions work the way I
* typed them, not the way I want them to work.
*
* Thank you for the fun semester. Ben
*/
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
    /** first candidate's name variable*/
    string firstCanidiateName;
    /** second candidate's name variable*/
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
     * Copy constructor for Ballot objects
     * @param origBallot is the ballot being copied
     * Tests:
     * Ballot ballot("Taco");
     * Ballot ballotCopy(ballot);
     * cout << ballot;
     * Ballot ballot("");
     * Ballot ballotCopy(ballot);
     * cout << ballot;
     *
     * Output should be the same as ballot for both.
     */
    Ballot(const Ballot& origBallot);
    /**
     * @brief Assignment operator for Ballot
     * This assignment operator overload 
     * will allow ballots to equal eachother
     * @param ballot is the ballot being used
     * @return *this
     * Tests:
     * Ballot ballot1;
     * Ballot ballot2;
     * ballot1 = ballot2
     * should reference ballot1
     * ballot1.recordVote("aa", "xx", false);
     * ballot2 = ballot1;
     * cout << ballot2;
     */
    Ballot & operator = (const Ballot& ballot);
    /**
     * @brief Insertion operator for Ballot
     * This insertion operator allows for the output
     * of certain Vote-based variables.
     * @param out is the output stream
     * @param ballot is the ballot being used
     * 
     * Tests:
     * Ballot ballotx("bruh");
     * ballotx.recordVote("taco", "bell", "false");
     * cout << ballotx;
     * Output:
     * bruh
     *      taco bell;
     * ballotx.recordVote("arbys", "mcdonalds", "true");
     * cout << ballotx;
     * Output:
     * bruh
     *      arbys mcdonalds (In person)
     */
    friend ostream& operator<<(ostream& out, const Ballot& ballot);
    /**
     * @brief Extraction operator for Ballot
     * This extraction operator certain vote
     * based variables to be read-in
     * @param in is the input stream
     * @param ballot is the ballot being used
     * 
     * Tests: 
     * stringstream ss;
     * ss << "ww" "1" "ee" "zz" 0
     * Ballot ballotx;
     * ss >> ballotx;
     * cout << ballotx << endl;
     * Output:
     * ww
     *    ee zz 
     * 
     * ss << "Test" "1" "John" "Doe" 1
     * ss >> ballotx;
     * cout << ballotx << endl;
     * Output
     * Test
     *      John Doe (In person)
     * 
     */
    friend istream& operator>>(istream& in, Ballot& ballot);
    /**
     * @brief Construct a new Ballot object
     * Constructor for Ballot(string)
     * voterID equals voterID2
     * votesStored = 0;
     * @param voterID2 is the voterID
     */
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
/**
 * @class BallotList
 * @brief creates a list of the balots
 * This class contains information to store ballots in
 * a list.
 */
class BallotList {
private:
    /**array of ballots*/
    Ballot* ballotPointer; //new Ballot[currentArraySize];
    /**current size of the array*/
    int currentArraySize;
    /**number of ballots in the array*/
    int numBallots;
public:
    /**
    * @brief Construct a new BallotList object
    * This is the default constructor for BallotList
    * numBallots becomes 0
    * currentArraySize becomes 4
    * ballotPointer initializes with a size of 4
    */
    BallotList();
    /**
     * @brief Destroy the BallotList object
     * Destructor for BallotList objects
     */
    ~BallotList();
    /**
     * @brief returns num of ballots
     * Returns the number of ballots currently in the array
     * @return int
     */
    int getNumBallots() const;
    /**
     * @brief Get a specific Ballot object
     * This returns a specific ballot based on the position provided
     * @param ballotPosition is the position
     * @return Ballot*
     */
    Ballot* getBallot(int ballotPosition);
    /**
     * @brief Get a specific Ballot object
     * This returns a specific ballot based on the position provided
     * This version is const
     * @param ballotPosition is the position
     * @return const Ballot*
     */
    const Ballot* getBallot(int ballotPosition) const;
    /**
     * @brief adds a ballot to the ballotList
     * This class will add a ballot to the ballotList above
     * @param ballot is the ballot being added
     * Tests:
     * Ballot zz("hi"), Ballot xz("hii"), Ballot cz("hiii"), Ballot bz("hiiiii"), Ballot growth("array grown");
     * zz.recordVote("default" "lol" 1);
     * zz.recordVote("default" "lol" 0);
     * listPointer.addBallot(zz);
     * listPointer.addBallot(xz);
     * listPointer.addBallot(cz);
     * listPointer.addBallot(bz);
     * listPointer.addBallot(growth);
     * The array should grow after the fifth implementation.
     */
    void addBallot(Ballot ballot);
    /**
     * @brief this finds a specific ballot
     * This class finds a specific ballot based off the voterID
     * @param voterID is the id used to find the ballot
     * @return Ballot*
     * listpointer.findBallot(hi);
     * This should output the pointer to ballot zz.
     * listpointer.findBallot(fakeballot);
     * This should output nullptr.
     */
    Ballot* findBallot(string voterID);
    /**
     * @brief counts ballots for a specific office's candidate
     * This takes two values (the office and candidate) and counts
     * the amount for each candidate. Returns how many there are
     * @param office is the office in question
     * @param candidateName is the candidate being counted for
     * @return int is the amount of ballots
     * Tests:
     * listPointer.countBallotsFor(default, lol);
     * Output should be 2.
     * listPointer.countBallotsFor(fake, fake);
     * Output should be zero.
     */
    int countBallotsFor(string office, string candidateName) const;
    /**
     * @brief Get the total votes cast
     * This will find the total votes cast in a specific ballotList
     * @return int of how many votes are cast
     * Tests:
     * Ballot ballotx("hi");
     * ballotx.recordVote("asdf" "asdf" true);
     * listPointer.addBallot(ballotx);
     * cout << listPointer.getTotalVotesCast();
     * Output: 1
     * 
     */
    int getTotalVotesCast() const;
    /**
     * @brief resets the list
     * This will reset the list.
     * Test:
     * Ballot xz("hi");
     * ballotx.recordVote("asdf" "asdf" true);
     * listPointer.addBallot(xz);
     * listPointer.resetList();
     */
    void resetList();
};
/**
 * @class VoteSummary
 * @brief creates a summary of the results
 * This outputs the summary of results from the BallotList
 * and Election objects.
 */
class VoteSummary {
public:
    /**
     * @brief Construct a new Vote Summary object
     * This constructor makes listPointer equal the param
     * @param listpointer2 is the param
     */
    VoteSummary(BallotList* listpointer2);
    /**
     * @brief Get the Ballots object
     * This will return the ballotList (listPointer)
     * @return BallotList*
     */
    BallotList* getBallots();
    /**
     * @brief loads voter data based on istream input
     * This will load ballot & voter data based on the istream
     * input. Based on what kind of input it is, it will be recorded
     * @param i is the istream
     */
    void loadVoterData(istream& i);
    /**
     * @brief prints the record of Voters
     * This prints everything related to voter data using a
     * stringstream class.
     * @return string
     */
    string printVoterRecord();
    /**
     * @brief prints the election report
     * This will output the election report, which includes the amount of votes
     * for each candidate in a district.
     * @param electionArray is the electionArray being used
     * @param arraySize is the size of the array
     * @return string
     */
    string printElectionReport(Election electionArray[], int arraySize);

private:
    /**this is the ballotList being used in the functions */
    BallotList* listPointer;
};