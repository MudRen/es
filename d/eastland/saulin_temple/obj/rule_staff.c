#include <mudlib.h>

inherit WEAPON ;

void create()
{
	set_name("staff of rule", "�ؽ��");
	add ("id", ({ "staff" }) );
	set_short( "�ؽ��" );
	set_long(
		"�������ֵĽ���Ժִ��ɮ���õķ����������������µĽ��ɡ�\n"
	);
	set("type", "bo");
	set("weapon_class", 25);
	set("min_damage", 18);
	set("max_damage", 28);
	set("weight", 150);
	set("value", ({ 755, "silver" }) );
}
