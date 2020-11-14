#ifndef PHOTO_H
#define PHOTO_H

#include "MultimediaAsset.h"

/// A multimedia Photo
class Photo: public MultimediaAsset {

private:

	/// The latitue of the photo
	float latitude;

	/// The longitude of the photo
	float longitude;

public:

	/// Constructor
	/**
	Creates a Photo with the given name, path, latitude and longitude
	\param name The name of the new photo
	\param filePath The path of the new photo's file
	\param latitude The latitude of the new photo
	\param longitude The longitude of the new photo
	*/
	Photo(std::string name = "", std::string filePath = "", float latitude = 0,
		float longitude = 0);

	/// Destructor
	virtual ~Photo();

	virtual void printTo(std::ostream& stream) const override;

	/// Displays the photo in Preview
	virtual void display() const override;

	/// Getter
	/**
	Returns the photo's latitude
	\return latitude
	*/
	float getLatitude() const { return latitude; }

	/// Setter
	/**
	Sets a latitude to the photo
	\param newLatitude The latitude to be set
	*/
	void setLatitude(float newLatitude) { latitude = newLatitude; }

	/// Getter
	/**
	Returns the photo's longitude
	\return longitude
	*/
	float getLongitude() const { return longitude; }

	/// Setter
	/**
	Sets a longitude to the photo
	\param newLongitude The longitude to be set
	*/
	void setLongitude(float newLongitude) { longitude = newLongitude; }

};

/// Type used to refer to a shared pointer to Photo
using PhotoPtr = std::shared_ptr<Photo>;

#endif
