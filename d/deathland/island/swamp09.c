
#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
  set_short("swamp of GreyIsland","�Ұ�֮��������");
  set_long(@Long
Long
,@CLong
һ�������������, �������ƺ��������µ��������������ȥ, �����С�Ľ���
���ÿһ��. Խ�����������ˮ��Խ��, �����������Ҳ��������ȫ����ס��. ��
�������Ѿ��޷�����ؿ������ܵ�״����, ֻ֪����Ľ��Ѿ����������������.

CLong
);
set("search_desc",([
    "here":"@@search_here",
    ]) );
set("exits",([
     "east":Deathland"/island/swamp13",
     "west":Deathland"/island/swamp05",
     "south":Deathland"/island/swamp10",
     "north":Deathland"/island/swamp08",
     ]) );
 set("exit_invisble",1);     
 ::reset();
}

string search_here()
{
     return "������ϸѰ�������ʱ��, �㷢�ֶ��Ϸ������ˮ�����ƺ������,\n"
            "����ԭ�������澹Ȼ��һƬ��ҶҲû��, ������޷�ͨ���Ǹ��ط�.\n"
            "�ƺ������Ѱ�������ķ�������.\n";
}
