import java.util.Hashtable;
import java.util.ArrayList;

/// Singleton dispatcher for common events
/**
Use this class to trigger events or register as listener for a desired event type
*/
public class EventDispatcher {

	/// Mapping of unique event identifiers to listeners
	private Hashtable<String, ArrayList<Listener>> listeners;

	/// The single available instance of `EventDispatcher`
	public static EventDispatcher instance = new EventDispatcher();

	/// Creates a simple `EventDispatcher`
	private EventDispatcher() {
		listeners = new Hashtable<String, ArrayList<Listener>>();
	}

	/// Adds a new listener
	/**
	The given event type is a string that uniquely identifies an event. Using an
	unexpected identifier will prevent the type from being notified of the correct
	event.
	\param eventType The unique identifier for the event to be observed
	\param listener The object to be notified when the event happens
	\see Event::getType()
	*/
	public void addListener(String eventType, Listener listener) {
		ArrayList<Listener> subscribed = listeners.get(eventType);

		if (subscribed == null) {
			subscribed = new ArrayList<Listener>();
			listeners.put(eventType, subscribed);
		}

		subscribed.add(listener);
	}

	/// Triggers an event
	/**
	This method notifies the listeners of this event's type.
	\param event The event which listeners should be notified of
	*/
	public void triggerEvent(Event event) {
		String eventType = event.getType();
		ArrayList<Listener> subscribed = listeners.get(eventType);

		if (subscribed == null) { return; }

		for (Listener listener : subscribed) {
			listener.eventOccurred(event);
		}
	}

	/// Common interface for all classes willing to be notified of an event
	public interface Listener {

		/// Notifies that an event has occurred
		/**
		The event passed as parameter will always be an instance of some class implementing
		the `Event` interface for which `addListener` has been previioulsy called.
		\param event The event that occurred
		*/
		void eventOccurred(Event event);
	}

	/// Common interface for all events
	public interface Event {

		/// The type of the event
		/**
		This type should be an unique identifier for this event. The valued returned
		here should be used to register to events of this type.
		\return The unique type identifier of this event
		*/
		String getType();
	}

}
