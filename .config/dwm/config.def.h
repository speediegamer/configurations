// speedie's Dynamic Window Manager configuration file!
// https://github.com/speediegamer/configurations
//
// REQUIRED DEPENDENCIES: media-fonts/terminus-font, media-fonts/fontawesome
// If you want it to be slightly usable: 
// * Make sure a dmenu binary is available in "~/.config/dmenu"
// * Make sure a st binary is available in "~/.config/st"
// * Pulsemixer (for volume controls) 
// * Pulseaudio/Pipewire (for the audio itself) 
//
// Included shortcuts for:
// * ~/.config/surf/surf (suckless surf web browser by pressing MOD+SHIFT+w)
// * /usr/bin/obs (OBS Studio by pressing MOD+SHIFT+o)
// * /usr/bin/mocp (Music On Console Player by pressing MOD+SHIFT+m)
// * /usr/bin/discord (Surfcord suckless surf based Discord client by pressing MOD+SHIFT+d)
// * ~/.config/st/st (st terminal by pressing MOD+SHIFT+ENTER)
// * /usr/bin/nvim (neovim by pressing MOD+SHIFT+t)
// * /usr/bin/fff (fucking fast file manager by pressing MOD+SHIFT+f)
// * Mute pipewire/pulseaudio (by pressing MOD+1)
// * Lower pipewire/pulseaudio volume (by pressing MOD+2)
// * Increase pipewire/pulseaudio volume (by pressing MOD+3)
// * Invidious (in the surf browser by pressing MOD+SHIFT+y)
// * Killing all surf instances (by pressing MOD+SHIFT+p)
// * Killing the current window (by pressing MOD+SHIFT+q)
// * Run ~/.config/dmenu/dmenu (by pressing MOD+SHIFT+comma) 
// * Patched with fullscreen so you can go fullscreen (by pressing MOD+SHIFT+f)
// * Switch tag (by pressing MOD+SHIFT+number between 1 and 9)
// * Find out the rest by reading the source code.

// That's it. Have a good day!

static const unsigned int borderpx            = 2;
static const unsigned int snap                = 32;
static const unsigned int gappx               = 7;
static const int showbar                      = 1;
static const int topbar                       = 1;
static const char *fonts[]                    = { "Terminus:size=10", "fontawesome:size=12" };
static const char dmenufont[]                 = "Terminus:size=10";
static const char col_background[]            = "#222222"; // dwm dark bg & slstatus bg
static const char col_backgroundmid[]         = "#222222"; // dwm middle background
static const char col_textnorm[]              = "#bbbbbb"; // application title bar/font for norm
static const char col_textsel[]               = "#eeeeee"; // dwm text/font for selected
static const char col_windowbordernorm[]      = "#5e81ac"; // dwm norm window border
static const char col_windowbordersel[]       = "#81a1c1"; // dwm sel window border
static const unsigned int baralpha            = 0xd0;
static const unsigned int borderalpha         = OPAQUE;
static const float mfact                      = 0.50;
static const int nmaster                      = 1;
static const int resizehints                  = 1;
static char dmenumon[2]                       = "0";
static const char *dmenucmd[]                 = { NULL };
static const char *termcmd[]                  = { NULL };
static const char *tags[] = { "  web", "  sh", "  chat", "  music", "  code", " doc", "  pkg", " video", "  misc" };
static const char *alttags[] = { "[  web]", "[  sh]", "[  chat]", "[  music]", "[  code]", "[ doc]", "[  pkg]", "[  video]", "[  misc]" };
static const char *colors[][3]      = {
	[SchemeNorm] = { col_textnorm, col_background, col_windowbordernorm },
	[SchemeSel]  = { col_textsel, col_backgroundmid, col_windowbordersel }, 
//                       text         background         window border
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
	{ MODKEY|ShiftMask,             XK_s,      spawn,          SHCMD("exec flameshot gui && killall flameshot") },
    { MODKEY|ShiftMask,             XK_f,      spawn,          SHCMD("~/.config/st/st fff") },
	{ MODKEY|ShiftMask,             XK_w,      spawn,          SHCMD("~/.config/surf/surf") },
	{ MODKEY|ShiftMask,             XK_t,	   spawn,          SHCMD("~/.config/st/st nvim") },
    { MODKEY|ShiftMask,             XK_p,      spawn,          SHCMD("killall WebKitWebProcess") },
	{ MODKEY|ShiftMask,             XK_d,      spawn,          SHCMD("/usr/bin/discord") },      
	{ MODKEY|ShiftMask,             XK_y,      spawn,          SHCMD("~/.config/surf/surf invidious.namazso.eu") },
	{ MODKEY|ShiftMask,             XK_x,      spawn,          SHCMD("~/.config/st/st bpytop") },
	{ MODKEY|ShiftMask,             XK_o,      spawn,          SHCMD("/usr/bin/obs") },
    { MODKEY,                       XK_3,      spawn,          SHCMD("pulsemixer --unmute && pulsemixer --change-volume +2 && killall pulsemixer") },
    { MODKEY,                       XK_2,      spawn,          SHCMD("pulsemixer --unmute && pulsemixer --change-volume -2 && killall pulsemixer") },
    { MODKEY,                       XK_1,      spawn,          SHCMD("pulsemixer --mute") },
	{ MODKEY|ShiftMask,             XK_a,      spawn,          SHCMD("~/.config/st/st pulsemixer") },
	{ MODKEY|ShiftMask,             XK_m,      spawn,          SHCMD("~/.config/st/st mocp /mnt/storage01/Music/Playlist") }, 
	{ MODKEY,                       XK_f,      togglefullscr,  {0} },
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
	{ ClkStatusText,        0,              Button2,        spawn,          SHCMD("~/.config/st/st") },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

