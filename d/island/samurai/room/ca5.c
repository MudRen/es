#include <mercury.h>

inherit ROOM;

void create()
{
   ::create();
   set_short( "��ǽ" );
   set_long(
@ANGEL
������һ����ʿ�Ǳ�����Χ��ǽ�ϣ������ǽ�ܸߣ����������ӳ�ǽ����
�¿�ʱ�������һ������ëë�ĸо�����Ϊ��ǽʵ��̫���ˣ���ǽ�ϻ�����λ
���ص���ʿ�����Ƕ���ĵ����ƺ��е㲻��.
ANGEL
);
	set( "objects",([
	"guard#1":MOB"guard3",
	"guard#2":MOB"guard3"]));
	set("light",1);
	set_outside("eastland");
        set( "exits", ([
    "north" :MR"ca4",
    "south" :MR"ca6",
                ]) );
         reset();                     
}

