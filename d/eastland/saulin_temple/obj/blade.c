#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name("blade of hell", "���޵�");
	add ("id", ({ "hell","blade" }) );
	set_short( "���޵�" );
	set_long(@C_LONG
���Ǵ�ĦԺ��ϯ��ɴ�ʦ���񰮵ı������ഫ��ԭ����ĳλ�������ı�����
��֪���Ѿ�մȾ�˶�����Ѫ������������ʦ�л�����ǽ���ѵ��͸���ʦ����
ʦҲ�Դ˵��Խ����㡣
C_LONG
                 );
	set("type", "longblade");
	set("weapon_class", 35);
	set("min_damage", 20);
	set("max_damage", 37);
	set("weight", 200);
	set("value", ({ 755, "silver" }) );
	set("no_sale", 1);
}
