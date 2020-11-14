
/// The controller responsible for the main window of the program
/**
To use this class, first create a new controller giving it a connected client.
Then, call it's mainLoop() method to activate the UI. This method will only return
when the program has finished executing.
*/
class MainController implements EventDispatcher.Listener {

	/// The main window of the program
	private MainWindow window = null;

	/// The client used for server communication
	private Client client = null;

	/// Creates a new controller with the given client
	/**
	This is the client that is going to be used for server communication.
	\param client The client that should be used for server communication
	*/
	public MainController(Client client) {
		this.client = client;
		this.window = new MainWindow();

		setUp();
	}

	/// Configures the events subscriptions
	private void setUp() {
		EventDispatcher.instance.addListener(MainWindow.ConfirmButtonPressEvent.type, this);
		EventDispatcher.instance.addListener(MainWindow.ExitButtonPressEvent.type, this);
		EventDispatcher.instance.addListener(ResponseReceivalEvent.type, this);
	}

	/// Starts the program's mainLoop
	/**
	This is a blocking method. This method will activate the UI and will never return.
	*/
	public void mainLoop() {
		window.mainLoop();
	}

	public void eventOccurred(EventDispatcher.Event event) {

		if (event.getType().equals(MainWindow.ConfirmButtonPressEvent.type)) {
			confirmButtonPressEventOccured((MainWindow.ConfirmButtonPressEvent) event);

		} else if (event.getType().equals(MainWindow.ExitButtonPressEvent.type)) {
			exitButtonPressEventOccured((MainWindow.ExitButtonPressEvent) event);

		} else if (event.getType().equals(ResponseReceivalEvent.type)) {
			responseReceivalEventOccured((ResponseReceivalEvent) event);

		} else {
			System.out.println("MainController received unexpected event of type " + event.getType());
			System.exit(-1);
		}

	}

	/// Constructs an operation to be performed on the server
	/**
	\param action The action that should be performed by the operation
	\param name The name of the asset related to the operation
	\return The new operation that executes the given action on an object with the
	given name
	*/
	private Operations.Operation getOperation(MainWindow.ActionOption action, String name) {
		switch (action) {
		case PRINT_ASSET:	return new Operations.SearchAsset(name);
		case PRINT_GROUP:	return new Operations.SearchGroup(name);
		case PLAY_ASSET:	return new Operations.PlayAsset(name);
		}
		System.exit(-1);
		return null;
	}

	/// Reacts to the pressing of the confirm button
	/**
	This method gets the current information in the UI and uses it to ask the client
	to perform a new operation.
	*/
	private void confirmButtonPressEventOccured(MainWindow.ConfirmButtonPressEvent event) {
		String name = window.getName();
		MainWindow.ActionOption action = window.getActionOption();
		Operations.Operation operation = getOperation(action, name);
		client.performOperation(operation);
	}

	/// Reacts to the pressing of the exit button
	/**
	This method terminates execution.
	*/
	private void exitButtonPressEventOccured(MainWindow.ExitButtonPressEvent event) {
		System.exit(0);
	}

	/// Reacts to the receival of a response from the server
	private void responseReceivalEventOccured(ResponseReceivalEvent event) {
		window.setResponse(event.response);
	}

}
