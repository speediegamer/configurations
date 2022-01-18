/* speedie's Dynamic Window Manager configuration file!
https://github.com/speediegamer/configurations

// Requires fontawesome and Terminus
appearance */

static const unsigned int borderpx  = 2;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const unsigned int gappx     = 5;        /* gaps between windows */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]          = { "Terminus:size=10", "fontawesome:size=12" };
static const char dmenufont[]       = "Terminus:size=10";
static const char col_dgray1[]      = "#222222"; // dwm dark bg & slstatus bg
static const char col_gray2[]       = "#444444"; // dwm title bar
static const char col_gray3[]       = "#bbbbbb"; // application title bar/font for norm
static const char col_gray4[]       = "#eeeeee"; // dwm text/font for selected
static const char col_border[]      = "#81a1c1"; // dwm window border (old color = 5757FF)
static const char *colors[][3]      = {
	/*               text         bg         border   */
	[SchemeNorm] = { col_gray3, col_dgray1, col_gray2 },
	[SchemeSel]  = { col_gray4, col_gray2, col_border  },
};

static const char *tags[] = { " ", " ", " ", " ", " ", " ", " ", " ", " " };

static const Rule rules[] = {
	/* class       instance    title       tags mask     isfloating   monitor */
        { "surf",   NULL,       NULL,       2 << 9,        0,           -1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ " ",      tile },    /* first entry is default */
	{ " ",      NULL },    /* no layout function means floating behavior */
	{ " ",      monocle },
};

#define MODKEY Mod1Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY|ShiftMask,             KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
//static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
//static const char *dmenucmd[] = { "dmenu_run", "-m -b", dmenumon, "-fn", dmenufont, "-nb", col_dgray1, "-nf", col_gray3, "-sb", col_border, "-sf", col_gray4, NULL };
//static const char *termcmd[]  = { "st", NULL };
static Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY|ShiftMask,             XK_comma,  spawn,          SHCMD("/usr/bin/dmenu_run") },
	{ MODKEY|ShiftMask,             XK_Return, spawn,          SHCMD("~/.config/st/st") },
	{ MODKEY|ShiftMask,             XK_s,      spawn,          SHCMD("scr") },
        { MODKEY|ShiftMask,             XK_f,      spawn,          SHCMD("st fff") },
	{ MODKEY|ShiftMask,             XK_w,      spawn,          SHCMD("~/.config/surf/surf https://duckduckgo.com") },
	{ MODKEY|ShiftMask,             XK_t,	   spawn,          SHCMD("st vim") },
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } }, 
	{ MODKEY,                       XK_Tab,    setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_Return, zoom,           {0} },
	{ MODKEY|ShiftMask,             XK_q,      killclient,     {0} },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ControlMask,           XK_0,      tag,            {.ui = ~0 } },
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

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
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

