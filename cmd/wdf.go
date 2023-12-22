package main

import (
	"encoding/binary"
	"errors"
	"fmt"
	"io"
	"os"
)

/*
------------------------------------------------------
4    | 4       | 4             | data  | FilelistData|
------------------------------------------------------
FLAG | FileNum | FileListOffset| data  | FilelistData|
------------------------------------------------------
*/

type WDF struct {
	WDFHeader
	List     []FileList
	FileName string
}

type WDFHeader struct {
	Flag   uint32 // 包裹的标签  		0x57444650
	Number uint32 // 包裹中的文件数量
	Offset uint32 // 包裹中的文件列表偏移位置
}

type FileList struct {
	Hash   uint32 // 文件的名字散列
	Offset uint32 // 文件的偏移
	Size   uint32 // 文件的大小
	Spaces uint32 // 文件的空间
}

func main() {
	wdf, err := NewWDF(os.Args[1])
	if err != nil {
		panic(err)
	}
	//fmt.Printf("%+v\n", wdf)
	wdf.Unarchive()
}

func NewWDF(filename string) (*WDF, error) {
	f, err := os.Open(filename)
	if err != nil {
		return nil, err
	}
	defer f.Close()
	buffer := make([]byte, 12)
	n, err := f.Read(buffer)
	if err != nil {
		return nil, err
	}
	if n != 12 {
		return nil, errors.New("len not 12")
	}

	wdf := &WDF{
		FileName: filename,
	}
	wdf.Flag = binary.LittleEndian.Uint32(buffer[0:4])
	wdf.Number = binary.LittleEndian.Uint32(buffer[4:8])
	wdf.Offset = binary.LittleEndian.Uint32(buffer[8:12])

	if wdf.Flag != 0x57444650 {
		return nil, errors.New("not invalid wdf")
	}

	f.Seek(int64(wdf.Offset), io.SeekStart)
	wdf.List = make([]FileList, wdf.Number)

	for i := 0; i < int(wdf.Number); i++ {
		var tmp FileList
		err := binary.Read(f, binary.LittleEndian, &tmp)
		if err != nil {
			return nil, err
		}
		wdf.List[i] = tmp
	}

	return wdf, nil
}

func (w *WDF) Unarchive() {
	f, _ := os.Open(w.FileName)
	defer f.Close()
	for _, val := range w.List {
		f.Seek(int64(val.Offset), io.SeekStart)
		tmp := make([]byte, val.Size)
		f.Read(tmp)
		os.WriteFile(fmt.Sprintf("%x.was", val.Hash), tmp, 0644)
	}
}
