// speedie's Dynamic Window Manager configuration file!
// https://github.com/speediegamer/configurations

// Before using, please know a few things.
// * This assumes that your terminal emulator is "~/.config/st/st" If this isn't the case, please edit the bottom SHCMD commands to what you're setup looks like.
// * You must install the Terminus and fontawesome fonts. Otherwise fonts will not be displayed. If you do not wish to do this, please edit *fonts to match your setup.
// * This is my personal build of dwm so you may not like the configuration. In that case either edit it or don't use it at all. I will not customize it for you.

// That's it. Have a good day!

static const unsigned int borderpx  = 2;
static const unsigned int snap      = 32;
static const unsigned int gappx     = 7;
static const int showbar            = 1;
static const int topbar             = 1;
static const char *fonts[]          = { "Terminus:size=10", "fontawesome:size=12" };
static const char dmenufont[]       = "Terminus:size=10";
static const char col_dgray1[]      = "#222222"; // dwm dark bg & slstatus bg
static const char col_gray2[]       = "#222222"; // dwm middle background
static const char col_gray3[]       = "#bbbbbb"; // application title bar/font for norm
static const char col_gray4[]       = "#eeeeee"; // dwm text/font for selected
static const char col_border[]      = "#81a1c1"; // dwm window border (old color = 5757FF)
static const unsigned int baralpha = 0xd0;
static const unsigned int borderalpha = OPAQUE;
static const float mfact            = 0.55;
static const char *tags[] = { "  web", "  sh", "  chat", "  music", "  code", " doc", "  pkg", " video", "  misc" };
static const char *alttags[] = { "[  web]", "[  sh]", "[  chat]", "[  music]", "[  code]", "[ doc]", "[  pkg]", "[  video]", "[  misc]" };
static char dmenumon[2] = "0";
static const char *dmenucmd[] = { NULL };
static const char *termcmd[]  = { NULL };
static const int nmaster            = 1;
static const int resizehints        = 1;
static const char *colors[][3]      = {
	[SchemeNorm] = { col_gray3, col_dgray1, col_gray2 },
	[SchemeSel]  = { col_gray4, col_gray2, col_border },
        /*               text         bg         border */ 
};

static const unsigned int alphas[][3]      = {
       /*               fg      bg        border     */
       [SchemeNorm] = { OPAQUE, baralpha, borderalpha },
       [SchemeSel]  = { OPAQUE, baralpha, borderalpha },
};

static const Rule rules[] = {
	/* class       instance    title       tags mask     isfloating   monitor */
        { "st",        NULL,       NULL,       3 << 9,        0,           -1 },
	{ "Surf",      NULL,       NULL,       2 << 9,        0,           -1 },
	{ "Surf",      NULL,       "broken",   4 << 9,        0,           -1 },
};

#include "layouts.c"
static const Layout layouts[] = {
        { "tile",    tile },
	{ "float",   NULL },
	{ "mono",    monocle },
	{ "grid",    grid },
};

#define MODKEY Mod1Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY|ShiftMask,             KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggletag,      {.ui = 1 << TAG} },

#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

static Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY|ShiftMask,             XK_comma,  spawn,          SHCMD("~/.config/dmenu/dmenu_run") },
	{ MODKEY|ShiftMask,             XK_Return, spawn,          SHCMD("~/.config/st/st") },
	{ MODKEY|ShiftMask,             XK_s,      spawn,          SHCMD("exec flameshot gui") },
        { MODKEY|ShiftMask,             XK_f,      spawn,          SHCMD("~/.config/st/st fff") },
	{ MODKEY|ShiftMask,             XK_w,      spawn,          SHCMD("~/.config/surf/surf") },
	{ MODKEY|ShiftMask,             XK_t,	   spawn,          SHCMD("~/.config/st/st nvim") },
        { MODKEY|ShiftMask,             XK_p,      spawn,          SHCMD("killall WebKitWebProcess") },
	{ MODKEY|ShiftMask,             XK_d,      spawn,          SHCMD("~/.config/discord/discord") },
        { MODKEY|ShiftMask,             XK_y,      spawn,          SHCMD("~/.config/surf/surf invidious.namazso.eu") },
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } }, 
	{ MODKEY,                       XK_Tab,    setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_Return, zoom,           {0} },
	{ MODKEY|ShiftMask,             XK_q,      killclient,     {0} },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY|ShiftMask,             XK_e,      setlayout,      {.v = &layouts[3]} },
	{ MODKEY|ControlMask,           XK_0,      view,           {.ui = ~0 } },
	{ MODKEY,                       XK_d,      focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_d,      tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
};

static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

