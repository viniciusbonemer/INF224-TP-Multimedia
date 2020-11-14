//
// Based on:
// Client Java pour communiquer avec le Serveur C++
// eric lecolinet - telecom paristech - 2015
//

import java.io.*;
import java.net.*;


public final class Client {

	private static final long serialVersionUID = 1L;

	private Socket sock;
	private BufferedReader input;
	private BufferedWriter output;

	public Client(String host, int port) throws UnknownHostException, IOException {
		try {
			sock = new java.net.Socket(host, port);
		} catch (java.net.UnknownHostException e) {
			System.err.println("Client: Couldn't find host " + host + ":" + port);
			throw e;
		} catch (java.io.IOException e) {
			System.err.println("Client: Couldn't reach host " + host + ":" + port);
			throw e;
		}

		try {
			input = new BufferedReader(new InputStreamReader(sock.getInputStream()));
			output = new BufferedWriter(new OutputStreamWriter(sock.getOutputStream()));
		} catch (java.io.IOException e) {
			System.err.println("Client: Couldn't open input or output streams");
			throw e;
		}
	}

	/// Asks the client to perform the given operation on the server
	/**
	The action is sent to the server and a `ResponseReceivalEvent` is triggered
	with the server's response.
	\param operation The operation to be sent to the server
	*/
	public void performOperation(Operations.Operation operation) {
		String request = operation.encoded();
		System.out.print("Request: " + request);

		String response = send(request);
		System.out.println("Response: " + response);

		EventDispatcher.instance.triggerEvent(new ResponseReceivalEvent(response));
	}

	/// Sends the request to the server and returns the result
	/**
	\param request The request to be sent to the server
	\return The server's response
	*/
	private String send(String request) {
		// Envoyer la requete au serveur
		try {
			request += "\n";  // ajouter le separateur de lignes
			output.write(request, 0, request.length());
			output.flush();
		} catch (java.io.IOException e) {
			System.err.println("Client: Couldn't send message: " + e);
			return null;
		}

		// Recuperer le resultat envoye par le serveur
		try {
			return input.readLine();
		} catch (java.io.IOException e) {
			System.err.println("Client: Couldn't receive message: " + e);
			return null;
		}
	}
}
