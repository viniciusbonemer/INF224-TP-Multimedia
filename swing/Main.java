
/// Class containing the main function
public final class Main {

	/// The host used for communication with the server
	private static final String DEFAULT_HOST = "localhost";

	/// The port used for communication with the server
	private static final int DEFAULT_PORT = 3331;

	/// The client that communicates to the server
	private static Client client = null;

	/// The controller responsible for the main window of the program
	private static MainController controller = null;

	public static void main(String argv[]) {
		String host = DEFAULT_HOST;
		int port = DEFAULT_PORT;

		try {
			client = new Client(host, port);
		} catch (Exception e) {
			System.err.println("Client: Couldn't connect to " + host + ":" + port);
			System.exit(1);
		}

		System.out.println("Client connected to " + host + ":" + port);

		Main.controller = new MainController(client);
		controller.mainLoop();
	}
}
