#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(6);
	set_name( "mountain rat", "ɽ����" );
	add( "id", ({ "rat" }) );
	set_short( "ɽ����" );
	set_long(
		"��ֻɽ�������������Ҷ����ԡ�\n"
	);
	set_perm_stat("dex", 9 );
	set_perm_stat("str", 10 );
	set_skill( "dodge", 50 );
        set("chat_chance",10);
        set("chat_output",({
            "����֨��һ���������ǰ���ܹ���\n"
           }) );
	set_c_verbs( ({ "%s��צ����ץ%s", "%s������%sҧ��",
		"%ş�����ȣ�����%s", "%s��ǰ�ʹܣ���צ����%s����" }) );
	set_c_limbs( ({ "ͷ��", "����", "ǰצ", "����", "β��" }) );

	set( "unit", "ֻ" );
	set_natural_armor( 25,7 );
	set( "natural_weapon_class1", 2 );
	set( "natural_min_damage1", 5 );
	set( "natural_max_damage1", 5 );
	set( "max_hp", 160 );
	set( "hit_points", 160 );
#include <../replace_mob.h>
}
