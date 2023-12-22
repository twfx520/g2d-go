package g2dgo

import (
	"bytes"
	"encoding/binary"
	"errors"
	"fmt"
	"io"
	"os"
)

type WasHeader struct {
	Flag   uint16 // 精灵文件标志 SP 0x5053
	Len    uint16 // 文件头的长度 默认为 12
	Group  uint16 // 精灵图片的组数，即方向数
	Frame  uint16 // 每组的图片数，即帧数
	Width  uint16 // 精灵动画的宽度，单位像素
	Height uint16 // 精灵动画的高度，单位像素
	KeyX   uint16 // 精灵动画的关键位X
	KeyY   uint16 //  精灵动画的关键位Y
}

type WasFrame struct {
	KeyX   uint32 //  图片的关键位X
	KeyY   uint32 // 图片的关键位Y
	Width  uint32 //图片的宽度，单位像素
	Height uint32 // 图片的高度，单位像素
}

type PalRGB struct {
	R uint32
	G uint32
	B uint32
}

type PalProgram struct {
	Color [3]PalRGB
}

type WAS struct {
	WasHeader
	Data      []byte
	Len       int
	Palette16 [256]uint16
	Palette32 [256]uint32
	FrameList []uint32
}

func NewWasFromMem(p uintptr, len uint32) {

}

func NewWasFromFile(filename string) (*WAS, error) {
	bs, err := os.ReadFile(filename)
	if err != nil {
		return nil, err
	}

	was := &WAS{
		Data: bs,
		Len:  len(bs),
	}
	err = was.parse()
	if err != nil {
		return nil, err
	}
	return was, nil
}

func (w *WAS) parse() error {
	buf := bytes.NewReader(w.Data)
	var header WasHeader
	err := binary.Read(buf, binary.LittleEndian, &header)
	if err != nil {
		fmt.Println("解析失败:", err)
		return err
	}
	w.WasHeader = header

	if header.Flag == 0x5053 {
		tmp := make([]byte, 512)
		buf.Read(tmp)
		for i := 0; i < 256; i++ {
			val := binary.LittleEndian.Uint16(tmp[2*i : 2*i+2])
			w.Palette16[i] = val
		}
		w.RGB565to888()
		w.FrameList = make([]uint32, header.Group*header.Frame)
		tmp = make([]byte, 4*len(w.FrameList))
		buf.Read(tmp)
		for i := 0; i < len(w.FrameList); i++ {
			val := binary.LittleEndian.Uint32(tmp[4*i : 4*i+4])
			w.FrameList[i] = val
		}
	} else {
		return errors.New("format invalid")
	}

	return nil
}

func (w *WAS) RGB565to888() {
	for i := 0; i < 256; i++ {
		r := uint8(w.Palette16[i]>>11) & 0xFF
		g := uint8(w.Palette16[i]>>5) & 0x3F
		b := uint8(w.Palette16[i]) & 0x1F
		w.Palette32[i] = uint32(b<<3|b>>2) | uint32(g<<2|g>>4)<<8 | uint32(r<<3|r>>2)<<16 | 0xFF000000
	}
}

func (w *WAS) GetTexture(id int) {
	if id > len(w.FrameList) {
		return
	}
	if id < len(w.FrameList) && w.FrameList[id] > 0 {
		offset := w.FrameList[id]
		buf := bytes.NewReader(w.Data)
		buf.Seek(int64(offset), io.SeekStart)
		var frame WasFrame
		binary.Read(buf, binary.LittleEndian, &frame)
		if frame.Width > 0 && frame.Height > 0 {
			for h := 0; h < int(frame.Height); h++ {

			}
		}
	}
}
