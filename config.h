/* See LICENSE file for copyright and license details. */

#define STATUSBAR "dwmblocks"

/* appearance */
static const unsigned int borderpx  = 2;        /* border pixel of windows */
static const int startwithgaps	     = 1;	 /* 1 means gaps are used by default */
static const unsigned int gappx     = 16;        /* gap pixel between windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int swallowfloating    = 1;        /* 1 means swallow floating windows by default */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]          = { "BlexMonoNerdFont:size=11" };
static const char dmenufont[]       = "BlexMonoNerdFont:size=11";
static const char col_gray1[]       = "#222222";
static const char col_gray2[]       = "#444444";
static const char col_gray3[]       = "#bbbbbb";
static const char col_gray4[]       = "#eeeeee";
static const char col_cyan[]        = "#005577";
static const char col_light_purple[]= "#8e42a5";
static const char col_dark_purple[] = "#411f4c";
static const char col_red[]         = "#e88bb3";
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_red, col_gray1, col_dark_purple},
	[SchemeSel]  = { col_dark_purple, col_light_purple,  col_light_purple},
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class     instance  title           tags mask  isfloating  isterminal  noswallow  monitor */
    { "Gimp",	    NULL,     NULL,           0,         1,          0,           0,        -1 },
    { "Firefox",	NULL,     NULL,           1 << 8,    0,          0,          -1,        -1 },
    { "kitty",	    NULL,     NULL,           0,         0,          1,           0,        -1 },
    { NULL,		    NULL,     "Event Tester", 0,         0,          0,           1,        -1 }, /* xev */
    // { "",		NULL,     NULL,           0,         0,          1,           0,        -1 },
    // { "alacritty",  NULL,     NULL,           0,         0,          1,           0,        -1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
};

/* key definitions */
#define MODKEY Mod1Mask

#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }
#define PrintScreenDWM	    0x0000ff61

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray1, "-nf", col_light_purple, "-sb", col_dark_purple, "-sf", col_gray4, NULL };
static const char *termcmd[]  = { "kitty", NULL };
static const char *lock[]  = { "systemctl", "suspend", NULL };
static const char *keyboardlayout[]  = { "switchLayout", NULL };
static const char *keyboardlayoutus[]  = { "switchLayout", "us", NULL };
static const char *keyboardlayouthu[]  = { "switchLayout", "hu", NULL };
static const char *screenshot[] = {"flameshot", "launcher", NULL};
static const char *increase_volume10[] = {"volumechanger", "+10", NULL};
static const char *decrease_volume10[] = {"volumechanger", "-10", NULL};
static const char *increase_volume1[] = {"volumechanger", "+1", NULL};
static const char *decrease_volume1[] = {"volumechanger", "-1", NULL};
static const char *increase_brightness10[] = {"brightnesschanger", "+10%", NULL};
static const char *decrease_brightness10[] = {"brightnesschanger", "10%-", NULL};
static const char *increase_brightness1[] = {"brightnesschanger", "+1%", NULL};
static const char *decrease_brightness1[] = {"brightnesschanger", "1%-", NULL};

static const Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_F5,     spawn,          {.v = decrease_brightness10} },
	{ MODKEY,                       XK_F6,     spawn,          {.v = increase_brightness10} },
	{ MODKEY|ShiftMask,             XK_F5,     spawn,          {.v = decrease_brightness1} },
	{ MODKEY|ShiftMask,             XK_F6,     spawn,          {.v = increase_brightness1} },
	{ MODKEY,                       XK_F2,     spawn,          {.v = decrease_volume10} },
	{ MODKEY,                       XK_F3,     spawn,          {.v = increase_volume10} },
	{ MODKEY|ShiftMask,             XK_F2,     spawn,          {.v = decrease_volume1} },
	{ MODKEY|ShiftMask,             XK_F3,     spawn,          {.v = increase_volume1} },
	{ MODKEY,                       XK_p,      spawn,          {.v = dmenucmd } },
	{ MODKEY|ShiftMask,             XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY|ShiftMask,             XK_m,	   spawn,          {.v = keyboardlayout} },
	{ MODKEY|ShiftMask,             XK_h,	   spawn,          {.v = keyboardlayouthu} },
	{ MODKEY|ShiftMask,             XK_u,	   spawn,          {.v = keyboardlayoutus} },
	{ MODKEY,             		    XK_x, 	   spawn,          {.v = lock } },
    { 0,                            PrintScreenDWM,     spawn, {.v = screenshot} },
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY,                       XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY|ShiftMask,             XK_c,      killclient,     {0} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	{ MODKEY,                       XK_minus,  setgaps,        {.i = -5 } },
	{ MODKEY,                       XK_plus,   setgaps,        {.i = +5 } },
	{ MODKEY|ShiftMask,             XK_minus,  setgaps,        {.i = GAP_RESET } },
	{ MODKEY|ShiftMask,             XK_g,      setgaps,        {.i = GAP_TOGGLE} },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },
};

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

