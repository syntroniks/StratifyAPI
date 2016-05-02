//Copyright 2011-2016 Tyler Gilbert; All Rights Reserved


#include "binary.h"
#include "fonts.h"

const uint8_t font3x5[] = {
		//Space
		B8(00000000), //1
		B8(00000000), //2
		B8(00000000), //3
		B8(00000000), //4
		B8(00000000), //5
		B8(00000000), //6
		B8(00000000), //7
		B8(00000000), //8

		//!
		B8(01000000), //1
		B8(01000000), //2
		B8(01000000), //3
		B8(00000000), //4
		B8(01000000), //5
		B8(00000000), //6
		B8(00000000), //7
		B8(00000000), //8

		//"
		B8(10010000), //1
		B8(10010000), //2
		B8(10010000), //3
		B8(00000000), //4
		B8(00000000), //5
		B8(00000000), //6
		B8(00000000), //7
		B8(00000000), //8

		//#
		B8(00000000), //1
		B8(01010000), //2
		B8(11111000), //3
		B8(01010000), //4
		B8(11111000), //5
		B8(01010000), //6
		B8(00000000), //7
		B8(00000000), //8

		//$
		B8(00100000), //1
		B8(01110000), //2
		B8(10100000), //3
		B8(01110000), //4
		B8(00101000), //5
		B8(01110000), //6
		B8(00100000), //7
		B8(00000000), //8

		//%
		B8(00000000), //1
		B8(10001000), //2
		B8(00010000), //3
		B8(00100000), //4
		B8(01000000), //5
		B8(10000000), //6
		B8(10001000), //7
		B8(00000000), //8

		//&
		B8(01110000), //1
		B8(10001000), //2
		B8(01010000), //3
		B8(00100000), //4
		B8(01010100), //5
		B8(10001000), //6
		B8(01110100), //7
		B8(00000000), //8

		//'
		B8(00100000), //1
		B8(00100000), //2
		B8(00000000), //3
		B8(00000000), //4
		B8(00000000), //5
		B8(00000000), //6
		B8(00000000), //7
		B8(00000000), //8

		//(
		B8(00010000), //1
		B8(00100000), //2
		B8(01000000), //3
		B8(01000000), //4
		B8(01000000), //5
		B8(01000000), //6
		B8(00100000), //7
		B8(00010000), //8

		//)
		B8(01000000), //1
		B8(00100000), //2
		B8(00010000), //3
		B8(00010000), //4
		B8(00010000), //5
		B8(00010000), //6
		B8(00100000), //7
		B8(01000000), //8

		//*
		B8(00100000), //1
		B8(10101000), //2
		B8(01110000), //3
		B8(11111000), //4
		B8(01110000), //5
		B8(10101000), //6
		B8(00100000), //7
		B8(00000000), //8

		//+
		B8(00000000), //1
		B8(00100000), //2
		B8(00100000), //3
		B8(11111000), //4
		B8(00100000), //5
		B8(00100000), //6
		B8(00000000), //7
		B8(00000000), //8

		//'
		B8(00000000), //1
		B8(00100000), //2
		B8(00100000), //3
		B8(11111000), //4
		B8(00100000), //5
		B8(00100000), //6
		B8(00000000), //7
		B8(00000000), //8

		//-
		B8(00000000), //1
		B8(00100000), //2
		B8(00100000), //3
		B8(11111000), //4
		B8(00100000), //5
		B8(00100000), //6
		B8(00000000), //7
		B8(00000000), //8

		//.
		B8(00000000), //1
		B8(00100000), //2
		B8(00100000), //3
		B8(11111000), //4
		B8(00100000), //5
		B8(00100000), //6
		B8(00000000), //7
		B8(00000000), //8

		// /
		B8(00000000), //1
		B8(00100000), //2
		B8(00100000), //3
		B8(11111000), //4
		B8(00100000), //5
		B8(00100000), //6
		B8(00000000), //7
		B8(00000000), //8

		//0
		B8(11100000), //1
		B8(10100000), //2
		B8(10100000), //3
		B8(10100000), //4
		B8(11100000), //5
		B8(00000000), //6
		B8(00000000), //7
		B8(00000000), //8

		//1
		B8(01000000), //1
		B8(11000000), //2
		B8(01000000), //3
		B8(01000000), //4
		B8(11100000), //5
		B8(00000000), //6
		B8(00000000), //7
		B8(00000000), //8

		//2
		B8(11100000), //1
		B8(00100000), //2
		B8(11100000), //3
		B8(10000000), //4
		B8(11100000), //5
		B8(00000000), //6
		B8(00000000), //7
		B8(00000000), //8

		//3
		B8(11100000), //1
		B8(00100000), //2
		B8(11100000), //3
		B8(00100000), //4
		B8(11100000), //5
		B8(00000000), //6
		B8(00000000), //7
		B8(00000000), //8

		//4
		B8(10100000), //1
		B8(10100000), //2
		B8(11100000), //3
		B8(00100000), //4
		B8(00100000), //5
		B8(00000000), //6
		B8(00000000), //7
		B8(00000000), //8

		//5
		B8(11100000), //1
		B8(10000000), //2
		B8(11100000), //3
		B8(00100000), //4
		B8(11100000), //5
		B8(00000000), //6
		B8(00000000), //7
		B8(00000000), //8

		//6
		B8(11100000), //1
		B8(10000000), //2
		B8(11100000), //3
		B8(10100000), //4
		B8(11100000), //5
		B8(00000000), //6
		B8(00000000), //7
		B8(00000000), //8

		//7
		B8(11100000), //1
		B8(00100000), //2
		B8(01000000), //3
		B8(01000000), //4
		B8(01000000), //5
		B8(00000000), //6
		B8(00000000), //7
		B8(00000000), //8

		//8
		B8(11100000), //1
		B8(10100000), //2
		B8(11100000), //3
		B8(10100000), //4
		B8(11100000), //5
		B8(00000000), //6
		B8(00000000), //7
		B8(00000000), //8

		//9
		B8(11100000), //1
		B8(10100000), //2
		B8(11100000), //3
		B8(00100000), //4
		B8(11100000), //5
		B8(00000000), //6
		B8(00000000), //7
		B8(00000000), //8

		//:
		B8(00000000), //1
		B8(01000000), //2
		B8(00000000), //3
		B8(01000000), //4
		B8(00000000), //5
		B8(00000000), //6
		B8(00000000), //7
		B8(00000000), //8

		//;
		B8(00000000), //1
		B8(01000000), //2
		B8(00000000), //3
		B8(01000000), //4
		B8(01000000), //5
		B8(00000000), //6
		B8(00000000), //7
		B8(00000000), //8

		//<
		B8(00100000), //1
		B8(01000000), //2
		B8(10000000), //3
		B8(01000000), //4
		B8(00100000), //5
		B8(00000000), //6
		B8(00000000), //7
		B8(00000000), //8

		//=
		B8(00000000), //1
		B8(00000000), //2
		B8(11100000), //3
		B8(00000000), //4
		B8(11100000), //5
		B8(00000000), //6
		B8(00000000), //7
		B8(00000000), //8

		//>
		B8(10000000), //1
		B8(01000000), //2
		B8(00100000), //3
		B8(01000000), //4
		B8(10000000), //5
		B8(00000000), //6
		B8(00000000), //7
		B8(00000000), //8

		//?
		B8(11100000), //1
		B8(00100000), //2
		B8(01000000), //3
		B8(00000000), //4
		B8(01000000), //5
		B8(00000000), //6
		B8(00000000), //7
		B8(00000000), //8

		//@
		B8(00000000), //1
		B8(00000000), //2
		B8(00000000), //3
		B8(00000000), //4
		B8(00000000), //5
		B8(00000000), //6
		B8(00000000), //7
		B8(00000000), //8


		//A
		B8(11100000), //1
		B8(10100000), //2
		B8(11100000), //3
		B8(10100000), //4
		B8(10100000), //5
		B8(00000000), //6
		B8(00000000), //7
		B8(00000000), //8

		//B
		B8(11100000), //1
		B8(10100000), //2
		B8(11000000), //3
		B8(10100000), //4
		B8(11100000), //5
		B8(00000000), //6
		B8(00000000), //7
		B8(00000000), //8

		//C
		B8(11100000), //1
		B8(10000000), //2
		B8(10000000), //3
		B8(10000000), //4
		B8(11100000), //5
		B8(00000000), //6
		B8(00000000), //7
		B8(00000000), //8

		//D
		B8(11000000), //1
		B8(10100000), //2
		B8(10100000), //3
		B8(10100000), //4
		B8(11000000), //5
		B8(00000000), //6
		B8(00000000), //7
		B8(00000000), //8

		//E
		B8(11100000), //1
		B8(10000000), //2
		B8(11100000), //3
		B8(10000000), //4
		B8(11100000), //5
		B8(00000000), //6
		B8(00000000), //7
		B8(00000000), //8

		//F
		B8(11100000), //1
		B8(10000000), //2
		B8(11100000), //3
		B8(10000000), //4
		B8(10000000), //5
		B8(00000000), //6
		B8(00000000), //7
		B8(00000000), //8

		//G
		B8(11100000), //1
		B8(10000000), //2
		B8(10000000), //3
		B8(10100000), //4
		B8(11100000), //5
		B8(00000000), //6
		B8(00000000), //7
		B8(00000000), //8

		//H
		B8(10100000), //1
		B8(10100000), //2
		B8(11100000), //3
		B8(10100000), //4
		B8(11100000), //5
		B8(00000000), //6
		B8(00000000), //7
		B8(00000000), //8

		//I
		B8(11100000), //1
		B8(01000000), //2
		B8(01000000), //3
		B8(01000000), //4
		B8(11100000), //5
		B8(00000000), //6
		B8(00000000), //7
		B8(00000000), //8


		//J
		B8(11100000), //1
		B8(01000000), //2
		B8(01000000), //3
		B8(01000000), //4
		B8(11000000), //5
		B8(00000000), //6
		B8(00000000), //7
		B8(00000000), //8

		//K
		B8(10100000), //1
		B8(10100000), //2
		B8(11000000), //3
		B8(10100000), //4
		B8(10100000), //5
		B8(00000000), //6
		B8(00000000), //7
		B8(00000000), //8

		//L
		B8(10000000), //1
		B8(10000000), //2
		B8(10000000), //3
		B8(10000000), //4
		B8(11100000), //5
		B8(00000000), //6
		B8(00000000), //7
		B8(00000000), //8

		//M
		B8(10100000), //1
		B8(11100000), //2
		B8(10100000), //3
		B8(10100000), //4
		B8(10100000), //5
		B8(00000000), //6
		B8(00000000), //7
		B8(00000000), //8

		//N
		B8(10100000), //1
		B8(11100000), //2
		B8(11100000), //3
		B8(10100000), //4
		B8(10100000), //5
		B8(00000000), //6
		B8(00000000), //7
		B8(00000000), //8

		//O
		B8(01000000), //1
		B8(10100000), //2
		B8(10100000), //3
		B8(10100000), //4
		B8(01000000), //5
		B8(00000000), //6
		B8(00000000), //7
		B8(00000000), //8

		//P
		B8(11100000), //1
		B8(10100000), //2
		B8(11100000), //3
		B8(10000000), //4
		B8(10000000), //5
		B8(00000000), //6
		B8(00000000), //7
		B8(00000000), //8

		//Q
		B8(01000000), //1
		B8(10100000), //2
		B8(10100000), //3
		B8(11100000), //4
		B8(01100000), //5
		B8(00000000), //6
		B8(00000000), //7
		B8(00000000), //8

		//R
		B8(11000000), //1
		B8(10100000), //2
		B8(11000000), //3
		B8(10100000), //4
		B8(10100000), //5
		B8(00000000), //6
		B8(00000000), //7
		B8(00000000), //8

		//S
		B8(11100000), //1
		B8(10000000), //2
		B8(11100000), //3
		B8(00100000), //4
		B8(11100000), //5
		B8(00000000), //6
		B8(00000000), //7
		B8(00000000), //8

		//T
		B8(11100000), //1
		B8(01000000), //2
		B8(01000000), //3
		B8(01000000), //4
		B8(01000000), //5
		B8(00000000), //6
		B8(00000000), //7
		B8(00000000), //8

		//U
		B8(10100000), //1
		B8(10100000), //2
		B8(10100000), //3
		B8(10100000), //4
		B8(11100000), //5
		B8(00000000), //6
		B8(00000000), //7
		B8(00000000), //8

		//V
		B8(10100000), //1
		B8(10100000), //2
		B8(10100000), //3
		B8(10100000), //4
		B8(01000000), //5
		B8(00000000), //6
		B8(00000000), //7
		B8(00000000), //8

		//W
		B8(10100000), //1
		B8(10100000), //2
		B8(10100000), //3
		B8(11100000), //4
		B8(10100000), //5
		B8(00000000), //6
		B8(00000000), //7
		B8(00000000), //8

		//X
		B8(10100000), //1
		B8(10100000), //2
		B8(01000000), //3
		B8(10100000), //4
		B8(10100000), //5
		B8(00000000), //6
		B8(00000000), //7
		B8(00000000), //8

		//Y
		B8(10100000), //1
		B8(10100000), //2
		B8(01000000), //3
		B8(01000000), //4
		B8(01000000), //5
		B8(00000000), //6
		B8(00000000), //7
		B8(00000000), //8

		//Z
		B8(11100000), //1
		B8(00100), //2
		B8(01000), //3
		B8(10000), //4
		B8(11100), //5
		B8(00000000), //6
		B8(00000000), //7
		B8(00000000), //8
		B8(00000000), //6
		B8(00000000), //7
		B8(00000000), //8

		//-
		B8(00000000), //1
		B8(00000000), //2
		B8(00000000), //3
		B8(11111000), //4
		B8(00000000), //5
		B8(00000000), //6
		B8(00000000), //7
		B8(00000000), //8

		//.
		B8(00000000), //1
		B8(00000000), //2
		B8(00000000), //3
		B8(00000000), //4
		B8(00000000), //5
		B8(00000000), //6
		B8(00100000), //7
		B8(00000000), //8

		// /
		B8(00100000), //1
		B8(00100000), //2
		B8(01000000), //3
		B8(10000000), //4
		B8(10000000), //5
		B8(00000000), //6
		B8(00000000), //7
		B8(00000000), //8

		//0
		B8(11100000), //1
		B8(10100000), //2
		B8(10100000), //3
		B8(10100000), //4
		B8(11100000), //5
		B8(00000000), //6
		B8(00000000), //7
		B8(00000000), //8

		//1
		B8(01000000), //1
		B8(01000000), //2
		B8(01000000), //3
		B8(01000000), //4
		B8(11100000), //5
		B8(00000000), //6
		B8(00000000), //7
		B8(00000000), //8

		//2
		B8(11100000), //1
		B8(00100000), //2
		B8(11100000), //3
		B8(10000000), //4
		B8(11100000), //5
		B8(00000000), //6
		B8(00000000), //7
		B8(00000000), //8

		//3
		B8(11100000), //1
		B8(00100000), //2
		B8(11100000), //3
		B8(00100000), //4
		B8(11100000), //5
		B8(00000000), //6
		B8(00000000), //7
		B8(00000000), //8

		//4
		B8(10100000), //1
		B8(10100000), //2
		B8(11100000), //3
		B8(00100000), //4
		B8(00100000), //5
		B8(00000000), //6
		B8(00000000), //7
		B8(00000000), //8

		//5
		B8(11100000), //1
		B8(10000000), //2
		B8(11100000), //3
		B8(00100000), //4
		B8(11100000), //5
		B8(00000000), //6
		B8(00000000), //7
		B8(00000000), //8

		//6
		B8(11100000), //1
		B8(10000000), //2
		B8(11100000), //3
		B8(10100000), //4
		B8(11100000), //5
		B8(00000000), //6
		B8(00000000), //7
		B8(00000000), //8

		//7
		B8(11100000), //1
		B8(00100000), //2
		B8(00100000), //3
		B8(01000000), //4
		B8(01000000), //5
		B8(00000000), //6
		B8(00000000), //7
		B8(00000000), //8

		//8
		B8(11100000), //1
		B8(10100000), //2
		B8(11100000), //3
		B8(10100000), //4
		B8(11100000), //5
		B8(00000000), //6
		B8(00000000), //7
		B8(00000000), //8

		//9
		B8(11100000), //1
		B8(10100000), //2
		B8(11100000), //3
		B8(00100000), //4
		B8(11100000), //5
		B8(00000000), //6
		B8(00000000), //7
		B8(00000000), //8

		//:
		B8(00000000), //1
		B8(01000000), //2
		B8(00000000), //3
		B8(01000000), //4
		B8(00000000), //5
		B8(00000000), //6
		B8(00000000), //7
		B8(00000000), //8

		//;
		B8(00000000), //1
		B8(01000000), //2
		B8(00000000), //3
		B8(01000000), //4
		B8(01000000), //5
		B8(00000000), //6
		B8(00000000), //7
		B8(00000000), //8

		//<
		B8(00100000), //1
		B8(01000000), //2
		B8(10000000), //3
		B8(01000000), //4
		B8(00100000), //5
		B8(00000000), //6
		B8(00000000), //7
		B8(00000000), //8

		//=
		B8(00000000), //1
		B8(11100000), //2
		B8(00000000), //3
		B8(11100000), //4
		B8(00000000), //5
		B8(00000000), //6
		B8(00000000), //7
		B8(00000000), //8

		//>
		B8(10000000), //1
		B8(01000000), //2
		B8(00100000), //3
		B8(01000000), //4
		B8(10000000), //5
		B8(00000000), //6
		B8(00000000), //7
		B8(00000000), //8

		//?
		B8(11100000), //1
		B8(00100000), //2
		B8(01100000), //3
		B8(00000000), //4
		B8(01000000), //5
		B8(00000000), //6
		B8(00000000), //7
		B8(00000000), //8

		//@
		B8(00000000), //1
		B8(00000000), //2
		B8(00000000), //3
		B8(00000000), //4
		B8(00000000), //5
		B8(00000000), //6
		B8(00000000), //7
		B8(00000000), //8

		//A
		B8(11100000), //1
		B8(10100000), //2
		B8(11100000), //3
		B8(10100000), //4
		B8(10100000), //5
		B8(00000000), //6
		B8(00000000), //7
		B8(00000000), //8

		//B
		B8(11100000), //1
		B8(10100000), //2
		B8(11000000), //3
		B8(10100000), //4
		B8(11100000), //5
		B8(00000000), //6
		B8(00000000), //7
		B8(00000000), //8

		//C
		B8(11100000), //1
		B8(10000000), //2
		B8(10000000), //3
		B8(10000000), //4
		B8(11100000), //5
		B8(00000000), //6
		B8(00000000), //7
		B8(00000000), //8

		//D
		B8(1100000), //1
		B8(10100000), //2
		B8(10100000), //3
		B8(10100000), //4
		B8(11000000), //5
		B8(00000000), //6
		B8(00000000), //7
		B8(00000000), //8

		//E
		B8(11100000), //1
		B8(10000000), //2
		B8(11100000), //3
		B8(10000000), //4
		B8(11100000), //5
		B8(00000000), //6
		B8(00000000), //7
		B8(00000000), //8

		//F
		B8(11100000), //1
		B8(10000000), //2
		B8(11100000), //3
		B8(10000000), //4
		B8(10000000), //5
		B8(00000000), //6
		B8(00000000), //7
		B8(00000000), //8

		//G
		B8(11100000), //1
		B8(10000000), //2
		B8(10000000), //3
		B8(10100000), //4
		B8(11100000), //5
		B8(00000000), //6
		B8(00000000), //7
		B8(00000000), //8

		//H
		B8(10100000), //1
		B8(10100000), //2
		B8(11100000), //3
		B8(10100000), //4
		B8(11100000), //5
		B8(00000000), //6
		B8(00000000), //7
		B8(00000000), //8

		//I
		B8(11100000), //1
		B8(01000000), //2
		B8(01000000), //3
		B8(01000000), //4
		B8(11100000), //5
		B8(00000000), //6
		B8(00000000), //7
		B8(00000000), //8


		//J
		B8(11100000), //1
		B8(01000000), //2
		B8(01000000), //3
		B8(01000000), //4
		B8(11000000), //5
		B8(00000000), //6
		B8(00000000), //7
		B8(00000000), //8

		//K
		B8(10100000), //1
		B8(10100000), //2
		B8(11000000), //3
		B8(10100000), //4
		B8(10100000), //5
		B8(00000000), //6
		B8(00000000), //7
		B8(00000000), //8

		//L
		B8(10000000), //1
		B8(10000000), //2
		B8(10000000), //3
		B8(10000000), //4
		B8(11100000), //5
		B8(00000000), //6
		B8(00000000), //7
		B8(00000000), //8

		//M
		B8(10100000), //1
		B8(11100000), //2
		B8(10100000), //3
		B8(10100000), //4
		B8(10100000), //5
		B8(00000000), //6
		B8(00000000), //7
		B8(00000000), //8

		//N
		B8(10100000), //1
		B8(11100000), //2
		B8(11100000), //3
		B8(10100000), //4
		B8(10100000), //5
		B8(00000000), //6
		B8(00000000), //7
		B8(00000000), //8

		//O
		B8(01000000), //1
		B8(10100000), //2
		B8(10100000), //3
		B8(10100000), //4
		B8(01000000), //5
		B8(00000000), //6
		B8(00000000), //7
		B8(00000000), //8

		//P
		B8(11100000), //1
		B8(10100000), //2
		B8(11100000), //3
		B8(10000000), //4
		B8(10000000), //5
		B8(00000000), //6
		B8(00000000), //7
		B8(00000000), //8

		//Q
		B8(01000000), //1
		B8(10100000), //2
		B8(10100000), //3
		B8(11100000), //4
		B8(01100000), //5
		B8(00000000), //6
		B8(00000000), //7
		B8(00000000), //8

		//R
		B8(11000000), //1
		B8(10100000), //2
		B8(11000000), //3
		B8(10100000), //4
		B8(10100000), //5
		B8(00000000), //6
		B8(00000000), //7
		B8(00000000), //8

		//S
		B8(11100000), //1
		B8(10000000), //2
		B8(11100000), //3
		B8(00100000), //4
		B8(11100000), //5
		B8(00000000), //6
		B8(00000000), //7
		B8(00000000), //8

		//T
		B8(11100000), //1
		B8(01000000), //2
		B8(01000000), //3
		B8(01000000), //4
		B8(01000000), //5
		B8(00000000), //6
		B8(00000000), //7
		B8(00000000), //8

		//U
		B8(10100000), //1
		B8(10100000), //2
		B8(10100000), //3
		B8(10100000), //4
		B8(11100000), //5
		B8(00000000), //6
		B8(00000000), //7
		B8(00000000), //8

		//V
		B8(10100), //1
		B8(10100), //2
		B8(10100), //3
		B8(10100), //4
		B8(01000), //5
		B8(00000000), //6
		B8(00000000), //7
		B8(00000000), //8

		//W
		B8(10100000), //1
		B8(10100000), //2
		B8(10100000), //3
		B8(11100000), //4
		B8(10100000), //5
		B8(00000000), //6
		B8(00000000), //7
		B8(00000000), //8

		//X
		B8(10100000), //1
		B8(10100000), //2
		B8(01000000), //3
		B8(10100000), //4
		B8(10100000), //5
		B8(00000000), //6
		B8(00000000), //7
		B8(00000000), //8

		//Y
		B8(10100000), //1
		B8(10100000), //2
		B8(01000000), //3
		B8(01000000), //4
		B8(01000000), //5
		B8(00000000), //6
		B8(00000000), //7
		B8(00000000), //8

		//Z
		B8(11100000), //1
		B8(00100000), //2
		B8(01000000), //3
		B8(10000000), //4
		B8(11100000), //5
		B8(00000000), //6
		B8(00000000), //7
		B8(00000000), //8

		//[
		B8(11000000), //1
		B8(10000000), //2
		B8(10000000), //3
		B8(10000000), //4
		B8(11000000), //5
		B8(00000000), //6
		B8(00000000), //7
		B8(00000000), //8

		// \ j
		B8(10000000), //1
		B8(10000000), //2
		B8(01000000), //3
		B8(00100000), //4
		B8(00100000), //5
		B8(00000000), //6
		B8(00000000), //7
		B8(00000000), //8

		//]
		B8(01100000), //1
		B8(00100000), //2
		B8(00100000), //3
		B8(00100000), //4
		B8(01100000), //5
		B8(00000000), //6
		B8(00000000), //7
		B8(00000000), //8

		//^
		B8(01000000), //1
		B8(10100000), //2
		B8(00000000), //3
		B8(00000000), //4
		B8(00000000), //5
		B8(00000000), //6
		B8(00000000), //7
		B8(00000000), //8

		//_
		B8(00000000), //1
		B8(00000000), //2
		B8(00000000), //3
		B8(00000000), //4
		B8(11100000), //5
		B8(00000000), //6
		B8(00000000), //7
		B8(00000000), //8

		//`
		B8(10000000), //1
		B8(01000000), //2
		B8(00000000), //3
		B8(00000000), //4
		B8(00000000), //5
		B8(00000000), //6
		B8(00000000), //7
		B8(00000000), //8

		//A
		B8(11100000), //1
		B8(10100000), //2
		B8(11100000), //3
		B8(10100000), //4
		B8(10100000), //5
		B8(00000000), //6
		B8(00000000), //7
		B8(00000000), //8

		//B
		B8(11100000), //1
		B8(10100000), //2
		B8(11000000), //3
		B8(10100000), //4
		B8(11100000), //5
		B8(00000000), //6
		B8(00000000), //7
		B8(00000000), //8

		//C
		B8(11100000), //1
		B8(10000000), //2
		B8(10000000), //3
		B8(10000000), //4
		B8(11100000), //5
		B8(00000000), //6
		B8(00000000), //7
		B8(00000000), //8

		//D
		B8(1100000), //1
		B8(10100000), //2
		B8(10100000), //3
		B8(10100000), //4
		B8(11000000), //5
		B8(00000000), //6
		B8(00000000), //7
		B8(00000000), //8

		//E
		B8(11100000), //1
		B8(10000000), //2
		B8(11100000), //3
		B8(10000000), //4
		B8(11100000), //5
		B8(00000000), //6
		B8(00000000), //7
		B8(00000000), //8

		//F
		B8(11100000), //1
		B8(10000000), //2
		B8(11100000), //3
		B8(10000000), //4
		B8(10000000), //5
		B8(00000000), //6
		B8(00000000), //7
		B8(00000000), //8

		//G
		B8(11100000), //1
		B8(10000000), //2
		B8(10000000), //3
		B8(10100000), //4
		B8(11100000), //5
		B8(00000000), //6
		B8(00000000), //7
		B8(00000000), //8

		//H
		B8(10100000), //1
		B8(10100000), //2
		B8(11100000), //3
		B8(10100000), //4
		B8(11100000), //5
		B8(00000000), //6
		B8(00000000), //7
		B8(00000000), //8

		//I
		B8(11100000), //1
		B8(01000000), //2
		B8(01000000), //3
		B8(01000000), //4
		B8(11100000), //5
		B8(00000000), //6
		B8(00000000), //7
		B8(00000000), //8


		//J
		B8(11100000), //1
		B8(01000000), //2
		B8(01000000), //3
		B8(01000000), //4
		B8(11000000), //5
		B8(00000000), //6
		B8(00000000), //7
		B8(00000000), //8

		//K
		B8(10100000), //1
		B8(10100000), //2
		B8(11000000), //3
		B8(10100000), //4
		B8(10100000), //5
		B8(00000000), //6
		B8(00000000), //7
		B8(00000000), //8

		//L
		B8(10000000), //1
		B8(10000000), //2
		B8(10000000), //3
		B8(10000000), //4
		B8(11100000), //5
		B8(00000000), //6
		B8(00000000), //7
		B8(00000000), //8

		//M
		B8(10100000), //1
		B8(11100000), //2
		B8(10100000), //3
		B8(10100000), //4
		B8(10100000), //5
		B8(00000000), //6
		B8(00000000), //7
		B8(00000000), //8

		//N
		B8(10100000), //1
		B8(11100000), //2
		B8(11100000), //3
		B8(10100000), //4
		B8(10100000), //5
		B8(00000000), //6
		B8(00000000), //7
		B8(00000000), //8

		//O
		B8(01000000), //1
		B8(10100000), //2
		B8(10100000), //3
		B8(10100000), //4
		B8(01000000), //5
		B8(00000000), //6
		B8(00000000), //7
		B8(00000000), //8

		//P
		B8(11100000), //1
		B8(10100000), //2
		B8(11100000), //3
		B8(10000000), //4
		B8(10000000), //5
		B8(00000000), //6
		B8(00000000), //7
		B8(00000000), //8

		//Q
		B8(01000000), //1
		B8(10100000), //2
		B8(10100000), //3
		B8(11100000), //4
		B8(01100000), //5
		B8(00000000), //6
		B8(00000000), //7
		B8(00000000), //8

		//R
		B8(11000000), //1
		B8(10100000), //2
		B8(11000000), //3
		B8(10100000), //4
		B8(10100000), //5
		B8(00000000), //6
		B8(00000000), //7
		B8(00000000), //8

		//S
		B8(11100000), //1
		B8(10000000), //2
		B8(11100000), //3
		B8(00100000), //4
		B8(11100000), //5
		B8(00000000), //6
		B8(00000000), //7
		B8(00000000), //8

		//T
		B8(11100000), //1
		B8(01000000), //2
		B8(01000000), //3
		B8(01000000), //4
		B8(01000000), //5
		B8(00000000), //6
		B8(00000000), //7
		B8(00000000), //8

		//U
		B8(10100000), //1
		B8(10100000), //2
		B8(10100000), //3
		B8(10100000), //4
		B8(11100000), //5
		B8(00000000), //6
		B8(00000000), //7
		B8(00000000), //8

		//V
		B8(10100), //1
		B8(10100), //2
		B8(10100), //3
		B8(10100), //4
		B8(01000), //5
		B8(00000000), //6
		B8(00000000), //7
		B8(00000000), //8

		//W
		B8(10100000), //1
		B8(10100000), //2
		B8(10100000), //3
		B8(11100000), //4
		B8(10100000), //5
		B8(00000000), //6
		B8(00000000), //7
		B8(00000000), //8

		//X
		B8(10100000), //1
		B8(10100000), //2
		B8(01000000), //3
		B8(10100000), //4
		B8(10100000), //5
		B8(00000000), //6
		B8(00000000), //7
		B8(00000000), //8

		//Y
		B8(10100000), //1
		B8(10100000), //2
		B8(01000000), //3
		B8(01000000), //4
		B8(01000000), //5
		B8(00000000), //6
		B8(00000000), //7
		B8(00000000), //8

		//Z
		B8(11100000), //1
		B8(00100000), //2
		B8(01000000), //3
		B8(10000000), //4
		B8(11100000), //5
		B8(00000000), //6
		B8(00000000), //7
		B8(00000000), //8


		//{
		B8(0010000), //1
		B8(0100000), //2
		B8(1100000), //3
		B8(0100000), //4
		B8(0010000), //5
		B8(00000000), //6
		B8(00000000), //7
		B8(00000000), //8

		//|
		B8(01000000), //1
		B8(01000000), //2
		B8(01000000), //3
		B8(01000000), //4
		B8(01000000), //5
		B8(00000000), //6
		B8(00000000), //7
		B8(00000000), //8

		//}
		B8(10000000), //1
		B8(01000000), //2
		B8(01100000), //3
		B8(01000000), //4
		B8(10000000), //5
		B8(00000000), //6
		B8(00000000), //7
		B8(00000000), //8

		//~
		B8(11000000), //1
		B8(10100000), //2
		B8(00000000), //3
		B8(00000000), //4
		B8(00000000), //5
		B8(00000000), //6
		B8(00000000), //7
		B8(00000000), //8

		// DEL
		B8(00000000), //1
		B8(00000000), //2
		B8(00000000), //3
		B8(00000000), //4
		B8(00000000), //5
		B8(00000000), //6
		B8(00000000), //7
		B8(00000000), //8

};
