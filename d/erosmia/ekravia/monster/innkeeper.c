#include "../ekravia.h"
inherit MONSTER;

void create()
{
	::create();
	set_level(19);
	set_name( "Dino", "��ŵ" );
	add( "id", ({ "dino" }) );
	set_short( "�õ��ϰ�  ��ŵ" );
	set_long(@LONG
һ����ĸߴ��������, ȫ������ɢ����һ�ּ������¸ҵ�����, ��ʮ��
ǰ����Ӧ���Ǹ���Ϊ��ɫ����ʿ��? ��֪Ϊ���������˻�������ĬĬ�ؾ�
Ӫһ���õꡣ
LONG
	);
	set_perm_stat( "str", 27);
	set_perm_stat( "dex", 23 );
	set_perm_stat( "int", 15 );
	set_perm_stat( "con", 25);
	set_perm_stat( "pie", 15 );
	set( "natural_armor_class", 100 );
	set( "natural_defense_bonus", 20 );
	set( "max_hp", 1000 );
	set( "hit_points", 1000 );
	set( "gender", "male" );
	set( "alignment", 800 );
	set( "wealth/silver", 5000 );
	set( "no_attack", 1);

	set( "chat_chance", 15 );
	set( "chat_output", ({
		"�ϰ����ڹ�̨ǰ, ĬĬ�ط���\�����ϵ��鼮��\n",
		"�ϰ�������һ��, ���ȵ��ʵ�����λ����, ����Ҫסһ����?��\n",
		"�ϰ�����Ĩ��, ����ز�������̨�Աߵļ��ӡ�\n"
	}) );
}
