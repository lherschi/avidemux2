SET(ADM_LIB ADM_ocrQt4)

ADM_QT_WRAP_UI(${ADM_LIB}_header  ocr.ui)
ADM_QT_WRAP_CPP(${ADM_LIB}_source  Q_ocr.h)

SET(${ADM_LIB}_SRCS
	Q_ocr.cpp  ${${ADM_LIB}_header}  ${${ADM_LIB}_source})

INCLUDE_DIRECTORIES(${CMAKE_CURRENT_BINARY_DIR})
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_BINARY_DIR})
INCLUDE_DIRECTORIES("${CMAKE_SOURCE_DIR}/avidemux/ADM_UIs/ADM_QT4/include")
ADD_LIBRARY(${ADM_LIB} STATIC ${${ADM_LIB}_SRCS})
