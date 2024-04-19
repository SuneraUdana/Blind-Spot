from flask import Flask, render_template, request

app = Flask(__name__)
app.secret_key = 'your_secret_key'  # Change this to a secure key


def get_location():
    with open("location_data.txt", "r") as file:
        # timestamp = datetime.datetime.now().strftime("%Y-%m-%d %H:%M:%S")
        fl = file.readlines()[0].split(',')
        lat = fl[0]
        # print(lat)
        lon = fl[1]

    return lat, lon

def get_object():
    with open("object.txt", "r") as file:
        # timestamp = datetime.datetime.now().strftime("%Y-%m-%d %H:%M:%S")
        fl = file.readlines()[0]

    return fl

@app.route('/')
def hello_world():
    latitude, longitude = get_location()
    object = get_object()
    return render_template('index.html', latitude=latitude, longitude=longitude, object=object)




@app.route('/receive_location_data', methods=['POST'])
def receive_location_data():
    data = request.json
    latitude = data.get('latitude')
    longitude = data.get('longitude')
    if latitude is not None and longitude is not None:
        with open("location_data.txt", "w") as file:
            file.write(f"{latitude},{longitude}\n")
        return "Location data received and saved successfully", 200
    else:
        return "Invalid data received", 400

@app.route('/receive_object', methods=['POST'])
def receive_object():
    data = request.json
    object = data.get('object')
    if object is not None and object is not None:
        with open("object.txt", "w") as file:
            file.write(f"{object}\n")
        return "Object data received and saved successfully", 200
    else:
        return "Invalid data received", 400


if __name__ == '__main__':
    app.run(debug=True)
