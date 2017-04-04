#include "texture_importer.h"
#include "halley/tools/assets/import_assets_database.h"
#include "halley/tools/file/filesystem.h"
#include "halley/file_formats/image.h"

using namespace Halley;

void TextureImporter::import(const ImportingAsset& asset, IAssetCollector& collector)
{
	// Update metadata
	Expects(asset.metadata);
	auto& meta = *asset.metadata;
	meta.set("compression", "png");

	// Get image
	Image image;
	Deserializer s(asset.inputFiles.at(0).data);
	s >> image;

	// Encode to PNG and save
	auto bytes = image.savePNGToBytes();
	auto span = gsl::as_bytes(gsl::span<const Byte>(bytes));
	collector.output(asset.assetId, AssetType::Texture, span, *asset.metadata);
}
