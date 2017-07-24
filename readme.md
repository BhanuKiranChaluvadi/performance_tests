Performance Tests
----------------------------
This performs the performance test between various combinations of publisher and subscriber written in both C++ and python, and find out where is approximately the limit at which the desired rate coincide with the real life for 4 combinations.
----------------------------

git: Clone https://github.com/BhanuKiranChaluvadi/performance_tests

FILES
############################
This package contains 
1. Publisher (talker and pytalker)- publishes a topic called "chatter " containing custom message type string.

2. Subscriber (listener and pylistener) - subscirbes to publisher

3. custom message file (SuperAwesome)

4. launch File  	--> cpp.launch 	(		C++ publisher, C++ subscriber)
					--> py.launch 			(pthon publisher, python subscriber)
					--> cppPubpySub.launch 	(C++ publisher, python subscriber)
					--> pyPubcppSub.launch 	(pthon publisher, C++ subscriber)

5. parameters.yaml 	--> rate, set the publisher loop rate
					--> listening_time, used to observe the average messages received b subscriber of a given amount of time.

#############################


LAUNCH
-----------------------------
1. Run the required launch file from the cmd window. e.g. roslaunch performance_tests cpp.launch 
2. Set loop rate and observed will be printed on the screen.
-----------------------------
