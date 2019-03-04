#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "rainbow sword", "�ʺ罣" );
	add( "id", ({ "sword", "rainbow" }) );
	set_short( "the colorful sword of rainbow", "��Ů�Ųʺ罣" );
	set_long(
		"This is the legendary weapon of Ju-nju ganger  . You\n"
		"can see many jewels  on the sword, surrounded by seven\n"
		"perfect pearl.\n",
"��Ѳʺ罣��������Ů��Ů���ʺ���佣�������������߲ʱ�ʯ\n"
"�������ϸ�������ʺ�Ů��ʹ�ã�����ĩ�һ�׺���߿����顣\n" 
	);
	set( "unit", "��" );
	set( "type", "longblade" );
	set( "weapon_class", 35 );
	set( "min_damage", 15 );
	set( "max_damage", 32 );
	set( "weight", 80 );
	set( "value", ({ 2540, "silver" }) );
//	set( "bleeding", 13 );

	set_verbs( ({  "slash", "thrust" }) );
	set_c_verbs( ({ "��%s��%sһ��", "%s����һ�����������⣬����%s",
		"��%s�ɿ����%s��ȥ" }) );
}
