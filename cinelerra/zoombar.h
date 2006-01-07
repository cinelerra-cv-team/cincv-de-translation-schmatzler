#ifndef ZOOMBAR_H
#define ZOOMBAR_H

class ZoomTextBox;

class FromTextBox;
class LengthTextBox;
class ToTextBox;


class SampleZoomPanel;
class AmpZoomPanel;
class TrackZoomPanel;
class AutoZoom;


#include "guicast.h"
#include "mwindow.inc"
#include "mwindowgui.inc"
#include "zoompanel.h"

class ZoomBar : public BC_SubWindow
{
public:
	ZoomBar(MWindow *mwindow, MWindowGUI *gui);
	~ZoomBar();

	int create_objects();
	void resize_event();
	int draw();
	int resize_event(int w, int h);
	void redraw_time_dependancies();
	int update();          // redraw the current values
	void update_autozoom();
	int update_clocks();
	int update_playback(int64_t new_position);       // update the playback position
	int set_selection(int which_one);
	void update_formatting(BC_TextBox *dst);

	MWindow *mwindow;
	MWindowGUI *gui;
	SampleZoomPanel *sample_zoom;
	AmpZoomPanel *amp_zoom;
	TrackZoomPanel *track_zoom;
	AutoZoom *auto_zoom;
	ZoomTextBox *auto_zoom_text;

	BC_Title *zoom_value, *playback_value;
	LengthTextBox *length_value;
	FromTextBox *from_value;
	ToTextBox *to_value;
	char string[256], string2[256];
	int64_t old_position;
};

class SampleZoomPanel : public ZoomPanel
{
public:
	SampleZoomPanel(MWindow *mwindow, ZoomBar *zoombar, int x, int y);
	int handle_event();
	MWindow *mwindow;
	ZoomBar *zoombar;
};

class AmpZoomPanel : public ZoomPanel
{
public:
	AmpZoomPanel(MWindow *mwindow, ZoomBar *zoombar, int x, int y);
	int handle_event();
	MWindow *mwindow;
	ZoomBar *zoombar;
};

class TrackZoomPanel : public ZoomPanel
{
public:
	TrackZoomPanel(MWindow *mwindow, ZoomBar *zoombar, int x, int y);
	int handle_event();
	MWindow *mwindow;
	ZoomBar *zoombar;
};

class AutoZoom : public BC_Tumbler
{
public:
	AutoZoom(MWindow *mwindow, ZoomBar *zoombar, int x, int y);
	int handle_up_event();
	int handle_down_event();
	MWindow *mwindow;
	ZoomBar *zoombar;
};






class ZoomTextBox : public BC_TextBox
{
public:
	ZoomTextBox(MWindow *mwindow, ZoomBar *zoombar, int x, int y, char *text);
	int handle_event();
	MWindow *mwindow;
	ZoomBar *zoombar;
};



class FromTextBox : public BC_TextBox
{
public:
	FromTextBox(MWindow *mwindow, ZoomBar *zoombar, int x, int y);
	int handle_event();
	int update_position(double new_position);
	char string[256], string2[256];
	MWindow *mwindow;
	ZoomBar *zoombar;
};


class LengthTextBox : public BC_TextBox
{
public:
	LengthTextBox(MWindow *mwindow, ZoomBar *zoombar, int x, int y);
	int handle_event();
	int update_position(double new_position);
	char string[256], string2[256];
	MWindow *mwindow;
	ZoomBar *zoombar;
};

class ToTextBox : public BC_TextBox
{
public:
	ToTextBox(MWindow *mwindow, ZoomBar *zoombar, int x, int y);
	int handle_event();
	int update_position(double new_position);
	char string[256], string2[256];
	MWindow *mwindow;
	ZoomBar *zoombar;
};




#endif
