import serial

def open_serial_port(port, baud_rate):
    try:
        ser = serial.Serial(port, baud_rate)
        print(f"Serial port {port} opened successfully at {baud_rate} baud.")
        return ser
    except serial.SerialException as e:
        print(f"Error opening serial port {port}: {e}")
        return None

if __name__ == "__main__":
    # Replace 'COM1' with your serial port (e.g., '/dev/ttyUSB0' on Linux)
    port_name = '/dev/ttyUSB0'
    baud_rate = 9600

    serial_port = open_serial_port(port_name, baud_rate)

    if serial_port is not None:
        try:
            while True:
                # Read data from the serial port (you may want to specify the number of bytes to read)
                data = serial_port.read()
                if data:
                    print("Received:", data)
        except KeyboardInterrupt:
            # Close the serial port when you stop the script
            serial_port.close()
            print("Serial port closed.")
        except serial.SerialException as e:
            print(f"Error reading from serial port {port_name}: {e}")
