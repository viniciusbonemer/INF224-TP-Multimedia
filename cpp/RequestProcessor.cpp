
#include "RequestProcessor.h"

RequestProcessor::RequestProcessor():
	factory(new MultimediaFactory())
	{ }

RequestProcessor::~RequestProcessor() {
	delete factory;
}

bool RequestProcessor::processRequest(cppu::TCPConnection& connection, const std::string& request, std::string& response) {
	std::cerr << "\nRequest: '" << request << "'" << std::endl;

	// Get the operation
	std::stringstream stream = std::stringstream(request);
	std::string op;
	std::getline(stream, op, ':');

	// Create a response stream
	std::stringstream responseStream = std::stringstream(response);

	// Delegate to the correct function
	if (op == "pa") {
		processPrintAssetRequest(connection, stream, responseStream);
	} else if (op == "pg") {
		processPrintGroupRequest(connection, stream, responseStream);
	} else if (op == "da") {
		processDisplayAssetRequest(connection, stream, responseStream);
	} else {
		responseStream << "Error. Syntax: <op>:<parameters>, where <op>='ca'|'cg'|'sa'|'sg'|'da'";
	}

	response = responseStream.str();
	std::cerr << "Response: " << response << std::endl;

	// renvoyer false si on veut clore la connexion avec le client
	return true;
}

bool RequestProcessor::processPrintAssetRequest(cppu::TCPConnection& connection,
																								std::stringstream& parameters,
																								std::stringstream& responseStream) {
	std::string name;
	getline(parameters, name, ':');

	auto lock = std::make_shared<cppu::TCPLock>(connection, true);
	factory->printAsset(name, responseStream);
	lock.reset();

	 return true;
}

bool RequestProcessor::processPrintGroupRequest(cppu::TCPConnection& connection,
																								std::stringstream& parameters,
																								std::stringstream& responseStream) {
	std::string name;
	std::getline(parameters, name, ':');

	auto lock = std::make_shared<cppu::TCPLock>(connection, true);
	factory->printGroup(name, responseStream);
	lock.reset();

	return true;;
}

bool RequestProcessor::processDisplayAssetRequest(cppu::TCPConnection& connection,
																									std::stringstream& parameters,
																									std::stringstream& responseStream) {
	std::string name;
	std::getline(parameters, name, ':');

	auto lock = std::make_shared<cppu::TCPLock>(connection, true);
	factory->displayAsset(name, responseStream);
	lock.reset();

	return true;
}
