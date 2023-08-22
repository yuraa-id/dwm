/* See LICENSE file for copyright and license details. */

#define SESSION_FILE "/tmp/dwm-session"

/* appearance */
static const unsigned int borderpx  	= 2;  /* border pixel of windows */
static const unsigned int colorfultitle = 1;  /* 0 means title use SchemeTitle and SchemeTitleFloat */
static const unsigned int colorfultag   = 1;  /* 0 means use SchemeSel for selected tag */
static const unsigned int snap      	= 32; /* snap pixel */
static const unsigned int gappih    	= 8;  /* horiz inner gap between windows */
static const unsigned int gappiv   		= 8;  /* vert inner gap between windows */
static const unsigned int gappoh    	= 10; /* horiz outer gap between windows and screen edge */
static const unsigned int gappov    	= 10; /* vert outer gap between windows and screen edge */
static const unsigned int stairpx   	= 60; /* depth of the stairs layout */
static       int smartgaps          	= 0;  /* 1 means no outer gap when there is only one window */
static const int showbar            	= 1;  /* 0 means no bar */
static const int topbar             	= 1;  /* 0 means bottom bar */
static const int stairdirection     	= 1;  /* 0: left-aligned, 1: right-aligned */
static const int stairsamesize      	= 1;  /* 1 means shrink all the staired windows to the same size */
static const int scalepreview       	= 4;  /* preview scaling (display w and h / scalepreview) */
static const int previewbar         	= 1;  /* show the bar in the preview window */
static const int horizpadbar        	= 5;  /* horizontal padding for statusbar */
static const int vertpadbar         	= 10;  /* vertical padding for statusbar */
static const int vertpad            = 5;       /* vertical padding of bar */
static const int sidepad            = 5;       /* horizontal padding of bar */
static const char *fonts[]          	= { "JetBrainsMono Nerd Font:size=10", "fontello:size=30", "icomoon:size=11", "NotoColorEmoji:pixelsize=15:antialias=true:autohint=true"};
static const char dmenufont[]       	= "JetBrainsMono Nerd Font:size=10";
/*static const char col_gray1[]       	= "#1b2b34";*/
static const char col_gray1[]       	= "#222222";
static const char col_gray2[]       	= "#444444";
static const char col_gray3[]       	= "#bbbbbb";
static const char col_gray4[]       	= "#eeeeee";
/*static const char col_cyan[]        	= "#005577";*/
static const char col_cyan[]        	= "#3b5469";
static const char col_white[]        	= "#d8dee9";
static const char col_green[]					= "#99c794";
static const char col_yellow[]				= "#e6c547";
static const char col_red[]						= "#ec5f67";
static const char col_blue[]					= "#6699cc";
static const char col_gray[]					= "#3a5165";
static const char *colors[][3]      	= {
	/*               fg         bg         border   */
	[SchemeNorm] 	   	 = { col_white, 			col_gray1, 		col_cyan },
	[SchemeSel]  	     = { col_white, 			col_gray1,  	col_cyan },

	[SchemeTag]        = { col_gray,    		col_gray1,  	col_cyan },
  [SchemeTag1]       = { col_yellow,   		col_gray1,  	col_cyan },
	[SchemeTag2]       = { col_red,       	col_gray1,  	col_cyan },
  [SchemeTag3]       = { col_green,   		col_gray1,  	col_cyan },
  [SchemeTag4]       = { col_yellow,    	col_gray1,  	col_cyan },
  [SchemeTag5]       = { col_red,  				col_gray1,  	col_cyan },
	[SchemeTag6]       = { col_green,     	col_gray1,  	col_cyan },
	[SchemeLayout]     = { col_gray4,       col_gray1,  	col_cyan },

	[SchemeTitle]      = { col_gray3,       col_gray1, 		col_cyan },
	[SchemeTitleFloat] = { col_blue,     		col_gray1,    col_cyan },
	[SchemeTitle1]     = { col_yellow,      col_gray1,    col_cyan },
	[SchemeTitle2]     = { col_red,         col_gray1,    col_cyan },
  [SchemeTitle3]     = { col_green,   		col_gray1,    col_cyan },
  [SchemeTitle4]     = { col_yellow,     	col_gray1,    col_cyan },
  [SchemeTitle5]     = { col_red,  				col_gray1,    col_cyan },
	[SchemeTitle6]     = { col_green,     	col_gray1,    col_cyan },

};

/* tagging */
static const char *tags[] 		= { "", "○","●","○","●","󰊠" };
static const char *alttags[] 	= { "", "●","●","●","●","󰊠" };

static const int tagschemes[] 	= { SchemeTag1, SchemeTag2, SchemeTag3,
                                  SchemeTag4, SchemeTag5, SchemeTag6 };
static const int titleschemes[] = { SchemeTitle1, SchemeTitle2, SchemeTitle3,
                                    SchemeTitle4, SchemeTitle5, SchemeTitle6 };


static const unsigned int ulinepad			= 5;	/* horizontal padding between the underline and tag */
static const unsigned int ulinestroke		= 2;	/* thickness / height of the underline */
static const unsigned int ulinevoffset	= 0;	/* how far above the bottom of the bar the line should appear */
static const int ulineall 							= 0;	/* 1 to show underline on all tags, 0 for just the active ones */

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     iscentered   isfloating   monitor */
	{ "Gimp",     NULL,       NULL,       0,            0,           1,           -1 },
	{ "Firefox",  NULL,       NULL,       1 << 8,       0,           0,           -1 },
	{ "st",       NULL,       NULL,       0,            1,           1,           -1 },
};

/* layout(s) */
static const float mfact     	= 0.45; /* factor of master area size [0.05..0.95] */
static const int nmaster    	= 1;    /* number of clients in master area */
static const int resizehints 	= 1;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

#define FORCE_VSPLIT 1  /* nrowgrid layout: force two clients to always split vertically */
#include "vanitygaps.c"
#include "tatami.c"
static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "[@]",      spiral },
	{ "[\\]",     dwindle },
	{ "|+|",      tatami },
	{ "[S]",      stairs },
	{ "TTT",      bstack },
	{ "===",      bstackhoriz },
	{ "HHH",      grid },
	{ "###",      nrowgrid },
	{ "---",      horizgrid },
	{ ":::",      gaplessgrid },
	{ "|M|",      centeredmaster },
/*	{ "H[]",      deck },*/
/*	{ ">M>",      centeredfloatingmaster },
/*	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ NULL,       NULL },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      previewtag,     {.ui = TAG } },     \

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

#define STATUSBAR "dwmblocks"

/* commands */
static 		 char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_cyan, "-sf", col_gray4, NULL };
static const char *termcmd[]  = { "xterm", NULL };
static const char *term2cmd[] = { "st", NULL };
static const char *flamecmd[] = { "flameshot-imgck" , NULL};
static const char *web[]  	  = { "firefox", NULL };
static const char *filemngr[] = { "thunar", NULL };
static const char *dmenupwr[] = { "dmenu_power", NULL };
static const char *dmenubt[]  = { "dmenu_bluetooth", NULL };
static const char *dmenunm[]  = { "networkmanager_dmenu", NULL };

#include <X11/XF86keysym.h>
#include "movestack.c"
static const Key keys[] = {

/*===================================================================================================*/	

	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_n,      		spawn,          {.v = filemngr } },
  { MODKEY,                       XK_w,      		spawn,          {.v = web } },
	{ MODKEY,                       XK_Print,  		spawn,          {.v = flamecmd } },
  { MODKEY|ShiftMask,             XK_grave,  		spawn,          {.v = dmenubt } },	
	{ MODKEY,                       XK_grave,  		spawn,          {.v = dmenupwr } },
	{ MODKEY,                       XK_p,      		spawn,          {.v = dmenucmd } },
	{ MODKEY|ShiftMask,             XK_p,      		spawn,          {.v = dmenunm } },
	{ MODKEY,		                		XK_Return, 		spawn,          {.v = termcmd } },
	{ MODKEY|ShiftMask,		        	XK_Return, 		spawn,          {.v = term2cmd } },

/*===================================================================================================*/	

	{ MODKEY,                       XK_b,      		togglebar,      {0} },
	{ MODKEY,                       XK_j,      		focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      		focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,      		incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_o,      		incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      		setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      		setmfact,       {.f = +0.05} },
	{ MODKEY|ShiftMask,             XK_h,      		setcfact,       {.f = +0.25} },
	{ MODKEY|ShiftMask,             XK_l,      		setcfact,       {.f = -0.25} },
	{ MODKEY|ShiftMask,             XK_o,      		setcfact,       {.f =  0.00} },
	{ MODKEY|ShiftMask,            	XK_j,      		movestack,      {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_k,      		movestack,      {.i = -1 } },

/*===================================================================================================*/	

	/*{ MODKEY,                       XK_Return, zoom,           {0} },*/
	{ Mod1Mask,                     XK_z,      		incrgaps,       {.i = +1 } },
	{ Mod1Mask,                     XK_a,      		incrgaps,       {.i = -1 } },
	{ Mod1Mask,                     XK_x,      		incrigaps,      {.i = +1 } },
	{ Mod1Mask,                     XK_s,      		incrigaps,      {.i = -1 } },
	{ Mod1Mask,                     XK_c,      		incrogaps,      {.i = +1 } },
	{ Mod1Mask,                     XK_d,      		incrogaps,      {.i = -1 } },
	{ Mod1Mask,                     XK_v,      		incrihgaps,     {.i = +1 } },
	{ Mod1Mask,                     XK_f,      		incrihgaps,     {.i = -1 } },
	{ Mod1Mask,                     XK_b,      		incrivgaps,     {.i = +1 } },
	{ Mod1Mask,                     XK_g,      		incrivgaps,     {.i = -1 } },
	{ Mod1Mask,                     XK_n,      		incrohgaps,     {.i = +1 } },
	{ Mod1Mask,                     XK_h,      		incrohgaps,     {.i = -1 } },
	{ Mod1Mask,                     XK_m,      		incrovgaps,     {.i = +1 } },
	{ Mod1Mask,                     XK_j,      		incrovgaps,     {.i = -1 } },
	{ MODKEY|Mod1Mask,              XK_0,      		togglegaps,     {0} },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_0,      		defaultgaps,    {0} },

/*===================================================================================================*/	

	{ MODKEY,                       XK_Tab,   		view,           {0} },
	{ MODKEY,            		    		XK_q,      		killclient,     {0} },
	{ MODKEY|ShiftMask,             XK_r,      		quit,           {0} },
	{ MODKEY|ControlMask|ShiftMask, XK_q,      		quit,           {1} }, 

/*===================================================================================================*/	

	{ MODKEY,                       XK_t,      		setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,      		setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,      		setlayout,      {.v = &layouts[2]} },
	{ MODKEY|ControlMask,						XK_comma,  		cyclelayout,    {.i = -1 } },
	{ MODKEY|ControlMask,           XK_period, 		cyclelayout,    {.i = +1 } },
	{ MODKEY,                       XK_space,  		setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  		togglefloating, {0} },
	{ MODKEY,                       XK_0,      		view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      		tag,            {.ui = ~0 } },

/*===================================================================================================*/	

	{ MODKEY,                       XK_comma,  		focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, 		focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  		tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, 		tagmon,         {.i = +1 } },

/*===================================================================================================*/	

	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)

/*===================================================================================================*/

  { 0, XF86XK_AudioMute,		    	spawn,		SHCMD("~/.local/bin/scripts/notify/change-volume mute") },
  { 0, XF86XK_AudioRaiseVolume,		spawn,		SHCMD("~/.local/bin/scripts/notify/change-volume up") },
  { 0, XF86XK_AudioLowerVolume,		spawn,		SHCMD("~/.local/bin/scripts/notify/change-volume down") },
  { 0, XF86XK_MonBrightnessUp,		spawn,		SHCMD("~/.local/bin/scripts/notify/change-brightness up") },
  { 0, XF86XK_MonBrightnessDown,	spawn,		SHCMD("~/.local/bin/scripts/notify/change-brightness down") },

};

/*===================================================================================================*/

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button1,        sigstatusbar,   {.i = 1} },
	{ ClkStatusText,        0,              Button2,        sigstatusbar,   {.i = 2} },
	{ ClkStatusText,        0,              Button3,        sigstatusbar,   {.i = 3} },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

