# Pseudocode
This file contains pseudocode for the most important and complicated functions discussed in the report, mainly `main()`, `menus()`, `visitor_controls()`, and `park_controls()`.

## main()
```
TODO AS FORD FINISHES
```

## menus()
```
Print options to user
Read input
while( input is not 0 ):
    if( chose Visitor Center ):
        call visitor_controls()
    else if( chose Park ):
        call park_controls()
    else if( chose Research Lab ):
        call lab_controls()
    else if( chose Check Alarms ):
        print messages from the lab, visitor, and park Alarms
    else:
        if( chose QUIT ):
            exit
        else:
            give menu options again to user
```

## visitor_controls()
```
Give the user Visitor section control options
Read in user integer input

if( chose QUIT ):
    exit
else if( chose Alarm System )