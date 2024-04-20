Visually impaired individuals face daily challenges while navigating public spaces, particularly on roads, where they often encounter difficulties in detecting obstacles while walking.

      Current solutions often rely on cloud infrastructures, which pose significant challenges: 
      Latency issues that can affect the system performance.
      Potential data protection and security concerns that can compromise sensitive information.
      Limited real-time information about the environment can hinder informed decision-making.


we used the NEO 6M GPS tracker to track the location and send it to the main dashboard of the system
   so that the blind person's guardian or family member can see the exact location he or she is in while detecting obstacles with ultrasonic.
we used a buzzer to tell the person that there is an obstacle when they walk on the roads. The obtained data is sent to the cloud so that their family can access it from the cloud dashboard. For the Object detection, we used tensorflow lite version.

To connect the sensors first we used the ESP32 module but it got burnt after giving the wrong voltage after that we used Arduino nano board to perfectly connect the sensors.Used two 3.7v batteries with a buck convertor to step down the voltage to 5v to power up the sensors.
