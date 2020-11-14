
/// Namespace for the operations that can be performed on the server
/**
\see Client::performOperation()
*/
public class Operations {

	private Operations() {}

	/// Common interface for all operations
	public interface Operation {

		/// Get the type of the operation
		/**
		This type should be a unique identifier for this operation.
		\return The operation type
		*/
		public String getType();

		/// Returns an encoded version of the operation
		/**
		This returned string should be encoded in a way that allows it to be directly
		sent to the server.
		\return The encoded versino of the operation
		*/
		public String encoded();

	}

	/// An operation to search an asset
	/**
	Use this operation to search a multimedia asset in the server
	*/
	public static class SearchAsset implements Operation {

		public final static String type = "SearchAsset";

		/// The name of the asset to be searched
		public final String name;

		/// Creates a new `SearchAsset` operation for the given asset name
		/**
		\param name The name of the asset to be searched
		*/
		public SearchAsset(String name) {
			this.name = name;
		}

		public String getType() {
			return SearchAsset.type;
		}

		public String encoded() {
			return "pa:" + name;
		}

	}

	/// An operation to search a group
	/**
	Use this operation to search a multimedia group in the server
	*/
	public static class SearchGroup implements Operation {

		public final static String type = "SearchGroup";

		/// The name of the group to be searched
		public final String name;

		/// Creates a new `SearchGroup` operation for the given group name
		/**
		\param name The name of the group to be searched
		*/
		public SearchGroup(String name) {
			this.name = name;
		}

		public String getType() {
			return SearchGroup.type;
		}

		public String encoded() {
			return "pg:" + name;
		}

	}

	/// An operation to play an asset
	/**
	Use this operation to play a multimedia asset in the server
	*/
	public static class PlayAsset implements Operation {

		public final static String type = "PlayAsset";

		/// The name of the asset to be played
		public final String name;

		/// Creates a new `PlayAsset` operation for the given asset name
		/**
		\param name The name of the asset to be played
		*/
		public PlayAsset(String name) {
			this.name = name;
		}

		public String getType() {
			return PlayAsset.type;
		}

		public String encoded() {
			return "da:" + name;
		}

	}

}
