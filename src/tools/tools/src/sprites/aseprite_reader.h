#pragma once
#include <gsl/span>
#include <map>
#include <optional>


#include "aseprite_file.h"
#include "halley/text/halleystring.h"
#include "halley/maths/vector4.h"

namespace Halley
{
	class Path;
	class Image;
	struct ImageData;

	class AsepriteReader
	{
	public:
		static std::map<String, std::vector<ImageData>> importAseprite(String baseName, gsl::span<const gsl::byte> fileData, bool trim, bool groupSeparated);
		static void addImageData(int frameNumber, std::vector<ImageData>& frameData, std::unique_ptr<Image> frameImage,
		                  const AsepriteFile& aseFile, const String& baseName, const String& sequence,
		                  const String& direction,
		                  int duration, bool trim, bool hasFrameNumber, std::optional<String> group, bool firstImage,
		                  const String& spriteName);
	};
}
