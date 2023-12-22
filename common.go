package g2dgo

type GGE_IMAGE_FORMAT uint32

const (
	IMAGE_JPG        GGE_IMAGE_FORMAT = iota ///< jpg文件
	IMAGE_PNG                                ///< png文件
	IMAGE_BMP                                ///< bmp文件
	IMAGE_TGA                                ///< tga文件
	IMAGE_DXT1                               ///< dds文件
	IMAGE_DXT3                               ///< dds文件
	IMAGE_DXT5                               ///< dds文件
	IMAGE_FORCE32BIT = 0x7FFFFFFF
)

// BLEND_MODE 混合模式
type BLEND_MODE uint32

const (
	BLEND_COLORMUL    BLEND_MODE = 0                                                ///< 颜色乘
	BLEND_COLORADD    BLEND_MODE = 1                                                ///< 颜色加
	BLEND_ALPHAMUL    BLEND_MODE = 0                                                ///< alpha乘
	BLEND_ALPHAADD    BLEND_MODE = 2                                                ///< alpha加
	BLEND_NOZWRITE    BLEND_MODE = 0                                                ///< 关闭Z缓冲
	BLEND_ZWRITE      BLEND_MODE = 4                                                ///< 开启Z缓冲
	BLEND_NOTEXFILTER BLEND_MODE = 0                                                ///< 关闭纹理过滤
	BLEND_TEXFILTER   BLEND_MODE = 8                                                ///< 开启纹理过滤
	BLEND_DEFAULT     BLEND_MODE = BLEND_COLORMUL | BLEND_ALPHAMUL | BLEND_NOZWRITE ///< 默认混合模式
	BLEND_DEFAULT_Z   BLEND_MODE = BLEND_COLORMUL | BLEND_ALPHAMUL | BLEND_ZWRITE   ///< 默认开启Z轴写入混合模式
	BLEND_FORCE32BIT  BLEND_MODE = 0x7FFFFFFF
)

// ALPHA_BLEND_MODE Alpha混合模式
type ALPHA_BLEND_MODE uint32

const (
	ALPHA_BLEND_DEFAULT      ALPHA_BLEND_MODE = iota ///< 默认值
	ALPHA_BLEND_ZERO                                 ///< ( 0, 0, 0, 0 )
	ALPHA_BLEND_ONE                                  ///< ( 1, 1, 1, 1 )
	ALPHA_BLEND_SRCCOLOR                             ///< ( Rs, Gs, Bs, As )
	ALPHA_BLEND_INVSRCCOLOR                          ///< ( 1 - Rs, 1 - Gs, 1 - Bs, 1 - As )
	ALPHA_BLEND_SRCALPHA                             ///< ( As, As, As, As )
	ALPHA_BLEND_INVSRCALPHA                          ///< ( 1 - As, 1 - As, 1 - As, 1 - As )
	ALPHA_BLEND_DESTALPHA                            ///< ( Ad, Ad, Ad, Ad )
	ALPHA_BLEND_INVDESTALPHA                         ///< ( 1 - Ad, 1 - Ad, 1 - Ad, 1 - Ad )
	ALPHA_BLEND_DESTCOLOR                            ///< ( Rd, Gd, Bd, Ad )
	ALPHA_BLEND_INVDESTCOLOR                         ///< ( 1 - Rd, 1 - Gd, 1 - Bd, 1 - Ad )
	ALPHA_BLEND_SRCALPHASAT                          ///< ( f, f, f, 1 ); f = min( As, 1 - Ad )
	ALPHA_BLEND__FORCE32BIT  = 0x7FFFFFFF
)

// ALPHA_BLEND_MASK Alpha混合掩码
type ALPHA_BLEND_MASK uint32

const (
	ALPHA_BLEND_SRC_MASK     ALPHA_BLEND_MASK = 0xF << 28
	ALPHA_BLEND_DST_MASK     ALPHA_BLEND_MASK = 0xF << 24
	ALPHA_CHANNEL_SRC_MASK   ALPHA_BLEND_MASK = 0xF << 20
	ALPHA_CHANNEL_DST_MASK   ALPHA_BLEND_MASK = 0xF << 16
	ALPHA_CHANNEL_FORCE32BIT ALPHA_BLEND_MASK = 0x7FFFFFFF
)

// GGE_STATE_BOOL_FUN 系统状态
type GGE_STATE_BOOL_FUN uint32

const (
	GGE_FRAMEFUNC           GGE_STATE_BOOL_FUN = iota ///< bool*()	帧函数，可在运行时更改，必须设置,返回true则退出，false继续运行
	GGE_EXITFUNC                                      ///< bool*()	收到退出消息回调(例如按Alt+F4)，可在运行时更改，返回true则退出，false继续运行
	GGE_FOCUSLOSTFUNC                                 ///< bool*()	失去焦点回调，可在运行时更改，返回值无用，建议返回false
	GGE_FOCUSGAINFUNC                                 ///< bool*()	获得焦点回调，可在运行时更改，返回值无用，建议返回false
	GGE_FORCE32BIT_STATE_BF = 0x7FFFFFFF
)

// GGE_STATE_SYS_VAL 系统状态
type GGE_STATE_SYS_VAL uint32

const (
	GGE_HWND                GGE_STATE_SYS_VAL = iota ///< HWND								窗口句柄，当用System_SetState()函数设置时，显示模式强制使用窗口模式，并且所有Input函数以及帧时间相关函数将不可用，主要用于制作游戏编辑器等工具软件(使用方法可参考示例程序sample3)。当用于System_GetState()函数时，如果之前设置过窗口句柄，则返回之前设置的窗口句柄，否则返回引擎创建的窗口的窗口句柄。
	GGE_MESSAGEFUNC                                  ///< bool*(HWND, UINT, WPARAM, LPARAM)	窗口消息处理函数,如果函数返回true表示该条消息已处理，不会传到默认消息处理函数，可在运行时更改
	GGE_FLUSH_BATCH_FUNC                             ///< void*()							引擎内部开始渲染时回调该函数，如果外部渲染自定义图元时做了缓存，可在此时刷新缓存
	GGE_FORCE32BIT_STATE_MF = 0x7FFFFFFF
)

// GGE_STATE_INT 系统状态
type GGE_STATE_INT uint32

const (
	GGE_ICON               GGE_STATE_INT = iota ///< int	设置图标(资源ID)
	GGE_FPS                                     ///< int	设置帧率(0:不限制 | >0:限制为该帧率)，可在运行时更改，默认:0
	GGE_SCREENMODE                              ///< int	是否全屏模式，可在运行时更改，默认:SCREEN_WINDOWED @see SCREEN_MODE
	GGE_SCREENWIDTH                             ///< int	屏幕宽度，可在运行时更改，默认:640
	GGE_SCREENHEIGHT                            ///< int	屏幕高度，可在运行时更改，默认:480
	GGE_SCREENBPP                               ///< int	色深(16/32)，可在运行时更改，默认:32
	GGE_TEXTURESIZE                             ///< int	获得纹理最大尺寸，只用于System_GetState()函数
	GGE_PSVERSION                               ///< int	PixelShader版本，只用于System_GetState()函数 @see PIXEL_SHADER_VERSION
	GGE_MAXTEXTUREUNITS                         ///< int	显卡支持的最大纹理单元数，只用于System_GetState()函数
	GGE_CODEPAGE                                ///< int	代码页，用于引擎内部编码转换，可在运行时更改，默认:936
	GGE_FORCE32BIT_STATE_I = 0x7FFFFFFF
)

// GGE_STATE_BOOL 系统状态
type GGE_STATE_BOOL uint32

const (
	GGE_HIDEMOUSE          GGE_STATE_BOOL = iota ///< bool	是否隐藏系统鼠标，可在运行时更改，默认:true
	GGE_DEBUGLOG                                 ///< bool	是否开启调试信息，可在运行时更改，默认:true
	GGE_SUSPEND                                  ///< bool	非激活状态时是否挂起，默认:false
	GGE_ZBUFFER                                  ///< bool	是否开启Z缓冲，可在运行时更改，默认:false（注意：如果要用该功能，必须在引擎初始化前将改状态设成true，否则该功能无效）
	GGE_VSYNC                                    ///< bool	是否开启垂直同步，可在运行时更改，默认:false
	GGE_FORCETEXFILTER                           ///< bool	强制开启纹理过滤，可在运行时更改，默认:false
	GGE_FORCE32BITTEXTURE                        ///< bool	载入纹理时强制转换成32位纹理(压缩格式除外)，可在运行时更改，默认:true
	GGE_AUDIOINITED                              ///< bool	音频引擎是否初始化成功，只用于System_GetState()函数
	GGE_ALPHARENDERTARGET                        ///< bool	显卡是否支持带Alpha通道的渲染目标纹理，只用于System_GetState()函数
	GGE_SOUNDEFFECT                              ///< bool	声卡是否支持音频效果器，只用于System_GetState()函数
	GGE_FORCE32BIT_STATE_B = 0x7FFFFFFF
)

// GGE_STATE_CHAR 系统状态
type GGE_STATE_CHAR uint32

const (
	GGE_TITLE              GGE_STATE_CHAR = iota ///< char*		设置窗口标题，可在运行时更改
	GGE_LOGNAME                                  ///< char*		Log文件名，默认:"galaxy2d.log"
	GGE_FORCE32BIT_STATE_C = 0x7FFFFFFF
)

type GGE_MSGFUN func(HWND, UINT, WPARAM, LPARAM uintptr) uintptr
type GGE_BOOLFUN func() uintptr

// ggeClipRect 裁剪区域矩形
type ggeClipRect struct {
	x      int32
	y      int32
	width  int32
	height int32
}

// 鼠标按键编码
const (
	GGEK_LBUTTON = 0x00
	GGEK_RBUTTON = 0x01
	GGEK_MBUTTON = 0x02
)

// 键盘编码
const (
	GGEK_ESCAPE    = 0x1B
	GGEK_BACKSPACE = 0x08
	GGEK_TAB       = 0x09
	GGEK_ENTER     = 0x0D
	GGEK_SPACE     = 0x20

	GGEK_SHIFT = 0x10
	GGEK_CTRL  = 0x11
	GGEK_ALT   = 0x12

	GGEK_LWIN = 0x5B
	GGEK_RWIN = 0x5C
	GGEK_APPS = 0x5D

	GGEK_PAUSE      = 0x13
	GGEK_CAPSLOCK   = 0x14
	GGEK_NUMLOCK    = 0x90
	GGEK_SCROLLLOCK = 0x91

	GGEK_PGUP   = 0x21
	GGEK_PGDN   = 0x22
	GGEK_HOME   = 0x24
	GGEK_END    = 0x23
	GGEK_INSERT = 0x2D
	GGEK_DELETE = 0x2E

	GGEK_LEFT  = 0x25
	GGEK_UP    = 0x26
	GGEK_RIGHT = 0x27
	GGEK_DOWN  = 0x28

	GGEK_0 = 0x30
	GGEK_1 = 0x31
	GGEK_2 = 0x32
	GGEK_3 = 0x33
	GGEK_4 = 0x34
	GGEK_5 = 0x35
	GGEK_6 = 0x36
	GGEK_7 = 0x37
	GGEK_8 = 0x38
	GGEK_9 = 0x39

	GGEK_A = 0x41
	GGEK_B = 0x42
	GGEK_C = 0x43
	GGEK_D = 0x44
	GGEK_E = 0x45
	GGEK_F = 0x46
	GGEK_G = 0x47
	GGEK_H = 0x48
	GGEK_I = 0x49
	GGEK_J = 0x4A
	GGEK_K = 0x4B
	GGEK_L = 0x4C
	GGEK_M = 0x4D
	GGEK_N = 0x4E
	GGEK_O = 0x4F
	GGEK_P = 0x50
	GGEK_Q = 0x51
	GGEK_R = 0x52
	GGEK_S = 0x53
	GGEK_T = 0x54
	GGEK_U = 0x55
	GGEK_V = 0x56
	GGEK_W = 0x57
	GGEK_X = 0x58
	GGEK_Y = 0x59
	GGEK_Z = 0x5A

	GGEK_GRAVE      = 0xC0
	GGEK_MINUS      = 0xBD
	GGEK_EQUALS     = 0xBB
	GGEK_BACKSLASH  = 0xDC
	GGEK_LBRACKET   = 0xDB
	GGEK_RBRACKET   = 0xDD
	GGEK_SEMICOLON  = 0xBA
	GGEK_APOSTROPHE = 0xDE
	GGEK_COMMA      = 0xBC
	GGEK_PERIOD     = 0xBE
	GGEK_SLASH      = 0xBF

	GGEK_NUMPAD0 = 0x60
	GGEK_NUMPAD1 = 0x61
	GGEK_NUMPAD2 = 0x62
	GGEK_NUMPAD3 = 0x63
	GGEK_NUMPAD4 = 0x64
	GGEK_NUMPAD5 = 0x65
	GGEK_NUMPAD6 = 0x66
	GGEK_NUMPAD7 = 0x67
	GGEK_NUMPAD8 = 0x68
	GGEK_NUMPAD9 = 0x69

	GGEK_MULTIPLY = 0x6A
	GGEK_DIVIDE   = 0x6F
	GGEK_ADD      = 0x6B
	GGEK_SUBTRACT = 0x6D
	GGEK_DECIMAL  = 0x6E

	GGEK_F1  = 0x70
	GGEK_F2  = 0x71
	GGEK_F3  = 0x72
	GGEK_F4  = 0x73
	GGEK_F5  = 0x74
	GGEK_F6  = 0x75
	GGEK_F7  = 0x76
	GGEK_F8  = 0x77
	GGEK_F9  = 0x78
	GGEK_F10 = 0x79
	GGEK_F11 = 0x7A
	GGEK_F12 = 0x7B
)
