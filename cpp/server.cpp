#include <memory>
#include <string>
#include <iostream>
#include <sstream>

#include "tcpserver.h"
#include "RequestProcessor.h"

const int PORT = 3331;

int main(int argc, char* argv[]) {
	// cree le TCPServer
	std::shared_ptr<cppu::TCPServer> server(new cppu::TCPServer());

	// cree l'objet qui gère les données
	std::shared_ptr<RequestProcessor> requestProcessor(new RequestProcessor());
	// MultimediaFactoryPtr factory = requestProcessor->getFactory();
	// factory->createPhoto("Photo", "~/Downloads/Photo.jpg");

	// le serveur appelera cette méthode chaque fois qu'il y a une requête
	server->setCallback(*requestProcessor, &RequestProcessor::processRequest);

	// Populate the factory
	{
		auto factory = requestProcessor->getFactory();
		auto photo = factory->createPhoto("image", "sample_assets/image.png");
		auto video = factory->createVideo("video", "sample_assets/video.mov");
		auto group = factory->createGroup("all");
		group->push_back(photo);
		group->push_back(video);
	}

	// lance la boucle infinie du serveur
	std::cout << "Starting Server on port " << PORT << std::endl;
	int status = server->run(PORT);

	// en cas d'erreur
	if (status < 0) {
		std::cerr << "Could not start Server on port " << PORT << std::endl;
		return 1;
	}

	return 0;
}
