package studio6;

//import assignment5.SerialComm;
import jssc.*;

public class SerialComm {

	static SerialPort port;

	private boolean debug;  // Indicator of "debugging mode"
	
	// This function can be called to enable or disable "debugging mode"
	void setDebug(boolean mode) {
		debug = mode;
	}	
	

	// Constructor for the SerialComm class
	public SerialComm(String name) throws SerialPortException {
		port = new SerialPort(name);		
		port.openPort();
		port.setParams(SerialPort.BAUDRATE_9600,
			SerialPort.DATABITS_8,
			SerialPort.STOPBITS_1,
			SerialPort.PARITY_NONE);
		
		debug = true; // Default is to NOT be in debug mode
	}
		
	// TODO: Add writeByte() method from Studio 5
	
	void writeByte(byte i) throws SerialPortException
	{
		
		if(debug==true)
		{
			String hex=Integer.toHexString(i);
			//System.out.print("<0x");
			System.out.println(hex);
			//System.out.println(">");
			
		}
		//port.writeByte(i);
		
			
		}
	
	// TODO: Add available() method
	boolean available() throws SerialPortException
	{
		if (port.getInputBufferBytesCount()>0)
		{
			return true;
		}else {
			return false;
		}
		
	}
	// TODO: Add readByte() method	
	byte readByte() throws SerialPortException
	{
		
		return port.readBytes(1)[0];
		
	}
	public static void main(String[] args) throws SerialPortException
	{
		SerialComm port = new SerialComm("/dev/cu.usbserial-DN02ZB5N");
		
		while(true)
		{
			if(port.available())
			{
				byte input=port.readByte();
				System.out.println((char)input);
				//port.writeByte(input);
			} 
			
			
		}
		
	}
	

}
