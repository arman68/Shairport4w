/////////////////////////////////////////////////////////////////////////////////
// CAudioPlayer

#pragma once

#include "myQueue.h"

class 	CWavePlayThread;

///////////////////////////////////////////////////////////
// CAudioPlayer

class CAudioPlayer 
{
public:
	CAudioPlayer();
	~CAudioPlayer();

	// handle of a pipe or a file
	bool	Init(HANDLE hDataSource, UINT nDeviceID = WAVE_MAPPER, ULONG nFreq = 44100, ULONG nChannels = 2, ULONG nSampleSizeBits = 16);
	void	Close();

	void	Play();
	void	Pause();

	void		Mute(bool bMute);
	bool		IsMuted() const;
	
    static void GetDeviceList(std::map< UINT, std::pair<std::wstring, CComVariant> >& mapDevices);
    static void	GetFullAudioDeviceByShortName(std::wstring& strDevname, CComVariant* pVarAudioID = NULL);
    static int	GetWaveMapperID(CComVariant varSoundcardName, CComVariant* pVarAudioID = NULL);

	static void FadeSamples(void* pDest, const BYTE* pSrc, ULONG dwBytes, double lfVolume);

public:
	// the default implementation just copies the data over
	virtual void OnPlayAudio(BYTE* pStream, ULONG dwLen);

protected:
	CHandle								m_hAudioData;
	std::shared_ptr<CWavePlayThread>	m_threadWavePlay;
};

