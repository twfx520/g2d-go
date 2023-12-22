package g2dgo

// EngineCreate 创建引擎
// @param ver 版本号
// @return 成功返回true，失败返回false
func EngineCreate(version int) bool {
	return true
}

// EngineRelease 释放引擎
func EngineRelease() {

}

// SystemInitiate 初始化系统
// @return 成功返回true，失败返回false
// @note 系统未初始化前只有System_SetState函数有效
func SystemInitiate() bool {
	return true
}

// SystemStart 系统开始运行
// @return 正常结束返回true，否则返回false
// @note 运行该函数前必须设置帧函数
func SystemStart() {

}

// SystemSetIntState 设置系统状态
func SystemSetIntState(state GGE_STATE_INT, value uint32) {

}

// SystemSetBoolState 设置系统状态
func SystemSetBoolState(state GGE_STATE_BOOL, value bool) {

}

// SystemSetIntState 设置系统状态
func SystemSetCharState(state GGE_STATE_CHAR, value string) {

}

// SystemSetIntState 设置系统状态
func SystemSetBoolFunState(state GGE_STATE_BOOL_FUN, value GGE_BOOLFUN) {

}

// SystemSetSysValState 设置系统状态
func SystemSetSysValState(state GGE_STATE_SYS_VAL, value uintptr) {

}

// SystemGetIntState 返回系统状态
func SystemGetIntState(state GGE_STATE_INT) int {
	return 0
}

// SystemGetBoolState 返回系统状态
func SystemGetBoolState(state GGE_STATE_BOOL) bool {
	return true
}

// SystemGetCharState 返回系统状态
func SystemGetCharState(state GGE_STATE_CHAR) string {
	return ""
}

// SystemGetBoolFunState 返回系统状态
func SystemGetBoolFunState(state GGE_STATE_BOOL_FUN) GGE_BOOLFUN {
	return nil
}

// SystemGetSysValState 返回系统状态
func SystemGetSysValState(state GGE_STATE_SYS_VAL) uintptr {
	return 0
}

// SystemLog 写入调试Log
func SystemLog(format string, a ...any) {
	// fmt.Sprintf(format, a...)
}

// SystemLaunch 运行外部可执行文件或打开URL
func SystemLaunch(url string) bool {
	return false
}

// ResourceLoad 读取资源文件
// @param filename 资源文件名
// @param size 读取文件成功后将文件大小写入该参数
// @return 读取成功返回资源内存指针，否则返回0
// @note 该函数优先读取绑定的文件包内的文件
func ResourceLoad(filename string, size *uint32) uintptr {
	return 0
}

// ResourceLoadTo 读取资源文件到指定的内存中
// @param filename 资源文件名
// @param buf 用于保存资源文件的内存
// @param size 内存大小，如果小于文件大小读取将会失败
// @return 读取成功返回实际读取的字节数，读取失败返回0
// @note 该函数优先读取绑定的文件包内的文件
func ResourceLoadTo(filename string, buf []byte, size uint32) uint32 {
	return 0
}

// ResourceGetSize 获取资源文件大小
// @param filename 资源文件名
// @return 资源文件大小
// @note 该函数优先读取绑定的文件包内的文件
func ResourceGetSize(filename string) uint32 {
	return 0
}

// ResourceIsExist 检测资源文件是否存在
// @param filename 资源文件名
// @return 资源文件存在返回true，否则返回false
func ResourceIsExist(filename string) bool {
	return false
}

// ResourceFree 释放资源
// @param buf Resource_Load()函数载入的资源
func ResourceFree(buf uintptr) {

}

// ResourceAttachPack 绑定文件包，文件包可以用引擎附带的文件打包工具生成，也可以是一个zip压缩文件
// @param filename 文件名
// @param password 密码
// @return 绑定成功返回true，否则返回false
// @note 若有多个文件包，依次绑定即可。搜索文件时从第一个绑定文件包开始查找文件，如果找到立即返回，忽略后面文件包中的同名文件。
func ResourceAttachPack(filename, password string) bool {
	return false
}

// ResourceRemovePack 移除文件包
// @param filename 文件名
func ResourceRemovePack(filename string) {

}

// ResourceAddPath 添加资源文件搜索路径
// 若Resource_Load()函数在当前目录无法找到资源文件，会尝试从搜索路径中查找文件，搜索路径可添加多个但不可删除
// @param pathname 资源搜索路径
func ResourceAddPath(pathname string) {

}

// void			 Ini_SetFile(const char *filename);
// void			 Ini_SetInt(const char *section, const char *name, int value);
// int			 Ini_GetInt(const char *section, const char *name, int def_val);
// void			 Ini_SetFloat(const char *section, const char *name, float value);
// float		 Ini_GetFloat(const char *section, const char *name, float def_val);
// void			 Ini_SetString(const char *section, const char *name, const char *value);
// const char*	 Ini_GetString(const char *section, const char *name, const char *def_val);

// TimerGetTime 游戏启动后经过的时间，每帧刷新一次，精确到1毫秒
// @return 返回游戏时间
func TimerGetTime() uint32 {
	return 0
}

// TimeGetTick 返回实时时间，一帧内两次调用该函数，返回值可能不同，精确到1毫秒
// @return 返回当前时间
func TimeGetTick() uint32 {
	return 0
}

// TimeGetDelta 返回上一帧所用时间
// @return 返回上一帧所用时间，精确到0.001秒
func TimeGetDelta() float32 {
	return 0
}

// TimerGetFPS 返回帧率
// @return 返回帧率
func TimerGetFPS() uint32 {
	return 0
}

// guint32		 Random_Create();
// void			 Random_Seed(guint32 seed, guint32 rid = 0);
// int			 Random_Int(int min, int max, guint32 rid = 0);
// float		 Random_Float(float min, float max, guint32 rid = 0);
// guint32		 Random_CreateMt();
// void			 Random_SeedMt(guint32 seed, guint32 rid = 0);
// int			 Random_IntMt(int min, int max, guint32 rid = 0);
// guint32		 Random_UIntMt(guint32 min, guint32 max, guint32 rid = 0);
// float		 Random_FloatMt(float min, float max, guint32 rid = 0);

// GraphClear 以指定颜色清除屏幕
// @param color 清除屏幕颜色
func GraphClear(color uint32) {

}

// GraphBeginScene
func GraphBeginScene() bool {
	return false
}

// GraphEndScene
func GraphEndScene() {

}

// bool	Graph_CopyBackBuffer(ggeTexture *texture, ggeRect *srcRt = 0, ggeRect *destRt = 0, bool btFilter = false);
// bool	Graph_CopyRanderTarget(ggeTexture *src, ggeTexture *dest, ggeRect *srcRt = 0, ggeRect *destRt = 0, bool btFilter = false);
// void			 Graph_SetCurrentShader(ggeShader *shader = 0);
// ggeShader*	 Graph_GetCurrentShader();

// GraphRenderLine 从点(x1,y1)至(x2,y2)画线
// @param x1 起始点x坐标
// @param y1 起始点y坐标
// @param x2 结束点x坐标
// @param y2 结束点y坐标
// @param color 指定线的颜色
func GraphRenderLine(x1, y1, x2, y2 float32, color uint32) {

}

// GraphRenderRect 从点(x1,y1)至(x2,y2)画矩形
// @param x1 起始点x坐标
// @param y1 起始点y坐标
// @param x2 结束点x坐标
// @param y2 结束点y坐标
// @param color 指定线的颜色
func GraphRenderRect(x1, y1, x2, y2 float32, color uint32) {

}

// void	Graph_RenderTriple(const ggeTriple &triple);
// void	Graph_RenderQuad(const ggeQuad &quad);
// void	Graph_RenderBatch(PRIM_TYPE primType, const ggeVertex *vt, int primNum, ggeTexture *tex = 0, int blend = BLEND_DEFAULT);
// void	Graph_RenderBatchIndices(PRIM_TYPE primType, const ggeVertex *vt, int vertexNum, const guint16 *indices, int primNum, ggeTexture *tex = 0, int blend = BLEND_DEFAULT);
// void	Graph_PushClipRect(const ggeClipRect &rt);
// const ggeClipRect*	Graph_GetClipRect();
// void					Graph_PopClipRect();
// guint32				Graph_GetClipRectCount();
// void					Graph_PushTransformMatrix(const ggeMatrix4 &mat);
// const ggeMatrix4*	Graph_GetTransformMatrix();
// void					Graph_PopTransformMatrix();
// guint32				Graph_GetTransformMatrixCount();
// void					Graph_PushViewTransform(float dx, float dy, float hscale = 1.0f, float vscale = 1.0f, float rot = 0.0f, float hx = 0.0f, float hy = 0.0f);
// void					Graph_PushViewMatrix(const ggeMatrix4 &mat);
// const ggeMatrix4&	Graph_GetViewMatrix();
// void					Graph_PopViewMatrix();
// guint32				Graph_GetViewMatrixCount();
// void					Graph_PushProjectionMatrix(const ggeMatrix4 &mat);
// const ggeMatrix4&	Graph_GetProjectionMatrix();
// void					Graph_PopProjectionMatrix();
// guint32				Graph_GetProjectionMatrixCount();

// GraphSnapshot 保存屏幕截图
// @param filename 保存文件名
// @param imageFormat 文件格式(该函数不支持dds压缩格式)
func GraphSnapshot(filename string, imageFormat GGE_IMAGE_FORMAT) {

}

// GraphGetDisplayModeCount 获取显示模式数量，调用Engine_Create()函数后有效
func GraphGetDisplayModeCount() uint32 {
	return 0
}

// GraphGetDisplayMode 获取显示模式，调用Engine_Create()函数后有效
func GraphGetDisplayMode(index uint32, width, height *uint32) {

}

// GraphGetDrawnBatches 获取渲染批次数
func GraphGetDrawnBatches() uint32 {
	return 0
}

// void					Audio_SetMaxVolume(float volume);
// float				Audio_GetMaxVolume();
// void					Audio_SetListenerPosition(const ggeVector3 &position);
// const ggeVector3&	Audio_GetListenerPosition();
// void					Audio_SetListenerVelocity(const ggeVector3 &velocity);
// const ggeVector3&	Audio_GetListenerVelocity();
// void					Audio_SetListenerOrientation(const ggeVector3 &forward, const ggeVector3 &up);
// const ggeVector3&	Audio_GetListenerOrientationForward();
// const ggeVector3&	Audio_GetListenerOrientationUp();
// void					Audio_SetDopplerScale(float scale);
// float				Audio_GetDopplerScale();
// void					Audio_SetDistanceModel(AUDIO_DISTANCE_MODEL model);
// AUDIO_DISTANCE_MODEL Audio_GetDistanceModel();

func InputGetMousePosX() float32 {
	return 0
}

func InputGetMousePosY() float32 {
	return 0
}

func InputSetMousePos(x, y float32) {

}

func InputGetMouseWheel() uint32 {
	return 0
}

func InputIsMouseOver() bool {
	return false
}

func InputIsKeyPress(key uint32) bool {
	return false
}

func InputIsKeyUp(key uint32) bool {
	return false
}

func InputIsKeyDown(key uint32) bool {
	return false
}

func InputIsMousePress(key uint32) bool {
	return false
}
func InputIsMouseUp(key uint32) bool {
	return false
}
func InputIsMouseDown(key uint32) bool {
	return false
}

func InputGetKey() uint32 {
	return 0
}
func InputGetChar() string {
	return ""
}
func InputGetKeyName(key uint32) string {
	return ""
}
