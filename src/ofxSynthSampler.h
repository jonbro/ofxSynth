#pragma once

#include "ofxSynth.h"

class ofxSynthSample  {
	public:
	
		ofxSynthSample();
		
		double	position;
		short 	myChannels;
		int   	mySampleRate;
		long	length;
		void getLength();

		char* 	myData;
		
		// get/set for the Path property

		~ofxSynthSample()
		{
			delete myData;
			myChunkSize = NULL;
			mySubChunk1Size = NULL;
			myFormat = NULL;
			myChannels = NULL;
			mySampleRate = NULL;
			myByteRate = NULL;
			myBlockAlign = NULL;
			myBitsPerSample = NULL;
			myDataSize = NULL;
		}
		
		bool load(string fileName);

		// read a wav file into this class
		bool read();
				
		// return a printable summary of the wav file
		char *getSummary();
		void				setSampleRate(int rate);

	private:
		string 	myPath;
		int		sampleRate;
		int 	myChunkSize;
		int		mySubChunk1Size;
		short 	myFormat;
		int   	myByteRate;
		short 	myBlockAlign;
		short 	myBitsPerSample;
		int		myDataSize;
		double	speed;
	
};

class ofxSynthSampler : public ofxSynth {
	public:
		ofxSynthSampler()	{
			direction=1; inPoint=0.0;outPoint=1.0;playing=false;
			sampleLoaded=false; currentFrequency=1.0; loopType=0;
		};
		virtual string		getName() { return "ofxSynthSampler"; }

		void				loadFile(string file);
		
		void				trigger();
		void				setFrequencyMidiNote(float note);
		void				setFrequencySyncToLength(int length);
		void				setDirectionForward(){direction = 1;};
		void				setDirectionBackward(){direction = -1;};
		void				setLoopPoints(float i, float o);
		void				setLoopType(int _loopType); // 0 loop 1 one shot
	
		void				setSampleRate(int rate);
		virtual void		audioRequested( float* buffer, int numFrames, int numChannels );
		double				play4(double frequency, double start, double end);
		void				play(float frequency, float start, float end, float &fill);

	private:
		int					sampleRate, direction, loopType;
		float				inPoint, outPoint, inSample, outSample;
		ofxSynthSample		sample;
		bool				sampleLoaded, playing;
		float				output; // used by the playback system

};