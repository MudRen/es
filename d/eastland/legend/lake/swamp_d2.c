#include "../legend.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("����ص׶�Ѩ");
    set_long(@LONG
��ǰ��Ȼһ�������¿�ȥ��ԭ���Ǳ��ϳ�����һ�ֻᷢ���ަ�࣬��������ޱ��
�������а��ƴ󣬷���ө���ƵĻ�ɫ���Ρ�ֻ��һ�����СС�����ަɡ���ͺ���
�ƻ�ͨ���Ĳ�ҹ��һ�㡣�ţ������㿴������֮�ʣ�������Щʲ�ᶫ�����������ƶ�
������ϸһ�ƣ��ŷ��֣�ԭ���������������������������ҧʳ����ޱ������Ȥ��
�£����е����ﶼ��͸���ģ�ֻ��Ƥ�����ؽڵĲ��ݿ�����ǿ��ʶ�ĳ�����
LONG
    );
    set("light",1);
    set("exits",([
            "eastdown":LAKE"swamp_d4",
            "westup":LAKE"swamp_d1",
    ]) );
    set("objects",([
           "mollusk#1":LMONSTER"mollusk",
           "mollusk#2":LMONSTER"mollusk",
           "mollusk#3":LMONSTER"mollusk",
    ]) );
    ::reset();
}

