#include "forest.h"

inherit ROOM;

void create()
{
	::create();
	set_outside("noden");
	set_short("��ɭ��");
	set_long(@CLong
��վ�ں�ɭ�ֵ���ڡ�����������һ��, ���ɭ�ֵ���ľ�쳣��ï��
, ʹ�����۶���ǿ�ҵ����ⶼ��ȫ�޷���͸�������ݴ�˵, �����ܵ�ħ��
а��ħ����Ӱ��, ɭ���е�һ��һľ��С�����Ƕ����а��ĺڰ����
    ����, ��ഫ��ָ���˵�����ǰ��ħ��ŵ۹�������ͨ����
CLong
);
	set("exits",([
		"north" : HERE"1n",
		"south" : "/d/noden/8,14.noden",
	]));
	set("no_monster", 1);
	set("exit_suppress", ({ "north", }) );
  	reset();

}
