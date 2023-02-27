#include <iostream> 
#include <fstream> 

using namespace std;

int main()
{
    ifstream infile; //instantiate a file object 
    int num{ 0 };  //variable to hold the number read in; initialized to 0 

    infile.open("integers.txt"); //try to open the file 

    //An error check should go here to ensure that the file opened successfully. 
    // Use the links above!  

    /*The following is a loop to read in all of the values in the file. This loop
    executes for as long as the file object has not gone into the fail state
    (caused by reading past the end of the file or reading in a non-numeric
    value) and as long as the last number read in is positive.  Otherwise, the
    loopends, and the program ends.*/

    while (!infile.fail() && num >= 0)
    {

        infile >> num; //read in a value from the file 
            /*If the file object goes into the fail state, BUT the
          eof has not been
            reached, then the problem is due to reading a non-
          numeric value into
            a variable designed to hold a numeric value. */

            if (infile.fail() && !infile.eof())
            {
                cout << "A non-numeric value was found in the file...Exiting program. " << endl; 
            }

        /*If the file object goes into the fail state, and the eof has been
        reached, the file object is in the fail state because the program has
        read past the end of the file.  This can occur if the file is empty.
        If the file is empty and you try to read in anything, the file object
        immediately goes into the fail state, and the eof function returns
        TRUE. */

            else if (infile.fail() && infile.eof())
            {
                cout << "End of file reached." << endl;
            }

        //If the number is negative... 
            else if (num < 0)
            {
                cout << "A negative value was found in the file...Exiting program. " << endl; 
            }


        //Otherwise, do something with the value read in, such as print it out. 

            else
            {
                cout << "The number read in was " << num << endl;
            }

    }  //end of while loop  

    system("pause");
    return 0;
}