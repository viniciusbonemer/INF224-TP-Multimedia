#include <memory>
#include <string>
#include <iostream>
#include <sstream>

#include "cppsocket.h"
#include "RequestProcessor.h"

static const std::string HOST = "localhost";
static const int PORT = 3331;

///
/// Lit une requete depuis le Terminal, envoie cette requete au serveur,
/// recupere sa reponse et l'affiche sur le Terminal.
/// Noter que le programme bloque si le serveur ne repond pas.
///

int main() {
  cppu::Socket sock;
  cppu::SocketBuffer sockbuf(sock);

  int status = sock.connect(HOST, PORT);

  if (status < 0) {
    switch (status) {
      case cppu::Socket::Failed:
        std::cerr << "Client: Couldn't reach host "<<HOST<<":"<<PORT << std::endl;
        return 1;
      case cppu::Socket::UnknownHost:
        std::cerr << "Client: Couldn't find host "<<HOST<<":"<<PORT << std::endl;
        return 1;
      default:
        std::cerr << "Client: Couldn't connect host "<<HOST<<":"<<PORT << std::endl;
        return 1;
    }
  }

  std::cout << "Client connected to "<< HOST<<":"<<PORT << std::endl;

  while (std::cin) {
    std::cout << "Request: ";
    std::string request, response;

    std::getline(std::cin, request);
    if (request == "quit") return 0;

    // Envoyer la requete au serveur
    if (sockbuf.writeLine(request) < 0) {
      std::cerr << "Client: Couldn't send message" << std::endl;
      return 2;
    }

    // Recuperer le resultat envoye par le serveur
    if (sockbuf.readLine(response) < 0) {
      std::cerr << "Client: Couldn't receive message" << std::endl;
      return 2;
    }

    // Le serveur remplace les '\n' par des ';' car '\n' sert a indiquer la
    // fin d'un message entre le client et le serveur
    // On fait ici la transformation inverse
    replace(response.begin(), response.end(), ';', '\n');

    std::cout << "Response: " << response << std::endl;
  }
}
