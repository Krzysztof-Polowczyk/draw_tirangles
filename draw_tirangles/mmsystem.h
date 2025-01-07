/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _INC_MMSYSTEM
#define _INC_MMSYSTEM

#include <_mingw_unicode.h>
#include <pshpack1.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifndef _WINMM_
#define WINMMAPI DECLSPEC_IMPORT
#else
#define WINMMAPI
#endif
#define _loadds
#define _huge

#define MAXPNAMELEN 32
#define MAXERRORLENGTH 256
#define MAX_JOYSTICKOEMVXDNAME 260

    typedef UINT MMVERSION;
    typedef UINT MMRESULT;

#define _MMRESULT_

#ifndef DEFINED_LPUINT
#define DEFINED_LPUINT
    typedef UINT* LPUINT;
#endif

    typedef struct mmtime_tag {
        UINT wType;
        union {
            DWORD ms;
            DWORD sample;
            DWORD cb;
            DWORD ticks;
            struct {
                BYTE hour;
                BYTE min;
                BYTE sec;
                BYTE frame;
                BYTE fps;
                BYTE dummy;
                BYTE pad[2];
            } smpte;
            struct {
                DWORD songptrpos;
            } midi;
        } u;
    } MMTIME, * PMMTIME, NEAR* NPMMTIME, * LPMMTIME;

#define TIME_MS 0x0001
#define TIME_SAMPLES 0x0002
#define TIME_BYTES 0x0004
#define TIME_SMPTE 0x0008
#define TIME_MIDI 0x0010
#define TIME_TICKS 0x0020

#ifndef MAKEFOURCC
#define MAKEFOURCC(ch0,ch1,ch2,ch3)				\
  ((DWORD)(BYTE)(ch0) | ((DWORD)(BYTE)(ch1) << 8) | 		\
   ((DWORD)(BYTE)(ch2) << 16) | ((DWORD)(BYTE)(ch3) << 24))
#endif /* MAKEFOURCC */

#define MM_JOY1MOVE 0x3A0
#define MM_JOY2MOVE 0x3A1
#define MM_JOY1ZMOVE 0x3A2
#define MM_JOY2ZMOVE 0x3A3
#define MM_JOY1BUTTONDOWN 0x3B5
#define MM_JOY2BUTTONDOWN 0x3B6
#define MM_JOY1BUTTONUP 0x3B7
#define MM_JOY2BUTTONUP 0x3B8

#define MM_MCINOTIFY 0x3B9

#define MM_WOM_OPEN 0x3BB
#define MM_WOM_CLOSE 0x3BC
#define MM_WOM_DONE 0x3BD

#define MM_WIM_OPEN 0x3BE
#define MM_WIM_CLOSE 0x3BF
#define MM_WIM_DATA 0x3C0

#define MM_MIM_OPEN 0x3C1
#define MM_MIM_CLOSE 0x3C2
#define MM_MIM_DATA 0x3C3
#define MM_MIM_LONGDATA 0x3C4
#define MM_MIM_ERROR 0x3C5
#define MM_MIM_LONGERROR 0x3C6

#define MM_MOM_OPEN 0x3C7
#define MM_MOM_CLOSE 0x3C8
#define MM_MOM_DONE 0x3C9

#ifndef MM_DRVM_OPEN
#define MM_DRVM_OPEN 0x3D0
#define MM_DRVM_CLOSE 0x3D1
#define MM_DRVM_DATA 0x3D2
#define MM_DRVM_ERROR 0x3D3
#endif

#define MM_STREAM_OPEN 0x3D4
#define MM_STREAM_CLOSE 0x3D5
#define MM_STREAM_DONE 0x3D6
#define MM_STREAM_ERROR 0x3D7

#define MM_MOM_POSITIONCB 0x3CA

#ifndef MM_MCISIGNAL
#define MM_MCISIGNAL 0x3CB
#endif

#define MM_MIM_MOREDATA 0x3CC

#define MM_MIXM_LINE_CHANGE 0x3D0
#define MM_MIXM_CONTROL_CHANGE 0x3D1

#define MMSYSERR_BASE 0
#define WAVERR_BASE 32
#define MIDIERR_BASE 64
#define TIMERR_BASE 96
#define JOYERR_BASE 160
#define MCIERR_BASE 256
#define MIXERR_BASE 1024

#define MCI_STRING_OFFSET 512
#define MCI_VD_OFFSET 1024
#define MCI_CD_OFFSET 1088
#define MCI_WAVE_OFFSET 1152
#define MCI_SEQ_OFFSET 1216

#define MMSYSERR_NOERROR 0
#define MMSYSERR_ERROR (MMSYSERR_BASE + 1)
#define MMSYSERR_BADDEVICEID (MMSYSERR_BASE + 2)
#define MMSYSERR_NOTENABLED (MMSYSERR_BASE + 3)
#define MMSYSERR_ALLOCATED (MMSYSERR_BASE + 4)
#define MMSYSERR_INVALHANDLE (MMSYSERR_BASE + 5)
#define MMSYSERR_NODRIVER (MMSYSERR_BASE + 6)
#define MMSYSERR_NOMEM (MMSYSERR_BASE + 7)
#define MMSYSERR_NOTSUPPORTED (MMSYSERR_BASE + 8)
#define MMSYSERR_BADERRNUM (MMSYSERR_BASE + 9)
#define MMSYSERR_INVALFLAG (MMSYSERR_BASE + 10)
#define MMSYSERR_INVALPARAM (MMSYSERR_BASE + 11)
#define MMSYSERR_HANDLEBUSY (MMSYSERR_BASE + 12)

#define MMSYSERR_INVALIDALIAS (MMSYSERR_BASE + 13)
#define MMSYSERR_BADDB (MMSYSERR_BASE + 14)
#define MMSYSERR_KEYNOTFOUND (MMSYSERR_BASE + 15)
#define MMSYSERR_READERROR (MMSYSERR_BASE + 16)
#define MMSYSERR_WRITEERROR (MMSYSERR_BASE + 17)
#define MMSYSERR_DELETEERROR (MMSYSERR_BASE + 18)
#define MMSYSERR_VALNOTFOUND (MMSYSERR_BASE + 19)
#define MMSYSERR_NODRIVERCB (MMSYSERR_BASE + 20)
#define MMSYSERR_MOREDATA (MMSYSERR_BASE + 21)
#define MMSYSERR_LASTERROR (MMSYSERR_BASE + 21)

    DECLARE_HANDLE(HDRVR);

#ifndef MMNODRV

    typedef struct DRVCONFIGINFOEX {
        DWORD dwDCISize;
        LPCWSTR lpszDCISectionName;
        LPCWSTR lpszDCIAliasName;
        DWORD dnDevNode;
    } DRVCONFIGINFOEX, * PDRVCONFIGINFOEX, NEAR* NPDRVCONFIGINFOEX, * LPDRVCONFIGINFOEX;

#ifndef DRV_LOAD
#define DRV_LOAD 0x0001
#define DRV_ENABLE 0x0002
#define DRV_OPEN 0x0003
#define DRV_CLOSE 0x0004
#define DRV_DISABLE 0x0005
#define DRV_FREE 0x0006
#define DRV_CONFIGURE 0x0007
#define DRV_QUERYCONFIGURE 0x0008
#define DRV_INSTALL 0x0009
#define DRV_REMOVE 0x000A
#define DRV_EXITSESSION 0x000B
#define DRV_POWER 0x000F
#define DRV_RESERVED 0x0800
#define DRV_USER 0x4000

    typedef struct tagDRVCONFIGINFO {
        DWORD dwDCISize;
        LPCWSTR lpszDCISectionName;
        LPCWSTR lpszDCIAliasName;
    } DRVCONFIGINFO, * PDRVCONFIGINFO, NEAR* NPDRVCONFIGINFO, * LPDRVCONFIGINFO;

#define DRVCNF_CANCEL 0x0000
#define DRVCNF_OK 0x0001
#define DRVCNF_RESTART 0x0002

    typedef LRESULT(CALLBACK* DRIVERPROC)(DWORD_PTR, HDRVR, UINT, LPARAM, LPARAM);

    WINMMAPI LRESULT WINAPI CloseDriver(HDRVR hDriver, LPARAM lParam1, LPARAM lParam2);
    WINMMAPI HDRVR WINAPI OpenDriver(LPCWSTR szDriverName, LPCWSTR szSectionName, LPARAM lParam2);
    WINMMAPI LRESULT WINAPI SendDriverMessage(HDRVR hDriver, UINT message, LPARAM lParam1, LPARAM lParam2);
    WINMMAPI HMODULE WINAPI DrvGetModuleHandle(HDRVR hDriver);
    WINMMAPI HMODULE WINAPI GetDriverModuleHandle(HDRVR hDriver);
    WINMMAPI LRESULT WINAPI DefDriverProc(DWORD_PTR dwDriverIdentifier, HDRVR hdrvr, UINT uMsg, LPARAM lParam1, LPARAM lParam2);
#endif

#define DRV_CANCEL DRVCNF_CANCEL
#define DRV_OK DRVCNF_OK
#define DRV_RESTART DRVCNF_RESTART
#define DRV_MCI_FIRST DRV_RESERVED
#define DRV_MCI_LAST (DRV_RESERVED + 0xFFF)
#endif

#define CALLBACK_TYPEMASK __MSABI_LONG(0x00070000)
#define CALLBACK_NULL __MSABI_LONG(0x00000000)
#define CALLBACK_WINDOW __MSABI_LONG(0x00010000)
#define CALLBACK_TASK __MSABI_LONG(0x00020000)
#define CALLBACK_FUNCTION __MSABI_LONG(0x00030000)
#define CALLBACK_THREAD (CALLBACK_TASK)
#define CALLBACK_EVENT __MSABI_LONG(0x00050000)
    typedef void (CALLBACK DRVCALLBACK)(HDRVR hdrvr, UINT uMsg, DWORD_PTR dwUser, DWORD_PTR dw1, DWORD_PTR dw2);

    typedef DRVCALLBACK* LPDRVCALLBACK;
    typedef DRVCALLBACK* PDRVCALLBACK;

#ifndef MMNOMMSYSTEM
#define OutputDebugStr OutputDebugString
#endif

#ifndef MMNOSOUND

    WINMMAPI WINBOOL WINAPI sndPlaySoundA(LPCSTR pszSound, UINT fuSound);
    WINMMAPI WINBOOL WINAPI sndPlaySoundW(LPCWSTR pszSound, UINT fuSound);

#define sndPlaySound __MINGW_NAME_AW(sndPlaySound)

#define SND_SYNC 0x0000
#define SND_ASYNC 0x0001
#define SND_NODEFAULT 0x0002
#define SND_MEMORY 0x0004
#define SND_LOOP 0x0008
#define SND_NOSTOP 0x0010
#define SND_NOWAIT __MSABI_LONG(0x00002000)
#define SND_ALIAS __MSABI_LONG(0x00010000)
#define SND_ALIAS_ID __MSABI_LONG(0x00110000)
#define SND_FILENAME __MSABI_LONG(0x00020000)
#define SND_RESOURCE __MSABI_LONG(0x00040004)
#define SND_PURGE 0x0040
#define SND_APPLICATION 0x0080

#define SND_ALIAS_START 0

#define sndAlias(c0,c1) (SND_ALIAS_START+((DWORD)(BYTE)(c0)|((DWORD)(BYTE)(c1)<<8)))

#define SND_ALIAS_SYSTEMASTERISK sndAlias('S','*')
#define SND_ALIAS_SYSTEMQUESTION sndAlias('S','?')
#define SND_ALIAS_SYSTEMHAND sndAlias('S','H')
#define SND_ALIAS_SYSTEMEXIT sndAlias('S','E')
#define SND_ALIAS_SYSTEMSTART sndAlias('S','S')
#define SND_ALIAS_SYSTEMWELCOME sndAlias('S','W')
#define SND_ALIAS_SYSTEMEXCLAMATION sndAlias('S','!')
#define SND_ALIAS_SYSTEMDEFAULT sndAlias('S','D')

    WINMMAPI WINBOOL WINAPI PlaySoundA(LPCSTR pszSound, HMODULE hmod, DWORD fdwSound);
    WINMMAPI WINBOOL WINAPI PlaySoundW(LPCWSTR pszSound, HMODULE hmod, DWORD fdwSound);

#define PlaySound __MINGW_NAME_AW(PlaySound)
#endif

#ifndef MMNOWAVE

#define WAVERR_BADFORMAT (WAVERR_BASE + 0)
#define WAVERR_STILLPLAYING (WAVERR_BASE + 1)
#define WAVERR_UNPREPARED (WAVERR_BASE + 2)
#define WAVERR_SYNC (WAVERR_BASE + 3)
#define WAVERR_LASTERROR (WAVERR_BASE + 3)

    DECLARE_HANDLE(HWAVE);
    DECLARE_HANDLE(HWAVEIN);
    DECLARE_HANDLE(HWAVEOUT);
    typedef HWAVEIN* LPHWAVEIN;
    typedef HWAVEOUT* LPHWAVEOUT;
    typedef DRVCALLBACK WAVECALLBACK;
    typedef WAVECALLBACK* LPWAVECALLBACK;

#define WOM_OPEN MM_WOM_OPEN
#define WOM_CLOSE MM_WOM_CLOSE
#define WOM_DONE MM_WOM_DONE
#define WIM_OPEN MM_WIM_OPEN
#define WIM_CLOSE MM_WIM_CLOSE
#define WIM_DATA MM_WIM_DATA

#define WAVE_MAPPER ((UINT)-1)

#define WAVE_FORMAT_QUERY 0x0001
#define WAVE_ALLOWSYNC 0x0002
#define WAVE_MAPPED 0x0004
#define WAVE_FORMAT_DIRECT 0x0008
#define WAVE_FORMAT_DIRECT_QUERY (WAVE_FORMAT_QUERY | WAVE_FORMAT_DIRECT)

    typedef struct wavehdr_tag {
        LPSTR lpData;
        DWORD dwBufferLength;
        DWORD dwBytesRecorded;
        DWORD_PTR dwUser;
        DWORD dwFlags;
        DWORD dwLoops;
        struct wavehdr_tag* lpNext;
        DWORD_PTR reserved;
    } WAVEHDR, * PWAVEHDR, NEAR* NPWAVEHDR, * LPWAVEHDR;

#define WHDR_DONE 0x00000001
#define WHDR_PREPARED 0x00000002
#define WHDR_BEGINLOOP 0x00000004
#define WHDR_ENDLOOP 0x00000008
#define WHDR_INQUEUE 0x00000010

    typedef struct tagWAVEOUTCAPSA {
        WORD wMid;
        WORD wPid;
        MMVERSION vDriverVersion;
        CHAR szPname[MAXPNAMELEN];
        DWORD dwFormats;
        WORD wChannels;
        WORD wReserved1;
        DWORD dwSupport;
    } WAVEOUTCAPSA, * PWAVEOUTCAPSA, * NPWAVEOUTCAPSA, * LPWAVEOUTCAPSA;

    typedef struct tagWAVEOUTCAPSW {
        WORD wMid;
        WORD wPid;
        MMVERSION vDriverVersion;
        WCHAR szPname[MAXPNAMELEN];
        DWORD dwFormats;
        WORD wChannels;
        WORD wReserved1;
        DWORD dwSupport;
    } WAVEOUTCAPSW, * PWAVEOUTCAPSW, * NPWAVEOUTCAPSW, * LPWAVEOUTCAPSW;

    __MINGW_TYPEDEF_AW(WAVEOUTCAPS)
        __MINGW_TYPEDEF_AW(PWAVEOUTCAPS)
        __MINGW_TYPEDEF_AW(NPWAVEOUTCAPS)
        __MINGW_TYPEDEF_AW(LPWAVEOUTCAPS)

        typedef struct tagWAVEOUTCAPS2A {
        WORD wMid;
        WORD wPid;
        MMVERSION vDriverVersion;
        CHAR szPname[MAXPNAMELEN];
        DWORD dwFormats;
        WORD wChannels;
        WORD wReserved1;
        DWORD dwSupport;
        GUID ManufacturerGuid;
        GUID ProductGuid;
        GUID NameGuid;
    } WAVEOUTCAPS2A, * PWAVEOUTCAPS2A, * NPWAVEOUTCAPS2A, * LPWAVEOUTCAPS2A;

    typedef struct tagWAVEOUTCAPS2W {
        WORD wMid;
        WORD wPid;
        MMVERSION vDriverVersion;
        WCHAR szPname[MAXPNAMELEN];
        DWORD dwFormats;
        WORD wChannels;
        WORD wReserved1;
        DWORD dwSupport;
        GUID ManufacturerGuid;
        GUID ProductGuid;
        GUID NameGuid;
    } WAVEOUTCAPS2W, * PWAVEOUTCAPS2W, * NPWAVEOUTCAPS2W, * LPWAVEOUTCAPS2W;

    __MINGW_TYPEDEF_AW(WAVEOUTCAPS2)
        __MINGW_TYPEDEF_AW(PWAVEOUTCAPS2)
        __MINGW_TYPEDEF_AW(NPWAVEOUTCAPS2)
        __MINGW_TYPEDEF_AW(LPWAVEOUTCAPS2)

#define WAVECAPS_PITCH 0x0001
#define WAVECAPS_PLAYBACKRATE 0x0002
#define WAVECAPS_VOLUME 0x0004
#define WAVECAPS_LRVOLUME 0x0008
#define WAVECAPS_SYNC 0x0010
#define WAVECAPS_SAMPLEACCURATE 0x0020

        typedef struct tagWAVEINCAPSA {
        WORD wMid;
        WORD wPid;
        MMVERSION vDriverVersion;
        CHAR szPname[MAXPNAMELEN];
        DWORD dwFormats;
        WORD wChannels;
        WORD wReserved1;
    } WAVEINCAPSA, * PWAVEINCAPSA, * NPWAVEINCAPSA, * LPWAVEINCAPSA;

    typedef struct tagWAVEINCAPSW {
        WORD wMid;
        WORD wPid;
        MMVERSION vDriverVersion;
        WCHAR szPname[MAXPNAMELEN];
        DWORD dwFormats;
        WORD wChannels;
        WORD wReserved1;
    } WAVEINCAPSW, * PWAVEINCAPSW, * NPWAVEINCAPSW, * LPWAVEINCAPSW;

    __MINGW_TYPEDEF_AW(WAVEINCAPS)
        __MINGW_TYPEDEF_AW(PWAVEINCAPS)
        __MINGW_TYPEDEF_AW(NPWAVEINCAPS)
        __MINGW_TYPEDEF_AW(LPWAVEINCAPS)

        typedef struct tagWAVEINCAPS2A {
        WORD wMid;
        WORD wPid;
        MMVERSION vDriverVersion;
        CHAR szPname[MAXPNAMELEN];
        DWORD dwFormats;
        WORD wChannels;
        WORD wReserved1;
        GUID ManufacturerGuid;
        GUID ProductGuid;
        GUID NameGuid;
    } WAVEINCAPS2A, * PWAVEINCAPS2A, * NPWAVEINCAPS2A, * LPWAVEINCAPS2A;

    typedef struct tagWAVEINCAPS2W {
        WORD wMid;
        WORD wPid;
        MMVERSION vDriverVersion;
        WCHAR szPname[MAXPNAMELEN];
        DWORD dwFormats;
        WORD wChannels;
        WORD wReserved1;
        GUID ManufacturerGuid;
        GUID ProductGuid;
        GUID NameGuid;
    } WAVEINCAPS2W, * PWAVEINCAPS2W, * NPWAVEINCAPS2W, * LPWAVEINCAPS2W;

    __MINGW_TYPEDEF_AW(WAVEINCAPS2)
        __MINGW_TYPEDEF_AW(PWAVEINCAPS2)
        __MINGW_TYPEDEF_AW(NPWAVEINCAPS2)
        __MINGW_TYPEDEF_AW(LPWAVEINCAPS2)

#define WAVE_INVALIDFORMAT 0x00000000
#define WAVE_FORMAT_1M08 0x00000001
#define WAVE_FORMAT_1S08 0x00000002
#define WAVE_FORMAT_1M16 0x00000004
#define WAVE_FORMAT_1S16 0x00000008
#define WAVE_FORMAT_2M08 0x00000010
#define WAVE_FORMAT_2S08 0x00000020
#define WAVE_FORMAT_2M16 0x00000040
#define WAVE_FORMAT_2S16 0x00000080
#define WAVE_FORMAT_4M08 0x00000100
#define WAVE_FORMAT_4S08 0x00000200
#define WAVE_FORMAT_4M16 0x00000400
#define WAVE_FORMAT_4S16 0x00000800

#define WAVE_FORMAT_44M08 0x00000100
#define WAVE_FORMAT_44S08 0x00000200
#define WAVE_FORMAT_44M16 0x00000400
#define WAVE_FORMAT_44S16 0x00000800
#define WAVE_FORMAT_48M08 0x00001000
#define WAVE_FORMAT_48S08 0x00002000
#define WAVE_FORMAT_48M16 0x00004000
#define WAVE_FORMAT_48S16 0x00008000
#define WAVE_FORMAT_96M08 0x00010000
#define WAVE_FORMAT_96S08 0x00020000
#define WAVE_FORMAT_96M16 0x00040000
#define WAVE_FORMAT_96S16 0x00080000

#ifndef WAVE_FORMAT_PCM
        typedef struct waveformat_tag {
        WORD wFormatTag;
        WORD nChannels;
        DWORD nSamplesPerSec;
        DWORD nAvgBytesPerSec;
        WORD nBlockAlign;
    } WAVEFORMAT, * PWAVEFORMAT, NEAR* NPWAVEFORMAT, * LPWAVEFORMAT;

#define WAVE_FORMAT_PCM 1

    typedef struct pcmwaveformat_tag {
        WAVEFORMAT wf;
        WORD wBitsPerSample;
    } PCMWAVEFORMAT, * PPCMWAVEFORMAT, NEAR* NPPCMWAVEFORMAT, * LPPCMWAVEFORMAT;
#endif

#ifndef _WAVEFORMATEX_
#define _WAVEFORMATEX_

    typedef struct tWAVEFORMATEX {
        WORD wFormatTag;
        WORD nChannels;
        DWORD nSamplesPerSec;
        DWORD nAvgBytesPerSec;
        WORD nBlockAlign;
        WORD wBitsPerSample;
        WORD cbSize;
    } WAVEFORMATEX, * PWAVEFORMATEX, NEAR* NPWAVEFORMATEX, * LPWAVEFORMATEX;
#endif
    typedef const WAVEFORMATEX* LPCWAVEFORMATEX;

    WINMMAPI UINT WINAPI waveOutGetNumDevs(void);
    WINMMAPI MMRESULT WINAPI waveOutGetDevCapsA(UINT_PTR uDeviceID, LPWAVEOUTCAPSA pwoc, UINT cbwoc);
    WINMMAPI MMRESULT WINAPI waveOutGetDevCapsW(UINT_PTR uDeviceID, LPWAVEOUTCAPSW pwoc, UINT cbwoc);

#define waveOutGetDevCaps __MINGW_NAME_AW(waveOutGetDevCaps)

    WINMMAPI MMRESULT WINAPI waveOutGetVolume(HWAVEOUT hwo, LPDWORD pdwVolume);
    WINMMAPI MMRESULT WINAPI waveOutSetVolume(HWAVEOUT hwo, DWORD dwVolume);
    WINMMAPI MMRESULT WINAPI waveOutGetErrorTextA(MMRESULT mmrError, LPSTR pszText, UINT cchText);
    WINMMAPI MMRESULT WINAPI waveOutGetErrorTextW(MMRESULT mmrError, LPWSTR pszText, UINT cchText);

#define waveOutGetErrorText __MINGW_NAME_AW(waveOutGetErrorText)

    WINMMAPI MMRESULT WINAPI waveOutOpen(LPHWAVEOUT phwo, UINT uDeviceID, LPCWAVEFORMATEX pwfx, DWORD_PTR dwCallback, DWORD_PTR dwInstance, DWORD fdwOpen);
    WINMMAPI MMRESULT WINAPI waveOutClose(HWAVEOUT hwo);
    WINMMAPI MMRESULT WINAPI waveOutPrepareHeader(HWAVEOUT hwo, LPWAVEHDR pwh, UINT cbwh);
    WINMMAPI MMRESULT WINAPI waveOutUnprepareHeader(HWAVEOUT hwo, LPWAVEHDR pwh, UINT cbwh);
    WINMMAPI MMRESULT WINAPI waveOutWrite(HWAVEOUT hwo, LPWAVEHDR pwh, UINT cbwh);
    WINMMAPI MMRESULT WINAPI waveOutPause(HWAVEOUT hwo);
    WINMMAPI MMRESULT WINAPI waveOutRestart(HWAVEOUT hwo);
    WINMMAPI MMRESULT WINAPI waveOutReset(HWAVEOUT hwo);
    WINMMAPI MMRESULT WINAPI waveOutBreakLoop(HWAVEOUT hwo);
    WINMMAPI MMRESULT WINAPI waveOutGetPosition(HWAVEOUT hwo, LPMMTIME pmmt, UINT cbmmt);
    WINMMAPI MMRESULT WINAPI waveOutGetPitch(HWAVEOUT hwo, LPDWORD pdwPitch);
    WINMMAPI MMRESULT WINAPI waveOutSetPitch(HWAVEOUT hwo, DWORD dwPitch);
    WINMMAPI MMRESULT WINAPI waveOutGetPlaybackRate(HWAVEOUT hwo, LPDWORD pdwRate);
    WINMMAPI MMRESULT WINAPI waveOutSetPlaybackRate(HWAVEOUT hwo, DWORD dwRate);
    WINMMAPI MMRESULT WINAPI waveOutGetID(HWAVEOUT hwo, LPUINT puDeviceID);
    WINMMAPI MMRESULT WINAPI waveOutMessage(HWAVEOUT hwo, UINT uMsg, DWORD_PTR dw1, DWORD_PTR dw2);
    WINMMAPI UINT WINAPI waveInGetNumDevs(void);
    WINMMAPI MMRESULT WINAPI waveInGetDevCapsA(UINT_PTR uDeviceID, LPWAVEINCAPSA pwic, UINT cbwic);
    WINMMAPI MMRESULT WINAPI waveInGetDevCapsW(UINT_PTR uDeviceID, LPWAVEINCAPSW pwic, UINT cbwic);

#define waveInGetDevCaps __MINGW_NAME_AW(waveInGetDevCaps)

    WINMMAPI MMRESULT WINAPI waveInGetErrorTextA(MMRESULT mmrError, LPSTR pszText, UINT cchText);
    WINMMAPI MMRESULT WINAPI waveInGetErrorTextW(MMRESULT mmrError, LPWSTR pszText, UINT cchText);

#define waveInGetErrorText __MINGW_NAME_AW(waveInGetErrorText)

    WINMMAPI MMRESULT WINAPI waveInOpen(LPHWAVEIN phwi, UINT uDeviceID, LPCWAVEFORMATEX pwfx, DWORD_PTR dwCallback, DWORD_PTR dwInstance, DWORD fdwOpen);
    WINMMAPI MMRESULT WINAPI waveInClose(HWAVEIN hwi);
    WINMMAPI MMRESULT WINAPI waveInPrepareHeader(HWAVEIN hwi, LPWAVEHDR pwh, UINT cbwh);
    WINMMAPI MMRESULT WINAPI waveInUnprepareHeader(HWAVEIN hwi, LPWAVEHDR pwh, UINT cbwh);
    WINMMAPI MMRESULT WINAPI waveInAddBuffer(HWAVEIN hwi, LPWAVEHDR pwh, UINT cbwh);
    WINMMAPI MMRESULT WINAPI waveInStart(HWAVEIN hwi);
    WINMMAPI MMRESULT WINAPI waveInStop(HWAVEIN hwi);
    WINMMAPI MMRESULT WINAPI waveInReset(HWAVEIN hwi);
    WINMMAPI MMRESULT WINAPI waveInGetPosition(HWAVEIN hwi, LPMMTIME pmmt, UINT cbmmt);
    WINMMAPI MMRESULT WINAPI waveInGetID(HWAVEIN hwi, LPUINT puDeviceID);
    WINMMAPI MMRESULT WINAPI waveInMessage(HWAVEIN hwi, UINT uMsg, DWORD_PTR dw1, DWORD_PTR dw2);
#endif

#ifndef MMNOMIDI

#define MIDIERR_UNPREPARED (MIDIERR_BASE + 0)
#define MIDIERR_STILLPLAYING (MIDIERR_BASE + 1)
#define MIDIERR_NOMAP (MIDIERR_BASE + 2)
#define MIDIERR_NOTREADY (MIDIERR_BASE + 3)
#define MIDIERR_NODEVICE (MIDIERR_BASE + 4)
#define MIDIERR_INVALIDSETUP (MIDIERR_BASE + 5)
#define MIDIERR_BADOPENMODE (MIDIERR_BASE + 6)
#define MIDIERR_DONT_CONTINUE (MIDIERR_BASE + 7)
#define MIDIERR_LASTERROR (MIDIERR_BASE + 7)

    DECLARE_HANDLE(HMIDI);
    DECLARE_HANDLE(HMIDIIN);
    DECLARE_HANDLE(HMIDIOUT);
    DECLARE_HANDLE(HMIDISTRM);
    typedef HMIDI* LPHMIDI;
    typedef HMIDIIN* LPHMIDIIN;
    typedef HMIDIOUT* LPHMIDIOUT;
    typedef HMIDISTRM* LPHMIDISTRM;
    typedef DRVCALLBACK MIDICALLBACK;
    typedef MIDICALLBACK* LPMIDICALLBACK;
#define MIDIPATCHSIZE 128
    typedef WORD PATCHARRAY[MIDIPATCHSIZE];
    typedef WORD* LPPATCHARRAY;
    typedef WORD KEYARRAY[MIDIPATCHSIZE];
    typedef WORD* LPKEYARRAY;

#define MIM_OPEN MM_MIM_OPEN
#define MIM_CLOSE MM_MIM_CLOSE
#define MIM_DATA MM_MIM_DATA
#define MIM_LONGDATA MM_MIM_LONGDATA
#define MIM_ERROR MM_MIM_ERROR
#define MIM_LONGERROR MM_MIM_LONGERROR
#define MOM_OPEN MM_MOM_OPEN
#define MOM_CLOSE MM_MOM_CLOSE
#define MOM_DONE MM_MOM_DONE

#define MIM_MOREDATA MM_MIM_MOREDATA
#define MOM_POSITIONCB MM_MOM_POSITIONCB

#define MIDIMAPPER ((UINT)-1)
#define MIDI_MAPPER ((UINT)-1)

#define MIDI_IO_STATUS __MSABI_LONG(0x00000020)

#define MIDI_CACHE_ALL 1
#define MIDI_CACHE_BESTFIT 2
#define MIDI_CACHE_QUERY 3
#define MIDI_UNCACHE 4

    typedef struct tagMIDIOUTCAPSA {
        WORD wMid;
        WORD wPid;
        MMVERSION vDriverVersion;
        CHAR szPname[MAXPNAMELEN];
        WORD wTechnology;
        WORD wVoices;
        WORD wNotes;
        WORD wChannelMask;
        DWORD dwSupport;
    } MIDIOUTCAPSA, * PMIDIOUTCAPSA, * NPMIDIOUTCAPSA, * LPMIDIOUTCAPSA;

    typedef struct tagMIDIOUTCAPSW {
        WORD wMid;
        WORD wPid;
        MMVERSION vDriverVersion;
        WCHAR szPname[MAXPNAMELEN];
        WORD wTechnology;
        WORD wVoices;
        WORD wNotes;
        WORD wChannelMask;
        DWORD dwSupport;
    } MIDIOUTCAPSW, * PMIDIOUTCAPSW, * NPMIDIOUTCAPSW, * LPMIDIOUTCAPSW;

    __MINGW_TYPEDEF_AW(MIDIOUTCAPS)
        __MINGW_TYPEDEF_AW(PMIDIOUTCAPS)
        __MINGW_TYPEDEF_AW(NPMIDIOUTCAPS)
        __MINGW_TYPEDEF_AW(LPMIDIOUTCAPS)

        typedef struct tagMIDIOUTCAPS2A {
        WORD wMid;
        WORD wPid;
        MMVERSION vDriverVersion;
        CHAR szPname[MAXPNAMELEN];
        WORD wTechnology;
        WORD wVoices;
        WORD wNotes;
        WORD wChannelMask;
        DWORD dwSupport;
        GUID ManufacturerGuid;
        GUID ProductGuid;
        GUID NameGuid;
    } MIDIOUTCAPS2A, * PMIDIOUTCAPS2A, * NPMIDIOUTCAPS2A, * LPMIDIOUTCAPS2A;

    typedef struct tagMIDIOUTCAPS2W {
        WORD wMid;
        WORD wPid;
        MMVERSION vDriverVersion;
        WCHAR szPname[MAXPNAMELEN];
        WORD wTechnology;
        WORD wVoices;
        WORD wNotes;
        WORD wChannelMask;
        DWORD dwSupport;
        GUID ManufacturerGuid;
        GUID ProductGuid;
        GUID NameGuid;
    } MIDIOUTCAPS2W, * PMIDIOUTCAPS2W, * NPMIDIOUTCAPS2W, * LPMIDIOUTCAPS2W;

    __MINGW_TYPEDEF_AW(MIDIOUTCAPS2)
        __MINGW_TYPEDEF_AW(PMIDIOUTCAPS2)
        __MINGW_TYPEDEF_AW(NPMIDIOUTCAPS2)
        __MINGW_TYPEDEF_AW(LPMIDIOUTCAPS2)

#define MOD_MIDIPORT 1
#define MOD_SYNTH 2
#define MOD_SQSYNTH 3
#define MOD_FMSYNTH 4
#define MOD_MAPPER 5
#define MOD_WAVETABLE 6
#define MOD_SWSYNTH 7

#define MIDICAPS_VOLUME 0x0001
#define MIDICAPS_LRVOLUME 0x0002
#define MIDICAPS_CACHE 0x0004
#define MIDICAPS_STREAM 0x0008

        typedef struct tagMIDIINCAPSA {
        WORD wMid;
        WORD wPid;
        MMVERSION vDriverVersion;
        CHAR szPname[MAXPNAMELEN];
        DWORD dwSupport;
    } MIDIINCAPSA, * PMIDIINCAPSA, * NPMIDIINCAPSA, * LPMIDIINCAPSA;

    typedef struct tagMIDIINCAPSW {
        WORD wMid;
        WORD wPid;
        MMVERSION vDriverVersion;
        WCHAR szPname[MAXPNAMELEN];
        DWORD dwSupport;
    } MIDIINCAPSW, * PMIDIINCAPSW, * NPMIDIINCAPSW, * LPMIDIINCAPSW;

    __MINGW_TYPEDEF_AW(MIDIINCAPS)
        __MINGW_TYPEDEF_AW(PMIDIINCAPS)
        __MINGW_TYPEDEF_AW(NPMIDIINCAPS)
        __MINGW_TYPEDEF_AW(LPMIDIINCAPS)

        typedef struct tagMIDIINCAPS2A {
        WORD wMid;
        WORD wPid;
        MMVERSION vDriverVersion;
        CHAR szPname[MAXPNAMELEN];
        DWORD dwSupport;
        GUID ManufacturerGuid;
        GUID ProductGuid;
        GUID NameGuid;
    } MIDIINCAPS2A, * PMIDIINCAPS2A, * NPMIDIINCAPS2A, * LPMIDIINCAPS2A;

    typedef struct tagMIDIINCAPS2W {
        WORD wMid;
        WORD wPid;
        MMVERSION vDriverVersion;
        WCHAR szPname[MAXPNAMELEN];
        DWORD dwSupport;
        GUID ManufacturerGuid;
        GUID ProductGuid;
        GUID NameGuid;
    } MIDIINCAPS2W, * PMIDIINCAPS2W, * NPMIDIINCAPS2W, * LPMIDIINCAPS2W;

    __MINGW_TYPEDEF_AW(MIDIINCAPS2)
        __MINGW_TYPEDEF_AW(PMIDIINCAPS2)
        __MINGW_TYPEDEF_AW(NPMIDIINCAPS2)
        __MINGW_TYPEDEF_AW(LPMIDIINCAPS2)

        typedef struct midihdr_tag {
        LPSTR lpData;
        DWORD dwBufferLength;
        DWORD dwBytesRecorded;
        DWORD_PTR dwUser;
        DWORD dwFlags;
        struct midihdr_tag far* lpNext;
        DWORD_PTR reserved;
        DWORD dwOffset;
        DWORD_PTR dwReserved[8];
    } MIDIHDR, * PMIDIHDR, NEAR* NPMIDIHDR, * LPMIDIHDR;

    typedef struct midievent_tag {
        DWORD dwDeltaTime;
        DWORD dwStreamID;
        DWORD dwEvent;
        DWORD dwParms[1];
    } MIDIEVENT;

    typedef struct midistrmbuffver_tag {
        DWORD dwVersion;
        DWORD dwMid;
        DWORD dwOEMVersion;
    } MIDISTRMBUFFVER;

#define MHDR_DONE 0x00000001
#define MHDR_PREPARED 0x00000002
#define MHDR_INQUEUE 0x00000004
#define MHDR_ISSTRM 0x00000008

#define MEVT_F_SHORT __MSABI_LONG(0x00000000)
#define MEVT_F_LONG __MSABI_LONG(0x80000000)
#define MEVT_F_CALLBACK __MSABI_LONG(0x40000000)

#define MEVT_EVENTTYPE(x) ((BYTE)(((x)>>24)&0xFF))
#define MEVT_EVENTPARM(x) ((DWORD)((x)&0x00FFFFFF))

#define MEVT_SHORTMSG ((BYTE)0x00)
#define MEVT_TEMPO ((BYTE)0x01)
#define MEVT_NOP ((BYTE)0x02)

#define MEVT_LONGMSG ((BYTE)0x80)
#define MEVT_COMMENT ((BYTE)0x82)
#define MEVT_VERSION ((BYTE)0x84)

#define MIDISTRM_ERROR (-2)

#define MIDIPROP_SET __MSABI_LONG(0x80000000)
#define MIDIPROP_GET __MSABI_LONG(0x40000000)

#define MIDIPROP_TIMEDIV __MSABI_LONG(0x00000001)
#define MIDIPROP_TEMPO __MSABI_LONG(0x00000002)

    typedef struct midiproptimediv_tag {
        DWORD cbStruct;
        DWORD dwTimeDiv;
    } MIDIPROPTIMEDIV, * LPMIDIPROPTIMEDIV;

    typedef struct midiproptempo_tag {
        DWORD cbStruct;
        DWORD dwTempo;
    } MIDIPROPTEMPO, * LPMIDIPROPTEMPO;

    WINMMAPI UINT WINAPI midiOutGetNumDevs(void);
    WINMMAPI MMRESULT WINAPI midiStreamOpen(LPHMIDISTRM phms, LPUINT puDeviceID, DWORD cMidi, DWORD_PTR dwCallback, DWORD_PTR dwInstance, DWORD fdwOpen);
    WINMMAPI MMRESULT WINAPI midiStreamClose(HMIDISTRM hms);
    WINMMAPI MMRESULT WINAPI midiStreamProperty(HMIDISTRM hms, LPBYTE lppropdata, DWORD dwProperty);
    WINMMAPI MMRESULT WINAPI midiStreamPosition(HMIDISTRM hms, LPMMTIME lpmmt, UINT cbmmt);
    WINMMAPI MMRESULT WINAPI midiStreamOut(HMIDISTRM hms, LPMIDIHDR pmh, UINT cbmh);
    WINMMAPI MMRESULT WINAPI midiStreamPause(HMIDISTRM hms);
    WINMMAPI MMRESULT WINAPI midiStreamRestart(HMIDISTRM hms);
    WINMMAPI MMRESULT WINAPI midiStreamStop(HMIDISTRM hms);
    WINMMAPI MMRESULT WINAPI midiConnect(HMIDI hmi, HMIDIOUT hmo, LPVOID pReserved);
    WINMMAPI MMRESULT WINAPI midiDisconnect(HMIDI hmi, HMIDIOUT hmo, LPVOID pReserved);
    WINMMAPI MMRESULT WINAPI midiOutGetDevCapsA(UINT_PTR uDeviceID, LPMIDIOUTCAPSA pmoc, UINT cbmoc);
    WINMMAPI MMRESULT WINAPI midiOutGetDevCapsW(UINT_PTR uDeviceID, LPMIDIOUTCAPSW pmoc, UINT cbmoc);

#define midiOutGetDevCaps __MINGW_NAME_AW(midiOutGetDevCaps)

    WINMMAPI MMRESULT WINAPI midiOutGetVolume(HMIDIOUT hmo, LPDWORD pdwVolume);
    WINMMAPI MMRESULT WINAPI midiOutSetVolume(HMIDIOUT hmo, DWORD dwVolume);
    WINMMAPI MMRESULT WINAPI midiOutGetErrorTextA(MMRESULT mmrError, LPSTR pszText, UINT cchText);
    WINMMAPI MMRESULT WINAPI midiOutGetErrorTextW(MMRESULT mmrError, LPWSTR pszText, UINT cchText);

#define midiOutGetErrorText __MINGW_NAME_AW(midiOutGetErrorText)

    WINMMAPI MMRESULT WINAPI midiOutOpen(LPHMIDIOUT phmo, UINT uDeviceID, DWORD_PTR dwCallback, DWORD_PTR dwInstance, DWORD fdwOpen);
    WINMMAPI MMRESULT WINAPI midiOutClose(HMIDIOUT hmo);
    WINMMAPI MMRESULT WINAPI midiOutPrepareHeader(HMIDIOUT hmo, LPMIDIHDR pmh, UINT cbmh);
    WINMMAPI MMRESULT WINAPI midiOutUnprepareHeader(HMIDIOUT hmo, LPMIDIHDR pmh, UINT cbmh);
    WINMMAPI MMRESULT WINAPI midiOutShortMsg(HMIDIOUT hmo, DWORD dwMsg);
    WINMMAPI MMRESULT WINAPI midiOutLongMsg(HMIDIOUT hmo, LPMIDIHDR pmh, UINT cbmh);
    WINMMAPI MMRESULT WINAPI midiOutReset(HMIDIOUT hmo);
    WINMMAPI MMRESULT WINAPI midiOutCachePatches(HMIDIOUT hmo, UINT uBank, LPWORD pwpa, UINT fuCache);
    WINMMAPI MMRESULT WINAPI midiOutCacheDrumPatches(HMIDIOUT hmo, UINT uPatch, LPWORD pwkya, UINT fuCache);
    WINMMAPI MMRESULT WINAPI midiOutGetID(HMIDIOUT hmo, LPUINT puDeviceID);
    WINMMAPI MMRESULT WINAPI midiOutMessage(HMIDIOUT hmo, UINT uMsg, DWORD_PTR dw1, DWORD_PTR dw2);
    WINMMAPI UINT WINAPI midiInGetNumDevs(void);
    WINMMAPI MMRESULT WINAPI midiInGetDevCapsA(UINT_PTR uDeviceID, LPMIDIINCAPSA pmic, UINT cbmic);
    WINMMAPI MMRESULT WINAPI midiInGetDevCapsW(UINT_PTR uDeviceID, LPMIDIINCAPSW pmic, UINT cbmic);

#define midiInGetDevCaps __MINGW_NAME_AW(midiInGetDevCaps)

    WINMMAPI MMRESULT WINAPI midiInGetErrorTextA(MMRESULT mmrError, LPSTR pszText, UINT cchText);
    WINMMAPI MMRESULT WINAPI midiInGetErrorTextW(MMRESULT mmrError, LPWSTR pszText, UINT cchText);

#define midiInGetErrorText __MINGW_NAME_AW(midiInGetErrorText)

    WINMMAPI MMRESULT WINAPI midiInOpen(LPHMIDIIN phmi, UINT uDeviceID, DWORD_PTR dwCallback, DWORD_PTR dwInstance, DWORD fdwOpen);
    WINMMAPI MMRESULT WINAPI midiInClose(HMIDIIN hmi);
    WINMMAPI MMRESULT WINAPI midiInPrepareHeader(HMIDIIN hmi, LPMIDIHDR pmh, UINT cbmh);
    WINMMAPI MMRESULT WINAPI midiInUnprepareHeader(HMIDIIN hmi, LPMIDIHDR pmh, UINT cbmh);
    WINMMAPI MMRESULT WINAPI midiInAddBuffer(HMIDIIN hmi, LPMIDIHDR pmh, UINT cbmh);
    WINMMAPI MMRESULT WINAPI midiInStart(HMIDIIN hmi);
    WINMMAPI MMRESULT WINAPI midiInStop(HMIDIIN hmi);
    WINMMAPI MMRESULT WINAPI midiInReset(HMIDIIN hmi);
    WINMMAPI MMRESULT WINAPI midiInGetID(HMIDIIN hmi, LPUINT puDeviceID);
    WINMMAPI MMRESULT WINAPI midiInMessage(HMIDIIN hmi, UINT uMsg, DWORD_PTR dw1, DWORD_PTR dw2);
#endif

#ifndef MMNOAUX

#define AUX_MAPPER ((UINT)-1)

    typedef struct tagAUXCAPSA {
        WORD wMid;
        WORD wPid;
        MMVERSION vDriverVersion;
        CHAR szPname[MAXPNAMELEN];
        WORD wTechnology;
        WORD wReserved1;
        DWORD dwSupport;
    } AUXCAPSA, * PAUXCAPSA, * NPAUXCAPSA, * LPAUXCAPSA;

    typedef struct tagAUXCAPSW {
        WORD wMid;
        WORD wPid;
        MMVERSION vDriverVersion;
        WCHAR szPname[MAXPNAMELEN];
        WORD wTechnology;
        WORD wReserved1;
        DWORD dwSupport;
    } AUXCAPSW, * PAUXCAPSW, * NPAUXCAPSW, * LPAUXCAPSW;

    __MINGW_TYPEDEF_AW(AUXCAPS)
        __MINGW_TYPEDEF_AW(PAUXCAPS)
        __MINGW_TYPEDEF_AW(NPAUXCAPS)
        __MINGW_TYPEDEF_AW(LPAUXCAPS)

        typedef struct tagAUXCAPS2A {
        WORD wMid;
        WORD wPid;
        MMVERSION vDriverVersion;
        CHAR szPname[MAXPNAMELEN];
        WORD wTechnology;
        WORD wReserved1;
        DWORD dwSupport;
        GUID ManufacturerGuid;
        GUID ProductGuid;
        GUID NameGuid;
    } AUXCAPS2A, * PAUXCAPS2A, * NPAUXCAPS2A, * LPAUXCAPS2A;

    typedef struct tagAUXCAPS2W {
        WORD wMid;
        WORD wPid;
        MMVERSION vDriverVersion;
        WCHAR szPname[MAXPNAMELEN];
        WORD wTechnology;
        WORD wReserved1;
        DWORD dwSupport;
        GUID ManufacturerGuid;
        GUID ProductGuid;
        GUID NameGuid;
    } AUXCAPS2W, * PAUXCAPS2W, * NPAUXCAPS2W, * LPAUXCAPS2W;

    __MINGW_TYPEDEF_AW(AUXCAPS2)
        __MINGW_TYPEDEF_AW(PAUXCAPS2)
        __MINGW_TYPEDEF_AW(NPAUXCAPS2)
        __MINGW_TYPEDEF_AW(LPAUXCAPS2)

#define AUXCAPS_CDAUDIO 1
#define AUXCAPS_AUXIN 2

#define AUXCAPS_VOLUME 0x0001
#define AUXCAPS_LRVOLUME 0x0002

        WINMMAPI UINT WINAPI auxGetNumDevs(void);
    WINMMAPI MMRESULT WINAPI auxGetDevCapsA(UINT_PTR uDeviceID, LPAUXCAPSA pac, UINT cbac);
    WINMMAPI MMRESULT WINAPI auxGetDevCapsW(UINT_PTR uDeviceID, LPAUXCAPSW pac, UINT cbac);

#define auxGetDevCaps __MINGW_NAME_AW(auxGetDevCaps)

    WINMMAPI MMRESULT WINAPI auxSetVolume(UINT uDeviceID, DWORD dwVolume);
    WINMMAPI MMRESULT WINAPI auxGetVolume(UINT uDeviceID, LPDWORD pdwVolume);
    WINMMAPI MMRESULT WINAPI auxOutMessage(UINT uDeviceID, UINT uMsg, DWORD_PTR dw1, DWORD_PTR dw2);
#endif

#ifndef MMNOMIXER

    DECLARE_HANDLE(HMIXEROBJ);
    typedef HMIXEROBJ* LPHMIXEROBJ;

    DECLARE_HANDLE(HMIXER);
    typedef HMIXER* LPHMIXER;

#define MIXER_SHORT_NAME_CHARS 16
#define MIXER_LONG_NAME_CHARS 64

#define MIXERR_INVALLINE (MIXERR_BASE + 0)
#define MIXERR_INVALCONTROL (MIXERR_BASE + 1)
#define MIXERR_INVALVALUE (MIXERR_BASE + 2)
#define MIXERR_LASTERROR (MIXERR_BASE + 2)

#define MIXER_OBJECTF_HANDLE __MSABI_LONG(0x80000000)
#define MIXER_OBJECTF_MIXER __MSABI_LONG(0x00000000)
#define MIXER_OBJECTF_HMIXER (MIXER_OBJECTF_HANDLE|MIXER_OBJECTF_MIXER)
#define MIXER_OBJECTF_WAVEOUT __MSABI_LONG(0x10000000)
#define MIXER_OBJECTF_HWAVEOUT (MIXER_OBJECTF_HANDLE|MIXER_OBJECTF_WAVEOUT)
#define MIXER_OBJECTF_WAVEIN __MSABI_LONG(0x20000000)
#define MIXER_OBJECTF_HWAVEIN (MIXER_OBJECTF_HANDLE|MIXER_OBJECTF_WAVEIN)
#define MIXER_OBJECTF_MIDIOUT __MSABI_LONG(0x30000000)
#define MIXER_OBJECTF_HMIDIOUT (MIXER_OBJECTF_HANDLE|MIXER_OBJECTF_MIDIOUT)
#define MIXER_OBJECTF_MIDIIN __MSABI_LONG(0x40000000)
#define MIXER_OBJECTF_HMIDIIN (MIXER_OBJECTF_HANDLE|MIXER_OBJECTF_MIDIIN)
#define MIXER_OBJECTF_AUX __MSABI_LONG(0x50000000)

    WINMMAPI UINT WINAPI mixerGetNumDevs(void);

    typedef struct tagMIXERCAPSA {
        WORD wMid;
        WORD wPid;
        MMVERSION vDriverVersion;
        CHAR szPname[MAXPNAMELEN];
        DWORD fdwSupport;
        DWORD cDestinations;
    } MIXERCAPSA, * PMIXERCAPSA, * LPMIXERCAPSA;

    typedef struct tagMIXERCAPSW {
        WORD wMid;
        WORD wPid;
        MMVERSION vDriverVersion;
        WCHAR szPname[MAXPNAMELEN];
        DWORD fdwSupport;
        DWORD cDestinations;
    } MIXERCAPSW, * PMIXERCAPSW, * LPMIXERCAPSW;

    __MINGW_TYPEDEF_AW(MIXERCAPS)
        __MINGW_TYPEDEF_AW(PMIXERCAPS)
        __MINGW_TYPEDEF_AW(LPMIXERCAPS)

        typedef struct tagMIXERCAPS2A {
        WORD wMid;
        WORD wPid;
        MMVERSION vDriverVersion;
        CHAR szPname[MAXPNAMELEN];
        DWORD fdwSupport;
        DWORD cDestinations;
        GUID ManufacturerGuid;
        GUID ProductGuid;
        GUID NameGuid;
    } MIXERCAPS2A, * PMIXERCAPS2A, * LPMIXERCAPS2A;

    typedef struct tagMIXERCAPS2W {
        WORD wMid;
        WORD wPid;
        MMVERSION vDriverVersion;
        WCHAR szPname[MAXPNAMELEN];
        DWORD fdwSupport;
        DWORD cDestinations;
        GUID ManufacturerGuid;
        GUID ProductGuid;
        GUID NameGuid;
    } MIXERCAPS2W, * PMIXERCAPS2W, * LPMIXERCAPS2W;

    __MINGW_TYPEDEF_AW(MIXERCAPS2)
        __MINGW_TYPEDEF_AW(PMIXERCAPS2)
        __MINGW_TYPEDEF_AW(LPMIXERCAPS2)

        WINMMAPI MMRESULT WINAPI mixerGetDevCapsA(UINT_PTR uMxId, LPMIXERCAPSA pmxcaps, UINT cbmxcaps);
    WINMMAPI MMRESULT WINAPI mixerGetDevCapsW(UINT_PTR uMxId, LPMIXERCAPSW pmxcaps, UINT cbmxcaps);

#define mixerGetDevCaps __MINGW_NAME_AW(mixerGetDevCaps)

    WINMMAPI MMRESULT WINAPI mixerOpen(LPHMIXER phmx, UINT uMxId, DWORD_PTR dwCallback, DWORD_PTR dwInstance, DWORD fdwOpen);
    WINMMAPI MMRESULT WINAPI mixerClose(HMIXER hmx);
    WINMMAPI DWORD WINAPI mixerMessage(HMIXER hmx, UINT uMsg, DWORD_PTR dwParam1, DWORD_PTR dwParam2);

    typedef struct tagMIXERLINEA {
        DWORD cbStruct;
        DWORD dwDestination;
        DWORD dwSource;
        DWORD dwLineID;
        DWORD fdwLine;
        DWORD_PTR dwUser;
        DWORD dwComponentType;
        DWORD cChannels;
        DWORD cConnections;
        DWORD cControls;
        CHAR szShortName[MIXER_SHORT_NAME_CHARS];
        CHAR szName[MIXER_LONG_NAME_CHARS];
        struct {
            DWORD dwType;
            DWORD dwDeviceID;
            WORD wMid;
            WORD wPid;
            MMVERSION vDriverVersion;
            CHAR szPname[MAXPNAMELEN];
        } Target;
    } MIXERLINEA, * PMIXERLINEA, * LPMIXERLINEA;

    typedef struct tagMIXERLINEW {
        DWORD cbStruct;
        DWORD dwDestination;
        DWORD dwSource;
        DWORD dwLineID;
        DWORD fdwLine;
        DWORD_PTR dwUser;
        DWORD dwComponentType;
        DWORD cChannels;
        DWORD cConnections;
        DWORD cControls;
        WCHAR szShortName[MIXER_SHORT_NAME_CHARS];
        WCHAR szName[MIXER_LONG_NAME_CHARS];
        struct {
            DWORD dwType;
            DWORD dwDeviceID;
            WORD wMid;
            WORD wPid;
            MMVERSION vDriverVersion;
            WCHAR szPname[MAXPNAMELEN];
        } Target;
    } MIXERLINEW, * PMIXERLINEW, * LPMIXERLINEW;

    __MINGW_TYPEDEF_AW(MIXERLINE)
        __MINGW_TYPEDEF_AW(PMIXERLINE)
        __MINGW_TYPEDEF_AW(LPMIXERLINE)

#define MIXERLINE_LINEF_ACTIVE __MSABI_LONG(0x00000001)
#define MIXERLINE_LINEF_DISCONNECTED __MSABI_LONG(0x00008000)
#define MIXERLINE_LINEF_SOURCE __MSABI_LONG(0x80000000)

#define MIXERLINE_COMPONENTTYPE_DST_FIRST __MSABI_LONG(0x0)
#define MIXERLINE_COMPONENTTYPE_DST_UNDEFINED (MIXERLINE_COMPONENTTYPE_DST_FIRST + 0)
#define MIXERLINE_COMPONENTTYPE_DST_DIGITAL (MIXERLINE_COMPONENTTYPE_DST_FIRST + 1)
#define MIXERLINE_COMPONENTTYPE_DST_LINE (MIXERLINE_COMPONENTTYPE_DST_FIRST + 2)
#define MIXERLINE_COMPONENTTYPE_DST_MONITOR (MIXERLINE_COMPONENTTYPE_DST_FIRST + 3)
#define MIXERLINE_COMPONENTTYPE_DST_SPEAKERS (MIXERLINE_COMPONENTTYPE_DST_FIRST + 4)
#define MIXERLINE_COMPONENTTYPE_DST_HEADPHONES (MIXERLINE_COMPONENTTYPE_DST_FIRST + 5)
#define MIXERLINE_COMPONENTTYPE_DST_TELEPHONE (MIXERLINE_COMPONENTTYPE_DST_FIRST + 6)
#define MIXERLINE_COMPONENTTYPE_DST_WAVEIN (MIXERLINE_COMPONENTTYPE_DST_FIRST + 7)
#define MIXERLINE_COMPONENTTYPE_DST_VOICEIN (MIXERLINE_COMPONENTTYPE_DST_FIRST + 8)
#define MIXERLINE_COMPONENTTYPE_DST_LAST (MIXERLINE_COMPONENTTYPE_DST_FIRST + 8)
#define MIXERLINE_COMPONENTTYPE_SRC_FIRST __MSABI_LONG(0x00001000)
#define MIXERLINE_COMPONENTTYPE_SRC_UNDEFINED (MIXERLINE_COMPONENTTYPE_SRC_FIRST + 0)
#define MIXERLINE_COMPONENTTYPE_SRC_DIGITAL (MIXERLINE_COMPONENTTYPE_SRC_FIRST + 1)
#define MIXERLINE_COMPONENTTYPE_SRC_LINE (MIXERLINE_COMPONENTTYPE_SRC_FIRST + 2)
#define MIXERLINE_COMPONENTTYPE_SRC_MICROPHONE (MIXERLINE_COMPONENTTYPE_SRC_FIRST + 3)
#define MIXERLINE_COMPONENTTYPE_SRC_SYNTHESIZER (MIXERLINE_COMPONENTTYPE_SRC_FIRST + 4)
#define MIXERLINE_COMPONENTTYPE_SRC_COMPACTDISC (MIXERLINE_COMPONENTTYPE_SRC_FIRST + 5)
#define MIXERLINE_COMPONENTTYPE_SRC_TELEPHONE (MIXERLINE_COMPONENTTYPE_SRC_FIRST + 6)
#define MIXERLINE_COMPONENTTYPE_SRC_PCSPEAKER (MIXERLINE_COMPONENTTYPE_SRC_FIRST + 7)
#define MIXERLINE_COMPONENTTYPE_SRC_WAVEOUT (MIXERLINE_COMPONENTTYPE_SRC_FIRST + 8)
#define MIXERLINE_COMPONENTTYPE_SRC_AUXILIARY (MIXERLINE_COMPONENTTYPE_SRC_FIRST + 9)
#define MIXERLINE_COMPONENTTYPE_SRC_ANALOG (MIXERLINE_COMPONENTTYPE_SRC_FIRST + 10)
#define MIXERLINE_COMPONENTTYPE_SRC_LAST (MIXERLINE_COMPONENTTYPE_SRC_FIRST + 10)

#define MIXERLINE_TARGETTYPE_UNDEFINED 0
#define MIXERLINE_TARGETTYPE_WAVEOUT 1
#define MIXERLINE_TARGETTYPE_WAVEIN 2
#define MIXERLINE_TARGETTYPE_MIDIOUT 3
#define MIXERLINE_TARGETTYPE_MIDIIN 4
#define MIXERLINE_TARGETTYPE_AUX 5

        WINMMAPI MMRESULT WINAPI mixerGetLineInfoA(HMIXEROBJ hmxobj, LPMIXERLINEA pmxl, DWORD fdwInfo);
    WINMMAPI MMRESULT WINAPI mixerGetLineInfoW(HMIXEROBJ hmxobj, LPMIXERLINEW pmxl, DWORD fdwInfo);

#define mixerGetLineInfo __MINGW_NAME_AW(mixerGetLineInfo)

#define MIXER_GETLINEINFOF_DESTINATION __MSABI_LONG(0x00000000)
#define MIXER_GETLINEINFOF_SOURCE __MSABI_LONG(0x00000001)
#define MIXER_GETLINEINFOF_LINEID __MSABI_LONG(0x00000002)
#define MIXER_GETLINEINFOF_COMPONENTTYPE __MSABI_LONG(0x00000003)
#define MIXER_GETLINEINFOF_TARGETTYPE __MSABI_LONG(0x00000004)

#define MIXER_GETLINEINFOF_QUERYMASK __MSABI_LONG(0x0000000F)

    WINMMAPI MMRESULT WINAPI mixerGetID(HMIXEROBJ hmxobj, UINT* puMxId, DWORD fdwId);

    typedef struct tagMIXERCONTROLA {
        DWORD cbStruct;
        DWORD dwControlID;
        DWORD dwControlType;
        DWORD fdwControl;
        DWORD cMultipleItems;
        CHAR szShortName[MIXER_SHORT_NAME_CHARS];
        CHAR szName[MIXER_LONG_NAME_CHARS];
        union {
            __C89_NAMELESS struct {
                LONG lMinimum;
                LONG lMaximum;
            } DUMMYSTRUCTNAME;
            __C89_NAMELESS struct {
                DWORD dwMinimum;
                DWORD dwMaximum;
            } DUMMYSTRUCTNAME2;
            DWORD dwReserved[6];
        } Bounds;
        union {
            DWORD cSteps;
            DWORD cbCustomData;
            DWORD dwReserved[6];
        } Metrics;
    } MIXERCONTROLA, * PMIXERCONTROLA, * LPMIXERCONTROLA;

    typedef struct tagMIXERCONTROLW {
        DWORD cbStruct;
        DWORD dwControlID;
        DWORD dwControlType;
        DWORD fdwControl;
        DWORD cMultipleItems;
        WCHAR szShortName[MIXER_SHORT_NAME_CHARS];
        WCHAR szName[MIXER_LONG_NAME_CHARS];
        union {
            __C89_NAMELESS struct {
                LONG lMinimum;
                LONG lMaximum;
            } DUMMYSTRUCTNAME;
            __C89_NAMELESS struct {
                DWORD dwMinimum;
                DWORD dwMaximum;
            } DUMMYSTRUCTNAME2;
            DWORD dwReserved[6];
        } Bounds;
        union {
            DWORD cSteps;
            DWORD cbCustomData;
            DWORD dwReserved[6];
        } Metrics;
    } MIXERCONTROLW, * PMIXERCONTROLW, * LPMIXERCONTROLW;

    __MINGW_TYPEDEF_AW(MIXERCONTROL)
        __MINGW_TYPEDEF_AW(PMIXERCONTROL)
        __MINGW_TYPEDEF_AW(LPMIXERCONTROL)

#define MIXERCONTROL_CONTROLF_UNIFORM __MSABI_LONG(0x00000001)
#define MIXERCONTROL_CONTROLF_MULTIPLE __MSABI_LONG(0x00000002)
#define MIXERCONTROL_CONTROLF_DISABLED __MSABI_LONG(0x80000000)

#define MIXERCONTROL_CT_CLASS_MASK __MSABI_LONG(0xF0000000)
#define MIXERCONTROL_CT_CLASS_CUSTOM __MSABI_LONG(0x00000000)
#define MIXERCONTROL_CT_CLASS_METER __MSABI_LONG(0x10000000)
#define MIXERCONTROL_CT_CLASS_SWITCH __MSABI_LONG(0x20000000)
#define MIXERCONTROL_CT_CLASS_NUMBER __MSABI_LONG(0x30000000)
#define MIXERCONTROL_CT_CLASS_SLIDER __MSABI_LONG(0x40000000)
#define MIXERCONTROL_CT_CLASS_FADER __MSABI_LONG(0x50000000)
#define MIXERCONTROL_CT_CLASS_TIME __MSABI_LONG(0x60000000)
#define MIXERCONTROL_CT_CLASS_LIST __MSABI_LONG(0x70000000)

#define MIXERCONTROL_CT_SUBCLASS_MASK __MSABI_LONG(0x0F000000)

#define MIXERCONTROL_CT_SC_SWITCH_BOOLEAN __MSABI_LONG(0x00000000)
#define MIXERCONTROL_CT_SC_SWITCH_BUTTON __MSABI_LONG(0x01000000)

#define MIXERCONTROL_CT_SC_METER_POLLED __MSABI_LONG(0x00000000)

#define MIXERCONTROL_CT_SC_TIME_MICROSECS __MSABI_LONG(0x00000000)
#define MIXERCONTROL_CT_SC_TIME_MILLISECS __MSABI_LONG(0x01000000)

#define MIXERCONTROL_CT_SC_LIST_SINGLE __MSABI_LONG(0x00000000)
#define MIXERCONTROL_CT_SC_LIST_MULTIPLE __MSABI_LONG(0x01000000)

#define MIXERCONTROL_CT_UNITS_MASK __MSABI_LONG(0x00FF0000)
#define MIXERCONTROL_CT_UNITS_CUSTOM __MSABI_LONG(0x00000000)
#define MIXERCONTROL_CT_UNITS_BOOLEAN __MSABI_LONG(0x00010000)
#define MIXERCONTROL_CT_UNITS_SIGNED __MSABI_LONG(0x00020000)
#define MIXERCONTROL_CT_UNITS_UNSIGNED __MSABI_LONG(0x00030000)
#define MIXERCONTROL_CT_UNITS_DECIBELS __MSABI_LONG(0x00040000)
#define MIXERCONTROL_CT_UNITS_PERCENT __MSABI_LONG(0x00050000)

#define MIXERCONTROL_CONTROLTYPE_CUSTOM (MIXERCONTROL_CT_CLASS_CUSTOM | MIXERCONTROL_CT_UNITS_CUSTOM)
#define MIXERCONTROL_CONTROLTYPE_BOOLEANMETER (MIXERCONTROL_CT_CLASS_METER | MIXERCONTROL_CT_SC_METER_POLLED | MIXERCONTROL_CT_UNITS_BOOLEAN)
#define MIXERCONTROL_CONTROLTYPE_SIGNEDMETER (MIXERCONTROL_CT_CLASS_METER | MIXERCONTROL_CT_SC_METER_POLLED | MIXERCONTROL_CT_UNITS_SIGNED)
#define MIXERCONTROL_CONTROLTYPE_PEAKMETER (MIXERCONTROL_CONTROLTYPE_SIGNEDMETER + 1)
#define MIXERCONTROL_CONTROLTYPE_UNSIGNEDMETER (MIXERCONTROL_CT_CLASS_METER | MIXERCONTROL_CT_SC_METER_POLLED | MIXERCONTROL_CT_UNITS_UNSIGNED)
#define MIXERCONTROL_CONTROLTYPE_BOOLEAN (MIXERCONTROL_CT_CLASS_SWITCH | MIXERCONTROL_CT_SC_SWITCH_BOOLEAN | MIXERCONTROL_CT_UNITS_BOOLEAN)
#define MIXERCONTROL_CONTROLTYPE_ONOFF (MIXERCONTROL_CONTROLTYPE_BOOLEAN + 1)
#define MIXERCONTROL_CONTROLTYPE_MUTE (MIXERCONTROL_CONTROLTYPE_BOOLEAN + 2)
#define MIXERCONTROL_CONTROLTYPE_MONO (MIXERCONTROL_CONTROLTYPE_BOOLEAN + 3)
#define MIXERCONTROL_CONTROLTYPE_LOUDNESS (MIXERCONTROL_CONTROLTYPE_BOOLEAN + 4)
#define MIXERCONTROL_CONTROLTYPE_STEREOENH (MIXERCONTROL_CONTROLTYPE_BOOLEAN + 5)
#define MIXERCONTROL_CONTROLTYPE_BASS_BOOST (MIXERCONTROL_CONTROLTYPE_BOOLEAN + 0x00002277)
#define MIXERCONTROL_CONTROLTYPE_BUTTON (MIXERCONTROL_CT_CLASS_SWITCH | MIXERCONTROL_CT_SC_SWITCH_BUTTON | MIXERCONTROL_CT_UNITS_BOOLEAN)
#define MIXERCONTROL_CONTROLTYPE_DECIBELS (MIXERCONTROL_CT_CLASS_NUMBER | MIXERCONTROL_CT_UNITS_DECIBELS)
#define MIXERCONTROL_CONTROLTYPE_SIGNED (MIXERCONTROL_CT_CLASS_NUMBER | MIXERCONTROL_CT_UNITS_SIGNED)
#define MIXERCONTROL_CONTROLTYPE_UNSIGNED (MIXERCONTROL_CT_CLASS_NUMBER | MIXERCONTROL_CT_UNITS_UNSIGNED)
#define MIXERCONTROL_CONTROLTYPE_PERCENT (MIXERCONTROL_CT_CLASS_NUMBER | MIXERCONTROL_CT_UNITS_PERCENT)
#define MIXERCONTROL_CONTROLTYPE_SLIDER (MIXERCONTROL_CT_CLASS_SLIDER | MIXERCONTROL_CT_UNITS_SIGNED)
#define MIXERCONTROL_CONTROLTYPE_PAN (MIXERCONTROL_CONTROLTYPE_SLIDER + 1)
#define MIXERCONTROL_CONTROLTYPE_QSOUNDPAN (MIXERCONTROL_CONTROLTYPE_SLIDER + 2)
#define MIXERCONTROL_CONTROLTYPE_FADER (MIXERCONTROL_CT_CLASS_FADER | MIXERCONTROL_CT_UNITS_UNSIGNED)
#define MIXERCONTROL_CONTROLTYPE_VOLUME (MIXERCONTROL_CONTROLTYPE_FADER + 1)
#define MIXERCONTROL_CONTROLTYPE_BASS (MIXERCONTROL_CONTROLTYPE_FADER + 2)
#define MIXERCONTROL_CONTROLTYPE_TREBLE (MIXERCONTROL_CONTROLTYPE_FADER + 3)
#define MIXERCONTROL_CONTROLTYPE_EQUALIZER (MIXERCONTROL_CONTROLTYPE_FADER + 4)
#define MIXERCONTROL_CONTROLTYPE_SINGLESELECT (MIXERCONTROL_CT_CLASS_LIST | MIXERCONTROL_CT_SC_LIST_SINGLE | MIXERCONTROL_CT_UNITS_BOOLEAN)
#define MIXERCONTROL_CONTROLTYPE_MUX (MIXERCONTROL_CONTROLTYPE_SINGLESELECT + 1)
#define MIXERCONTROL_CONTROLTYPE_MULTIPLESELECT (MIXERCONTROL_CT_CLASS_LIST | MIXERCONTROL_CT_SC_LIST_MULTIPLE | MIXERCONTROL_CT_UNITS_BOOLEAN)
#define MIXERCONTROL_CONTROLTYPE_MIXER (MIXERCONTROL_CONTROLTYPE_MULTIPLESELECT + 1)
#define MIXERCONTROL_CONTROLTYPE_MICROTIME (MIXERCONTROL_CT_CLASS_TIME | MIXERCONTROL_CT_SC_TIME_MICROSECS | MIXERCONTROL_CT_UNITS_UNSIGNED)
#define MIXERCONTROL_CONTROLTYPE_MILLITIME (MIXERCONTROL_CT_CLASS_TIME | MIXERCONTROL_CT_SC_TIME_MILLISECS | MIXERCONTROL_CT_UNITS_UNSIGNED)

        typedef struct tagMIXERLINECONTROLSA {
        DWORD cbStruct;
        DWORD dwLineID;
        __C89_NAMELESS union {
            DWORD dwControlID;
            DWORD dwControlType;
        } DUMMYUNIONNAME;
        DWORD cControls;
        DWORD cbmxctrl;
        LPMIXERCONTROLA pamxctrl;
    } MIXERLINECONTROLSA, * PMIXERLINECONTROLSA, * LPMIXERLINECONTROLSA;

    typedef struct tagMIXERLINECONTROLSW {
        DWORD cbStruct;
        DWORD dwLineID;
        __C89_NAMELESS union {
            DWORD dwControlID;
            DWORD dwControlType;
        } DUMMYUNIONNAME;
        DWORD cControls;
        DWORD cbmxctrl;
        LPMIXERCONTROLW pamxctrl;
    } MIXERLINECONTROLSW, * PMIXERLINECONTROLSW, * LPMIXERLINECONTROLSW;

    __MINGW_TYPEDEF_AW(MIXERLINECONTROLS)
        __MINGW_TYPEDEF_AW(PMIXERLINECONTROLS)
        __MINGW_TYPEDEF_AW(LPMIXERLINECONTROLS)

        WINMMAPI MMRESULT WINAPI mixerGetLineControlsA(HMIXEROBJ hmxobj, LPMIXERLINECONTROLSA pmxlc, DWORD fdwControls);
    WINMMAPI MMRESULT WINAPI mixerGetLineControlsW(HMIXEROBJ hmxobj, LPMIXERLINECONTROLSW pmxlc, DWORD fdwControls);

#define mixerGetLineControls __MINGW_NAME_AW(mixerGetLineControls)

#define MIXER_GETLINECONTROLSF_ALL __MSABI_LONG(0x00000000)
#define MIXER_GETLINECONTROLSF_ONEBYID __MSABI_LONG(0x00000001)
#define MIXER_GETLINECONTROLSF_ONEBYTYPE __MSABI_LONG(0x00000002)

#define MIXER_GETLINECONTROLSF_QUERYMASK __MSABI_LONG(0x0000000F)

    typedef struct tMIXERCONTROLDETAILS {
        DWORD cbStruct;
        DWORD dwControlID;
        DWORD cChannels;
        __C89_NAMELESS union {
            HWND hwndOwner;
            DWORD cMultipleItems;
        } DUMMYUNIONNAME;
        DWORD cbDetails;
        LPVOID paDetails;
    } MIXERCONTROLDETAILS, * PMIXERCONTROLDETAILS, * LPMIXERCONTROLDETAILS;

    typedef struct tagMIXERCONTROLDETAILS_LISTTEXTA {
        DWORD dwParam1;
        DWORD dwParam2;
        CHAR szName[MIXER_LONG_NAME_CHARS];
    } MIXERCONTROLDETAILS_LISTTEXTA, * PMIXERCONTROLDETAILS_LISTTEXTA, * LPMIXERCONTROLDETAILS_LISTTEXTA;
    typedef struct tagMIXERCONTROLDETAILS_LISTTEXTW {
        DWORD dwParam1;
        DWORD dwParam2;
        WCHAR szName[MIXER_LONG_NAME_CHARS];
    } MIXERCONTROLDETAILS_LISTTEXTW, * PMIXERCONTROLDETAILS_LISTTEXTW, * LPMIXERCONTROLDETAILS_LISTTEXTW;

    __MINGW_TYPEDEF_AW(MIXERCONTROLDETAILS_LISTTEXT)
        __MINGW_TYPEDEF_AW(PMIXERCONTROLDETAILS_LISTTEXT)
        __MINGW_TYPEDEF_AW(LPMIXERCONTROLDETAILS_LISTTEXT)

        typedef struct tMIXERCONTROLDETAILS_BOOLEAN {
        LONG fValue;
    } MIXERCONTROLDETAILS_BOOLEAN, * PMIXERCONTROLDETAILS_BOOLEAN, * LPMIXERCONTROLDETAILS_BOOLEAN;

    typedef struct tMIXERCONTROLDETAILS_SIGNED {
        LONG lValue;
    } MIXERCONTROLDETAILS_SIGNED, * PMIXERCONTROLDETAILS_SIGNED, * LPMIXERCONTROLDETAILS_SIGNED;

    typedef struct tMIXERCONTROLDETAILS_UNSIGNED {
        DWORD dwValue;
    } MIXERCONTROLDETAILS_UNSIGNED, * PMIXERCONTROLDETAILS_UNSIGNED, * LPMIXERCONTROLDETAILS_UNSIGNED;

    WINMMAPI MMRESULT WINAPI mixerGetControlDetailsA(HMIXEROBJ hmxobj, LPMIXERCONTROLDETAILS pmxcd, DWORD fdwDetails);
    WINMMAPI MMRESULT WINAPI mixerGetControlDetailsW(HMIXEROBJ hmxobj, LPMIXERCONTROLDETAILS pmxcd, DWORD fdwDetails);

#define mixerGetControlDetails __MINGW_NAME_AW(mixerGetControlDetails)

#define MIXER_GETCONTROLDETAILSF_VALUE __MSABI_LONG(0x00000000)
#define MIXER_GETCONTROLDETAILSF_LISTTEXT __MSABI_LONG(0x00000001)

#define MIXER_GETCONTROLDETAILSF_QUERYMASK __MSABI_LONG(0x0000000F)

    WINMMAPI MMRESULT WINAPI mixerSetControlDetails(HMIXEROBJ hmxobj, LPMIXERCONTROLDETAILS pmxcd, DWORD fdwDetails);

#define MIXER_SETCONTROLDETAILSF_VALUE __MSABI_LONG(0x00000000)
#define MIXER_SETCONTROLDETAILSF_CUSTOM __MSABI_LONG(0x00000001)

#define MIXER_SETCONTROLDETAILSF_QUERYMASK __MSABI_LONG(0x0000000F)
#endif

#ifndef MMNOTIMER

#define TIMERR_NOERROR (0)
#define TIMERR_NOCANDO (TIMERR_BASE+1)
#define TIMERR_STRUCT (TIMERR_BASE+33)

    typedef void (CALLBACK TIMECALLBACK)(UINT uTimerID, UINT uMsg, DWORD_PTR dwUser, DWORD_PTR dw1, DWORD_PTR dw2);
    typedef TIMECALLBACK* LPTIMECALLBACK;

#define TIME_ONESHOT 0x0000
#define TIME_PERIODIC 0x0001

#define TIME_CALLBACK_FUNCTION 0x0000
#define TIME_CALLBACK_EVENT_SET 0x0010
#define TIME_CALLBACK_EVENT_PULSE 0x0020
#define TIME_KILL_SYNCHRONOUS 0x0100

    typedef struct timecaps_tag {
        UINT wPeriodMin;
        UINT wPeriodMax;
    } TIMECAPS, * PTIMECAPS, NEAR* NPTIMECAPS, * LPTIMECAPS;

    WINMMAPI MMRESULT WINAPI timeGetSystemTime(LPMMTIME pmmt, UINT cbmmt);
    WINMMAPI DWORD WINAPI timeGetTime(void);
    WINMMAPI MMRESULT WINAPI timeSetEvent(UINT uDelay, UINT uResolution, LPTIMECALLBACK fptc, DWORD_PTR dwUser, UINT fuEvent);
    WINMMAPI MMRESULT WINAPI timeKillEvent(UINT uTimerID);
    WINMMAPI MMRESULT WINAPI timeGetDevCaps(LPTIMECAPS ptc, UINT cbtc);
    WINMMAPI MMRESULT WINAPI timeBeginPeriod(UINT uPeriod);
    WINMMAPI MMRESULT WINAPI timeEndPeriod(UINT uPeriod);
#endif

#ifndef MMNOJOY

#define JOYERR_NOERROR (0)
#define JOYERR_PARMS (JOYERR_BASE+5)
#define JOYERR_NOCANDO (JOYERR_BASE+6)
#define JOYERR_UNPLUGGED (JOYERR_BASE+7)

#define JOY_BUTTON1 0x0001
#define JOY_BUTTON2 0x0002
#define JOY_BUTTON3 0x0004
#define JOY_BUTTON4 0x0008
#define JOY_BUTTON1CHG 0x0100
#define JOY_BUTTON2CHG 0x0200
#define JOY_BUTTON3CHG 0x0400
#define JOY_BUTTON4CHG 0x0800

#define JOY_BUTTON5 __MSABI_LONG(0x00000010)
#define JOY_BUTTON6 __MSABI_LONG(0x00000020)
#define JOY_BUTTON7 __MSABI_LONG(0x00000040)
#define JOY_BUTTON8 __MSABI_LONG(0x00000080)
#define JOY_BUTTON9 __MSABI_LONG(0x00000100)
#define JOY_BUTTON10 __MSABI_LONG(0x00000200)
#define JOY_BUTTON11 __MSABI_LONG(0x00000400)
#define JOY_BUTTON12 __MSABI_LONG(0x00000800)
#define JOY_BUTTON13 __MSABI_LONG(0x00001000)
#define JOY_BUTTON14 __MSABI_LONG(0x00002000)
#define JOY_BUTTON15 __MSABI_LONG(0x00004000)
#define JOY_BUTTON16 __MSABI_LONG(0x00008000)
#define JOY_BUTTON17 __MSABI_LONG(0x00010000)
#define JOY_BUTTON18 __MSABI_LONG(0x00020000)
#define JOY_BUTTON19 __MSABI_LONG(0x00040000)
#define JOY_BUTTON20 __MSABI_LONG(0x00080000)
#define JOY_BUTTON21 __MSABI_LONG(0x00100000)
#define JOY_BUTTON22 __MSABI_LONG(0x00200000)
#define JOY_BUTTON23 __MSABI_LONG(0x00400000)
#define JOY_BUTTON24 __MSABI_LONG(0x00800000)
#define JOY_BUTTON25 __MSABI_LONG(0x01000000)
#define JOY_BUTTON26 __MSABI_LONG(0x02000000)
#define JOY_BUTTON27 __MSABI_LONG(0x04000000)
#define JOY_BUTTON28 __MSABI_LONG(0x08000000)
#define JOY_BUTTON29 __MSABI_LONG(0x10000000)
#define JOY_BUTTON30 __MSABI_LONG(0x20000000)
#define JOY_BUTTON31 __MSABI_LONG(0x40000000)
#define JOY_BUTTON32 __MSABI_LONG(0x80000000)

#define JOY_POVCENTERED (WORD) -1
#define JOY_POVFORWARD 0
#define JOY_POVRIGHT 9000
#define JOY_POVBACKWARD 18000
#define JOY_POVLEFT 27000

#define JOY_RETURNX __MSABI_LONG(0x00000001)
#define JOY_RETURNY __MSABI_LONG(0x00000002)
#define JOY_RETURNZ __MSABI_LONG(0x00000004)
#define JOY_RETURNR __MSABI_LONG(0x00000008)
#define JOY_RETURNU __MSABI_LONG(0x00000010)
#define JOY_RETURNV __MSABI_LONG(0x00000020)
#define JOY_RETURNPOV __MSABI_LONG(0x00000040)
#define JOY_RETURNBUTTONS __MSABI_LONG(0x00000080)
#define JOY_RETURNRAWDATA __MSABI_LONG(0x00000100)
#define JOY_RETURNPOVCTS __MSABI_LONG(0x00000200)
#define JOY_RETURNCENTERED __MSABI_LONG(0x00000400)
#define JOY_USEDEADZONE __MSABI_LONG(0x00000800)
#define JOY_RETURNALL (JOY_RETURNX | JOY_RETURNY | JOY_RETURNZ | JOY_RETURNR | JOY_RETURNU | JOY_RETURNV | JOY_RETURNPOV | JOY_RETURNBUTTONS)
#define JOY_CAL_READALWAYS __MSABI_LONG(0x00010000)
#define JOY_CAL_READXYONLY __MSABI_LONG(0x00020000)
#define JOY_CAL_READ3 __MSABI_LONG(0x00040000)
#define JOY_CAL_READ4 __MSABI_LONG(0x00080000)
#define JOY_CAL_READXONLY __MSABI_LONG(0x00100000)
#define JOY_CAL_READYONLY __MSABI_LONG(0x00200000)
#define JOY_CAL_READ5 __MSABI_LONG(0x00400000)
#define JOY_CAL_READ6 __MSABI_LONG(0x00800000)
#define JOY_CAL_READZONLY __MSABI_LONG(0x01000000)
#define JOY_CAL_READRONLY __MSABI_LONG(0x02000000)
#define JOY_CAL_READUONLY __MSABI_LONG(0x04000000)
#define JOY_CAL_READVONLY __MSABI_LONG(0x08000000)

#define JOYSTICKID1 0
#define JOYSTICKID2 1

#define JOYCAPS_HASZ 0x0001
#define JOYCAPS_HASR 0x0002
#define JOYCAPS_HASU 0x0004
#define JOYCAPS_HASV 0x0008
#define JOYCAPS_HASPOV 0x0010
#define JOYCAPS_POV4DIR 0x0020
#define JOYCAPS_POVCTS 0x0040

    typedef struct tagJOYCAPSA {
        WORD wMid;
        WORD wPid;
        CHAR szPname[MAXPNAMELEN];
        UINT wXmin;
        UINT wXmax;
        UINT wYmin;
        UINT wYmax;
        UINT wZmin;
        UINT wZmax;
        UINT wNumButtons;
        UINT wPeriodMin;
        UINT wPeriodMax;
        UINT wRmin;
        UINT wRmax;
        UINT wUmin;
        UINT wUmax;
        UINT wVmin;
        UINT wVmax;
        UINT wCaps;
        UINT wMaxAxes;
        UINT wNumAxes;
        UINT wMaxButtons;
        CHAR szRegKey[MAXPNAMELEN];
        CHAR szOEMVxD[MAX_JOYSTICKOEMVXDNAME];
    } JOYCAPSA, * PJOYCAPSA, * NPJOYCAPSA, * LPJOYCAPSA;

    typedef struct tagJOYCAPSW {
        WORD wMid;
        WORD wPid;
        WCHAR szPname[MAXPNAMELEN];
        UINT wXmin;
        UINT wXmax;
        UINT wYmin;
        UINT wYmax;
        UINT wZmin;
        UINT wZmax;
        UINT wNumButtons;
        UINT wPeriodMin;
        UINT wPeriodMax;
        UINT wRmin;
        UINT wRmax;
        UINT wUmin;
        UINT wUmax;
        UINT wVmin;
        UINT wVmax;
        UINT wCaps;
        UINT wMaxAxes;
        UINT wNumAxes;
        UINT wMaxButtons;
        WCHAR szRegKey[MAXPNAMELEN];
        WCHAR szOEMVxD[MAX_JOYSTICKOEMVXDNAME];
    } JOYCAPSW, * PJOYCAPSW, * NPJOYCAPSW, * LPJOYCAPSW;

    __MINGW_TYPEDEF_AW(JOYCAPS)
        __MINGW_TYPEDEF_AW(PJOYCAPS)
        __MINGW_TYPEDEF_AW(NPJOYCAPS)
        __MINGW_TYPEDEF_AW(LPJOYCAPS)

        typedef struct tagJOYCAPS2A {
        WORD wMid;
        WORD wPid;
        CHAR szPname[MAXPNAMELEN];
        UINT wXmin;
        UINT wXmax;
        UINT wYmin;
        UINT wYmax;
        UINT wZmin;
        UINT wZmax;
        UINT wNumButtons;
        UINT wPeriodMin;
        UINT wPeriodMax;
        UINT wRmin;
        UINT wRmax;
        UINT wUmin;
        UINT wUmax;
        UINT wVmin;
        UINT wVmax;
        UINT wCaps;
        UINT wMaxAxes;
        UINT wNumAxes;
        UINT wMaxButtons;
        CHAR szRegKey[MAXPNAMELEN];
        CHAR szOEMVxD[MAX_JOYSTICKOEMVXDNAME];
        GUID ManufacturerGuid;
        GUID ProductGuid;
        GUID NameGuid;
    } JOYCAPS2A, * PJOYCAPS2A, * NPJOYCAPS2A, * LPJOYCAPS2A;

    typedef struct tagJOYCAPS2W {
        WORD wMid;
        WORD wPid;
        WCHAR szPname[MAXPNAMELEN];
        UINT wXmin;
        UINT wXmax;
        UINT wYmin;
        UINT wYmax;
        UINT wZmin;
        UINT wZmax;
        UINT wNumButtons;
        UINT wPeriodMin;
        UINT wPeriodMax;
        UINT wRmin;
        UINT wRmax;
        UINT wUmin;
        UINT wUmax;
        UINT wVmin;
        UINT wVmax;
        UINT wCaps;
        UINT wMaxAxes;
        UINT wNumAxes;
        UINT wMaxButtons;
        WCHAR szRegKey[MAXPNAMELEN];
        WCHAR szOEMVxD[MAX_JOYSTICKOEMVXDNAME];
        GUID ManufacturerGuid;
        GUID ProductGuid;
        GUID NameGuid;
    } JOYCAPS2W, * PJOYCAPS2W, * NPJOYCAPS2W, * LPJOYCAPS2W;

    __MINGW_TYPEDEF_AW(JOYCAPS2)
        __MINGW_TYPEDEF_AW(PJOYCAPS2)
        __MINGW_TYPEDEF_AW(NPJOYCAPS2)
        __MINGW_TYPEDEF_AW(LPJOYCAPS2)

        typedef struct joyinfo_tag {
        UINT wXpos;
        UINT wYpos;
        UINT wZpos;
        UINT wButtons;
    } JOYINFO, * PJOYINFO, NEAR* NPJOYINFO, * LPJOYINFO;

    typedef struct joyinfoex_tag {
        DWORD dwSize;
        DWORD dwFlags;
        DWORD dwXpos;
        DWORD dwYpos;
        DWORD dwZpos;
        DWORD dwRpos;
        DWORD dwUpos;
        DWORD dwVpos;
        DWORD dwButtons;
        DWORD dwButtonNumber;
        DWORD dwPOV;
        DWORD dwReserved1;
        DWORD dwReserved2;
    } JOYINFOEX, * PJOYINFOEX, NEAR* NPJOYINFOEX, * LPJOYINFOEX;

    WINMMAPI UINT WINAPI joyGetNumDevs(void);
    WINMMAPI MMRESULT WINAPI joyGetDevCapsA(UINT_PTR uJoyID, LPJOYCAPSA pjc, UINT cbjc);
    WINMMAPI MMRESULT WINAPI joyGetDevCapsW(UINT_PTR uJoyID, LPJOYCAPSW pjc, UINT cbjc);

#define joyGetDevCaps __MINGW_NAME_AW(joyGetDevCaps)

    WINMMAPI MMRESULT WINAPI joyGetPos(UINT uJoyID, LPJOYINFO pji);
    WINMMAPI MMRESULT WINAPI joyGetPosEx(UINT uJoyID, LPJOYINFOEX pji);
    WINMMAPI MMRESULT WINAPI joyGetThreshold(UINT uJoyID, LPUINT puThreshold);
    WINMMAPI MMRESULT WINAPI joyReleaseCapture(UINT uJoyID);
    WINMMAPI MMRESULT WINAPI joySetCapture(HWND hwnd, UINT uJoyID, UINT uPeriod, WINBOOL fChanged);
    WINMMAPI MMRESULT WINAPI joySetThreshold(UINT uJoyID, UINT uThreshold);
#endif

#ifndef MMNOMMIO

#define MMIOERR_BASE 256
#define MMIOERR_FILENOTFOUND (MMIOERR_BASE + 1)
#define MMIOERR_OUTOFMEMORY (MMIOERR_BASE + 2)
#define MMIOERR_CANNOTOPEN (MMIOERR_BASE + 3)
#define MMIOERR_CANNOTCLOSE (MMIOERR_BASE + 4)
#define MMIOERR_CANNOTREAD (MMIOERR_BASE + 5)
#define MMIOERR_CANNOTWRITE (MMIOERR_BASE + 6)
#define MMIOERR_CANNOTSEEK (MMIOERR_BASE + 7)
#define MMIOERR_CANNOTEXPAND (MMIOERR_BASE + 8)
#define MMIOERR_CHUNKNOTFOUND (MMIOERR_BASE + 9)
#define MMIOERR_UNBUFFERED (MMIOERR_BASE + 10)
#define MMIOERR_PATHNOTFOUND (MMIOERR_BASE + 11)
#define MMIOERR_ACCESSDENIED (MMIOERR_BASE + 12)
#define MMIOERR_SHARINGVIOLATION (MMIOERR_BASE + 13)
#define MMIOERR_NETWORKERROR (MMIOERR_BASE + 14)
#define MMIOERR_TOOMANYOPENFILES (MMIOERR_BASE + 15)
#define MMIOERR_INVALIDFILE (MMIOERR_BASE + 16)

#define CFSEPCHAR '+'

    typedef DWORD FOURCC;
    typedef char _huge* HPSTR;
    DECLARE_HANDLE(HMMIO);
    typedef LRESULT(CALLBACK MMIOPROC)(LPSTR lpmmioinfo, UINT uMsg, LPARAM lParam1, LPARAM lParam2);
    typedef MMIOPROC* LPMMIOPROC;

    typedef struct _MMIOINFO {
        DWORD dwFlags;
        FOURCC fccIOProc;
        LPMMIOPROC pIOProc;
        UINT wErrorRet;
        HTASK htask;
        LONG cchBuffer;
        HPSTR pchBuffer;
        HPSTR pchNext;
        HPSTR pchEndRead;
        HPSTR pchEndWrite;
        LONG lBufOffset;
        LONG lDiskOffset;
        DWORD adwInfo[3];
        DWORD dwReserved1;
        DWORD dwReserved2;
        HMMIO hmmio;
    } MMIOINFO, * PMMIOINFO, NEAR* NPMMIOINFO, * LPMMIOINFO;

    typedef const MMIOINFO* LPCMMIOINFO;

    typedef struct _MMCKINFO {
        FOURCC ckid;
        DWORD cksize;
        FOURCC fccType;
        DWORD dwDataOffset;
        DWORD dwFlags;
    } MMCKINFO, * PMMCKINFO, NEAR* NPMMCKINFO, * LPMMCKINFO;

    typedef const MMCKINFO* LPCMMCKINFO;

#define MMIO_RWMODE 0x00000003
#define MMIO_SHAREMODE 0x00000070

#define MMIO_CREATE 0x00001000
#define MMIO_PARSE 0x00000100
#define MMIO_DELETE 0x00000200
#define MMIO_EXIST 0x00004000
#define MMIO_ALLOCBUF 0x00010000
#define MMIO_GETTEMP 0x00020000

#define MMIO_DIRTY 0x10000000

#define MMIO_READ 0x00000000
#define MMIO_WRITE 0x00000001
#define MMIO_READWRITE 0x00000002

#define MMIO_COMPAT 0x00000000
#define MMIO_EXCLUSIVE 0x00000010
#define MMIO_DENYWRITE 0x00000020
#define MMIO_DENYREAD 0x00000030
#define MMIO_DENYNONE 0x00000040

#define MMIO_FHOPEN 0x0010
#define MMIO_EMPTYBUF 0x0010
#define MMIO_TOUPPER 0x0010
#define MMIO_INSTALLPROC 0x00010000
#define MMIO_GLOBALPROC 0x10000000
#define MMIO_REMOVEPROC 0x00020000
#define MMIO_UNICODEPROC 0x01000000
#define MMIO_FINDPROC 0x00040000
#define MMIO_FINDCHUNK 0x0010
#define MMIO_FINDRIFF 0x0020
#define MMIO_FINDLIST 0x0040
#define MMIO_CREATERIFF 0x0020
#define MMIO_CREATELIST 0x0040

#define MMIOM_READ MMIO_READ
#define MMIOM_WRITE MMIO_WRITE
#define MMIOM_SEEK 2
#define MMIOM_OPEN 3
#define MMIOM_CLOSE 4
#define MMIOM_WRITEFLUSH 5
#define MMIOM_RENAME 6

#define MMIOM_USER 0x8000

#define FOURCC_RIFF mmioFOURCC('R','I','F','F')
#define FOURCC_LIST mmioFOURCC('L','I','S','T')

#define FOURCC_DOS mmioFOURCC('D','O','S',' ')
#define FOURCC_MEM mmioFOURCC('M','E','M',' ')

#ifndef SEEK_SET
#define SEEK_SET 0
#define SEEK_CUR 1
#define SEEK_END 2
#endif

#define MMIO_DEFAULTBUFFER 8192

#define mmioFOURCC(ch0,ch1,ch2,ch3) MAKEFOURCC(ch0,ch1,ch2,ch3)

    WINMMAPI FOURCC WINAPI mmioStringToFOURCCA(LPCSTR sz, UINT uFlags);
    WINMMAPI FOURCC WINAPI mmioStringToFOURCCW(LPCWSTR sz, UINT uFlags);

#define mmioStringToFOURCC __MINGW_NAME_AW(mmioStringToFOURCC)

    WINMMAPI LPMMIOPROC WINAPI mmioInstallIOProcA(FOURCC fccIOProc, LPMMIOPROC pIOProc, DWORD dwFlags);
    WINMMAPI LPMMIOPROC WINAPI mmioInstallIOProcW(FOURCC fccIOProc, LPMMIOPROC pIOProc, DWORD dwFlags);

#define mmioInstallIOProc __MINGW_NAME_AW(mmioInstallIOProc)

    WINMMAPI HMMIO WINAPI mmioOpenA(LPSTR pszFileName, LPMMIOINFO pmmioinfo, DWORD fdwOpen);
    WINMMAPI HMMIO WINAPI mmioOpenW(LPWSTR pszFileName, LPMMIOINFO pmmioinfo, DWORD fdwOpen);

#define mmioOpen __MINGW_NAME_AW(mmioOpen)

    WINMMAPI MMRESULT WINAPI mmioRenameA(LPCSTR pszFileName, LPCSTR pszNewFileName, LPCMMIOINFO pmmioinfo, DWORD fdwRename);
    WINMMAPI MMRESULT WINAPI mmioRenameW(LPCWSTR pszFileName, LPCWSTR pszNewFileName, LPCMMIOINFO pmmioinfo, DWORD fdwRename);

#define mmioRename __MINGW_NAME_AW(mmioRename)

    WINMMAPI MMRESULT WINAPI mmioClose(HMMIO hmmio, UINT fuClose);
    WINMMAPI LONG WINAPI mmioRead(HMMIO hmmio, HPSTR pch, LONG cch);
    WINMMAPI LONG WINAPI mmioWrite(HMMIO hmmio, const char _huge* pch, LONG cch);
    WINMMAPI LONG WINAPI mmioSeek(HMMIO hmmio, LONG lOffset, int iOrigin);
    WINMMAPI MMRESULT WINAPI mmioGetInfo(HMMIO hmmio, LPMMIOINFO pmmioinfo, UINT fuInfo);
    WINMMAPI MMRESULT WINAPI mmioSetInfo(HMMIO hmmio, LPCMMIOINFO pmmioinfo, UINT fuInfo);
    WINMMAPI MMRESULT WINAPI mmioSetBuffer(HMMIO hmmio, LPSTR pchBuffer, LONG cchBuffer, UINT fuBuffer);
    WINMMAPI MMRESULT WINAPI mmioFlush(HMMIO hmmio, UINT fuFlush);
    WINMMAPI MMRESULT WINAPI mmioAdvance(HMMIO hmmio, LPMMIOINFO pmmioinfo, UINT fuAdvance);
    WINMMAPI LRESULT WINAPI mmioSendMessage(HMMIO hmmio, UINT uMsg, LPARAM lParam1, LPARAM lParam2);
    WINMMAPI MMRESULT WINAPI mmioDescend(HMMIO hmmio, LPMMCKINFO pmmcki, const MMCKINFO* pmmckiParent, UINT fuDescend);
    WINMMAPI MMRESULT WINAPI mmioAscend(HMMIO hmmio, LPMMCKINFO pmmcki, UINT fuAscend);
    WINMMAPI MMRESULT WINAPI mmioCreateChunk(HMMIO hmmio, LPMMCKINFO pmmcki, UINT fuCreate);
#endif

#ifndef MMNOMCI

#ifndef _MCIERROR_
#define _MCIERROR_
    typedef DWORD MCIERROR;
#endif

#ifndef _MCIDEVICEID_
#define _MCIDEVICEID_
    typedef UINT MCIDEVICEID;
#endif

    typedef UINT(CALLBACK* YIELDPROC)(MCIDEVICEID mciId, DWORD dwYieldData);

    WINMMAPI MCIERROR WINAPI mciSendCommandA(MCIDEVICEID mciId, UINT uMsg, DWORD_PTR dwParam1, DWORD_PTR dwParam2);
    WINMMAPI MCIERROR WINAPI mciSendCommandW(MCIDEVICEID mciId, UINT uMsg, DWORD_PTR dwParam1, DWORD_PTR dwParam2);

#define mciSendCommand __MINGW_NAME_AW(mciSendCommand)

    WINMMAPI MCIERROR WINAPI mciSendStringA(LPCSTR lpstrCommand, LPSTR lpstrReturnString, UINT uReturnLength, HWND hwndCallback);
    WINMMAPI MCIERROR WINAPI mciSendStringW(LPCWSTR lpstrCommand, LPWSTR lpstrReturnString, UINT uReturnLength, HWND hwndCallback);

#define mciSendString __MINGW_NAME_AW(mciSendString)

    WINMMAPI MCIDEVICEID WINAPI mciGetDeviceIDA(LPCSTR pszDevice);
    WINMMAPI MCIDEVICEID WINAPI mciGetDeviceIDW(LPCWSTR pszDevice);

#define mciGetDeviceID __MINGW_NAME_AW(mciGetDeviceID)

    WINMMAPI MCIDEVICEID WINAPI mciGetDeviceIDFromElementIDA(DWORD dwElementID, LPCSTR lpstrType);
    WINMMAPI MCIDEVICEID WINAPI mciGetDeviceIDFromElementIDW(DWORD dwElementID, LPCWSTR lpstrType);

#define mciGetDeviceIDFromElementID __MINGW_NAME_AW(mciGetDeviceIDFromElementID)

    WINMMAPI WINBOOL WINAPI mciGetErrorStringA(MCIERROR mcierr, LPSTR pszText, UINT cchText);
    WINMMAPI WINBOOL WINAPI mciGetErrorStringW(MCIERROR mcierr, LPWSTR pszText, UINT cchText);

#define mciGetErrorString __MINGW_NAME_AW(mciGetErrorString)

    WINMMAPI WINBOOL WINAPI mciSetYieldProc(MCIDEVICEID mciId, YIELDPROC fpYieldProc, DWORD dwYieldData);
    WINMMAPI HTASK WINAPI mciGetCreatorTask(MCIDEVICEID mciId);
    WINMMAPI YIELDPROC WINAPI mciGetYieldProc(MCIDEVICEID mciId, LPDWORD pdwYieldData);

#define MCIERR_INVALID_DEVICE_ID (MCIERR_BASE + 1)
#define MCIERR_UNRECOGNIZED_KEYWORD (MCIERR_BASE + 3)
#define MCIERR_UNRECOGNIZED_COMMAND (MCIERR_BASE + 5)
#define MCIERR_HARDWARE (MCIERR_BASE + 6)
#define MCIERR_INVALID_DEVICE_NAME (MCIERR_BASE + 7)
#define MCIERR_OUT_OF_MEMORY (MCIERR_BASE + 8)
#define MCIERR_DEVICE_OPEN (MCIERR_BASE + 9)
#define MCIERR_CANNOT_LOAD_DRIVER (MCIERR_BASE + 10)
#define MCIERR_MISSING_COMMAND_STRING (MCIERR_BASE + 11)
#define MCIERR_PARAM_OVERFLOW (MCIERR_BASE + 12)
#define MCIERR_MISSING_STRING_ARGUMENT (MCIERR_BASE + 13)
#define MCIERR_BAD_INTEGER (MCIERR_BASE + 14)
#define MCIERR_PARSER_INTERNAL (MCIERR_BASE + 15)
#define MCIERR_DRIVER_INTERNAL (MCIERR_BASE + 16)
#define MCIERR_MISSING_PARAMETER (MCIERR_BASE + 17)
#define MCIERR_UNSUPPORTED_FUNCTION (MCIERR_BASE + 18)
#define MCIERR_FILE_NOT_FOUND (MCIERR_BASE + 19)
#define MCIERR_DEVICE_NOT_READY (MCIERR_BASE + 20)
#define MCIERR_INTERNAL (MCIERR_BASE + 21)
#define MCIERR_DRIVER (MCIERR_BASE + 22)
#define MCIERR_CANNOT_USE_ALL (MCIERR_BASE + 23)
#define MCIERR_MULTIPLE (MCIERR_BASE + 24)
#define MCIERR_EXTENSION_NOT_FOUND (MCIERR_BASE + 25)
#define MCIERR_OUTOFRANGE (MCIERR_BASE + 26)
#define MCIERR_FLAGS_NOT_COMPATIBLE (MCIERR_BASE + 28)
#define MCIERR_FILE_NOT_SAVED (MCIERR_BASE + 30)
#define MCIERR_DEVICE_TYPE_REQUIRED (MCIERR_BASE + 31)
#define MCIERR_DEVICE_LOCKED (MCIERR_BASE + 32)
#define MCIERR_DUPLICATE_ALIAS (MCIERR_BASE + 33)
#define MCIERR_BAD_CONSTANT (MCIERR_BASE + 34)
#define MCIERR_MUST_USE_SHAREABLE (MCIERR_BASE + 35)
#define MCIERR_MISSING_DEVICE_NAME (MCIERR_BASE + 36)
#define MCIERR_BAD_TIME_FORMAT (MCIERR_BASE + 37)
#define MCIERR_NO_CLOSING_QUOTE (MCIERR_BASE + 38)
#define MCIERR_DUPLICATE_FLAGS (MCIERR_BASE + 39)
#define MCIERR_INVALID_FILE (MCIERR_BASE + 40)
#define MCIERR_NULL_PARAMETER_BLOCK (MCIERR_BASE + 41)
#define MCIERR_UNNAMED_RESOURCE (MCIERR_BASE + 42)
#define MCIERR_NEW_REQUIRES_ALIAS (MCIERR_BASE + 43)
#define MCIERR_NOTIFY_ON_AUTO_OPEN (MCIERR_BASE + 44)
#define MCIERR_NO_ELEMENT_ALLOWED (MCIERR_BASE + 45)
#define MCIERR_NONAPPLICABLE_FUNCTION (MCIERR_BASE + 46)
#define MCIERR_ILLEGAL_FOR_AUTO_OPEN (MCIERR_BASE + 47)
#define MCIERR_FILENAME_REQUIRED (MCIERR_BASE + 48)
#define MCIERR_EXTRA_CHARACTERS (MCIERR_BASE + 49)
#define MCIERR_DEVICE_NOT_INSTALLED (MCIERR_BASE + 50)
#define MCIERR_GET_CD (MCIERR_BASE + 51)
#define MCIERR_SET_CD (MCIERR_BASE + 52)
#define MCIERR_SET_DRIVE (MCIERR_BASE + 53)
#define MCIERR_DEVICE_LENGTH (MCIERR_BASE + 54)
#define MCIERR_DEVICE_ORD_LENGTH (MCIERR_BASE + 55)
#define MCIERR_NO_INTEGER (MCIERR_BASE + 56)
#define MCIERR_WAVE_OUTPUTSINUSE (MCIERR_BASE + 64)
#define MCIERR_WAVE_SETOUTPUTINUSE (MCIERR_BASE + 65)
#define MCIERR_WAVE_INPUTSINUSE (MCIERR_BASE + 66)
#define MCIERR_WAVE_SETINPUTINUSE (MCIERR_BASE + 67)
#define MCIERR_WAVE_OUTPUTUNSPECIFIED (MCIERR_BASE + 68)
#define MCIERR_WAVE_INPUTUNSPECIFIED (MCIERR_BASE + 69)
#define MCIERR_WAVE_OUTPUTSUNSUITABLE (MCIERR_BASE + 70)
#define MCIERR_WAVE_SETOUTPUTUNSUITABLE (MCIERR_BASE + 71)
#define MCIERR_WAVE_INPUTSUNSUITABLE (MCIERR_BASE + 72)
#define MCIERR_WAVE_SETINPUTUNSUITABLE (MCIERR_BASE + 73)
#define MCIERR_SEQ_DIV_INCOMPATIBLE (MCIERR_BASE + 80)
#define MCIERR_SEQ_PORT_INUSE (MCIERR_BASE + 81)
#define MCIERR_SEQ_PORT_NONEXISTENT (MCIERR_BASE + 82)
#define MCIERR_SEQ_PORT_MAPNODEVICE (MCIERR_BASE + 83)
#define MCIERR_SEQ_PORT_MISCERROR (MCIERR_BASE + 84)
#define MCIERR_SEQ_TIMER (MCIERR_BASE + 85)
#define MCIERR_SEQ_PORTUNSPECIFIED (MCIERR_BASE + 86)
#define MCIERR_SEQ_NOMIDIPRESENT (MCIERR_BASE + 87)
#define MCIERR_NO_WINDOW (MCIERR_BASE + 90)
#define MCIERR_CREATEWINDOW (MCIERR_BASE + 91)
#define MCIERR_FILE_READ (MCIERR_BASE + 92)
#define MCIERR_FILE_WRITE (MCIERR_BASE + 93)
#define MCIERR_NO_IDENTITY (MCIERR_BASE + 94)
#define MCIERR_CUSTOM_DRIVER_BASE (MCIERR_BASE + 256)

#define MCI_FIRST DRV_MCI_FIRST

#define MCI_OPEN 0x0803
#define MCI_CLOSE 0x0804
#define MCI_ESCAPE 0x0805
#define MCI_PLAY 0x0806
#define MCI_SEEK 0x0807
#define MCI_STOP 0x0808
#define MCI_PAUSE 0x0809
#define MCI_INFO 0x080A
#define MCI_GETDEVCAPS 0x080B
#define MCI_SPIN 0x080C
#define MCI_SET 0x080D
#define MCI_STEP 0x080E
#define MCI_RECORD 0x080F
#define MCI_SYSINFO 0x0810
#define MCI_BREAK 0x0811
#define MCI_SAVE 0x0813
#define MCI_STATUS 0x0814
#define MCI_CUE 0x0830
#define MCI_REALIZE 0x0840
#define MCI_WINDOW 0x0841
#define MCI_PUT 0x0842
#define MCI_WHERE 0x0843
#define MCI_FREEZE 0x0844
#define MCI_UNFREEZE 0x0845
#define MCI_LOAD 0x0850
#define MCI_CUT 0x0851
#define MCI_COPY 0x0852
#define MCI_PASTE 0x0853
#define MCI_UPDATE 0x0854
#define MCI_RESUME 0x0855
#define MCI_DELETE 0x0856

#define MCI_USER_MESSAGES (DRV_MCI_FIRST + 0x400)
#define MCI_LAST 0x0FFF

#define MCI_ALL_DEVICE_ID ((MCIDEVICEID)-1)

#define MCI_DEVTYPE_VCR 513
#define MCI_DEVTYPE_VIDEODISC 514
#define MCI_DEVTYPE_OVERLAY 515
#define MCI_DEVTYPE_CD_AUDIO 516
#define MCI_DEVTYPE_DAT 517
#define MCI_DEVTYPE_SCANNER 518
#define MCI_DEVTYPE_ANIMATION 519
#define MCI_DEVTYPE_DIGITAL_VIDEO 520
#define MCI_DEVTYPE_OTHER 521
#define MCI_DEVTYPE_WAVEFORM_AUDIO 522
#define MCI_DEVTYPE_SEQUENCER 523

#define MCI_DEVTYPE_FIRST MCI_DEVTYPE_VCR
#define MCI_DEVTYPE_LAST MCI_DEVTYPE_SEQUENCER

#define MCI_DEVTYPE_FIRST_USER 0x1000

#define MCI_MODE_NOT_READY (MCI_STRING_OFFSET + 12)
#define MCI_MODE_STOP (MCI_STRING_OFFSET + 13)
#define MCI_MODE_PLAY (MCI_STRING_OFFSET + 14)
#define MCI_MODE_RECORD (MCI_STRING_OFFSET + 15)
#define MCI_MODE_SEEK (MCI_STRING_OFFSET + 16)
#define MCI_MODE_PAUSE (MCI_STRING_OFFSET + 17)
#define MCI_MODE_OPEN (MCI_STRING_OFFSET + 18)

#define MCI_FORMAT_MILLISECONDS 0
#define MCI_FORMAT_HMS 1
#define MCI_FORMAT_MSF 2
#define MCI_FORMAT_FRAMES 3
#define MCI_FORMAT_SMPTE_24 4
#define MCI_FORMAT_SMPTE_25 5
#define MCI_FORMAT_SMPTE_30 6
#define MCI_FORMAT_SMPTE_30DROP 7
#define MCI_FORMAT_BYTES 8
#define MCI_FORMAT_SAMPLES 9
#define MCI_FORMAT_TMSF 10

#define MCI_MSF_MINUTE(msf) ((BYTE)(msf))
#define MCI_MSF_SECOND(msf) ((BYTE)(((WORD)(msf)) >> 8))
#define MCI_MSF_FRAME(msf) ((BYTE)((msf)>>16))

#define MCI_MAKE_MSF(m,s,f) ((DWORD)(((BYTE)(m) | ((WORD)(s)<<8)) | (((DWORD)(BYTE)(f))<<16)))

#define MCI_TMSF_TRACK(tmsf) ((BYTE)(tmsf))
#define MCI_TMSF_MINUTE(tmsf) ((BYTE)(((WORD)(tmsf)) >> 8))
#define MCI_TMSF_SECOND(tmsf) ((BYTE)((tmsf)>>16))
#define MCI_TMSF_FRAME(tmsf) ((BYTE)((tmsf)>>24))

#define MCI_MAKE_TMSF(t,m,s,f) ((DWORD)(((BYTE)(t) | ((WORD)(m)<<8)) | (((DWORD)(BYTE)(s) | ((WORD)(f)<<8))<<16)))

#define MCI_HMS_HOUR(hms) ((BYTE)(hms))
#define MCI_HMS_MINUTE(hms) ((BYTE)(((WORD)(hms)) >> 8))
#define MCI_HMS_SECOND(hms) ((BYTE)((hms)>>16))

#define MCI_MAKE_HMS(h,m,s) ((DWORD)(((BYTE)(h) | ((WORD)(m)<<8)) | (((DWORD)(BYTE)(s))<<16)))

#define MCI_NOTIFY_SUCCESSFUL 0x0001
#define MCI_NOTIFY_SUPERSEDED 0x0002
#define MCI_NOTIFY_ABORTED 0x0004
#define MCI_NOTIFY_FAILURE 0x0008

#define MCI_NOTIFY __MSABI_LONG(0x00000001)
#define MCI_WAIT __MSABI_LONG(0x00000002)
#define MCI_FROM __MSABI_LONG(0x00000004)
#define MCI_TO __MSABI_LONG(0x00000008)
#define MCI_TRACK __MSABI_LONG(0x00000010)

#define MCI_OPEN_SHAREABLE __MSABI_LONG(0x00000100)
#define MCI_OPEN_ELEMENT __MSABI_LONG(0x00000200)
#define MCI_OPEN_ALIAS __MSABI_LONG(0x00000400)
#define MCI_OPEN_ELEMENT_ID __MSABI_LONG(0x00000800)
#define MCI_OPEN_TYPE_ID __MSABI_LONG(0x00001000)
#define MCI_OPEN_TYPE __MSABI_LONG(0x00002000)

#define MCI_SEEK_TO_START __MSABI_LONG(0x00000100)
#define MCI_SEEK_TO_END __MSABI_LONG(0x00000200)

#define MCI_STATUS_ITEM __MSABI_LONG(0x00000100)
#define MCI_STATUS_START __MSABI_LONG(0x00000200)

#define MCI_STATUS_LENGTH __MSABI_LONG(0x00000001)
#define MCI_STATUS_POSITION __MSABI_LONG(0x00000002)
#define MCI_STATUS_NUMBER_OF_TRACKS __MSABI_LONG(0x00000003)
#define MCI_STATUS_MODE __MSABI_LONG(0x00000004)
#define MCI_STATUS_MEDIA_PRESENT __MSABI_LONG(0x00000005)
#define MCI_STATUS_TIME_FORMAT __MSABI_LONG(0x00000006)
#define MCI_STATUS_READY __MSABI_LONG(0x00000007)
#define MCI_STATUS_CURRENT_TRACK __MSABI_LONG(0x00000008)

#define MCI_INFO_PRODUCT __MSABI_LONG(0x00000100)
#define MCI_INFO_FILE __MSABI_LONG(0x00000200)
#define MCI_INFO_MEDIA_UPC __MSABI_LONG(0x00000400)
#define MCI_INFO_MEDIA_IDENTITY __MSABI_LONG(0x00000800)
#define MCI_INFO_NAME __MSABI_LONG(0x00001000)
#define MCI_INFO_COPYRIGHT __MSABI_LONG(0x00002000)

#define MCI_GETDEVCAPS_ITEM __MSABI_LONG(0x00000100)

#define MCI_GETDEVCAPS_CAN_RECORD __MSABI_LONG(0x00000001)
#define MCI_GETDEVCAPS_HAS_AUDIO __MSABI_LONG(0x00000002)
#define MCI_GETDEVCAPS_HAS_VIDEO __MSABI_LONG(0x00000003)
#define MCI_GETDEVCAPS_DEVICE_TYPE __MSABI_LONG(0x00000004)
#define MCI_GETDEVCAPS_USES_FILES __MSABI_LONG(0x00000005)
#define MCI_GETDEVCAPS_COMPOUND_DEVICE __MSABI_LONG(0x00000006)
#define MCI_GETDEVCAPS_CAN_EJECT __MSABI_LONG(0x00000007)
#define MCI_GETDEVCAPS_CAN_PLAY __MSABI_LONG(0x00000008)
#define MCI_GETDEVCAPS_CAN_SAVE __MSABI_LONG(0x00000009)

#define MCI_SYSINFO_QUANTITY __MSABI_LONG(0x00000100)
#define MCI_SYSINFO_OPEN __MSABI_LONG(0x00000200)
#define MCI_SYSINFO_NAME __MSABI_LONG(0x00000400)
#define MCI_SYSINFO_INSTALLNAME __MSABI_LONG(0x00000800)

#define MCI_SET_DOOR_OPEN __MSABI_LONG(0x00000100)
#define MCI_SET_DOOR_CLOSED __MSABI_LONG(0x00000200)
#define MCI_SET_TIME_FORMAT __MSABI_LONG(0x00000400)
#define MCI_SET_AUDIO __MSABI_LONG(0x00000800)
#define MCI_SET_VIDEO __MSABI_LONG(0x00001000)
#define MCI_SET_ON __MSABI_LONG(0x00002000)
#define MCI_SET_OFF __MSABI_LONG(0x00004000)

#define MCI_SET_AUDIO_ALL __MSABI_LONG(0x00000000)
#define MCI_SET_AUDIO_LEFT __MSABI_LONG(0x00000001)
#define MCI_SET_AUDIO_RIGHT __MSABI_LONG(0x00000002)

#define MCI_BREAK_KEY __MSABI_LONG(0x00000100)
#define MCI_BREAK_HWND __MSABI_LONG(0x00000200)
#define MCI_BREAK_OFF __MSABI_LONG(0x00000400)

#define MCI_RECORD_INSERT __MSABI_LONG(0x00000100)
#define MCI_RECORD_OVERWRITE __MSABI_LONG(0x00000200)

#define MCI_SAVE_FILE __MSABI_LONG(0x00000100)

#define MCI_LOAD_FILE __MSABI_LONG(0x00000100)

    typedef struct tagMCI_GENERIC_PARMS {
        DWORD_PTR dwCallback;
    } MCI_GENERIC_PARMS, * PMCI_GENERIC_PARMS, * LPMCI_GENERIC_PARMS;

    typedef struct tagMCI_OPEN_PARMSA {
        DWORD_PTR dwCallback;
        MCIDEVICEID wDeviceID;
        LPCSTR lpstrDeviceType;
        LPCSTR lpstrElementName;
        LPCSTR lpstrAlias;
    } MCI_OPEN_PARMSA, * PMCI_OPEN_PARMSA, * LPMCI_OPEN_PARMSA;

    typedef struct tagMCI_OPEN_PARMSW {
        DWORD_PTR dwCallback;
        MCIDEVICEID wDeviceID;
        LPCWSTR lpstrDeviceType;
        LPCWSTR lpstrElementName;
        LPCWSTR lpstrAlias;
    } MCI_OPEN_PARMSW, * PMCI_OPEN_PARMSW, * LPMCI_OPEN_PARMSW;

    __MINGW_TYPEDEF_AW(MCI_OPEN_PARMS)
        __MINGW_TYPEDEF_AW(PMCI_OPEN_PARMS)
        __MINGW_TYPEDEF_AW(LPMCI_OPEN_PARMS)

        typedef struct tagMCI_PLAY_PARMS {
        DWORD_PTR dwCallback;
        DWORD dwFrom;
        DWORD dwTo;
    } MCI_PLAY_PARMS, * PMCI_PLAY_PARMS, * LPMCI_PLAY_PARMS;

    typedef struct tagMCI_SEEK_PARMS {
        DWORD_PTR dwCallback;
        DWORD dwTo;
    } MCI_SEEK_PARMS, * PMCI_SEEK_PARMS, * LPMCI_SEEK_PARMS;

    typedef struct tagMCI_STATUS_PARMS {
        DWORD_PTR dwCallback;
        DWORD_PTR dwReturn;
        DWORD dwItem;
        DWORD dwTrack;
    } MCI_STATUS_PARMS, * PMCI_STATUS_PARMS, * LPMCI_STATUS_PARMS;

    typedef struct tagMCI_INFO_PARMSA {
        DWORD_PTR dwCallback;
        LPSTR lpstrReturn;
        DWORD dwRetSize;
    } MCI_INFO_PARMSA, * LPMCI_INFO_PARMSA;
    typedef struct tagMCI_INFO_PARMSW {
        DWORD_PTR dwCallback;
        LPWSTR lpstrReturn;
        DWORD dwRetSize;
    } MCI_INFO_PARMSW, * LPMCI_INFO_PARMSW;

    __MINGW_TYPEDEF_AW(MCI_INFO_PARMS)
        __MINGW_TYPEDEF_AW(LPMCI_INFO_PARMS)

        typedef struct tagMCI_GETDEVCAPS_PARMS {
        DWORD_PTR dwCallback;
        DWORD dwReturn;
        DWORD dwItem;
    } MCI_GETDEVCAPS_PARMS, * PMCI_GETDEVCAPS_PARMS, * LPMCI_GETDEVCAPS_PARMS;

    typedef struct tagMCI_SYSINFO_PARMSA {
        DWORD_PTR dwCallback;
        LPSTR lpstrReturn;
        DWORD dwRetSize;
        DWORD dwNumber;
        UINT wDeviceType;
    } MCI_SYSINFO_PARMSA, * PMCI_SYSINFO_PARMSA, * LPMCI_SYSINFO_PARMSA;

    typedef struct tagMCI_SYSINFO_PARMSW {
        DWORD_PTR dwCallback;
        LPWSTR lpstrReturn;
        DWORD dwRetSize;
        DWORD dwNumber;
        UINT wDeviceType;
    } MCI_SYSINFO_PARMSW, * PMCI_SYSINFO_PARMSW, * LPMCI_SYSINFO_PARMSW;

    __MINGW_TYPEDEF_AW(MCI_SYSINFO_PARMS)
        __MINGW_TYPEDEF_AW(PMCI_SYSINFO_PARMS)
        __MINGW_TYPEDEF_AW(LPMCI_SYSINFO_PARMS)

        typedef struct tagMCI_SET_PARMS {
        DWORD_PTR dwCallback;
        DWORD dwTimeFormat;
        DWORD dwAudio;
    } MCI_SET_PARMS, * PMCI_SET_PARMS, * LPMCI_SET_PARMS;

    typedef struct tagMCI_BREAK_PARMS {
        DWORD_PTR dwCallback;
        int nVirtKey;
        HWND hwndBreak;
    } MCI_BREAK_PARMS, * PMCI_BREAK_PARMS, * LPMCI_BREAK_PARMS;

    typedef struct tagMCI_SAVE_PARMSA {
        DWORD_PTR dwCallback;
        LPCSTR lpfilename;
    } MCI_SAVE_PARMSA, * PMCI_SAVE_PARMSA, * LPMCI_SAVE_PARMSA;

    typedef struct tagMCI_SAVE_PARMSW {
        DWORD_PTR dwCallback;
        LPCWSTR lpfilename;
    } MCI_SAVE_PARMSW, * PMCI_SAVE_PARMSW, * LPMCI_SAVE_PARMSW;

    __MINGW_TYPEDEF_AW(MCI_SAVE_PARMS)
        __MINGW_TYPEDEF_AW(PMCI_SAVE_PARMS)
        __MINGW_TYPEDEF_AW(LPMCI_SAVE_PARMS)

        typedef struct tagMCI_LOAD_PARMSA {
        DWORD_PTR dwCallback;
        LPCSTR lpfilename;
    } MCI_LOAD_PARMSA, * PMCI_LOAD_PARMSA, * LPMCI_LOAD_PARMSA;

    typedef struct tagMCI_LOAD_PARMSW {
        DWORD_PTR dwCallback;
        LPCWSTR lpfilename;
    } MCI_LOAD_PARMSW, * PMCI_LOAD_PARMSW, * LPMCI_LOAD_PARMSW;

    __MINGW_TYPEDEF_AW(MCI_LOAD_PARMS)
        __MINGW_TYPEDEF_AW(PMCI_LOAD_PARMS)
        __MINGW_TYPEDEF_AW(LPMCI_LOAD_PARMS)

        typedef struct tagMCI_RECORD_PARMS {
        DWORD_PTR dwCallback;
        DWORD dwFrom;
        DWORD dwTo;
    } MCI_RECORD_PARMS, * LPMCI_RECORD_PARMS;

#define MCI_VD_MODE_PARK (MCI_VD_OFFSET + 1)

#define MCI_VD_MEDIA_CLV (MCI_VD_OFFSET + 2)
#define MCI_VD_MEDIA_CAV (MCI_VD_OFFSET + 3)
#define MCI_VD_MEDIA_OTHER (MCI_VD_OFFSET + 4)

#define MCI_VD_FORMAT_TRACK 0x4001

#define MCI_VD_PLAY_REVERSE __MSABI_LONG(0x00010000)
#define MCI_VD_PLAY_FAST __MSABI_LONG(0x00020000)
#define MCI_VD_PLAY_SPEED __MSABI_LONG(0x00040000)
#define MCI_VD_PLAY_SCAN __MSABI_LONG(0x00080000)
#define MCI_VD_PLAY_SLOW __MSABI_LONG(0x00100000)

#define MCI_VD_SEEK_REVERSE __MSABI_LONG(0x00010000)

#define MCI_VD_STATUS_SPEED __MSABI_LONG(0x00004002)
#define MCI_VD_STATUS_FORWARD __MSABI_LONG(0x00004003)
#define MCI_VD_STATUS_MEDIA_TYPE __MSABI_LONG(0x00004004)
#define MCI_VD_STATUS_SIDE __MSABI_LONG(0x00004005)
#define MCI_VD_STATUS_DISC_SIZE __MSABI_LONG(0x00004006)

#define MCI_VD_GETDEVCAPS_CLV __MSABI_LONG(0x00010000)
#define MCI_VD_GETDEVCAPS_CAV __MSABI_LONG(0x00020000)

#define MCI_VD_SPIN_UP __MSABI_LONG(0x00010000)
#define MCI_VD_SPIN_DOWN __MSABI_LONG(0x00020000)

#define MCI_VD_GETDEVCAPS_CAN_REVERSE __MSABI_LONG(0x00004002)
#define MCI_VD_GETDEVCAPS_FAST_RATE __MSABI_LONG(0x00004003)
#define MCI_VD_GETDEVCAPS_SLOW_RATE __MSABI_LONG(0x00004004)
#define MCI_VD_GETDEVCAPS_NORMAL_RATE __MSABI_LONG(0x00004005)

#define MCI_VD_STEP_FRAMES __MSABI_LONG(0x00010000)
#define MCI_VD_STEP_REVERSE __MSABI_LONG(0x00020000)

#define MCI_VD_ESCAPE_STRING __MSABI_LONG(0x00000100)

    typedef struct tagMCI_VD_PLAY_PARMS {
        DWORD_PTR dwCallback;
        DWORD dwFrom;
        DWORD dwTo;
        DWORD dwSpeed;
    } MCI_VD_PLAY_PARMS, * PMCI_VD_PLAY_PARMS, * LPMCI_VD_PLAY_PARMS;

    typedef struct tagMCI_VD_STEP_PARMS {
        DWORD_PTR dwCallback;
        DWORD dwFrames;
    } MCI_VD_STEP_PARMS, * PMCI_VD_STEP_PARMS, * LPMCI_VD_STEP_PARMS;

    typedef struct tagMCI_VD_ESCAPE_PARMSA {
        DWORD_PTR dwCallback;
        LPCSTR lpstrCommand;
    } MCI_VD_ESCAPE_PARMSA, * PMCI_VD_ESCAPE_PARMSA, * LPMCI_VD_ESCAPE_PARMSA;

    typedef struct tagMCI_VD_ESCAPE_PARMSW {
        DWORD_PTR dwCallback;
        LPCWSTR lpstrCommand;
    } MCI_VD_ESCAPE_PARMSW, * PMCI_VD_ESCAPE_PARMSW, * LPMCI_VD_ESCAPE_PARMSW;

    __MINGW_TYPEDEF_AW(MCI_VD_ESCAPE_PARMS)
        __MINGW_TYPEDEF_AW(PMCI_VD_ESCAPE_PARMS)
        __MINGW_TYPEDEF_AW(LPMCI_VD_ESCAPE_PARMS)

#define MCI_CDA_STATUS_TYPE_TRACK __MSABI_LONG(0x00004001)
#define MCI_CDA_TRACK_AUDIO (MCI_CD_OFFSET + 0)
#define MCI_CDA_TRACK_OTHER (MCI_CD_OFFSET + 1)

#define MCI_WAVE_PCM (MCI_WAVE_OFFSET + 0)
#define MCI_WAVE_MAPPER (MCI_WAVE_OFFSET + 1)

#define MCI_WAVE_OPEN_BUFFER __MSABI_LONG(0x00010000)

#define MCI_WAVE_SET_FORMATTAG __MSABI_LONG(0x00010000)
#define MCI_WAVE_SET_CHANNELS __MSABI_LONG(0x00020000)
#define MCI_WAVE_SET_SAMPLESPERSEC __MSABI_LONG(0x00040000)
#define MCI_WAVE_SET_AVGBYTESPERSEC __MSABI_LONG(0x00080000)
#define MCI_WAVE_SET_BLOCKALIGN __MSABI_LONG(0x00100000)
#define MCI_WAVE_SET_BITSPERSAMPLE __MSABI_LONG(0x00200000)

#define MCI_WAVE_INPUT __MSABI_LONG(0x00400000)
#define MCI_WAVE_OUTPUT __MSABI_LONG(0x00800000)

#define MCI_WAVE_STATUS_FORMATTAG __MSABI_LONG(0x00004001)
#define MCI_WAVE_STATUS_CHANNELS __MSABI_LONG(0x00004002)
#define MCI_WAVE_STATUS_SAMPLESPERSEC __MSABI_LONG(0x00004003)
#define MCI_WAVE_STATUS_AVGBYTESPERSEC __MSABI_LONG(0x00004004)
#define MCI_WAVE_STATUS_BLOCKALIGN __MSABI_LONG(0x00004005)
#define MCI_WAVE_STATUS_BITSPERSAMPLE __MSABI_LONG(0x00004006)
#define MCI_WAVE_STATUS_LEVEL __MSABI_LONG(0x00004007)

#define MCI_WAVE_SET_ANYINPUT __MSABI_LONG(0x04000000)
#define MCI_WAVE_SET_ANYOUTPUT __MSABI_LONG(0x08000000)

#define MCI_WAVE_GETDEVCAPS_INPUTS __MSABI_LONG(0x00004001)
#define MCI_WAVE_GETDEVCAPS_OUTPUTS __MSABI_LONG(0x00004002)

        typedef struct tagMCI_WAVE_OPEN_PARMSA {
        DWORD_PTR dwCallback;
        MCIDEVICEID wDeviceID;
        LPCSTR lpstrDeviceType;
        LPCSTR lpstrElementName;
        LPCSTR lpstrAlias;
        DWORD dwBufferSeconds;
    } MCI_WAVE_OPEN_PARMSA, * PMCI_WAVE_OPEN_PARMSA, * LPMCI_WAVE_OPEN_PARMSA;

    typedef struct tagMCI_WAVE_OPEN_PARMSW {
        DWORD_PTR dwCallback;
        MCIDEVICEID wDeviceID;
        LPCWSTR lpstrDeviceType;
        LPCWSTR lpstrElementName;
        LPCWSTR lpstrAlias;
        DWORD dwBufferSeconds;
    } MCI_WAVE_OPEN_PARMSW, * PMCI_WAVE_OPEN_PARMSW, * LPMCI_WAVE_OPEN_PARMSW;

    __MINGW_TYPEDEF_AW(MCI_WAVE_OPEN_PARMS)
        __MINGW_TYPEDEF_AW(PMCI_WAVE_OPEN_PARMS)
        __MINGW_TYPEDEF_AW(LPMCI_WAVE_OPEN_PARMS)

        typedef struct tagMCI_WAVE_DELETE_PARMS {
        DWORD_PTR dwCallback;
        DWORD dwFrom;
        DWORD dwTo;
    } MCI_WAVE_DELETE_PARMS, * PMCI_WAVE_DELETE_PARMS, * LPMCI_WAVE_DELETE_PARMS;

    typedef struct tagMCI_WAVE_SET_PARMS {
        DWORD_PTR dwCallback;
        DWORD dwTimeFormat;
        DWORD dwAudio;
        UINT wInput;
        UINT wOutput;
        WORD wFormatTag;
        WORD wReserved2;
        WORD nChannels;
        WORD wReserved3;
        DWORD nSamplesPerSec;
        DWORD nAvgBytesPerSec;
        WORD nBlockAlign;
        WORD wReserved4;
        WORD wBitsPerSample;
        WORD wReserved5;
    } MCI_WAVE_SET_PARMS, * PMCI_WAVE_SET_PARMS, * LPMCI_WAVE_SET_PARMS;

#define MCI_SEQ_DIV_PPQN (0 + MCI_SEQ_OFFSET)
#define MCI_SEQ_DIV_SMPTE_24 (1 + MCI_SEQ_OFFSET)
#define MCI_SEQ_DIV_SMPTE_25 (2 + MCI_SEQ_OFFSET)
#define MCI_SEQ_DIV_SMPTE_30DROP (3 + MCI_SEQ_OFFSET)
#define MCI_SEQ_DIV_SMPTE_30 (4 + MCI_SEQ_OFFSET)

#define MCI_SEQ_FORMAT_SONGPTR 0x4001
#define MCI_SEQ_FILE 0x4002
#define MCI_SEQ_MIDI 0x4003
#define MCI_SEQ_SMPTE 0x4004
#define MCI_SEQ_NONE 65533
#define MCI_SEQ_MAPPER 65535

#define MCI_SEQ_STATUS_TEMPO __MSABI_LONG(0x00004002)
#define MCI_SEQ_STATUS_PORT __MSABI_LONG(0x00004003)
#define MCI_SEQ_STATUS_SLAVE __MSABI_LONG(0x00004007)
#define MCI_SEQ_STATUS_MASTER __MSABI_LONG(0x00004008)
#define MCI_SEQ_STATUS_OFFSET __MSABI_LONG(0x00004009)
#define MCI_SEQ_STATUS_DIVTYPE __MSABI_LONG(0x0000400A)
#define MCI_SEQ_STATUS_NAME __MSABI_LONG(0x0000400B)
#define MCI_SEQ_STATUS_COPYRIGHT __MSABI_LONG(0x0000400C)

#define MCI_SEQ_SET_TEMPO __MSABI_LONG(0x00010000)
#define MCI_SEQ_SET_PORT __MSABI_LONG(0x00020000)
#define MCI_SEQ_SET_SLAVE __MSABI_LONG(0x00040000)
#define MCI_SEQ_SET_MASTER __MSABI_LONG(0x00080000)
#define MCI_SEQ_SET_OFFSET __MSABI_LONG(0x01000000)

    typedef struct tagMCI_SEQ_SET_PARMS {
        DWORD_PTR dwCallback;
        DWORD dwTimeFormat;
        DWORD dwAudio;
        DWORD dwTempo;
        DWORD dwPort;
        DWORD dwSlave;
        DWORD dwMaster;
        DWORD dwOffset;
    } MCI_SEQ_SET_PARMS, * PMCI_SEQ_SET_PARMS, * LPMCI_SEQ_SET_PARMS;

#define MCI_ANIM_OPEN_WS __MSABI_LONG(0x00010000)
#define MCI_ANIM_OPEN_PARENT __MSABI_LONG(0x00020000)
#define MCI_ANIM_OPEN_NOSTATIC __MSABI_LONG(0x00040000)

#define MCI_ANIM_PLAY_SPEED __MSABI_LONG(0x00010000)
#define MCI_ANIM_PLAY_REVERSE __MSABI_LONG(0x00020000)
#define MCI_ANIM_PLAY_FAST __MSABI_LONG(0x00040000)
#define MCI_ANIM_PLAY_SLOW __MSABI_LONG(0x00080000)
#define MCI_ANIM_PLAY_SCAN __MSABI_LONG(0x00100000)

#define MCI_ANIM_STEP_REVERSE __MSABI_LONG(0x00010000)
#define MCI_ANIM_STEP_FRAMES __MSABI_LONG(0x00020000)

#define MCI_ANIM_STATUS_SPEED __MSABI_LONG(0x00004001)
#define MCI_ANIM_STATUS_FORWARD __MSABI_LONG(0x00004002)
#define MCI_ANIM_STATUS_HWND __MSABI_LONG(0x00004003)
#define MCI_ANIM_STATUS_HPAL __MSABI_LONG(0x00004004)
#define MCI_ANIM_STATUS_STRETCH __MSABI_LONG(0x00004005)

#define MCI_ANIM_INFO_TEXT __MSABI_LONG(0x00010000)

#define MCI_ANIM_GETDEVCAPS_CAN_REVERSE __MSABI_LONG(0x00004001)
#define MCI_ANIM_GETDEVCAPS_FAST_RATE __MSABI_LONG(0x00004002)
#define MCI_ANIM_GETDEVCAPS_SLOW_RATE __MSABI_LONG(0x00004003)
#define MCI_ANIM_GETDEVCAPS_NORMAL_RATE __MSABI_LONG(0x00004004)
#define MCI_ANIM_GETDEVCAPS_PALETTES __MSABI_LONG(0x00004006)
#define MCI_ANIM_GETDEVCAPS_CAN_STRETCH __MSABI_LONG(0x00004007)
#define MCI_ANIM_GETDEVCAPS_MAX_WINDOWS __MSABI_LONG(0x00004008)

#define MCI_ANIM_REALIZE_NORM __MSABI_LONG(0x00010000)
#define MCI_ANIM_REALIZE_BKGD __MSABI_LONG(0x00020000)

#define MCI_ANIM_WINDOW_HWND __MSABI_LONG(0x00010000)
#define MCI_ANIM_WINDOW_STATE __MSABI_LONG(0x00040000)
#define MCI_ANIM_WINDOW_TEXT __MSABI_LONG(0x00080000)
#define MCI_ANIM_WINDOW_ENABLE_STRETCH __MSABI_LONG(0x00100000)
#define MCI_ANIM_WINDOW_DISABLE_STRETCH __MSABI_LONG(0x00200000)

#define MCI_ANIM_WINDOW_DEFAULT __MSABI_LONG(0x00000000)

#define MCI_ANIM_RECT __MSABI_LONG(0x00010000)
#define MCI_ANIM_PUT_SOURCE __MSABI_LONG(0x00020000)
#define MCI_ANIM_PUT_DESTINATION __MSABI_LONG(0x00040000)

#define MCI_ANIM_WHERE_SOURCE __MSABI_LONG(0x00020000)
#define MCI_ANIM_WHERE_DESTINATION __MSABI_LONG(0x00040000)

#define MCI_ANIM_UPDATE_HDC __MSABI_LONG(0x00020000)

    typedef struct tagMCI_ANIM_OPEN_PARMSA {
        DWORD_PTR dwCallback;
        MCIDEVICEID wDeviceID;
        LPCSTR lpstrDeviceType;
        LPCSTR lpstrElementName;
        LPCSTR lpstrAlias;
        DWORD dwStyle;
        HWND hWndParent;
    } MCI_ANIM_OPEN_PARMSA, * PMCI_ANIM_OPEN_PARMSA, * LPMCI_ANIM_OPEN_PARMSA;

    typedef struct tagMCI_ANIM_OPEN_PARMSW {
        DWORD_PTR dwCallback;
        MCIDEVICEID wDeviceID;
        LPCWSTR lpstrDeviceType;
        LPCWSTR lpstrElementName;
        LPCWSTR lpstrAlias;
        DWORD dwStyle;
        HWND hWndParent;
    } MCI_ANIM_OPEN_PARMSW, * PMCI_ANIM_OPEN_PARMSW, * LPMCI_ANIM_OPEN_PARMSW;

    __MINGW_TYPEDEF_AW(MCI_ANIM_OPEN_PARMS)
        __MINGW_TYPEDEF_AW(PMCI_ANIM_OPEN_PARMS)
        __MINGW_TYPEDEF_AW(LPMCI_ANIM_OPEN_PARMS)

        typedef struct tagMCI_ANIM_PLAY_PARMS {
        DWORD_PTR dwCallback;
        DWORD dwFrom;
        DWORD dwTo;
        DWORD dwSpeed;
    } MCI_ANIM_PLAY_PARMS, * PMCI_ANIM_PLAY_PARMS, * LPMCI_ANIM_PLAY_PARMS;

    typedef struct tagMCI_ANIM_STEP_PARMS {
        DWORD_PTR dwCallback;
        DWORD dwFrames;
    } MCI_ANIM_STEP_PARMS, * PMCI_ANIM_STEP_PARMS, * LPMCI_ANIM_STEP_PARMS;

    typedef struct tagMCI_ANIM_WINDOW_PARMSA {
        DWORD_PTR dwCallback;
        HWND hWnd;
        UINT nCmdShow;
        LPCSTR lpstrText;
    } MCI_ANIM_WINDOW_PARMSA, * PMCI_ANIM_WINDOW_PARMSA, * LPMCI_ANIM_WINDOW_PARMSA;

    typedef struct tagMCI_ANIM_WINDOW_PARMSW {
        DWORD_PTR dwCallback;
        HWND hWnd;
        UINT nCmdShow;
        LPCWSTR lpstrText;
    } MCI_ANIM_WINDOW_PARMSW, * PMCI_ANIM_WINDOW_PARMSW, * LPMCI_ANIM_WINDOW_PARMSW;

    __MINGW_TYPEDEF_AW(MCI_ANIM_WINDOW_PARMS)
        __MINGW_TYPEDEF_AW(PMCI_ANIM_WINDOW_PARMS)
        __MINGW_TYPEDEF_AW(LPMCI_ANIM_WINDOW_PARMS)

        typedef struct tagMCI_ANIM_RECT_PARMS {
        DWORD_PTR dwCallback;
#ifdef MCI_USE_OFFEXT
        POINT ptOffset;
        POINT ptExtent;
#else
        RECT rc;
#endif
    } MCI_ANIM_RECT_PARMS;

    typedef MCI_ANIM_RECT_PARMS* PMCI_ANIM_RECT_PARMS;
    typedef MCI_ANIM_RECT_PARMS* LPMCI_ANIM_RECT_PARMS;

    typedef struct tagMCI_ANIM_UPDATE_PARMS {
        DWORD_PTR dwCallback;
        RECT rc;
        HDC hDC;
    } MCI_ANIM_UPDATE_PARMS, * PMCI_ANIM_UPDATE_PARMS, * LPMCI_ANIM_UPDATE_PARMS;

#define MCI_OVLY_OPEN_WS __MSABI_LONG(0x00010000)
#define MCI_OVLY_OPEN_PARENT __MSABI_LONG(0x00020000)

#define MCI_OVLY_STATUS_HWND __MSABI_LONG(0x00004001)
#define MCI_OVLY_STATUS_STRETCH __MSABI_LONG(0x00004002)

#define MCI_OVLY_INFO_TEXT __MSABI_LONG(0x00010000)

#define MCI_OVLY_GETDEVCAPS_CAN_STRETCH __MSABI_LONG(0x00004001)
#define MCI_OVLY_GETDEVCAPS_CAN_FREEZE __MSABI_LONG(0x00004002)
#define MCI_OVLY_GETDEVCAPS_MAX_WINDOWS __MSABI_LONG(0x00004003)

#define MCI_OVLY_WINDOW_HWND __MSABI_LONG(0x00010000)
#define MCI_OVLY_WINDOW_STATE __MSABI_LONG(0x00040000)
#define MCI_OVLY_WINDOW_TEXT __MSABI_LONG(0x00080000)
#define MCI_OVLY_WINDOW_ENABLE_STRETCH __MSABI_LONG(0x00100000)
#define MCI_OVLY_WINDOW_DISABLE_STRETCH __MSABI_LONG(0x00200000)

#define MCI_OVLY_WINDOW_DEFAULT __MSABI_LONG(0x00000000)

#define MCI_OVLY_RECT __MSABI_LONG(0x00010000)
#define MCI_OVLY_PUT_SOURCE __MSABI_LONG(0x00020000)
#define MCI_OVLY_PUT_DESTINATION __MSABI_LONG(0x00040000)
#define MCI_OVLY_PUT_FRAME __MSABI_LONG(0x00080000)
#define MCI_OVLY_PUT_VIDEO __MSABI_LONG(0x00100000)

#define MCI_OVLY_WHERE_SOURCE __MSABI_LONG(0x00020000)
#define MCI_OVLY_WHERE_DESTINATION __MSABI_LONG(0x00040000)
#define MCI_OVLY_WHERE_FRAME __MSABI_LONG(0x00080000)
#define MCI_OVLY_WHERE_VIDEO __MSABI_LONG(0x00100000)

    typedef struct tagMCI_OVLY_OPEN_PARMSA {
        DWORD_PTR dwCallback;
        MCIDEVICEID wDeviceID;
        LPCSTR lpstrDeviceType;
        LPCSTR lpstrElementName;
        LPCSTR lpstrAlias;
        DWORD dwStyle;
        HWND hWndParent;
    } MCI_OVLY_OPEN_PARMSA, * PMCI_OVLY_OPEN_PARMSA, * LPMCI_OVLY_OPEN_PARMSA;

    typedef struct tagMCI_OVLY_OPEN_PARMSW {
        DWORD_PTR dwCallback;
        MCIDEVICEID wDeviceID;
        LPCWSTR lpstrDeviceType;
        LPCWSTR lpstrElementName;
        LPCWSTR lpstrAlias;
        DWORD dwStyle;
        HWND hWndParent;
    } MCI_OVLY_OPEN_PARMSW, * PMCI_OVLY_OPEN_PARMSW, * LPMCI_OVLY_OPEN_PARMSW;

    __MINGW_TYPEDEF_AW(MCI_OVLY_OPEN_PARMS)
        __MINGW_TYPEDEF_AW(PMCI_OVLY_OPEN_PARMS)
        __MINGW_TYPEDEF_AW(LPMCI_OVLY_OPEN_PARMS)

        typedef struct tagMCI_OVLY_WINDOW_PARMSA {
        DWORD_PTR dwCallback;
        HWND hWnd;
        UINT nCmdShow;
        LPCSTR lpstrText;
    } MCI_OVLY_WINDOW_PARMSA, * PMCI_OVLY_WINDOW_PARMSA, * LPMCI_OVLY_WINDOW_PARMSA;

    typedef struct tagMCI_OVLY_WINDOW_PARMSW {
        DWORD_PTR dwCallback;
        HWND hWnd;
        UINT nCmdShow;
        LPCWSTR lpstrText;
    } MCI_OVLY_WINDOW_PARMSW, * PMCI_OVLY_WINDOW_PARMSW, * LPMCI_OVLY_WINDOW_PARMSW;

    __MINGW_TYPEDEF_AW(MCI_OVLY_WINDOW_PARMS)
        __MINGW_TYPEDEF_AW(PMCI_OVLY_WINDOW_PARMS)
        __MINGW_TYPEDEF_AW(LPMCI_OVLY_WINDOW_PARMS)

        typedef struct tagMCI_OVLY_RECT_PARMS {
        DWORD_PTR dwCallback;
#ifdef MCI_USE_OFFEXT
        POINT ptOffset;
        POINT ptExtent;
#else
        RECT rc;
#endif
    } MCI_OVLY_RECT_PARMS, * PMCI_OVLY_RECT_PARMS, * LPMCI_OVLY_RECT_PARMS;

    typedef struct tagMCI_OVLY_SAVE_PARMSA {
        DWORD_PTR dwCallback;
        LPCSTR lpfilename;
        RECT rc;
    } MCI_OVLY_SAVE_PARMSA, * PMCI_OVLY_SAVE_PARMSA, * LPMCI_OVLY_SAVE_PARMSA;

    typedef struct tagMCI_OVLY_SAVE_PARMSW {
        DWORD_PTR dwCallback;
        LPCWSTR lpfilename;
        RECT rc;
    } MCI_OVLY_SAVE_PARMSW, * PMCI_OVLY_SAVE_PARMSW, * LPMCI_OVLY_SAVE_PARMSW;

    __MINGW_TYPEDEF_AW(MCI_OVLY_SAVE_PARMS)
        __MINGW_TYPEDEF_AW(PMCI_OVLY_SAVE_PARMS)
        __MINGW_TYPEDEF_AW(LPMCI_OVLY_SAVE_PARMS)

        typedef struct tagMCI_OVLY_LOAD_PARMSA {
        DWORD_PTR dwCallback;
        LPCSTR lpfilename;
        RECT rc;
    } MCI_OVLY_LOAD_PARMSA, * PMCI_OVLY_LOAD_PARMSA, * LPMCI_OVLY_LOAD_PARMSA;

    typedef struct tagMCI_OVLY_LOAD_PARMSW {
        DWORD_PTR dwCallback;
        LPCWSTR lpfilename;
        RECT rc;
    } MCI_OVLY_LOAD_PARMSW, * PMCI_OVLY_LOAD_PARMSW, * LPMCI_OVLY_LOAD_PARMSW;

    __MINGW_TYPEDEF_AW(MCI_OVLY_LOAD_PARMS)
        __MINGW_TYPEDEF_AW(PMCI_OVLY_LOAD_PARMS)
        __MINGW_TYPEDEF_AW(LPMCI_OVLY_LOAD_PARMS)
#endif

#ifndef NEWTRANSPARENT
#define NEWTRANSPARENT 3
#define QUERYROPSUPPORT 40
#endif

#define SELECTDIB 41
#define DIBINDEX(n) MAKELONG((n),0x10FF)

#ifndef SC_SCREENSAVE
#define SC_SCREENSAVE 0xF140
#endif

#ifdef __cplusplus
}
#endif

#include <poppack.h>
#endif