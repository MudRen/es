#include <mudlib.h>

inherit WEAPON ;

void create()
{
	set_name("holy blade", "���ֽ䵶");
	add ("id", ({ "holy","blade" }) );
	set_short( "���ֽ䵶" );
	set_long(
		"�������ֵĽ���Ժִ��ɮ�����õı��� һ���˳�֮Ϊ�䵶\n"
	);
	set("type", "longblade");
	set("weapon_class", 25);
	set("min_damage", 12);
	set("max_damage", 25);
	set("weight", 150);
	set("value", ({ 500, "silver" }) );
	set_c_verbs( ({
		"%s��һ����ֵĽǶȿ��˳���������%s",
		"%s��������ֱ�� ����%s",
		"��%s�ӳ�һƬ��Ļ���˵�%s",
		"���е�%s����һ������ķ���������%s",
	}) );
}
