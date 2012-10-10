
#ifndef __TEXT_HPP
#define __TEXT_HPP

#include <vector>
#include <string>

#include "FreeTypeGX.h"
#include "video.hpp"
#include "memory/smartptr.hpp"
#include "wstringEx/wstringEx.hpp"

using namespace std;

struct SFont
{
	SmartBuf data;
	size_t dataSize;
	SmartPtr<FreeTypeGX> font;
	u32 lineSpacing;
	u32 weight;
	u32 index;
public:
	bool fromBuffer(u8 *buffer, u32 bufferSize, u32 size, u32 lspacing, u32 w = 0, u32 idx = 0, const char *genKey = NULL);
	bool fromFile(const char *filename, u32 size, u32 lspacing, u32 w = 0, u32 idx = 0);
	SFont(void) : data(SmartBuf(NULL, SmartBuf::SRCALL_MEM2)), dataSize(0), font(SmartPtr<FreeTypeGX>(new FreeTypeGX)), lineSpacing(0), weight(0), index(0) { }
	~SFont(void) { }
};

class CText
{
public:
	void setText(SFont font, const wstringEx &t);
	void setText(SFont font, const wstringEx &t, u32 startline);
	void setColor(const CColor &c);
	void setFrame(float width, u16 style, bool ignoreNewlines = false, bool instant = false);
	void tick(void);
	void draw(void);
	int getTotalHeight();
private:
	
	struct SWord
	{
		wstringEx text;
		Vector3D pos;
		Vector3D targetPos;
	};
private:
	typedef vector<SWord> CLine;
	vector<CLine> m_lines;
	SFont m_font;
	CColor m_color;
	u32 firstLine;
	u32 totalHeight;
};

// Nothing to do with CText. Q&D helpers for string formating.

enum {
	MAX_MSG_SIZE	= 1024,
	MAX_USES		= 8,
};

char *fmt(const char *format, ...);
std::string sfmt(const char *format, ...);
wstringEx wfmt(const wstringEx &format, ...);
bool checkFmt(const wstringEx &ref, const wstringEx &format);
std::string vectorToString(const vector<std::string> &vect, std::string sep);
wstringEx vectorToString(const vector<wstringEx> &vect, char sep);
vector<wstringEx> stringToVector(const wstringEx &text, char sep);
vector<std::string> stringToVector(const std::string &text, char sep);
std::string upperCase(std::string text);
std::string lowerCase(std::string text);
std::string ltrim(std::string s);
std::string rtrim(std::string s);
void Asciify( wchar_t *str );
void Asciify2( char *str );

#endif // !defined(__TEXT_HPP)
