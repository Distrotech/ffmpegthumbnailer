SUBDIRS = man
ACLOCAL_AMFLAGS = -I m4

lib_LTLIBRARIES = libffmpegthumbnailer.la

libffmpegthumbnailer_la_SOURCES =   libffmpegthumbnailer/moviedecoder.h \
                                    libffmpegthumbnailer/moviedecoder.cpp \
                                    libffmpegthumbnailer/imagewriter.h \
                                    libffmpegthumbnailer/imagewriterfactory.h \
                                    libffmpegthumbnailer/stringoperations.h \
                                    libffmpegthumbnailer/stringoperations.cpp \
                                    libffmpegthumbnailer/videothumbnailer.cpp \
                                    libffmpegthumbnailer/videothumbnailerc.cpp \
                                    libffmpegthumbnailer/ifilter.h \
                                    libffmpegthumbnailer/videoframe.h \
                                    libffmpegthumbnailer/histogram.h \
                                    libffmpegthumbnailer/grayscalefilter.h \
                                    libffmpegthumbnailer/filmstrip.h \
                                    libffmpegthumbnailer/filmstripfilter.h \
                                    libffmpegthumbnailer/filmstripfilter.cpp

if PNG
libffmpegthumbnailer_la_SOURCES +=  libffmpegthumbnailer/pngwriter.h \
                                    libffmpegthumbnailer/pngwriter.cpp
endif

if JPEG
libffmpegthumbnailer_la_SOURCES +=  libffmpegthumbnailer/jpegwriter.h \
                                    libffmpegthumbnailer/jpegwriter.cpp
endif

nobase_include_HEADERS =    libffmpegthumbnailer/videothumbnailer.h \
                            libffmpegthumbnailer/videothumbnailerc.h \
                            libffmpegthumbnailer/imagetypes.h \
                            libffmpegthumbnailer/ifilter.h \
                            libffmpegthumbnailer/videoframe.h \
                            libffmpegthumbnailer/filmstripfilter.h

libffmpegthumbnailer_includedir         = $(includedir)/libffmpegthumbnailer
libffmpegthumbnailer_la_CXXFLAGS        = $(AM_CXXFLAGS) $(FFMPEG_CFLAGS) $(PNG_CFLAGS)
libffmpegthumbnailer_la_LDFLAGS         = -version-info 4:8:0
libffmpegthumbnailer_la_LIBADD          = $(FFMPEG_LIBS) $(PNG_LIBS) $(JPEG_LIBS)

bin_PROGRAMS = ffmpegthumbnailer

ffmpegthumbnailer_SOURCES = main.cpp
ffmpegthumbnailer_LDADD = $(DL_LIBS) libffmpegthumbnailer.la

if ENABLE_UNITTEST
check_PROGRAMS = testrunner
TESTS = testrunner
AM_COLOR_TESTS = always
endif

testrunner_SOURCES =    unittest/testrunner.cpp \
                        unittest/histogramtest.cpp \
                        unittest/videothumbnailertest.cpp

testrunner_CXXFLAGS =   $(AM_CXXFLAGS) '-DTEST_DATADIR="$(top_srcdir)/unittest"'
testrunner_LDFLAGS  =   libffmpegthumbnailer.la
testrunner_LDADD    =   $(UNITTEST_LIBS)

if ENABLE_THUMBNAILER
thumbnailerdir		=	$(datadir)/thumbnailers
thumbnailer_DATA	= 	dist/ffmpegthumbnailer.thumbnailer
endif

EXTRA_DIST			= 	$(thumbnailer_DATA)

pkgconfigdir = @pkgconfigdir@
pkgconfig_DATA = libffmpegthumbnailer.pc

