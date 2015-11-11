#***************************************************
#	^> File Name: single.mk
#	^> Author: AoEiuV020
#	^> Mail: 490674483@qq.com
#	^> Created Time: 2015/05/09
#***************************************************
#######�Զ����뵱ǰ�ļ���������.cpp������.o�Ϳ�ִ���ļ���
#######���C=CC�����.c,
#######���RELEASE=1��ͬʱ���ɶ�Ӧ.a��.so,
#######�Զ��жϲ���ϵͳ
#ifeq ($(shell uname 2>&1),Linux)
#	WINDOWS=0
#else
#	WINDOWS=1
#endif
WINDOWS=0
#######�������ж�ϵͳ�ǲ���WINDOWS,׼��׼����ν�ˣ����þͺá�����
ifeq ($(WINDOWS),1)
	SHELL=cmd.exe
	TAREXT=exe
	RM=del /f
else
	TAREXT=out
	RM=rm -f
endif
#######������WINDOWS��һ���ĵط�������
n=pixel.c
SRCEXT:=$(suffix $(n))
CC=gcc
CXX=g++
ifeq ($(SRCEXT),$(findstring $(SRCEXT),.c .i))
	C=CC
	FLAGS=CFLAGS
else
	C=CXX
	FLAGS=CXXFLAGS
endif
#######���C������c����c++������

INCLUDES=-I.
CFLAGS=-Wall -std=c99 -O2 -g $(INCLUDES)
CXXFLAGS=-Wall -std=c++11 -O2 -g $(INCLUDES)
LDFLAGS=-L.
TARGET=$(notdir $(CURDIR)).$(TAREXT)
OBJS=$(patsubst %$(SRCEXT),%.o,$(n))
LIBS=-lsdl2




ECHO=echo $@:$? done...


.PHONY:all clean


all:$(TARGET)
	./$<
	@$(ECHO)


$(TARGET):$(OBJS)
	$($(C)) $^ $(LDFLAGS) $(LIBS) -o $@


$(OBJS):%.o:%$(SRCEXT)
	$($(C)) -c $^ $($(FLAGS)) -o $@


clean:
	-@$(RM) $(OBJS) $(TARGET)
	@$(ECHO)
