# Problem Statement

To successfully design, develop, and simulate an IoT-based Home Automation System (HAS)
utilizing NodeMCU, an open source IoT platform, allowing full management of all system loads
from anywhere in the globe via a public web application with an internet connection. Home
Automation allows us to operate devices in our houses from anywhere using a mobile device.
Home automation is more correctly linked with homes in which practically everything is
connected to a remotely controllable network, from lighting, fans, and electrical outlets to
heating, cooling, and ventilation systems. This may also include any alarm systems, all doors,
windows, locks, smoke sensors, security cameras, and any other sensor that may be related to it
from a home safety standpoint. We will build a project in which we will control the light and fan
over the internet. In other words, we’ll use smart devices to turn lights and fans ON and OFF
remotely.
# Possible Outcome

We will be able to manipulate light from far in this project. Android phones, laptops, and other
smart gadgets are examples. Let's pretend that someone neglected to turn off the light in his
room. However, the individual is no longer present in the room. In this situation, the individual
will be able to turn on or off the light using the Wi-Fi network as needed.

# Proposed system and architecture

The system's core principle is to control home over internet. The database will be stored in a
server along with the process. The system can be divided into its hardware and software
components. The hardware components consist of a Relay Module, ESP8266 connected with
lights, fans, electrical devices and power supply and a server which will wirelessly connect with
the ESP8266 and paired smartphones to send and receive data. The block diagram illustrates the
connections among the physical components.
The software components consist of the logic used in the Relay Module and ESP8266 to take
input and show the output specifically controlling the devices.

# Experimental Setup and Results
For the experimental setup we have used the CISCO Packet Tracer to implement the prototype
system. Here we used the home gateway, Appliance, Speaker, Fan, Light and AC components to
configure the prototype.
Fig 2: Prototype System in Cisco Packet Tracer6
We have used similar logic described in the proposed architecture to develop and test the
prototype. The home gateway acts as the server in this prototype and sends the outcome to the
door. All the sending and receiving of the data is done wirelessly through the home gateway.
The outcome of this is like this in the following figure (3), while switch is active, we see that the
specific LED is on.
