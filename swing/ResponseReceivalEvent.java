
/// An event triggered by the receival of a response from the server
/**
Listeners of this event will be notified each time that the server responds to
a request.
*/
public class ResponseReceivalEvent implements EventDispatcher.Event {

	public static final String type = "ResponseReceivalEvent";

	/// The server's response
	public final String response;

	/// Creates a new event with the given response
	/**
	\param response The response received from the server
	*/
	public ResponseReceivalEvent(String response) {
		this.response = response;
	}

	public String getType() { return ResponseReceivalEvent.type; }

}
