#include "lwip/apps/fs.h"
#include "lwip/def.h"


#define file_NULL (struct fsdata_file *) NULL


#ifndef FS_FILE_FLAGS_HEADER_INCLUDED
#define FS_FILE_FLAGS_HEADER_INCLUDED 1
#endif
#ifndef FS_FILE_FLAGS_HEADER_PERSISTENT
#define FS_FILE_FLAGS_HEADER_PERSISTENT 0
#endif
/* FSDATA_FILE_ALIGNMENT: 0=off, 1=by variable, 2=by include */
#ifndef FSDATA_FILE_ALIGNMENT
#define FSDATA_FILE_ALIGNMENT 0
#endif
#ifndef FSDATA_ALIGN_PRE
#define FSDATA_ALIGN_PRE
#endif
#ifndef FSDATA_ALIGN_POST
#define FSDATA_ALIGN_POST
#endif
#if FSDATA_FILE_ALIGNMENT==2
#include "fsdata_alignment.h"
#endif
#if FSDATA_FILE_ALIGNMENT==1
static const unsigned int dummy_align__404_html = 0;
#endif
static const unsigned char FSDATA_ALIGN_PRE data__404_html[] FSDATA_ALIGN_POST = {
/* /404.html (10 chars) */
0x2f,0x34,0x30,0x34,0x2e,0x68,0x74,0x6d,0x6c,0x00,0x00,0x00,

/* HTTP header */
/* "HTTP/1.0 404 File not found
" (29 bytes) */
0x48,0x54,0x54,0x50,0x2f,0x31,0x2e,0x30,0x20,0x34,0x30,0x34,0x20,0x46,0x69,0x6c,
0x65,0x20,0x6e,0x6f,0x74,0x20,0x66,0x6f,0x75,0x6e,0x64,0x0d,0x0a,
/* "Server: lwIP/2.1.2 (http://savannah.nongnu.org/projects/lwip)
" (63 bytes) */
0x53,0x65,0x72,0x76,0x65,0x72,0x3a,0x20,0x6c,0x77,0x49,0x50,0x2f,0x32,0x2e,0x31,
0x2e,0x32,0x20,0x28,0x68,0x74,0x74,0x70,0x3a,0x2f,0x2f,0x73,0x61,0x76,0x61,0x6e,
0x6e,0x61,0x68,0x2e,0x6e,0x6f,0x6e,0x67,0x6e,0x75,0x2e,0x6f,0x72,0x67,0x2f,0x70,
0x72,0x6f,0x6a,0x65,0x63,0x74,0x73,0x2f,0x6c,0x77,0x69,0x70,0x29,0x0d,0x0a,
/* "Content-Length: 1096
" (18+ bytes) */
0x43,0x6f,0x6e,0x74,0x65,0x6e,0x74,0x2d,0x4c,0x65,0x6e,0x67,0x74,0x68,0x3a,0x20,
0x31,0x30,0x39,0x36,0x0d,0x0a,
/* "Content-Type: text/html

" (27 bytes) */
0x43,0x6f,0x6e,0x74,0x65,0x6e,0x74,0x2d,0x54,0x79,0x70,0x65,0x3a,0x20,0x74,0x65,
0x78,0x74,0x2f,0x68,0x74,0x6d,0x6c,0x0d,0x0a,0x0d,0x0a,
/* raw file data (1096 bytes) */
0x3c,0x21,0x44,0x4f,0x43,0x54,0x59,0x50,0x45,0x20,0x48,0x54,0x4d,0x4c,0x20,0x50,
0x55,0x42,0x4c,0x49,0x43,0x20,0x22,0x2d,0x2f,0x2f,0x57,0x33,0x43,0x2f,0x2f,0x44,
0x54,0x44,0x20,0x48,0x54,0x4d,0x4c,0x20,0x34,0x2e,0x30,0x31,0x20,0x54,0x72,0x61,
0x6e,0x73,0x69,0x74,0x69,0x6f,0x6e,0x61,0x6c,0x2f,0x2f,0x45,0x4e,0x22,0x3e,0x0d,
0x0a,0x3c,0x68,0x74,0x6d,0x6c,0x3e,0x3c,0x68,0x65,0x61,0x64,0x3e,0x3c,0x74,0x69,
0x74,0x6c,0x65,0x3e,0x53,0x54,0x4d,0x33,0x32,0x46,0x37,0x78,0x78,0x3c,0x2f,0x74,
0x69,0x74,0x6c,0x65,0x3e,0x3c,0x2f,0x68,0x65,0x61,0x64,0x3e,0x0d,0x0a,0x3c,0x62,
0x6f,0x64,0x79,0x20,0x73,0x74,0x79,0x6c,0x65,0x3d,0x22,0x63,0x6f,0x6c,0x6f,0x72,
0x3a,0x20,0x62,0x6c,0x61,0x63,0x6b,0x3b,0x20,0x62,0x61,0x63,0x6b,0x67,0x72,0x6f,
0x75,0x6e,0x64,0x2d,0x63,0x6f,0x6c,0x6f,0x72,0x3a,0x20,0x77,0x68,0x69,0x74,0x65,
0x3b,0x22,0x3e,0x0d,0x0a,0x3c,0x74,0x61,0x62,0x6c,0x65,0x20,0x77,0x69,0x64,0x74,
0x68,0x3d,0x22,0x31,0x30,0x30,0x25,0x22,0x3e,0x0d,0x0a,0x3c,0x74,0x62,0x6f,0x64,
0x79,0x3e,0x0d,0x0a,0x3c,0x74,0x72,0x20,0x76,0x61,0x6c,0x69,0x67,0x6e,0x3d,0x22,
0x74,0x6f,0x70,0x22,0x3e,0x0d,0x0a,0x3c,0x74,0x64,0x20,0x77,0x69,0x64,0x74,0x68,
0x3d,0x22,0x38,0x30,0x22,0x3e,0x3c,0x62,0x72,0x3e,0x0d,0x0a,0x3c,0x64,0x69,0x76,
0x20,0x73,0x74,0x79,0x6c,0x65,0x3d,0x22,0x74,0x65,0x78,0x74,0x2d,0x61,0x6c,0x69,
0x67,0x6e,0x3a,0x20,0x63,0x65,0x6e,0x74,0x65,0x72,0x3b,0x22,0x3e,0x3c,0x69,0x6d,
0x67,0x20,0x73,0x74,0x79,0x6c,0x65,0x3d,0x22,0x77,0x69,0x64,0x74,0x68,0x3a,0x20,
0x39,0x36,0x70,0x78,0x3b,0x20,0x68,0x65,0x69,0x67,0x68,0x74,0x3a,0x20,0x36,0x38,
0x70,0x78,0x3b,0x22,0x20,0x61,0x6c,0x74,0x3d,0x22,0x53,0x54,0x20,0x6c,0x6f,0x67,
0x6f,0x22,0x20,0x73,0x72,0x63,0x3d,0x22,0x69,0x6d,0x67,0x2f,0x6c,0x6f,0x67,0x6f,
0x2e,0x6a,0x70,0x67,0x22,0x3e,0x3c,0x2f,0x64,0x69,0x76,0x3e,0x0d,0x0a,0x3c,0x2f,
0x74,0x64,0x3e,0x0d,0x0a,0x3c,0x74,0x64,0x20,0x77,0x69,0x64,0x74,0x68,0x3d,0x22,
0x35,0x30,0x30,0x22,0x3e,0x0d,0x0a,0x3c,0x68,0x31,0x3e,0x3c,0x73,0x6d,0x61,0x6c,
0x6c,0x3e,0x3c,0x73,0x6d,0x61,0x6c,0x6c,0x3e,0x3c,0x73,0x6d,0x61,0x6c,0x6c,0x3e,
0x3c,0x73,0x6d,0x61,0x6c,0x6c,0x3e,0x3c,0x62,0x69,0x67,0x3e,0x3c,0x62,0x69,0x67,
0x3e,0x3c,0x62,0x69,0x67,0x20,0x73,0x74,0x79,0x6c,0x65,0x3d,0x22,0x66,0x6f,0x6e,
0x74,0x2d,0x77,0x65,0x69,0x67,0x68,0x74,0x3a,0x20,0x62,0x6f,0x6c,0x64,0x3b,0x22,
0x3e,0x3c,0x62,0x69,0x67,0x3e,0x3c,0x73,0x74,0x72,0x6f,0x6e,0x67,0x3e,0x3c,0x73,
0x70,0x61,0x6e,0x20,0x73,0x74,0x79,0x6c,0x65,0x3d,0x22,0x66,0x6f,0x6e,0x74,0x2d,
0x73,0x74,0x79,0x6c,0x65,0x3a,0x20,0x69,0x74,0x61,0x6c,0x69,0x63,0x3b,0x22,0x3e,
0x53,0x54,0x4d,0x33,0x32,0x46,0x37,0x78,0x78,0x20,0x57,0x65,0x62,0x73,0x65,0x72,
0x76,0x65,0x72,0x20,0x44,0x65,0x6d,0x6f,0x3c,0x2f,0x73,0x70,0x61,0x6e,0x3e,0x3c,
0x2f,0x73,0x74,0x72,0x6f,0x6e,0x67,0x3e,0x3c,0x2f,0x62,0x69,0x67,0x3e,0x3c,0x2f,
0x62,0x69,0x67,0x3e,0x3c,0x2f,0x62,0x69,0x67,0x3e,0x3c,0x2f,0x62,0x69,0x67,0x3e,
0x3c,0x2f,0x73,0x6d,0x61,0x6c,0x6c,0x3e,0x3c,0x2f,0x73,0x6d,0x61,0x6c,0x6c,0x3e,
0x3c,0x2f,0x73,0x6d,0x61,0x6c,0x6c,0x3e,0x3c,0x2f,0x73,0x6d,0x61,0x6c,0x6c,0x3e,
0x0d,0x0a,0x3c,0x73,0x6d,0x61,0x6c,0x6c,0x20,0x73,0x74,0x79,0x6c,0x65,0x3d,0x22,
0x66,0x6f,0x6e,0x74,0x2d,0x66,0x61,0x6d,0x69,0x6c,0x79,0x3a,0x20,0x56,0x65,0x72,
0x64,0x61,0x6e,0x61,0x3b,0x22,0x3e,0x3c,0x73,0x6d,0x61,0x6c,0x6c,0x3e,0x3c,0x62,
0x69,0x67,0x3e,0x3c,0x62,0x69,0x67,0x3e,0x3c,0x62,0x69,0x67,0x3e,0x3c,0x62,0x69,
0x67,0x20,0x73,0x74,0x79,0x6c,0x65,0x3d,0x22,0x66,0x6f,0x6e,0x74,0x2d,0x77,0x65,
0x69,0x67,0x68,0x74,0x3a,0x20,0x62,0x6f,0x6c,0x64,0x3b,0x20,0x63,0x6f,0x6c,0x6f,
0x72,0x3a,0x20,0x72,0x67,0x62,0x28,0x35,0x31,0x2c,0x20,0x35,0x31,0x2c,0x20,0x32,
0x35,0x35,0x29,0x3b,0x22,0x3e,0x3c,0x62,0x69,0x67,0x3e,0x3c,0x73,0x74,0x72,0x6f,
0x6e,0x67,0x3e,0x3c,0x73,0x70,0x61,0x6e,0x20,0x73,0x74,0x79,0x6c,0x65,0x3d,0x22,
0x66,0x6f,0x6e,0x74,0x2d,0x73,0x74,0x79,0x6c,0x65,0x3a,0x20,0x69,0x74,0x61,0x6c,
0x69,0x63,0x3b,0x22,0x3e,0x3c,0x2f,0x73,0x70,0x61,0x6e,0x3e,0x3c,0x2f,0x73,0x74,
0x72,0x6f,0x6e,0x67,0x3e,0x3c,0x2f,0x62,0x69,0x67,0x3e,0x3c,0x73,0x70,0x61,0x6e,
0x20,0x73,0x74,0x79,0x6c,0x65,0x3d,0x22,0x63,0x6f,0x6c,0x6f,0x72,0x3a,0x20,0x72,
0x67,0x62,0x28,0x35,0x31,0x2c,0x20,0x35,0x31,0x2c,0x20,0x32,0x35,0x35,0x29,0x3b,
0x22,0x3e,0x3c,0x62,0x72,0x3e,0x0d,0x0a,0x3c,0x2f,0x73,0x70,0x61,0x6e,0x3e,0x3c,
0x2f,0x62,0x69,0x67,0x3e,0x3c,0x2f,0x62,0x69,0x67,0x3e,0x3c,0x2f,0x62,0x69,0x67,
0x3e,0x3c,0x2f,0x62,0x69,0x67,0x3e,0x3c,0x2f,0x73,0x6d,0x61,0x6c,0x6c,0x3e,0x3c,
0x2f,0x73,0x6d,0x61,0x6c,0x6c,0x3e,0x3c,0x2f,0x68,0x31,0x3e,0x0d,0x0a,0x3c,0x68,
0x32,0x3e,0x34,0x30,0x34,0x20,0x2d,0x20,0x50,0x61,0x67,0x65,0x20,0x6e,0x6f,0x74,
0x20,0x66,0x6f,0x75,0x6e,0x64,0x3c,0x2f,0x68,0x32,0x3e,0x0d,0x0a,0x3c,0x70,0x3e,
0x3c,0x73,0x70,0x61,0x6e,0x20,0x73,0x74,0x79,0x6c,0x65,0x3d,0x22,0x66,0x6f,0x6e,
0x74,0x2d,0x66,0x61,0x6d,0x69,0x6c,0x79,0x3a,0x20,0x54,0x69,0x6d,0x65,0x73,0x20,
0x4e,0x65,0x77,0x20,0x52,0x6f,0x6d,0x61,0x6e,0x2c,0x54,0x69,0x6d,0x65,0x73,0x2c,
0x73,0x65,0x72,0x69,0x66,0x3b,0x22,0x3e,0x20,0x53,0x6f,0x72,0x72,0x79,0x2c,0x0d,
0x0a,0x74,0x68,0x65,0x20,0x70,0x61,0x67,0x65,0x20,0x79,0x6f,0x75,0x20,0x61,0x72,
0x65,0x20,0x72,0x65,0x71,0x75,0x65,0x73,0x74,0x69,0x6e,0x67,0x20,0x77,0x61,0x73,
0x20,0x6e,0x6f,0x74,0x20,0x66,0x6f,0x75,0x6e,0x64,0x20,0x6f,0x6e,0x20,0x74,0x68,
0x69,0x73,0x20,0x73,0x65,0x72,0x76,0x65,0x72,0x2e,0x3c,0x2f,0x73,0x70,0x61,0x6e,
0x3e,0x20,0x3c,0x2f,0x70,0x3e,0x0d,0x0a,0x3c,0x2f,0x74,0x64,0x3e,0x0d,0x0a,0x3c,
0x2f,0x74,0x72,0x3e,0x0d,0x0a,0x3c,0x2f,0x74,0x62,0x6f,0x64,0x79,0x3e,0x0d,0x0a,
0x3c,0x2f,0x74,0x61,0x62,0x6c,0x65,0x3e,0x0d,0x0a,0x3c,0x2f,0x62,0x6f,0x64,0x79,
0x3e,0x3c,0x2f,0x68,0x74,0x6d,0x6c,0x3e,};

#if FSDATA_FILE_ALIGNMENT==1
static const unsigned int dummy_align__index_html = 1;
#endif
static const unsigned char FSDATA_ALIGN_PRE data__index_html[] FSDATA_ALIGN_POST = {
/* /index.html (12 chars) */
0x2f,0x69,0x6e,0x64,0x65,0x78,0x2e,0x68,0x74,0x6d,0x6c,0x00,

/* HTTP header */
/* "HTTP/1.0 200 OK
" (17 bytes) */
0x48,0x54,0x54,0x50,0x2f,0x31,0x2e,0x30,0x20,0x32,0x30,0x30,0x20,0x4f,0x4b,0x0d,
0x0a,
/* "Server: lwIP/2.1.2 (http://savannah.nongnu.org/projects/lwip)
" (63 bytes) */
0x53,0x65,0x72,0x76,0x65,0x72,0x3a,0x20,0x6c,0x77,0x49,0x50,0x2f,0x32,0x2e,0x31,
0x2e,0x32,0x20,0x28,0x68,0x74,0x74,0x70,0x3a,0x2f,0x2f,0x73,0x61,0x76,0x61,0x6e,
0x6e,0x61,0x68,0x2e,0x6e,0x6f,0x6e,0x67,0x6e,0x75,0x2e,0x6f,0x72,0x67,0x2f,0x70,
0x72,0x6f,0x6a,0x65,0x63,0x74,0x73,0x2f,0x6c,0x77,0x69,0x70,0x29,0x0d,0x0a,
/* "Content-Length: 1993
" (18+ bytes) */
0x43,0x6f,0x6e,0x74,0x65,0x6e,0x74,0x2d,0x4c,0x65,0x6e,0x67,0x74,0x68,0x3a,0x20,
0x31,0x39,0x39,0x33,0x0d,0x0a,
/* "Content-Type: text/html

" (27 bytes) */
0x43,0x6f,0x6e,0x74,0x65,0x6e,0x74,0x2d,0x54,0x79,0x70,0x65,0x3a,0x20,0x74,0x65,
0x78,0x74,0x2f,0x68,0x74,0x6d,0x6c,0x0d,0x0a,0x0d,0x0a,
/* raw file data (1993 bytes) */
0x3c,0x21,0x44,0x4f,0x43,0x54,0x59,0x50,0x45,0x20,0x68,0x74,0x6d,0x6c,0x3e,0x0d,
0x0a,0x3c,0x68,0x74,0x6d,0x6c,0x3e,0x0d,0x0a,0x3c,0x62,0x6f,0x64,0x79,0x3e,0x0d,
0x0a,0x0d,0x0a,0x3c,0x68,0x31,0x3e,0x53,0x65,0x72,0x69,0x61,0x6c,0x20,0x50,0x6f,
0x72,0x74,0x3c,0x2f,0x68,0x31,0x3e,0x0d,0x0a,0x0d,0x0a,0x3c,0x70,0x3e,0x53,0x65,
0x72,0x69,0x61,0x6c,0x20,0x70,0x6f,0x72,0x74,0x20,0x73,0x65,0x74,0x75,0x70,0x20,
0x61,0x6e,0x64,0x20,0x63,0x6f,0x6e,0x6e,0x65,0x63,0x74,0x69,0x6f,0x6e,0x3c,0x2f,
0x70,0x3e,0x0d,0x0a,0x0d,0x0a,0x3c,0x66,0x6f,0x72,0x6d,0x20,0x61,0x63,0x74,0x69,
0x6f,0x6e,0x3d,0x22,0x2f,0x69,0x6e,0x64,0x65,0x78,0x2e,0x68,0x74,0x6d,0x6c,0x22,
0x3e,0x0d,0x0a,0x20,0x20,0x3c,0x6c,0x61,0x62,0x65,0x6c,0x20,0x66,0x6f,0x72,0x3d,
0x22,0x62,0x61,0x75,0x64,0x22,0x3e,0x42,0x61,0x75,0x64,0x3a,0x3c,0x2f,0x6c,0x61,
0x62,0x65,0x6c,0x3e,0x0d,0x0a,0x20,0x20,0x3c,0x73,0x65,0x6c,0x65,0x63,0x74,0x20,
0x6e,0x61,0x6d,0x65,0x3d,0x22,0x62,0x61,0x75,0x64,0x22,0x20,0x69,0x64,0x3d,0x22,
0x62,0x61,0x75,0x64,0x22,0x3e,0x0d,0x0a,0x20,0x20,0x3c,0x6f,0x70,0x74,0x69,0x6f,
0x6e,0x20,0x76,0x61,0x6c,0x75,0x65,0x3d,0x22,0x31,0x31,0x35,0x32,0x30,0x30,0x22,
0x3e,0x31,0x31,0x35,0x32,0x30,0x30,0x3c,0x2f,0x6f,0x70,0x74,0x69,0x6f,0x6e,0x3e,
0x0d,0x0a,0x20,0x20,0x3c,0x6f,0x70,0x74,0x69,0x6f,0x6e,0x20,0x76,0x61,0x6c,0x75,
0x65,0x3d,0x22,0x39,0x36,0x30,0x30,0x22,0x3e,0x39,0x36,0x30,0x30,0x3c,0x2f,0x6f,
0x70,0x74,0x69,0x6f,0x6e,0x3e,0x0d,0x0a,0x20,0x20,0x3c,0x6f,0x70,0x74,0x69,0x6f,
0x6e,0x20,0x76,0x61,0x6c,0x75,0x65,0x3d,0x22,0x31,0x39,0x32,0x30,0x30,0x22,0x3e,
0x31,0x39,0x32,0x30,0x30,0x3c,0x2f,0x6f,0x70,0x74,0x69,0x6f,0x6e,0x3e,0x0d,0x0a,
0x20,0x20,0x3c,0x6f,0x70,0x74,0x69,0x6f,0x6e,0x20,0x76,0x61,0x6c,0x75,0x65,0x3d,
0x22,0x33,0x38,0x34,0x30,0x30,0x22,0x3e,0x33,0x38,0x34,0x30,0x30,0x3c,0x2f,0x6f,
0x70,0x74,0x69,0x6f,0x6e,0x3e,0x0d,0x0a,0x20,0x20,0x3c,0x6f,0x70,0x74,0x69,0x6f,
0x6e,0x20,0x76,0x61,0x6c,0x75,0x65,0x3d,0x22,0x35,0x37,0x36,0x30,0x30,0x22,0x3e,
0x35,0x37,0x36,0x30,0x30,0x3c,0x2f,0x6f,0x70,0x74,0x69,0x6f,0x6e,0x3e,0x0d,0x0a,
0x20,0x20,0x3c,0x2f,0x73,0x65,0x6c,0x65,0x63,0x74,0x3e,0x0d,0x0a,0x20,0x20,0x0d,
0x0a,0x20,0x20,0x3c,0x62,0x72,0x3e,0x3c,0x62,0x72,0x3e,0x0d,0x0a,0x20,0x20,0x0d,
0x0a,0x20,0x20,0x3c,0x6c,0x61,0x62,0x65,0x6c,0x20,0x66,0x6f,0x72,0x3d,0x22,0x70,
0x61,0x72,0x69,0x74,0x79,0x22,0x3e,0x50,0x61,0x72,0x69,0x74,0x79,0x3a,0x3c,0x2f,
0x6c,0x61,0x62,0x65,0x6c,0x3e,0x0d,0x0a,0x20,0x20,0x3c,0x73,0x65,0x6c,0x65,0x63,
0x74,0x20,0x6e,0x61,0x6d,0x65,0x3d,0x22,0x70,0x61,0x72,0x69,0x74,0x79,0x22,0x20,
0x69,0x64,0x3d,0x22,0x70,0x61,0x72,0x69,0x74,0x79,0x22,0x3e,0x0d,0x0a,0x20,0x20,
0x3c,0x6f,0x70,0x74,0x69,0x6f,0x6e,0x20,0x76,0x61,0x6c,0x75,0x65,0x3d,0x22,0x4e,
0x6f,0x6e,0x65,0x22,0x3e,0x4e,0x6f,0x6e,0x65,0x3c,0x2f,0x6f,0x70,0x74,0x69,0x6f,
0x6e,0x3e,0x0d,0x0a,0x20,0x20,0x3c,0x6f,0x70,0x74,0x69,0x6f,0x6e,0x20,0x76,0x61,
0x6c,0x75,0x65,0x3d,0x22,0x4f,0x64,0x64,0x22,0x3e,0x4f,0x64,0x64,0x3c,0x2f,0x6f,
0x70,0x74,0x69,0x6f,0x6e,0x3e,0x0d,0x0a,0x20,0x20,0x3c,0x6f,0x70,0x74,0x69,0x6f,
0x6e,0x20,0x76,0x61,0x6c,0x75,0x65,0x3d,0x22,0x45,0x76,0x65,0x6e,0x22,0x3e,0x45,
0x76,0x65,0x6e,0x3c,0x2f,0x6f,0x70,0x74,0x69,0x6f,0x6e,0x3e,0x0d,0x0a,0x20,0x20,
0x3c,0x6f,0x70,0x74,0x69,0x6f,0x6e,0x20,0x76,0x61,0x6c,0x75,0x65,0x3d,0x22,0x4d,
0x61,0x72,0x6b,0x22,0x3e,0x4d,0x61,0x72,0x6b,0x3c,0x2f,0x6f,0x70,0x74,0x69,0x6f,
0x6e,0x3e,0x0d,0x0a,0x20,0x20,0x3c,0x6f,0x70,0x74,0x69,0x6f,0x6e,0x20,0x76,0x61,
0x6c,0x75,0x65,0x3d,0x22,0x53,0x70,0x61,0x63,0x65,0x22,0x3e,0x53,0x70,0x61,0x63,
0x65,0x3c,0x2f,0x6f,0x70,0x74,0x69,0x6f,0x6e,0x3e,0x0d,0x0a,0x20,0x20,0x3c,0x2f,
0x73,0x65,0x6c,0x65,0x63,0x74,0x3e,0x0d,0x0a,0x20,0x20,0x0d,0x0a,0x20,0x20,0x3c,
0x62,0x72,0x3e,0x3c,0x62,0x72,0x3e,0x0d,0x0a,0x20,0x20,0x20,0x0d,0x0a,0x20,0x20,
0x3c,0x6c,0x61,0x62,0x65,0x6c,0x20,0x66,0x6f,0x72,0x3d,0x22,0x64,0x61,0x74,0x61,
0x22,0x3e,0x44,0x61,0x74,0x61,0x20,0x42,0x69,0x74,0x73,0x3a,0x3c,0x2f,0x6c,0x61,
0x62,0x65,0x6c,0x3e,0x0d,0x0a,0x20,0x20,0x3c,0x73,0x65,0x6c,0x65,0x63,0x74,0x20,
0x6e,0x61,0x6d,0x65,0x3d,0x22,0x64,0x61,0x74,0x61,0x22,0x20,0x69,0x64,0x3d,0x22,
0x64,0x61,0x74,0x61,0x22,0x3e,0x0d,0x0a,0x20,0x20,0x3c,0x6f,0x70,0x74,0x69,0x6f,
0x6e,0x20,0x76,0x61,0x6c,0x75,0x65,0x3d,0x22,0x38,0x22,0x3e,0x38,0x20,0x62,0x69,
0x74,0x73,0x3c,0x2f,0x6f,0x70,0x74,0x69,0x6f,0x6e,0x3e,0x0d,0x0a,0x20,0x20,0x3c,
0x6f,0x70,0x74,0x69,0x6f,0x6e,0x20,0x76,0x61,0x6c,0x75,0x65,0x3d,0x22,0x37,0x22,
0x3e,0x37,0x20,0x62,0x69,0x74,0x73,0x3c,0x2f,0x6f,0x70,0x74,0x69,0x6f,0x6e,0x3e,
0x0d,0x0a,0x20,0x20,0x3c,0x6f,0x70,0x74,0x69,0x6f,0x6e,0x20,0x76,0x61,0x6c,0x75,
0x65,0x3d,0x22,0x36,0x22,0x3e,0x36,0x20,0x62,0x69,0x74,0x73,0x3c,0x2f,0x6f,0x70,
0x74,0x69,0x6f,0x6e,0x3e,0x0d,0x0a,0x20,0x20,0x3c,0x6f,0x70,0x74,0x69,0x6f,0x6e,
0x20,0x76,0x61,0x6c,0x75,0x65,0x3d,0x22,0x35,0x22,0x3e,0x35,0x20,0x62,0x69,0x74,
0x73,0x3c,0x2f,0x6f,0x70,0x74,0x69,0x6f,0x6e,0x3e,0x0d,0x0a,0x20,0x20,0x3c,0x2f,
0x73,0x65,0x6c,0x65,0x63,0x74,0x3e,0x0d,0x0a,0x20,0x0d,0x0a,0x20,0x20,0x3c,0x62,
0x72,0x3e,0x3c,0x62,0x72,0x3e,0x0d,0x0a,0x20,0x20,0x20,0x0d,0x0a,0x20,0x20,0x3c,
0x6c,0x61,0x62,0x65,0x6c,0x20,0x66,0x6f,0x72,0x3d,0x22,0x73,0x74,0x6f,0x70,0x22,
0x3e,0x53,0x74,0x6f,0x70,0x20,0x42,0x69,0x74,0x73,0x3a,0x3c,0x2f,0x6c,0x61,0x62,
0x65,0x6c,0x3e,0x0d,0x0a,0x20,0x20,0x3c,0x73,0x65,0x6c,0x65,0x63,0x74,0x20,0x6e,
0x61,0x6d,0x65,0x3d,0x22,0x73,0x74,0x6f,0x70,0x22,0x20,0x69,0x64,0x3d,0x22,0x73,
0x74,0x6f,0x70,0x22,0x3e,0x0d,0x0a,0x20,0x20,0x3c,0x6f,0x70,0x74,0x69,0x6f,0x6e,
0x20,0x76,0x61,0x6c,0x75,0x65,0x3d,0x22,0x31,0x22,0x3e,0x31,0x20,0x62,0x69,0x74,
0x73,0x3c,0x2f,0x6f,0x70,0x74,0x69,0x6f,0x6e,0x3e,0x0d,0x0a,0x20,0x20,0x3c,0x6f,
0x70,0x74,0x69,0x6f,0x6e,0x20,0x76,0x61,0x6c,0x75,0x65,0x3d,0x22,0x32,0x22,0x3e,
0x32,0x20,0x62,0x69,0x74,0x73,0x3c,0x2f,0x6f,0x70,0x74,0x69,0x6f,0x6e,0x3e,0x0d,
0x0a,0x20,0x20,0x3c,0x2f,0x73,0x65,0x6c,0x65,0x63,0x74,0x3e,0x0d,0x0a,0x20,0x0d,
0x0a,0x20,0x20,0x3c,0x62,0x72,0x3e,0x3c,0x62,0x72,0x3e,0x0d,0x0a,0x20,0x20,0x20,
0x0d,0x0a,0x20,0x20,0x3c,0x6c,0x61,0x62,0x65,0x6c,0x20,0x66,0x6f,0x72,0x3d,0x22,
0x68,0x61,0x72,0x64,0x77,0x61,0x72,0x65,0x22,0x3e,0x48,0x61,0x72,0x64,0x77,0x61,
0x72,0x65,0x20,0x46,0x6c,0x6f,0x77,0x20,0x43,0x6f,0x6e,0x74,0x72,0x6f,0x6c,0x3a,
0x3c,0x2f,0x6c,0x61,0x62,0x65,0x6c,0x3e,0x0d,0x0a,0x20,0x20,0x3c,0x73,0x65,0x6c,
0x65,0x63,0x74,0x20,0x6e,0x61,0x6d,0x65,0x3d,0x22,0x68,0x61,0x72,0x64,0x77,0x61,
0x72,0x65,0x22,0x20,0x69,0x64,0x3d,0x22,0x68,0x61,0x72,0x64,0x77,0x61,0x72,0x65,
0x22,0x3e,0x0d,0x0a,0x20,0x20,0x3c,0x6f,0x70,0x74,0x69,0x6f,0x6e,0x20,0x76,0x61,
0x6c,0x75,0x65,0x3d,0x22,0x4e,0x6f,0x6e,0x65,0x22,0x3e,0x4e,0x6f,0x6e,0x65,0x3c,
0x2f,0x6f,0x70,0x74,0x69,0x6f,0x6e,0x3e,0x0d,0x0a,0x20,0x20,0x3c,0x6f,0x70,0x74,
0x69,0x6f,0x6e,0x20,0x76,0x61,0x6c,0x75,0x65,0x3d,0x22,0x52,0x54,0x53,0x2f,0x43,
0x54,0x53,0x22,0x3e,0x52,0x54,0x53,0x2f,0x43,0x54,0x53,0x3c,0x2f,0x6f,0x70,0x74,
0x69,0x6f,0x6e,0x3e,0x0d,0x0a,0x20,0x20,0x3c,0x6f,0x70,0x74,0x69,0x6f,0x6e,0x20,
0x76,0x61,0x6c,0x75,0x65,0x3d,0x22,0x44,0x54,0x52,0x2f,0x44,0x53,0x52,0x22,0x3e,
0x44,0x54,0x52,0x2f,0x44,0x53,0x52,0x3c,0x2f,0x6f,0x70,0x74,0x69,0x6f,0x6e,0x3e,
0x0d,0x0a,0x20,0x20,0x3c,0x6f,0x70,0x74,0x69,0x6f,0x6e,0x20,0x76,0x61,0x6c,0x75,
0x65,0x3d,0x22,0x52,0x53,0x34,0x38,0x35,0x2d,0x72,0x74,0x73,0x22,0x3e,0x52,0x53,
0x34,0x38,0x35,0x2d,0x72,0x74,0x73,0x3c,0x2f,0x6f,0x70,0x74,0x69,0x6f,0x6e,0x3e,
0x0d,0x0a,0x20,0x20,0x3c,0x2f,0x73,0x65,0x6c,0x65,0x63,0x74,0x3e,0x0d,0x0a,0x20,
0x0d,0x0a,0x20,0x20,0x3c,0x62,0x72,0x3e,0x3c,0x62,0x72,0x3e,0x0d,0x0a,0x0d,0x0a,
0x20,0x20,0x3c,0x6c,0x61,0x62,0x65,0x6c,0x20,0x66,0x6f,0x72,0x3d,0x22,0x73,0x65,
0x6e,0x64,0x64,0x61,0x74,0x61,0x22,0x3e,0x53,0x65,0x6e,0x64,0x3a,0x3c,0x2f,0x6c,
0x61,0x62,0x65,0x6c,0x3e,0x0d,0x0a,0x20,0x20,0x3c,0x69,0x6e,0x70,0x75,0x74,0x20,
0x74,0x79,0x70,0x65,0x3d,0x22,0x74,0x65,0x78,0x74,0x22,0x20,0x69,0x64,0x3d,0x22,
0x73,0x65,0x6e,0x64,0x22,0x20,0x6e,0x61,0x6d,0x65,0x3d,0x22,0x73,0x65,0x6e,0x64,
0x22,0x20,0x76,0x61,0x6c,0x75,0x65,0x3d,0x22,0x54,0x65,0x73,0x74,0x22,0x3e,0x0d,
0x0a,0x20,0x20,0x0d,0x0a,0x20,0x20,0x3c,0x62,0x72,0x3e,0x3c,0x62,0x72,0x3e,0x0d,
0x0a,0x20,0x20,0x0d,0x0a,0x20,0x20,0x3c,0x62,0x75,0x74,0x74,0x6f,0x6e,0x20,0x6f,
0x6e,0x63,0x6c,0x69,0x63,0x6b,0x3d,0x22,0x68,0x74,0x74,0x70,0x47,0x65,0x74,0x28,
0x29,0x3b,0x22,0x3e,0x43,0x6c,0x69,0x63,0x6b,0x20,0x6d,0x65,0x3c,0x2f,0x62,0x75,
0x74,0x74,0x6f,0x6e,0x3e,0x0d,0x0a,0x0d,0x0a,0x3c,0x2f,0x66,0x6f,0x72,0x6d,0x3e,
0x0d,0x0a,0x0d,0x0a,0x3c,0x73,0x63,0x72,0x69,0x70,0x74,0x3e,0x0d,0x0a,0x20,0x20,
0x0d,0x0a,0x20,0x20,0x66,0x75,0x6e,0x63,0x74,0x69,0x6f,0x6e,0x20,0x68,0x74,0x74,
0x70,0x47,0x65,0x74,0x28,0x29,0x0d,0x0a,0x20,0x20,0x7b,0x0d,0x0a,0x20,0x20,0x20,
0x20,0x20,0x20,0x76,0x61,0x72,0x20,0x78,0x6d,0x6c,0x48,0x74,0x74,0x70,0x20,0x3d,
0x20,0x6e,0x65,0x77,0x20,0x58,0x4d,0x4c,0x48,0x74,0x74,0x70,0x52,0x65,0x71,0x75,
0x65,0x73,0x74,0x28,0x29,0x3b,0x0d,0x0a,0x20,0x20,0x20,0x20,0x20,0x20,0x78,0x6d,
0x6c,0x48,0x74,0x74,0x70,0x2e,0x6f,0x70,0x65,0x6e,0x28,0x20,0x22,0x47,0x45,0x54,
0x22,0x2c,0x77,0x69,0x6e,0x64,0x6f,0x77,0x2e,0x6c,0x6f,0x63,0x61,0x74,0x69,0x6f,
0x6e,0x2c,0x20,0x74,0x72,0x75,0x65,0x20,0x29,0x3b,0x20,0x2f,0x2f,0x20,0x66,0x61,
0x6c,0x73,0x65,0x20,0x66,0x6f,0x72,0x20,0x73,0x79,0x6e,0x63,0x68,0x72,0x6f,0x6e,
0x6f,0x75,0x73,0x20,0x72,0x65,0x71,0x75,0x65,0x73,0x74,0x0d,0x0a,0x20,0x20,0x20,
0x20,0x20,0x20,0x63,0x6f,0x6e,0x73,0x6f,0x6c,0x65,0x2e,0x6c,0x6f,0x67,0x28,0x29,
0x3b,0x0d,0x0a,0x20,0x20,0x20,0x20,0x20,0x20,0x78,0x6d,0x6c,0x48,0x74,0x74,0x70,
0x2e,0x73,0x65,0x6e,0x64,0x28,0x77,0x69,0x6e,0x64,0x6f,0x77,0x2e,0x6c,0x6f,0x63,
0x61,0x74,0x69,0x6f,0x6e,0x29,0x3b,0x0d,0x0a,0x20,0x20,0x20,0x20,0x20,0x20,0x63,
0x6f,0x6e,0x73,0x6f,0x6c,0x65,0x2e,0x6c,0x6f,0x67,0x28,0x77,0x69,0x6e,0x64,0x6f,
0x77,0x2e,0x6c,0x6f,0x63,0x61,0x74,0x69,0x6f,0x6e,0x29,0x3b,0x0d,0x0a,0x20,0x20,
0x20,0x20,0x20,0x20,0x72,0x65,0x74,0x75,0x72,0x6e,0x20,0x78,0x6d,0x6c,0x48,0x74,
0x74,0x70,0x2e,0x72,0x65,0x73,0x70,0x6f,0x6e,0x73,0x65,0x54,0x65,0x78,0x74,0x3b,
0x0d,0x0a,0x20,0x20,0x7d,0x0d,0x0a,0x20,0x20,0x0d,0x0a,0x3c,0x2f,0x73,0x63,0x72,
0x69,0x70,0x74,0x3e,0x20,0x0d,0x0a,0x0d,0x0a,0x3c,0x2f,0x62,0x6f,0x64,0x79,0x3e,
0x0d,0x0a,0x3c,0x2f,0x68,0x74,0x6d,0x6c,0x3e,};



const struct fsdata_file file__404_html[] = { {
file_NULL,
data__404_html,
data__404_html + 12,
sizeof(data__404_html) - 12,
FS_FILE_FLAGS_HEADER_INCLUDED | FS_FILE_FLAGS_HEADER_PERSISTENT,
}};

const struct fsdata_file file__index_html[] = { {
file__404_html,
data__index_html,
data__index_html + 12,
sizeof(data__index_html) - 12,
FS_FILE_FLAGS_HEADER_INCLUDED | FS_FILE_FLAGS_HEADER_PERSISTENT,
}};

#define FS_ROOT file__index_html
#define FS_NUMFILES 2

