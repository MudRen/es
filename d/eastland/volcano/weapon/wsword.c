#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "wraith sword", "����֮��" );
	add( "id", ({ "sword" }) );
	set_short( "����֮��" );
	set_long(
                "����һ���û�ɽ�Ҵ���ı�����ӵ���൱����ƻ�����\n" );
	set( "unit", "��" );
	set( "type", "longblade" );
	set( "hit_func", "weapon_hit" );
	set( "weight", 130 );
	set( "weapon_class", 25 );
	set( "min_damage", 15 );
	set( "max_damage", 20 );
	set( "value", ({ 1000, "silver" }) );
}

int weapon_hit( object victim, int damage )
{
	object owner;
        int    my_kar,vic_kar,sp;

	owner = environment();
        my_kar=(int)owner->query("str");
        vic_kar=(int)victim->query("str");
        sp=(int)owner->query("spell_points");
        if (sp < 3) return 0;
        if (vic_kar*2 > my_kar*3) return 0;
                owner->set("spell_points",sp-3);
		tell_object( owner, 
		"\n��İ���֮���ų�һƬ��ɫ��â��������"+victim->query("c_name")+"��"+victim->query("c_name")+"�о����ޱȵ����ȡ�\n\n");
		tell_object( victim, 
		owner->query("c_name") + "�İ���֮���ų�һƬ��ɫ��â���㱻���������ȵĹ�â��\n");
		tell_room( environment(owner),
			owner->query("c_name") + "�İ���֮���ų�һƬ��ɫ��â����"
			+ victim->query("c_name")+" ��\n",
			({ victim, owner }) );
	victim->receive_special_damage( "fire", 10 );
	return 10;
}
