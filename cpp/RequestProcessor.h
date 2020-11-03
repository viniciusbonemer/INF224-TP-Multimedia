#ifndef REQUESTPROCESSOR_H
#define REQUESTPROCESSOR_H

#include <memory>
#include <string>
#include <iostream>
#include <sstream>

#include "tcpserver.h"
#include "MultimediaFactory.h"

class RequestProcessor {

private:
	MultimediaFactory *factory;

	void performOperation(std::string&, const std::string&, std::stringstream&);

	// bool processCreateAssetRequest(cppu::TCPConnection& connection, const std::stringstream& parameters, std::stringstream& responseStream);
//
	// bool processCreateGroupRequest(cppu::TCPConnection& connection, const std::stringstream& parameters, std::stringstream& responseStream);
//
	bool processPrintAssetRequest(cppu::TCPConnection& connection,
																std::stringstream& parameters,
																std::stringstream& responseStream);

	bool processPrintGroupRequest(cppu::TCPConnection& connection,
																std::stringstream& parameters,
																std::stringstream& responseStream);

	bool processDisplayAssetRequest(cppu::TCPConnection& connection,
																	std::stringstream& parameters,
																	std::stringstream& responseStream);

public:

	RequestProcessor();

	virtual ~RequestProcessor();

	/* Cette méthode est appelée chaque fois qu'il y a une requête à traiter.
	* Ca doit etre une methode de la classe qui gere les données, afin qu'elle
	* puisse y accéder.
	*
	* Arguments:
	* - 'request' contient la requête
	* - 'response' sert à indiquer la réponse qui sera renvoyée au client
	* - si la fonction renvoie false la connexion est close.
	*
	* Cette fonction peut etre appelée en parallele par plusieurs threads (il y a
	* un thread par client).
	*
	* Pour eviter les problemes de concurrence on peut créer un verrou en creant
	* une variable Lock **dans la pile** qui doit etre en mode WRITE (2e argument = true)
	* si la fonction modifie les donnees.
	*/
	bool processRequest(cppu::TCPConnection& connection, const std::string& request, std::string& response);

};

#endif
