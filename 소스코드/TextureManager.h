#pragma once
#include "ResourceManager.h"
#include <SFML/Graphics/Texture.hpp>
#include <filesystem>

class TextureManager: public ResourceManager<TextureManager, sf::Texture>{
public:
	TextureManager(): ResourceManager(std::experimental::filesystem::current_path().u8string() + "\\" + "textures.txt"){}

	sf::Texture* Load(const std::string& l_path){
		sf::Texture* texture = new sf::Texture();
		if(!texture->loadFromFile(l_path))
		{
			delete texture;
			texture = nullptr;
			std::cerr << "! Failed to load texture: " << l_path << std::endl;
		}
		return texture;
	}
}; 