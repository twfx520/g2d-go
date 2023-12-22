package g2dgo

type TARGET_TYPE uint32

const (
	TARGET_DEFAULT    TARGET_TYPE = 0 ///< 默认类型
	TARGET_ZBUFFER    TARGET_TYPE = 1 ///< 开启ZBuffer
	TARGET_LOCKABLE   TARGET_TYPE = 2 ///< 渲染目标纹理可以被锁定
	TARGET_ALPHA      TARGET_TYPE = 4 ///< 渲染目标纹理带Alpha通道(可通过系统状态 GGE_ALPHARENDERTARGET 检测显卡是否支持创建带Alpha通道的渲染目标纹理)
	TARGET_FORCE32BIT TARGET_TYPE = 0x7FFFFFFF
)

type Texture struct {
}

func NewTextureFromFile(filename string) {

}

func NewTextureFormMem(p uintptr, size uint32) {

}
