#ifndef MULTIMEDIAASSET_H
#define MULTIMEDIAASSET_H

#include <iostream>
#include <string>

/// Abstract base class for every type of multimedia asset
class MultimediaAsset {

protected:

	/// The name of the asset
	/**
	This is different from the file name. It can be any arbitrary name that
	represents the asset.
	*/
	std::string name;

	/// The path to the asset's file
	/**
	This should be an absoltue path that allows one to retrieve the asset.
	*/
	std::string filePath;

public:

	/// Base constructor
	/**
	Creates a MultimediaAsset with the given name and path
	\param name The name of the new asset
	\param filePath The path of the new asset's file
	*/
	MultimediaAsset(std::string name = "", std::string filePath = "");

	/// Base destructor
	virtual ~MultimediaAsset();

	/// Prints information about the asset to the given stream
	/**
	\param stream The stream to which information should be output to
	*/
	virtual void printTo(std::ostream& stream) const;

	/// Used by subclasses to display the asset in an adequate way
	/**
	Each concrete subclass should override this method to provide an adequate
	way of displaying itself
	*/
	virtual void display() const = 0;

	/// Getter
	/**
	Returns the asset's name
	\return name
	*/
	std::string getName() const { return name; }

	/// Setter
	/**
	Sets a new name to the asset
	\param newName The name to be set
	*/
	void setName(std::string newName) { name = newName; }

	/// Getter
	/**
	Returns the asset's file path
	\return file path
	*/
	std::string getFilePath() const { return filePath; }

	/// Setter
	/**
	Sets a new file path to the asset
	\param newFilePath The file path to be set
	*/
	void setFilePath(std::string newFilePath) { filePath = newFilePath; }
};

/// Type used to refer to a shared pointer to MultimediaAsset
using MultimediaAssetPtr = std::shared_ptr<MultimediaAsset>;

#endif
