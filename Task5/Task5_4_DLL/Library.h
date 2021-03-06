/** 
  * @file	Library.h
  * @brief	Simple implementation of logic around 2d lines and points
  * @author	Vitaliy Sidenko
  * @date	30/06/2012
  */

#ifndef _LIB_H
#define _LIB_H

#define DllExport __declspec(dllexport)

/* Point in 2d space */
struct point
{
	float x, y;
};

/* Line in 2d space */
struct line
{
	point a, b;
};

/**
  * @brief		Gets number of saved points
  */
extern "C" DllExport unsigned points();

/**
  * @brief		Gets number of saved lines
  */
extern "C" DllExport unsigned lines();

/**
  * @brief		Clear all points
  * @return		void
  */
extern "C" DllExport void clearPoints();

/**
  * @brief		Add point
  * @param		[in] p Point to add
  * @return		void
  */
extern "C" DllExport void addPoint(point &p);

/**
  * @brief		Get point by index
  * @param		[in] index Point index
  * @return		Pointer to point struct
  */
extern "C" DllExport point* getPoint(unsigned index);

/**
  * @brief		Set point by index
  * @param		[in] p Point data
  * @param		[in] index Point index
  * @return		False if index does not exist
  */
extern "C" DllExport bool setPoint(point &p, unsigned index);

/**
  * @brief		Clear all lines
  * @return		void
  */
extern "C" DllExport void clearLines();

/**
  * @brief		Add line
  * @param		[in] l Line to add
  * @return		void
  */
extern "C" DllExport void addLine(line &l);

/**
  * @brief		Get line by index
  * @param		[in] index Line index
  * @return		Pointer to line struct
  */
extern "C" DllExport line* getLine(unsigned index);

/**
  * @brief		Set line by index
  * @param		[in] l Line data
  * @param		[in] index Line index
  * @return		False if index does not exist
  */
extern "C" DllExport bool setLine(line &l, unsigned index);

/**
  * @brief		Get line length
  * @param		[in] index Line index
  * @return		Line length or 0 if index does not exist
  */
extern "C" DllExport float lineLength(unsigned index);

/**
  * @brief		Check if point lies of the lane
  * @param		[in] pointIndex Point index
  * @param		[in] lineIndex Line index
  * @return		1 if point lies in the line, else 0; -1 if index does not exist
  */
extern "C" DllExport int liesOnLine(unsigned pointIndex, unsigned lineIndex);

/**
  * @brief		Check if point lies of the lane segment
  * @param		[in] pointIndex Point index
  * @param		[in] lineIndex Line index
  * @return		1 if point lies in the line segment, else 0; -1 if index does not exist
  */
extern "C" DllExport int liesOnLineSegment(unsigned pointIndex, unsigned lineIndex);

/**
  * @brief		Get triangle data by given line and a point
  * @param		[in] pointIndex Point index
  * @param		[in] lineIndex Line index
  * @return		Traingle area or 0 if index does not exist
  */
extern "C" DllExport float triangleArea(unsigned pointIndex, unsigned lineIndex);

/**
  * @brief		Get triangle data by given point indexes
  * @param		[in] point1 1st Point index
  * @param		[in] point2 2d Point index
  * @param		[in] point3 3d Point index
  * @return		Traingle area or 0 if index does not exist
  */
extern "C" DllExport float triangleArea2(unsigned point1, unsigned point2, unsigned point3);

#endif	/* _LIB_H */