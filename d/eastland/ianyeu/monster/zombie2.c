
#include <mudlib.h>
#include <stats.h>
#include <conditions.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(2);
	set_name("black-claw zombie", "��צ����");
	add( "id", ({ "zombie","black-claw" }) );
   set_short( "��צ����" );
	set_long(
"��צ�����Ǳ�����ʧ�ܵĻ���,��Թ���޷��������ɵĽ���...\n"
"���ǴӼ��˵ķߺ��в�����Թ�飬��ϲ���úںڵ�צ��ץס����...\n"
"��Ҫ��һ������,����������µĵ���... ��������Ķ�����������!!!\n"
	);
	set( "unit", "ֻ" );
	set( "alignment", -1000 );
	set_natural_armor( 10, 4 );
	set_natural_weapon( 4, 1, 2 );
	set_perm_stat( "int", 1 );
	set_perm_stat( "pie", 1 );
	set_perm_stat( "str", 3 );
	set_skill("dodge",15);
   set( "killer", 1 );
	set( "pursuing", 1 );
	set( "tactic_func", "block" );
	set_c_limbs( ({ "���ͷ­", "�ںڵ�����", "����������", "��ϵ��Ķ���" }) );
	set_c_verbs( ({ "%s����ۺڵ�צ�ӣ�ץ��%s","%s�쳤��ͷ����%s", }) );
        set("alt_corpse","/d/monk/monster/corpse1.c"); 
        set("c_death_msg","��������ɱ���ữ��һ̲Ѫˮ... \n"); 


}

int block()
{
	object victim;

	if( random(20)>5 || !(victim= query_attacker()) ) return 0;
	if( victim->query("stop_attack") ) return 0;
	tell_object( victim, 
"��צ����ͻȻ�쳤�����ֱۣ���������ס��Ĳ���˵��.... ����...��..��...��!�� \n\n");
	tell_room( environment(), 
"������צ���� �����ε���ס��" + victim->query("c_cap_name") + "�Ĳ��ӣ�\n",
		({ victim, this_object() }) );
	victim->block_attack(4+random(4));
	victim->set_temp("msg_stop_attack", 
"( ��Ĳ��ӱ���ס,����������������! )\n" );
	return 1;
}
