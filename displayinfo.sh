#!/bin/bash

Hour=`date +%H`

afternoon=12
evening=17
midnight=24

if [ $Hour -lt $afternoon ]; then
	echo "Hello and good morning, $LOGNAME"
	echo "Current date is `date`"
	echo "User is `who i am`"
	echo "Current directory `pwd`"

elif [ $Hour -lt $evening ]; then
	echo "Hello and good afternoon, $LOGNAME"
	echo "Current date is `date`"
	echo "User is `who i am`"
	echo "Current directory `pwd`"

elif [ $Hour -lt $midnight ]; then
	echo "Hello and good evening, $LOGNAME"
	echo "Current date is `date`"
	echo "User is `who i am`"
	echo "Current directory `pwd`"

else
	echo "ERROR: Time is broken"
fi
