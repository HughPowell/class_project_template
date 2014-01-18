# Project generator for [CLASS](http://rfc.zeromq.org/spec:21) projects

Generates a skeleton for a CLASS project

## Usage

* Hack the CONFIG file with some (relatively) sensible values
* Run the generate.sh script giving the directory of where the project should be created
    e.g. `./generate.sh ~/`
    This will create the project in the users home directory
* Update the README.md file
* There are two template classes, myp\_mystatefulmod and myp\_mystatelessmod included.  Run
    `grep -r myp_mystate`
  from the project directory to find all the places where these classes are used.  Hopefully this'll give you enough information about how to add new classes.
