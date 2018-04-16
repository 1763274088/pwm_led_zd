#ifndef __MUSIC_H__ 
#define __MUSIC_H__ 

////// 定义低音音名（数值单位：Hz）
////#define L1 262
////#define L2 294
////#define L3 330
////#define L4 349
////#define L5 392
////#define L6 440
////#define L7 494

////// 定义中音音名
////#define M1 523
////#define M2 587
////#define M3 659
////#define M4 698
////#define M5 784
////#define M6 880
////#define M7 988

////// 定义高音音名
////#define H1 1047
////#define H2 1175
////#define H3 1319
////#define H4 1397
////#define H5 1568
////#define H6 1760
////#define H7 1976

// 定义低音音名（数值单位：Hz）
#define L1 2000-262
#define L2 2000-294
#define L3 2000-330
#define L4 2000-349
#define L5 2000-392
#define L6 2000-440
#define L7 2000-494

// 定义中音音名
#define M1 2000-523
#define M2 2000-587
#define M3 2000-659
#define M4 2000-698
#define M5 2000-784
#define M6 2000-880
#define M7 2000-988

// 定义高音音名
#define H1 2000-1047
#define H2 2000-1175
#define H3 2000-1319
#define H4 2000-1397
#define H5 2000-1568
#define H6 2000-1760
#define H7 2000-1976

// 定义时值单位，决定演奏速度（数值单位：ms）
#define TT 2000

typedef struct
{
		short mName; // 音名：取值L1～L7、M1～M7、H1～H7分别表示低音、中音、高音的1234567，取值0表示休止符
		short mTime; // 时值：取值T、T/2、T/4、T/8、T/16、T/32分别表示全音符、二分音符、四分音符、八分音符.，取值0表示演奏结束
}tNote;


// 演奏乐曲
extern void musicPlay(void); 
#endif // __MUSIC_H__ 


