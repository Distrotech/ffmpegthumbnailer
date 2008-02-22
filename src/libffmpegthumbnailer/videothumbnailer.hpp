//    Copyright (C) 2007 Dirk Vanden Boer <dirk.vdb@gmail.com>
//
//    This program is free software; you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation; either version 2 of the License, or
//    (at your option) any later version.
//
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    along with this program; if not, write to the Free Software
//    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

#ifndef VIDEO_THUMBNAILER_HPP
#define VIDEO_THUMBNAILER_HPP

#include <string>
#include <vector>
#include <map>
#include <inttypes.h>

typedef std::map<uint8_t, int> Histogram;

class VideoFrame;
class PngWriter;

class VideoThumbnailer
{
public:
    VideoThumbnailer();
	VideoThumbnailer(int thumbnailSize, uint16_t seekPercentage, bool filmStripOverlay, bool workaroundIssues);
	~VideoThumbnailer();

	void generateThumbnail(const std::string& videoFile, const std::string& outputFile);
    void generateThumbnail(const std::string& videoFile, std::vector<uint8_t>& buffer);

    void setThumbnailSize(int size);
    void setSeekPercentage(int percentage);
    void setFilmStripOverlay(bool enabled);
    void setWorkAroundIssues(bool workAround);
	
private:
    void generateThumbnail(const std::string& videoFile, PngWriter& pngWriter);
    void writePng(const std::string& videoFile, PngWriter& pngWriter, const VideoFrame& videoFrame, int duration, std::vector<uint8_t*>& rowPointers);
	
    std::string getMimeType(const std::string& videoFile);
	std::string getExtension(const std::string& videoFilename);

	void generateHistogram(const VideoFrame& videoFrame, Histogram& histogram);
	bool isDarkImage(const int numPixels, const Histogram& histogram);
	void overlayFilmStrip(VideoFrame& videoFrame);

private:
    int             m_ThumbnailSize;
    uint16_t        m_SeekPercentage;    
    bool            m_OverlayFilmStrip;
    bool            m_WorkAroundIssues;
};

#endif
