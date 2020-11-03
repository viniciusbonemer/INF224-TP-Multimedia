#ifndef MULTIMEDIA_FACTORY_H
#define MULTIMEDIA_FACTORY_H

#include <map>

#include "MultimediaAsset.h"
#include "Photo.h"
#include "Video.h"
#include "Film.h"
#include "MultimediaGroup.h"

/// A factory of multimedia assets and groups
/**
A reference to every created member is kept.
*/
class MultimediaFactory {

private:

	/// Every created asset
	std::map<std::string, MultimediaAssetPtr> assets;

	/// Every created group
	std::map<std::string, MultimediaGroupPtr> groups;

public:

	/// Constructor
	/**
	Creates a new MultimediaFactory
	*/
	MultimediaFactory();

	/// Destructor
	virtual ~MultimediaFactory();

	/// Creates a new photo
	/**
	A reference to the created photo is stored. The parameters match those of the
	Photo's constructor.
	\see Photo()
	*/
	PhotoPtr createPhoto(std::string name, std::string filePath = "",
											 float latitude = 0, float longitude = 0);

	/// Creates a new video
	/**
	A reference to the created video is stored. The parameters match those of the
	Video's constructor.
	\see Video()
	*/
	VideoPtr createVideo(std::string name, std::string filePath = "",
											 int duration = 0);

	/// Creates a new film
	/**
	A reference to the created film is stored. The parameters match those of the
	Film's constructor.
	\see Film()
	*/
	FilmPtr createFilm(std::string name, std::string filePath = "",
										 int duration = 0, int *chapterDurations = nullptr,
										 int chaptersCount = 0);

	/// Creates a new group
	/**
	A reference to the created group is stored. The parameters match those of the
	MultimediaGroup's constructor.
	\see MultimediaGroup()
	*/
	MultimediaGroupPtr createGroup(std::string name);

	/// Prints information about the asset to the stream
	/**
	If the asset is not found, an error is printed to the stream.
	\param name The name of the asset from which information should be printed
	\param stream The stream to which information should be printed
	*/
	void printAsset(std::string name, std::ostream& stream) const;

	/// Prints information about the group to the stream
	/**
	If the group is not found, an error is printed to the stream.
	\param name The name of the group from which information should be printed
	\param stream The stream to which information should be printed
	*/
	void printGroup(std::string name, std::ostream& stream) const;

	/// Displays the given asset
	/**
	If the asset is not found, an error is printed to the stream.
	\param name The name of the asset to display
	\param stream The stream to which eventual errors should be printed
	*/
	void displayAsset(std::string name, std::ostream& stream) const;

};

#endif
