package g2dgo

type G2dRect struct {
	X1 float32
	Y1 float32
	X2 float32
	Y2 float32
}

type G2dBox struct {
	X float32
	Y float32
	W float32
	H float32
	G2dRect
}

func NewG2dBox(x, y, w, h float32) *G2dBox {
	return &G2dBox{
		X: x,
		Y: y,
		W: w,
		H: h,
		G2dRect: G2dRect{
			X1: x,
			Y1: y,
			X2: x + w,
			Y2: y + h,
		},
	}
}

func (b *G2dBox) CheckBox() {}
