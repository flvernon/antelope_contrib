#include	<stdio.h>
#include	"../../h/igl.h"
#include	"devpar.h"
#include	"../com/global.h"

#define T(a)	if( key & a )
#define T2(a,b)	if( key & a || key & b )
char buff[1024];
extern int key;
char devname[]	="plotdb";
int intbytes=DEFAULT_INTBYTES;

readcom(file,level)
FILE *file;
int level;
   {
	float x, y, x1, y1, x2, y2, xcur, ycur;
	float on1, off1, on2, off2;
	int i;
	char buf[128];
	char *cptr;
	int c;
	int npts;
	int icol, rcol, gcol, bcol, ifill;
	int ifat, ipat;
	int cnt, len;
	int npoly, n, nv;
	int idash;
	int ipen, ibrush, iang, isize;
	int pencolor, penmode, penfat, pendash, pencdash;
	int brushmode, brushcolor, brushpat;
	int textfont, textcenter;
	float textsize, textangle;
	int rastermode;
	int symindex;
	float symangle,symsize;
	FILE *temp, *fopen();
	
	if(level > MAXLEVEL)
		err(FATAL,"too many recursive include files, level=%d",level);

	while( (c= (int)getc(file)) != EOF)
	   {
		c &= 0xff;
		if( (c & M) == 0)	/* non-plot text */
		   {
			putc(c,stderr);
			while( (c=(int)getc(file)) != EOF)
			   {
				if( (c&M) != 0) break;
				putc(c,stderr);
			   }
			if(c == EOF) break;
			c &= 0xff;
		   }

		   

		switch(c)	/* master command switch */
		   {
			case IGL_MOVE:
				getfxy(&xcur,&ycur,file);
				T(VECTOR) pr("move: %7.3f %7.3f\n",xcur,ycur);
				break;

			case IGL_DRAW:
				getfxy(&xcur,&ycur,file);
				T(VECTOR) pr("draw: %7.3f %7.3f\n",xcur,ycur);
				break;

			case IGL_LINE:
				getfxy(&x,&y,file);
				getfxy(&xcur,&ycur,file);
				T(VECTOR) {
					  pr("line: %7.3f %7.3f ",x,y);
					  pr(" %7.3f %7.3f\n",xcur,ycur);
				}
				break;

			case IGL_POINT:
				getfxy(&xcur,&ycur,file);
				T(POINT) pr("point: %7.3f %7.3f\n",xcur,ycur);
				break;
 
			case IGL_BOX:
				getfxy(&xcur,&ycur,file);
				getfxy(&x,&y,file);
				T(VECTOR) {
				  pr("box: %7.3f %7.3f ", xcur,ycur);
				  pr("%7.3f %7.3f\n",x,y);
				  }
				break;
			
			
			case IGL_WINDOW:
				getfxy(&x1,&y1,file);
				getfxy(&x2,&y2,file);
				T(WIND) {
					pr("window: %7.3f %7.3f", x1,y1);
					pr(" %7.3f %7.3f\n",x2,y2);
				}
				break;
			
			case IGL_UNWINDOW:
				T(WIND) pr("unwindow:\n");
				break;

			case IGL_SETPEN:
				ipen= getc(file) & 0xff;
				T(PEN) pr("setpen: %d\n",ipen);
				break;
					
			case IGL_DEFBWPEN:
				ipen= getc(file) & 0xff;
				penfat = getc(file) & 0xff;
				pendash = getc(file) & 0xff;
				penmode = getc(file) & 0xff;
				T(PEN) pr("defbwpen: %d\n",ipen);
				T(PEN) pr("\tfat=%d dash=%d mode=%d\n",penfat,pendash,penmode);
				break;
			
			case IGL_DEFCPEN:
				ipen= getc(file) & 0xff;
				penfat = getc(file) & 0xff;
				pendash = getc(file) & 0xff;
				pencolor = getc(file) & 0xff;
				T(PEN) pr("defcpen: %d\n",ipen);
				T(PEN) pr("\tfat=%d dash=%d color=%d\n",penfat,pendash,pencolor);
				break;
			
			case IGL_SETPENMODE:
				penmode= getc(file) & 0x3;
				T(PEN) pr("penmode: %d\n",penmode);
				break;

			case IGL_SETFAT:
				penfat = getc(file) & 0xff;
				T(PEN) pr("penfat: %d\n",penfat);
				break;
					
			case IGL_SETDASH:
				idash= getc(file) & 0xff;
				T(VECTOR) pr("dash: %d\n",idash);
				break;

			case IGL_SETPENCOLOR:
				pencolor= getc(file) & 0xff;
				T2(PEN,COLOR) pr("pencolor: %d\n",pencolor);
				break;

			case IGL_DEFCOLOR:
				icol= getc(file) & 0xff;
				rcol= getc(file) & 0xff;
				gcol= getc(file) & 0xff;
				bcol= getc(file) & 0xff;
				T(COLOR) {
				    pr("defcolor %3d:",icol);
				    pr(" %5.3f %5.3f %5.3f\n",
					(float)(rcol)/255.0,
					(float)(gcol)/255.0,
					(float)(bcol)/255.0);
				   }
				break;
			
			case IGL_DEFDASH:
				idash= getc(file) & 0xff;
				on1 = (float)(geti(file)) / FLOATNORM;
				off1= (float)(geti(file)) / FLOATNORM;
				on2 = (float)(geti(file)) / FLOATNORM;
				off2= (float)(geti(file)) / FLOATNORM;
				T(COLOR) {
					pr("defdash %3d: %5.3f %5.3f",idash,on1,off1);
					pr(" %5.3f %5.3f",on2,off2);
				}
				break;

			case IGL_DEFPATTERN:
				ipat= getc(file) & 0xff;
				T(POLY) pr("defpattern %3d:\n",ipat);
				fread(buf,4,32,file);
				break;

			case IGL_DEFBWBRUSH:
				ibrush= getc(file) & 0xff;
				brushpat = getc(file) & 0xff;
				brushmode = getc(file) & 0xff;
				T(PEN) pr("defbwbrush: %d\n",ibrush);
				T(PEN)
				  pr("\tpat=%d mode=%d\n",brushpat,brushmode);
				break;

			case IGL_DEFCBRUSH:
				ibrush= getc(file) & 0xff;
				brushcolor = getc(file) & 0xff;
				T(PEN) pr("defcbrush: %d\n",ibrush);
				T(PEN)
				  pr("\tcolor=%d\n",brushcolor);
				break;

			case IGL_SETBRUSH:
				ibrush= getc(file) & 0xff;
				T(PEN) pr("setbrush: %d\n",ibrush);
				break;

			case IGL_SETBRUSHCOLOR:
				brushcolor= getc(file) & 0xff;
				T(BRUSH) pr("brushcolor: %d\n",brushcolor);
				break;
			

			case IGL_SETPATTERN:
				ipat= getc(file) & 0xff;
				T2(BRUSH,PAT) pr("brushpat: %d\n",ipat);
				break;

			case IGL_SETBRUSHMODE:
				brushmode= getc(file) & 0x7;
				T(BRUSH) pr("brushmode: %d\n",brushmode);
				break;

			case IGL_RASTER:
				T(RASTER) pr("raster:\n");
				raster(file);
				break;

			case IGL_RASTERFILE:
				cptr= buf;
				do *cptr = getc(file); while(*cptr++);
				T(RASTER) pr("rasterfile: %s\n",buf);
				temp= fopen(buf,"r");
				if(temp == NULL)
				   {
					err(WARN,"cannot open raster file %s\n",
						buf);
					break;
				   }
				raster(temp);
				fclose(temp);
				break;


			case IGL_SETRASTMODE:
				rastermode= getc(file) & 0x7;
				T(RASTER) pr("rastermode: %d\n",rastermode);
				break;

			case IGL_POLYFILL:
				npts= geti(file);
				T(POLY) pr("polygon: npts=%d\n",npts);
				for(i=0; i<npts; i++)
				   {
					getfxy(&x,&y,file);
				   }
				break;

			case IGL_POLYFILLN:
				npoly= geti(file);
				T(POLY) pr("polygon: npoly=%d npts=\n",npoly);
				for(n=0; n<npoly; n++)
				   {
					npts= geti(file);
					T(POLY) pr("%d, ",npts);
					for(i=0; i<npts; i++)
					   {
						getfxy(&x,&y,file);
					   }
				   }
				T(POLY) pr("\n");
				break;

			case IGL_BOXFILL:
				getfxy(&x1,&y1,file);
				getfxy(&x2,&y2,file);
				T(POLY) {
				   pr("boxfill: %7.3f %7.3f", x1,y1);
				   pr(" %7.3f %7.3f\n",x2,y2);
					}
				break;




			case IGL_TEXT:
				/* this is not very robust!!!! */
				getfxy(&xcur,&ycur,file);
				cptr= buf;
				do *cptr = getc(file); while(*cptr++);
				*cptr++= '\0';
				T(TEXT) pr("text: >>%s<<   ",buf);
				T(TEXT) pr("\t %7.3f %7.3f\n",xcur,ycur);
				break;


			case IGL_SETTEXTANGLE:
				textangle= (float)(geti(file))/ANGLENORM;
				textangle *= 360.0;
				textangle *= 2*3.14159/360.0;
				T(TEXT) pr("textangle: %7.2f\n",textangle);
				break;
				 
			case IGL_SETTEXTSIZE:
				textsize= (float)(geti(file))/FLOATNORM;
				T(TEXT) pr("textsize: %7.2f\n",textsize);
				break;
				 
			case IGL_TEXTCENTER:
				textcenter= getc(file) &0xff;
				T(TEXT) pr("textcenter: hpos=%d vpos=%d\n",
					textcenter&0x00000003,
					(textcenter>>2)%03);
				break;

			case IGL_SETTEXTFONT:
				textfont = getc(file) & 0xff;
				T(TEXT) pr("settextfont:");
				break;

			case IGL_LOADSYMS:
				pr("loading symbols\n");
				break;

			case IGL_SYMBOL:
				symindex = getc(file);
				getfxy(&xcur,&ycur,file);
				symsize=(float)(geti(file))/FLOATNORM;
				symangle=(float)(geti(file))/ANGLENORM;
				symangle *= 360.0;
				symangle *= 2*3.141592/360.0;
				T(SYMBOL)
				 pr("symbol %d: size=%6.3f\n",symindex,symsize);
				T(SYMBOL)
				 pr("\tangle=%6.3f x=%7.3f y=%7.3f\n",symangle,xcur,ycur);
				 break;
		
				 
			case IGL_ERASE:
				pr("erase:\n");
				/* assume more to come */
				return(1);
				break;

			case IGL_PAUSE:
				pr("pause:\n");
			/*
			case IGL_INCLUDE:
				cptr= buf;
				do *cptr = getc(file); while(*cptr++);
				temp= fopen(buf,"r");
				T(MISC) pr("include: %s", buf);
				if(temp == NULL)
				   {
					err(WARN,"cannot open include file %s\n",
						buf);
					break;
				   }
				readcom(temp,level+1);
				fclose(temp);
				break;
				
			case IGL_INIT:
				T(MISC) pr("init:");
				break;
			case IGL_FINISH:
				T(MISC) pr("finish:");
				break;
			*/

			case IGL_ENDPLOT:
				pr("ENDPLOT:\n");
				break;
			
			case IGL_PLOTLABEL:
				/* this is not very robust!!!! */
				cptr= buf;
				do *cptr = getc(file); while(*cptr++);
				*cptr++= '\0';
				T(TEXT) pr("text: >>%s<<\n",buf);
				break;

			case IGL_SETINTBYTES:
				intbytes= getc(file) & 0xff;
				pr ("intbytes = %d\n", intbytes);
				break;
	
			default:
				fprintf(stdout,"*** ERROR ***\n");
				fprintf(stdout,"unknown plot command= %c =%o\n",
					c&0x7f, c&0xff);
				break;
		   }
	   }
	return(0); /* if we reach here, that's all */
   }


getfxy(x,y,file)
float *x, *y;
FILE *file;
   {
	struct xypack { int xin, yin; } xy;

	switch (intbytes) {
	case 2: 
		{		
		register struct sxypack { short xin, yin; } *sxy;
		int xxyy;
		xxyy= getw(file);
		sxy= (struct sxypack *)(&xxyy);
		xy.xin = (int)sxy->xin;
		xy.yin = (int)sxy->yin;
		}
		break;
	case 4: 
		xy.xin = getw(file);
		xy.yin = getw(file);
		break;
	default:
		err(FATAL,"Unsupported INTBYTES = %d", intbytes);
	}
		
	*x= (float)(xy.xin) * GEN_INCHPIX;
	*y= (float)(xy.yin) * GEN_INCHPIX;
   }

/*   This routine supplies all integer values to the drivers.  If we
     change to a greater number of bits per integer, we need only change
     this routine as far as the device drivers.  A variable number of bits
     could also be supported here.
*/
geti(file)
FILE *file;
{
	int n;
	switch (intbytes) {
	case 2: 
		n = geth (file);
		break;
	case 4: 
		n = getw (file);
		break;
	default:
		err(FATAL,"Unsupported INTBYTES = %d", intbytes);
	}
	return (n);
}

pr(fmt,a1,a2,a3,a4,a5,a6)
char *fmt;
int a1,a2,a3,a4,a5,a6;
   {
	fprintf(stdout,fmt,a1,a2,a3,a4,a5,a6);
   }