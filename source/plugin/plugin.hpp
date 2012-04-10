
//============================================================================
// Name        : plugin.hpp
// Copyright   : 2012 FIX94
//============================================================================

#ifndef _PLUGIN_HPP_
#define _PLUGIN_HPP_

#include <fstream>
#include <iostream>
#include <string>

#include "config/config.hpp"
#include "safe_vector.hpp"

using namespace std;

class Plugin
{
public:
	bool AddPlugin(Config &plugin);
	u8* GetBannerSound(u32 magic);
	u32 GetBannerSoundSize();
	char* GetDolName(u32 magic);
	void init(string);
	void Cleanup();
	void EndAdd();
private:
	safe_vector<u8*> BannerSound;
	safe_vector<u32> BannerSoundSize;
	safe_vector<u32> magicWords;
	safe_vector<string> DolName;
	u8 banner_pos;
	string pluginsDir;
	bool adding;
};
#endif