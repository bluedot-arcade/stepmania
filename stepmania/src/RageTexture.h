#ifndef RAGE_TEXTURE_H
#define RAGE_TEXTURE_H
/*
-----------------------------------------------------------------------------
 Class: RageTexture

 Desc: Abstract class for a texture and metadata.

 Copyright (c) 2001-2002 by the person(s) listed below.  All rights reserved.
	Chris Danford
-----------------------------------------------------------------------------
*/


#include "RageTypes.h"


/* A unique texture is identified by a RageTextureID.  (Loading the
 * same file with two different dither settings is considered two
 * different textures, for example.)  See RageTexture.cpp for explanations
 * of these. */
struct RageTextureID
{
	CString filename;
	int iMaxSize;
	int iMipMaps;
	int iAlphaBits;
	int iColorDepth;
	int iTransparencyOnly;
	bool bDither;
	bool bStretch;
	bool bHotPinkColorKey; /* #FF00FF */

	bool operator< (const RageTextureID &rhs) const;
	bool operator== (const RageTextureID &rhs) const;

	void Init();

	RageTextureID() { Init(); }
	RageTextureID(const CString &fn) { Init(); filename=fn; }
};

//-----------------------------------------------------------------------------
// RageTexture Class Declarations
//-----------------------------------------------------------------------------
class RageTexture
{
public:
	RageTexture( RageTextureID file );
	virtual ~RageTexture() = 0;
	virtual void Update( float fDeltaTime ) {}
	virtual void Reload() {}
	virtual void Invalidate() { }	/* only called by RageTextureManager::InvalidateTextures */
	virtual unsigned GetTexHandle() const = 0;	// accessed by RageDisplay

	// movie texture/animated texture stuff
	virtual void Play() {}
	virtual void Stop() {}
	virtual void Pause() {}
	virtual void SetPosition( float fSeconds ) {}
	virtual void SetPlaybackRate( float fRate ) {}
	virtual bool IsAMovie() const { return false; }
	virtual bool IsPlaying() const { return false; }
	void SetLooping(bool looping) { }

	int GetSourceWidth() const	{return m_iSourceWidth;}
	int GetSourceHeight() const {return m_iSourceHeight;}
	int GetTextureWidth() const {return m_iTextureWidth;}
	int GetTextureHeight() const{return m_iTextureHeight;}
	int GetImageWidth() const	{return m_iImageWidth;}
	int GetImageHeight() const	{return m_iImageHeight;}

	int GetFramesWide() const	{return m_iFramesWide;}
	int GetFramesHigh() const	{return m_iFramesHigh;}

	int GetSourceFrameWidth() const		{return GetSourceWidth()	/	GetFramesWide();}
	int GetSourceFrameHeight() const	{return GetSourceHeight()	/	GetFramesHigh();}
	int GetTextureFrameWidth() const	{return GetTextureWidth()	/	GetFramesWide();}
	int GetTextureFrameHeight() const	{return GetTextureHeight()	/	GetFramesHigh();}
	int GetImageFrameWidth() const		{return GetImageWidth()		/	GetFramesWide();}
	int GetImageFrameHeight() const		{return GetImageHeight()	/	GetFramesHigh();}

	/* Use these to convert between the different coordinate systems: */
	float GetSourceToImageCoordsRatio() const { return float(GetImageWidth()) / GetSourceWidth(); }
	float GetImageToTexCoordsRatio() const { return 1.0f / GetTextureWidth(); }
	float GetSourceToTexCoordsRatio() const { return GetSourceToImageCoordsRatio() * GetImageToTexCoordsRatio(); }

	const RectF *GetTextureCoordRect( int frameNo ) const;
	int   GetNumFrames() const { return m_iFramesWide*m_iFramesHigh; }

	/* Used by RageTextureManager.  Order is important; see RageTextureManager.cpp. */
	enum TexPolicy { TEX_CACHED, TEX_VOLATILE, TEX_DEFAULT } m_Policy;
	int		m_iRefCount;
	bool	m_bWasUsed;

	/* The ID that we were asked to load: */
	const RageTextureID &GetID() const { return m_ID; }

	static void GetFrameDimensionsFromFileName( CString sPath, int* puFramesWide, int* puFramesHigh );
	static int GetFrameCountFromFileName( CString sPath );

private:
	/* We might change settings when loading (due to hints, hardware
	 * limitations, etc).  The data actually loaded is here: */
	RageTextureID m_ID;

protected:

	int		m_iSourceWidth,		m_iSourceHeight;	// dimensions of the original image loaded from disk
	int		m_iTextureWidth,	m_iTextureHeight;	// dimensions of the texture in memory
	int		m_iImageWidth,		m_iImageHeight;		// dimensions of the image in the texture
	int		m_iFramesWide,		m_iFramesHigh;		// The number of frames of animation in each row and column of this texture
	vector<RectF>	m_TextureCoordRects;	// size = m_iFramesWide * m_iFramesHigh

	virtual void CreateFrameRects();
};

#endif
