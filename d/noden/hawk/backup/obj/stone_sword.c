#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "flinty longsword", "��ʯ����" );
	add( "id", ({ "longsword", "sword" }) );
	set_short( "��ʯ����" );
	set_long(
		"����һ���ð���ɫ��ʯ���ɵĵĳ������������о����µġ�\n" );
	set( "unit", "��" );
	set( "type", "longblade" );
	set( "hit_func", "weapon_hit" );
	set( "weight", 110 );
	set( "weapon_class", 24 );
	set( "min_damage", 11 );
	set( "max_damage", 22 );
	set( "value", ({ 750, "silver" }) );
}

int weapon_hit( object victim, int damage )
{
	object owner, armor;
	int str;

	owner = environment();
	str = owner->query_stat("str");
	if( random(str)>12 && (armor= victim->query("armor/body")) ) {
		tell_object( owner, 
		        "\n�����ʯ�������е��˵Ļ��ף�����������һ�����ڵĺۼ���\n\n"
			);
		tell_object( victim, 
			owner->query("c_name") + "����ʯ����������ĵĻ��ף�����������һ�����ڵĺۼ���\n"
                        );
		tell_room( environment(owner), 
			owner->query("c_name") + "����ʯ�������е��˵Ļ��ף�����������һ�����ڵĺۼ���\n"
			,({ owner, victim }) );
		if( !armor->query("ac_damaged") ) 
			armor->set_short((string)armor->query("short") + " (����)" );
		if( (int)armor->query("armor_class") > 1 )
			armor->add( "ac_damaged", 1 );
		victim->calc_armor_class();
	}
	return 0;
}
