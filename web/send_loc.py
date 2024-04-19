import requests
import serial
import time

# EC2 instance URL to send data to
EC2_URL = 'http://13.201.44.67/receive_location_data'


def get_location():
    # Replace '/dev/ttyUSB0' with the appropriate serial port
    serial_port = '/dev/ttyUSB0'
    baud_rate = 9600

    # Open the serial port
    ser = serial.Serial(serial_port, baud_rate, timeout=1)
    # Open the output file
    output_file = open("data.txt", "w")

    try:
        while True:
            if ser.in_waiting > 0:
                try:
                    line = ser.readline().decode('utf-8').strip()
                    dataArray = line.split(" ")
                    longitude = dataArray[0]
                    latitude = dataArray[1]

                    return latitude, longitude
                except UnicodeDecodeError:
                    return None, None


                # Write the received line with timestamp to the output file

    except KeyboardInterrupt:
        return None, None
    finally:
        # Close the serial connection and the output file
        ser.close()
        output_file.close()


def send_location_data(latitude, longitude):
    data = {'latitude': latitude, 'longitude': longitude}
    try:
        response = requests.post(EC2_URL, json=data)
        if response.status_code == 200:
            print("Location data sent successfully")
        else:
            print("Failed to send location data. Status code:", response.status_code)
    except Exception as e:
        print("An error occurred while sending location data:", e)


# Example usage
if __name__ == "__main__":
    while True:
        latitude, longitude = get_location()
        print(latitude, longitude)
        # latitude = 37.7749
        # longitude = -122.4194
        send_location_data(latitude, longitude)
        time.sleep(5)  # Send data every 5 seconds
