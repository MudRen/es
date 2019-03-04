
#include <mudlib.h>
#include <stats.h>
#include <conditions.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(3);
	set_name("jojo zombie", "�౽���");
	add( "id", ({ "zombie","jojo" }) );
   set_short( "�౽���" );
	set_long(
"�౽����Ǳ�����ʧ�ܵĻ���,��Թ���޷��������ɵĽ���...\n"
"�������嶼������,����Լ�����\��������������ϵ�������,��ȫ���ǡ���\n"
"��Ҫ��һ������,����������µĵ���... ��������Ķ�����������!!!\n"
	);
	set( "unit", "ֻ" );
	set( "alignment", -1600 );
	set_natural_armor( 10, 4 );
	set_natural_weapon( 4, 3, 7 );
	set_perm_stat( "int", 2 );
	set_perm_stat( "pie", 1 );
	set_perm_stat( "str", 5 );
	set_skill("dodge",20);
   set( "killer", 1 );
	set( "pursuing", 1 );
	set( "tactic_func", "emit_poison" );
	set_c_limbs( ({ "����Դ�", "���õ�����", "����������", "��ϵ����۾�" }) );
	set_c_verbs( ({ "%s����ۺڵ�צ�ӣ�ץ��%s","%s�쳤����ҧ��%s", }) );
        set("alt_corpse","/d/monk/monster/corpse1.c"); 
        set("c_death_msg","��������ɱ���ữ��һ̲Ѫˮ... \n"); 


}

int emit_poison()
{
	object victim;

	if( random(21)>3 || !(victim= query_attacker()) ) return 0;
   tell_room( environment(this_object()), 
"�����Ӷ�������˫�֣�һ�Ÿ��õ����絽������� ....\n",
		this_object() );
	(CONDITION_PREFIX + "simple_poison")->apply_effect( victim, 4, 4 );
	return 1;
}
