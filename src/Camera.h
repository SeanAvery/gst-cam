#include <gst/gst.h>
#include <gst/app/gstappsink.h>
#include <iostream>
#include <string>
#include "RingBuffer.cpp"

class Camera {
	public:
		GstElement* launch;
		GstBus* bus;
		GstAppSink* sink;
		int frameCount;
		void init();
		bool open();
		bool capture();
		RingBuffer memory;
	private:
		static void onEOS(_GstAppSink* sink, void* user_data);
		static GstFlowReturn onPreroll(_GstAppSink* sink, void* user_data);
		static GstFlowReturn onBuffer(_GstAppSink* sink, void* user_data);
		void checkBuffer(_GstAppSink* msink);
		void checkMsgBus();
};
