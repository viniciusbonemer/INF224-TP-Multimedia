import java.awt.BorderLayout;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyEvent;
import javax.swing.*;

/// The main window of the program
/**
To use this class, instantiate a new object and call it's mainLoop() method to
display the UI. This is a blocking event. Use getName(), getResponse() and
getActionOption() to get information from the UI or the set equivalents to
update the UI.
*/
public final class MainWindow extends JFrame {

	private static final long serialVersionUID = 1L;

	/// Indicates if the program is running on MacOS
	/**
	This can be used to correctly configure the menu bar fro mac os.
	*/
	private static final boolean systemIsMacOS = System.getProperty("os.name").equals("Mac OS X");

	private JRadioButton printAssetOption = null;
	private JRadioButton printGroupOption = null;
	private JRadioButton playAssetOption = null;

	private JTextField nameLabel = null;
	private JTextField responseLabel = null;

	private JTextField nameTextField = null;
	private JTextArea  responseTextArea = null;

	/// The action performed by the confirm button and confirm menu item
	private Action confirmAction = null;

	/// The action performed by the exit button and exit menu item
	private Action exitAction = null;

	private JButton confirmButton = null;
	private JButton exitButton = null;

	/// Create a new window
	/**
	After creating the window, mainLoop() has to be called before the UI is shown.
	*/
	public MainWindow() {
		if (MainWindow.systemIsMacOS) {
			System.setProperty("apple.laf.useScreenMenuBar", "true");
		}
		setDefaultCloseOperation(EXIT_ON_CLOSE);

		createTextArea();
		createRadioButtons();

		createActions();
		createButtons();
		createMenuBar();

		setUpHierarchy();
	}

	/// Enters the program's main loop
	/**
	This is a blocking method. It will cause the UI to appear.
	*/
	public void mainLoop() {
		pack();
		setVisible(true);
	}

	/// Returns the name currently in the name text field
	public String getName() { return nameTextField.getText(); }

	/// Sets the name in the name text field
	/**
	\param newName The new name to be set in the text field
	*/
	public void setName(String newName) { nameTextField.setText(newName); }

	/// Returns the response currently in the response text field
	public String getResponse() { return responseTextArea.getText(); }

	/// Sets the response in the response text field
	/**
	\param newResponse The new response to be set in the text field.
	*/
	public void setResponse(String newResponse) {
		responseTextArea.setText(newResponse);
		revalidate();
		repaint();
	}

	/// Returns the currently selected action option
	/**
	The options are selected through the radio buttons and represented by the
	equivalent type in ActionOption.
	*/
	public ActionOption getActionOption() {
		if (printAssetOption.isSelected()) {
			return ActionOption.PRINT_ASSET;
		} else if (printGroupOption.isSelected()) {
			return ActionOption.PRINT_GROUP;
		} else {
			return ActionOption.PLAY_ASSET;
		}
	}

	private void createTextArea() {
		nameLabel = new JTextField("Name:");
		responseLabel = new JTextField("Response:");

		nameTextField = new JTextField();
		responseTextArea = new JTextArea(3, 30);

		nameLabel.setEditable(false);
		responseLabel.setEditable(false);
		responseTextArea.setEditable(false);
	}

	private void createRadioButtons() {
		printAssetOption = new JRadioButton("Print Asset", true);
		printGroupOption = new JRadioButton("Print Group");
		playAssetOption = new JRadioButton("Play Asset");

		ButtonGroup group = new ButtonGroup();
		group.add(printAssetOption);
		group.add(printGroupOption);
		group.add(playAssetOption);
	}

	private void createActions() {
		confirmAction = new ConfirmAction();
		exitAction = new ExitAction();
	}

	private void createButtons() {
		confirmButton = new JButton(confirmAction);
		exitButton = new JButton(exitAction);
	}

	private void createMenuBar() {
		JMenu optionsMenu = new JMenu("Options");

		JMenuItem confirmMenuItem = new JMenuItem(confirmAction);
		JMenuItem exitMenuItem = new JMenuItem(exitAction);

		optionsMenu.add(confirmMenuItem);
		optionsMenu.add(exitMenuItem);

		JMenuBar menuBar = new JMenuBar();
		menuBar.add(optionsMenu);
		setJMenuBar(menuBar);
	}

	private void setUpHierarchy() {
		setLayout(new BorderLayout());

		JPanel radioPanel = new JPanel(new GridLayout(1, 3));
		radioPanel.add(printAssetOption);
		radioPanel.add(printGroupOption);
		radioPanel.add(playAssetOption);
		add(radioPanel, BorderLayout.NORTH);

		JPanel bottomPanel = new JPanel();
		bottomPanel.setLayout(new BoxLayout(bottomPanel, BoxLayout.X_AXIS));
		bottomPanel.add(exitButton);
		bottomPanel.add(confirmButton);
		add(bottomPanel, BorderLayout.SOUTH);

		JPanel topPanel = new JPanel(new SpringLayout());
		topPanel.add(nameLabel);
		topPanel.add(nameTextField);
		topPanel.add(responseLabel);
		topPanel.add(new JScrollPane(responseTextArea));

		SpringUtilities.makeCompactGrid(topPanel,
																		2, 2,  // rows, cols
																		5, 5,  // leftMargin, topMargin
																		5, 5); // hPadding, vPadding
		add(topPanel, BorderLayout.CENTER);
	}

	/// The action options to be performed
	/**
	Each case is equivalent to one of the radio buttons
	*/
	public enum ActionOption {
		PRINT_ASSET,
		PRINT_GROUP,
		PLAY_ASSET
	}

	/// The action performed by the confirm button and confirm menu item
	/**
	This action emmits a `ConfirmButtonPressEvent`
	*/
	private final class ConfirmAction extends AbstractAction {

		ConfirmAction() {
			super("Confirm");
		}

		public void actionPerformed(ActionEvent e) {
			EventDispatcher.instance.triggerEvent(new ConfirmButtonPressEvent());
		}

	}

	/// The event triggered when the confirm button is pressed
	public final class ConfirmButtonPressEvent implements EventDispatcher.Event {

		public static final String type = "ConfirmButtonPressEvent";

		public ConfirmButtonPressEvent() { }

		public String getType() { return ConfirmButtonPressEvent.type; }
	}

	/// The action performed by the exit button and exit menu item
	/**
	This action emmits a `ExitButtonPressEvent`
	*/
	private final class ExitAction extends AbstractAction {

		ExitAction() {
			super("Exit");
		}

		public void actionPerformed(ActionEvent e) {
			EventDispatcher.instance.triggerEvent(new ExitButtonPressEvent());
		}

	}

	/// The event triggered when the exit button is pressed
	public final class ExitButtonPressEvent implements EventDispatcher.Event {

		public static final String type = "ExitButtonPressEvent";

		public ExitButtonPressEvent() { }

		public String getType() { return ExitButtonPressEvent.type; }
	}

}
